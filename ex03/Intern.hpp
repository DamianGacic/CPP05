#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <ostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& cpy);
		Intern&	operator=(const Intern& src);
		~Intern();
		static AForm	*makePresident(std::string target);
		static AForm	*makeRobot(std::string target);
		static AForm	*makeShrubbery(std::string target);
		static AForm	*makeForm(std::string form_name, std::string target);
};

std::ostream&	operator<<(std::ostream& os, Intern& src);

#endif
