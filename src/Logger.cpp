#include "../inc/Logger.h"

using namespace std;

OcrLogger::OcrLogger()
: m_pLogger(Poco::Logger::get(APP_NAME)),
  m_pLogstream(NULL)
{

}

void OcrLogger::init(const std::string &logfile, const std::string &loglevel)
{
	m_strLogfile = logfile;
	m_strLoglevel = loglevel;
}

OcrLogger::~OcrLogger()
{
	delete m_pLogstream;
}

Poco::LogStream* OcrLogger::operator()()
{
	AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
	pChannel->setProperty("path", "smaple.log");
	pChannel->setProperty("rotation", "2 K");

	Logger::root().setChannel(pChannel);
	Logger& logger = Logger::get("TestLogger");

	for (int i = 0; i < 100; ++i)
		logger.information("Testing SimpleFileChannel");

	//if (!m_pLogstream)
		//m_pLogstream = new LogStream(logger);

	return m_pLogstream;
}


