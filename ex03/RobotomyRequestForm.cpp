#include "RobotomyRequestForm.hpp"
#include <ostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45)
{
	this->_target = "default";
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", false, 72, 45)
{
	this->_target = target;
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy)
{
	this->_target = cpy._target;
	srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		this->setSigned(src.getSigned());
		this->_target = src._target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& src)
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
	os << "RobotomyRequestForm " << src.getName() << ", sign grade " << src.signGrade()
		<< ", exec grade " << src.exGrade() << ".";
	return os;
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "* drilling noises  *" << std::endl;
	if (rand() % 2)
	{
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	}
	else
	{
		std::cout << "The robotomy failed." << std::endl;
	}
}

std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}
