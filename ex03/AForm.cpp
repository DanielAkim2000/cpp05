#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

AForm::AForm() : name("unamed"), isSigned(false), gradeRequiredSign(5), gradeRequiredExec(10)
{
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec)
	: name(name), isSigned(false), gradeRequiredSign(gradeSign), gradeRequiredExec(gradeExec)
{
	if (gradeRequiredSign > 150 || gradeRequiredExec > 150)
		throw AForm::GradeTooLowException();
	if (gradeRequiredSign < 1 || gradeRequiredExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), gradeRequiredSign(other.gradeRequiredSign), gradeRequiredExec(other.gradeRequiredExec)
{
	if (gradeRequiredSign > 150 || gradeRequiredExec > 150)
		throw AForm::GradeTooLowException();
	if (gradeRequiredSign < 1 || gradeRequiredExec < 1)
		throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat &burr)
{
	if (burr.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	else
		setSigned(true);
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	this->executeAction();
}

const std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int AForm::getGradeExec(void) const
{
	return (this->gradeRequiredExec);
}

int AForm::getGradeSign(void) const
{
	return (this->gradeRequiredSign);
}

void AForm::setSigned(bool isSigned)
{
	this->isSigned = isSigned;
}
std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	const char *signedLabel = f.getIsSigned() ? "yes" : "no";

	o << "Form \"" << f.getName() << "\""
	  << " (signed: " << signedLabel
	  << ", sign: " << f.getGradeSign()
	  << ", exec: " << f.getGradeExec()
	  << ")";
	return (o);
}
