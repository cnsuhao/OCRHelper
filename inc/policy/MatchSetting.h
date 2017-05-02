#ifndef INC_POLICY_MATCHSETTING_H_
#define INC_POLICY_MATCHSETTING_H_

#include <string>
#include "StringMatchDirection.h"

class MatchSetting
{
public:
	MatchSetting( 	const std::string& pattern_,
					const std::string& groupName_,
					const bool isMandatory_,
					const StringMatchDirection matchDirection_)
	: _pattern( pattern_ )
	, _groupName( groupName_ )
	, _isMandatory( isMandatory_ )
	, _matchDirection( matchDirection_ )
	{}

	const bool getIsMandatory() const { return _isMandatory; }
	const std::string getPattern() const { return _pattern; }
	const std::string getGroupName() const { return _groupName; }
	const StringMatchDirection getStringMatchDirection() const { return _matchDirection; }

	void setIsMandatory( const bool value ) { _isMandatory = value; }
	void setPattern( const std::string& value ) { _pattern = value; }
	void setGroupName( const std::string& value ) { _groupName = value; }
	void setStringMatchDirection( const StringMatchDirection value ) { _matchDirection = value; }

private:

	bool _isMandatory 	= false;
	StringMatchDirection _matchDirection;
	std::string _pattern = "";
	std::string _groupName = "";
};

#endif /* INC_POLICY_MATCHSETTING_H_ */
