#include "contact.hpp"
#include "phonebook.hpp"

int	contact::check(std::string str){
	for (size_t s = 0; s < str.length(); s++){
		if (!std::isdigit(str[s]))
			return (0);
	}
	return (1);
}

std::string contact::readinput(std::string msg, int n){
	std::string	input;
	int			i = 1;
	while (1){
		std::cout << msg << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty()){
			if (n)
				i = contact::check(input);
			if (i)
				break ;
		}
		else {
			std::cout << "\n\n\033[0;33m:::::: GOODBYE ::::::\n";
			exit (1);
		}
		std::cout << "\033[0;31mInvalide, please try again\033[0m\n"; 
	}
	return (input);
}

void  contact::fill(int i){
	this->firstname = this->readinput("\033[0;33mFirst name\t:\033[0m ", 0);
	this->lastname = this->readinput("\033[0;33mLast name\t:\033[0m ", 0);
	this->nickname = this->readinput("\033[0;33mNickname\t:\033[0m ", 0);
	this->number = this->readinput("\033[0;33mPhone number\t:\033[0m ", 1);
	this->secret = this->readinput("\033[0;33mDarkest secret\t:\033[0m ", 0);
	this->id = i;
	std::cout << "\033[32m:::Contact created successfully:::\n\033[0m"; 
}

std::string	contact::preprinter(std::string str){
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void  contact::print(int i){
	std::string str;
	std::cout << "|" << std::setw(10) << i + 1 ;
	str = contact::preprinter(this->firstname);
	std::cout << "|" << std::setw(10) << str;
	str = contact::preprinter(this->lastname);
	std::cout << "|" << std::setw(10) << str;
	str = contact::preprinter(this->nickname);
	std::cout << "|" << std::setw(10) << str;
	std::cout << "|" << std::endl;
}

void  contact::viewinfos(void){
	system("clear");
	std::cout << "\033[2;37m:::"<< this->firstname << "'s informations:::\n\n\033[0m";
	std::cout << "\033[0;33mFirst name\t:\033[0m " << this->firstname << std::endl;
	std::cout << "\033[0;33mLast name\t:\033[0m " << this->lastname << std::endl;
	std::cout << "\033[0;33mNickname\t:\033[0m " << this->nickname << std::endl;
	std::cout << "\033[0;33mPhone number\t:\033[0m " << this->number << std::endl;
	std::cout << "\033[0;33mDarkest secret\t:\033[0m " << this->secret << std::endl;
	std::cout << std::endl;
}
