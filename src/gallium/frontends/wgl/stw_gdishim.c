#include "stw_gdishim.h"
#include "stw_pixelformat.h"
#include "stw_framebuffer.h"

int GetPixelFormat(HDC hdc)
{
   return stw_pixelformat_get(hdc);
}

int DescribePixelFormat(
   HDC                     hdc,
   int                     iPixelFormat,
   UINT                    nBytes,
   LPPIXELFORMATDESCRIPTOR ppfd
)
{
   if (iPixelFormat >= stw_pixelformat_get_count(hdc))
      return 0;

   const struct stw_pixelformat_info* info = stw_pixelformat_get_info(iPixelFormat);
   memcpy(ppfd, &info->pfd, nBytes);
   return 1;
}

BOOL SetPixelFormat(
   HDC                         hdc,
   int                         format,
   const PIXELFORMATDESCRIPTOR* ppfd
)
{
   struct stw_framebuffer* fb;

   fb = stw_framebuffer_from_hdc(hdc);
   if (fb) {
      fb->iPixelFormat = format;
      stw_framebuffer_unlock(fb);
      return TRUE;
   }

   return FALSE;
}
