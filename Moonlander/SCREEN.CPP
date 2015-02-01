//---------------------------------------------------------------------------

#pragma hdrstop
#include<ddraw.h>
#include "screen.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)


void linedraw(HDC hc,int x1,int y1,int x2,int y2,COLORREF col)
 {
  int yunit,xunit;
  int ydiff = y2-y1;
  int tempx,tempy;
  tempx = x1;
  tempy = y1;
  if(ydiff<0)
   {
    ydiff = -ydiff;
    yunit = -1;
   }
  else yunit = 1;
  int xdiff = x2-x1;
  if(xdiff<0)
   {
    xdiff = -xdiff;
    xunit = -1;
   }
  else xunit = 1;
  int error = 0;
  if(xdiff>ydiff)
  {
   int length = xdiff+1;
    for(int i = 0; i<length;i++)
     {
      if(tempx < 640 && tempx >= 0)
       SetPixel(hc,tempx,tempy,col);
      tempx += xunit;
      error += ydiff;
      if(error > xdiff)
       {
        error -= xdiff;
        tempy += yunit;
       }
      }
    }
   else
   {
    int length = ydiff+1;
     for(int i = 0; i<length;i++)
      {
       if(tempx < 640 && tempx >= 0)
        SetPixel(hc,tempx,tempy,col);
       tempy += yunit;
       error += xdiff;
       if(error > ydiff)
        {
         error -= ydiff;
         tempx += xunit;
        }
       }
     }


 };

 void linedraw(int x1,int y1,int x2,int y2,colortype col,int bits,LPDIRECTDRAWSURFACE lpddsback)
 {
 /*  if(lpddsback->GetDC(&hdc) == DD_OK)
     {
  */
  unsigned short fincolor;
  fincolor = 0;
  fincolor += col.red;
  if(bits == 16) fincolor <<= 6;
   else
    {
     fincolor <<= 5;
     col.green >>= 1;
    }
  fincolor += col.green;
  fincolor <<= 5;
  fincolor += col.blue;
  unsigned short* surf;
  DDSURFACEDESC ddsd;
  ddsd.dwSize = sizeof(ddsd);
  if (lpddsback->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL) == DD_OK)
   {
    surf = (unsigned short*)ddsd.lpSurface;

  int yunit,xunit;
  int ydiff = y2-y1;
  int tempx,tempy;
  tempx = x1;
  tempy = y1;
  if(ydiff<0)
   {
    ydiff = -ydiff;
    yunit = -1;
   }
  else yunit = 1;
  int xdiff = x2-x1;
  if(xdiff<0)
   {
    xdiff = -xdiff;
    xunit = -1;
   }
  else xunit = 1;
  int error = 0;
  if(xdiff>ydiff)
  {
   int length = xdiff+1;
    for(int i = 0; i<length;i++)
     {
      /*if(tempx < 640 && tempx >= 0 && tempy < 480 && tempy >= 0) */
       *(surf + ((short)tempy * (ddsd.lPitch/2)) + (short)tempx) = fincolor;
      tempx += xunit;
      error += ydiff;
      if(error > xdiff)
       {
        error -= xdiff;
        tempy += yunit;
       }
      }
    }
   else
   {
    int length = ydiff+1;
     for(int i = 0; i<length;i++)
      {
      /* if(tempx < 640 && tempx >= 0 && tempy < 480 && tempy >= 0)*/
        *(surf +((short)tempy * (ddsd.lPitch/2)) + (short)tempx) = fincolor;
       tempy += yunit;
       error += xdiff;
       if(error > ydiff)
        {
         error -= ydiff;
         tempx += xunit;
        }
       }
     }
 } lpddsback->Unlock(NULL);

 };

 void linedrawf(unsigned short* surf,DDSURFACEDESC dsd,int x1,int y1,int x2,int y2,short z,colortype col,int bits)
 {
 /*  if(lpddsback->GetDC(&hdc) == DD_OK)
     {
  */
  unsigned short fincolor;
  fincolor = 0;
  fincolor += col.red;
  if(bits == 16) fincolor <<= 6;
   else
    {
     fincolor <<= 5;
    }
  fincolor += col.green;
  fincolor <<= 5;
  fincolor += col.blue;
  unsigned short* tsurf;

  tsurf = surf;
  int yunit,xunit;
  int ydiff = y2-y1;
  int tempx,tempy;
  tempx = x1;
  tempy = y1;
  if(ydiff<0)
   {
    ydiff = -ydiff;
    yunit = -1;
   }
  else yunit = 1;
  int xdiff = x2-x1;
  if(xdiff<0)
   {
    xdiff = -xdiff;
    xunit = -1;
   }
  else xunit = 1;
  int error = 0;
  if(xdiff>ydiff)
  {
   int length = xdiff+1;
    for(int i = 0; i<length;i++)
     {
      /*if(tempx < 640 && tempx >= 0 && tempy < 480 && tempy >= 0) */
     /* if(z<zbuffer[tempx][tempy])
       {
        zbuffer[tempx][tempy] = z;
       */ *(tsurf + ((short)tempy * (dsd.lPitch/2)) + (short)tempx) = fincolor;
       /*} */

      tempx += xunit;
      error += ydiff;
      if(error > xdiff)
       {
        error -= xdiff;
        tempy += yunit;
       }
      }
    }
   else
   {
    int length = ydiff+1;
     for(int i = 0; i<length;i++)
      {
      /* if(tempx < 640 && tempx >= 0 && tempy < 480 && tempy >= 0)*/
     /* if(z<zbuffer[tempx][tempy])
       {
        zbuffer[tempx][tempy] = z;
      */  *(tsurf + ((short)tempy * (dsd.lPitch/2)) + (short)tempx) = fincolor;
      /* }*/

       tempy += yunit;
       error += xdiff;
       if(error > ydiff)
        {
         error -= ydiff;
         tempx += xunit;
        }
       }
     }

 };

