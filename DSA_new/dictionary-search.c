#include <stdio.h>
#include <string.h>



int search_range(const char* dict[], int l, int r, const char* word) {
	if (l > r) return -1;

	int k = (l + r) / 2;
	int t = strcmp(word, dict[k]);

	if (t == 0) 
		return k;
	if (t < 0) return search_range(dict, l, k - 1, word);
	return search_range(dict, k + 1, r, word);
}

int search(const char* dict[], int n, const char* word) {
	return search_range(dict, 0, n - 1, word);
}


int main() {
	const char* dict[] = {
		"a",
		"abc",
		"cable",
		"car",
		"cartoon",
		"door",
		"empty",
		"fool",
		"foot",
		"football",
		"goal",
		"goat",
		"god",
		"hell",
		"ink",
		"tap",
		"work",
		"worker"
	};
	const int n = sizeof(dict) / sizeof(dict[0]);

	int i = search(dict, n, "truck");

	printf(i == -1 ? "Not found\n" : "Found at %d\n", i);

	return 0;
}