#include "phonebook.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>
#include <limits>

void  phonebook::intro(void){
	system("clear");
	this->nb = 0;
	std::cout << "\e[92;5;118m::::::📖 Welcome to Lcarnet 📖::::::\033[0m\n";
	std::cout << std::endl;
	std::cout<<"\033[2;37m................Usage...............\033[0m\n";
	std::cout<<"\033[0;33mADD\033[0m\t: Save a new contact\n";
	std::cout<<"\033[0;33mSEARCH\033[0m\t: Display a specific contact\n";
	std::cout<<"\033[0;33mEXIT\033[0m\t: Quite lcarnet\n";
	std::cout<<"\033[2;37m....................................\033[0m\n";
	std::cout << std::endl;
}

void  phonebook::add(void){
	static int i = 0;
	system("clear");
	this->contacts[i % 8].fill(i % 8);
	this->nb = 1;
	i++;
}

int  phonebook::display(void){
	if (!this->nb){
		std::cout << "\033[0;31m No contact saved, try adding contacts\033[0m\n";
		return (0);
	}
	system("clear");
	std::cout << "\033[0;33m-------------------Contacts------------------\033[0m" << std::endl;
	std::cout << "|\033[2;37m  Index  \033[0m ";
	std::cout << "|\033[2;37mFirst name\033[0m";
	std::cout << "|\033[2;37m Last name\033[0m";
	std::cout << "|\033[2;37m Nickname \033[0m|";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++){
		this->contacts[i].print(i);
	}
	return (1);
}

int	contact::id_check(int id)
{
	id -= 1;
	if (this->firstname.empty())
		return (0);
	return (1);
}

int phonebook::select(void) {
	int id;
    while (1) {
		std::cout << "\n\033[0;33mEnter the contact's index: \033[0m" << std::endl;
		std::cin >> id;
		if (std::cin.eof()){
			std::cout << "\n\n\033[0;33m:::::: GOODBYE ::::::\n";
			exit (1);
		}
		if (this->contacts[id - 1].id_check(id - 1) && id >= 1 && id <= 8)
			break ; //valid input
		else {
			if (id <= 0 || id >= 9)
				std::cout << "\033[0;31mInvalide index, Please enter a valid index\033[0m" << std::endl;
			else
				std::cout << "\033[0;31mContact does not exist, Please enter a valid index\033[0m" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return id;
}

void  phonebook::search(void){
	int	i;

	if (!phonebook::display())
		return ;
	i = phonebook::select();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->contacts[i - 1].viewinfos();
}
