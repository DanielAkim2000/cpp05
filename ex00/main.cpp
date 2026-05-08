#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 2);
		std::cout << a;
		a.incrementGrade();
		std::cout << a;
		a.incrementGrade();
		std::cout << a;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Bob", 151);
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Charlie", 149);
		std::cout << c;
		c.decrementGrade();
		std::cout << c;
		c.decrementGrade();
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
