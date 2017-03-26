#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cmath>
#include <cfloat>
#include <random>
#include <numeric>
#include <algorithm>

/*****************************************************************************************/
// Check if the squence is a derangement
/*****************************************************************************************/
bool isderangement(int *nums, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (nums[i] == i)
			return false;
	}
	return true;
}

/*****************************************************************************************/
int main()
{
	int n = 0, total_arrangements = 0, count_derangements = 0;
	std::cout << "Enter sample size: ";
	std::cin >> n;	

	int *nums = new int[n];
	std::iota(nums, nums + n, 0); //fill the array with whole numbers starting from 0 (0, 1, 2, 3, 4 ..., n - 1)

	total_arrangements = 1;
	for (int i = 1; i <= n; i++)
		total_arrangements *= i;

	while (std::next_permutation(nums, nums + n))
	{
		if (isderangement(nums, n))
			count_derangements++;
	}
	
	double e = (static_cast<double>(total_arrangements)) / (count_derangements);
	std::cout << std::endl << "Out of " << total_arrangements << " random shuffles, " << count_derangements << " shuffles created derangements." << std::endl;
	std::cout << std::setprecision(DBL_DIG) << "Approximate value of e is: " << e;
	std::cin >> total_arrangements;

	delete[] nums;
	return 0;
}
