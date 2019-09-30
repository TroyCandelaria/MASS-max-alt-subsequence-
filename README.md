# MASS-max-alt-sum-subsequence-
A dynamic coding solution to findind the value of the maximum alternating sub-sequence using a single table that i thought was an interesting idea

maximum alternating subsequence it a subsequence which follows the patter A+B-C+D-E... where A is before B is before C and so on in the original sequence. The code fids the Maximum possible value of all the potential subsequences.

it uses a single table to store the value of the MASS of all the possible subsequences of smaller sequences from i to j then uses that information to see if that sub sequence should be included in the final subsequence.

also the table is flipped so the diagonal of the table is along the the top row and the top row is along the diagonal. this made working from the diagonal to the top sequential easier for sequential accesses.
