#include "stdafx.h"

// DELETE THIS COMMENT BLOCK OR USE WHAT IS IN IT!
// Use the following line to make a windows program with main startup (rather than a console program)
// Remove the /entry part if you want to use WinMain instead...
//
//#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
//
//
// This is the syntax for including libraries:
//
#pragma comment(lib,"Dbghelp.lib")
#include <Dbghelp.h>
int main(int argc, char**argv)
{
    if (argc > 1)
    {
        char buf[2048];
        if (UnDecorateSymbolName(argv[1], buf, 2048, UNDNAME_COMPLETE))
        {
            // UnDecorateSymbolName returned success
            printf("Symbol : %s\n", buf);
        }
        else
        {
            // UnDecorateSymbolName failed
            DWORD error = GetLastError();
            printf("UnDecorateSymbolName returned error %d\n", error);
        }
    }
}
