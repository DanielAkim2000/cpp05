#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Bureaucrat::Bureaucrat() : name("unamed"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name) : name(name), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->setGrade(other.getGrade());
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade(void)
{
	this->setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	this->setGrade(grade + 1);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

const std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (o);
}
