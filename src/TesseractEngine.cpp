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
: _handle(NULL),
  _img(NULL),
  _filename(),
  _lang("deu")
{}

TesseractEngine::~TesseractEngine()
{}

const string& TesseractEngine::run()
{
	if((_img = pixRead(_filename.c_str())) == NULL)
		die("Error reading image\n");

	_handle = new tesseract::TessBaseAPI();

	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (_handle->Init(NULL, _lang.c_str()))
		die("Error initialising tesseract\n");

	// Open input image with leptonica library
	_handle->SetImage(_img);
	_handle->Recognize(0);

	// Get OCR result
	const char* out = _handle->GetUTF8Text();
	_output = string(out);

	// Destroy used object and release memory
	_handle->End();

	pixDestroy(&_img);

	return _output;
}


void TesseractEngine::init(const string& path_)
{
	_filename = path_;
}
