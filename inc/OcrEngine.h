/*
 * OcrEngine.h
 *
 *  Created on: Apr 17, 2017
 *      Author: developer
 */

#ifndef INC_OCRENGINE_H_
#define INC_OCRENGINE_H_

#include <iostream>

using namespace std;

namespace engine
{
	class OcrEngine
	{
	public:

		OcrEngine():
			_output()
		{}

		virtual ~OcrEngine() {}

		//methods
		virtual const std::string& run() = 0;

		void die(const char *errstr)
		{
			fputs(errstr, stderr);
			exit(1);
		}

	protected:
		std::string	_output;
	};
}


#endif /* INC_OCRENGINE_H_ */
