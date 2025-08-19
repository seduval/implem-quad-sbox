#include "config.h"
#include "precalcul.h"
#include "poly.h"
#include "non_lin.h"
#include "lin.h"
#include "get_and_print_implem.h"

using namespace std;

int main(int argc, char **argv)  {

    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "Time is " << ctime(&now) << endl;

    int nb_sol = -1; //Par défault, on renvoie toutes les solutions
    uint8_t nb_and_max = 0; //Par défault, on suppose le nombre de AND voulu inconnu
    uint64_t time_max = 0;
    vector<uint32_t> v_lut;
    uint32_t nb_elem = 0;
    uint32_t size_in = 0;
    uint32_t size_out = 0;
    uint8_t precomputed_files = 1; //Par défault, on utilise les fichiers de precalcul

    option longopts[] = {
        {"cut_nuplet", optional_argument, NULL, 'c'},
        {"precomputed_files", optional_argument, NULL, 'p'},
        {"lut", required_argument, NULL, 'l'},
        {"solmax", optional_argument, NULL, 's'},
        {"andmax", optional_argument, NULL, 'a'},
        {"timemax", required_argument, NULL, 't'},
        {"help", no_argument, NULL, 'h'}
    };
    int opt;
    while ((opt = getopt_long(argc, argv, "l:s:a:t:p:h", longopts, 0)) != -1) {
        switch (opt) {
             case 'h': {
                cout<<" The option '--lut' or '-l' requires the values of the LUT separated by ','"<<endl
                <<" For example: '-l 0,1,5,4,8,3,7,2'"<<endl
                <<" The number of values must be a power of 2 beetween 8 and 512"<<endl
                <<" The option ' --timemax' or '-t' requires the time you are willing to wait (in minutes) "<<endl
                <<" The other options are optionnal : "<<endl
                <<" The option ' --andmax' or '-a' allows you to choose a maximum for the number of AND gates wanted in the implementation"<<endl
                <<" The option '--solmax' or '-s' allows you to choose the number of different solutions wanted, by default the programm will try to find all of them"<<endl
                <<" The option '--precomputed_files' or '-p' allows you to not use the precomputed files, to do so give '0' "<<endl
                <<" By default this option is used if all the solutions are not wanted, if you don't want it give 0"<<endl;
                exit(0);
            }
            case 'l':   {
                string lut_values (optarg);
                istringstream iss(lut_values);
                string value;
                while (getline(iss, value, ',')) {
                    v_lut.push_back(stoi(value));
                }
                nb_elem = v_lut.size();
                if ((nb_elem > 512) || (nb_elem < 8) || (hammingWeight(nb_elem) != 1)) {
                    cout<<"The number of values in the LUT must be a power of 2 beetween 8 and 512 "<<endl;
                    exit(0);
                }
                size_in = log2(nb_elem);
                size_out = size_in;
                break;
            }
            case 's': {
                nb_sol = atoi(optarg);
                break;
            }
            case 'a': {
                nb_and_max = atoi(optarg);
                break;
            }
            case 't': {
                time_max = atoi(optarg)*60;
                break;
            }
            case 'p' : {
                precomputed_files = atoi(optarg);
                break;
            }
            default:
                cerr << "Unknown program argument " << opt << endl;
        }
    }

    if (time_max == 0){
        cerr<<"You need to indicate a time limit with the option '--time_max'"<<endl;
        exit(0);
    }

    uint32_t lut [nb_elem];
    for (uint32_t i=0; i<nb_elem; i++)  {
        lut[i] = v_lut[i];
    }

    lut_to_implems(lut, size_in, size_out, nb_sol, nb_and_max, time_max, precomputed_files);
   
    exit(0);
}