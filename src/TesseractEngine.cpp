/*
 * OcradEngine.cpp
 *
 *  Created on: Apr 17, 2017
 *      Author: developer
 */

#include "../inc/engine/TesseractEngine.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

using namespace std;
using namespace engine;

TesseractEngine::TesseractEngine()
: handle(NULL),
  img(NULL)
{}

TesseractEngine::~TesseractEngine()
{}

string TesseractEngine::run()
{
	if((img = pixRead(strFilename.c_str())) == NULL)
		die("Error reading image\n");

	handle = new tesseract::TessBaseAPI();

	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (handle->Init(NULL, strLang.c_str()))
		die("Error initialising tesseract\n");

	// Open input image with leptonica library
	handle->SetImage(img);

	handle->Recognize(0);

	// Get OCR result
	output = handle->GetUTF8Text();

	// Destroy used object and release memory
	handle->End();

	pixDestroy(&img);

	return output;
}


void TesseractEngine::init(std::string strPath_)
{
	this->strFilename = strPath_;
}