inline void horizlinedraw(unsigned short* surf,/*DDSURFACEDESC dsd,*/int x1,int y1,int x2,int y2,short z,unsigned short col,bool ltf,short zbuffer[640][480],int lpitch)
 {
 /*  if(lpddsback->GetDC(&hdc) == DD_OK)
     {
  */
  static unsigned short* tsurf;
 /* unsigned short excol;
 */ /*tsurf = surf + ((unsigned short)y1 * ((unsigned short)dsd.lPitch>>1)) + (unsigned short)x1;
 */
   if(x1 <0) x1 = 0;
   tsurf = /*(unsigned short)*/(surf + (y1 * (lpitch>>1)) + x1);
   static int count;
   if(x2<640) count = x2;
   else count = 640;
    for(unsigned short i = x1; i<=count;i++)
     {
      tsurf++;
      /*if(tempx < 640 && tempx >= 0 && tempy < 480 && tempy >= 0) */
    /*  if(x1+i < 640)
       {
    */    if(((z<zbuffer[i][y1])/* || ltf*/))
        {
         zbuffer[i][y1] = z;
    /*     excol = *(tsurf + i);

         if((excol >= 2048) && ((excol % 32) != 0))
     */     *(tsurf) = col;
        }
    /*   }
    */  }
/* } lpddsback->Unlock(NULL);
 */};

