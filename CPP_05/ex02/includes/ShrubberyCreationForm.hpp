#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP 

# include "Form.hpp"

class ShrubberyCreationForm : public Form{
	private:
		const std::string	target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& src );
		ShrubberyCreationForm& operator=( ShrubberyCreationForm& rhs );
		~ShrubberyCreationForm( void );

		void	execute( const Bureaucrat& executor ) const;
};

#endif
