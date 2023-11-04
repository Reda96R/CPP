#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class contact{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string secret;
		std::string number;
		int			id;

		std::string preprinter(std::string);
	public:
		std::string readinput(std::string, int n);
		void  fill(int i);
		void  print(int i);
		int	  check(std::string);
		void  viewinfos(int i);
};

#endif
