#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeRequiredSign;
	const int gradeRequiredExec;

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
	Form();
	Form(const std::string name, int gradeSign, int gradeExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	void setSigned(bool isSigned);
	const std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;
	void beSigned(const Bureaucrat &burr);
};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif
