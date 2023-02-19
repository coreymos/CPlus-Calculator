#include "Equation.h"
#include <iostream>

using namespace std;

Equation::Equation() : number1(0.0f), number2(0.0f), name(""), result(0.0f)
{
}

void Equation::initialize()
{
	// Initiliazes the equation by getting number1 and number2
	cout << "Enter the first number: ";
	cin >> number1;

	cout << "Enter the second number: ";
	cin >> number2;

	bool valid = false;
	cin.ignore();
	while (!valid) {
		// Initializes the name variable
		cout << "Enter an operator (+ - / *): ";
		getline(cin, name);
		if (name == "+" || name == "-" || name == "/" || name == "*")
			valid = true;
		else
			cout << "Invalid input!\n";
	}

}

void Equation::display_result()
{
	cout << number1 << " " << name << " " << number2 << " = "
		<< result << endl;
}

float Equation::add()
{
	// Adds the numbers and returns the result
	result = number1 + number2;
	return result;
}

float Equation::subtract()
{
	// Subtracts the numbers and returns the result
	result = number1 - number2;
	return result;
}

float Equation::divide()
{
	// Divides the numbers and returns the result
	result = number1 / number2;
	return result;
}

float Equation::multiply()
{
	// Multiplies the numbers and returns the result
	result = number1 * number2;
	return result;
}

void Equation::set_result(float new_result)
{
	// Sets result to the new_result
	result = new_result;
}

void Equation::determine_result() {
	// Determines the correct string character to display to the user
	if (name == "+")
		add();
	if (name == "-")
		subtract();
	if (name == "/")
		divide();
	if (name == "*")
		multiply();
	display_result();
}