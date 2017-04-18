#ifndef INC_LOGGER_H_
#define INC_LOGGER_H_

#include "../env/include/Poco/Logger.h"
#include "../env/include/Poco/FileChannel.h"
#include "../env/include/Poco/SimpleFileChannel.h"
#include "../env/include/Poco/AutoPtr.h"
#include "../env/include/Poco/LogStream.h"

#include <iostream>

using Poco::Logger;
using Poco::FileChannel;
using Poco::SimpleFileChannel;
using Poco::AutoPtr;
using Poco::LogStream;

#define APP_NAME "Ocr"

class OcrLogger
{
public:
    OcrLogger();
    virtual ~OcrLogger();

    void init(const std::string &logfile, const std::string &loglevel);

    Poco::LogStream* operator()();

private:
    Poco::Logger& 		m_pLogger;
    Poco::LogStream* 	m_pLogstream;
    std::string 		m_strLogfile;
    std::string			m_strLoglevel;
 };


#endif /* INC_LOGGER_H_ */
