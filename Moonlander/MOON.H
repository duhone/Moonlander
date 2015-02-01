#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

class TMOONLANER 
{
    //TTimer *Timer1;
    void FormKeyDown(WORD &Key);
    
    void FormCreate();
    void FormDestroy();
    void Timer1Timer();
    void formpaint();

	bool IsDone() const { return m_done; }

private:	// User declarations
 
 /*HSNDOBJ                 hsoenginesound     = NULL;*/
 bool                    soundon;
 JOYCAPS                 joystats;
 JOYINFO                 joyinfo;
 WAVEFORMATEX            wformat;
 LPHWAVEOUT              whandle;
 DWORD                   initvol;
 DWORD                   initplayrate;
 
 HDC                     hmemdc;
 HFONT                   appfont;
 HFONT                   appfont2;
 HPEN                    hpen1;
 HPEN                    hpen2;
 HBRUSH                  hbrush1;
 HANDLE                 thrustbit;
 HANDLE                 fuelbit;
 HANDLE                 altitudebit;
 HANDLE                 anglebit;
 HINSTANCE               hwnd;
 int                     a;
 char                    whichscreen;
 bool                    firstopen;
 double                  prevtime,currenttime,difftime;
 struct ascore
  {
   char name[4];
   unsigned long score;
  };
 struct options
  {
   char vidres;
   char vidgur;
   char sndonoff;
   char controltype;
   char difficulty;
  };
  options xferopt;
  ascore hscores[10];
  HFILE cfgfile;
  char level;
  char menulevel;
  char menuy;
  char doreset;
  char scale;
  unsigned short numbnewpolys;
  unsigned char dificulty;
  unsigned int onescore;
  unsigned long score;
  int altitude;
  int lbcolor,rbcolor,lfcolor,rfcolor;
  char yn16;
  bool win;
  bool paused;
  unsigned long frms1,frms2,time1,time2;

  void drawmenu();
  void flip();
  void demo();
  void drawscreen(bool done);
  void drawindicators();
  void newgame();
  void gameloop();
  void newloop();
  void resume();
public:		// User declarations
	TMOONLANER(HINSTANCE a_instance);

private:
	bool m_done = false;
	HINSTANCE m_instance;
};

