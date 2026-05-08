#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	typedef AForm *(Intern::*CreateFn)(const std::string &target);
	struct FormEntry
	{
		const char *name;
		CreateFn create;
	};

	AForm *createRobotomy(const std::string &target);
	AForm *createShrubbery(const std::string &target);
	AForm *createPresidential(const std::string &target);

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string name, std::string target);
};

#endif
