#include "AForm.hpp"

AForm::AForm(): _name("default"), _sign_it(150), _execute_it(150)
{
	this->_signed = false;
}

AForm::AForm(const AForm& cpy): _name(cpy._name), _sign_it(cpy._sign_it), _execute_it(cpy._execute_it)
{
	this->_signed = cpy._signed;
}

AForm::AForm(const std::string _name, bool _signed, const int _sign_it, const int _execute_it):
	_name(_name), _sign_it(_sign_it), _execute_it(_execute_it)
{
	this->_signed = _signed;
}

AForm::~AForm()
{

}

AForm&	AForm::operator=(const AForm& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, AForm& src)
{
	if (src.signGrade() < 1 || src.exGrade() < 1)
	{
		throw AForm::GradeTooHighException();
		return os;
	}
	else if (src.signGrade() > 150 || src.exGrade() > 150)
	{
		throw AForm::GradeTooLowException();
		return os;
	}
	os << "Form " << src.getName() << ", sign grade " << src.signGrade()
		<< ", exec grade " << src.exGrade();
	return os;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high! (Aform)";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low! (Aform)";
}

const std::string	AForm::getName() const
{
	return this->_name;	
}

int	AForm::exGrade() const
{
	return this->_execute_it;
}

int	AForm::signGrade() const
{
	return this->_sign_it;
}


void	AForm::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > this->_sign_it)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

void	AForm::setSigned(bool signed_status)
{
	this->_signed = signed_status;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execute_it)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}
