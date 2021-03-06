#include "VBase.h"

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#if defined(_WIN32)
#include <windows.h>
#endif

void VBase::VLog(const char* format, ...)
{
	char    buf[4096], *p = buf;
	va_list args;
	int     n;

	va_start(args, format);
	n = _vsnprintf(p, sizeof buf - 3, format, args); // buf-3 is room for CR/LF/NUL

	int len = strlen(buf);
	char* con = new char[len + 2];

	strcpy(con, buf);
	con[len] = '\n';
	con[len + 1] = '\0';

	printf(con, args);
	va_end(args);

	p += (n < 0) ? sizeof buf - 3 : n;

	while (p > buf  &&  isspace(p[-1]))
		*--p = '\0';

	*p++ = '\r';
	*p++ = '\n';
	*p = '\0';

	wchar_t output[4096];
	std::mbstowcs(output, buf, strlen(buf) + 1);

#if defined(_WIN32)
	OutputDebugString(output);
#endif

	delete[] con;
}

