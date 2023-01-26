#include <string>
#include <iostream>

std::string lowerAndJoin(std::string inputString) {
	char c;
	std::string s;
	for(int i = 0; i < inputString.size(); i++) {
		c = inputString[i];
		if(isalpha(c))
			s += std::tolower(c);
	}
	return s;
}

bool isPalindrome(std::string inputString) {
	bool success = true;
	std::string s = lowerAndJoin(inputString);
	size_t n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] != s[n - i - 1])
			success = false;
	}
	return success;
}

int main(int argc, char* argv[]) {
	printf("\n\"Given a string s, return 1 if it is a palindrome, or 0 otherwise.\"\n");
	std::string string = "A man, a plan, a canal: Panama";
	std::cout << "\nString: " << string << "\nPalindrome: " << isPalindrome(string);
	string = "Race a car";
	std::cout << "\nString: " << string << "\nPalindrome: " << isPalindrome(string);
	printf("\n");
}
