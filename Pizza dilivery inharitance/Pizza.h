#ifndef PIZZA_H
#define PIZZA_H
#include <vector>
#include<iostream>
class Pizza
{
	friend std::ostream& operator<<(std::ostream& o,const Pizza& aPizza);

	private:
		std::string size;
		std::string type;
		std::vector <std::string> toppings;		
		double calcPrice();
		double price = calcPrice();

	public:
		Pizza(std::string size,std::string type,std::vector <std::string> toppings );
		~Pizza();
		
		double getPrice()	{return price;}
		std::string getSize(){ return size;}
		std::string getType(){ return type;}
		std::vector<std::string> getToppings(){ return toppings;}
		
};

#endif
