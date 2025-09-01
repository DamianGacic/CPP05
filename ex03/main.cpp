#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "   -Testing Intern Class-   " << std::endl;
	
	// Test subject example exactly as specified
	std::cout << "\n   -Subject Example Test-   " << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		if (rrf)
		{
			std::cout << "Successfully created: " << rrf->getName() << " targeted at Bender" << std::endl;
			
			// Test that the form actually works
			try
			{
				Bureaucrat boss("Boss", 1);
				boss.signForm(*rrf);
				boss.executeForm(*rrf);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Exception: " << e.what() << std::endl;
			}
			
			delete rrf;
		}
		else
		{
			std::cout << "ERROR: Failed to create robotomy request form" << std::endl;
		}
	}
	
	std::cout << "\n   -Testing All Form Types-   " << std::endl;
	
	Intern intern;
	AForm* forms[3];
	std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	std::string targets[3] = {"Arthur Dent", "Marvin", "Home"};
	
	// Create all three types of forms
	for (int formIndex = 0; formIndex < 3; formIndex++)
	{
		std::cout << "\nCreating " << formNames[formIndex] << " form:" << std::endl;
		forms[formIndex] = intern.makeForm(formNames[formIndex], targets[formIndex]);
		
		if (forms[formIndex])
		{
			std::cout << "Form details: " << forms[formIndex]->getName() 
					  << ", sign grade: " << forms[formIndex]->signGrade()
					  << ", exec grade: " << forms[formIndex]->exGrade() << std::endl;
		}
	}
	
	std::cout << "\n   -Testing Form Functionality-   " << std::endl;
	
	try
	{
		Bureaucrat president("President", 1);
		Bureaucrat manager("Manager", 50);
		
		// Test presidential pardon form
		if (forms[0])
		{
			std::cout << "\nTesting Presidential Pardon Form:" << std::endl;
			president.signForm(*forms[0]);
			president.executeForm(*forms[0]);
		}
		
		// Test robotomy request form  
		if (forms[1])
		{
			std::cout << "\nTesting Robotomy Request Form:" << std::endl;
			manager.signForm(*forms[1]);
			president.executeForm(*forms[1]);
		}
		
		// Test shrubbery creation form
		if (forms[2])
		{
			std::cout << "\nTesting Shrubbery Creation Form:" << std::endl;
			manager.signForm(*forms[2]);
			manager.executeForm(*forms[2]);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception during form testing: " << e.what() << std::endl;
	}
	
	// Clean up memory
	for (int formIndex = 0; formIndex < 3; formIndex++)
	{
		delete forms[formIndex];
	}
	
	std::cout << "\n   -Testing Error Cases-   " << std::endl;
	
	// Test invalid form names
	AForm* invalidForm1 = intern.makeForm("invalid form", "target");
	if (invalidForm1)
	{
		std::cout << "ERROR: Shouldn't have created invalid form" << std::endl;
		delete invalidForm1;
	}
	
	AForm* invalidForm2 = intern.makeForm("", "target");
	if (invalidForm2)
	{
		std::cout << "ERROR: Shouldn't have created form with empty name" << std::endl;
		delete invalidForm2;
	}
	
	AForm* invalidForm3 = intern.makeForm("ROBOTOMY REQUEST", "target"); // Test case sensitivity
	if (invalidForm3)
	{
		std::cout << "ERROR: Shouldn't have created form with wrong case" << std::endl;
		delete invalidForm3;
	}
	
	std::cout << "\n--- Testing Multiple Interns ---" << std::endl;
	
	// Test that multiple interns work independently
	Intern intern1, intern2, intern3;
	AForm* form1 = intern1.makeForm("robotomy request", "Robot1");
	AForm* form2 = intern2.makeForm("shrubbery creation", "Garden");
	AForm* form3 = intern3.makeForm("presidential pardon", "Prisoner");
	
	if (form1 && form2 && form3)
	{
		std::cout << "Successfully created forms with multiple interns" << std::endl;
		std::cout << "Form1: " << form1->getName() << std::endl;
		std::cout << "Form2: " << form2->getName() << std::endl;
		std::cout << "Form3: " << form3->getName() << std::endl;
		
		delete form1;
		delete form2;
		delete form3;
	}
	
	std::cout << "\n--- Testing Edge Cases ---" << std::endl;
	
	// Test with unusual but valid targets
	AForm* weirdTarget = intern.makeForm("robotomy request", "");
	if (weirdTarget)
	{
		std::cout << "Created form with empty target" << std::endl;
		delete weirdTarget;
	}
	
	AForm* longTarget = intern.makeForm("shrubbery creation", "VeryLongTargetNameWithSpecialCharacters!@#$%^&*()");
	if (longTarget)
	{
		std::cout << "Created form with complex target name" << std::endl;
		delete longTarget;
	}
	
	std::cout << "\n=== All Tests Completed ===" << std::endl;
	
	return 0;
}