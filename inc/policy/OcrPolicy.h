/*
 * OcrPolicy.h
 *
 *  Created on: May 1, 2017
 *      Author: gheemads
 */

#ifndef INC_POLICY_OCRPOLICY_H_
#define INC_POLICY_OCRPOLICY_H_

#include "MetaInformationPolicy.h"
#include "MatchSetting.h"

class OcrPolicy
{
public:

	OcrPolicy(	MetaKeywords& metaKeywords_,
				MatchSettings& matchSettings_)
		: _metaKeywords(metaKeywords_)
		, _matchSettings(matchSettings_) {}

private:

	MetaKeywords _metaKeywords;
	MatchSetting _matchSettings;
};


#endif /* INC_POLICY_OCRPOLICY_H_ */
