#include <string>
#include <getopt.h>

#define _DEBUG

//Aprise
#include "env/include/Asprise/asprise_ocr_api.h"
//logger
#include "inc/Logger.h"
//parser
#include "inc/KeyValueParser.h"
//engines
#include "inc/engine/TesseractEngine.h"
//domain
//policy
#include "inc/policy/MetaInformationPolicy.h"

using namespace std;
using namespace engine;

#define CL_OPTION_NO_ARGUMENT 				0
#define CL_OPTION_ARGUMENT_REQUIRED 		1
#define CL_OPTION_ARGUMENT_OPTINIONAL 		2

#define PARAM_LOGLEVEL_REQUIRED				0x01
#define PARAM_LOGFILE_REQUIRED				0x02
#define PARAM_INPUT_REQUIRED				0x04
#define PARAM_POLICY_REQUIRED				0x08
#define PARAM_SUPPLIER_ORDER_ID_REQUIRED	0x10


#define VERSION "ocr-0.1.0"

static bool checkInputParameterMask(int mask_)
{
	return mask_ == 0x1F ? true : false;
}

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

const string& runTesseract(const string& file)
{
	TesseractEngine tess;
	tess.init(file);
	return tess.run();
}

int main(int argc, char *argv[])
{
	string strSupplierOrderId 	= "";
	string strLogLevel 			= "trace";
	string strLogFile 			= "test.log";
	string strInput 			= "";
	string strPolicy 			= "";

	int mask = 0;
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
			 case  -1:     	/* no more arguments */
			 case  0:     	/* long options toggles */		break;
			 case 'l': 	{	strLogLevel = optarg;			mask |= PARAM_LOGLEVEL_REQUIRED;			break; }
			 case 'f': 	{	strLogFile = optarg;			mask |= PARAM_LOGFILE_REQUIRED;				break; }
			 case 'i':	{	strInput = optarg;				mask |= PARAM_INPUT_REQUIRED;				break; }
			 case 'p': 	{	strPolicy = optarg;				mask |= PARAM_POLICY_REQUIRED;				break; }
			 case 'o':	{	strSupplierOrderId = optarg; 	mask |= PARAM_SUPPLIER_ORDER_ID_REQUIRED;	break; }
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

	OcrLogger& logger = OcrLogger::getInstance();
	logger.init(strLogFile, strLogLevel);
	logger.trace("supplier_orc ..... Start.");


	/*
	if(!checkInputParameterMask(mask))
	{
		logger.fatal("missing input variable.");
		return(-2);
	}
	*/


	string str = runTesseract("..//data//faller1.png");

#ifdef _DEBUG
	cout << "OUTPUT: \n" << str << endl;
#endif

	KeyValueParser parser;

	string keyLieferschein = "Lieferschein";
	string keyDatum = "Datum";
	string keyAuftrag = "Auftrag:";

	string out = parser.getValueByKey(str, keyLieferschein, "[0-9]", "6");
	cout << out << endl;

	out = parser.getValueByKey(str, keyDatum, "[0-9.]", "10");
	cout << out << endl;

	out = parser.getValueByKey(str, keyAuftrag, "[0-9]", "6");
	cout << out << endl;

	logger.trace("supplier_orc ..... End.");


	return 0;
}
