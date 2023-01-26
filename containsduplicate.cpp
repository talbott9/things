#include <iostream>
#include <cstdio>
#include <vector>

//Given an integer array nums, return true if any value appears at least twice 
//in the array, and return false if every element is distinct.

bool containsDuplicate(std::vector<int> nums) {
	bool success = false;
	for(int i = 0; i < nums.size(); i++) {
		int counter = 0;
		for(int j = 0; j < nums.size(); j++) {
			if(nums[i] == nums[j])
				counter++;
		}
		if(counter >= 2)
			success = true;
	}
	return success;
}

std::vector<int> parseStringToVector(std::string inputString) {
	std::vector<int> result;
	std::string string;
	char c;
	//printf("%i\n", inputString.size());
	for(int i = 0; i < inputString.size(); i++) {
		c = inputString[i];
		if(i != inputString.size() - 1) {
			if(!ispunct(c)) {
				string += c;
			} else {
				result.push_back(std::stoi(string));
				string = "";
			}
		} else {
			if(isdigit(c))
				string += c;
			result.push_back(std::stoi(string));
			string = "";
		}
	}
	return result;
}

int main(int argc, char* argv[]) {
	std::string input;
	std::vector<int> nums;
	printf("\nContains duplicates. If an array contains duplicates, return 1. Else, return 0.\nUse commas with no spaces in between (ex.: 3,2,3,1).\n");
	while(input != "q" && input != "quit") {
		printf("\nInput array: ");
		std::cin >> input;
		nums = parseStringToVector(input);
		for(int i = 0; i < nums.size(); i++) {
			printf("%i", nums[i]);
				if(i != nums.size() - 1)
					printf(", ");
		}
		printf("\n");
		printf("Contains duplicate: %b\n", containsDuplicate(nums));
	}
}
