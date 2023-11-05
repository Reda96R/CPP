#include "contact.hpp"
#include "phonebook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

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
			if (!(std::cin.eof()) && i)
				break ;
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
	if (str.length() > 9)
		return (str.substr(0, 8) + ".");
	return (str);
}

void  contact::print(int i){
	std::string str;
	std::cout << "|" << std::setw(5) << i + 1 << std::setw(6);
	std::cout << "|" << (str = contact::preprinter(this->firstname)) << std::setw(11 - str.length());
	std::cout << "|" << (str = contact::preprinter(this->lastname)) << std::setw(11 - str.length());
	std::cout << "|" << (str = contact::preprinter(this->nickname)) << std::setw(11 - str.length());
	std::cout << "|" << std::endl;
}

void  contact::viewinfos(int i){
	(void)i;
	if (this->firstname.empty()){
		std::cout << "\033[0;31mContact does not exist, try again and enter a valid index\033[0m" << std::endl;
		return ;
	}
	else{
		system("clear");
		std::cout << "\033[2;37m:::"<< this->firstname << "'s informations:::\n\n\033[0m";
		std::cout << "\033[0;33mFirst name\t:\033[0m " << this->firstname << std::endl;
		std::cout << "\033[0;33mLast name\t:\033[0m " << this->lastname << std::endl;
		std::cout << "\033[0;33mNickname\t:\033[0m " << this->nickname << std::endl;
		std::cout << "\033[0;33mPhone number\t:\033[0m " << this->number << std::endl;
		std::cout << "\033[0;33mDarkest secret\t:\033[0m " << this->secret << std::endl;
		std::cout << std::endl;
	}
}
