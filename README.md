# implem-quad-sbox

## Name
Lightweight quadratic S-box bitsliced implementation tool

## Description
This tool allows to implement any quadratic S-box of up to 9/10 bits if you have a large amount of computing power available, on up to 7 bits on standard computers.

## Installation

To install, clone this repository from git.

Usually, you should first start by preparing the precomputation files.
This is done by the two following commands (from the base git directory):

`make precomputation_program`

`make precomputation_files MAX_SIZE=7`

where the value 7 should be replaced with the maximum S-box size you wish to consider.
Be careful about the choice of this size, as it is the main factor determining memory usage.
Most computers should be able to handle up to 7 bits, but only dedicated machines can handle 9 bits, and very expensive dedicated machines can handle 10 bits.

## Usage

Then, launch the program on your given S-box using a command of the following type:

`./implem_{YOUR_COMPUTER_NAME} --solmax 3 --andmax 4 --lut 0,1,4,5,3,2,7,6,12,13,8,9,15,14,11,10 --timemax 10`

where `--solmax 3` asks the tool for 3 implementation solutions,
where `--andmax 4` tells the tool to cut short if the implementation costs more than 4 AND gates,
where `--lut 0,1,4,5,3,2,7,6,12,13,8,9,15,14,11,10` specifies your S-box (here a 4-bit S-box) in Look-up-Table form,
where `--timemax 10` will cut the program after 10 minutes.

The output will be a C function which implements your S-box.

## Support

For details on the tool, please read the article (https://doi.org/10.1109/TCSI.2025.3602151).

In case of need, please contact Marie Bolzer and Sébastien Duval (e-mails in article).

## Roadmap
In the future, we plan to make the tool work on more than quadratic S-boxes.

## Contributing
If you wish to contribute, please contact us to discuss ideas.

## Authors and acknowledgment
A tool provided by Marie Bolzer and Sébastien Duval.

## Results
Results of appyling the tool can be found in the article (https://doi.org/10.1109/TCSI.2025.3602151).

### Updated results
After a nice work by Totó Busnello who checked our results up to 6-bit functions via a SAT solver and found lower bounds for the number of required AND gates for some functions, he spotted a few typos that we detail below for clarity and found a better implementation than our 9-AND BL_ECCZ_1 in the paper with 8 AND. This allowed us to spot a bug in the tool that prevented us from exploring a (rarely but sometimes useful) part of the search space. The tool has been updated and now also finds an 8-AND, 35-XOR implementation for BL_ECCZ_1.

Typos:
- in Table IX of the paper, we write that the linearity of BL_ECCZ_11 is 16, but it is 32,
- in the Supplementary Material, there is a small mistake in the implementation of S_2260. `q5 = (l13 × l8) ⊕ x5` should be replaced by `q5 = (l13 × l8) ⊕ l0`,
- the primitive polynomials used in the article do not always match the primitive polynomials used in the implementations in the Supplementary Material, in particular over 6 bits we actually used X⁶+X⁴+X³+X+1 and not X⁶+X⁴+X²+X+1 as was written in the paper.

We thank Totó Busnello for checking our results and finding these discrepancies.