inline void ghorizlinedraw(unsigned short* surf,/*DDSURFACEDESC dsd,*/int x1,int y1,int x2,int y2,short z,colortype col,bool ltf,float inten1,float inten2,bool flame,short zbuffer[640][480],int bits,int lpitch)
 {

  /*long temp;*/
 /*if(x1>=0 && x2 <640 && y1 >=0 && y1 < 480)
 {
 /*  if(lpddsback->GetDC(&hdc) == DD_OK)
     {
  */
  float tempinten,inteninc;
  unsigned short tempgr,temprd,tempbl;
  unsigned short fincolor;
  if(bits != 16) col.green >>= 1;
/*  if(inten1 > 7.75) inten1 = 7.75;
  if(inten2 > 7.75) inten2 = 7.75;
*/
 /* avginten = (inten1 + inten2)/2.0;
  fincolor = 0;
  fincolor += col.red * avginten;
  fincolor <<= 6;
  fincolor += col.green * avginten;
  fincolor <<= 5;
  fincolor += col.blue * avginten;

 */ if(x2-x1 != 0) inteninc = (inten2 - inten1)/float(x2-x1);
  else inteninc = 0;
  if(x2-x1 != 0) tempinten = inten1;
   else tempinten = (inten1 + inten2)*0.5;
  unsigned short* tsurf;
 /* unsigned short excol;
 */ tsurf = surf + ((short)y1 * ((short)lpitch>>1)) + (short)x1;
    for(short i = 0; i<=(x2-x1);i++)
     {
      /*if(tempx < 640 && tempx >= 0 && tempy < 480 && tempy >= 0) */
      if(x1+i < 640)
       {
        if(((z<zbuffer[x1+i][y1])/* || ltf*/))
        {
         zbuffer[x1+i][y1] = z;
    /*     excol = *(tsurf + i);
         if((excol >= 2048) && ((excol % 32) != 0))
     */
       fincolor = 0;
  /*     if(tempinten > 7.75) tempinten = 7.75;
  */     if(flame)
        {
         temprd = col.red * tempinten-rand() % 7;
         tempgr = col.green * tempinten + rand()%7;
         tempbl = col.blue * tempinten + rand()%7;
        }
        else
         {
          temprd = col.red * tempinten;
          tempgr = col.green * tempinten;
          tempbl = col.blue * tempinten;
         }
 /*      if(temprd > 31) temprd = 31;
       if(tempbl > 31) tempbl = 31;
       if(bits == 16)
        {
         if(tempgr > 63) tempgr = 63;
        }
        else
         {
          if(tempgr > 31) tempgr = 31;
         }
  */     fincolor += temprd;
       if(bits == 16) fincolor <<= 6;
       else
        {
         fincolor <<= 5;

         }
        fincolor += tempgr;
        fincolor <<= 5;
        fincolor += tempbl;

       /*if(x1 + i < 640)*/ *(tsurf + i) = fincolor;
        tempinten += inteninc;

        }

       }

      }
/* } lpddsback->Unlock(NULL);
 *//*}*/
 };

