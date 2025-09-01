#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "   -Testing Form Creation-   " << std::endl;
	
	try
	{
		Form validForm("Tax Form", 50, 25);
		std::cout << validForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form invalidForm("Invalid Form", 0, 25);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception creating invalid form: " << e.what() << std::endl;
	}

	std::cout << "\n   -Testing Form Signing-   " << std::endl;
	
	try
	{
		Bureaucrat highLevel("Boss", 1);
		Bureaucrat lowLevel("Intern", 100);
		Form importantForm("Important Document", 50, 25);
		
		std::cout << highLevel << std::endl;
		std::cout << lowLevel << std::endl;
		std::cout << importantForm << std::endl;
		
		highLevel.signForm(importantForm);
		std::cout << "After signing: " << importantForm << std::endl;
		
		lowLevel.signForm(importantForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n   -Testing Grade Too Low-   " << std::endl;
	
	try
	{
		Bureaucrat weakBureaucrat("Weak", 150);
		Form restrictedForm("Top Secret", 1, 1);
		
		std::cout << weakBureaucrat << std::endl;
		std::cout << restrictedForm << std::endl;
		
		weakBureaucrat.signForm(restrictedForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}