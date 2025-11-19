#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


const int N = 9;

double G[N][N] = {
	{0, 4, -1, -1, 3.3, -1, -1, -1, -1},
	{4, 0, -1, 1.8, -1, 3.2, 5, -1, -1},
	{-1, -1, 0, -1, -1, -1, -1, 1.2, -1},
	{-1, 1.8, -1, 0, 2, 1.7, -1, -1, -1},
	{3.3, -1, -1, 2, 0, 2.6, 5.7, -1, 4.9},
	{-1, 3.2, -1, 1.7, 2.6, 0, 3, -1, -1},
	{-1, 5, -1, -1, 5.7, 3, 0, -1, 3.8},
	{-1, -1, 1.2, -1, -1, -1, -1, 0, -1},
	{-1, -1, -1, -1, 4.9, -1, 3.8, -1, 0},
};

bool areNeighbors(int i, int j) {
	return G[i][j] > 0;
}

bool isPath(int P[], int n) {
	if (n <= 1) return false;

	for (int i = 0; i < n - 1; i++)
		if (!areNeighbors(P[i], P[i + 1])) return false;

	return true;
}

bool isSimplePath(int P[], int n) {
	if (!isPath(P, n)) return false;

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (P[i] == P[j] && (i != 0 || j != n - 1))
				return false;
		}
	}

	return true;
}

bool isCycle(int P[], int n) {
	return isSimplePath(P, n)
		&& P[0] == P[n - 1];
}

double totalCost(int P[], int n) {
	double c = 0;
	for (int i = 0; i < n - 1; i++)
		c += G[P[i]][P[i + 1]];

	return c;
}



bool areConnected_recursive_helper(int i, int j, int k, int depth) {
	if (k == j) return true;
	if (depth == N) return false;

	for (int l = 0; l < N; l++) {
		if (areNeighbors(k, l)) {
			bool b = areConnected_recursive_helper(i, j, l, depth + 1);
			if (b) return true;
		}
	}

	return false;
}

bool areConnected_recursive(int i, int j) {
	return areConnected_recursive_helper(i, j, i, 0);
}


int main() {
	int P1[] = { 0, 1, 5, 6, 8, 4, 0 };
	int n = sizeof(P1) / sizeof(P1[0]);

	if (areConnected_recursive(1, 7))
		cout << "connected" << endl;
	else cout << "not connected" << endl;


	return 0;
}