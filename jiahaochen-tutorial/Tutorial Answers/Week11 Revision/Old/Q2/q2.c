//
// Question 2 - Limits of parallelism
//

/*

Speedup is limited by the total time needed for the sequential (serial) part of the program


	Part 1

	10% sequential and 90% parallel with 4 processors used.

	0.1 + (0.9 / 4) = 0.1 + 0.225
	                = 0.325

	1 / 0.325 ~= 3x speedup

	Part 2

	90% sequential and 10% parallel with 32 processors used.

	0.9 + (0.1 / 32) = 0.9 + 0.003125
	                 = 0.903125

	1 / 0.903125 ~= 1.1x speedup

	Part 3

	5% sequential and 95% parallel with an unlimited number of processors.

	0.05 + (0.95 / inf) = 0.05

	1 / 0.05 ~= 20x speedup
*/
