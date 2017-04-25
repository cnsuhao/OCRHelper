#ifndef INC_KEYVALUEPARSER_H_
#define INC_KEYVALUEPARSER_H_

#include <string>

class KeyValueParser
{
public:
	KeyValueParser(){}
	virtual ~KeyValueParser(){}

	std::string getValueByKey(	const std::string& input_,
								const std::string& key_,
								const std::string& characterset_,
								const std::string& offset_);

	std::string getRows( const std::string& input_);

};

#endif /* INC_KEYVALUEPARSER_H_ */
