#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string name;
		bool			  _signed;
		const int		  gradeToSign;
		const int		  gradeToExecute;

	public:
		Form( void );
		Form( const std::string& name, int gradeToSign );
		Form( const std::string& name, int gradeToSign , int grdaeToExecute );
		Form( const Form& src );
		Form& operator=( const Form& rhs );
		~Form( void );
		
		
		std::string	  getName( void ) const;
		bool		  getSigned( void ) const;
		int			  getGradeToSign( void ) const;
		int			  getGradeToExecute( void ) const;
		void		  beSigned( const Bureaucrat& bureaucrat );

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

std::ostream&	operator<<(std::ostream& o, const Form& rhs);

#endif
