#include <string>
#include <memory>

using namespace std;

class Equation
{
private:
	float number1;
	float number2;
	string name;
	float result;


public:
	Equation();

	void initialize();
	void display_result();

	float add();
	float subtract();
	float divide();
	float multiply();

	void determine_result();
	void set_result(float new_result);
};