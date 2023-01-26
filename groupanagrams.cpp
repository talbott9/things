#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

//Given an array of strings strs, group the anagrams together. You can return the answer in any order.

//Warning: extremely inefficient.

//std::vector<std::string> strings = {"anagram","aanrgam","cat","rat","tar","man", "art", "santouka", "toukasan", "kansatou", "ayatsuji", "tayjuisa", "nam", "nagraam"};
//

const int NUMBER_OF_STRINGS = 100;

bool compareVector(std::vector<std::string> stringVector1, std::vector<std::string> stringVector2) {
	std::vector<std::string> v1 = stringVector1;
	std::vector<std::string> v2 = stringVector2;
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
       	return v1 == v2;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> strings) {
	std::vector<std::vector<std::string>> result;
	for(int i = 0; i < strings.size(); i++) {
		bool matches = 0;
		size_t counter1 = 0;
		size_t counter2 = 0;
		std::vector<std::string> array;
		//Compare two strings, see if the same letters occur
		//the same number of times, group them in the same array
		//then add it to the array array
		for(int j = 0; j < strings.size(); j++) {
			if(strings[i].size() == strings[j].size() && strings[i] != strings[j]) {
				for(int k = 0; k < strings[i].size(); k++) {
					for(int l = 0; l < strings[i].size(); l++) {
						if(strings[i][k] == strings[j][l])
							counter1++;
						if(strings[i][k] == strings[i][l])
							counter2++;
					}
					if(counter1 == counter2) {
						matches = 1;
					} else {
						matches = 0;
						break;
					}
				}
				//std::cout << strings[i] << counter2 << "/" << strings[j] << counter1<< matches << std::endl;
				if(matches)
					array.push_back(strings[j]);
			}
			counter1 = 0; counter2 = 0;
		}
		array.push_back(strings[i]);
		result.push_back(array);
	}
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result.size(); j++) {
			if(i != j && compareVector(result[i], result[j]))
				result.erase(result.begin()+j);
		}
	}
	return result;
}

int main(int argc, char* argv[]) {
	printf("\nGrouped anagrams. Checks if strings in a given array are anagrams and groups them together.\nUse only spaces to separate strings (ex: anagram aanramg ayatsuji tsujiaya santouka kansatou).\n\n");
	while(true) {
		std::string stringArray[NUMBER_OF_STRINGS];
		std::vector<std::string> strings;
		printf("Array: ");
		for(int i = 0; i < NUMBER_OF_STRINGS; i++) {
			std::cin >> stringArray[i];
			if(std::cin.peek() == '\n')
				break;
		}
		for(int i = 0; i < NUMBER_OF_STRINGS; i++) {
			if(stringArray[i] != "")
				strings.push_back(stringArray[i]);
		}
		printf("Grouped anagrams: ");
		std::vector<std::vector<std::string>> result = groupAnagrams(strings);
		for(int i = 0; i < result.size(); i++) {
			printf("[");
			for(int j = 0; j < result[i].size(); j++) {
				std::cout << result[i][j];
				if(j != result[i].size() - 1)
					printf(", ");
			}
			printf("]");
		}
		printf("\n\n");
	}
	return 0;
}
