#include "../inc/KeyValueParser.h"
#include "../inc/Logger.h"

//POCO
#include "../env/include/Poco/RegularExpression.h"

using namespace std;

string KeyValueParser::getValueByKey(	const string& input_,
										const string& key_,
										const string& characterset_,
										const string& offset_)
{
	OcrLogger& logger = OcrLogger::getInstance();
	string value;

	//TBD needs description
	string pattern = "(?<="+key_+" )"+characterset_+"{"+offset_+"}";

	Poco::RegularExpression regex(pattern);
	int i = regex.extract(input_, value);

	if(i == 0)
		logger.warning("No value found for key: " + key_);
	if(i > 1)
		logger.warning("More than one value found for key: " + key_);

	logger.info("value: '" + value + "' found for key: " + key_);

	return value;
}

