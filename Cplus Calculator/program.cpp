#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include "equation.h"

using namespace std;

void add_equation(list<Equation>& log_history);
void display_log(list<Equation>& log_history);
void clear_log(list<Equation>& log_history);

int main()
{
	list<Equation> math_equations;
	bool done = false;

	while (!done) {
		int choice = -1;
		bool valid = !(0 <= choice <= 5);

		// Menu Interface that gets an input and does the desired action
		cout << "Calculator Menu:\n0. Quit Program\n1. Enter an equation\n2. Display Log\n3. Clear Log\n";
		while (!valid) {
			cout << "Your choice: ";
			cin >> choice;
			if (!(0 <= choice <= 3))
				cout << "Invalid input, please type an integer (0-3)\n";
			else
				valid = true;
		}

		if (choice == 0)
			done = true;
		else if (choice == 1)
			add_equation(math_equations);
		else if (choice == 2)
			display_log(math_equations);
		else if (choice == 3)
			clear_log(math_equations);
	}
}

void display_log(list<Equation>& log_history) {
	// Iterates through the log and displays each item
	list<Equation>::iterator it;
	for_each(log_history.begin(), log_history.end(),
		[](auto& math_equations) {
			math_equations.display_result();
		}
	);
	cout << endl;
}

void add_equation(list<Equation>& log_history) {
	// Initializes an equation object and then adds it to the log
	Equation equation;
	equation.initialize();
	equation.determine_result();
	log_history.push_back(equation);
}

void clear_log(list<Equation>& log_history) {
	// Clears the log
	log_history.clear();
	cout << "Log cleared!\n";
}