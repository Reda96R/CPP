#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		const std::string	  target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& src );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );
		~PresidentialPardonForm( void );
		
		void	execute( const Bureaucrat& executor ) const;
};

#endif
