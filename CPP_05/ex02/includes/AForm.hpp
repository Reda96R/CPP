#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				_signed;
		
	public:
		AForm( void );
		AForm( const AForm& src );
		AForm& operator=( const AForm& rhs );
		AForm( const std::string& name, int gradeToSign, int gradeToExecute );
		virtual ~AForm( void );

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
		class FormNotSignedException : public std::exception{
			public:
				virtual const char*	what() const throw(){
					return ("\033[0;31mForm not signed\033[0m");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const AForm& rhs);

#endif
