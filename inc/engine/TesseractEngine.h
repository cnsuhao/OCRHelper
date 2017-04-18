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

		void init(std::string strPath_);
		std::string run();

	private:

		tesseract::TessBaseAPI 	*handle;
		PIX 					*img;

		std::string 			strFilename;
		std::string	 			strLang = "deu";

	};
}


#endif /* INC_TESSERACTENGINE_H_ */
