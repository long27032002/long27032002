#include <iostream>
using namespace std;

double x = 10, y = 20;

class MyAction {
public:
	virtual void exec() const = 0;
};

class AddAction : public MyAction {
public:
	virtual void exec() const {
		cout << x + y << endl;
	}
};


class SubtractAction : public MyAction {
public:
	virtual void exec() const {
		cout << x - y << endl;
	}
};

class MultiplyAction : public MyAction {
public:
	virtual void exec() const {
		cout << x * y << endl;
	}
};

class DivideAction : public MyAction {
public:
	virtual void exec() const {
		cout << x / y << endl;
	}
};


struct {
	const char* title;
	MyAction* action;
} menu[] = {
	{ "Multiply", new MultiplyAction},
	{ "Add", new AddAction },
	{ "Divide" , new DivideAction },
	{ "Subtract", new SubtractAction }
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
	else menu[choice-1].action->exec();

	for (int i = 0; i < n; i++)
		delete menu[i].action;

	return 0;
}
