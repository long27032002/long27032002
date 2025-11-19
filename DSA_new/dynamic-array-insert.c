#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void insertElement(int** pa, int* pn, int i, int v) {
	int* b = realloc(*pa, (*pn + 1) * sizeof(int));
	if (b != NULL) {
		memcpy(*pa + (i + 1), *pa + i, (*pn - i) * sizeof(int));
		(*pa)[i] = v;
	}
	else {
		b = malloc((*pn + 1) * sizeof(int));
		memcpy(b, *pa, i * sizeof(int));
		memcpy(b + i + 1, *pa + i, (*pn - i) * sizeof(int));
		b[i] = v;

		free(*pa);
		*pa = b;
	}

	*pn++;
}

void printArray(int* a, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int n = 10;
	int* a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		a[i] = i;

	printArray(a, n);

	insertElement(&a, &n, 5, 100);

	printArray(a, n);

	return 0;
}