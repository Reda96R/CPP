#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include <stdint.h> // uintptr_t for c++98
# include "Data.hpp"

class Serializer {
	private:
		Serializer( void );

	public:
		Serializer( const Serializer& src );
		Serializer& operator=( const Serializer& rhs );

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

		~Serializer( void );
};

#endif
