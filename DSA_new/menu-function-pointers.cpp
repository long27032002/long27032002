#include <iostream>
using namespace std;

double x = 10, y = 20;

void add() {
	cout << x + y << endl;
}

void subtract() {
	cout << x - y << endl;
}

void multiply() {
	cout << x * y << endl;
}

void divide() {
	cout << x / y << endl;
}

void xplus2y() {
	cout << (x + 2 * y) << endl;
}


struct {
	const char* title;
	void (*action)();
} menu[] = {
	{ "Multiply", multiply },
	{ "Add", add },
	{ "Divide" , divide },
	{ "Subtract", subtract },
	{ "x + 2y", xplus2y }
};

const int n = sizeof(menu) / sizeof(menu[0]);


int main() {

	cout << "Choose an option: \n";
	for (int i = 1; i <= n; i++)
		cout << i << ". " << menu[i-1].title << endl;
	cout << "Your choice: ";

	int choice;
	cin >> choice;

	if (choice <= 0 || choice > n) cout << "Invalid choice" << endl;
	else menu[choice-1].action();

	return 0;
}
