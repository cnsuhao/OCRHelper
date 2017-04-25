#ifndef INC_DOMAIN_OCRINFORMATION_H_
#define INC_DOMAIN_OCRINFORMATION_H_

#include <string>

namespace domain {

class OcrInformation
{
public:
	//ctor
	OcrInformation():
		Filename(),
		Processed(),
		DPI(0),
		EngineName(),
		PolicyFilename()
	{}
	//dtor
	virtual ~OcrInformation(){}

	std::string Filename;			// Scanned filename (whatever format)
	std::string Processed;			// When the file got processed with an ORC engine
	int DPI;						// DPI if image
	std::string EngineName;			// Name of the OCR engine
	std::string PolicyFilename;		// Used policy file
};

}


#endif /* INC_DOMAIN_OCRINFORMATION_H_ */
