# EulerConstantCalculator-Using-Randomness
This program uses probability to approximately calculate the value of euler constant.

### Program 1 (using probability)
This program creates a sample of `n` whole numbers in arithmetic progression with common difference of one. The sample is shuffled `trials` times. The program counts the number of shffules that produce derangements. The probability of a shuffle producing a derangement is `1/e` as the sample size and number of trials approach infinity.

### Program 2 (counting derangements)
This program creates a sample of `n` whole numbers in arithmetic progression with common difference of one. All the permutations of the sample are checked for derangements. The number of derangements is equal to:

![derangement formula](http://i.imgur.com/0glC3f9.png)

If we divide the numer of derangements by the total number of possible arrangements, we approximately get the value of `1/e`. The value measured gets more and more accurate as the size of the sample space increases. However, the computation time required also increases rapidly along with it.


More information on derangements: https://en.wikipedia.org/wiki/Derangement
