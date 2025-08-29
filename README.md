# implem-quad-sbox

## Name
Lightweight quadratic S-box implementation tool

## Description
This tool allows to implement any quadratic S-box of up to 9/10 bits if you have a large amount of computing power available, on up to 7 bits on standard computers.
Implementations are bitsliced circuits with low AND-depth and number of AND gates, fit for side-channel protections such as masking.
This tool corresponds to the IEEE-TCAS article "A New Tool to Find Lightweight (AND, XOR) Implementations of Quadratic Vectorial Boolean Functions up to Dimension 9" by Marie Bolzer, Sébastien Duval and Marine Minier.

## Installation

To install, clone this repository from git.

Usually, you should first start by preparing the precomputation files.
This is done by the two following commands (from the base git directory):

make precomputation_program
make precomputation_files MAX_SIZE=7

where the value 7 should be replaced with the maximum S-box size you wish to consider.
Be careful about the choice of this size, as it is the main factor determining memory usage.
Most computers should be able to handle up to 7 bits, but only dedicated machines can handle 9 bits, and very expensive dedicated machines can handle 10 bits.

## Usage

Then, launch the program on your given S-box using a command of the following type:

./implem_{YOUR_COMPUTER_NAME} -s 3 -a 4 -l 0,1,4,5,3,2,7,6,12,13,8,9,15,14,11,10 -t 10

where -s 3 asks the tool for 3 implementation solutions,
where -a 4 tells the tool to cut short if the implementation costs more than 4 AND gates,
where -l 0,1,4,5,3,2,7,6,12,13,8,9,15,14,11,10 specifies your S-box (here a 4-bit S-box) in Look-up-Table form,
where -t 10 will cut the program after 10 minutes.
You also can specify -p 0 if you do not want to use the precomputation files. By default, they are used.

The output will be a C function which implements your S-box.

## Support

For details on the tool, please read the article.

In case of need, please contact Marie Bolzer <marie.bolzer@univ-lorraine.fr> and Sébastien Duval <sebastien.duval@loria.fr>.

## Roadmap
In the future, we plan to make the tool work on more than quadratic S-boxes.

## Contributing
If you wish to contribute, please contact us to discuss ideas.

## Authors and acknowledgment
A tool provided by Marie Bolzer and Sébastien Duval.
