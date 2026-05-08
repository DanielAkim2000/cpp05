#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Bureaucrat boss("Boss", 1);
	Bureaucrat low("Intern", 150);
	Intern someRandomIntern;

	std::cout << "-- Make forms" << std::endl;
	AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm *robo = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
	AForm *unknown = someRandomIntern.makeForm("unknown form", "target");

	std::cout << "\n-- Execute without signing" << std::endl;
	if (shrub)
		low.executeForm(*shrub);

	std::cout << "\n-- Sign with low grade" << std::endl;
	try
	{
		if (shrub)
			shrub->beSigned(low);
	}
	catch (std::exception &e)
	{
		std::cout << "Intern couldn't sign shrubbery because " << e.what() << std::endl;
	}

	std::cout << "\n-- Sign and execute with boss" << std::endl;
	if (shrub)
		shrub->beSigned(boss);
	if (robo)
		robo->beSigned(boss);
	if (pardon)
		pardon->beSigned(boss);

	if (shrub)
		boss.executeForm(*shrub);
	if (robo)
		boss.executeForm(*robo);
	if (pardon)
		boss.executeForm(*pardon);

	std::cout << "\n-- Execute with low grade" << std::endl;
	if (pardon)
		low.executeForm(*pardon);

	delete shrub;
	delete robo;
	delete pardon;
	delete unknown;

	return 0;
}
