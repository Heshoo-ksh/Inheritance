#include "DeliveredPizza.h"
#include <iomanip>
#include <limits>

std::ostream& operator<<(std::ostream& o,const Pizza& aPizza)
{
  o<<"\nYou ordered a "<<aPizza.size<<" "<<aPizza.type<<" with ";
  for (std::string oneTopping : aPizza.toppings)
  	o<<oneTopping<<" ";
  std::cout << std::setprecision(2) << std::fixed;
  o<<"\nPizza Price:$\t"<<aPizza.price<<std::endl;

  return o;
}

std::ostream& operator<<(std::ostream& o, DeliveredPizza& aDeliveredPizza)
{
	double price = aDeliveredPizza.getPrice();
	std::string size = aDeliveredPizza.getSize();
	std::string type = aDeliveredPizza.getType();
	o<<"\nYou ordered a "<<size<<" "<<type<<" with ";
	for (std::string oneTopping : aDeliveredPizza.getToppings())
		o<<oneTopping<<" ";
	std::cout << std::setprecision(2) << std::fixed;
	o<<"\nPizza Price:$\t"<<price<<std::endl;
	o<<"Delivery Fee:\t$"<<aDeliveredPizza.deliveryFee<<std::endl;
	o<<"Total Price:\t$"<<aDeliveredPizza.totalPrice<<std::endl;
	o<<	"\nDelivered to:\t"<<aDeliveredPizza.delivryAdress;

  return o;
}

void orderPizza(std::string &size, std::string &type, std::string const toppings[6],  std::vector <std::string> &orderedToppings);
void validateNumaricData(int &choice, int min, int max);

int main()
{
	int choice;
	std::string size,type,address;
	std::string toppings[] = {"Pepperoni", "Mushrooms", "Onions", "Green Pepper", "Tomatoes", "Jalapenos"};
  	std::vector <std::string> orderedToppings;

	orderPizza(size,type,toppings,orderedToppings);

  	Pizza aPizza(size,type,orderedToppings);

	
	std::cout<<"\nWould you like 1 - pick up or 2 - delivery?\t";
	std::cin>>choice;
	validateNumaricData(choice,1,2);
	
	if (choice == 1	)
		std::cout<<aPizza;
	else 
	{
		std::cin.ignore();
		std::cout<<"\nPlease enter your address:"<<std::endl<<"\t\t";
		getline(std::cin ,address);
		DeliveredPizza aDeliveredPizza(address,size,type,orderedToppings);
		
		std::cout<<aDeliveredPizza;
	}
		
}

void orderPizza(std::string &size, std::string &type, std::string const toppings[6], std::vector <std::string> &orderedToppings)
{
  int choice;
	std::cout<<"What size pizza would you like to order?\n\t1 - Small\n\t2 - Medium\n\t3 - Large\n\t----> ";
	std::cin>>choice;
	validateNumaricData(choice,1,3);

  if (choice == 1)
  {
    size = "Small";
  }
  else if (choice == 2)
  {
    size = "Medium";
  }
  else if (choice == 3)
  {
    size = "Large";
  }
  
	std::cout<<"What type of crust would you like to order?\n\t1 - Classic\n\t2 - Deep Dish\n\t3 - Thin Crust\n\t---->";
	std::cin>>choice;
	validateNumaricData(choice,1,3);

  if (choice == 1)
  {
    type = "Classic";
  }
  else if (choice == 2)
  {
    type = "Deep Dish";
  }
  else if (choice == 3)
  {
    type = "Thin Crust";
  }
  
  while (choice != 0)
  {
    std::cout<<"Choose from the following toppings or 0 to quit\n\t";
	std::cout<<"1: Pepperoni\n\t2: Mushrooms\n\t3: Onions\n\t4: Green Pepper\n\t5: Tomatoes\n\t6: Jalapenos\n\t	---->";
	std::cin>>choice;
	validateNumaricData(choice,0,7);

    if (choice != 0)
      orderedToppings.push_back(toppings[choice-1]);
    }
}
void validateNumaricData(int &choice, int min, int max)
{
	while(std::cin.fail()){
		
			std::cout<<"\nERROR:\tInvalid input Due to the wrong Data type, try again \nChoice:\t";
	  		std::cin.clear();
	   		std::cin.ignore( std::numeric_limits<std::streamsize>::max(),'\n'); 
	   		std::cin>>choice;
	}
	while ( choice > max || choice < min)
	{
		std::cout<<"\nERROR:\tOption selected is not valid, try again.\nChoice:\t";
		std::cin>>choice;
		validateNumaricData( choice,  min,  max);
	}
}

