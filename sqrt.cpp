#include <cstdio>

double abs(double x) {
	if(x >= 0) {
		return x;
	} else {
		return -x;
	}
}

double sqrt(double radicand) {
	double root;
	double guess = 1;
	while(abs(root - guess) > 0.001) {
		root = radicand/guess;
		guess = (root + guess)/2;
	}
	return guess;
}

double cbrt(double radicand) {
	double root;
	double guess = 1;
	while(abs(root - guess) > 0.001) {
		root = radicand/guess/guess;
		guess = (root/sqrt(guess) + 2*guess)/3;
	}
	return guess;
}

int main(int argc, char* argv[]) {
	const int NUMBER_OF_INTS = 8;
	int radicand[NUMBER_OF_INTS] = {2, 9, 8, 100, 25, 36, 49, 564656456};
	for(int i = 0; i < NUMBER_OF_INTS; i++)
		printf("\nRadicand: %i, Square root: %g, Cube: %g", radicand[i], sqrt(radicand[i]), cbrt(radicand[i]));
	printf("\n");
}
