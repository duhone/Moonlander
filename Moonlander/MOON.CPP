
//---------------------------------------------------------------------------
#include<ddraw.h>

#include<mmsystem.h>
#include<math.h>
#include<float.h>
/*#include "dsutil.h"*/
#pragma hdrstop
#include "screen.h"
#include "TERAIN.h"
#include "SHIP.h"

#include "moon.h"
//---------------------------------------------------------------------------

         // DirectDraw object

HDC                     hdc;
DDPIXELFORMAT           pixform;
int bits;
LPDIRECTDRAW2            lpdd;           // DirectDraw object
LPDIRECTDRAW            lpdd1;
LPDIRECTDRAWSURFACE     lpddsprimary;   // DirectDraw primary surface
LPDIRECTDRAWSURFACE     lpddsback;      // DirectDraw back surface
short zbuffer[640][480];


terrainclass terrain;
shipclass ship;



TMOONLANER *MOONLANER;
//---------------------------------------------------------------------------
TMOONLANER::TMOONLANER(HINSTANCE a_instance) : m_instance(a_instance)
   
{
}
//---------------------------------------------------------------------------

void TMOONLANER::flip()
 {
  HRESULT ddrval;
  while(1)
   {
    ddrval = lpddsprimary->Flip(NULL,0);
    if(ddrval == DD_OK)
     {
      break;
     }
    if(ddrval == DDERR_SURFACELOST)
     {
      ddrval = lpddsprimary->Restore();
      if(ddrval != DD_OK)
       {
        break;
       }
     }
    if(ddrval != DDERR_WASSTILLDRAWING)
     {
      break;
     }

   }

  }

void TMOONLANER::drawindicators()
 {
  hmemdc = CreateCompatibleDC(hdc);
  SelectObject(hmemdc,thrustbit);
  BitBlt(hdc,0,0,65,145,hmemdc,0,0,SRCCOPY);
  SelectObject(hmemdc,altitudebit);
  BitBlt(hdc,70,0,100,60,hmemdc,0,0,SRCCOPY);
  SelectObject(hmemdc,fuelbit);
  BitBlt(hdc,575,0,65,145,hmemdc,0,0,SRCCOPY);
  SelectObject(hmemdc,anglebit);
  BitBlt(hdc,470,0,100,60,hmemdc,0,0,SRCCOPY);
  int tempy;
  tempy = 135 - (ship.retthrust() * 6.25);
  for(a=0;a<10;a++)
   {
    linedraw(hdc,10+a,tempy,10+a,135,RGB(0,255,0));
   }
  tempy = 135 - (ship.retfuel() / 20);
  for(a=0;a<15;a++)
   {
    linedraw(hdc,600+a,tempy,600+a,135,RGB(0,255,0));
   }
  tempy = 135 - (ship.retyvelocity() * 5);
  if(tempy > 135) tempy = 135;
  if(tempy <10) tempy = 10;
  for(a=0;a<10;a++)
   {
    linedraw(hdc,45+a,tempy,45+a,135,RGB(0,255,0));
   }
  SetBkColor(hdc,RGB(0,0,0));
  SetTextColor(hdc,RGB(255,0,0));
  SelectObject(hdc,appfont);



  char* string;
  int ndig,dec,sign;
  string = fcvt(ship.retaltitude(),0,&dec,&sign);
  ndig = strlen(string);
  TextOut(hdc,130-((ndig-1)*10),21,string,ndig);
  switch(lbcolor)
   {
    case 0:
      SetPixel(hdc,77,25,RGB(255,255,255));
      SetPixel(hdc,77,24,RGB(255,255,255));
      SetPixel(hdc,76,25,RGB(255,255,255));
      SetPixel(hdc,77,26,RGB(255,255,255));
      SetPixel(hdc,78,25,RGB(255,255,255));
      break;
    case 1:
      SetPixel(hdc,91,25,RGB(0,0,255));
      SetPixel(hdc,91,24,RGB(0,0,255));
      SetPixel(hdc,90,25,RGB(0,0,255));
      SetPixel(hdc,91,26,RGB(0,0,255));
      SetPixel(hdc,92,25,RGB(0,0,255));
      break;
     case 2:
      SetPixel(hdc,77,34,RGB(0,255,0));
      SetPixel(hdc,77,33,RGB(0,255,0));
      SetPixel(hdc,76,34,RGB(0,255,0));
      SetPixel(hdc,77,35,RGB(0,255,0));
      SetPixel(hdc,78,34,RGB(0,255,0));
      break;
   case 3:
      SetPixel(hdc,91,34,RGB(255,0,0));
      SetPixel(hdc,91,33,RGB(255,0,0));
      SetPixel(hdc,90,34,RGB(255,0,0));
      SetPixel(hdc,91,35,RGB(255,0,0));
      SetPixel(hdc,92,34,RGB(255,0,0));
      break;

   }
  switch(rbcolor)
   {
    case 0:
      SetPixel(hdc,148,25,RGB(255,255,255));
      SetPixel(hdc,148,24,RGB(255,255,255));
      SetPixel(hdc,147,25,RGB(255,255,255));
      SetPixel(hdc,148,26,RGB(255,255,255));
      SetPixel(hdc,149,25,RGB(255,255,255));
      break;
    case 1:
      SetPixel(hdc,162,25,RGB(0,0,255));
      SetPixel(hdc,162,24,RGB(0,0,255));
      SetPixel(hdc,161,25,RGB(0,0,255));
      SetPixel(hdc,162,26,RGB(0,0,255));
      SetPixel(hdc,163,25,RGB(0,0,255));
      break;
     case 2:
      SetPixel(hdc,148,34,RGB(0,255,0));
      SetPixel(hdc,148,33,RGB(0,255,0));
      SetPixel(hdc,147,34,RGB(0,255,0));
      SetPixel(hdc,148,35,RGB(0,255,0));
      SetPixel(hdc,149,34,RGB(0,255,0));
      break;
  case 3:
      SetPixel(hdc,162,34,RGB(255,0,0));
      SetPixel(hdc,162,33,RGB(255,0,0));
      SetPixel(hdc,161,34,RGB(255,0,0));
      SetPixel(hdc,162,35,RGB(255,0,0));
      SetPixel(hdc,163,34,RGB(255,0,0));
      break;

   }
 switch(lfcolor)
   {
    case 0:
      SetPixel(hdc,94,45,RGB(255,255,255));
      SetPixel(hdc,94,44,RGB(255,255,255));
      SetPixel(hdc,93,45,RGB(255,255,255));
      SetPixel(hdc,94,46,RGB(255,255,255));
      SetPixel(hdc,95,45,RGB(255,255,255));
      break;
    case 1:
      SetPixel(hdc,108,45,RGB(0,0,255));
      SetPixel(hdc,108,44,RGB(0,0,255));
      SetPixel(hdc,107,45,RGB(0,0,255));
      SetPixel(hdc,108,46,RGB(0,0,255));
      SetPixel(hdc,109,45,RGB(0,0,255));
      break;
    case 2:
      SetPixel(hdc,94,54,RGB(0,255,0));
      SetPixel(hdc,94,53,RGB(0,255,0));
      SetPixel(hdc,93,54,RGB(0,255,0));
      SetPixel(hdc,94,55,RGB(0,255,0));
      SetPixel(hdc,95,54,RGB(0,255,0));
      break;
    case 3:
      SetPixel(hdc,108,54,RGB(255,0,0));
      SetPixel(hdc,108,53,RGB(255,0,0));
      SetPixel(hdc,107,54,RGB(255,0,0));
      SetPixel(hdc,108,55,RGB(255,0,0));
      SetPixel(hdc,109,54,RGB(255,0,0));
      break;

   }
 switch(rfcolor)
   {
    case 0:
      SetPixel(hdc,131,45,RGB(255,255,255));
      SetPixel(hdc,131,44,RGB(255,255,255));
      SetPixel(hdc,130,45,RGB(255,255,255));
      SetPixel(hdc,131,46,RGB(255,255,255));
      SetPixel(hdc,132,45,RGB(255,255,255));
      break;
    case 1:
      SetPixel(hdc,145,45,RGB(0,0,255));
      SetPixel(hdc,145,44,RGB(0,0,255));
      SetPixel(hdc,144,45,RGB(0,0,255));
      SetPixel(hdc,145,46,RGB(0,0,255));
      SetPixel(hdc,146,45,RGB(0,0,255));
      break;
    case 2:
      SetPixel(hdc,131,54,RGB(0,255,0));
      SetPixel(hdc,131,53,RGB(0,255,0));
      SetPixel(hdc,130,54,RGB(0,255,0));
      SetPixel(hdc,131,55,RGB(0,255,0));
      SetPixel(hdc,132,54,RGB(0,255,0));
      break;
     case 3:
      SetPixel(hdc,145,54,RGB(255,0,0));
      SetPixel(hdc,145,53,RGB(255,0,0));
      SetPixel(hdc,144,54,RGB(255,0,0));
      SetPixel(hdc,145,55,RGB(255,0,0));
      SetPixel(hdc,146,54,RGB(255,0,0));
      break;

   }
  int pos;
  pos = pow((fabs(double(ship.retangle()) * 355.5556)),(0.333333));
  if(ship.retangle() < 0) pos = -1 * pos;
  linedraw(hdc,pos+520,24,pos+520,36,RGB(0,255,0));
  DeleteDC(hmemdc);
  
 }

