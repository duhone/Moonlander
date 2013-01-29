//---------------------------------------------------------------------------
#ifndef SHIPH
#define SHIPH
//---------------------------------------------------------------------------

class shipclass
{
 private:
  float xposition,yposition;
  float angle,thrust,fuel,xaccel,yaccel,newxv,oldxv,newyv,oldyv,xchange,ychange;
  bool fire;
  int altitude;
  struct vertexstruct
    {
     float lx;
     float ly;
     float lz;
     float vx;
     float vy;
     float vz;
     int sx;
     int sy;
     int sz;
     float dvx;
     float dvy;
     float dvz;
     float fvx;
     float fvy;
     float fvz;

     float inten;
     float inten1;
    };
   struct polystruct
    {
     bool culled;
     vertexstruct v1;
     vertexstruct v2;
     vertexstruct v3;
     float dxv,dyv,dzv;          /*direction vectors*/
     float nxv,nyv,nzv;          /*normal vectors*/
     int midx,midy,midz;         /*midpoints of polygons*/
     float fmidx,fmidy,fmidz;
     short dist;
     colortype color;
     colortype color1;
    };




  /*struct vertexstruct
   {
    float lx;
    float ly;
    float wx;
    float wy;
    float vx;
    float vy;
   };
  struct polystruct
   {
    vertexstruct v1;
    vertexstruct v2;
    vertexstruct v3;
    COLORREF color;
   }; */
  polystruct shiparray[109];
  int a;
 void calcpolynorms(void);
 bool cmpvert(vertexstruct temp1,vertexstruct temp2);
 void cpyvert(vertexstruct *dest,vertexstruct src);
 void calcvernorms();


 public:
 shipclass(void);
 void calcpolylight(void);
 void calcverlight(void);
 void transform(int scale,char guryn);
 void cull(void);
 void project(void);
 void moveship(double diftime);
 void resetvars();
 float retxpos(void);
 float retypos(void);
 float retthrust(void);
 float retfuel(void);
 int retaltitude(void);
 int retangle(void);
 double retyvelocity();
 bool retfire(void);
 void setxpos(int xpos);
 void setypos(int ypos);
 void setangle(float ang);
 void setthrust(float th);
 void setfuel(float fl);
 void setaltitude(int alt);
 void setfire(bool fr);
 void addangle(float ang);
 void addthrust(float th);
 void drawship(unsigned short* surf,char guryn,int bits,LPDIRECTDRAWSURFACE lpddsback,short zbuffer[640][480],int pitch);


 };

#endif