void __fastcall polydraw(unsigned short* surf,/*DDSURFACEDESC ddsd,*/int x1,int x2,int x3,int y1,int y2,int y3,short z1,colortype col,int bits,short zbuffer[640][480],LPDIRECTDRAWSURFACE lpddsback,int pitch)
 {
  int tempx1,tempx2,a;
  float slope1,slope2,b1,b2,tempslope1,tempslope2;
  unsigned short fincolor;
  fincolor = 0;
  fincolor += col.red;
  if(bits == 16) fincolor <<= 6;
   else
    {
     fincolor <<= 5;
     col.green >>= 1;
    }
  fincolor += col.green;
  fincolor <<= 5;
  fincolor += col.blue;
  bool lptf;
  if((col.red == 0) || (col.blue == 0)) lptf = true;
  else lptf = false;




  if((x2-x1) != 0)
   {
    slope1 = float(y2-y1)/float(x2-x1);
   }
 /*  else slope1 = 10000;

 */ if((x3-x1) != 0)
   {
    slope2 = float(y3-y1)/float(x3-x1);
   }
 /*  else slope2 = 10000;
  /*if(slope1 == 0)
   {
    if((x2-x1) <= 0) slope1 = -0.000001;
    else slope1 = 0.000001;
   }
  if(slope2 == 0)
   {
    if((x3-x1) <= 0) slope2 = -0.000001;
    else slope2 = 0.000001;
   }


 /* if(slope2 == 0) slope2 = 0.000001;
 */
 if((x2-x1) != 0) b1 = y2 - slope1*x2;
  if((x3-x1) != 0) b2 = y3 - slope2*x3;
  a = y1;
  if(slope1 != 0) tempslope1 = 1/slope1;
  if(slope2 != 0) tempslope2 = 1/slope2;

  bool update1yn,update2yn;
    if((slope1 == 0) || ((x2-x1) == 0))
     {
      tempx1 = x2;
      update1yn = false;
     }
     else update1yn = true;

    if((slope2 == 0) || ((x3-x1) == 0))
     {
      tempx2 = x3;
      update2yn = false;
     }
     else update2yn = true;

  for(;;)
   {
/*    if((slope1 == 0) || ((x2-x1) == 0))
     tempx1 = x2;
     else tempx1 = (a-b1)*tempslope1;
  */
     if(update1yn) tempx1 = (a-b1)*tempslope1;

/*    if((slope2 == 0) || ((x3-x1) == 0))
     tempx2 = x3;
     else tempx2 = (a-b2)*tempslope2;
  */
     if(update2yn) tempx2 = (a-b2)*tempslope2;

    /*if(tempx2!=tempx1)*/
     if((a>0) && (a<480)) horizlinedraw(surf,/*ddsd,*/tempx1,a,tempx2,a,z1,fincolor,lptf,zbuffer,pitch);
    if((a >= y2) || (a >= y3)) break;
    a++;

   }
  if((a>=y2) && (a>=y3))
   {
   lpddsback->Unlock(NULL);
   return;
   }
  if(a>=y2)
   {
    a++;
    if((x3-x2) != 0) slope1 = float(y3-y2)/float(x3-x2);
/*    else slope1 = 10000;
 /*   if(slope1 == 0)
    {
     if((x3-x2) <= 0) slope1 = -0.000001;
     else slope1 = 0.000001;
    }


 /*   if(slope1 == 0) slope1 = 0.000001;
 */
    if((x3-x2) != 0) b1 = y3 - slope1*x3;
   if(slope1 != 0) tempslope1 = 1/slope1;
   if(slope2 != 0) tempslope2 = 1/slope2;

     if((slope1 == 0) || ((x3-x2) == 0))
     {
      tempx1 = x3;
      update1yn = false;
     }
     else update1yn = true;

    if((slope2 == 0) || ((x3-x1) == 0))
     {
      tempx2 = x3;
      update2yn = false;
     }
     else update2yn = true;


    for(;;)
     {
 /*   if((slope1 == 0) || ((x3-x2) == 0))
     tempx1 = x3;
     else tempx1 = (a-b1)*tempslope1;
    if((slope2 == 0) || ((x3-x1) == 0))
     tempx2 = x3;
     else tempx2 = (a-b2)*tempslope2;
*/
    if(update1yn)   tempx1 = (a-b1)*tempslope1;
    if(update2yn)   tempx2 = (a-b2)*tempslope2;
/*      tempx1 = (a-b1)/slope1;
      tempx2 = (a-b2)/slope2;
  */   /* if(tempx2!=tempx1)*/
    if((a>0) && (a<480)) horizlinedraw(surf,/*ddsd,*/tempx1,a,tempx2,a,z1,fincolor,lptf,zbuffer,pitch);
      if((a >= y3)) break;
      a++;

     }

   }
   else
    {
    a++;
    if((x3-x2) != 0) slope2 = float(y3-y2)/float(x3-x2);
/*    else slope2 = 10000;
 /*   if(slope2 == 0)
    {
     if((x3-x2) <= 0) slope2 = -0.000001;
     else slope2 = 0.000001;
    }

 /*   if(slope2 == 0) slope2 = 0.000001;
 */
    if((x3-x2) != 0) b2 = y3 - slope2*x3;

    if(slope1 != 0) tempslope1 = 1/slope1;
    if(slope2 != 0) tempslope2 = 1/slope2;

     if((slope1 == 0) || ((x2-x1) == 0))
     {
      tempx1 = x2;
      update1yn = false;
     }
     else update1yn = true;

    if((slope2 == 0) || ((x3-x2) == 0))
     {
      tempx2 = x2;
      update2yn = false;
     }
     else update2yn = true;


    for(;;)
     {
/*      if((slope1 == 0) || ((x2-x1) == 0))
     tempx1 = x2;
     else tempx1 = (a-b1)*tempslope1;
    if((slope2 == 0) || ((x3-x2) == 0))
     tempx2 = x2;
     else tempx2 = (a-b2)*tempslope2;
*/
    if(update1yn)   tempx1 = (a-b1)*tempslope1;
    if(update2yn)   tempx2 = (a-b2)*tempslope2;

/*      tempx1 = (a-b1)/slope1;
      tempx2 = (a-b2)/slope2;
  */   /* if(tempx2 > tempx1)*/
    if((a>0) && (a<480)) horizlinedraw(surf,/*ddsd,*/tempx1,a,tempx2,a,z1,fincolor,lptf,zbuffer,pitch);
      if((a >= y2)) break;
      a++;

     }

    }
  /*linedrawf(surf,ddsd,x1,y1,x2,y2,z1,col);
  linedrawf(surf,ddsd,x2,y2,x3,y3,z1,col);
  linedrawf(surf,ddsd,x3,y3,x1,y1,z1,col);
  */




 };

