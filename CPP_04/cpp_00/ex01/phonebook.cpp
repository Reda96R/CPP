#include "phonebook.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>

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

// int  phonebook::select(void){
// 	int	id;
// 	int	n = 0;
//
// 	do{
// 		std::cout << "\n\033[0;33mEnter the contact's index: \033[0m" << std::endl;
// 		std::cin >> id;
// 		if (std::cin.fail()){
// 			std::cout << "here\n";
// 			std::cin.clear();
// 			std::cin.ignore();
// 		}
// 		if (id >= 1 && id <= 8)
// 			n = 1;
// 		else{
// 			std::cin.clear();
// 			std::cin.ignore();
// 			std::cout << "\033[0;31mIndex out of range, please enter a valid one\033[0m" << std::endl;
// 		}
// 	}
// 	while (!n);
// 	return (id);
//
// }

// int phonebook::select(void) {
//     int id;
//     int n = 0;
//     bool errorDisplayed = false; // Flag to track if the error message has been displayed
//
//     do {
//         if (!errorDisplayed)
//             std::cout << "\n\033[0;33mEnter the contact's index: \033[0m" << std::endl;
// 		std::cin >> id;
// 		if (std::cin.fail() || id <= 0 || id > 9) {
// 			if (!errorDisplayed){
// 				std::cout << "\033[0;31mInvalid input, Please enter a valid input\033[0m" << std::endl;
// 				errorDisplayed = true;
// 			}
// 			std::cin.clear();
// 			std::cin.ignore(); // Clear the input buffer
//         } else if (id >= 1 && id <= 8)
//             n = 1; // Valid input
//     }
// 	while (!n);
//     return id;
// }

int phonebook::select(void) {
    int id;
    int n = 0;
	std::string input;
    // bool errorDisplayed = false; // Flag to track if the error message has been displayed

    do {
		std::cout << "\n\033[0;33mEnter the contact's index: \033[0m" << std::endl;
		std::getline(std::cin, input);
		std::istringstream iss (input);
		if (iss >> id){
			if (id >= 1 && id <= 8)
				n = 1; // Valid input
		}
		else {
				std::cout << "\033[0;31mInvalid input, Please enter a valid input\033[0m" << std::endl;
			std::cin.clear();
			std::cin.ignore(); // Clear the input buffer 
		}
			iss.clear();
    }
	while (!n);
    return id;
}

void  phonebook::search(void){
	int	i;

	if (!phonebook::display())
		return ;
	i = phonebook::select();
	std::cin.ignore();
	this->contacts[i - 1].viewinfos(i - 1);
}
