#include <cstdio>
#include <string>
#include <iostream>

//Given two strings s and t, return true if t is an anagram of s, 
//and false otherwise.

bool caseSensitive;

bool isAnagram(std::string s, std::string t) {
	bool success = false;

	if(s.size() == t.size()) {
		for(int i = 0; i < s.size(); i++) {
			int counter1 = 0;
			int counter2 = 0;
			for(int j = 0; j < s.size(); j++) {
				if(!caseSensitive) {
					if(tolower(s[i]) == tolower(s[j]))
						counter1++;
					if(tolower(s[i]) == tolower(t[j]))
						counter2++;
				} else {
					if(s[i] == s[j])
						counter1++;
					if(s[i] == t[j])
						counter2++;
				}
			}
			if(counter1 == counter2) {
				success = true;
			} else {
				success = false;
				break;
			}
		}
	}

	return success;
}

int main(int argc, char* argv[]) {
	std::string string1;
	std::string string2;
	printf("\nValid anagrams. If two strings are anagrams, return 1. Else, return 0. Use only spaces to separate the strings (ex: cupboard cpuardob)\n");
	while(string1 != "y" && string1 != "n") {
		printf("Case sensitive? (y or n) ");
		std::cin >> string1;
	}
	if(string1 == "y")
		caseSensitive = 1;
	else
		caseSensitive = 0;
	while(string1 != "q") {
		std::cout << "\nStrings: ";
		std::cin >> string1 >> string2;
		printf("Anagram: %b\n", isAnagram(string1, string2));
	}
	return 0;
}
