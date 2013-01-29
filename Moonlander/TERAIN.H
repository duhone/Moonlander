//---------------------------------------------------------------------------
#ifndef TERAINH
#define TERAINH
//---------------------------------------------------------------------------
class terrainclass
 {
  private:
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
     int fmidx,fmidy,fmidz;
     short dist;
     colortype color;
     colortype color1;
    };
   polystruct terarray[3000];
   int maxnumbpolys;
   int numbpolys;
   int a;
   struct alt
    {
     int y;
     colortype color;
    };
   alt altarray[1280];
  public:
   void newterrain(int diff);
   void setaltitudearray(void);
   int getaltitude(int x1,int y1,int sc);
   int retcolor(int x1);
   void resetinten();
   void transform(int xpos,int ypos,float sc);
   void project(void);
   void cull(void);
   void drawterrain(unsigned short* surf,char guryn,int bits,LPDIRECTDRAWSURFACE lpddsback,short zbuffer[640][480],int pitch);
   void calcpolynorms(void);
   void calcvernorms(void);
   void calcpolylight(void);
   void calcverlight(void);
/*   void calcdist(void);
 */  unsigned int zclip(int xpos,int ypos);
   unsigned int gzclip(int xpos,int ypos);
   unsigned int xyclip(int xpos,int ypos);
   unsigned int gxyclip(int xpos,int ypos);
   void removepolys(unsigned short rempolys);
   int retnumpolys();


 };


#endif
