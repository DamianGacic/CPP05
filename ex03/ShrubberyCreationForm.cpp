#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137)
{
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", false, 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy)
{
	this->_target = cpy._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		this->setSigned(src.getSigned());
		this->_target = src.getTarget();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& src)
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
	os << "ShrubberyCreationForm " << src.getName() << ", sign grade "
		<< src.signGrade() << ", execute grade " << src.exGrade() << ".";
	return os;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	outFile;
	int		treeCount;
	
	outFile.open((this->_target + "_shrubbery").c_str());
	treeCount = 0;
	while (treeCount < 3)
	{	
		outFile <<	"           \\/ |    |/ "<< std::endl;
		outFile <<	 "       \\/ / \\||/  /_/___/_ "<< std::endl;
		outFile <<	 "        \\/   |/ \\/ "<< std::endl;
		outFile <<	 "   _\\__\\_\\   |  /_____/_ "<< std::endl;
		outFile <<	 "          \\  | /          / "<< std::endl;
		outFile <<	 " __ _-----`  |{,-----------~ "<< std::endl;
		outFile <<	 "           \\ }{ "<< std::endl;
		outFile <<	 "            }{{ "<< std::endl;
		outFile <<	 "            }}{ "<< std::endl;
		outFile <<	 "            {{} "<< std::endl;
		outFile <<	 "      , -=-~{ .-^- "<< std::endl;
		outFile <<		"        `} "<< std::endl;
		outFile <<	 "             {	"<< std::endl;
		outFile << std::endl;
		treeCount++;
	}
	outFile.close();
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}
