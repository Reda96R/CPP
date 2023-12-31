#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	private:
		std::string	  name;
		unsigned int  hitPoints;
		unsigned int  energyPoints;
		unsigned int  attackDamage;

		
	public:
		ClapTrap();
		ClapTrap (const ClapTrap &f);
		ClapTrap& operator=(const ClapTrap& f);
		ClapTrap ( std::string name);
		~ClapTrap ();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	beRepaired(unsigned int	amount);

};

#endif
