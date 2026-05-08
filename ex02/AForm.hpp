#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeRequiredSign;
	const int gradeRequiredExec;

protected:
	virtual void executeAction() const = 0;

public:
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	AForm();
	AForm(const std::string name, int gradeSign, int gradeExec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	void setSigned(bool isSigned);
	const std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;
	void beSigned(const Bureaucrat &burr);
	void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif
