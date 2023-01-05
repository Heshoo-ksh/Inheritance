#include "DeliveredPizza.h"

DeliveredPizza::DeliveredPizza (std::string delivryAdress,std::string size,std::string type,std::vector <std::string> toppings):
	Pizza (size, type,toppings)
{
  	double price = getPrice();
  	
	this-> delivryAdress = delivryAdress;
	
	if(price > 20)
		this -> deliveryFee = 3.50;
	else if (price < 21)
		this-> deliveryFee = 5.00;
		
	this -> totalPrice =  price + deliveryFee;
}

DeliveredPizza ::~DeliveredPizza ()
{
}
