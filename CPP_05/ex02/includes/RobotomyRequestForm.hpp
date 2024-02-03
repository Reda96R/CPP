#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm{
	private:
		const std::string	target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& src );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );
		~RobotomyRequestForm( void );

		void	execute( const Bureaucrat& executor ) const;
};

#endif
