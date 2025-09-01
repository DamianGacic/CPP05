#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5)
{
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", false, 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm(cpy)
{
	this->_target = cpy._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		this->setSigned(src.getSigned());
		this->_target = src._target;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm& src)
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
	os << "PresidentialPardonForm sign grade " << src.signGrade() << ", exec grade " << src.exGrade() << ".";
	return os;
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}
