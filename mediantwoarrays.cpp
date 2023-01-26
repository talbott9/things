#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

double medianTwoArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	double result;
	std::vector<int> mergedArray;
	for(int i = 0; i < nums1.size(); i++) 
		mergedArray.push_back(nums1[i]);
	for(int i = 0; i < nums2.size(); i++)
		mergedArray.push_back(nums2[i]);
	sort(mergedArray.begin(), mergedArray.end());
	double n = mergedArray.size();
	if(mergedArray.size()%2 == 0)
		result = (mergedArray[n/2]  + mergedArray[n/2 - 1]) / 2.0;
	else
		result = mergedArray[n/2];
	printf("\nMerged array: ");
	for(int i = 0; i < n; i++)
		printf("%i, ", mergedArray[i]);
	return result;
}

int main(int argc, char* argv[]) {
	std::vector<int> nums1 = {1, 3, 67, 3, 123, 43, 4};
	std::vector<int> nums2 = {2, 5, 43, 2, 1, 3, 10, 20, 30, 90};

	printf("\nArray 1: ");
	for(int i = 0; i < nums1.size(); i++)
		printf("%i, ", nums1[i]);
	printf("\nArray 2: ");
	for(int i = 0; i < nums2.size(); i++)
		printf("%i, ", nums2[i]);

	double result = medianTwoArrays(nums1, nums2);

	printf("\nMedian of the two arrays: %g\n", result);
}
