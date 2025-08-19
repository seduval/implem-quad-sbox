#include "config.h"
#include "poly.h"

using namespace std;

uint64_t corres(uint32_t b1, uint32_t b2, int n) {
    uint32_t i;
    uint32_t j;
    if (b1 < b2)    {
        i = b1;
        j = b2;
    }
    else {
        i = b2;
        j = b1;
    }
    uint64_t res = (n *(n -1))/2 -1 -i*(n-1) + (i*(i-1)/2) - (j-i) +1;
    return res;
}

int hammingWeight(poly x) {
    bitset<64> bits(x);
    return bits.count();
}

poly lowest_hw(set<poly> * set_op,int nb_bits) {
    int lowest = -1;
    int lowestWeight = nb_bits;
    auto a_supprimer = (*set_op).begin();
    for (auto it = (*set_op).begin(); it != (*set_op).end(); it++) {
        int poids = hammingWeight(*it);
        if (poids < lowestWeight) {
            lowest = *it;
            lowestWeight = poids;
            a_supprimer = it;
        }
    }
    (*set_op).erase(a_supprimer);
    return lowest;
}

void moebius_transform (uint32_t * table, uint32_t nb_elem) {
    uint32_t nb_words = nb_elem/(8*sizeof(uint32_t)) + (nb_elem&0x1f?1:0);

    // For higher order bits.
    for (uint32_t k=1; k<nb_words; k<<=1) {
        for (uint32_t i=0; i<nb_words; i+=k<<1) {
            for (uint32_t j=0; j<k; j++) {
                table[i+k+j] ^= table[i+j];
            }
        }
    }

    // For lower order bits.
    for(uint32_t word_n=0;word_n<nb_words;word_n++) {
        uint32_t tmp = table[word_n];
        tmp^=(tmp&0x55555555)<<1;
        tmp^=(tmp&0x33333333)<<2;
        tmp^=(tmp&0xf0f0f0f)<<4;
        tmp^=(tmp&0xff00ff)<<8;
        tmp^=(tmp<<16);
        table[word_n]=tmp;
    }
}

void truth_table_to_anf (uint32_t * truth_table, uint32_t nb_elem) {
    moebius_transform(truth_table, nb_elem);
}

void anf_to_truth_table (uint32_t * anf, uint32_t nb_elem) {
    moebius_transform(anf, nb_elem);
}

void lut_to_truth_table (uint32_t ** truth_table, uint32_t * lut, uint32_t size_in, uint32_t size_out) {
    uint32_t nb_elem = 1ul<<size_in;
    uint32_t x, fx, bit_n, fx_shift, x_word, x_ind;
    uint32_t word_n, nb_words=nb_elem/(8*sizeof(uint32_t)) + (nb_elem&0x1f?1:0);

    for (bit_n=0; bit_n<size_out; bit_n++)
        for (word_n=0; word_n<nb_words; word_n++)
            truth_table[bit_n][word_n] = 0;

    for (x=0; x<nb_elem; x++) {
        fx = lut[x];
        x_word = x>>5; // x/32
        x_ind = x&0x1f; // x%32
        for (bit_n=0, fx_shift=fx; bit_n<size_out; bit_n++, fx_shift>>=1) {
            truth_table[bit_n][x_word] |= (fx_shift&1ul)<<x_ind;
        }
    }
}

void truth_table_to_lut (uint32_t * lut, uint32_t ** truth_table, uint32_t size_in, uint32_t size_out) {
    uint32_t nb_elem = 1ul<<size_in;
    uint32_t x, bit_n, x_word, x_ind;

    for (x=0; x<nb_elem; x++) {
        x_word = x>>5;
        x_ind = x&0x1f;
        lut[x] = 0;
        for (bit_n=0; bit_n<size_out; bit_n++) {
            lut[x] |= ((truth_table[bit_n][x_word]>>x_ind) & 1ul)<<bit_n;
        }
    }
}

void lut_to_anf (uint32_t ** anf, uint32_t * lut, uint32_t size_in, uint32_t size_out) {
    uint32_t nb_elem = 1ul<<size_in;
    uint32_t nb_words = nb_elem/(8*sizeof(uint32_t)) + (nb_elem&0x1f?1:0);
    uint32_t ** truth_table = (uint32_t**)malloc((size_out)*sizeof(uint32_t*));
    for (uint32_t comp_n=0; comp_n<size_out; comp_n++)
        truth_table[comp_n] = (uint32_t*)malloc(nb_words*sizeof(uint32_t));

    lut_to_truth_table((uint32_t**)truth_table, lut, size_in, size_out);

    for (uint32_t coord_n=0; coord_n<size_out; coord_n++) {
        memcpy(anf[coord_n], truth_table[coord_n], nb_elem/8);
        truth_table_to_anf(anf[coord_n], nb_elem);
    }

    for (uint32_t comp_n=0; comp_n<size_out; comp_n++)
        free(truth_table[comp_n]);
    free(truth_table);
}

