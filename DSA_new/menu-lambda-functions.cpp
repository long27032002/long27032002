#include <iostream>
using namespace std;

double x = 10, y = 20;

struct {
	const char* title;
	void (*action)();
} menu[] = {
	{ "Multiply", []() {
			cout << x * y << endl;
		}},
	{ "Add", []() {
			cout << x + y << endl;
		} },
	{ "Divide" , []() {
			cout << x / y << endl;
		} },
	{ "Subtract", []() {
			cout << x - y << endl;
		} },
	{ "x + 2y", []() {
			cout << x + 2*y << endl;
		} }
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
