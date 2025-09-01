#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& cpy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm & src);
		~RobotomyRequestForm();
		std::string getTarget() const;

	protected:
		void	executeAction() const;
};

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& src);

#endif
