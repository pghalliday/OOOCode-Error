#include "OOOError.h"
#include "OOO_vprintf.h"

#define OOOClass OOOError
OOOPrivateData
	char * szMessage;
OOOPrivateDataEnd

OOODestructor
{
	O_free(OOOF(szMessage));
}
OOODestructorEnd

OOOMethod(char *, toString)
{
	return OOOF(szMessage);
}
OOOMethodEnd

OOOConstructor(char * szMessage, ...)
{
	va_list aArgs;

	#define OOOInterface OOOIError
	OOOMapVirtuals
		OOOMapVirtual(toString)
	OOOMapVirtualsEnd
	#undef OOOInterface

	OOOMapMethods
	OOOMapMethodsEnd

	va_start(aArgs, szMessage);
	OOO_vprintf(szMessage, aArgs);
	va_end(aArgs);

	OOOF(szMessage) = O_strdup(OOO_vprintf_szBuffer);
}
OOOConstructorEnd
#undef OOOClass
