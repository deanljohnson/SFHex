// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SFHEX_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SFHEX_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SFHEX_EXPORTS
#define SFHEX_API __declspec(dllexport)
#else
#define SFHEX_API __declspec(dllimport)
#endif

// This class is exported from the SFHex.dll
class SFHEX_API CSFHex {
public:
	CSFHex(void);
	// TODO: add your methods here.
};

extern SFHEX_API int nSFHex;

SFHEX_API int fnSFHex(void);
