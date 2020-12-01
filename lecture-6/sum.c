#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char** argv) {
	if (argc > 1) {
		int sum = 0;
		for (int i = 1; i < argc; ++i) {
			int value = (int)strtol(argv[i], NULL, 0);
			sum += value;
		}
		printf("%d", sum);
		return EXIT_SUCCESS;
	}
	
	int n = 0;
	if (1 != scanf("%d", &n))
		return EXIT_FAILURE;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int value = 0;
		if (1 != scanf("%d", &value))
			return EXIT_FAILURE;
		sum += value;
	}
	printf("%d", sum);
}