void TMOONLANER::drawscreen(bool done)
 {
   DDSURFACEDESC ddsd;
  ddsd.dwSize = sizeof(ddsd);
    unsigned short* shortsurf;
    if (lpddsback->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL) == DD_OK)
   {
  unsigned int* surf;

  surf = (unsigned int*)ddsd.lpSurface;
  shortsurf = (unsigned short*)surf;
  memset(surf,0,153600);
         /*  asm
         {
          mov eax,0
          mov ecx,153600
          mov edi,surf
          cld
          rep stosd*/
          //}


/*   if(lpddsback->GetDC(&hdc) == DD_OK)
     {

     PatBlt(hdc,0,0,640,480,BLACKNESS);
    }lpddsback->ReleaseDC(hdc);
 */ terrain.drawterrain(shortsurf,xferopt.vidgur,bits,lpddsback,zbuffer,ddsd.lPitch);
  ship.drawship(shortsurf,xferopt.vidgur,bits,lpddsback,zbuffer,ddsd.lPitch);
 } lpddsback->Unlock(NULL);

  appfont = CreateFont(20,8,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");

  if(lpddsback->GetDC(&hdc) == DD_OK)
     {

  drawindicators();
  if(done)
   {
    SetTextColor(hdc,RGB(255,0,0));
    SetBkColor(hdc,RGB(0,0,0));
    if(win==1) TextOut(hdc,250,40,"YOU WIN",7);
     else TextOut(hdc,250,40,"YOU LOSE",8);
      	 prevtime = GetCurrentTime();
			  difftime = 0;

      while(difftime <= 1000)
				{
				 currenttime = GetCurrentTime();
				 difftime = currenttime - prevtime;
				}


    TextOut(hdc,200,80,"REMEANING FUEL",14);
   	char* string;
    int ndig,dec,sign;
    string = fcvt(ship.retfuel(),0,&dec,&sign);
    ndig = strlen(string);
    TextOut(hdc,400,80,string,ndig);
    TextOut(hdc,200,120,"SCORE MULTIPLIER",16);
    int lcolor;
    lcolor =terrain.retcolor(ship.retxpos());
    string = fcvt(lcolor,0,&dec,&sign);
    ndig = strlen(string);
    TextOut(hdc,400,120,string,ndig);
    TextOut(hdc,200,160,"DIFFICULTY MODIFYER",20);
    string = fcvt(level,0,&dec,&sign);
    ndig = strlen(string);
    if(level == 1) 			TextOut(hdc,400,160,"-50%",4);
    if(level == 2) 			TextOut(hdc,400,160,"NONE",4);
    if(level == 3) 			TextOut(hdc,400,160,"+50%",4);
    TextOut(hdc,200,200,"SCORE",5);
    if(win == 1)
     {
      if(level == 1) onescore = (ship.retfuel() * lcolor) - (ship.retfuel() * lcolor * 0.5);
      if(level == 2) onescore = (ship.retfuel() * lcolor);
      if(level == 3) onescore = (ship.retfuel() * lcolor) + (ship.retfuel() * lcolor * 0.5);
     }
     string = fcvt(onescore,0,&dec,&sign);
     ndig = strlen(string);
     TextOut(hdc,400,200,string,ndig);
     TextOut(hdc,200,240,"TOTAL SCORE",11);
     score += onescore;
     string = fcvt(score,0,&dec,&sign);
     ndig = strlen(string);
     TextOut(hdc,400,240,string,ndig);
	 /*  */
     		string = fcvt((frms1/(time1/1000)),0,&dec,&sign);
			    ndig = strlen(string);
			    TextOut(hdc,350,10,string,ndig);
             	string = fcvt((frms2/(time2/1000)),0,&dec,&sign);
			    ndig = strlen(string);
			    TextOut(hdc,400,10,string,ndig);
                string = fcvt(terrain.retnumpolys(),0,&dec,&sign);
 			    ndig = strlen(string);
                TextOut(hdc,270,10,string,ndig);


 }
   }
   lpddsback->ReleaseDC(hdc);
  DeleteObject(appfont);
 }

