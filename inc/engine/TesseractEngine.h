/*
 * TesseractEngine.h
 *
 *  Created on: Apr 17, 2017
 *      Author: gheemads
 */

#ifndef INC_TESSERACTENGINE_H_
#define INC_TESSERACTENGINE_H_

#include "../../env/include/tesseract/baseapi.h"
#include <leptonica/allheaders.h>

#include "../OcrEngine.h"

namespace engine
{
	class TesseractEngine : public OcrEngine
	{
	public:

		TesseractEngine();
		virtual ~TesseractEngine();

		void init(const std::string& strPath_);
		const std::string& run();

	private:

		tesseract::TessBaseAPI 	*_handle;
		PIX 					*_img;
		std::string 			_filename;
		std::string	 			_lang;
	};
}


#endif /* INC_TESSERACTENGINE_H_ */
