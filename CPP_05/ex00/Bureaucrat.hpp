#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		std::string	  getName();
		int			  getGrade();
		void		  incrementGrade();
		void		  decrementGrade();
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
