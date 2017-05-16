/*
 * MetaInformationPolicy.h
 *
 *  Created on: Apr 19, 2017
 *      Author: gheemads
 */

#ifndef INC_POLICY_METAINFORMATION_H_
#define INC_POLICY_METAINFORMATION_H_

#include <string>

class MetaKeywords
{
public:
	MetaKeywords():
		_deliverySlipIdKeyword(),
		_dateKeyword(),
		_customerIdKeyword(),
		_processingPersonKeyword(),
		_pageKeyword()
	{ };

	virtual ~MetaKeywords(){};

	const std::string getDeliverySlipIdKeyword() const { return _deliverySlipIdKeyword; }
	const std::string getDateKeyword() const { return _dateKeyword; }
	const std::string getCustomerIdKeyword() const { return _customerIdKeyword; }
	const std::string getProcessingPersonKeyword() const { return _processingPersonKeyword; }
	const std::string getPageKeyword() const { return _pageKeyword; }

	void setDeliverySlipIdKeyword( const std::string& value ) { _deliverySlipIdKeyword = value; }
	void setDateKeyword( const std::string& value ) { _dateKeyword = value; }
	void setCustomerIdKeyword( const std::string& value ) { _customerIdKeyword = value; }
	void setProcessingPersonKeyword( const std::string& value ) { _processingPersonKeyword = value; }
	void setPageKeyword( const std::string& value ) { _pageKeyword = value; }

private:
	std::string _deliverySlipIdKeyword;			// Lieferschein Nummer
	std::string _dateKeyword;					// Zeitstempel / Datum
	std::string _customerIdKeyword;				// Kunden-Nr.
	std::string _processingPersonKeyword;		// Bearbeiter
	std::string _pageKeyword;					// Seite/n des Lieferschein
};











#endif /* INC_POLICY_METAINFORMATION_H_ */
