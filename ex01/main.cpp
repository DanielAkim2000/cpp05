#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 5);
		Form leaveForm("LeaveRequest", 5, 10);

		alice.signForm(leaveForm);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bob("Bob", 50);
		Form topSecret("TopSecret", 10, 5);

		bob.signForm(topSecret);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Form invalid("Invalid", 0, 151);
		std::cout << invalid;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Form invalid("Invalid", 0, 0);
		std::cout << invalid;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
