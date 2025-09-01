#include "Form.hpp"

Form::Form(): _name("Default"), _sign_it(150), _execute_it(150)
{
	this->_signed = false;
}

Form::Form(const std::string& name, int signGrade, int exGrade): _name(name), _sign_it(signGrade), _execute_it(exGrade)
{
	if (signGrade < 1 || exGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || exGrade > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(const Form& cpy): _name(cpy._name), _sign_it(cpy._sign_it), _execute_it(cpy._execute_it)
{
	this->_signed = cpy._signed;
}

Form::~Form()
{

}

Form&	Form::operator=(const Form& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Form& src)
{
	if (src.signGrade() < 1 || src.exGrade() < 1)
	{
		throw Form::GradeTooHighException();
		return os;
	}
	else if (src.signGrade() > 150 || src.exGrade() > 150)
	{
		throw Form::GradeTooLowException();
		return os;
	}
	os << "Form " << src.getName() << ", signed: " << (src.getSigned() ? "yes" : "no")
		<< ", sign grade required: " << src.signGrade() << ", exec grade required: " << src.exGrade();
	return os;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high! (form)";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low! (form)";
}

const std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

void	Form::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > this->_sign_it)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

int	Form::exGrade() const
{
	return this->_execute_it;
}

int	Form::signGrade() const
{
	return this->_sign_it;
}

