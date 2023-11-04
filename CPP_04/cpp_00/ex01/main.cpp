#include "phonebook.hpp"

int	main(){
	phonebook book;
	std::string	input;
	book.intro();
	while (1){
		std::cout << "🖊️> " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else if (input == "EXIT")
			break ;
		else
		 std::cout <<"\033[0;31mERROR: command not valid\033[0m\n\033[32mvalid commands:\033[0m ADD, SEARCH, EXIT\n";
	}
	std::cout << "\n\033[0;33m:::::: GOODBYE ::::::\n";
	return (0);
}
