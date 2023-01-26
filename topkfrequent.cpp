#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

//Given an integer array nums and an integer k, return the k most 
//frequent elements. You may return the answer in any order.

bool cmp(std::pair<int, int>& a, std::pair<int, int>& b) {
	return a.second > b.second;
}

std::vector<std::pair<int, int>> sort(std::map<int, int>& inputMap) {
	std::vector<std::pair<int, int>> pairVector;
	for(const auto& it : inputMap) {
		pairVector.push_back(it);
		//std::cout << it.first << "/" << it.second << std::endl;
	}
	
	sort(pairVector.begin(), pairVector.end(), cmp);

	return pairVector;
}

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
	std::vector<int> result;
	std::map<int, int> freqMap;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < nums.size(); j++) {
			if(i == nums[j])
				freqMap[i]++;
		}
	}
	std::vector<std::pair<int, int>> sortedMap = sort(freqMap);
	for(int i = 0; i < k; i++) {
		result.push_back(sortedMap[i].first);
		//std::cout << sortedMap[i].first << "/" << sortedMap[i].second << std::endl;
	}
	return result;
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
	std::vector<int> nums;
	std::string input;
	int k;
	printf("\n\"Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.\"\nUse commas with no spaces in between (ex.: 3,2,3,1).");
	while(true) {
		printf("\n\nArray: ");
		std::cin >> input;
		nums = parseStringToVector(input);
		printf("k: ");
		std::cin >> input;
		k = std::stoi(input);
		std::vector<int> result = topKFrequent(nums, k);
		printf("%i most frequent integers: ", k);
		for(int i = 0; i < result.size(); i++) {
			printf("%i", result[i]);
			if(i != result.size() - 1)
				printf(", ");
		}
	}
	return 0;
}
