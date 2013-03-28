#include "std.h"

#include <stdarg.h>
#include <stdio.h>

#define _DBG
#ifdef _DBG

// void __cdecl dprintf(_In_z_ _Printf_format_string_ const char * _Format, ...)
void dprintf(const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list,format);
	int buf_size = _vscprintf(format,arg_list);
	char *buf = (char*) malloc(buf_size+1);
	if (buf) {
		vsprintf(buf,format,arg_list);
		OutputDebugStringA(buf);
		free(buf);
	}
	va_end(arg_list);
}

#endif
