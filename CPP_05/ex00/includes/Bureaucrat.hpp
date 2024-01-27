#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