void TMOONLANER::demo()
 {
  double initialtime,comdifftime;
  ship.resetvars();
  ship.setxpos(530);
  ship.setypos(100);
  ship.setangle(0);
  ship.setthrust(20);
  ship.setfuel(1250);
  ship.setaltitude(1000);
  ship.setfire(false);
  terrain.newterrain(90);
  terrain.setaltitudearray();
  terrain.transform(ship.retxpos(),ship.retypos(),1);
  terrain.cull();
 /* terrain.zclip(); */
  terrain.project();
 /* terrain.xyclip(ship.retxpos(),ship.retypos());
  */ship.transform(1,xferopt.vidgur);
  ship.setaltitude(terrain.getaltitude(ship.retxpos(),ship.retypos(),1));
   drawscreen(false);

    flip();


  initialtime = GetTickCount();
  prevtime = initialtime;
  currenttime = prevtime;
  for(;;)
   {
    if(GetAsyncKeyState(VK_ESCAPE) < 0)
     break;


    prevtime = currenttime;
    currenttime = GetTickCount();
    difftime = currenttime - prevtime;
    comdifftime = currenttime - initialtime;
    if(comdifftime > 9740) break;
    if(comdifftime >100 && comdifftime < 700)
     	ship.addangle(-0.003142 * difftime);
    if(comdifftime >700 && comdifftime < 1700)
     	ship.setfire(true);
    if(comdifftime > 3800 && comdifftime < 4200)
     ship.setfire(false);

    if(comdifftime > 4200 && comdifftime < 5400)
     ship.addangle(0.003142 * difftime);
    if(comdifftime > 5600 && comdifftime < 6100)
     ship.setfire(true);

    if(comdifftime > 6500 && comdifftime < 7200)
     ship.addthrust(-0.01 * difftime);
    if(comdifftime > 7200 && comdifftime < 7600)
     ship.setfire(false);
    if(comdifftime > 7600 && comdifftime < 8000)
     ship.addangle(-0.003142 * difftime);
    if(comdifftime > 8000 && comdifftime < 8600)
     ship.setfire(true);

    ship.moveship(difftime);
    terrain.transform(ship.retxpos(),ship.retypos(),1);
   /* terrain.project();  */
    ship.transform(1,xferopt.vidgur);
    ship.setaltitude(terrain.getaltitude(ship.retxpos(),ship.retypos(),1));

      drawscreen(false);

      flip();

     
  }
 }

