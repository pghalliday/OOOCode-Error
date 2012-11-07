#include "OOOUnitTestDefines.h"
#include "OOOError.h"

OOOTest(OOOError)
{
	OOOError * pError = OOOConstruct(OOOError, "Hello, %s!", "world");

	/* toString should return initialisation string */
	OOOCheck(O_strcmp(OOOICall(OOOCast(OOOIError, pError), toString), "Hello, world!") == 0);

	OOODestroy(pError);
}
