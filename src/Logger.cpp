#include "../inc/Logger.h"

using namespace std;


OcrLogger::OcrLogger()
{
}

OcrLogger::~OcrLogger()
{
}

void OcrLogger::init(const std::string &logfile, const std::string &loglevel)
{
	AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
	pChannel->setProperty("path", logfile);
	pChannel->setProperty("rotation", "2 K");

	AutoPtr<PatternFormatter> pPf(new PatternFormatter);
	pPf->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s %p LINE:%u, FILE:%U %t");

	AutoPtr<FormattingChannel> pFC(new FormattingChannel(pPf, pChannel));
	Logger::root().setChannel(pFC);

	Poco::Logger& logger = Logger::get("OcrLogger");
	logger.setLevel(loglevel);
}



void OcrLogger::fatal(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_FATAL);
}

void OcrLogger::critical(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_CRITICAL);
}

void OcrLogger::error(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_ERROR);
}

void OcrLogger::warning(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_WARNING);
}
void OcrLogger::notice(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_NOTICE);
}

void OcrLogger::info(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_INFO);
}

void OcrLogger::debug(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_DEBUG);
}

void OcrLogger::trace(const string& msg)
{
	log(msg, MSG_LEVEL::MSG_LEVEL_TRACE);
}


void OcrLogger::log(const std::string& msg, MSG_LEVEL level)
{
	switch(level)
	{
	case MSG_LEVEL::MSG_LEVEL_TRACE:		Logger::get("OcrLogger").trace(msg); 			break;
	case MSG_LEVEL::MSG_LEVEL_DEBUG:		Logger::get("OcrLogger").debug(msg); 			break;
	case MSG_LEVEL::MSG_LEVEL_INFO:			Logger::get("OcrLogger").information(msg); 		break;
	case MSG_LEVEL::MSG_LEVEL_NOTICE:		Logger::get("OcrLogger").notice(msg); 			break;
	case MSG_LEVEL::MSG_LEVEL_WARNING:		Logger::get("OcrLogger").warning(msg); 			break;
	case MSG_LEVEL::MSG_LEVEL_ERROR:		Logger::get("OcrLogger").error(msg); 			break;
	case MSG_LEVEL::MSG_LEVEL_CRITICAL:		Logger::get("OcrLogger").critical(msg); 		break;
	case MSG_LEVEL::MSG_LEVEL_FATAL:		Logger::get("OcrLogger").fatal(msg); 			break;
	default:
		Logger::get("OcrLogger").warning("Logging Message without priority: " + msg);
	}
}




