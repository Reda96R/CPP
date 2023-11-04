#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

class phonebook{
	private:
		contact contacts[8];
		int		nb;
	public:
		void  intro(void);
		void  add(void);
		void  display(void);
		void  search(void);
		int  select(void);
		
};

#endif
