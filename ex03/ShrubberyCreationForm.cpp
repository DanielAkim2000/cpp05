#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream out((this->target + "_shrubbery").c_str());
	if (!out)
		return;
	out << "       _-_\n";
	out << "    /~~   ~~\\\\\n";
	out << " /~~         ~~\\\\\n";
	out << "{               }\n";
	out << " \\\\  _-     -_  /\n";
	out << "   ~  \\\\ //  ~\n";
	out << "_- -   | | _- _\n";
	out << "  _ -  | |   -_\n";
	out << "      // \\\\\n";
}
