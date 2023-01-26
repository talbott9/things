#include <vector>
#include <cstdio>
#include <iostream>

//O(n^2)

std::vector<int> productExceptSelf(std::vector<int>& nums) {
	std::vector<int> answer;

	for(int i = 0; i < nums.size(); i++) {
		int product = 1;
		for(int j = 0; j < nums.size(); j++) {
			if(i != j) {
				product *= nums[j];
			}
		}
		answer.push_back(product);
	}

	return answer;
}

int main(int argc, char* argv[]) {
	std::vector<int> nums = {1,2,3,4};
	std::vector<int> answer = productExceptSelf(nums);
	printf("\n\"Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].\"\n\nArray: ");
	for(int i= 0; i < nums.size(); i++)
		printf("%i, ", nums[i]);
	printf("\nProducts except self: ");
	for(int i = 0; i < nums.size(); i++)
		printf("%i, ", answer[i]);
	printf("\n");
	return 0;
}
