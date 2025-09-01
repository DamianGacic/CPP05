#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool	_signed;
		const int	_sign_it;
		const int	_execute_it;
	
	public:
		Form();
		Form(const std::string& name, int signGrade, int exGrade);
		Form(const Form& cpy);
		Form&	operator=(const Form& src);
		~Form();
		const std::string	getName() const;
		int	exGrade() const;
		int	signGrade() const;
 		void	beSigned(Bureaucrat const &src);
		bool	getSigned() const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& src);

#endif
