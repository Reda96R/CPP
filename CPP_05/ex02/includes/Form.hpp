#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				_signed;
		
	public:
		Form( void );
		Form( const Form& src );
		Form& operator=( const Form& rhs );
		Form( const std::string& name, int gradeToSign, int gradeToExecute );
		~Form( void );

		std::string	  getName( void ) const;
		bool		  getSigned( void ) const;
		int			  getGradeToSign( void ) const;
		int			  getGradeToExecute( void ) const;
		void		  beSigned( const Bureaucrat& bureaucrat );
		virtual void  execute( const Bureaucrat& executor ) const = 0;
		

		class GradeTooHighException : public std::exception{
			public:
				virtual const char*	what() const throw(){
					return ("\033[0;31mGrade too high\033[0m");
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char*	what() const throw(){
					return ("\033[0;31mGrade too low\033[0m");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const Form& rhs);

#endif
