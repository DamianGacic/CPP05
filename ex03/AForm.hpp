#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool	_signed;
		const int	_sign_it;
		const int	_execute_it;

	protected:
		void	setSigned(bool signed_status);
	
	public:
		AForm();
		AForm(const std::string _name, bool _signed, const int _sign_it, const int _execute_it);
		AForm(const AForm& cpy);
		AForm&	operator=(const AForm& src);
		virtual ~AForm();
		const std::string	getName() const;
		int	exGrade() const;
		int	signGrade() const;
 		void	beSigned(Bureaucrat const &src);
		void	execute(Bureaucrat const &executor) const;
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
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	protected:
		virtual void	executeAction() const = 0;
};

std::ostream&	operator<<(std::ostream& os, AForm& src);

#endif
