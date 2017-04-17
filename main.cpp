#include <iostream>
#include <getopt.h>

#include "env/include/Asprise/asprise_ocr_api.h"

using namespace std;

#define CL_OPTION_NO_ARGUMENT 			0
#define CL_OPTION_ARGUMENT_REQUIRED 	1
#define CL_OPTION_ARGUMENT_OPTINIONAL 	2

static void showUsage()
{
        cout << "Usage:" << endl;
        cout << "myprog input_file output_file" << endl;
}

void testAspriseOcr()
{
   const char * libFolder = "..//env//lib";
   LIBRARY_HANDLE libHandle = dynamic_load_aocr_library(libFolder);

   // one time setup
   int setup = c_com_asprise_ocr_setup(false);

   // starts the ocr engine; the pointer must be of long long type
   long long ptrToApi = c_com_asprise_ocr_start("eng", OCR_SPEED_FAST, NULL, NULL, NULL);

   char * s = c_com_asprise_ocr_recognize(ptrToApi, "..//data//faller1.png", -1, -1, -1, -1, -1,
      OCR_RECOGNIZE_TYPE_ALL, OCR_OUTPUT_FORMAT_PDF,
      "PROP_PDF_OUTPUT_FILE=result.pdf|PROP_PDF_OUTPUT_TEXT_VISIBLE=true|\
            PROP_PDF_OUTPUT_RETURN_TEXT=text", "|", "=");

   std::cout << "Returned: " << s << std::endl;

   // do more recognition here ...

   // finally, stops the OCR engine.
   c_com_asprise_ocr_stop(ptrToApi);

   dynamic_unload_aocr_library(libHandle);
}



int main(int argc, char *argv[])
{
	cout << "!!!Hello World!!!" << endl;
	testAspriseOcr();

	int c;
	static struct option long_options[] = {
		{"supplier_order_id",     CL_OPTION_ARGUMENT_REQUIRED, 0,  's' },
		{0, 0, 0, 0 }};

	while ( (c = getopt_long(argc, argv, "abcdef", long_options, NULL)) != -1)
	{
		// check to see if a single character or long option came through
		switch (c)
		{
			 case 's':
				 cout << "option A selected" << std::endl;
				 break;
			 case 'b':
				 cout << "option B selected" << std::endl;
				 break;
		}
	}

	return 0;
}
