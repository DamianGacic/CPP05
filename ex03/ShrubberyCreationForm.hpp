#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		std::string	getTarget() const;

	protected:
		void	executeAction() const;
};

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& src);

#endif