void gpolydraw(unsigned short* surf,/*DDSURFACEDESC ddsd,*/int x1,int x2,int x3,int y1,int y2,int y3,short z1,colortype col,float inten1,float inten2,float inten3,bool flame,int bits,short zbuffer[640][480],int pitch)
 {
  int tempx1,tempx2,a;
  float slope1,slope2,b1,b2,inteninc1,inteninc2,tempinten1,tempinten2;
  /*unsigned short fincolor;
  /*avginten = (inten1 + inten2 + inten3)/3.0;
  fincolor = 0;
  fincolor += col.red * avginten;
  fincolor <<= 6;
  fincolor += col.green * avginten;
  fincolor <<= 5;
  fincolor += col.blue * avginten;
  */bool lptf;
  if((col.red == 0) || (col.blue == 0)) lptf = true;
  else lptf = false;

  if(lptf)
   {
    if(inten1 > 3.87) inten1 = 3.87;
    if(inten2 > 3.87) inten2 = 3.87;
    if(inten3 > 3.87) inten3 = 3.87;

   }
  else
   {
    if(inten1 > 31.0) inten1 = 31.0;
    if(inten2 > 31.0) inten2 = 31.0;
    if(inten3 > 31.0) inten3 = 31.0;

   }

  if((x2-x1) != 0)
   {
    slope1 = float(y2-y1)/float(x2-x1);
   }
 /*  else slope1 = 10000;

 */ if((x3-x1) != 0)
   {
    slope2 = float(y3-y1)/float(x3-x1);
   }
 /*  else slope2 = 10000;
  /*if(slope1 == 0)
   {
    if((x2-x1) <= 0) slope1 = -0.000001;
    else slope1 = 0.000001;
   }
  if(slope2 == 0)
   {
    if((x3-x1) <= 0) slope2 = -0.000001;
    else slope2 = 0.000001;
   }


 /* if(slope2 == 0) slope2 = 0.000001;
 */
 if((x2-x1) != 0) b1 = y2 - slope1*x2;
  if((x3-x1) != 0) b2 = y3 - slope2*x3;
  a = y1;
  if(y2-y1 != 0) inteninc1 = (inten2-inten1)/float(y2-y1);
   else inteninc1 = 0;
  if(y3-y1 != 0) inteninc2 = (inten3-inten1)/float(y3-y1);
  else inteninc2 = 0;
  if(y2-y1 != 0) tempinten1 = inten1;
   else tempinten1 = inten2;
  if(y3-y1 != 0) tempinten2 = inten1;
   else tempinten2 = inten3;
  for(;;)
   {
    if(((x2-x1) == 0) || (slope1 == 0))
     tempx1 = x2;
     else tempx1 = (a-b1)/slope1;
    if(((x3-x1) == 0) || (slope2 == 0))
     tempx2 = x3;
     else tempx2 = (a-b2)/slope2;
    /*if(tempx2!=tempx1)*/ ghorizlinedraw(surf,/*ddsd,*/tempx1,a,tempx2,a,z1,col,false,tempinten1,tempinten2,flame,zbuffer,bits,pitch);
    tempinten1 += inteninc1;
    tempinten2 += inteninc2;
    if((a >= y2) || (a >= y3)) break;
    a++;

   }
  if((a>=y2) && (a>=y3))
   {
  /* lpddsback->Unlock(NULL);*/
   return;
   }
  if(a>=y2)
   {
    a++;
    if((x3-x2) != 0) slope1 = float(y3-y2)/float(x3-x2);
/*    else slope1 = 10000;
 /*   if(slope1 == 0)
    {
     if((x3-x2) <= 0) slope1 = -0.000001;
     else slope1 = 0.000001;
    }


 /*   if(slope1 == 0) slope1 = 0.000001;
 */
    if((x3-x2) != 0) b1 = y3 - slope1*x3;
    if(y3-y2 != 0)
     inteninc1 = (inten3-inten2)/(y3-y2);
     else inteninc1 = 0;
    /*if(y1==y2)*/ tempinten1 = inten2;
    for(;;)
     {
    if(((x3-x2) == 0) || (slope1 == 0))
     tempx1 = x3;
     else tempx1 = (a-b1)/slope1;
    if(((x3-x1) == 0) || (slope2 == 0))
     tempx2 = x3;
     else tempx2 = (a-b2)/slope2;

/*      tempx1 = (a-b1)/slope1;
      tempx2 = (a-b2)/slope2;
  */   /* if(tempx2!=tempx1)*/ ghorizlinedraw(surf,/*ddsd,*/tempx1,a,tempx2,a,z1,col,false,tempinten1,tempinten2,flame,zbuffer,bits,pitch);
      tempinten1 += inteninc1;
      tempinten2 += inteninc2;

      if((a >= y3)) break;
      a++;

     }

   }
   else
    {
    a++;
    if((x3-x2) != 0) slope2 = float(y3-y2)/float(x3-x2);
/*    else slope2 = 10000;
 /*   if(slope2 == 0)
    {
     if((x3-x2) <= 0) slope2 = -0.000001;
     else slope2 = 0.000001;
    }

 /*   if(slope2 == 0) slope2 = 0.000001;
 */
    if((x3-x2) != 0) b2 = y3 - slope2*x3;
    if(y3-y2 != 0) inteninc2 = (inten3-inten2)/(y3-y2);
     else inteninc2 = 0;
    tempinten2 = inten3;
    for(;;)
     {
      if(((x2-x1) == 0) || (slope1 == 0))
     tempx1 = x2;
     else tempx1 = (a-b1)/slope1;
    if(((x3-x2) == 0) || (slope2 == 0))
     tempx2 = x2;
     else tempx2 = (a-b2)/slope2;

/*      tempx1 = (a-b1)/slope1;
      tempx2 = (a-b2)/slope2;
  */   /* if(tempx2 > tempx1)*/ ghorizlinedraw(surf,/*ddsd,*/tempx1,a,tempx2,a,z1,col,false,tempinten1,tempinten2,flame,zbuffer,bits,pitch);
      tempinten1 += inteninc1;
      tempinten2 += inteninc2;

      if((a >= y2)) break;
      a++;

     }

    }
 /* colortype tempcol; */
 /* tempcol.red = 31;
  tempcol.green = 63;
  tempcol.blue = 31;
  linedrawf(surf,ddsd,x1,y1,x2,y2,z1,tempcol);
  linedrawf(surf,ddsd,x2,y2,x3,y3,z1,tempcol);
  linedrawf(surf,ddsd,x3,y3,x1,y1,z1,tempcol);
 */




 };



