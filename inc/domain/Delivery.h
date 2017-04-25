#ifndef INC_DOMAIN_DELIVERY_H_
#define INC_DOMAIN_DELIVERY_H_

#include <string>
#include <vector>

#include "DeliveryDetail.h"
#include "OcrInformation.h"

#define IMPORT_STATUS_READY			0
#define IMPORT_STATUS_PROCESSED		1
#define IMPORT_STATUS_ERROR			2
#define IMPORT_STATUS_NOT_SET 		3

namespace domain {

class Delivery
{
public:
	//ctor
	Delivery():
		DeliverySlipNumber(),
		DeliveryDate(),
		IsImported(IMPORT_STATUS_NOT_SET)
	{}
	virtual ~Delivery();

	std::string DeliverySlipNumber;						// LieferscheinNummer
	std::string DeliveryDate;							// Zeitstempel
	int IsImported;										// Import Status
	std::vector<DeliveryDetail> DeliveryDetail;			// Alle gelieferten Artikel
	OcrInformation OcrInfo;								// Zusaetzliche OCR Informationen
};

}

#endif /* INC_DOMAIN_DELIVERY_H_ */