vector<poly> anf_to_poly_non_lin(uint32_t ** anf, uint32_t size_in, uint32_t size_out)  {
    vector<poly> Y;
    uint32_t nb_elem = 0x1<<size_in;

    for (uint32_t comp_n=0; comp_n<size_out; comp_n++) {
        poly y = 0;
        for (uint32_t u=0; u<nb_elem; u++) {
            if (((anf[comp_n][u>>5]>>(u&0x1f))&1ul)) {
                uint32_t temp_u = u;
                uint32_t bits_u[size_in];
                for (uint32_t b = 0 ; b<size_in; b++) {
                    bits_u[b] = temp_u&1ul;
                    temp_u >>= 1;
                }
                for (uint32_t b1 = 0; b1<size_in ; b1++) {
                    for (uint32_t b2 = b1+1; b2<size_in; b2++) {
                        if ((bits_u[b1] == bits_u[b2]) && (bits_u[b1] == 1))    {
                            y ^= 1ul << (corres(b1, b2, size_in));
                        }
                    }
                }
            }
        }
        Y.push_back(y);
    }

    return Y;
}

vector<poly> anf_to_poly_lin(uint32_t ** anf, uint32_t size_in, uint32_t size_out)  {

    vector<poly> Y;
    uint32_t nb_elem = 0x1<<size_in;

    for (uint32_t comp_n=0; comp_n<size_out; comp_n++) {
        poly y = 0;
        for (uint32_t u=0; u<nb_elem; u++) {
            if (((anf[comp_n][u>>5]>>(u&0x1f))&1ul)) {
                uint32_t temp_u = u;
                uint32_t bits_u[size_in];
                for (uint32_t b = 0 ; b<size_in; b++) {
                    bits_u[b] = temp_u&1ul;
                    temp_u >>= 1;
                }
                if ( hammingWeight(u) == 1) {
                    for (uint32_t b1 = 0; b1<size_in ; b1++) {
                        if (bits_u[b1] == 1)
                            y ^= 1ul << (size_in - b1 -1 );
                    }
                }
            }
        }
        Y.push_back(y);
    }

    return Y;
}

vector<poly> anf_to_poly_neg(uint32_t ** anf, uint32_t size_in, uint32_t size_out)  {

    vector<poly> Y;
    uint32_t nb_elem = 0x1<<size_in;

    for (uint32_t comp_n=0; comp_n<size_out; comp_n++) {
        poly y = 0;
        for (uint32_t u=0; u<nb_elem; u++) {
            if (((anf[comp_n][u>>5]>>(u&0x1f))&1ul)) {
                if (u==0) {
                    y = 1;
                }
            }
        }
        Y.push_back(y);
    }

    return Y;
}

vector<poly> supp(poly value, vector<poly> Y) {
    vector<poly> res;
    for (uint32_t i = 0; i<Y.size(); i++)   {
        if (Y[i] != value){
            res.push_back(Y[i]);
        }
    }
    return res;
}

vector<vector<poly>> Permutations(const vector<poly>& v) {
    vector<vector<poly>> result;
    vector<poly> sortedV = v;  
    sort(sortedV.begin(), sortedV.end()); 

    do {
        result.push_back(sortedV);
    } while (next_permutation(sortedV.begin(), sortedV.end()));

    return result;
}

vector<set<poly>> remove_duplicates_set(vector<set<poly>> vect_set) {
    set<set<poly>> set_intermediaire;
    vector<set<poly>> res;
    for (uint32_t j=0; j<vect_set.size(); j++)   {
        uint8_t comp = set_intermediaire.size();
        set_intermediaire.insert(vect_set[j]);
        uint8_t taille = set_intermediaire.size();
        if (comp != taille) {
            res.push_back(vect_set[j]);
        }
    }
    return res;
}

void print_monom(poly x, uint32_t nb_bits)   {
    vector<poly> bits_x;
    for (uint32_t b = 0; b < nb_bits ; b++) {
        bits_x.push_back(x&1ul);
        x >>= 1;
    }
    bool affiche = true;
    for (uint32_t i=0; i<nb_bits; i++)   {
        if (bits_x[i] == 1) {
            if (affiche) {
                cout<<"x["<<nb_bits-1-i<<"]";
                affiche = false ;
            }
            else 
                cout<<" ^ x["<<nb_bits-1-i<<"]";
        }
    }
}

uint32_t print_bit_lin_sup(poly x1 ,poly x2 ,uint32_t nb_bits) {
    uint32_t nb_xor = 0;
    vector<poly> bits_x1;
    for (uint32_t b = 0; b < nb_bits ; b++) {
        bits_x1.push_back(x1&1ul);
        x1 >>= 1;
    }
    vector<poly> bits_x2;
    for (uint32_t b = 0; b < nb_bits ; b++) {
        bits_x2.push_back(x2&1ul);
        x2 >>= 1;
    }
    for (uint32_t b = 0; b < nb_bits; b++) {
        if ((bits_x1[b] == bits_x2[b]) && (bits_x1[b] == 1))    {
            cout<<" ^ x["<<nb_bits-1-b<<"]";
            nb_xor ++;
        }
    }
    return nb_xor ;
}
