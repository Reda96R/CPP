#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form{
	private:
		const std::string	target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& src );
		RobotomyRequestForm& operator=( RobotomyRequestForm& rhs );
		~RobotomyRequestForm( void );

		void	execute( const Bureaucrat& executor ) const;
};

#endif
