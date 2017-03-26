#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cmath>
#include <cfloat>
#include <random>
#include <numeric>
#include <algorithm>

/*****************************************************************************************/
// Wrapper for random number generator (RNG)
/*****************************************************************************************/
typedef std::uint_fast32_t random_num_type;

std::random_device seed_generator;
std::mt19937 gen(seed_generator());

/*****************************************************************************************/
// Check if the squence is a derangement
/*****************************************************************************************/
bool isderangement(random_num_type *nums, random_num_type size)
{
	for (random_num_type i = 0; i < size; i++)
	{
		if (nums[i] == i)
			return false;
	}
	return true;
}

/*****************************************************************************************/
int main()
{
	random_num_type n = 0, trials = 0, count_derangements = 0;
	std::cout << "Enter sample size: ";
	std::cin >> n;	

	random_num_type *nums = new random_num_type[n];
	std::iota(nums, nums + n, 0); //fill the array with whole numbers starting from 0 (0, 1, 2, 3, 4 ..., n - 1)

	std::cout << "Enter the number of trials to use: ";
	std::cin >> trials;

	random_num_type trials_per_percent = trials / 100;
	for (random_num_type i = 0; i < trials; i++)
	{		
		std::shuffle(nums, nums + n, gen); //random shuffle
		if (isderangement(nums, n))
			count_derangements++;

		if (i%trials_per_percent == 0) std::cout << ".";
	}
	
	double e = (static_cast<double>(trials)) / (count_derangements);
	std::cout << std::endl << "Out of " << trials << " random shuffles, " << count_derangements << " shuffles created derangements." << std::endl;
	std::cout << std::setprecision(DBL_DIG) << "Approximate value of e is: " << e;
	std::cin >> trials;

	delete[] nums;
	return 0;
}
