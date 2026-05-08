#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Form::Form() : name("unamed"), isSigned(false), gradeRequiredSign(5), gradeRequiredExec(10)
{
}

Form::Form(const std::string name, int gradeSign, int gradeExec)
	: name(name), isSigned(false), gradeRequiredSign(gradeSign), gradeRequiredExec(gradeExec)
{
	if (gradeRequiredSign > 150 || gradeRequiredExec > 150)
		throw Form::GradeTooLowException();
	if (gradeRequiredSign < 1 || gradeRequiredExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned), gradeRequiredSign(other.gradeRequiredSign), gradeRequiredExec(other.gradeRequiredExec)
{
	if (gradeRequiredSign > 150 || gradeRequiredExec > 150)
		throw Form::GradeTooLowException();
	if (gradeRequiredSign < 1 || gradeRequiredExec < 1)
		throw Form::GradeTooHighException();
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat &burr)
{
	if (burr.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else
		setSigned(true);
}

const std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int Form::getGradeExec(void) const
{
	return (this->gradeRequiredExec);
}

int Form::getGradeSign(void) const
{
	return (this->gradeRequiredSign);
}

void Form::setSigned(bool isSigned)
{
	this->isSigned = isSigned;
}
std::ostream &operator<<(std::ostream &o, const Form &f)
{
	const char *signedLabel = f.getIsSigned() ? "yes" : "no";

	o << "Form \"" << f.getName() << "\""
	  << " (signed: " << signedLabel
	  << ", sign: " << f.getGradeSign()
	  << ", exec: " << f.getGradeExec()
	  << ")";
	return (o);
}
