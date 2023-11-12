#ifndef MYREPLACE_HPP
#define MYREPLACE_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>

class MyReplace{
	private:
		std::string	  input;
	public:
		MyReplace(std::string input);
		void	Replacer( std::string s1, std::string s2);
		~MyReplace();

};

#endif
