#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	static const FormEntry entries[] = {
		{"robotomy request", &Intern::createRobotomy},
		{"shrubbery creation", &Intern::createShrubbery},
		{"presidential pardon", &Intern::createPresidential}};

	for (int i = 0; i < 3; i++)
	{
		if (name == entries[i].name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*entries[i].create)(target);
		}
	}

	std::cout << "Intern cannot create form: " << name << " because form does not exist " << std::endl;
	return NULL;
}
