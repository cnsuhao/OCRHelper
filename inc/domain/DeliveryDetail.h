#ifndef INC_DOMAIN_DELIVERYDETAIL_H_
#define INC_DOMAIN_DELIVERYDETAIL_H_

#include <string>
#include <vector>

#include "Product.h"

namespace domain {

class DeliveryDetail
{
public:
	//dtor
	DeliveryDetail():
		Quantity()
	{};
	//ctor
	virtual ~DeliveryDetail(){};

	std::string Quantity;				// Menge
	Product Product;					// Gelieferter Artikel
};

}

#endif /* INC_DOMAIN_DELIVERYDETAIL_H_ */
