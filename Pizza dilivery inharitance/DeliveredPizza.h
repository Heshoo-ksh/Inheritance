#ifndef DELIVEREDPIZZA_H
#define DELIVEREDPIZZA_H

#include "Pizza.h"

class DeliveredPizza  : public Pizza
{
	friend std::ostream& operator<<(std::ostream& o, DeliveredPizza& aDeliveredPizza);

	private:
		double deliveryFee;
		double totalPrice;
		std::string delivryAdress;
		
	public:
		DeliveredPizza (std::string delivryAdress,std::string size,std::string type,std::vector <std::string> toppings);
		~DeliveredPizza ();
	
};

#endif
