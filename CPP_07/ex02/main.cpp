#include "Array.hpp"
#include <stdlib.h>

int	main( void ){

//=================================================
	std::cout << ":::Int:::" << std::endl;
	Array<int> test0(4);
	for (unsigned int i = 0; i < test0.size(); i++)
		test0[i] = i;
	for (unsigned int i = 0; i < test0.size(); i++)
		std::cout << test0[i] << std::endl;
	std::cout << std::endl;

	std::cout << ":::Char:::" << std::endl;
	Array<char> test1(4);
	test1[0] = 'a';
	test1[1] = 'b';
	test1[2] = 'c';
	test1[3] = 'd';
	for (unsigned int i = 0; i < test1.size(); i++)
		std::cout << test1[i] << std::endl;
	std::cout << std::endl;

	std::cout << ":::String:::" << std::endl;
	Array<std::string> test2(4);
	test2[0] = "a0";
	test2[1] = "b1";
	test2[2] = "c2";
	test2[3] = "d3";
	for (unsigned int i = 0; i < test2.size(); i++)
		std::cout << test2[i] << std::endl;
	std::cout << std::endl;

//=================================================
	try{
		std::cout << test0[4] << std::endl;
		std::cout << test0[-4] << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
