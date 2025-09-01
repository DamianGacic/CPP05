#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <ostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& cpy);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
		std::string	getTarget() const;

	protected:
		void	executeAction() const;
};

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& src);


#endif