void TMOONLANER::drawmenu()
 {
  if(lpddsback->GetDC(&hdc) == DD_OK)
   {
    hpen1 = CreatePen(PS_SOLID,1,RGB(255,0,0));
    hbrush1 = CreateSolidBrush(RGB(255,0,0));
    PatBlt(hdc,0,0,640,480,BLACKNESS);
    SelectObject(hdc,hpen1);
    SelectObject(hdc,hbrush1);
    SetBkColor(hdc,RGB(0,0,0));
    SetTextColor(hdc,RGB(255,0,0));
    if(menulevel == 1)
     {
   appfont = CreateFont(56,21,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");
     SelectObject(hdc,appfont);

      TextOut(hdc,200,100,"NEW GAME",8);
      TextOut(hdc,200,200,"OPTIONS",7);
      TextOut(hdc,200,300,"QUIT",4);

      Ellipse(hdc,150,117+100*menuy,180,137+100*menuy);
      lpddsback->ReleaseDC(hdc);
     }
    if(menulevel == 2)
     {
     appfont = CreateFont(40,15,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");
     SelectObject(hdc,appfont);
     appfont2 = CreateFont(24,9,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");


      TextOut(hdc,40,50,"Video Reolution",15);
      TextOut(hdc,40,125,"Gouraurd Shading",16);
      TextOut(hdc,40,200,"SOUND",5);
      TextOut(hdc,40,275,"Control Type",12);
      TextOut(hdc,40,350,"Reset High Scores",17);
      SelectObject(hdc,appfont2);
      SetTextColor(hdc,RGB(192,0,0));

      if(xferopt.vidres == 1)
       TextOut(hdc,420,63,"640x480",7);
      if(xferopt.vidres == 2)
       TextOut(hdc,420,63,"1024x768",8);
       if(xferopt.vidgur == 2)
       TextOut(hdc,420,137,"ON",2);
      if(xferopt.vidgur == 1)
       TextOut(hdc,420,137,"OFF",3);
       if(xferopt.sndonoff == 2)
       TextOut(hdc,420,212,"ON",2);
      if(xferopt.sndonoff == 1)
       TextOut(hdc,420,212,"OFF",3);
       if(xferopt.controltype == 1)
       TextOut(hdc,420,287,"Keyboard Only",13);
      if(xferopt.controltype == 2)
       TextOut(hdc,420,287,"Joystick",8);
      if(xferopt.controltype == 3)
       TextOut(hdc,420,287,"Joystick and Throttle",21);
      if(doreset == true)
       TextOut(hdc,420,362,"Done",4);

       Ellipse(hdc,2,60+75*menuy,32,80+75*menuy);
     lpddsback->ReleaseDC(hdc);


     }
    flip();
    DeleteObject(appfont);
    DeleteObject(hpen1);
    DeleteObject(appfont2);
   }
 }




void TMOONLANER::FormKeyDown(WORD &Key)
{
 switch(Key)
  {
   case 0x0000004e:
    {
     if((menulevel == 0) && !paused)
      {
       newgame();
       break;

      }
    }
   case 0x00000052:
    {
     if((menulevel == 0) && paused)
      {
       resume();
       break;
      }
     }
   case VK_ESCAPE:
    {
     if(menulevel == 0)
      {
       //Timer1->Enabled = false;
       menulevel = 1;
       drawmenu();
       break;
      }
     if(menulevel == 1)
      {
       if(paused)
        {
         menulevel = 0;
         menuy = 0;
     /*    resume();
     */  //PostMessage(Handle,WM_KEYDOWN,0x00000052,0x00000000);
         break;
        }
       else
        {
         menulevel = 0;
         menuy = 0;
         firstopen = true;
         //Timer1->Enabled = true;
         //Timer1->Interval = 200;
         break;
        }
      }
     if(menulevel == 2)
      {
       menulevel = 1;
       menuy = 0;
       drawmenu();
       break;
      }

    }
   case VK_UP:
    {
     if(menulevel == 1)
      {
       menuy -= 1;
       if(menuy == -1) menuy = 2;
       drawmenu();
       break;
      }
    if(menulevel == 2)
      {
       menuy -= 1;
       if(menuy == -1) menuy = 4;
       drawmenu();
       break;
      }

     }
    case VK_DOWN:
     {
      if(menulevel == 1)
       {
        menuy += 1;
        if(menuy == 3) menuy = 0;
        drawmenu();
        break;
       }
   if(menulevel == 2)
       {
        menuy += 1;
        if(menuy == 5) menuy = 0;
        drawmenu();
        break;
       }

      }
     case VK_RETURN:
      {
       if(menulevel == 1 && menuy == 2)
        {
		   m_done = true;
        }
       if(menulevel == 1 && menuy == 1)
        {
         menulevel = 2;
         menuy = 0;
         drawmenu();
         break;
        }
       if(menulevel == 1 && menuy == 0)
        {
         menulevel = 0;
         menuy = 0;
         //PostMessage(Handle,WM_KEYDOWN,0x0000004e,0x00000000);
      /*   newgame();
      */   break;
        }

       if(menulevel == 2 && menuy == 0)
        {
         if(xferopt.vidres == 1)
          xferopt.vidres = 2;
         else xferopt.vidres = 1;
         drawmenu();
         break;
        }
       if(menulevel == 2 && menuy == 1)
        {
         if(xferopt.vidgur == 1)
          xferopt.vidgur = 2;
         else xferopt.vidgur = 1;
         drawmenu();
         break;
        }
   if(menulevel == 2 && menuy == 2)
        {
         if(xferopt.sndonoff == 1)
          xferopt.sndonoff = 2;
         else xferopt.sndonoff = 1;
         if(xferopt.sndonoff == 2)
          {
            wformat.wFormatTag = WAVE_FORMAT_PCM;
           wformat.nChannels = 1;
           wformat.nSamplesPerSec = 22050l;
           wformat.nAvgBytesPerSec = 22050l;
           wformat.nBlockAlign = 1;
           wformat.wBitsPerSample = 8;
           wformat.cbSize = 0;
           waveOutOpen(whandle,WAVE_MAPPER,&wformat,0,0,CALLBACK_NULL);
           waveOutGetVolume(*whandle,&initvol);
           waveOutSetVolume(*whandle,0xff00ff00);






            }
         if(xferopt.sndonoff == 1)
          {
           PlaySound(NULL,NULL,NULL);
           waveOutSetVolume(*whandle,initvol);
           waveOutReset(*whandle);
           waveOutClose(*whandle);
          }
         drawmenu();
         break;
        }
     if(menulevel == 2 && menuy == 3)
        {
         xferopt.controltype += 1;
         if(xferopt.controltype == 4)
          xferopt.controltype = 1;
         if(xferopt.controltype == 2)
          {
           MMRESULT mr;
           mr = joyGetDevCaps(JOYSTICKID1,&joystats,sizeof(joystats));
           if(!(mr == JOYERR_NOERROR))
           xferopt.controltype == 1;
          }
         if(xferopt.controltype == 3)
          {
           MMRESULT mr;
           mr = joyGetDevCaps(JOYSTICKID1,&joystats,sizeof(joystats));
           if(!(joystats.wCaps == JOYCAPS_HASZ))
            xferopt.controltype == 2;
           if(!(mr == JOYERR_NOERROR))
            xferopt.controltype == 1;
          }


         drawmenu();
         break;
        }
     if(menulevel == 2 && menuy == 4)
        {
         int a;
         for(a=0;a<=9;a++)
		  {
		   hscores[a].name[0] = NULL;
		   hscores[a].score = 0;
		  }
         double b,c;
         doreset = true;
         drawmenu();
         b = GetTickCount();
         c=b;
         doreset = false;
         while((c-b) < 750)
          {
           c = GetTickCount();
          }
         drawmenu();
         break;
        }


       }
     }
  }
//---------------------------------------------------------------------------




void TMOONLANER::FormCreate()
{
 _control87(MCW_EM,MCW_EM);
 _control87(PC_24,MCW_PC);
 //randomize();


  ShowCursor(FALSE);

ddinit(&bits,&lpdd,&lpdd1,&lpddsprimary,&lpddsback,m_instance);

//Timer1->Enabled = true;

 /*HDC hdc;*/

 /*if(lpddsprimary->GetDC(&hdc) == DD_OK)
  {
   PatBlt(hdc,0,0,640,480,BLACKNESS);
     SelectObject(hdc,appfont);
   SetBkColor(hdc,RGB(0,0,0));
   SetTextColor(hdc,RGB(255,0,0));
   TextOut(hdc,150,200,"MOONLANDER",10);
   lpddsback->ReleaseDC(hdc);
  }*/
  whichscreen = 1;
  firstopen = true;
   xferopt.difficulty = 1;
   xferopt.vidres = 1;
   xferopt.vidgur = 1;
   xferopt.sndonoff = 1;
   xferopt.controltype = 1;


	  int a;
      for(a=0;a<=9;a++)
		{
		 hscores[a].name[0] = NULL;
		 hscores[a].score = 0;
		}
	  cfgfile = _lopen("moonland.cfg",OF_READWRITE);
	  char temp[8];
	  _lread(cfgfile,temp,5);
	  memmove(&xferopt,temp,5);
	  for(a=0;a<=9;a++)
		{

		 _lread(cfgfile,temp,8);
		 memmove(&hscores[a],temp,8);
		}
	   _lclose(cfgfile);
       menuy = 0;
       /*hscores[2].name[0] = 'G';
       hscores[2].name[1] = 'H';
       hscores[2].name[2] = 'I';
       hscores[2].name[3] = NULL;
       hscores[2].score = 9;
       */
  thrustbit = LoadImage(GetModuleHandle(NULL),"thrustbitmap",IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR);
  fuelbit = LoadImage(GetModuleHandle(NULL),"fuelbitmap",IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR);
  altitudebit = LoadBitmap(GetModuleHandle(NULL),"altitudebitmap");
  anglebit = LoadImage(GetModuleHandle(NULL),"anglebitmap",IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR);
  level = 1;

  if(xferopt.controltype == 2)
          {
           MMRESULT mr;
           mr = joyGetDevCaps(JOYSTICKID1,&joystats,sizeof(joystats));
           if(!(mr == JOYERR_NOERROR))
           xferopt.controltype == 1;
          }
         if(xferopt.controltype == 3)
          {
           MMRESULT mr;
           mr = joyGetDevCaps(JOYSTICKID1,&joystats,sizeof(joystats));
           if(!(joystats.wCaps == JOYCAPS_HASZ))
            xferopt.controltype == 2;
           if(!(mr == JOYERR_NOERROR))
            xferopt.controltype == 1;
          }

       if(xferopt.sndonoff == 2)
          {
           wformat.wFormatTag = WAVE_FORMAT_PCM;
           wformat.nChannels = 1;
           wformat.nSamplesPerSec = 22050l;
           wformat.nAvgBytesPerSec = 22050l;
           wformat.nBlockAlign = 1;
           wformat.wBitsPerSample = 8;
           wformat.cbSize = 0;
           waveOutOpen(whandle,WAVE_MAPPER,&wformat,0,0,CALLBACK_NULL);
           waveOutGetVolume(*whandle,&initvol);
           waveOutSetVolume(*whandle,0xff00ff00);
            }
    soundon = false;
    /* PlaySound("enginesound",GetModuleHandle(NULL),SND_RESOURCE | SND_ASYNC | SND_LOOP);
   HRESULT       hr;
   hr = DirectSoundCreate(NULL, &lpdsound, NULL);
   hr = lpdsound->SetCooperativeLevel(Handle, DSSCL_EXCLUSIVE);
   hsoenginesound     = SndObjCreate(lpdsound, "enginesound",      1);
   SndObjPlay(hsoenginesound, DSBPLAY_LOOPING); */
  /* pixform.dwSize = sizeof(pixform);

   GetPixelFormat(&pixform);
   */
/*   if(pixform.dwRGBBitCount == 16) bits = 16;
    else bits = 15;
  */

 /* bits = 15;*/
 }
//---------------------------------------------------------------------------

void TMOONLANER::FormDestroy()
{
  PlaySound(NULL,NULL,NULL);
 /*SndObjDestroy(hsoenginesound);
 hsoenginesound = NULL;
 lpdsound->Release();*/
if(lpdd != NULL)
 {
  if(lpddsprimary != NULL)
   {
    lpddsprimary->Release();
    lpddsprimary = NULL;
   }
  lpdd->Release();
  lpdd = NULL;
 }

 if(xferopt.sndonoff == 2)
          {

           waveOutSetVolume(*whandle,initvol);
           waveOutReset(*whandle);
           waveOutClose(*whandle);
          }



  char temp[8];

	  cfgfile = _lopen("moonland.cfg",OF_READWRITE);

	  memmove(temp,&xferopt,5);


	  /*errcode =*/ _lwrite(cfgfile,temp,5);
	  int a;
      for(a=0;a<=9;a++)
		{
		 memmove(temp,&hscores[a],8);
		 /*errcode =*/ _lwrite(cfgfile,temp,8);

		}
	  /*errcode =*/ _lclose(cfgfile);

 }
//---------------------------------------------------------------------------

void TMOONLANER::Timer1Timer()
{
 if(firstopen == true)
  {
   firstopen = false;
   //Timer1->Interval = 10000;
  }
   if(whichscreen == 1)
    {
     if(lpddsback->GetDC(&hdc) == DD_OK)
      {
       appfont = CreateFont(64,24,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");
       PatBlt(hdc,0,0,640,480,BLACKNESS);
       SelectObject(hdc,appfont);
       SetBkColor(hdc,RGB(0,0,0));
       SetTextColor(hdc,RGB(255,0,0));
       TextOut(hdc,150,200,"MOONLANDER",10);
       lpddsback->ReleaseDC(hdc);
       DeleteObject(appfont);
      }
    }
   if(whichscreen == 2)
    {
     /*demo();*/
    }
   if(whichscreen == 3)
    {
     if(lpddsback->GetDC(&hdc) == DD_OK)
      {
       appfont = CreateFont(70,24,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");
       appfont2 = CreateFont(24,9,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");
       hpen1 = CreatePen(PS_SOLID,3,RGB(255,0,0));
       hpen2 = CreatePen(PS_SOLID,1,RGB(255,0,0));

       PatBlt(hdc,0,0,640,480,BLACKNESS);
       SelectObject(hdc,appfont);
       SelectObject(hdc,hpen1);
       SetBkColor(hdc,RGB(0,0,0));
       SetTextColor(hdc,RGB(255,0,0));
       TextOut(hdc,120,50,"HIGH SCORES",11);
       MoveToEx(hdc,0,150,NULL);
       LineTo(hdc,639,150);
       SelectObject(hdc,appfont2);
       TextOut(hdc,150,155,"INITIALS",8);
       TextOut(hdc,440,155,"SCORE",5);
       SelectObject(hdc,hpen2);
       MoveToEx(hdc,0,180,NULL);
       LineTo(hdc,639,180);
     int y,a,x,ndig,dec,sign;
     y = 190;
     x = 40;
     char* string;
     DeleteObject(appfont);
     appfont = CreateFont(16,6,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");

     for(a=0;a<10;a++)
      {
       if(a == 9)
        x -= 13;
       string = fcvt((a+1),0,&dec,&sign);
       ndig = strlen(string);
       TextOut(hdc,x,y,string,ndig);
       if(a == 9)
        x += 13;

       TextOut(hdc,x+130,y,hscores[a].name,strlen(hscores[a].name));
       string = fcvt(hscores[a].score,0,&dec,&sign);
       ndig = strlen(string);
       TextOut(hdc,(x+486)-(13*ndig),y,string,ndig);
       y += 29;

      }

     lpddsback->ReleaseDC(hdc);
     DeleteObject(appfont);
     DeleteObject(hpen1);
     DeleteObject(appfont2);
     DeleteObject(hpen2);
    }
    }



 whichscreen += 1;
 if(whichscreen == 4) whichscreen = 1;

 HRESULT ddrval;
 while(1)
  {
   ddrval = lpddsprimary->Flip(NULL,0);
   if(ddrval == DD_OK)
    {
     break;
    }
   if(ddrval == DDERR_SURFACELOST)
    {
     ddrval = lpddsprimary->Restore();
     if(ddrval != DD_OK)
      {
       break;
      }
    }
   if(ddrval != DDERR_WASSTILLDRAWING)
    {
     break;
    }

  }
}

void TMOONLANER::newloop()
 {
  ship.resetvars();
  ship.setxpos(640);
  ship.setypos(20);
  ship.setangle(0);
  ship.setthrust(0);
  ship.setfire(false);
  ship.setaltitude(1000);
  if(level == 1)
   {
    ship.setfuel(2500);
   }

  if(level == 2)
   {
    ship.setfuel(2250);
   }

  if(level == 3)
   {
    ship.setfuel(2000);
   }
  terrain.newterrain(dificulty);
  terrain.setaltitudearray();
  ship.setaltitude(terrain.getaltitude(ship.retxpos(),ship.retypos(),scale));




	  scale = 1;
	  onescore = 0;
	  win = false;
	  paused = false;
	/*  done = 0;*/
	  currenttime = GetCurrentTime();
	  prevtime = currenttime;
	  time1 = 0;
      time2 = 0;
      frms1 = 0;
      frms2 = 0;
 }

void TMOONLANER::gameloop()
 {
  for(;;)
		{
		 int count1,count2;
         int *clearz;
         clearz = (int*)zbuffer[0];
       /*  for(count1=0;count1<640;count1++)
          {
           for(count2=0;count2<480;count2++)
            {
             zbuffer[count1][count2] = 32766;
            }
          }
       */
		 
         /*asm
         {
          mov ecx,0
          mov eax,0x7fff7fff

          mov ecx,153600
          mov edi,clearz
          cld
          rep stosd
  }*/
         for(count1=0;count1<153600;count1++)
          {
             *(clearz+count1) = 0x7fff7fff;
          }
        /*  memset(clearz,0x01111111111111110111111111111111b,(153600*4));
          */
          prevtime = currenttime;
		 currenttime = GetTickCount();
		 difftime = currenttime - prevtime;
		 if(difftime < 0)
		  difftime = 0;
		 if(GetAsyncKeyState(VK_LEFT) < 0)
			ship.addangle(0.003142 * difftime);
		 if(GetAsyncKeyState(VK_RIGHT) < 0)
			ship.addangle(-0.003142 * difftime);
		 if(GetAsyncKeyState(VK_UP) < 0)
			ship.addthrust(0.01 * difftime);
		 if(GetAsyncKeyState(VK_DOWN) < 0)
			ship.addthrust(-0.01 * difftime);
		 if(GetAsyncKeyState(VK_SPACE) < 0)
			ship.setfire(true);
			else
			 ship.setfire(false);
		 if(GetAsyncKeyState(VK_ESCAPE) < 0)
		  paused = true;
         if(xferopt.controltype == 2)
          {
           MMRESULT mr;
           mr = joyGetPos(JOYSTICKID1,&joyinfo);
           float an;
           an = (joyinfo.wXpos - 32768.0) / (joystats.wXmax - 32768.0);
           if(joyinfo.wXpos > 38768)
            {

             ship.addangle(-0.004 * an * difftime);

            }
           if(joyinfo.wXpos < 26768)
            {
             an = fabs(an);
             ship.addangle(0.004 * an * difftime);
            }
           an = (joyinfo.wYpos - 32768.0) / (joystats.wYmax - 32768.0);
           if(joyinfo.wYpos > 38768)
            {

             ship.addthrust(-0.015 * an * difftime);

            }
           if(joyinfo.wYpos < 26768)
            {
             an = fabs(an);
             ship.addthrust(0.015 * an * difftime);
            }
           if(joyinfo.wButtons == JOY_BUTTON1)
             ship.setfire(true);
             else
              ship.setfire(false);

          }
    if(xferopt.controltype == 3)
          {
           MMRESULT mr;
           mr = joyGetPos(JOYSTICKID1,&joyinfo);
           float an;
           an = (joyinfo.wXpos - 32768.0) / (joystats.wXmax - 32768.0);
           if(joyinfo.wXpos > 38768)
            {

             ship.addangle(-0.004 * an * difftime);

            }
           if(joyinfo.wXpos < 26768)
            {
             an = fabs(an);
             ship.addangle(0.004 * an * difftime);
            }
           an = double(joyinfo.wZpos - joystats.wZmin) / double(joystats.wZmax - joystats.wZmin);
             an = fabs(an - 1);
             ship.setthrust(20.0 * an);
           if(joyinfo.wButtons == JOY_BUTTON1)
             ship.setfire(true);
             else
              ship.setfire(false);

          }


       if(xferopt.sndonoff == 2)
        {
         if(ship.retfire() == true)
          {
           if(soundon)
            {
             unsigned long volume;
             volume = 5000 + (ship.retthrust() * 3000);
             volume *= 65536;
             volume += 5000 + (ship.retthrust() * 3000);
             waveOutSetVolume(*whandle,volume);


            }
            else
             {
              unsigned long volume;
              volume = 5000 + (ship.retthrust() * 3000);
              volume *= 65536;
              volume += 5000 + (ship.retthrust() * 3000);
              waveOutSetVolume(*whandle,volume);
              soundon = true;
              PlaySound("enginesound",GetModuleHandle(NULL),SND_RESOURCE | SND_ASYNC | SND_LOOP);

             }
          }
         if((ship.retfire() == false) && soundon)
          {
           soundon = false;
           PlaySound(NULL,NULL,NULL);
          }
        }

         ship.moveship(difftime);
  ship.setaltitude(terrain.getaltitude(ship.retxpos(),ship.retypos(),scale));
    	if(ship.retaltitude() < 700)
		  {
			scale = 4;
            time2 += difftime;
            frms2 += 1;
		  }
          else
           {
            scale = 1;
            time1 += difftime;
            frms1 += 1;
           }
    terrain.resetinten();
    terrain.transform(ship.retxpos(),ship.retypos(),scale);
    terrain.cull();
    numbnewpolys = 0;
  /*  if(scale == 4)
     {

      if(xferopt.vidgur == 2) numbnewpolys = terrain.gzclip(ship.retxpos(),ship.retypos());
       else numbnewpolys = terrain.zclip(ship.retxpos(),ship.retypos());
     }
   */
    terrain.project();
    if(xferopt.vidgur == 2) numbnewpolys += terrain.gxyclip(ship.retxpos(),ship.retypos());
      else terrain.xyclip(ship.retxpos(),ship.retypos());

 /*   numbnewpolys += terrain.xyclip(ship.retxpos(),ship.retypos());
  /* terrain.calcdist();
 */   ship.transform(scale,xferopt.vidgur);
    ship.cull();
    if(xferopt.vidgur == 1)
     ship.calcpolylight();
     else
      ship.calcverlight();
    ship.project();
    lbcolor = terrain.retcolor(ship.retxpos());

    rbcolor = lbcolor;
    lfcolor = lbcolor;
    rfcolor = lbcolor;
      drawscreen(false);

      flip();
    terrain.removepolys(numbnewpolys);



		/* numbframes += 1;*/
		 if(ship.retaltitude() <= 0)
		  {
            if(xferopt.sndonoff == 2)
             PlaySound(NULL,NULL,NULL);
			if((ship.retangle() < (10-(level*2)) && ship.retangle() > (-10+(level*2))) && ship.retyvelocity() < (12-(level*3)) && (lbcolor > 0))
			  win = true;
			else win = false;
         for(count1=0;count1<640;count1++)
          {
           for(count2=0;count2<480;count2++)
            {
             zbuffer[count1][count2] = 32766;
            }
          }
    numbnewpolys = 0;
    terrain.resetinten();
    terrain.transform(ship.retxpos(),ship.retypos(),scale);
    terrain.cull();
    if(scale == 4)
     {

      if(xferopt.vidgur == 2) numbnewpolys = terrain.gzclip(ship.retxpos(),ship.retypos());
       else numbnewpolys = terrain.zclip(ship.retxpos(),ship.retypos());
     }

    terrain.project();
    if(xferopt.vidgur == 2) numbnewpolys += terrain.gxyclip(ship.retxpos(),ship.retypos());
      else terrain.xyclip(ship.retxpos(),ship.retypos());
 /*   terrain.calcdist();
  */
     drawscreen(true);
     terrain.removepolys(numbnewpolys);

          flip();




		if(win==1)
         {
				 prevtime = GetCurrentTime();
			  difftime = 0;
			  while(difftime <= 2000)
				{
				 currenttime = GetCurrentTime();
				 difftime = currenttime - prevtime;
				}

	      if(lpddsprimary->GetDC(&hdc) == DD_OK)
             {
               	TextOut(hdc,150,280,"PRESS SPACE KEY TO CONTINUE WITH NEXT MISSION",45);
              lpddsprimary->ReleaseDC(hdc);
              }
            	 prevtime = GetCurrentTime();

        	  difftime = 0;
			  while(difftime <= 500)
				{
				 currenttime = GetCurrentTime();
				 difftime = currenttime - prevtime;
				}

           		while(GetAsyncKeyState(VK_SPACE) >= 0);
                  {
                  }

			 }

  			if(win==0 && (score > hscores[9].score))
			 {
			  prevtime = GetCurrentTime();
			  difftime = 0;
			  while(difftime <= 1500)
				{
				 currenttime = GetCurrentTime();
				 difftime = currenttime - prevtime;

				}
	      if(lpddsprimary->GetDC(&hdc) == DD_OK)
             {
               	TextOut(hdc,150,280,"PRESS SPACE KEY TO CONTINUE",27);
           /* 	char* string;
    			int ndig,dec,sign;
	    		string = fcvt((frms1/(time1/1000)),0,&dec,&sign);
			    ndig = strlen(string);
			    TextOut(hdc,390,10,string,ndig);
             	string = fcvt((frms2/(time2/1000)),0,&dec,&sign);
			    ndig = strlen(string);
			    TextOut(hdc,400,10,string,ndig);
                string = fcvt(terrain.retnumpolys(),0,&dec,&sign);
 			    ndig = strlen(string);
                TextOut(hdc,300,10,string,2);
          */    lpddsprimary->ReleaseDC(hdc);
              }

			  while(difftime <= 500)
				{
				 currenttime = GetCurrentTime();
				 difftime = currenttime - prevtime;
				}

           		while(GetAsyncKeyState(VK_SPACE) >= 0);
                  {
                  }

          if(lpddsprimary->GetDC(&hdc) == DD_OK)
             {

				TextOut(hdc,200,300,"ENTER YOUR INITIALS",19);
				hscores[9].score = score;
                MSG msg;
            	 prevtime = GetCurrentTime();
            	  difftime = 0;
         /*      TextOut(hdc,100,100,"1",1);
		 */	   while(difftime <= 200)
			    	{
				  currenttime = GetCurrentTime();
				  difftime = currenttime - prevtime;
				 }
          /*     TextOut(hdc,100,100,"2",1);
          */      while(PeekMessage(&msg,NULL,0,0,PM_REMOVE ))
                 {
                 }
           /*     TextOut(hdc,100,100,"3",1);
          */       while(!PeekMessage(&msg,NULL,WM_KEYFIRST,WM_KEYLAST,PM_REMOVE ))
                 {
                 }



			   /*	GetMessage(&msg,NULL,0,0); */
           /*     TextOut(hdc,100,100,"4",1);

		   */		hscores[9].name[0] = msg.wParam;
  				TextOut(hdc,400,300,&hscores[9].name[0],1);
            	 prevtime = GetCurrentTime();
            	  difftime = 0;
			   while(difftime <= 200)
			    	{
				  currenttime = GetCurrentTime();
				  difftime = currenttime - prevtime;
				 }

                while(PeekMessage(&msg,NULL,WM_KEYFIRST,WM_KEYLAST,PM_REMOVE ))
                 {
                 }


               while(!PeekMessage(&msg,NULL,WM_KEYFIRST,WM_KEYLAST,PM_REMOVE ))
                 {
                 }

		   /*		GetMessage(&msg,MOONLANER->Handle,WM_KEYFIRST,WM_KEYLAST);
			*/	hscores[9].name[1] = msg.wParam;
				TextOut(hdc,411,300,&hscores[9].name[1],1);
             	 prevtime = GetCurrentTime();
            	  difftime = 0;
			   while(difftime <= 200)
			    	{
				  currenttime = GetCurrentTime();
				  difftime = currenttime - prevtime;
				 }

                while(PeekMessage(&msg,NULL,WM_KEYFIRST,WM_KEYLAST,PM_REMOVE ))
                 {
                 }


                while(!PeekMessage(&msg,NULL,WM_KEYFIRST,WM_KEYLAST,PM_REMOVE ))
                 {
                 }



			  /*	GetMessage(&msg,MOONLANER->Handle,WM_KEYFIRST,WM_KEYLAST);
			 */	hscores[9].name[2] = msg.wParam;
				TextOut(hdc,422,300,&hscores[9].name[2],1);


              lpddsprimary->ReleaseDC(hdc);
              }
                int a;
                ascore tempscore;
				for(a=8;a>=0;a--)
				 {
				  if(hscores[a].score < score)
					{
					 tempscore = hscores[a];
					 hscores[a] = hscores[a+1];
					 hscores[a+1] = tempscore;
					}
				  else



                   break;
				 }



			 }







         	if(win == false)
             {
         /*        if(lpddsprimary->GetDC(&hdc) == DD_OK)
             {
               	char* string;
    			int ndig,dec,sign;
	    		string = fcvt((frms1/(time1/1000)),0,&dec,&sign);
			    ndig = strlen(string);
			    TextOut(hdc,300,10,string,ndig);
             	string = fcvt((frms2/(time2/1000)),0,&dec,&sign);
			    ndig = strlen(string);
			    TextOut(hdc,400,10,string,ndig);

              lpddsprimary->ReleaseDC(hdc);
              }
            */


              prevtime = GetCurrentTime();
            	  difftime = 0;
			   while(difftime <= 3000)
			    	{
				  currenttime = GetCurrentTime();
				  difftime = currenttime - prevtime;
				 }

             }

		  	break;
		  }
	  if(paused) break;

	 }


 }

void TMOONLANER::resume()
 {
    Timer1->Enabled = false;
     
  paused = false;
  prevtime = GetCurrentTime();
  difftime = 0;
  while(difftime <= 500)
   {
    currenttime = GetCurrentTime();
    difftime = currenttime - prevtime;
   }



  prevtime = GetTickCount();
  currenttime = GetTickCount();
  difftime = 0;
  gameloop();
  while(win == true)
	{
	 newloop();
	 gameloop();
	 if(dificulty < 90) dificulty += 2;
	}
    firstopen = true;
         Timer1->Enabled = true;
         Timer1->Interval = 200;


 }


void TMOONLANER::newgame()
	 {
            Timer1->Enabled = false;

      _control87(MCW_EM,MCW_EM);
      _control87(PC_24,PC_24);

	  win = true;
	  score = 0;
      bool up,down,ret;
      char pos;
      pos = 1;
      up = false;
       down = false;
       ret = false;
    

    while(!ret)
     {
      if(up) pos -= 1;
      if(down) pos += 1;
      if(pos == 0) pos = 3;
      if(pos == 4) pos = 1;
      if(lpddsback->GetDC(&hdc) == DD_OK)
         {

         PatBlt(hdc,0,0,640,480,BLACKNESS);
        appfont = CreateFont(48,18,0,0,600,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Arial");
       SelectObject(hdc,appfont);
       SetBkColor(hdc,RGB(0,0,0));
       SetTextColor(hdc,RGB(255,0,0));
       TextOut(hdc,200,100,"EASY",4);
       TextOut(hdc,200,200,"MEDIUM",6);
       TextOut(hdc,200,300,"HARD",4);
        hpen1 = CreatePen(PS_SOLID,1,RGB(255,0,0));
        hbrush1 = CreateSolidBrush(RGB(255,0,0));
       SelectObject(hdc,hpen1);
       SelectObject(hdc,hbrush1);
       Ellipse(hdc,150,14+100*pos,180,34+100*pos);


         lpddsback->ReleaseDC(hdc);
         DeleteObject(appfont);
         DeleteObject(hpen1);
         DeleteObject(hbrush1);
          flip();

         }
       up = false;
       down = false;
       ret = false;
     	 prevtime = GetCurrentTime();
            	  difftime = 0;
			   while(difftime <= 400)
			    	{
				  currenttime = GetCurrentTime();
				  difftime = currenttime - prevtime;
				 }


       while(!up && !down && !ret)
        {
          if(GetAsyncKeyState(VK_UP) < 0) up = true;
          if(GetAsyncKeyState(VK_DOWN) < 0) down = true;
          if(GetAsyncKeyState(VK_RETURN) < 0) ret = true;
        }
     }
     level = pos;
	  if(level == 1) dificulty = 2;
	  if(level == 2) dificulty = 22;
	  if(level == 3) dificulty = 42;


	  while(win == true)
		{
		 newloop();
		 gameloop();
		if(dificulty < 90) dificulty += 2;


		}
         firstopen = true;
         Timer1->Enabled = true;
         Timer1->Interval = 200;



		}



