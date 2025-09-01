#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name(cpy._name)
{
	this->_grade = cpy._grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src)
{
	if (src.getGrade() > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return os;
	}
	else if (src.getGrade() < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return os;
	}
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

int	Bureaucrat::signForm(AForm &src)
{
	try
	{
		src.beSigned(*this);
		std::cout << this->getName() << " signed " << src.getName() << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << src.getName()
			<< " because " << e.what() << std::endl;
		return 0;
	}
}

int	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn't exec " << form.getName()
			<< " because " << e.what() << std::endl;
		return 0;
	}
}

const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

