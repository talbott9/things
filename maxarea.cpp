#include <vector>
#include <cstdio>

int maxArea(std::vector<int>& height) {
	int result, width, highestArea;
	size_t n = height.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			width = j - i; 
			int actualHeight = height[i] > height[j] ? height[j] : height[i];
			highestArea = width*actualHeight;
			if(highestArea > result)
				result = highestArea;
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	printf("\nYou are given an integer array height of length n.\nThere are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).\nFind two lines that together with the x-axis form a container, such that the container contains the most water.\n");
	std::vector<int> height = {1,8,6,2,5,4,8,3,7};
	size_t n = height.size();
	printf("\nHeights: ");
	for(int i = 0; i < n; i++)
		printf("%i, ", height[i]);
	printf("\nMaximum area: %i\n", maxArea(height));
}
