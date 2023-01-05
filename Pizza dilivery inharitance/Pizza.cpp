#include "Pizza.h"

Pizza::Pizza(std::string size,std::string type,	std::vector <std::string> toppings )
{
	
	this-> toppings = toppings;
  	this-> size = size;
	this-> price = calcPrice();
	this-> type = type;
}

Pizza::~Pizza(){}

double Pizza::calcPrice()
{
	double pizzaPrice = toppings.size() * 2;
	if (size == "Small")
	{
		pizzaPrice +=   10;
	}
	else if (size == "Medium")
	{
		pizzaPrice +=  14;
	}
	else if (size == "Large")
	{
		pizzaPrice +=  17;
	}
	return pizzaPrice;
}

