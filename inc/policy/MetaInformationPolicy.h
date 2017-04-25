/*
 * MetaInformationPolicy.h
 *
 *  Created on: Apr 19, 2017
 *      Author: gheemads
 */

#ifndef INC_POLICY_METAINFORMATIONPOLICY_H_
#define INC_POLICY_METAINFORMATIONPOLICY_H_

#include <string>

class MetaInformationPolicy
{
public:
	MetaInformationPolicy():
		_deliverySlipIdKeyword(),
		_timeStampKeyword()
	{ };

	virtual ~MetaInformationPolicy(){};

	const std::string& getDeliverySlipIdKeyword() const { return _deliverySlipIdKeyword; }
	const std::string& getTimestampKeyword() const { return _timeStampKeyword; }

	void setDeliverySlipIdKeyword( const std::string& value ) { _deliverySlipIdKeyword = value; }
	void setTimestampKeyword( const std::string& value ) { _timeStampKeyword = value; }

private:
	std::string _deliverySlipIdKeyword;			// LieferscheinNummer
	std::string _timeStampKeyword;				// Zeitstempel
};



#endif /* INC_POLICY_METAINFORMATIONPOLICY_H_ */
