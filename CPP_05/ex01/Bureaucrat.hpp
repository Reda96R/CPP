#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string& name, int grade );
		Bureaucrat( const Bureaucrat& src );
		Bureaucrat& operator=( const Bureaucrat& rhs );
		~Bureaucrat( void );

		std::string	  getName( void ) const;
		int			  getGrade( void ) const;
		void		  incrementGrade( void );
		void		  decrementGrade( void );
		void		  signForm( Form& form );
	//add be signed	
		class GradeTooLowException : public std::exception{
			public:
				virtual const char*	what() const throw(){
					return ("\033[0;31mGrade too low\033[0m");
				}
		};
		class GradeTooHighException : public std::exception{
			public:
				virtual const char*	what() const throw(){
					return ("\033[0;31mGrade too high\033[0m");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
