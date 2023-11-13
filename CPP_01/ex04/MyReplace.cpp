#include "MyReplace.hpp"
#include <string>

MyReplace::MyReplace(std::string input): input(input){
}

void	MyReplace::Replacer(std::string s1, std::string s2){
	std::ofstream	out;
	std::string		str;
	size_t			n;

	std::ifstream in(this->input.c_str());
	if (!in.is_open()){
		std::cerr << "\033[0;31mError opening the file\033[0m" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (std::getline(in, str, '\0')){
		out.open(((this->input + ".replace").c_str()));
		if (out.fail()){
			std::cerr << "\033[0;31mError creating the file\033[0m" << std::endl;
			in.close();
			std::exit(EXIT_FAILURE);
		}
		n = str.find(s1);
		while (n != std::string::npos){
			str.erase(n, s1.length());
			str.insert(n, s2);
			n = str.find(s1);
		}
		out << str;
		out.close();
	}
	else {
		std::cerr << "\033[0;31mError: Empty file\033[0m" << std::endl;
	}
	in.close();
}

MyReplace::~MyReplace(){
}
