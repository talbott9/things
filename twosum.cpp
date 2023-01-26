#include <cstdio>
#include <vector>
#include <iostream>

//Given an array of integers nums and an integer target, 
//return indices of the two numbers such that they add up to target.

const int NUMBER_OF_INTS = 100;

std::vector<int> twoSum(std::vector<int> nums, int target) {
	std::vector<int> indices = {0, 0};
	for(int i = 0; i < nums.size(); i++) {
		for(int j = 0; j < nums.size(); j++) {
			if(nums[i] + nums[j] == target)
				indices = {i, j};
		}
	}
	return indices;
}

int main(int argc, char* argv[]) {
	printf("\n\"Given an array of integers nums and an integer target, return indices of two numbers such that they add up to target.\"\nUse only spaces to separate the numbers (ex.: 1 2 3 4).\n\n");
	while(true) {
		std::vector<int> nums;
		std::string numbers[NUMBER_OF_INTS];
		int target;
		printf("Array: ");
		for(int i = 0; i < NUMBER_OF_INTS; i++) {
			std::cin >> numbers[i];
			if(std::cin.peek() == '\n')
				break;
		}
		for(int i = 0; i < NUMBER_OF_INTS; i++) {
			if(numbers[i] != "")
				nums.push_back(std::stoi(numbers[i]));
		}
		printf("Target: ");
		std::cin >> target;
		std::vector<int> result = twoSum(nums, target);
		if(nums[result[0]] + nums[result[1]] == target) {
			printf("Indices that add up to target: [%i, %i]\n(%i + %i == %i)\n\n", result[0], result[1], nums[result[0]], nums[result[1]], nums[result[0]] + nums[result[1]]);
		} else {
			printf("None of those numbers add up to target.\n\n");
		}
	}
}
