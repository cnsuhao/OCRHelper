#ifndef INC_DB_MARIADBCONNECTOR_H_
#define INC_DB_MARIADBCONNECTOR_H_

#include <Poco/Util/Application.h>
#include <Poco/Util/Subsystem.h>

// MariaDB
#include <Poco/Data/MySQL/MySQLException.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/SessionFactory.h>

//
#include <memory>

class MariaDB : public Poco::Util::Subsystem
{
public:
	MariaDB();
	virtual ~MariaDB();
	void GetConnection();
	bool Query ( std::string query );

protected:

	std::unique_ptr < Poco::Data::Session > m_Session;

	void initialize ( Poco::Util::Application &self );
	void reinitialize ( Poco::Util::Application &self );
	void uninitialize();
	void defineOptions ( Poco::Util::OptionSet& options );
	const char* name() const;
	std::string m_ConnectString;


};



#endif /* INC_DB_MARIADBCONNECTOR_H_ */
