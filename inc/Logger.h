#ifndef INC_LOGGER_H_
#define INC_LOGGER_H_

#include "../env/include/Poco/Logger.h"
#include "../env/include/Poco/SimpleFileChannel.h"
#include "../env/include/Poco/PatternFormatter.h"
#include "../env/include/Poco/FormattingChannel.h"
#include "../env/include/Poco/AutoPtr.h"

#include <iostream>

using Poco::Logger;
using Poco::SimpleFileChannel;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::AutoPtr;

class OcrLogger
{
public:
	OcrLogger(OcrLogger const&)			= delete;
    void operator=(OcrLogger const&)  	= delete;

    virtual ~OcrLogger();

    static OcrLogger& getInstance()
    {
        static OcrLogger instance;
        return instance;
    }

    void init(const std::string &logfile, const std::string &loglevel);

    //Logging Messages
    void fatal(const std::string& msg);
    void critical(const std::string& msg);
    void error(const std::string& msg);
    void warning(const std::string& msg);
    void notice(const std::string& msg);
    void info(const std::string& msg);
    void debug(const std::string& msg);
    void trace(const std::string& msg);

    // nested
private:
    OcrLogger();

    enum MSG_LEVEL { MSG_LEVEL_NONE,
    				MSG_LEVEL_TRACE,
					MSG_LEVEL_DEBUG,
					MSG_LEVEL_INFO,
					MSG_LEVEL_NOTICE,
					MSG_LEVEL_WARNING,
					MSG_LEVEL_ERROR,
					MSG_LEVEL_CRITICAL,
					MSG_LEVEL_FATAL };

    // methods
private:
    void log(const std::string& msg, MSG_LEVEL level);

    // members
private:

};


#endif /* INC_LOGGER_H_ */
