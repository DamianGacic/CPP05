#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "   -Form creation with targets-   " << std::endl;
	
	try
	{
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Siren");  
		PresidentialPardonForm pardon("Midas");
		
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n   -Form Execution-   " << std::endl;
	
	try
	{
		Bureaucrat president("President", 1);
		Bureaucrat manager("Manager", 50);
		Bureaucrat intern("Intern", 150);
		
		ShrubberyCreationForm shrub("wood");
		RobotomyRequestForm robot("Bender");  
		PresidentialPardonForm pardon("fish");
		
		std::cout << "\n   -Testing ShrubberyCreationForm (grades 145/137)-   " << std::endl;
		std::cout << "Form: " << shrub << std::endl;
		manager.signForm(shrub);
		manager.executeForm(shrub);
		
		std::cout << "\n   -Testing RobotomyRequestForm (grades 72/45)-   " << std::endl;
		std::cout << "Form: " << robot << std::endl;
		manager.signForm(robot);
		president.executeForm(robot);
		
		std::cout << "\n    -Testing PresidentialPardonForm (grades 25/5)-   " << std::endl;
		std::cout << "Form: " << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n - Execution error testing-   " << std::endl;
	
	std::cout << "\n   -Test 1: Unsigned form-   " << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm unsignedForm("Criminal");
		
		std::cout << "Trying executing unsigned form:" << std::endl;
		president.executeForm(unsignedForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n   -Test 2: Grade too low-   " << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm restrictedForm("VIP");
		
		std::cout << "President signing the form first:" << std::endl;
		Bureaucrat president("President", 1);
		president.signForm(restrictedForm);
		
		std::cout << "Now intern trying to execute:" << std::endl;
		intern.executeForm(restrictedForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n   -Test 3: Grade too low for signing-   " << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm restrictedForm("TopSecret");
		
		std::cout << "Intern trying to sign Presidential form:" << std::endl;
		intern.signForm(restrictedForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n   -Testing Multiple Robotomy Attempts (50% success)-   " << std::endl;
	
	try
	{
		Bureaucrat boss("Boss", 1);
		
		for (int testNum = 1; testNum <= 4; testNum++)
		{
			std::cout << "\n   -Robotomy test- " << testNum << " ---" << std::endl;
			RobotomyRequestForm robot("Target" + std::string(1, '0' + testNum));
			boss.signForm(robot);
			boss.executeForm(robot);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n   -Testing Direct execute() calls-   " << std::endl;
	
	try
	{
		Bureaucrat president("DirectExecPresident", 1);
		ShrubberyCreationForm directShrub("direct");
		
		std::cout << "Testing direct execute() call without signing:" << std::endl;
		directShrub.execute(president);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Direct execute exception: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat president("DirectExecPresident", 1);
		Bureaucrat lowLevel("LowLevel", 149);
		ShrubberyCreationForm directShrub("direct2");
		
		std::cout << "Signing form, then trying executing with low grade:" << std::endl;
		president.signForm(directShrub);
		directShrub.execute(lowLevel);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Direct execute exception: " << e.what() << std::endl;
	}

	return 0;
}