void ddinit(int *bits,LPDIRECTDRAW2 *lpdd,LPDIRECTDRAW *lpdd1,LPDIRECTDRAWSURFACE *lpddsprimary,LPDIRECTDRAWSURFACE *lpddsback,HWND handle)
{
 HRESULT ddrval;
 DDSURFACEDESC ddsd;
 DDSCAPS ddscaps;
 /*hwnd = reinterpret_cast<unsigned long *>(GetWindowLong(Handle,GWL_HINSTANCE));
 */ddrval = DirectDrawCreate(NULL,lpdd1,NULL);
 if(FAILED((*lpdd1)->QueryInterface(IID_IDirectDraw2,(LPVOID * )lpdd)))
  {
   //Application->MessageBox("could not get interface 2","error",MB_OK);
   PostQuitMessage(0);

  }
 (*lpdd1)->Release();
 if(ddrval == DD_OK)
  {
   ddrval = (*lpdd)->SetCooperativeLevel(handle,DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
   if(ddrval == DD_OK)
    {
     ddrval = (*lpdd)->SetDisplayMode(640,480,16,0,0);
   /*  ddrval = lpdd->Restore();
   /*   UpdateWindow(Handle);
    /* ddrval = lpdd->SetCooperativeLevel(Handle,DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
     */if(ddrval == DD_OK)
      {
       ZeroMemory(&ddsd,sizeof(ddsd));
       ddsd.dwSize = sizeof(ddsd);
       ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
       ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP | DDSCAPS_COMPLEX;
       ddsd.dwBackBufferCount = 1;
       /*Sleep(500);*/
       ddrval = (*lpdd)->CreateSurface(&ddsd,lpddsprimary,NULL);
     /*  bits = ddsd.ddpfPixelFormat.dwRBitMask + ddsd.ddpfPixelFormat.dwGBitMask + ddsd.ddpfPixelFormat.dwBBitMask;
       if(bits == 65535) bits = 16;
        else bits = 15;
     */
       if(ddrval == DD_OK)
        {
         ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
         ddrval = (*lpddsprimary)->GetAttachedSurface(&ddscaps,lpddsback);
         if(ddrval != DD_OK)
          {
           MessageBox(nullptr, "a direct draw error1","error",MB_OK);
           PostQuitMessage(0);
          }
        }
        else
         {
          MessageBox(nullptr, "a direct draw error2","eror",MB_OK);


          if(ddrval == DDERR_NOEMULATION)
           {
            MessageBox(nullptr, "a direct draw eror2a","eror",MB_OK);
            PostQuitMessage(0);
           }
          if(ddrval == DDERR_NOEXCLUSIVEMODE)
           {
            MessageBox(nullptr, "a direct draw eror2b","eror",MB_OK);
            PostQuitMessage(0);
           }
          if(ddrval == DDERR_NOFLIPHW)
           {
            MessageBox(nullptr, "a direct draw eror2c","eror",MB_OK);
            PostQuitMessage(0);
           }
          if(ddrval == DDERR_NOMIPMAPHW)
           {
            MessageBox(nullptr, "a direct draw eror2d","eror",MB_OK);
            PostQuitMessage(0);
           }

        }
      }
      else
       {
        MessageBox(nullptr, "a direct draw eror3","eror",MB_OK);
          PostQuitMessage(0);

       }

    }
    else
     {
      MessageBox(nullptr, "a direct draw eror4","eror",MB_OK);
          PostQuitMessage(0);

     }

  }
  else
   {
    MessageBox(nullptr, "a direct draw eror5","eror",MB_OK);
          PostQuitMessage(0);

   }

 if ((*lpddsprimary)->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL) == DD_OK)
   {
   unsigned short* surf;

    surf = (unsigned short*)ddsd.lpSurface;
    *surf = 0x0000;
    (*lpddsprimary)->Unlock(NULL);
   }
HDC hdc;
 if((*lpddsprimary)->GetDC(&hdc) == DD_OK)
  {
   SetPixel(hdc,0,0,RGB(255,255,255));
   (*lpddsprimary)->ReleaseDC(hdc);
  }

  if ((*lpddsprimary)->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL) == DD_OK)
   {
     unsigned short* surf;

    surf = (unsigned short*)ddsd.lpSurface;
    *bits = *surf;
    (*lpddsprimary)->Unlock(NULL);
   }
  if((*bits) == 0xffff) *bits = 16;
   else *bits = 15;


}
