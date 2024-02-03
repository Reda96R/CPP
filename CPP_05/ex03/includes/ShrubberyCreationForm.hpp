#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP 

#include <fstream>
# include "AForm.hpp"
# include <cstdlib>
# include <string>

class ShrubberyCreationForm : public AForm{
	private:
		const std::string	target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& src );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& rhs );
		~ShrubberyCreationForm( void );

		void	execute( const Bureaucrat& executor ) const;
};

#endif
