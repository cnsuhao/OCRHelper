#include <iostream>
#include <getopt.h>

#include "env/include/Asprise/asprise_ocr_api.h"

#include "inc/Logger.h"
#include "inc/engine/TesseractEngine.h"

using namespace std;
using namespace engine;

#define CL_OPTION_NO_ARGUMENT 			0
#define CL_OPTION_ARGUMENT_REQUIRED 	1
#define CL_OPTION_ARGUMENT_OPTINIONAL 	2

#define VERSION "ocr-0.1.0"


static void showUsage(char* path)
{
	 printf("Usage: %s [OPTIONS]\n", path);
	 printf("  -f, --logfile             full path to log file\n");
	 printf("  -h, --help                print this help and exit\n");
	 printf("  -i, --input               given supplier delivery slip as file\n");
	 printf("  -l, --loglevel            prioritized log level\n");
	 printf("  -o, --supplier_order_id   supplier order id\n");
	 printf("  -p, --policy              supplier ocr configuration\n");
	 printf("--------\n");
	 printf("Version: %s", VERSION);
	 printf("\n");
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

void runTesseract()
{
	TesseractEngine tess;
	tess.init("..//data//faller1.png");
	string str = tess.run();
	std::cout << "Returned: " << str << std::endl;
}


//--loglevel=debug
//--logfile=/opt/supplier_ocr/log/noch_20170101.log
//--input=/opt/supplier_ocr/input/noch_20170101.pdf
//--policy=/opt/supplier_ocr/etc/noch.cfg
//--supplier_order_id=123456

int main(int argc, char *argv[])
{
	string strSupplierOrderId = "";
	string strLogLevel = "none";
	string strLogFile = "test.log";
	string strInput = "";
	string strPolicy = "";


	//runTesseract();

	OcrLogger logger;







	logger.init(strLogFile, strLogLevel);
	logger();

	int c;
	static struct option long_options[] = {
		{"loglevel",     		CL_OPTION_ARGUMENT_REQUIRED, 	0,  'l' },
		{"logfile",     		CL_OPTION_ARGUMENT_REQUIRED,	0,  'f' },
		{"input",     			CL_OPTION_ARGUMENT_REQUIRED, 	0,  'i' },
		{"policy",     			CL_OPTION_ARGUMENT_REQUIRED,	0,  'p' },
		{"supplier_order_id",   CL_OPTION_ARGUMENT_REQUIRED, 	0,  'o' },
		{"help",   				CL_OPTION_NO_ARGUMENT, 			0,  'h' },
		{0, 0, 0, 0 }};

	while ( (c = getopt_long(argc, argv, "lfipoh", long_options, NULL)) != -1)
	{
		// check to see if a single character or long option came through
		switch (c)
		{
			 case 	-1:       			/* no more arguments */
			 case 	0:       			/* long options toggles */
			 break;

			 case 'l':
			 {
				 strLogLevel = optarg;
				 break;
			 }

			 case 'f':
			 {
				 strLogFile = optarg;
				 break;
			 }

			 case 'i':
			 {
				 strInput = optarg;
				 break;
			 }

			 case 'p':
			 {
				 strPolicy = optarg;
				 break;
			 }

			 case 'o':
			 {
				 strSupplierOrderId = optarg;
				 break;
			 }

			 case 'h':
			 {
				 showUsage(argv[0]);
				 return(0);
			 }

			 case ':':
			 case '?':
			 {
				 fprintf(stderr, "Try `%s --help' for more information.\n", argv[0]);
				 return(-2);
			 }

			 default:
			 {
				 fprintf(stderr, "%s: invalid option -- %c\n", argv[0], c);
				 fprintf(stderr, "Try `%s --help' for more information.\n", argv[0]);
				 return(-2);
			 }
		}
	}






	return 0;
}
