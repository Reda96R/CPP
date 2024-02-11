#include "Serializer.hpp"

int	main( void ){
	Data		*data;
	Data		*ptr;

	data = new Data;
	data->name = "Reda";
	data->id = 1;

	//:::::::::::::::::::::::::::::::::::::::::::::::::::
	std::cout << "\033[0;32m:::Data:::\033[0m" << std::endl; 
	std::cout << "==> Address : " << data << std::endl;
	std::cout << "==> Name    : " << data->name << std::endl;
	std::cout << "==> Id      : " << data->id << std::endl;

	//:::::::::::::::::::::::::::::::::::::::::::::::::::
	ptr = Serializer::deserialize(Serializer::serialize(data));
	std::cout << std::endl;
	
	//:::::::::::::::::::::::::::::::::::::::::::::::::::
	std::cout << "\033[0;31m:::Ptr:::\033[0m" << std::endl; 
	std::cout << "--> Address : " << ptr << std::endl;
	std::cout << "--> Name    : " << ptr->name << std::endl;
	std::cout << "--> Id      : " << ptr->id << std::endl;

	delete (data);
}
