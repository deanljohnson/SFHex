// SFHex.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SFHex.h"


// This is an example of an exported variable
SFHEX_API int nSFHex=0;

// This is an example of an exported function.
SFHEX_API int fnSFHex(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see SFHex.h for the class definition
CSFHex::CSFHex()
{
    return;
}
