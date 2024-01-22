#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
# include <iostream>

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

		std::string	  getName() const;
		int			  getGrade() const;
		void		  incrementGrade();
		void		  decrementGrade();
		
		class GradeTooLowException : public std::exception{
			public:
				virtual const char*	what() const throw(){
					return ("Grade too low");
				}
		};
		class GradeTooHighException : public std::exception{
			public:
				virtual const char*	what() const throw(){
					return ("Grade too high");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
