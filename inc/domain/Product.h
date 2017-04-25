#ifndef INC_DOMAIN_PRODUCT_H_
#define INC_DOMAIN_PRODUCT_H_

#include <string>

namespace domain {

class Product
{
public:
	//ctor
	Product():
		ProductName(),
		ProductNumber(),
		UnitPrice()
	{};
	//dtor
	virtual ~Product(){};

	std::string ProductName;			// Artikelpositionen
	std::string ProductNumber;			// Artikelnummern
	std::string UnitPrice;				// Einzelpreis
};

}

#endif /* INC_DOMAIN_PRODUCT_H_ */
