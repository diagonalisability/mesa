#ifndef STW_GDISHIM_H
#define STW_GDISHIM_H

#include <windows.h>

/* Layer plane descriptor */
typedef struct tagLAYERPLANEDESCRIPTOR { // lpd
   WORD  nSize;
   WORD  nVersion;
   DWORD dwFlags;
   BYTE  iPixelType;
   BYTE  cColorBits;
   BYTE  cRedBits;
   BYTE  cRedShift;
   BYTE  cGreenBits;
   BYTE  cGreenShift;
   BYTE  cBlueBits;
   BYTE  cBlueShift;
   BYTE  cAlphaBits;
   BYTE  cAlphaShift;
   BYTE  cAccumBits;
   BYTE  cAccumRedBits;
   BYTE  cAccumGreenBits;
   BYTE  cAccumBlueBits;
   BYTE  cAccumAlphaBits;
   BYTE  cDepthBits;
   BYTE  cStencilBits;
   BYTE  cAuxBuffers;
   BYTE  iLayerPlane;
   BYTE  bReserved;
   COLORREF crTransparent;
} LAYERPLANEDESCRIPTOR, * PLAYERPLANEDESCRIPTOR, FAR* LPLAYERPLANEDESCRIPTOR;

typedef struct _WGLSWAP
{
   HDC hdc;
   UINT uiFlags;
} WGLSWAP;

#define WGL_SWAPMULTIPLE_MAX 16

WINGDIAPI DWORD WINAPI
wglSwapMultipleBuffers(UINT n,
   CONST WGLSWAP* ps);

/* wglSwapLayerBuffers flags */
#define WGL_SWAP_MAIN_PLANE     0x00000001

/* Pixel format descriptor */
typedef struct tagPIXELFORMATDESCRIPTOR
{
   WORD  nSize;
   WORD  nVersion;
   DWORD dwFlags;
   BYTE  iPixelType;
   BYTE  cColorBits;
   BYTE  cRedBits;
   BYTE  cRedShift;
   BYTE  cGreenBits;
   BYTE  cGreenShift;
   BYTE  cBlueBits;
   BYTE  cBlueShift;
   BYTE  cAlphaBits;
   BYTE  cAlphaShift;
   BYTE  cAccumBits;
   BYTE  cAccumRedBits;
   BYTE  cAccumGreenBits;
   BYTE  cAccumBlueBits;
   BYTE  cAccumAlphaBits;
   BYTE  cDepthBits;
   BYTE  cStencilBits;
   BYTE  cAuxBuffers;
   BYTE  iLayerType;
   BYTE  bReserved;
   DWORD dwLayerMask;
   DWORD dwVisibleMask;
   DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR, * PPIXELFORMATDESCRIPTOR, FAR* LPPIXELFORMATDESCRIPTOR;

#endif /* STW_PIXELFORMAT_H */
