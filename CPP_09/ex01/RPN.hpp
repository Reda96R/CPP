#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN{
	private:
		std::stack<int> rpnStack;
	public:
		RPN( void );
		RPN( const RPN& src );
		RPN& operator=( const RPN& rhs );
		~RPN( void );

		void	calculator( std::string input );
};

#endif
