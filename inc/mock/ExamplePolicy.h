#ifndef INC_POLICY_EXAMPLEPOLICY_H_
#define INC_POLICY_EXAMPLEPOLICY_H_

#include <string>
#include <vector>

#include "../policy/OcrPolicy.h"
#include "../policy/MatchSetting.h"
#include "../policy/MetaInformation.h"
#include "../policy/StringMatchDirection.h"

// Faller: 		Done, article could be difficult
// Maerklin: 	Inc
// Noch: 		Inc, needs 2 line parsing
// Tillig: 		Done
// Viessmann: 	Done

static OcrPolicy CreateFallerPolicy()
{
	OcrPolicy policy;
	MetaKeywords metaKeywords( "Lieferschein/ Delivery", "Dunningen", "Kunde/ Customer:", "", "Seite/ Page" );

	string strArticle = "FA [0-9]{3,4}|" \
						"S-H0 [0-9]{3,4}|" \
						"[0-9]{4,5}|" \
						"Z[0-9]{2,4}|" \
						"[0-9]{4,5} [A-Z]{1}[0-9]{1}";

	MatchSetting g1( "[0-9]{6}", 		"Item No.",		true, 	LEFT_TO_MIDDLE);
	MatchSetting g2( ".*", 				"Description", 	true,	MIDDLE);
	MatchSetting g3( strArticle, 		"Article",		true, 	RIGHT_TO_MIDDLE);
	MatchSetting g4( "[0-9]{1,2} STK", 	"Quantity",		true, 	RIGHT_TO_MIDDLE);
	std::vector<MatchSetting> vec =  { g1, g2, g3, g4 };

	policy.setMetaKeywords(metaKeywords);
	policy.setMatchSetting(vec);
	return policy;
};

static OcrPolicy CreateMaerklinPolicy()
{
	OcrPolicy policy;
	return policy;
};

static OcrPolicy CreateNochPolicy()
{
	OcrPolicy policy;
	MetaKeywords metaKeywords( "Nr.", "Leistungsdatum:", "Kund.-Nr.", "Vertreter:", "Seite" );

	MatchSetting g1( "[0-9]{1,3}", 				"Menge",				true, 	LEFT_TO_MIDDLE);
	MatchSetting g2( "[0-9]{5}", 				"Artikel-Nr.",			true, 	LEFT_TO_MIDDLE);
	MatchSetting g3( ".*", 						"Artikelbezeichnung", 	true,	MIDDLE);
	MatchSetting g4( "[0-9]{1,3},[0-9]{2},", 	"Einzelpreis",			true, 	RIGHT_TO_MIDDLE);
	MatchSetting g5( "[0-9]{1,3},[0-9]{2}", 	"Rabatt %",				true, 	RIGHT_TO_MIDDLE);
	MatchSetting g6( "[0-9]{1,3},[0-9]{2}", 	"Nettobetrag",			true, 	RIGHT_TO_MIDDLE);
	std::vector<MatchSetting> vec =  { g1, g2, g3, g4, g5, g6 };

	policy.setMetaKeywords(metaKeywords);
	policy.setMatchSetting(vec);
	return policy;
};

// DONE :)
static OcrPolicy CreateTilligPolicy()
{
	OcrPolicy policy;

	MetaKeywords metaKeywords( "LIEFERSCHEIN", "Datum", "Kunden-Nr.", "Bearbeiter", "Seite" );

	MatchSetting g1( "[0-9]{1,2}", 	"POS",			true, 	LEFT_TO_MIDDLE);
	MatchSetting g2( "[0-9]{5}", 	"Artikel",		true, 	LEFT_TO_MIDDLE);
	MatchSetting g3( ".*", 			"Bezeichnung", 	true,	MIDDLE);
	MatchSetting g4( "[0-9]{1,2}", 	"VP-Einheit",	false, 	RIGHT_TO_MIDDLE);
	MatchSetting g5( "[0-9]{1,2}", 	"Menge",		true, 	RIGHT_TO_MIDDLE);
	MatchSetting g6( "St",			"ME",			false,  RIGHT_TO_MIDDLE);
	std::vector<MatchSetting> vec =  { g1, g2, g3, g4, g5, g6};

	policy.setMetaKeywords(metaKeywords);
	policy.setMatchSetting(vec);
	return policy;
};

static OcrPolicy CreateViessmannPolicy()
{
	OcrPolicy policy;

	MetaKeywords metaKeywords( "Belegnummer", "Datum", "Kundennummer", "Bearbeiter", "");

	MatchSetting g1( "[0-9]{1,2}", 			"POS",			true, 	LEFT_TO_MIDDLE);
	MatchSetting g2( "[0-9]{5}", 			"Artikelnr",	true, 	LEFT_TO_MIDDLE);
	MatchSetting g3( ".*", 					"Bezeichnung", 	true,	MIDDLE);
	MatchSetting g4( "[0-9]{1,2}", 			"Menge",		true, 	RIGHT_TO_MIDDLE);
	MatchSetting g5( "Stk", 				"ME",			false, 	RIGHT_TO_MIDDLE);
	MatchSetting g6( "[0-9]{1,3},[0-9]{2}", "Einzelpreis",	true, 	RIGHT_TO_MIDDLE);
	MatchSetting g7( "[0-9]{1,3},[0-9]{2}",	"Gesamtpreis",	true,  	RIGHT_TO_MIDDLE);
	MatchSetting g8( "[0-9]{1}",			"SC",			false,  RIGHT_TO_MIDDLE);
	std::vector<MatchSetting> vec =  { g1, g2, g3, g4, g5, g6, g7, g8};

	policy.setMetaKeywords(metaKeywords);
	policy.setMatchSetting(vec);
	return policy;
};

#endif /* INC_POLICY_EXAMPLEPOLICY_H_ */
