//---------------------------------------------------------------------------
#ifndef screenH
#define screenH
//---------------------------------------------------------------------------
struct colortype
 {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
 } clortype;


void linedraw(HDC hc,int x1,int y1,int x2,int y2,COLORREF col);
void linedraw(int x1,int y1,int x2,int y2,colortype col,int bits,LPDIRECTDRAWSURFACE lpddsback);
void linedrawf(unsigned short* surf,DDSURFACEDESC dsd,int x1,int y1,int x2,int y2,short z,colortype col,int bits);
inline void horizlinedraw(unsigned short* surf,/*DDSURFACEDESC dsd,*/int x1,int y1,int x2,int y2,short z,unsigned short col,bool ltf,short zbuffer[640][480],int lpitch);
inline void ghorizlinedraw(unsigned short* surf,/*DDSURFACEDESC dsd,*/int x1,int y1,int x2,int y2,short z,colortype col,bool ltf,float inten1,float inten2,bool flame,short zbuffer[640][480],int bits,int lpitch);
void __fastcall polydraw(unsigned short* surf,/*DDSURFACEDESC ddsd,*/int x1,int x2,int x3,int y1,int y2,int y3,short z1,colortype col,int bits,short zbuffer[640][480],LPDIRECTDRAWSURFACE lpddsback,int pitch);
void gpolydraw(unsigned short* surf,/*DDSURFACEDESC ddsd,*/int x1,int x2,int x3,int y1,int y2,int y3,short z1,colortype col,float inten1,float inten2,float inten3,bool flame,int bits,short zbuffer[640][480],int pitch);
void ddinit(int *bits,LPDIRECTDRAW2 *lpdd,LPDIRECTDRAW *lpdd1,LPDIRECTDRAWSURFACE *lpddsprimary,LPDIRECTDRAWSURFACE *lpddsback,HINSTANCE handle);



#endif

