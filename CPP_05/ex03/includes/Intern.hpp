#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern{
	public:
		Intern( void );
		Intern( const Intern& src );
		Intern& operator=( const Intern& rhs );
		~Intern( void );

		AForm* makeForm( std::string name, std::string target );
};

#endif
