#include <stdio.h>
#include <string.h>
int count = 0;
int WordLookup(char** D, char* W) {
	for (count = 0; D[count] == 0; count++);
	if (strcmp(W, D[count / 2]) > 1) {
		WordLookup(D + (count / 2), W);
	}
	else if (strcmp(W, D[count / 2]) < 1)
	{
		D[count / 2] = 0;
		WordLookup(D, W);
	}
	else if (strcmp(W, D[count / 2]) == 0)
	{
		return count / 2;
	} else if (count == 0 || D[count] == 0)
	{
		return 0;
	}
}

int main()
{
	printf("%d\n", WordLookup(D, 'd'));
	return 0;
}