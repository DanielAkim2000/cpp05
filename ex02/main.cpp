#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("marvin");
	PresidentialPardonForm pardon("arthur");

	std::cout << "-- Execute without signing" << std::endl;
	intern.executeForm(shrub);

	std::cout << "\n-- Sign with low grade" << std::endl;
	try
	{
		shrub.beSigned(intern);
	}
	catch (std::exception &e)
	{
		std::cout << "Intern couldn't sign shrubbery because " << e.what() << std::endl;
	}

	std::cout << "\n-- Sign and execute with boss" << std::endl;
	shrub.beSigned(boss);
	robo.beSigned(boss);
	pardon.beSigned(boss);

	boss.executeForm(shrub);
	boss.executeForm(robo);
	boss.executeForm(pardon);

	std::cout << "\n-- Execute with low grade" << std::endl;
	intern.executeForm(pardon);

	return 0;
}
