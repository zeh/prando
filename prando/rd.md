# Runs Test
The runs test can be used to test the assumption that the pseudo-random numbers are
independent of each other. We start with a sequence of pseudo-random numbers in [0,1].
We then look for unbroken subsequences of numbers, where the numbers within each
subsequence are monotonically increasing. Such a subsequence is called a run up, and it
may be as long as one number.
For example, let us consider the sequence: 0.8, 0.7, 0.75, 0.55, 0.6, 0.7, 0.3, 0.4,
0.5. Starting from the beginning of this sequence, i.e., from the left, we find a run up of
44 Computer Simulation Techniques
length 1, i.e. 0.8, then a run up of length 2, i.e. 0.7, 0.75, followed by two successive run
ups of length 3, i.e. 0.55, 0.6, 0.7, and 0.3, 0.4, 0.5.
In general, let ri be the number of run ups of length i. (In the above example we
have r1=1, r2=1, r3=2.) All run-ups with a length i≥6 are grouped together into a single
run-up. The ri values calculated for a particular sequence are then used to calculate the
following statistic:
R =1/n{(ri − nbi)(rj − nbj)aij}; 1≤i≤6, 1≤j≤6,
where n is the sample size and bi, i=1,...6, and aij are known coefficients. The aij
coefficient is obtained as the (i,j)th element of the matrix
  4529.4 9044.9 13568 18091 22615 27892
  9044.9 18097 27139 36187 45234 55789
  13568 27139 40721 54281 67852 83685
  18091 36187 54281 72414 90470 111580
  22615 45234 67852 90470 113262 139476
  27892 55789 83685 111580 139476 172860
 ,
and the bi coefficient is obtained as the ith element of the vector
(b1,...,b6) = (1/6 , 5/24 ,11/120 ,19/720 , 29/5040 , 1/840 )

