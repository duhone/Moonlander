//---------------------------------------------------------------------------
#include<ddraw.h>
#include<math.h>
#include "screen.h"
#include "Util.h"
#include "TERAIN.h"

void terrainclass::newterrain(int diff)
 {
      bool landpad;
      landpad = false;
	  int xtemp,ytemp,distance,xtemp1,xtemp2;
      float currentangle,prevangle,nextangle,multangle;
	  xtemp = 0;
	  ytemp = 0;
      maxnumbpolys = 3000;

      numbpolys = 4;
      terarray[0].v1.lx=0;
      terarray[0].v1.ly=5;
      terarray[0].v1.lz=10;
      terarray[0].v3.lx=50;
      terarray[0].v3.ly=340;
      terarray[0].v3.lz=10;
      terarray[0].v2.lx=0;
      terarray[0].v2.ly=550;
      terarray[0].v2.lz=0.1f;
      terarray[0].color.red = 1;
      terarray[0].color.green = 2;
      terarray[0].color.blue = 1;

      terarray[1].v1.lx=50;
      terarray[1].v1.ly=340;
      terarray[1].v1.lz=10;
      terarray[1].v3.lx=50;
      terarray[1].v3.ly=550;
      terarray[1].v3.lz=0.1f;
      terarray[1].v2.lx=0;
      terarray[1].v2.ly=550;
      terarray[1].v2.lz=0.1f;
      terarray[1].color.red = 1;
      terarray[1].color.green = 2;
      terarray[1].color.blue = 1;

      terarray[2].v1.lx=0;
      terarray[2].v1.ly=5;
      terarray[2].v1.lz=10;
      terarray[2].v2.lx=50;
      terarray[2].v2.ly=340;
      terarray[2].v2.lz=10;
      terarray[2].v3.lx=0;
      terarray[2].v3.ly=550;
      terarray[2].v3.lz=20;
      terarray[2].color.red = 1;
      terarray[2].color.green = 2;
      terarray[2].color.blue = 1;

      terarray[3].v1.lx=50;
      terarray[3].v1.ly=340;
      terarray[3].v1.lz=10;
      terarray[3].v2.lx=50;
      terarray[3].v2.ly=550;
      terarray[3].v2.lz=20;
      terarray[3].v3.lx=0;
      terarray[3].v3.ly=550;
      terarray[3].v3.lz=20;
      terarray[3].color.red = 1;
      terarray[3].color.green = 2;
      terarray[3].color.blue = 1;

      xtemp = 50;
      ytemp = 340;


	  currentangle = static_cast<float>((rand()%diff)+1);
	  if((rand()%2) == 0) currentangle *= -1;
	  distance = (rand()%(120-diff))+1;
	  ytemp += distance*sin(currentangle*0.017453);
	  xtemp += distance*cos(currentangle*0.017453);
	  if(ytemp < 250 || ytemp > 500)
		while(ytemp < 250 || ytemp > 500)
		 {
		  ytemp -= distance*sin(currentangle*0.017453);
		  xtemp -= distance*cos(currentangle*0.017453);
		  currentangle = (rand()%diff) + 1;
		  ytemp += distance*sin(currentangle*0.017453);
		  xtemp += distance*cos(currentangle*0.017453);
		 }
      numbpolys +=4;
      terarray[numbpolys-4].v1.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-4].v1.ly=terarray[numbpolys-5].v1.ly;
      terarray[numbpolys-4].v1.lz=10;
      terarray[numbpolys-4].v3.lx=xtemp;
      terarray[numbpolys-4].v3.ly=ytemp;
      terarray[numbpolys-4].v3.lz=10;
      terarray[numbpolys-4].v2.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-4].v2.ly=550;
      terarray[numbpolys-4].v2.lz=0.1;
      terarray[numbpolys-4].color.red = 1;
      terarray[numbpolys-4].color.green = 2;
      terarray[numbpolys-4].color.blue = 1;

      terarray[numbpolys-3].v1.lx=xtemp;
      terarray[numbpolys-3].v1.ly=ytemp;
      terarray[numbpolys-3].v1.lz=10;
      terarray[numbpolys-3].v3.lx=xtemp;
      terarray[numbpolys-3].v3.ly=550;
      terarray[numbpolys-3].v3.lz=0.1;
      terarray[numbpolys-3].v2.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-3].v2.ly=550;
      terarray[numbpolys-3].v2.lz=0.1;
      terarray[numbpolys-3].color.red = 1;
      terarray[numbpolys-3].color.green = 2;
      terarray[numbpolys-3].color.blue = 1;

      terarray[numbpolys-2].v1.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-2].v1.ly=terarray[numbpolys-5].v1.ly;
      terarray[numbpolys-2].v1.lz=10;
      terarray[numbpolys-2].v2.lx=xtemp;
      terarray[numbpolys-2].v2.ly=ytemp;
      terarray[numbpolys-2].v2.lz=10;
      terarray[numbpolys-2].v3.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-2].v3.ly=550;
      terarray[numbpolys-2].v3.lz=20;
      terarray[numbpolys-2].color.red = 1;
      terarray[numbpolys-2].color.green = 2;
      terarray[numbpolys-2].color.blue = 1;

      terarray[numbpolys-1].v1.lx=xtemp;
      terarray[numbpolys-1].v1.ly=ytemp;
      terarray[numbpolys-1].v1.lz=10;
      terarray[numbpolys-1].v2.lx=xtemp;
      terarray[numbpolys-1].v2.ly=550;
      terarray[numbpolys-1].v2.lz=20;
      terarray[numbpolys-1].v3.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-1].v3.ly=550;
      terarray[numbpolys-1].v3.lz=20;
      terarray[numbpolys-1].color.red = 1;
      terarray[numbpolys-1].color.green = 2;
      terarray[numbpolys-1].color.blue = 1;

	  prevangle = currentangle;
	  if((rand()%(6+(diff/9)))==0) currentangle = 0;
		else
		 {
		  if(currentangle < 0)
           {
            currentangle = -1*(rand()%diff)+1;
		    if(random(4) == 0) currentangle *= -1;
           }
           else
            {
             currentangle = random(diff)+1;
		     if(random(4) == 0) currentangle *= -1;
            }
		 }
	  if((currentangle!=0) && (random(6+(diff/9)) == 0))
		nextangle = 0;
		else
		 {
          if(nextangle < 0)
           {
		    nextangle = -1*random(diff)+1;
		    if(random(4) == 0) nextangle *= -1;
           }
           else
            {
		     nextangle = random(diff)+1;
		     if(random(4) == 0) nextangle *= -1;
            }
		 }
	  while(xtemp < 1239)
		{
		 if(currentangle == 0)
		  {
            numbpolys +=20;
			landpad = true;
			multangle = abs(nextangle) + abs(prevangle);
			if(multangle < 50)
			 {
              xtemp1 = xtemp + 16;
              xtemp2 = xtemp + 49;
			  xtemp += 65;
              terarray[numbpolys-20].color.red = 0;
              terarray[numbpolys-20].color.green = 0;
              terarray[numbpolys-20].color.blue = 8;
              terarray[numbpolys-19].color.red = 0;
              terarray[numbpolys-19].color.green = 0;
              terarray[numbpolys-19].color.blue = 8;
              terarray[numbpolys-18].color.red = 0;
              terarray[numbpolys-18].color.green = 0;
              terarray[numbpolys-18].color.blue = 8;
              terarray[numbpolys-17].color.red = 0;
              terarray[numbpolys-17].color.green = 0;
              terarray[numbpolys-17].color.blue = 8;
              terarray[numbpolys-16].color.red = 0;
              terarray[numbpolys-16].color.green = 0;
              terarray[numbpolys-16].color.blue = 8;
              terarray[numbpolys-15].color.red = 0;
              terarray[numbpolys-15].color.green = 0;
              terarray[numbpolys-15].color.blue = 8;
              terarray[numbpolys-14].color.red = 0;
              terarray[numbpolys-14].color.green = 0;
              terarray[numbpolys-14].color.blue = 8;
              terarray[numbpolys-13].color.red = 0;
              terarray[numbpolys-13].color.green = 0;
              terarray[numbpolys-13].color.blue = 8;


			 }

			if(multangle>=50 && multangle<=100)
			 {
              xtemp1 = xtemp + 12;
              xtemp2 = xtemp + 38;
			  xtemp += 50;
              terarray[numbpolys-20].color.red = 0;
              terarray[numbpolys-20].color.green = 16;
              terarray[numbpolys-20].color.blue = 0;
              terarray[numbpolys-19].color.red = 0;
              terarray[numbpolys-19].color.green = 16;
              terarray[numbpolys-19].color.blue = 0;
              terarray[numbpolys-18].color.red = 0;
              terarray[numbpolys-18].color.green = 16;
              terarray[numbpolys-18].color.blue = 0;
              terarray[numbpolys-17].color.red = 0;
              terarray[numbpolys-17].color.green = 16;
              terarray[numbpolys-17].color.blue = 0;
              terarray[numbpolys-16].color.red = 0;
              terarray[numbpolys-16].color.green = 16;
              terarray[numbpolys-16].color.blue = 0;
              terarray[numbpolys-15].color.red = 0;
              terarray[numbpolys-15].color.green = 16;
              terarray[numbpolys-15].color.blue = 0;
              terarray[numbpolys-14].color.red = 0;
              terarray[numbpolys-14].color.green = 16;
              terarray[numbpolys-14].color.blue = 0;
              terarray[numbpolys-13].color.red = 0;
              terarray[numbpolys-13].color.green = 16;
              terarray[numbpolys-13].color.blue = 0;



			 }
			if(multangle>100)
			 {
              xtemp1 = xtemp + 8;
              xtemp2 = xtemp +24;
			  xtemp += 32;
              terarray[numbpolys-20].color.red = 8;
              terarray[numbpolys-20].color.green = 0;
              terarray[numbpolys-20].color.blue = 0;
              terarray[numbpolys-19].color.red = 8;
              terarray[numbpolys-19].color.green = 0;
              terarray[numbpolys-19].color.blue = 0;
              terarray[numbpolys-18].color.red = 8;
              terarray[numbpolys-18].color.green = 0;
              terarray[numbpolys-18].color.blue = 0;
              terarray[numbpolys-17].color.red = 8;
              terarray[numbpolys-17].color.green = 0;
              terarray[numbpolys-17].color.blue = 0;
              terarray[numbpolys-16].color.red = 8;
              terarray[numbpolys-16].color.green = 0;
              terarray[numbpolys-16].color.blue = 0;
              terarray[numbpolys-15].color.red = 8;
              terarray[numbpolys-15].color.green = 0;
              terarray[numbpolys-15].color.blue = 0;
              terarray[numbpolys-14].color.red = 8;
              terarray[numbpolys-14].color.green = 0;
              terarray[numbpolys-14].color.blue = 0;
              terarray[numbpolys-13].color.red = 8;
              terarray[numbpolys-13].color.green = 0;
              terarray[numbpolys-13].color.blue = 0;


			 }
              terarray[numbpolys-20].v1.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-20].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-20].v1.lz=10;
              terarray[numbpolys-20].v3.lx=xtemp1;
              terarray[numbpolys-20].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-20].v3.lz=10;
              terarray[numbpolys-20].v2.lx=xtemp1;
              terarray[numbpolys-20].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-20].v2.lz=9;
              terarray[numbpolys-19].v1.lx=xtemp1;
              terarray[numbpolys-19].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-19].v1.lz=10;
              terarray[numbpolys-19].v3.lx=xtemp2;
              terarray[numbpolys-19].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-19].v3.lz=10;
              terarray[numbpolys-19].v2.lx=xtemp1;
              terarray[numbpolys-19].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-19].v2.lz=9;
              terarray[numbpolys-18].v1.lx=xtemp2;
              terarray[numbpolys-18].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-18].v1.lz=10;
              terarray[numbpolys-18].v3.lx=xtemp2;
              terarray[numbpolys-18].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-18].v3.lz=9;
              terarray[numbpolys-18].v2.lx=xtemp1;
              terarray[numbpolys-18].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-18].v2.lz=9;
              terarray[numbpolys-17].v1.lx=xtemp2;
              terarray[numbpolys-17].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-17].v1.lz=10;
              terarray[numbpolys-17].v3.lx=xtemp;
              terarray[numbpolys-17].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-17].v3.lz=10;
              terarray[numbpolys-17].v2.lx=xtemp2;
              terarray[numbpolys-17].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-17].v2.lz=9;


              terarray[numbpolys-16].v1.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-16].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-16].v1.lz=10;
              terarray[numbpolys-16].v2.lx=xtemp1;
              terarray[numbpolys-16].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-16].v2.lz=10;
              terarray[numbpolys-16].v3.lx=xtemp1;
              terarray[numbpolys-16].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-16].v3.lz=11;
              terarray[numbpolys-15].v1.lx=xtemp1;
              terarray[numbpolys-15].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-15].v1.lz=10;
              terarray[numbpolys-15].v2.lx=xtemp2;
              terarray[numbpolys-15].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-15].v2.lz=10;
              terarray[numbpolys-15].v3.lx=xtemp1;
              terarray[numbpolys-15].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-15].v3.lz=11;
              terarray[numbpolys-14].v1.lx=xtemp2;
              terarray[numbpolys-14].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-14].v1.lz=10;
              terarray[numbpolys-14].v2.lx=xtemp2;
              terarray[numbpolys-14].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-14].v2.lz=11;
              terarray[numbpolys-14].v3.lx=xtemp1;
              terarray[numbpolys-14].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-14].v3.lz=11;
              terarray[numbpolys-13].v1.lx=xtemp2;
              terarray[numbpolys-13].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-13].v1.lz=10;
              terarray[numbpolys-13].v2.lx=xtemp;
              terarray[numbpolys-13].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-13].v2.lz=10;
              terarray[numbpolys-13].v3.lx=xtemp2;
              terarray[numbpolys-13].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-13].v3.lz=11;

              terarray[numbpolys-12].v1.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-12].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-12].v1.lz=10;
              terarray[numbpolys-12].v2.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-12].v2.ly=550;
              terarray[numbpolys-12].v2.lz=0.1;
              terarray[numbpolys-12].v3.lx=xtemp1;
              terarray[numbpolys-12].v3.ly=550;
              terarray[numbpolys-12].v3.lz=0.1;
              terarray[numbpolys-12].color.red = 1;
              terarray[numbpolys-12].color.green = 2;
              terarray[numbpolys-12].color.blue = 1;
              terarray[numbpolys-11].v1.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-11].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-11].v1.lz=10;
              terarray[numbpolys-11].v2.lx=xtemp1;
              terarray[numbpolys-11].v2.ly=550;
              terarray[numbpolys-11].v2.lz=0.1;
              terarray[numbpolys-11].v3.lx=xtemp1;
              terarray[numbpolys-11].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-11].v3.lz=9;
              terarray[numbpolys-11].color.red = 1;
              terarray[numbpolys-11].color.green = 2;
              terarray[numbpolys-11].color.blue = 1;
              terarray[numbpolys-10].v1.lx=xtemp1;
              terarray[numbpolys-10].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-10].v1.lz=9;
              terarray[numbpolys-10].v2.lx=xtemp1;
              terarray[numbpolys-10].v2.ly=550;
              terarray[numbpolys-10].v2.lz=0.1;
              terarray[numbpolys-10].v3.lx=xtemp2;
              terarray[numbpolys-10].v3.ly=550;
              terarray[numbpolys-10].v3.lz=0.1;
              terarray[numbpolys-10].color.red = 1;
              terarray[numbpolys-10].color.green = 2;
              terarray[numbpolys-10].color.blue = 1;
              terarray[numbpolys-9].v1.lx=xtemp1;
              terarray[numbpolys-9].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-9].v1.lz=9;
              terarray[numbpolys-9].v3.lx=xtemp2;
              terarray[numbpolys-9].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-9].v3.lz=9;
              terarray[numbpolys-9].v2.lx=xtemp2;
              terarray[numbpolys-9].v2.ly=550;
              terarray[numbpolys-9].v2.lz=0.1;
              terarray[numbpolys-9].color.red = 1;
              terarray[numbpolys-9].color.green = 2;
              terarray[numbpolys-9].color.blue = 1;

              terarray[numbpolys-8].v1.lx=xtemp2;
              terarray[numbpolys-8].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-8].v1.lz=9;
              terarray[numbpolys-8].v3.lx=xtemp;
              terarray[numbpolys-8].v3.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-8].v3.lz=10;
              terarray[numbpolys-8].v2.lx=xtemp2;
              terarray[numbpolys-8].v2.ly=550;
              terarray[numbpolys-8].v2.lz=0.1;
              terarray[numbpolys-8].color.red = 1;
              terarray[numbpolys-8].color.green = 2;
              terarray[numbpolys-8].color.blue = 1;

              terarray[numbpolys-7].v1.lx=xtemp;
              terarray[numbpolys-7].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-7].v1.lz=10;
              terarray[numbpolys-7].v3.lx=xtemp;
              terarray[numbpolys-7].v3.ly=550;
              terarray[numbpolys-7].v3.lz=0.1;
              terarray[numbpolys-7].v2.lx=xtemp2;
              terarray[numbpolys-7].v2.ly=550;
              terarray[numbpolys-7].v2.lz=0.1;
              terarray[numbpolys-7].color.red = 1;
              terarray[numbpolys-7].color.green = 2;
              terarray[numbpolys-7].color.blue = 1;


              terarray[numbpolys-6].v1.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-6].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-6].v1.lz=10;
              terarray[numbpolys-6].v3.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-6].v3.ly=550;
              terarray[numbpolys-6].v3.lz=20;
              terarray[numbpolys-6].v2.lx=xtemp1;
              terarray[numbpolys-6].v2.ly=550;
              terarray[numbpolys-6].v2.lz=20;
              terarray[numbpolys-6].color.red = 1;
              terarray[numbpolys-6].color.green = 2;
              terarray[numbpolys-6].color.blue = 1;

              terarray[numbpolys-5].v1.lx=terarray[numbpolys-21].v1.lx;
              terarray[numbpolys-5].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-5].v1.lz=10;
              terarray[numbpolys-5].v3.lx=xtemp1;
              terarray[numbpolys-5].v3.ly=550;
              terarray[numbpolys-5].v3.lz=20;
              terarray[numbpolys-5].v2.lx=xtemp1;
              terarray[numbpolys-5].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-5].v2.lz=11;
              terarray[numbpolys-5].color.red = 1;
              terarray[numbpolys-5].color.green = 2;
              terarray[numbpolys-5].color.blue = 1;

              terarray[numbpolys-4].v1.lx=xtemp1;
              terarray[numbpolys-4].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-4].v1.lz=11;
              terarray[numbpolys-4].v3.lx=xtemp1;
              terarray[numbpolys-4].v3.ly=550;
              terarray[numbpolys-4].v3.lz=20;
              terarray[numbpolys-4].v2.lx=xtemp2;
              terarray[numbpolys-4].v2.ly=550;
              terarray[numbpolys-4].v2.lz=20;
              terarray[numbpolys-4].color.red = 1;
              terarray[numbpolys-4].color.green = 2;
              terarray[numbpolys-4].color.blue = 1;

              terarray[numbpolys-3].v1.lx=xtemp1;
              terarray[numbpolys-3].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-3].v1.lz=11;
              terarray[numbpolys-3].v2.lx=xtemp2;
              terarray[numbpolys-3].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-3].v2.lz=11;
              terarray[numbpolys-3].v3.lx=xtemp2;
              terarray[numbpolys-3].v3.ly=550;
              terarray[numbpolys-3].v3.lz=20;
              terarray[numbpolys-3].color.red = 1;
              terarray[numbpolys-3].color.green = 2;
              terarray[numbpolys-3].color.blue = 1;

              terarray[numbpolys-2].v1.lx=xtemp2;
              terarray[numbpolys-2].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-2].v1.lz=11;
              terarray[numbpolys-2].v2.lx=xtemp;
              terarray[numbpolys-2].v2.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-2].v2.lz=10;
              terarray[numbpolys-2].v3.lx=xtemp2;
              terarray[numbpolys-2].v3.ly=550;
              terarray[numbpolys-2].v3.lz=20;
              terarray[numbpolys-2].color.red = 1;
              terarray[numbpolys-2].color.green = 2;
              terarray[numbpolys-2].color.blue = 1;

              terarray[numbpolys-1].v1.lx=xtemp;
              terarray[numbpolys-1].v1.ly=terarray[numbpolys-21].v1.ly;
              terarray[numbpolys-1].v1.lz=10;
              terarray[numbpolys-1].v2.lx=xtemp;
              terarray[numbpolys-1].v2.ly=550;
              terarray[numbpolys-1].v2.lz=20;
              terarray[numbpolys-1].v3.lx=xtemp2;
              terarray[numbpolys-1].v3.ly=550;
              terarray[numbpolys-1].v3.lz=20;
              terarray[numbpolys-1].color.red = 1;
              terarray[numbpolys-1].color.green = 2;
              terarray[numbpolys-1].color.blue = 1;



			prevangle = currentangle;
			currentangle = nextangle;
            if(currentangle < 0)
             {
              nextangle = -1*random(diff)+1;
              if(random(4) == 0) nextangle *= -1;
             }
             else
              {
               nextangle = random(diff)+1;
               if(random(4) == 0) nextangle *= -1;
              }



/*			nextangle = random(diff)+1;
			if(random(2) == 0) nextangle *= -1;
  */		  }
		  else
			{
             numbpolys += 4;
			 distance = random(120-diff)+1;
			 ytemp += distance*sin(currentangle*0.017453);
			 xtemp += distance*cos(currentangle*0.017453);
			 if(ytemp < 250 || ytemp >500)
			  {
				while(ytemp < 250 || ytemp > 500)
				 {
					ytemp -= distance*sin(currentangle*0.017453);
					xtemp -= distance*cos(currentangle*0.017453);
					currentangle = random(diff) + 1;
					ytemp += distance*sin(currentangle*0.017453);
					xtemp += distance*cos(currentangle*0.017453);
				 }
			  }
			 if(xtemp > 1239)
				xtemp = 1239;

      terarray[numbpolys-4].v1.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-4].v1.ly=terarray[numbpolys-5].v1.ly;
      terarray[numbpolys-4].v1.lz=10;
      terarray[numbpolys-4].v3.lx=xtemp;
      terarray[numbpolys-4].v3.ly=ytemp;
      terarray[numbpolys-4].v3.lz=10;
      terarray[numbpolys-4].v2.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-4].v2.ly=550;
      terarray[numbpolys-4].v2.lz=0.1;
      terarray[numbpolys-4].color.red = 1;
      terarray[numbpolys-4].color.green = 2;
      terarray[numbpolys-4].color.blue = 1;

      terarray[numbpolys-3].v1.lx=xtemp;
      terarray[numbpolys-3].v1.ly=ytemp;
      terarray[numbpolys-3].v1.lz=10;
      terarray[numbpolys-3].v3.lx=xtemp;
      terarray[numbpolys-3].v3.ly=550;
      terarray[numbpolys-3].v3.lz=0.1;
      terarray[numbpolys-3].v2.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-3].v2.ly=550;
      terarray[numbpolys-3].v2.lz=0.1;
      terarray[numbpolys-3].color.red = 1;
      terarray[numbpolys-3].color.green = 2;
      terarray[numbpolys-3].color.blue = 1;

      terarray[numbpolys-2].v1.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-2].v1.ly=terarray[numbpolys-5].v1.ly;
      terarray[numbpolys-2].v1.lz=10;
      terarray[numbpolys-2].v2.lx=xtemp;
      terarray[numbpolys-2].v2.ly=ytemp;
      terarray[numbpolys-2].v2.lz=10;
      terarray[numbpolys-2].v3.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-2].v3.ly=550;
      terarray[numbpolys-2].v3.lz=20;
      terarray[numbpolys-2].color.red = 1;
      terarray[numbpolys-2].color.green = 2;
      terarray[numbpolys-2].color.blue = 1;

      terarray[numbpolys-1].v1.lx=xtemp;
      terarray[numbpolys-1].v1.ly=ytemp;
      terarray[numbpolys-1].v1.lz=10;
      terarray[numbpolys-1].v2.lx=xtemp;
      terarray[numbpolys-1].v2.ly=550;
      terarray[numbpolys-1].v2.lz=20;
      terarray[numbpolys-1].v3.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-1].v3.ly=550;
      terarray[numbpolys-1].v3.lz=20;
      terarray[numbpolys-1].color.red = 1;
      terarray[numbpolys-1].color.green = 2;
      terarray[numbpolys-1].color.blue = 1;



			 prevangle = currentangle;
			 currentangle = nextangle;
			 if(((currentangle!=0) && (random(6+(diff/9)) == 0) && (xtemp < (1000 + diff))) || ((xtemp > 400) && (landpad == false) && (currentangle!=0)))
				nextangle = 0;
				else
				 {
				  if(currentangle < 0)
                   {
                    nextangle = -1*random(diff)+1;
				    if(random(4) == 0) nextangle *= -1;
                   }
                   else
                    {
                     nextangle = random(diff)+1;
				     if(random(4) == 0) nextangle *= -1;
                    }

				 }
			}
		}
       numbpolys += 4;

      terarray[numbpolys-4].v1.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-4].v1.ly=terarray[numbpolys-5].v1.ly;
      terarray[numbpolys-4].v1.lz=10;
      terarray[numbpolys-4].v3.lx=1279;
      terarray[numbpolys-4].v3.ly=0;
      terarray[numbpolys-4].v3.lz=10;
      terarray[numbpolys-4].v2.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-4].v2.ly=550;
      terarray[numbpolys-4].v2.lz=0.1;
      terarray[numbpolys-4].color.red = 1;
      terarray[numbpolys-4].color.green = 2;
      terarray[numbpolys-4].color.blue = 1;

      terarray[numbpolys-3].v1.lx=1279;
      terarray[numbpolys-3].v1.ly=0;
      terarray[numbpolys-3].v1.lz=10;
      terarray[numbpolys-3].v3.lx=1279;
      terarray[numbpolys-3].v3.ly=550;
      terarray[numbpolys-3].v3.lz=0.1;
      terarray[numbpolys-3].v2.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-3].v2.ly=550;
      terarray[numbpolys-3].v2.lz=0.1;
      terarray[numbpolys-3].color.red = 1;
      terarray[numbpolys-3].color.green = 2;
      terarray[numbpolys-3].color.blue = 1;

      terarray[numbpolys-2].v1.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-2].v1.ly=terarray[numbpolys-5].v1.ly;
      terarray[numbpolys-2].v1.lz=10;
      terarray[numbpolys-2].v2.lx=1279;
      terarray[numbpolys-2].v2.ly=0;
      terarray[numbpolys-2].v2.lz=10;
      terarray[numbpolys-2].v3.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-2].v3.ly=550;
      terarray[numbpolys-2].v3.lz=20;
      terarray[numbpolys-2].color.red = 1;
      terarray[numbpolys-2].color.green = 2;
      terarray[numbpolys-2].color.blue = 1;

      terarray[numbpolys-1].v1.lx=1279;
      terarray[numbpolys-1].v1.ly=0;
      terarray[numbpolys-1].v1.lz=10;
      terarray[numbpolys-1].v2.lx=1279;
      terarray[numbpolys-1].v2.ly=550;
      terarray[numbpolys-1].v2.lz=20;
      terarray[numbpolys-1].v3.lx=terarray[numbpolys-5].v1.lx;
      terarray[numbpolys-1].v3.ly=550;
      terarray[numbpolys-1].v3.lz=20;
      terarray[numbpolys-1].color.red = 1;
      terarray[numbpolys-1].color.green = 2;
      terarray[numbpolys-1].color.blue = 1;


  calcpolynorms();
  calcvernorms();
  calcpolylight();
  calcverlight();
 }

void terrainclass::setaltitudearray(void)
 {
  int xunit,xpoint,ypoint;
  int count;
  float slope,temp;
  count = 0;
  xunit = 0;
  while(count < numbpolys)
   {
    if(terarray[count].color.red == 0 || terarray[count].color.blue == 0)
     {
      xunit = terarray[count].v1.lx;
      xpoint = xunit;
      ypoint = terarray[count].v1.ly;
      temp = float(terarray[count].v3.lx - terarray[count].v1.lx);
      if(temp == 0) temp =1;
      slope = (terarray[count].v3.ly - terarray[count].v1.ly)/temp;
      while(xunit <= terarray[count].v3.lx)
       {
        altarray[xunit].y = slope*(xunit-xpoint) + ypoint;
        altarray[xunit].color = terarray[count].color;
        xunit++;

       }
       xunit = terarray[count+1].v1.lx;
       xpoint = xunit;
       ypoint = terarray[count+1].v1.ly;
       temp = float(terarray[count+1].v3.lx - terarray[count+1].v1.lx);
       if(temp == 0) temp = 1;
       slope = (terarray[count+1].v3.ly - terarray[count+1].v1.ly)/temp;
       while(xunit <= terarray[count+1].v3.lx)
        {
         altarray[xunit].y = slope*(xunit-xpoint) + ypoint;
         altarray[xunit].color = terarray[count+1].color;
         xunit++;

        }
       xunit = terarray[count+3].v1.lx;
       xpoint = xunit;
       ypoint = terarray[count+3].v1.ly;
       temp = float(terarray[count+3].v3.lx - terarray[count+3].v1.lx);
       if( temp == 0) temp = 1;
       slope = (terarray[count+3].v3.ly - terarray[count+3].v1.ly)/temp;
       while(xunit <= terarray[count+3].v3.lx)
        {
         altarray[xunit].y = slope*(xunit-xpoint) + ypoint;
         altarray[xunit].color = terarray[count+3].color;
         xunit++;

        }


      count += 20;
     }
     else
      {
       xunit = terarray[count].v1.lx;
       xpoint = xunit;
       ypoint = terarray[count].v1.ly;
       temp = float(terarray[count].v3.lx - terarray[count].v1.lx);
       if(temp == 0) temp =1;
       slope = (terarray[count].v3.ly - terarray[count].v1.ly)/temp;
       while(xunit <= terarray[count].v3.lx)
        {
         altarray[xunit].y = slope*(xunit-xpoint) + ypoint;
         altarray[xunit].color = terarray[count].color;
         xunit++;

        }

       count += 4;
      }
   }



 }

int terrainclass::getaltitude(int x1,int y1,int sc)
 {
  int alt;
  if(x1 < 0) x1 = 0;
  if(x1 >= 1280) x1 = 1279;
  alt = altarray[x1].y;
  if(sc == 1)
   alt -= y1+8;
  if(sc == 4)
   alt -= y1+8;

  alt *= 10;
  return (alt-42);

 }

int terrainclass::retcolor(int x1)
 {
  colortype col;
  col = altarray[x1].color;
  int c;
  if(col.red != 0 && col.blue !=0)
   c = 0;
  if(col.blue == 0)
   c = 1;
  if(col.green == 0)
   c = 2;
  if(col.red == 0)
   c = 3;

  return c;

 }

void terrainclass::resetinten()
 {
  for(a=0;a<numbpolys;a++)
   {
    terarray[a].v1.inten1 = terarray[a].v1.inten;
    terarray[a].v2.inten1 = terarray[a].v2.inten;
    terarray[a].v3.inten1 = terarray[a].v3.inten;

   }
 }


void terrainclass::transform(int xpos,int ypos,float sc)
  {
   if(sc == 1) xpos /= 2;
   int temp;
   for(a=0;a<numbpolys;a++)
    {
     if(sc == 1)
      {
       temp = xpos + 320;
       terarray[a].v1.vx = terarray[a].v1.lx - temp;
       terarray[a].v2.vx = terarray[a].v2.lx - temp;
       terarray[a].v3.vx = terarray[a].v3.lx - temp;
       terarray[a].fmidx = terarray[a].midx - temp;
       terarray[a].v1.vy = terarray[a].v1.ly-240;
       terarray[a].v2.vy = terarray[a].v2.ly-240;
       terarray[a].v3.vy = terarray[a].v3.ly-240;
       terarray[a].fmidy = terarray[a].midy-240;
       terarray[a].v1.vz = terarray[a].v1.lz;
       terarray[a].v2.vz = terarray[a].v2.lz;
       terarray[a].v3.vz = terarray[a].v3.lz;
       terarray[a].fmidz = terarray[a].midz;

      }
     if(sc == 4)
      {
       terarray[a].v1.vx = ((terarray[a].v1.lx - xpos))*4;
       terarray[a].v2.vx = ((terarray[a].v2.lx - xpos))*4;
       terarray[a].v3.vx = ((terarray[a].v3.lx - xpos))*4;
       terarray[a].fmidx = (terarray[a].midx - xpos)*4;
       terarray[a].v1.vy = ((terarray[a].v1.ly) - ypos)*4;
       terarray[a].v2.vy = ((terarray[a].v2.ly) - ypos)*4;
       terarray[a].v3.vy = ((terarray[a].v3.ly) - ypos)*4;
       terarray[a].fmidy = (terarray[a].midy - ypos)*4;
       terarray[a].v1.vz = ((terarray[a].v1.lz));
       terarray[a].v2.vz = ((terarray[a].v2.lz));
       terarray[a].v3.vz = ((terarray[a].v3.lz));
       terarray[a].fmidz = terarray[a].midz;


      }

    }
  }

void terrainclass::project(void)
 {
  float temp;
  for(a=0;a<numbpolys;a++)
   {
    if((terarray[a].culled==false))
    {
     if(terarray[a].v1.vz >= -49)
      {
       temp = 50/(int)(terarray[a].v1.vz+50);
       terarray[a].v1.sx = ((terarray[a].v1.vx)*temp)+320;
       terarray[a].v1.sy = ((terarray[a].v1.vy)*temp)+240;
      }
     else if(terarray[a].v1.vz > -51)
      {
       terarray[a].v1.sx = (50.0*(terarray[a].v1.vx))+320;
       terarray[a].v1.sy = (50.0*(terarray[a].v1.vy))+240;
      }
     else
      {
       temp = (50.0*abs(terarray[a].v1.vz+50));
       terarray[a].v1.sx = (terarray[a].v1.vx*temp)+320;
       terarray[a].v1.sy = (terarray[a].v1.vy*temp)+240;

      }
     if(terarray[a].v2.vz >= -49)
      {
       temp = 50.0/(terarray[a].v2.vz+50);
       terarray[a].v2.sx = ((terarray[a].v2.vx)*temp)+320;
       terarray[a].v2.sy = ((terarray[a].v2.vy)*temp)+240;
      }
     else if(terarray[a].v2.vz > -51)
      {
       terarray[a].v2.sx = (50.0*(terarray[a].v2.vx))+320;
       terarray[a].v2.sy = (50.0*(terarray[a].v2.vy))+240;
      }
     else
      {
       temp = (50.0*abs(terarray[a].v2.vz+50));
       terarray[a].v2.sx = (terarray[a].v2.vx*temp)+320;
       terarray[a].v2.sy = (terarray[a].v2.vy*temp)+240;

      }
     if(terarray[a].v3.vz >= -49)
      {
       temp = 50.0/(terarray[a].v3.vz+50);
       terarray[a].v3.sx = ((terarray[a].v3.vx)*temp)+320;
       terarray[a].v3.sy = ((terarray[a].v3.vy)*temp)+240;
      }
     else if(terarray[a].v3.vz > -51)
      {
       terarray[a].v3.sx = (50.0*(terarray[a].v3.vx))+320;
       terarray[a].v3.sy = (50.0*(terarray[a].v3.vy))+240;
      }
     else
      {
       temp = (50.0*abs(terarray[a].v3.vz+50));
       terarray[a].v3.sx = (terarray[a].v3.vx*temp)+320;
       terarray[a].v3.sy = (terarray[a].v3.vy*temp)+240;

      }


  /*    terarray[a].v2.sx = 50.0*((terarray[a].v2.vx)/(terarray[a].v2.vz*0.1+50))+320.0;
      terarray[a].v2.sy = 50.0*((terarray[a].v2.vy)/(terarray[a].v2.vz*0.1+50))+240.0;
      terarray[a].v3.sx = 50.0*((terarray[a].v3.vx)/(terarray[a].v3.vz*0.1+50))+320.0;
      terarray[a].v3.sy = 50.0*((terarray[a].v3.vy)/(terarray[a].v3.vz*0.1+50))+240.0;
   */  }
   }
 }

void terrainclass::cull(void)
 {
  float tempx,tempy,tempz,dotp;
  int a;
  for(a=0;a<numbpolys;a++)
   {
    /*calc viewvector*/
     tempx = 0-terarray[a].fmidx;
      tempy = 0-terarray[a].fmidy;
      tempz = -50 - terarray[a].fmidz;
    /*calculate z buffer distance*/
      terarray[a].dist = sqrt(tempx*tempx + tempy*tempy + tempz*tempz);

   /*   magnitude = sqrt(tempx*tempx + tempy*tempy + tempz*tempz);
      tempx /= magnitude;
      tempy /= magnitude;
      tempz /= magnitude;
  */  /*calc dot product between veiw vector and
      poly normal*/
    dotp = (terarray[a].dxv*tempx)+(terarray[a].dyv*tempy)+(terarray[a].dzv*tempz);
    if(dotp < -0.0)
    terarray[a].culled = true;
    else terarray[a].culled = false;
   }



/*  float temp1,temp2,temp3,dotp;
  for(a=0;a<numbpolys;a++)
   {
    temp1 = (terarray[a].v1.vz*terarray[a].v2.vy)-(terarray[a].v1.vy*terarray[a].v2.vz);
    temp2 = (terarray[a].v1.vx*terarray[a].v2.vz)-(terarray[a].v1.vz*terarray[a].v2.vx);
    temp3 = (terarray[a].v1.vy*terarray[a].v2.vx)-(terarray[a].v1.vx*terarray[a].v2.vy);

    dotp = (terarray[a].v3.vx*temp1)+(terarray[a].v3.vy*temp2)+(terarray[a].v3.vz*temp3);
    if(dotp < 0)
    terarray[a].culled = true;
    else terarray[a].culled = false;
   }
*/ }


void terrainclass::drawterrain(unsigned short* surf,char guryn,int bits,LPDIRECTDRAWSURFACE lpddsback,short zbuffer[640][480],int pitch)
 {
  vertexstruct temp1,temp2,temp3;
  /* temp1 = top vertex:  temp2 = counterclockwise vertex: temp3 = clockwize vertex */
  /*DDSURFACEDESC ddsd;
  ddsd.dwSize = sizeof(ddsd);


  if (lpddsback->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL) == DD_OK)
   {
  unsigned short* surf;

  surf = (unsigned short*)ddsd.lpSurface;
 */

  for(a=0;a<numbpolys;a++)
   {
    if(!(terarray[a].culled))
     {
      if((terarray[a].v1.sy <= terarray[a].v2.sy) && (terarray[a].v1.sy <= terarray[a].v3.sy))
       {
        temp1 = terarray[a].v1;
        temp2 = terarray[a].v2;
        temp3 = terarray[a].v3;
/*        tempy1 = terarray[a].v1.sy;
        tempy2 = terarray[a].v2.sy;
        tempy3 = terarray[a].v3.sy;
  */
       }
      if((terarray[a].v2.sy < terarray[a].v1.sy) && (terarray[a].v2.sy <= terarray[a].v3.sy))
       {
        temp1 = terarray[a].v2;
        temp2 = terarray[a].v3;
        temp3 = terarray[a].v1;
      /*  tempy1 = terarray[a].v2.sy;
        tempy2 = terarray[a].v3.sy;
        tempy3 = terarray[a].v1.sy;
       */
       }
      if((terarray[a].v3.sy < terarray[a].v2.sy) && (terarray[a].v3.sy < terarray[a].v1.sy))
       {
        temp1 = terarray[a].v3;
        temp2 = terarray[a].v1;
        temp3 = terarray[a].v2;
       /* tempy1 = terarray[a].v3.sy;
        tempy2 = terarray[a].v1.sy;
        tempy3 = terarray[a].v2.sy;
       */
       }
       if(guryn == 1) polydraw(surf,/*ddsd,*/temp1.sx,temp2.sx,temp3.sx,temp1.sy,temp2.sy,temp3.sy,terarray[a].dist,terarray[a].color1,bits,zbuffer,lpddsback,pitch);
        else gpolydraw(surf,/*ddsd,*/temp1.sx,temp2.sx,temp3.sx,temp1.sy,temp2.sy,temp3.sy,terarray[a].dist,terarray[a].color,temp1.inten1,temp2.inten1,temp3.inten1,false,bits,zbuffer,pitch);

     }

   }
/* } lpddsback->Unlock(NULL);
 */
 }

void terrainclass::calcpolynorms(void)
 {
  int a;
  double magnitude,v1,v2,v3,w1,w2,w3;
  for(a=0;a<numbpolys;a++)
  {
   /*calculate polygon normals*/
   v1 = terarray[a].v2.lx - terarray[a].v1.lx;
   v2 = terarray[a].v2.ly - terarray[a].v1.ly;
   v3 = terarray[a].v2.lz - terarray[a].v1.lz;
   w1 = terarray[a].v3.lx - terarray[a].v1.lx;
   w2 = terarray[a].v3.ly - terarray[a].v1.ly;
   w3 = terarray[a].v3.lz - terarray[a].v1.lz;
   terarray[a].nxv = v2*w3 - v3*w2;
   terarray[a].nyv = v3*w1 - v1*w3;
   terarray[a].nzv = v1*w2 - v2*w1;
   /*calculate direction vectors*/


   magnitude = sqrt((terarray[a].nxv*terarray[a].nxv) + (terarray[a].nyv*terarray[a].nyv) + (terarray[a].nzv*terarray[a].nzv));



   if(magnitude != 0.0)
    {
     terarray[a].dxv = terarray[a].nxv/magnitude;
     terarray[a].dyv = terarray[a].nyv/magnitude;
     terarray[a].dzv = terarray[a].nzv/magnitude;
    }
   /*calculate midpoints*/
   terarray[a].midx = (terarray[a].v1.lx + terarray[a].v2.lx + terarray[a].v3.lx)/3.0;
   terarray[a].midy = (terarray[a].v1.ly + terarray[a].v2.ly + terarray[a].v3.ly)/3.0;
   terarray[a].midz = (terarray[a].v1.lz + terarray[a].v2.lz + terarray[a].v3.lz)/3.0;

  }
 }

void terrainclass::calcvernorms(void)
 {
  int a;
 /* double magnitude,v1,v2,v3,w1,w2,w3;
 */ terarray[0].v1.dvx = (terarray[0].dxv + terarray[2].dxv)/2.0;
  terarray[0].v1.dvy = (terarray[0].dyv + terarray[2].dyv)/2.0;
  terarray[0].v1.dvz = (terarray[0].dzv + terarray[2].dzv)/2.0;
  terarray[0].v2.dvx = (terarray[0].dxv + terarray[1].dxv)/2.0;
  terarray[0].v2.dvy = (terarray[0].dyv + terarray[1].dyv)/2.0;
  terarray[0].v2.dvz = (terarray[0].dzv + terarray[1].dzv)/2.0;
 /* terarray[0].v3.dvx = terarray[0].dxv + terarray[2].dxv + terarray[1].dxv + terarray[3].dxv;
  terarray[0].v3.dvy = terarray[0].dyv + terarray[2].dyv + terarray[1].dyv + terarray[3].dyv;
  terarray[0].v3.dvz = terarray[0].dzv + terarray[2].dzv + terarray[1].dzv + terarray[3].dzv;
 *//* terarray[1].v1.dvx = terarray[0].dxv + terarray[2].dxv + terarray[1].dxv + terarray[3].dxv;
  terarray[1].v1.dvy = terarray[0].dyv + terarray[2].dyv + terarray[1].dyv + terarray[3].dyv;
  terarray[1].v1.dvz = terarray[0].dzv + terarray[2].dzv + terarray[1].dzv + terarray[3].dzv;
  */terarray[1].v2.dvx = (terarray[0].dxv + terarray[1].dxv)/2.0;
  terarray[1].v2.dvy = (terarray[0].dyv + terarray[1].dyv)/2.0;
  terarray[1].v2.dvz = (terarray[0].dzv + terarray[1].dzv)/2.0;
 /* terarray[1].v3.dvx = terarray[0].dxv + terarray[2].dxv + terarray[1].dxv + terarray[3].dxv;
  terarray[1].v3.dvy = terarray[0].dyv + terarray[2].dyv + terarray[1].dyv + terarray[3].dyv;
  terarray[1].v3.dvz = terarray[0].dzv + terarray[2].dzv + terarray[1].dzv + terarray[3].dzv;
 */
  terarray[2].v1.dvx = (terarray[0].dxv + terarray[2].dxv)/2.0;
  terarray[2].v1.dvy = (terarray[0].dyv + terarray[2].dyv)/2.0;
  terarray[2].v1.dvz = (terarray[0].dzv + terarray[2].dzv)/2.0;
  terarray[2].v3.dvx = (terarray[2].dxv + terarray[3].dxv)/2.0;
  terarray[2].v3.dvy = (terarray[2].dyv + terarray[3].dyv)/2.0;
  terarray[2].v3.dvz = (terarray[2].dzv + terarray[3].dzv)/2.0;
  terarray[3].v3.dvx = (terarray[2].dxv + terarray[3].dxv)/2.0;
  terarray[3].v3.dvy = (terarray[2].dyv + terarray[3].dyv)/2.0;
  terarray[3].v3.dvz = (terarray[2].dzv + terarray[3].dzv)/2.0;
  a = 4;
  bool lpyn;
  float tempx[13];
  float tempy[13];
  float tempz[13];
  while(a<numbpolys-4)
  {
   if((terarray[a].color.red == 0) || (terarray[a].color.green == 0))

     lpyn = true;

    else lpyn = false;
   if(lpyn)
    {
     tempx[0] = terarray[a-4].dxv + terarray[a-3].dxv + terarray[a-2].dxv + terarray[a-1].dxv
                + terarray[a].dxv + terarray[a+4].dxv + terarray[a+8].dxv + terarray[a+9].dxv
                + terarray[a+14].dxv + terarray[a+15].dxv;
     tempy[0] = terarray[a-4].dyv + terarray[a-3].dyv + terarray[a-2].dyv + terarray[a-1].dyv
                + terarray[a].dyv + terarray[a+4].dyv + terarray[a+8].dyv + terarray[a+9].dyv
                + terarray[a+14].dyv + terarray[a+15].dyv;
     tempz[0] = terarray[a-4].dzv + terarray[a-3].dzv + terarray[a-2].dzv + terarray[a-1].dzv
                + terarray[a].dzv + terarray[a+4].dzv + terarray[a+8].dzv + terarray[a+9].dzv
                + terarray[a+14].dzv + terarray[a+15].dzv;
     tempx[1] = terarray[a-3].dxv + terarray[a+8].dxv;
     tempy[1] = terarray[a-3].dyv + terarray[a+8].dyv;
     tempz[1] = terarray[a-3].dzv + terarray[a+8].dzv;
     tempx[2] = terarray[a-1].dxv + terarray[a+14].dxv;
     tempy[2] = terarray[a-1].dyv + terarray[a+14].dyv;
     tempz[2] = terarray[a-1].dzv + terarray[a+14].dzv;
     tempx[3] = terarray[a+14].dxv + terarray[a+15].dxv + terarray[a+16].dxv;
     tempy[3] = terarray[a+14].dyv + terarray[a+15].dyv + terarray[a+16].dyv;
     tempz[3] = terarray[a+14].dzv + terarray[a+15].dzv + terarray[a+16].dzv;
     tempx[4] = terarray[a+4].dxv + terarray[a+5].dxv + terarray[a+6].dxv + terarray[a+15].dxv
                + terarray[a+16].dxv + terarray[a+17].dxv;
     tempy[4] = terarray[a+4].dyv + terarray[a+5].dyv + terarray[a+6].dyv + terarray[a+15].dyv
                + terarray[a+16].dyv + terarray[a+17].dyv;
     tempz[4] = terarray[a+4].dzv + terarray[a+5].dzv + terarray[a+6].dzv + terarray[a+15].dzv
                + terarray[a+16].dzv + terarray[a+17].dzv;
     tempx[5] = terarray[a].dxv + terarray[a+1].dxv + terarray[a+4].dxv + terarray[a+5].dxv;
     tempy[5] = terarray[a].dyv + terarray[a+1].dyv + terarray[a+4].dyv + terarray[a+5].dyv;
     tempz[5] = terarray[a].dzv + terarray[a+1].dzv + terarray[a+4].dzv + terarray[a+5].dzv;
     tempx[6] = terarray[a].dxv + terarray[a+1].dxv + terarray[a+2].dxv + terarray[a+9].dxv
                + terarray[a+10].dxv + terarray[a+11].dxv;
     tempy[6] = terarray[a].dyv + terarray[a+1].dyv + terarray[a+2].dyv + terarray[a+9].dyv
                + terarray[a+10].dyv + terarray[a+11].dyv;
     tempz[6] = terarray[a].dzv + terarray[a+1].dzv + terarray[a+2].dzv + terarray[a+9].dzv
                + terarray[a+10].dzv + terarray[a+11].dzv;
     tempx[7] = terarray[a+8].dxv + terarray[a+9].dxv + terarray[a+10].dxv;
     tempy[7] = terarray[a+8].dyv + terarray[a+9].dyv + terarray[a+10].dyv;
     tempz[7] = terarray[a+8].dzv + terarray[a+9].dzv + terarray[a+10].dzv;
     tempx[8] = terarray[a+16].dxv + terarray[a+17].dxv + terarray[a+18].dxv + terarray[a+19].dxv;
     tempy[8] = terarray[a+16].dyv + terarray[a+17].dyv + terarray[a+18].dyv + terarray[a+19].dyv;
     tempz[8] = terarray[a+16].dzv + terarray[a+17].dzv + terarray[a+18].dzv + terarray[a+19].dzv;
     tempx[9] = terarray[a+6].dxv + terarray[a+7].dxv + terarray[a+17].dxv + terarray[a+18].dxv;
     tempy[9] = terarray[a+6].dyv + terarray[a+7].dyv + terarray[a+17].dyv + terarray[a+18].dyv;
     tempz[9] = terarray[a+6].dzv + terarray[a+7].dzv + terarray[a+17].dzv + terarray[a+18].dzv;
     tempx[10] = terarray[a+1].dxv + terarray[a+2].dxv + terarray[a+3].dxv + terarray[a+5].dxv
                + terarray[a+6].dxv + terarray[a+7].dxv;
     tempy[10] = terarray[a+1].dyv + terarray[a+2].dyv + terarray[a+3].dyv + terarray[a+5].dyv
                + terarray[a+6].dyv + terarray[a+7].dyv;
     tempz[10] = terarray[a+1].dzv + terarray[a+2].dzv + terarray[a+3].dzv + terarray[a+5].dzv
                + terarray[a+6].dzv + terarray[a+7].dzv;
     tempx[11] = terarray[a+2].dxv + terarray[a+3].dxv + terarray[a+11].dxv + terarray[a+12].dxv;
     tempy[11] = terarray[a+2].dyv + terarray[a+3].dyv + terarray[a+11].dyv + terarray[a+12].dyv;
     tempz[11] = terarray[a+2].dzv + terarray[a+3].dzv + terarray[a+11].dzv + terarray[a+12].dzv;
     tempx[12] = terarray[a+10].dxv + terarray[a+11].dxv + terarray[a+12].dxv + terarray[a+13].dxv;
     tempy[12] = terarray[a+10].dyv + terarray[a+11].dyv + terarray[a+12].dyv + terarray[a+13].dyv;
     tempz[12] = terarray[a+10].dzv + terarray[a+11].dzv + terarray[a+12].dzv + terarray[a+13].dzv;

     tempx[0] /= 10.0;
     tempy[0] /= 10.0;
     tempz[0] /= 10.0;
     tempx[1] /= 2.0;
     tempy[1] /= 2.0;
     tempz[1] /= 2.0;
     tempx[2] /= 2.0;
     tempy[2] /= 2.0;
     tempz[2] /= 2.0;
     tempx[3] /= 3.0;
     tempy[3] /= 3.0;
     tempz[3] /= 3.0;
     tempx[4] /= 6.0;
     tempy[4] /= 6.0;
     tempz[4] /= 6.0;
     tempx[5] /= 10;
     tempy[5] /= 10;
     tempz[5] /= 10;
     tempx[6] /= 6.0;
     tempy[6] /= 6.0;
     tempz[6] /= 6.0;
     tempx[7] /= 3.0;
     tempy[7] /= 3.0;
     tempz[7] /= 3.0;
     tempx[8] /= 4.0;
     tempy[8] /= 4.0;
     tempz[8] /= 4.0;
     tempx[9] /= 4.0;
     tempy[9] /= 4.0;
     tempz[9] /= 4.0;
     tempx[10] /= 6.0;
     tempy[10] /= 6.0;
     tempz[10] /= 6.0;
     tempx[11] /= 4.0;
     tempy[11] /= 4.0;
     tempz[11] /= 4.0;
     tempx[12] /= 4.0;
     tempy[12] /= 4.0;
     tempz[12] /= 4.0;


     terarray[a-4].v3.dvx = tempx[0];
     terarray[a-4].v3.dvy = tempy[0];
     terarray[a-4].v3.dvz = tempz[0];
     terarray[a-3].v1.dvx = tempx[0];
     terarray[a-3].v1.dvy = tempy[0];
     terarray[a-3].v1.dvz = tempz[0];
     terarray[a-2].v2.dvx = tempx[0];
     terarray[a-2].v2.dvy = tempy[0];
     terarray[a-2].v2.dvz = tempz[0];
     terarray[a-1].v1.dvx = tempx[0];
     terarray[a-1].v1.dvy = tempy[0];
     terarray[a-1].v1.dvz = tempz[0];
     terarray[a].v1.dvx = tempx[0];
     terarray[a].v1.dvy = tempy[0];
     terarray[a].v1.dvz = tempz[0];
     terarray[a+4].v1.dvx = tempx[0];
     terarray[a+4].v1.dvy = tempy[0];
     terarray[a+4].v1.dvz = tempz[0];
     terarray[a+8].v1.dvx = tempx[0];
     terarray[a+8].v1.dvy = tempy[0];
     terarray[a+8].v1.dvz = tempz[0];
     terarray[a+9].v1.dvx = tempx[0];
     terarray[a+9].v1.dvy = tempy[0];
     terarray[a+9].v1.dvz = tempz[0];
     terarray[a+14].v1.dvx = tempx[0];
     terarray[a+14].v1.dvy = tempy[0];
     terarray[a+14].v1.dvz = tempz[0];
     terarray[a+15].v1.dvx = tempx[0];
     terarray[a+15].v1.dvy = tempy[0];
     terarray[a+15].v1.dvz = tempz[0];
     terarray[a-3].v3.dvx = tempx[1];
     terarray[a-3].v3.dvy = tempy[1];
     terarray[a-3].v3.dvz = tempz[1];
     terarray[a+8].v2.dvx = tempx[1];
     terarray[a+8].v2.dvy = tempy[1];
     terarray[a+8].v2.dvz = tempz[1];
     terarray[a-1].v2.dvx = tempx[2];
     terarray[a-1].v2.dvy = tempy[2];
     terarray[a-1].v2.dvz = tempz[2];
     terarray[a+14].v3.dvx = tempx[2];
     terarray[a+14].v3.dvy = tempy[2];
     terarray[a+14].v3.dvz = tempz[2];
     terarray[a+14].v2.dvx = tempx[3];
     terarray[a+14].v2.dvy = tempy[3];
     terarray[a+14].v2.dvz = tempz[3];
     terarray[a+15].v3.dvx = tempx[3];
     terarray[a+15].v3.dvy = tempy[3];
     terarray[a+15].v3.dvz = tempz[3];
     terarray[a+16].v3.dvx = tempx[3];
     terarray[a+16].v3.dvy = tempy[3];
     terarray[a+16].v3.dvz = tempz[3];
     terarray[a+4].v3.dvx = tempx[4];
     terarray[a+4].v3.dvy = tempy[4];
     terarray[a+4].v3.dvz = tempz[4];
     terarray[a+5].v3.dvx = tempx[4];
     terarray[a+5].v3.dvy = tempy[4];
     terarray[a+5].v3.dvz = tempz[4];
     terarray[a+6].v3.dvx = tempx[4];
     terarray[a+6].v3.dvy = tempy[4];
     terarray[a+6].v3.dvz = tempz[4];
     terarray[a+15].v2.dvx = tempx[4];
     terarray[a+15].v2.dvy = tempy[4];
     terarray[a+15].v2.dvz = tempz[4];
     terarray[a+16].v1.dvx = tempx[4];
     terarray[a+16].v1.dvy = tempy[4];
     terarray[a+16].v1.dvz = tempz[4];
     terarray[a+17].v1.dvx = tempx[4];
     terarray[a+17].v1.dvy = tempy[4];
     terarray[a+17].v1.dvz = tempz[4];
     terarray[a].v3.dvx = tempx[5];
     terarray[a].v3.dvy = tempy[5];
     terarray[a].v3.dvz = tempz[5];
     terarray[a+1].v1.dvx = tempx[5];
     terarray[a+1].v1.dvy = tempy[5];
     terarray[a+1].v1.dvz = tempz[5];
     terarray[a+4].v2.dvx = tempx[5];
     terarray[a+4].v2.dvy = tempy[5];
     terarray[a+4].v2.dvz = tempz[5];
     terarray[a+5].v1.dvx = tempx[5];
     terarray[a+5].v1.dvy = tempy[5];
     terarray[a+5].v1.dvz = tempz[5];
     terarray[a].v2.dvx = tempx[6];
     terarray[a].v2.dvy = tempy[6];
     terarray[a].v2.dvz = tempz[6];
     terarray[a+1].v2.dvx = tempx[6];
     terarray[a+1].v2.dvy = tempy[6];
     terarray[a+1].v2.dvz = tempz[6];
     terarray[a+2].v2.dvx = tempx[6];
     terarray[a+2].v2.dvy = tempy[6];
     terarray[a+2].v2.dvz = tempz[6];
     terarray[a+9].v3.dvx = tempx[6];
     terarray[a+9].v3.dvy = tempy[6];
     terarray[a+9].v3.dvz = tempz[6];
     terarray[a+10].v1.dvx = tempx[6];
     terarray[a+10].v1.dvy = tempy[6];
     terarray[a+10].v1.dvz = tempz[6];
     terarray[a+11].v1.dvx = tempx[6];
     terarray[a+11].v1.dvy = tempy[6];
     terarray[a+11].v1.dvz = tempz[6];
     terarray[a+8].v3.dvx = tempx[7];
     terarray[a+8].v3.dvy = tempy[7];
     terarray[a+8].v3.dvz = tempz[7];
     terarray[a+9].v2.dvx = tempx[7];
     terarray[a+9].v2.dvy = tempy[7];
     terarray[a+9].v2.dvz = tempz[7];
     terarray[a+10].v2.dvx = tempx[7];
     terarray[a+10].v2.dvy = tempy[7];
     terarray[a+10].v2.dvz = tempz[7];
     terarray[a+16].v2.dvx = tempx[8];
     terarray[a+16].v2.dvy = tempy[8];
     terarray[a+16].v2.dvz = tempz[8];
     terarray[a+17].v3.dvx = tempx[8];
     terarray[a+17].v3.dvy = tempy[8];
     terarray[a+17].v3.dvz = tempz[8];
     terarray[a+18].v3.dvx = tempx[8];
     terarray[a+18].v3.dvy = tempy[8];
     terarray[a+18].v3.dvz = tempz[8];
     terarray[a+19].v3.dvx = tempx[8];
     terarray[a+19].v3.dvy = tempy[8];
     terarray[a+19].v3.dvz = tempz[8];
     terarray[a+6].v2.dvx = tempx[9];
     terarray[a+6].v2.dvy = tempy[9];
     terarray[a+6].v2.dvz = tempz[9];
     terarray[a+7].v3.dvx = tempx[9];
     terarray[a+7].v3.dvy = tempy[9];
     terarray[a+7].v3.dvz = tempz[9];
     terarray[a+17].v2.dvx = tempx[9];
     terarray[a+17].v2.dvy = tempy[9];
     terarray[a+17].v2.dvz = tempz[9];
     terarray[a+18].v1.dvx = tempx[9];
     terarray[a+18].v1.dvy = tempy[9];
     terarray[a+18].v1.dvz = tempz[9];
     terarray[a+1].v3.dvx = tempx[10];
     terarray[a+1].v3.dvy = tempy[10];
     terarray[a+1].v3.dvz = tempz[10];
     terarray[a+2].v1.dvx = tempx[10];
     terarray[a+2].v1.dvy = tempy[10];
     terarray[a+2].v1.dvz = tempz[10];
     terarray[a+3].v1.dvx = tempx[10];
     terarray[a+3].v1.dvy = tempy[10];
     terarray[a+3].v1.dvz = tempz[10];
     terarray[a+5].v2.dvx = tempx[10];
     terarray[a+5].v2.dvy = tempy[10];
     terarray[a+5].v2.dvz = tempz[10];
     terarray[a+6].v1.dvx = tempx[10];
     terarray[a+6].v1.dvy = tempy[10];
     terarray[a+6].v1.dvz = tempz[10];
     terarray[a+7].v1.dvx = tempx[10];
     terarray[a+7].v1.dvy = tempy[10];
     terarray[a+7].v1.dvz = tempz[10];
     terarray[a+2].v3.dvx = tempx[11];
     terarray[a+2].v3.dvy = tempy[11];
     terarray[a+2].v3.dvz = tempz[11];
     terarray[a+3].v2.dvx = tempx[11];
     terarray[a+3].v2.dvy = tempy[11];
     terarray[a+3].v2.dvz = tempz[11];
     terarray[a+11].v3.dvx = tempx[11];
     terarray[a+11].v3.dvy = tempy[11];
     terarray[a+11].v3.dvz = tempz[11];
     terarray[a+12].v1.dvx = tempx[11];
     terarray[a+12].v1.dvy = tempy[11];
     terarray[a+12].v1.dvz = tempz[11];
     terarray[a+10].v3.dvx = tempx[12];
     terarray[a+10].v3.dvy = tempy[12];
     terarray[a+10].v3.dvz = tempz[12];
     terarray[a+11].v2.dvx = tempx[12];
     terarray[a+11].v2.dvy = tempy[12];
     terarray[a+11].v2.dvz = tempz[12];
     terarray[a+12].v2.dvx = tempx[12];
     terarray[a+12].v2.dvy = tempy[12];
     terarray[a+12].v2.dvz = tempz[12];
     terarray[a+13].v2.dvx = tempx[12];
     terarray[a+13].v2.dvy = tempy[12];
     terarray[a+13].v2.dvz = tempz[12];

     a += 20;
    }
   else
    {
     if(((terarray[a-13].color.red == 0) || (terarray[a-13].color.green == 0)) && a >= 13)
      {
     tempx[0] = terarray[a-1].dxv + terarray[a+2].dxv + terarray[a+3].dxv;
     tempy[0] = terarray[a-1].dyv + terarray[a+2].dyv + terarray[a+3].dyv;
     tempz[0] = terarray[a-1].dzv + terarray[a+2].dzv + terarray[a+3].dzv;
     tempx[1] = terarray[a-1].dxv + terarray[a-2].dxv + terarray[a-7].dxv + terarray[a-8].dxv
                + terarray[a-13].dxv + terarray[a-17].dxv + terarray[a].dxv + terarray[a+2].dxv;
     tempy[1] = terarray[a-1].dyv + terarray[a-2].dyv + terarray[a-7].dyv + terarray[a-8].dyv
                + terarray[a-13].dyv + terarray[a-17].dyv + terarray[a].dyv + terarray[a+2].dyv;
     tempz[1] = terarray[a-1].dzv + terarray[a-2].dzv + terarray[a-7].dzv + terarray[a-8].dzv
                + terarray[a-13].dzv + terarray[a-17].dzv + terarray[a].dzv + terarray[a+2].dzv;
     tempx[2] = terarray[a-7].dxv + terarray[a].dxv + terarray[a+1].dxv;
     tempy[2] = terarray[a-7].dyv + terarray[a].dyv + terarray[a+1].dyv;
     tempz[2] = terarray[a-7].dzv + terarray[a].dzv + terarray[a+1].dzv;

     tempx[0] /= 3.0;
     tempy[0] /= 3.0;
     tempz[0] /= 3.0;
     tempx[1] /= 8.0;
     tempy[1] /= 8.0;
     tempz[1] /= 8.0;
     tempx[2] /= 3.0;
     tempy[2] /= 3.0;
     tempz[2] /= 3.0;

     terarray[a-1].v2.dvx = tempx[0];
     terarray[a-1].v2.dvy = tempy[0];
     terarray[a-1].v2.dvz = tempz[0];
     terarray[a+2].v3.dvx = tempx[0];
     terarray[a+2].v3.dvy = tempy[0];
     terarray[a+2].v3.dvz = tempz[0];
     terarray[a+3].v3.dvx = tempx[0];
     terarray[a+3].v3.dvy = tempy[0];
     terarray[a+3].v3.dvz = tempz[0];
     terarray[a-17].v3.dvx = tempx[1];
     terarray[a-17].v3.dvy = tempy[1];
     terarray[a-17].v3.dvz = tempz[1];
     terarray[a-13].v2.dvx = tempx[1];
     terarray[a-13].v2.dvy = tempy[1];
     terarray[a-13].v2.dvz = tempz[1];
     terarray[a-8].v3.dvx = tempx[1];
     terarray[a-8].v3.dvy = tempy[1];
     terarray[a-8].v3.dvz = tempz[1];
     terarray[a-7].v1.dvx = tempx[1];
     terarray[a-7].v1.dvy = tempy[1];
     terarray[a-7].v1.dvz = tempz[1];
     terarray[a-2].v2.dvx = tempx[1];
     terarray[a-2].v2.dvy = tempy[1];
     terarray[a-2].v2.dvz = tempz[1];
     terarray[a-1].v1.dvx = tempx[1];
     terarray[a-1].v1.dvy = tempy[1];
     terarray[a-1].v1.dvz = tempz[1];
     terarray[a].v1.dvx = tempx[1];
     terarray[a].v1.dvy = tempy[1];
     terarray[a].v1.dvz = tempz[1];
     terarray[a+2].v1.dvx = tempx[1];
     terarray[a+2].v1.dvy = tempy[1];
     terarray[a+2].v1.dvz = tempz[1];
     terarray[a-7].v3.dvx = tempx[2];
     terarray[a-7].v3.dvy = tempy[2];
     terarray[a-7].v3.dvz = tempz[2];
     terarray[a].v2.dvx = tempx[2];
     terarray[a].v2.dvy = tempy[2];
     terarray[a].v2.dvz = tempz[2];
     terarray[a+1].v2.dvx = tempx[2];
     terarray[a+1].v2.dvy = tempy[2];
     terarray[a+1].v2.dvz = tempz[2];

      }
      else
       {
     tempx[0] = terarray[a-1].dxv + terarray[a+2].dxv + terarray[a+3].dxv;
     tempy[0] = terarray[a-1].dyv + terarray[a+2].dyv + terarray[a+3].dyv;
     tempz[0] = terarray[a-1].dzv + terarray[a+2].dzv + terarray[a+3].dzv;
     tempx[1] = terarray[a-4].dxv + terarray[a-3].dxv + terarray[a-2].dxv + terarray[a-1].dxv
                + terarray[a].dxv + terarray[a+1].dxv;
     tempy[1] = terarray[a-4].dyv + terarray[a-3].dyv + terarray[a-2].dyv + terarray[a-1].dyv
                + terarray[a].dyv + terarray[a+1].dyv;
     tempz[1] = terarray[a-4].dzv + terarray[a-3].dzv + terarray[a-2].dzv + terarray[a-1].dzv
                + terarray[a].dzv + terarray[a+1].dzv;
     tempx[2] = terarray[a-3].dxv + terarray[a].dxv + terarray[a+1].dxv;
     tempy[2] = terarray[a-3].dyv + terarray[a].dyv + terarray[a+1].dyv;
     tempz[2] = terarray[a-3].dzv + terarray[a].dzv + terarray[a+1].dzv;

     tempx[0] /= 3.0;
     tempy[0] /= 3.0;
     tempz[0] /= 3.0;
     tempx[1] /= 6.0;
     tempy[1] /= 6.0;
     tempz[1] /= 6.0;
     tempx[2] /= 3.0;
     tempy[2] /= 3.0;
     tempz[2] /= 3.0;


     terarray[a-1].v2.dvx = tempx[0];
     terarray[a-1].v2.dvy = tempy[0];
     terarray[a-1].v2.dvz = tempz[0];
     terarray[a+2].v3.dvx = tempx[0];
     terarray[a+2].v3.dvy = tempy[0];
     terarray[a+2].v3.dvz = tempz[0];
     terarray[a+3].v3.dvx = tempx[0];
     terarray[a+3].v3.dvy = tempy[0];
     terarray[a+3].v3.dvz = tempz[0];
     terarray[a-4].v3.dvx = tempx[1];
     terarray[a-4].v3.dvy = tempy[1];
     terarray[a-4].v3.dvz = tempz[1];
     terarray[a-3].v1.dvx = tempx[1];
     terarray[a-3].v1.dvy = tempy[1];
     terarray[a-3].v1.dvz = tempz[1];
     terarray[a-2].v2.dvx = tempx[1];
     terarray[a-2].v2.dvy = tempy[1];
     terarray[a-2].v2.dvz = tempz[1];
     terarray[a-1].v1.dvx = tempx[1];
     terarray[a-1].v1.dvy = tempy[1];
     terarray[a-1].v1.dvz = tempz[1];
     terarray[a].v1.dvx = tempx[1];
     terarray[a].v1.dvy = tempy[1];
     terarray[a].v1.dvz = tempz[1];
     terarray[a+2].v1.dvx = tempx[1];
     terarray[a+2].v1.dvy = tempy[1];
     terarray[a+2].v1.dvz = tempz[1];
     terarray[a-3].v3.dvx = tempx[2];
     terarray[a-3].v3.dvy = tempy[2];
     terarray[a-3].v3.dvz = tempz[2];
     terarray[a].v2.dvx = tempx[2];
     terarray[a].v2.dvy = tempy[2];
     terarray[a].v2.dvz = tempz[2];
     terarray[a+1].v2.dvx = tempx[2];
     terarray[a+1].v2.dvy = tempy[2];
     terarray[a+1].v2.dvz = tempz[2];

       }
     a+=4;

    }
  }
  if((terarray[a-13].color.red == 0) || (terarray[a-13].color.green == 0))
      {
     tempx[0] = terarray[a-1].dxv + terarray[a+2].dxv + terarray[a+3].dxv;
     tempy[0] = terarray[a-1].dyv + terarray[a+2].dyv + terarray[a+3].dyv;
     tempz[0] = terarray[a-1].dzv + terarray[a+2].dzv + terarray[a+3].dzv;
     tempx[1] = terarray[a-1].dxv + terarray[a-2].dxv + terarray[a-7].dxv + terarray[a-8].dxv
                + terarray[a-13].dxv + terarray[a-17].dxv + terarray[a].dxv + terarray[a+2].dxv;
     tempy[1] = terarray[a-1].dyv + terarray[a-2].dyv + terarray[a-7].dyv + terarray[a-8].dyv
                + terarray[a-13].dyv + terarray[a-17].dyv + terarray[a].dyv + terarray[a+2].dyv;
     tempz[1] = terarray[a-1].dzv + terarray[a-2].dzv + terarray[a-7].dzv + terarray[a-8].dzv
                + terarray[a-13].dzv + terarray[a-17].dzv + terarray[a].dzv + terarray[a+2].dzv;
     tempx[2] = terarray[a-7].dxv + terarray[a-8].dxv + terarray[a].dxv;
     tempy[2] = terarray[a-7].dyv + terarray[a-8].dyv + terarray[a].dyv;
     tempz[2] = terarray[a-7].dzv + terarray[a-8].dzv + terarray[a].dzv;

     tempx[0] /= 3.0;
     tempy[0] /= 3.0;
     tempz[0] /= 3.0;
     tempx[1] /= 8.0;
     tempy[1] /= 8.0;
     tempz[1] /= 8.0;
     tempx[2] /= 3.0;
     tempy[2] /= 3.0;
     tempz[2] /= 3.0;

     terarray[a-1].v2.dvx = tempx[0];
     terarray[a-1].v2.dvy = tempy[0];
     terarray[a-1].v2.dvz = tempz[0];
     terarray[a+2].v3.dvx = tempx[0];
     terarray[a+2].v3.dvy = tempy[0];
     terarray[a+2].v3.dvz = tempz[0];
     terarray[a+3].v3.dvx = tempx[0];
     terarray[a+3].v3.dvy = tempy[0];
     terarray[a+3].v3.dvz = tempz[0];
     terarray[a-17].v3.dvx = tempx[1];
     terarray[a-17].v3.dvy = tempy[1];
     terarray[a-17].v3.dvz = tempz[1];
     terarray[a-13].v2.dvx = tempx[1];
     terarray[a-13].v2.dvy = tempy[1];
     terarray[a-13].v2.dvz = tempz[1];
     terarray[a-8].v3.dvx = tempx[1];
     terarray[a-8].v3.dvy = tempy[1];
     terarray[a-8].v3.dvz = tempz[1];
     terarray[a-7].v1.dvx = tempx[1];
     terarray[a-7].v1.dvy = tempy[1];
     terarray[a-7].v1.dvz = tempz[1];
     terarray[a-2].v2.dvx = tempx[1];
     terarray[a-2].v2.dvy = tempy[1];
     terarray[a-2].v2.dvz = tempz[1];
     terarray[a-1].v1.dvx = tempx[1];
     terarray[a-1].v1.dvy = tempy[1];
     terarray[a-1].v1.dvz = tempz[1];
     terarray[a].v1.dvx = tempx[1];
     terarray[a].v1.dvy = tempy[1];
     terarray[a].v1.dvz = tempz[1];
     terarray[a+2].v1.dvx = tempx[1];
     terarray[a+2].v1.dvy = tempy[1];
     terarray[a+2].v1.dvz = tempz[1];
     terarray[a-7].v3.dvx = tempx[2];
     terarray[a-7].v3.dvy = tempy[2];
     terarray[a-7].v3.dvz = tempz[2];
     terarray[a].v2.dvx = tempx[2];
     terarray[a].v2.dvy = tempy[2];
     terarray[a].v2.dvz = tempz[2];
     terarray[a+1].v2.dvx = tempx[2];
     terarray[a+1].v2.dvy = tempy[2];
     terarray[a+1].v2.dvz = tempz[2];

      }
      else
       {
     tempx[0] = terarray[a-1].dxv + terarray[a+2].dxv + terarray[a+3].dxv;
     tempy[0] = terarray[a-1].dyv + terarray[a+2].dyv + terarray[a+3].dyv;
     tempz[0] = terarray[a-1].dzv + terarray[a+2].dzv + terarray[a+3].dzv;
     tempx[1] = terarray[a-4].dxv + terarray[a-3].dxv + terarray[a-2].dxv + terarray[a-1].dxv
                + terarray[a].dxv + terarray[a+1].dxv;
     tempy[1] = terarray[a-4].dyv + terarray[a-3].dyv + terarray[a-2].dyv + terarray[a-1].dyv
                + terarray[a].dyv + terarray[a+1].dyv;
     tempz[1] = terarray[a-4].dzv + terarray[a-3].dzv + terarray[a-2].dzv + terarray[a-1].dzv
                + terarray[a].dzv + terarray[a+1].dzv;
     tempx[2] = terarray[a-3].dxv + terarray[a].dxv + terarray[a+1].dxv;
     tempy[2] = terarray[a-3].dyv + terarray[a].dyv + terarray[a+1].dyv;
     tempz[2] = terarray[a-3].dzv + terarray[a].dzv + terarray[a+1].dzv;

     tempx[0] /= 3.0;
     tempy[0] /= 3.0;
     tempz[0] /= 3.0;
     tempx[1] /= 6.0;
     tempy[1] /= 6.0;
     tempz[1] /= 6.0;
     tempx[2] /= 3.0;
     tempy[2] /= 3.0;
     tempz[2] /= 3.0;


     terarray[a-1].v2.dvx = tempx[0];
     terarray[a-1].v2.dvy = tempy[0];
     terarray[a-1].v2.dvz = tempz[0];
     terarray[a+2].v3.dvx = tempx[0];
     terarray[a+2].v3.dvy = tempy[0];
     terarray[a+2].v3.dvz = tempz[0];
     terarray[a+3].v3.dvx = tempx[0];
     terarray[a+3].v3.dvy = tempy[0];
     terarray[a+3].v3.dvz = tempz[0];
     terarray[a-4].v3.dvx = tempx[1];
     terarray[a-4].v3.dvy = tempy[1];
     terarray[a-4].v3.dvz = tempz[1];
     terarray[a-3].v1.dvx = tempx[1];
     terarray[a-3].v1.dvy = tempy[1];
     terarray[a-3].v1.dvz = tempz[1];
     terarray[a-2].v2.dvx = tempx[1];
     terarray[a-2].v2.dvy = tempy[1];
     terarray[a-2].v2.dvz = tempz[1];
     terarray[a-1].v1.dvx = tempx[1];
     terarray[a-1].v1.dvy = tempy[1];
     terarray[a-1].v1.dvz = tempz[1];
     terarray[a].v1.dvx = tempx[1];
     terarray[a].v1.dvy = tempy[1];
     terarray[a].v1.dvz = tempz[1];
     terarray[a+2].v1.dvx = tempx[1];
     terarray[a+2].v1.dvy = tempy[1];
     terarray[a+2].v1.dvz = tempz[1];
     terarray[a-3].v3.dvx = tempx[2];
     terarray[a-3].v3.dvy = tempy[2];
     terarray[a-3].v3.dvz = tempz[2];
     terarray[a].v2.dvx = tempx[2];
     terarray[a].v2.dvy = tempy[2];
     terarray[a].v2.dvz = tempz[2];
     terarray[a+1].v2.dvx = tempx[2];
     terarray[a+1].v2.dvy = tempy[2];
     terarray[a+1].v2.dvz = tempz[2];

       }
     tempx[3] = terarray[a+3].dxv;
     tempy[3] = terarray[a+3].dyv;
     tempz[3] = terarray[a+3].dzv;
     tempx[4] = terarray[a].dxv + terarray[a+1].dxv + terarray[a+2].dxv + terarray[a+3].dxv;
     tempy[4] = terarray[a].dyv + terarray[a+1].dyv + terarray[a+2].dyv + terarray[a+3].dyv;
     tempz[4] = terarray[a].dzv + terarray[a+1].dzv + terarray[a+2].dzv + terarray[a+3].dzv;
     tempx[5] = terarray[a+1].dxv;
     tempy[5] = terarray[a+1].dyv;
     tempz[5] = terarray[a+1].dzv;

     tempx[3] /= 1.0;
     tempy[3] /= 1.0;
     tempz[3] /= 1.0;
     tempx[4] /= 4.0;
     tempy[4] /= 4.0;
     tempz[4] /= 4.0;
     tempx[5] /= 1.0;
     tempy[5] /= 1.0;
     tempz[5] /= 1.0;


     terarray[a+3].v2.dvx = tempx[3];
     terarray[a+3].v2.dvy = tempy[3];
     terarray[a+3].v2.dvz = tempz[3];
     terarray[a].v3.dvx = tempx[4];
     terarray[a].v3.dvy = tempy[4];
     terarray[a].v3.dvz = tempz[4];
     terarray[a+1].v1.dvx = tempx[4];
     terarray[a+1].v1.dvy = tempy[4];
     terarray[a+1].v1.dvz = tempz[4];
     terarray[a+2].v2.dvx = tempx[4];
     terarray[a+2].v2.dvy = tempy[4];
     terarray[a+2].v2.dvz = tempz[4];
     terarray[a+3].v1.dvx = tempx[4];
     terarray[a+3].v1.dvy = tempy[4];
     terarray[a+3].v1.dvz = tempz[4];
     terarray[a+1].v3.dvx = tempx[5];
     terarray[a+1].v3.dvy = tempy[5];
     terarray[a+1].v3.dvz = tempz[5];


  for(a=0;a<numbpolys;a++)
   {
    double magnitude=1;
    magnitude = sqrt((terarray[a].v1.dvx*terarray[a].v1.dvx) + (terarray[a].v1.dvy*terarray[a].v1.dvy) + (terarray[a].v1.dvz*terarray[a].v1.dvz));
    if(magnitude == 0) magnitude = 1;
    terarray[a].v1.dvx = terarray[a].v1.dvx/magnitude;
    terarray[a].v1.dvy = terarray[a].v1.dvy/magnitude;
    terarray[a].v1.dvz = terarray[a].v1.dvz/magnitude;
    magnitude = sqrt((terarray[a].v2.dvx*terarray[a].v2.dvx) + (terarray[a].v2.dvy*terarray[a].v2.dvy) + (terarray[a].v2.dvz*terarray[a].v2.dvz));
    if(magnitude == 0) magnitude = 1;
    terarray[a].v2.dvx = terarray[a].v2.dvx/magnitude;
    terarray[a].v2.dvy = terarray[a].v2.dvy/magnitude;
    terarray[a].v2.dvz = terarray[a].v2.dvz/magnitude;
    magnitude = sqrt((terarray[a].v3.dvx*terarray[a].v3.dvx + terarray[a].v3.dvy*terarray[a].v3.dvy + terarray[a].v3.dvz*terarray[a].v3.dvz));
    if(magnitude == 0) magnitude = 1;
    terarray[a].v3.dvx = terarray[a].v3.dvx/magnitude;
    terarray[a].v3.dvy = terarray[a].v3.dvy/magnitude;
    terarray[a].v3.dvz = terarray[a].v3.dvz/magnitude;

   }

 }


void terrainclass::calcpolylight(void)
 {
  int a;
  float view1,view2,view3,dotp,magnitude;

  for(a=0;a<numbpolys;a++)
   {
    view1 = 450 - terarray[a].midx;
    view2 = -300 - terarray[a].midy;
    view3 = -140 - terarray[a].midz;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    if(magnitude == 0) magnitude = 1;
    view1 /= magnitude;
    view2 /= magnitude;
    view3 /= magnitude;

    dotp = view1*terarray[a].dxv + view2*terarray[a].dyv + view3*terarray[a].dzv;
    if(dotp <= 0.0)
     {
      terarray[a].color1.red = terarray[a].color.red;
      terarray[a].color1.green = terarray[a].color.green;
      terarray[a].color1.blue = terarray[a].color.blue;

     /* terarray[a].color.red *= 16*dotp;
      terarray[a].color.green *= 16*dotp;
      terarray[a].color.blue *= 16*dotp;
    */ }
     else
     {
      if(terarray[a].color.red == 0 || terarray[a].color.blue == 0)
       {
 /*       if(terarray[a].color.green != 0)
         {
    */
          terarray[a].color1.red = terarray[a].color.red + terarray[a].color.red*3*dotp;
          terarray[a].color1.green = terarray[a].color.green + terarray[a].color.green*3*dotp;
          terarray[a].color1.blue = terarray[a].color.blue + terarray[a].color.blue*3*dotp;
          if(terarray[a].color1.red > 31) terarray[a].color1.red = 31;
          if(terarray[a].color1.green > 63) terarray[a].color1.green = 63;
          if(terarray[a].color1.blue > 31) terarray[a].color1.blue = 31;

   /*      }
        else
        {
  *//*       terarray[a].color1.red = terarray[a].color.red + terarray[a].color.red*8.9*dotp;
         terarray[a].color1.green = terarray[a].color.green + terarray[a].color.green*8.9*dotp;
         terarray[a].color1.blue = terarray[a].color.blue + terarray[a].color.blue*8.9*dotp;
          if(terarray[a].color1.red > 31) terarray[a].color1.red = 31;
          if(terarray[a].color1.green > 63) terarray[a].color1.green = 63;
          if(terarray[a].color1.blue > 31) terarray[a].color1.blue = 31;
    */
  /*      }
  */
       }
       else
        {
         terarray[a].color1.red = terarray[a].color.red + terarray[a].color.red*30*dotp;
         terarray[a].color1.green = terarray[a].color.green + terarray[a].color.green*30*dotp;
         terarray[a].color1.blue = terarray[a].color.blue + terarray[a].color.blue*30*dotp;
          if(terarray[a].color1.red > 31) terarray[a].color1.red = 31;
          if(terarray[a].color1.green > 63) terarray[a].color1.green = 63;
          if(terarray[a].color1.blue > 31) terarray[a].color1.blue = 31;

        }
     }

   }
 }

void terrainclass::calcverlight(void)
 {
  int a;
  float view1,view2,view3,dotp,magnitude;

  for(a=0;a<numbpolys;a++)
   {
    view1 = 450 - terarray[a].v1.lx;
    view2 = -300 - terarray[a].v1.ly;
    view3 = -140 - terarray[a].v1.lz;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    if(magnitude == 0) magnitude = 1;
    view1 /= magnitude;
    view2 /= magnitude;
    view3 /= magnitude;

    dotp = view1*terarray[a].v1.dvx + view2*terarray[a].v1.dvy + view3*terarray[a].v1.dvz;
    if(dotp <= 0.0625)
     {
      terarray[a].v1.inten = 1;
     }
     else
     {
      terarray[a].v1.inten = 16.0*dotp;
     }
    view1 = 640 - terarray[a].v2.lx;
    view2 = -400 - terarray[a].v2.ly;
    view3 = -140 - terarray[a].v2.lz;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    if(magnitude == 0) magnitude = 1;

    view1 /= magnitude;
    view2 /= magnitude;
    view3 /= magnitude;

    dotp = view1*terarray[a].v2.dvx + view2*terarray[a].v2.dvy + view3*terarray[a].v2.dvz;
    if(dotp <= 0.0625)
     {
      terarray[a].v2.inten = 1;
     }
     else
     {
      terarray[a].v2.inten = 16.0*dotp;
     }
    view1 = 640 - terarray[a].v3.lx;
    view2 = -400 - terarray[a].v3.ly;
    view3 = -140 - terarray[a].v3.lz;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    if(magnitude == 0) magnitude = 1;
    view1 /= magnitude;
    view2 /= magnitude;
    view3 /= magnitude;

    dotp = view1*terarray[a].v3.dvx + view2*terarray[a].v3.dvy + view3*terarray[a].v3.dvz;
    if(dotp <= 0.0625)
     {
      terarray[a].v3.inten = 1;
     }
     else
     {
      terarray[a].v3.inten = 16.0*dotp;
     }

   }
 }



/*void terrainclass::calcdist(void)
   {
    int a;
    float tempx,tempy,tempz;
    for(a = 0;a<numbpolys;a++)
     {
      tempx = -terarray[a].fmidx;
      tempy = -terarray[a].fmidy;
      tempz = -50 - terarray[a].fmidz;
      terarray[a].dist = sqrt(tempx*tempx + tempy*tempy + tempz*tempz);
     }
   }
 */

unsigned int terrainclass::zclip(int xpos,int ypos)
 {
  int a;
  bool v1yn,v2yn,v3yn;
  int numbout;
  float t,tempx,tempy/*,tempz*/;
  unsigned int newpolys;
  newpolys = 0;
  for(a=0;a<numbpolys;a++)
  {
   if(terarray[a].culled == false)
   {
    v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.vz < -49)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.vz < -49)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.vz < -49)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout > 0)
     {
      if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            t = (-49-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
            terarray[a].v1.vx = (terarray[a].v2.vx - terarray[a].v1.vx)*t + terarray[a].v1.vx;
            terarray[a].v1.vy = (terarray[a].v2.vy - terarray[a].v1.vy)*t + terarray[a].v1.vy;
            terarray[a].v1.vz = -49;
           }
          if(v3yn == true)
           {
            t = (-49-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
            terarray[a].v1.vx = (terarray[a].v1.vx - terarray[a].v3.vx)*t + terarray[a].v3.vx;
            terarray[a].v1.vy = (terarray[a].v1.vy - terarray[a].v3.vy)*t + terarray[a].v3.vy;
            terarray[a].v1.vz = -49;
           }
         }
       if(v2yn == false)
         {
          if(v1yn == true)
           {
            t = (-49-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
            terarray[a].v2.vx = (terarray[a].v2.vx - terarray[a].v1.vx)*t + terarray[a].v1.vx;
            terarray[a].v2.vy = (terarray[a].v2.vy - terarray[a].v1.vy)*t + terarray[a].v1.vy;
            terarray[a].v2.vz = -49;
           }
          if(v3yn == true)
           {
            t = (-49-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
            terarray[a].v2.vx = (terarray[a].v3.vx - terarray[a].v2.vx)*t + terarray[a].v2.vx;
            terarray[a].v2.vy = (terarray[a].v3.vy - terarray[a].v2.vy)*t + terarray[a].v2.vy;
            terarray[a].v2.vz = -49;
           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            t = (-49-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
            terarray[a].v3.vx = (terarray[a].v1.vx - terarray[a].v3.vx)*t + terarray[a].v3.vx;
            terarray[a].v3.vy = (terarray[a].v1.vy - terarray[a].v3.vy)*t + terarray[a].v3.vy;
            terarray[a].v3.vz = -49;
           }
          if(v2yn == true)
           {
            t = (-49-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
            terarray[a].v3.vx = (terarray[a].v3.vx - terarray[a].v2.vx)*t + terarray[a].v2.vx;
            terarray[a].v3.vy = (terarray[a].v3.vy - terarray[a].v2.vy)*t + terarray[a].v2.vy;
            terarray[a].v3.vz = -49;
           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         t = (-49-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
         tempx = (terarray[a].v1.vx-terarray[a].v3.vx)*t + terarray[a].v3.vx;
         tempy = (terarray[a].v1.vy-terarray[a].v3.vy)*t + terarray[a].v3.vy;
         terarray[numbpolys-1].v1.vx = tempx;
         terarray[numbpolys-1].v1.vy = tempy;
         terarray[numbpolys-1].v1.vz = -49;
         terarray[numbpolys-1].v3.vx = terarray[a].v2.vx;
         terarray[numbpolys-1].v3.vy = terarray[a].v2.vy;
         terarray[numbpolys-1].v3.vz = terarray[a].v2.vz;
         t = (-49-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
         terarray[numbpolys-1].v2.vx = (terarray[a].v2.vx-terarray[a].v1.vx)*t + terarray[a].v1.vx;
         terarray[numbpolys-1].v2.vy = (terarray[a].v2.vy-terarray[a].v1.vy)*t + terarray[a].v1.vy;
         terarray[numbpolys-1].v2.vz = -49;
         terarray[a].v1.vx = tempx;
         terarray[a].v1.vy = tempy;
         terarray[a].v1.vz = -49;
        }
     if(v2yn == false)
        {
         t = (-49-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
         tempx = (terarray[a].v2.vx-terarray[a].v1.vx)*t + terarray[a].v1.vx;
         tempy = (terarray[a].v2.vy-terarray[a].v1.vy)*t + terarray[a].v1.vy;
         terarray[numbpolys-1].v1.vx = tempx;
         terarray[numbpolys-1].v1.vy = tempy;
         terarray[numbpolys-1].v1.vz = -49;
         terarray[numbpolys-1].v3.vx = terarray[a].v3.vx;
         terarray[numbpolys-1].v3.vy = terarray[a].v3.vy;
         terarray[numbpolys-1].v3.vz = terarray[a].v3.vz;
         t = (-49-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
         terarray[numbpolys-1].v2.vx = (terarray[a].v3.vx-terarray[a].v2.vx)*t + terarray[a].v2.vx;
         terarray[numbpolys-1].v2.vy = (terarray[a].v3.vy-terarray[a].v2.vy)*t + terarray[a].v2.vy;
         terarray[numbpolys-1].v2.vz = -49;
         terarray[a].v2.vx = tempx;
         terarray[a].v2.vy = tempy;
         terarray[a].v2.vz = -49;
        }
       if(v3yn == false)
        {
         t = (-49-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
         tempx = (terarray[a].v3.vx-terarray[a].v2.vx)*t + terarray[a].v2.vx;
         tempy = (terarray[a].v3.vy-terarray[a].v2.vy)*t + terarray[a].v2.vy;
         terarray[numbpolys-1].v1.vx = tempx;
         terarray[numbpolys-1].v1.vy = tempy;
         terarray[numbpolys-1].v1.vz = -49;
         terarray[numbpolys-1].v3.vx = terarray[a].v1.vx;
         terarray[numbpolys-1].v3.vy = terarray[a].v1.vy;
         terarray[numbpolys-1].v3.vz = terarray[a].v1.vz;
         t = (-49-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
         terarray[numbpolys-1].v2.vx = (terarray[a].v1.vx-terarray[a].v3.vx)*t + terarray[a].v3.vx;
         terarray[numbpolys-1].v2.vy = (terarray[a].v1.vy-terarray[a].v3.vy)*t + terarray[a].v3.vy;
         terarray[numbpolys-1].v2.vz = -49;
         terarray[a].v3.vx = tempx;
         terarray[a].v3.vy = tempy;
         terarray[a].v3.vz = -49;
        }
/*       terarray[numbpolys-1].v1.lx = ((terarray[a].v1.vx + xpos)+320);
       terarray[numbpolys-1].v2.lx = ((terarray[a].v2.vx + xpos)+320);
       terarray[numbpolys-1].v3.lx = ((terarray[a].v3.vx + xpos)+320);
       terarray[numbpolys-1].v1.ly = ((terarray[a].v1.vy) + ypos);
       terarray[numbpolys-1].v2.ly = ((terarray[a].v2.vy) + ypos);
       terarray[numbpolys-1].v3.ly = ((terarray[a].v3.vy) + ypos);
       terarray[numbpolys-1].v1.lz = ((terarray[a].v1.vz)+75);
       terarray[numbpolys-1].v2.lz = ((terarray[a].v2.vz)+75);
       terarray[numbpolys-1].v3.lz = ((terarray[a].v3.vz)+75);
  */     terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
         terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;
       terarray[numbpolys-1].color = terarray[a].color;

       terarray[numbpolys-1].color1 = terarray[a].color1;
       terarray[numbpolys-1].nxv = terarray[a].nxv;
       terarray[numbpolys-1].nyv = terarray[a].nyv;
       terarray[numbpolys-1].nzv = terarray[a].nzv;
       terarray[numbpolys-1].dxv = terarray[a].dxv;
       terarray[numbpolys-1].dyv = terarray[a].dyv;
       terarray[numbpolys-1].dzv = terarray[a].dzv;
       terarray[numbpolys-1].culled = false;
     }
     }
    }
  }
  return newpolys;
 }

unsigned int terrainclass::gzclip(int xpos,int ypos)
 {
  int a;
  bool v1yn,v2yn,v3yn;
  int numbout;
  float t,tempx,tempy/*,tempz*/;
  unsigned int newpolys;
  newpolys = 0;
  for(a=0;a<numbpolys;a++)
  {
   if(terarray[a].culled == false)
   {
    v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.vz < 1)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.vz < 1)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.vz < 1)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout > 0)
     {
      if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            terarray[a].v1.inten1 = (((1-terarray[a].v1.vz)/(terarray[a].v2.vz - terarray[a].v1.vz))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = (1-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
            terarray[a].v1.vx = (terarray[a].v2.vx - terarray[a].v1.vx)*t + terarray[a].v1.vx;
            terarray[a].v1.vy = (terarray[a].v2.vy - terarray[a].v1.vy)*t + terarray[a].v1.vy;
            terarray[a].v1.vz = 1;
           }
          if(v3yn == true)
           {
            terarray[a].v1.inten1 = (((1-terarray[a].v1.vz)/(terarray[a].v3.vz - terarray[a].v1.vz))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = (1-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
            terarray[a].v1.vx = (terarray[a].v1.vx - terarray[a].v3.vx)*t + terarray[a].v3.vx;
            terarray[a].v1.vy = (terarray[a].v1.vy - terarray[a].v3.vy)*t + terarray[a].v3.vy;
            terarray[a].v1.vz = 1;

           }
         }
       if(v2yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v2.inten1 = (((1-terarray[a].v2.vz)/(terarray[a].v1.vz - terarray[a].v2.vz))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = (1-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
            terarray[a].v2.vx = (terarray[a].v2.vx - terarray[a].v1.vx)*t + terarray[a].v1.vx;
            terarray[a].v2.vy = (terarray[a].v2.vy - terarray[a].v1.vy)*t + terarray[a].v1.vy;
            terarray[a].v2.vz = 1;

           }
          if(v3yn == true)
           {
            terarray[a].v2.inten1 = (((1-terarray[a].v2.vz)/(terarray[a].v3.vz - terarray[a].v2.vz))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = (1-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
            terarray[a].v2.vx = (terarray[a].v3.vx - terarray[a].v2.vx)*t + terarray[a].v2.vx;
            terarray[a].v2.vy = (terarray[a].v3.vy - terarray[a].v2.vy)*t + terarray[a].v2.vy;
            terarray[a].v2.vz = 1;

           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v3.inten1 = (((1-terarray[a].v3.vz)/(terarray[a].v1.vz - terarray[a].v3.vz))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = (1-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
            terarray[a].v3.vx = (terarray[a].v1.vx - terarray[a].v3.vx)*t + terarray[a].v3.vx;
            terarray[a].v3.vy = (terarray[a].v1.vy - terarray[a].v3.vy)*t + terarray[a].v3.vy;
            terarray[a].v3.vz = 1;

           }
          if(v2yn == true)
           {
            terarray[a].v3.inten1 = (((1-terarray[a].v3.vz)/(terarray[a].v2.vz - terarray[a].v3.vz))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = (1-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
            terarray[a].v3.vx = (terarray[a].v3.vx - terarray[a].v2.vx)*t + terarray[a].v2.vx;
            terarray[a].v3.vy = (terarray[a].v3.vy - terarray[a].v2.vy)*t + terarray[a].v2.vy;
            terarray[a].v3.vz = 1;

           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v2.inten1;
         terarray[numbpolys-1].v2.inten1 = (((1-terarray[a].v1.vz)/(terarray[a].v2.vz - terarray[a].v1.vz))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[a].v1.inten1 = (((1-terarray[a].v1.vz)/(terarray[a].v3.vz - terarray[a].v1.vz))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v1.inten1;

         t = (1-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
         tempx = (terarray[a].v1.vx-terarray[a].v3.vx)*t + terarray[a].v3.vx;
         tempy = (terarray[a].v1.vy-terarray[a].v3.vy)*t + terarray[a].v3.vy;
         terarray[numbpolys-1].v1.vx = tempx;
         terarray[numbpolys-1].v1.vy = tempy;
         terarray[numbpolys-1].v1.vz = 1;
         terarray[numbpolys-1].v3.vx = terarray[a].v2.vx;
         terarray[numbpolys-1].v3.vy = terarray[a].v2.vy;
         terarray[numbpolys-1].v3.vz = terarray[a].v2.vz;
         t = (1-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
         terarray[numbpolys-1].v2.vx = (terarray[a].v2.vx-terarray[a].v1.vx)*t + terarray[a].v1.vx;
         terarray[numbpolys-1].v2.vy = (terarray[a].v2.vy-terarray[a].v1.vy)*t + terarray[a].v1.vy;
         terarray[numbpolys-1].v2.vz = 1;
         terarray[a].v1.vx = tempx;
         terarray[a].v1.vy = tempy;
         terarray[a].v1.vz = 1;

        }
     if(v2yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v3.inten1;
         terarray[numbpolys-1].v2.inten1 = (((1-terarray[a].v2.vz)/(terarray[a].v3.vz - terarray[a].v2.vz))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[a].v2.inten1 = (((1-terarray[a].v2.vz)/(terarray[a].v1.vz - terarray[a].v2.vz))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v2.inten1;

         t = (1-terarray[a].v1.vz)/(terarray[a].v2.vz-terarray[a].v1.vz);
         tempx = (terarray[a].v2.vx-terarray[a].v1.vx)*t + terarray[a].v1.vx;
         tempy = (terarray[a].v2.vy-terarray[a].v1.vy)*t + terarray[a].v1.vy;
         terarray[numbpolys-1].v1.vx = tempx;
         terarray[numbpolys-1].v1.vy = tempy;
         terarray[numbpolys-1].v1.vz = 1;
         terarray[numbpolys-1].v3.vx = terarray[a].v3.vx;
         terarray[numbpolys-1].v3.vy = terarray[a].v3.vy;
         terarray[numbpolys-1].v3.vz = terarray[a].v3.vz;
         t = (1-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
         terarray[numbpolys-1].v2.vx = (terarray[a].v3.vx-terarray[a].v2.vx)*t + terarray[a].v2.vx;
         terarray[numbpolys-1].v2.vy = (terarray[a].v3.vy-terarray[a].v2.vy)*t + terarray[a].v2.vy;
         terarray[numbpolys-1].v2.vz = 1;
         terarray[a].v2.vx = tempx;
         terarray[a].v2.vy = tempy;
         terarray[a].v2.vz = 1;

        }
       if(v3yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v1.inten1;
         terarray[numbpolys-1].v2.inten1 = (((1-terarray[a].v3.vz)/(terarray[a].v1.vz - terarray[a].v3.vz))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[a].v3.inten1 = (((1-terarray[a].v3.vz)/(terarray[a].v2.vz - terarray[a].v3.vz))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v3.inten1;

         t = (1-terarray[a].v2.vz)/(terarray[a].v3.vz-terarray[a].v2.vz);
         tempx = (terarray[a].v3.vx-terarray[a].v2.vx)*t + terarray[a].v2.vx;
         tempy = (terarray[a].v3.vy-terarray[a].v2.vy)*t + terarray[a].v2.vy;
         terarray[numbpolys-1].v1.vx = tempx;
         terarray[numbpolys-1].v1.vy = tempy;
         terarray[numbpolys-1].v1.vz = 1;
         terarray[numbpolys-1].v3.vx = terarray[a].v1.vx;
         terarray[numbpolys-1].v3.vy = terarray[a].v1.vy;
         terarray[numbpolys-1].v3.vz = terarray[a].v1.vz;
         t = (1-terarray[a].v3.vz)/(terarray[a].v1.vz-terarray[a].v3.vz);
         terarray[numbpolys-1].v2.vx = (terarray[a].v1.vx-terarray[a].v3.vx)*t + terarray[a].v3.vx;
         terarray[numbpolys-1].v2.vy = (terarray[a].v1.vy-terarray[a].v3.vy)*t + terarray[a].v3.vy;
         terarray[numbpolys-1].v2.vz = 1;
         terarray[a].v3.vx = tempx;
         terarray[a].v3.vy = tempy;
         terarray[a].v3.vz = 1;

        }
/*       terarray[numbpolys-1].v1.lx = ((terarray[a].v1.vx + xpos)+320);
       terarray[numbpolys-1].v2.lx = ((terarray[a].v2.vx + xpos)+320);
       terarray[numbpolys-1].v3.lx = ((terarray[a].v3.vx + xpos)+320);
       terarray[numbpolys-1].v1.ly = ((terarray[a].v1.vy) + ypos);
       terarray[numbpolys-1].v2.ly = ((terarray[a].v2.vy) + ypos);
       terarray[numbpolys-1].v3.ly = ((terarray[a].v3.vy) + ypos);
       terarray[numbpolys-1].v1.lz = ((terarray[a].v1.vz)+75);
       terarray[numbpolys-1].v2.lz = ((terarray[a].v2.vz)+75);
       terarray[numbpolys-1].v3.lz = ((terarray[a].v3.vz)+75);
  */     terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
         terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;
       terarray[numbpolys-1].color = terarray[a].color;

       terarray[numbpolys-1].color1 = terarray[a].color1;
       terarray[numbpolys-1].nxv = terarray[a].nxv;
       terarray[numbpolys-1].nyv = terarray[a].nyv;
       terarray[numbpolys-1].nzv = terarray[a].nzv;
       terarray[numbpolys-1].dxv = terarray[a].dxv;
       terarray[numbpolys-1].dyv = terarray[a].dyv;
       terarray[numbpolys-1].dzv = terarray[a].dzv;
       terarray[numbpolys-1].culled = false;
     }
     }
    }
  }
  return newpolys;
 }



unsigned int terrainclass::xyclip(int xpos,int ypos)
 {
  int a;
  /*bool v1yn,v2yn,v3yn;
  *//*int numbout;
  float t,tempx,tempy;
  */unsigned int newpolys = 0;
  /*newpolys = 0;
  */for(a=0;a<numbpolys;a++)
  {
   if(terarray[a].culled == false)
   {
    if((terarray[a].v1.sx < 0) && (terarray[a].v2.sx < 0) && (terarray[a].v3.sx < 0))
     terarray[a].culled = true;
    if((terarray[a].v1.sx > 639) && (terarray[a].v2.sx > 639) && (terarray[a].v3.sx > 639))
     terarray[a].culled = true;
    if((terarray[a].v1.sy < 0) && (terarray[a].v2.sy < 0) && (terarray[a].v3.sy < 0))
     terarray[a].culled = true;
    if((terarray[a].v1.sy > 479) && (terarray[a].v2.sy > 479) && (terarray[a].v3.sy > 479))
     terarray[a].culled = true;

   // left clip//
 /*   v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.sx < 0)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.sx < 0)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.sx < 0)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout == 3) terarray[a].culled = true;
    if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v1.sy = terarray[a].v1.sy + (t*(0.0-terarray[a].v1.sx));
            terarray[a].v1.sx = 0;
           }
          if(v3yn == true)
           {
            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v1.sy = terarray[a].v3.sy + (t*(0.0-terarray[a].v3.sx));
            terarray[a].v1.sx = 0;
           }
         }
       if(v2yn == false)
         {
          if(v1yn == true)
           {
            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v2.sy = terarray[a].v1.sy + (t*(0.0-terarray[a].v1.sx));
            terarray[a].v2.sx = 0;
           }
          if(v3yn == true)
           {
            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v2.sy = terarray[a].v2.sy + (t*(0.0-terarray[a].v2.sx));
            terarray[a].v2.sx = 0;
           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v3.sy = terarray[a].v3.sy + (t*(0.0-terarray[a].v3.sx));
            terarray[a].v3.sx = 0;
           }
          if(v2yn == true)
           {
            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v3.sy = terarray[a].v2.sy + (t*(0.0-terarray[a].v2.sx));
            terarray[a].v3.sx = 0;
           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         tempy = terarray[a].v3.sy + t*(0.0-terarray[a].v3.sx);
         tempx = 0;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v2.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v2.sy;
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         terarray[numbpolys-1].v2.sx = 0;
         terarray[numbpolys-1].v2.sy = terarray[a].v1.sy + t*(0.0-terarray[a].v1.sx);
         terarray[a].v1.sx = tempx;
         terarray[a].v1.sy = tempy;
        }
       if(v2yn == false)
        {
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         tempy = terarray[a].v1.sy + t*(0.0-terarray[a].v1.sx);
         tempx = 0;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v3.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v3.sy;
         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         terarray[numbpolys-1].v2.sx = 0;
         terarray[numbpolys-1].v2.sy = terarray[a].v2.sy + t*(0.0-terarray[a].v2.sx);
         terarray[a].v2.sx = tempx;
         terarray[a].v2.sy = tempy;
        }
       if(v3yn == false)
        {
         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         tempy = terarray[a].v2.sy + t*(0.0-terarray[a].v2.sx);
         tempx = 0;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v1.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v1.sy;
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = 0;
         terarray[numbpolys-1].v2.sy = terarray[a].v3.sy + t*(0.0-terarray[a].v3.sx);
         terarray[a].v3.sx = tempx;
         terarray[a].v3.sy = tempy;
        }
       terarray[numbpolys-1].culled = false;
       terarray[numbpolys-1].color = terarray[a].color;
       terarray[numbpolys-1].color1 = terarray[a].color1;

       terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
       terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;
      }


   // right clip //
    v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.sx > 639)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.sx > 639)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.sx > 639)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout == 3) terarray[a].culled = true;
    if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v1.sy = terarray[a].v1.sy + (t*(639-terarray[a].v1.sx));
            terarray[a].v1.sx = 639;
           }
          if(v3yn == true)
           {
            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v1.sy = terarray[a].v3.sy + (t*(639-terarray[a].v3.sx));
            terarray[a].v1.sx = 639;
           }
         }
       if(v2yn == false)
         {
          if(v1yn == true)
           {
            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v2.sy = terarray[a].v1.sy + (t*(639-terarray[a].v1.sx));
            terarray[a].v2.sx = 639;
           }
          if(v3yn == true)
           {
            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v2.sy = terarray[a].v2.sy + (t*(639-terarray[a].v2.sx));
            terarray[a].v2.sx = 639;
           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v3.sy = terarray[a].v3.sy + (t*(639-terarray[a].v3.sx));
            terarray[a].v3.sx = 639;
           }
          if(v2yn == true)
           {
            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v3.sy = terarray[a].v2.sy + (t*(639-terarray[a].v2.sx));
            terarray[a].v3.sx = 639;
           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         tempy = terarray[a].v3.sy + t*(639-terarray[a].v3.sx);
         tempx = 639;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v2.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v2.sy;
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         terarray[numbpolys-1].v2.sx = 639;
         terarray[numbpolys-1].v2.sy = terarray[a].v1.sy + t*(639-terarray[a].v1.sx);
         terarray[a].v1.sx = tempx;
         terarray[a].v1.sy = tempy;
        }
       if(v2yn == false)
        {
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         tempy = terarray[a].v1.sy + t*(639-terarray[a].v1.sx);
         tempx = 639;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v3.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v3.sy;
         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         terarray[numbpolys-1].v2.sx = 639;
         terarray[numbpolys-1].v2.sy = terarray[a].v2.sy + t*(639-terarray[a].v2.sx);
         terarray[a].v2.sx = tempx;
         terarray[a].v2.sy = tempy;
        }
       if(v3yn == false)
        {
         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         tempy = terarray[a].v2.sy + t*(639-terarray[a].v2.sx);
         tempx = 639;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v1.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v1.sy;
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = 639;
         terarray[numbpolys-1].v2.sy = terarray[a].v3.sy + t*(639-terarray[a].v3.sx);
         terarray[a].v3.sx = tempx;
         terarray[a].v3.sy = tempy;
        }
       terarray[numbpolys-1].culled = false;
       terarray[numbpolys-1].color = terarray[a].color;
       terarray[numbpolys-1].color1 = terarray[a].color1;

      terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
       terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;

      }







   // bottom clip //
    v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.sy > 479)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.sy > 479)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.sy > 479)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout == 3) terarray[a].culled = true;

    if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v1.sy = 479;
            terarray[a].v1.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
           }
          if(v3yn == true)
           {
            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v1.sy = 479;
            terarray[a].v1.sx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
           }
         }
      if(v2yn == false)
         {
          if(v1yn == true)
           {
            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v2.sy = 479;
            terarray[a].v2.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
           }
          if(v3yn == true)
           {
            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v2.sy = 479;
            terarray[a].v2.sx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v3.sy = 479;
            terarray[a].v3.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
           }
          if(v2yn == true)
           {
            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v3.sy = 479;
            terarray[a].v3.sx = terarray[a].v2.sx + (479-terarray[a].v2.sy)/t;
           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         t = float(terarray[a].v3.sy-terarray[a].v1.sy)/float(terarray[a].v3.sx-terarray[a].v1.sx);
         tempy = 479;
         tempx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v2.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v2.sy;
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         terarray[numbpolys-1].v2.sx = terarray[a].v2.sx + (479-terarray[a].v2.sy)/t;
         terarray[numbpolys-1].v2.sy = 479;
         terarray[a].v1.sx = tempx;
         terarray[a].v1.sy = tempy;
        }
       if(v2yn == false)
        {
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         tempy = 479;
         tempx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v3.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v3.sy;
         t = float(terarray[a].v2.sy-terarray[a].v3.sy)/float(terarray[a].v2.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
         terarray[numbpolys-1].v2.sy = 479;
         terarray[a].v2.sx = tempx;
         terarray[a].v2.sy = tempy;
        }
       if(v3yn == false)
        {
         t = float(terarray[a].v2.sy-terarray[a].v3.sy)/float(terarray[a].v2.sx-terarray[a].v3.sx);
         tempy = 479;
         tempx = terarray[a].v2.sx + (479-terarray[a].v2.sy)/t;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v1.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v1.sy;
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
         terarray[numbpolys-1].v2.sy = 479;
         terarray[a].v3.sx = tempx;
         terarray[a].v3.sy = tempy;
        }
       terarray[numbpolys-1].culled = false;
       terarray[numbpolys-1].color = terarray[a].color;
       terarray[numbpolys-1].color1 = terarray[a].color1;

       terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
       terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;

      }



 */
   }
  }
  return newpolys;
 }

unsigned int terrainclass::gxyclip(int xpos,int ypos)
 {
  int a;
  bool v1yn,v2yn,v3yn;
  int numbout;
  float t,tempx,tempy/*,tempz*/;
  unsigned int newpolys;
  newpolys = 0;
  for(a=0;a<numbpolys;a++)
  {
   if(terarray[a].culled == false)
   {
   /* left clip*/
    v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.sx < 0)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.sx < 0)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.sx < 0)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout == 3) terarray[a].culled = true;
    if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            terarray[a].v1.inten1 = ((-terarray[a].v1.sx/float(terarray[a].v2.sx - terarray[a].v1.sx))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v1.sy = terarray[a].v1.sy + (t*(0.0-terarray[a].v1.sx));
            terarray[a].v1.sx = 0;

           }
          if(v3yn == true)
           {
            terarray[a].v1.inten1 = ((-terarray[a].v1.sx/float(terarray[a].v3.sx - terarray[a].v1.sx))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v1.sy = terarray[a].v3.sy + (t*(0.0-terarray[a].v3.sx));
            terarray[a].v1.sx = 0;

           }
         }
       if(v2yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v2.inten1 = ((-terarray[a].v2.sx/float(terarray[a].v1.sx - terarray[a].v2.sx))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v2.sy = terarray[a].v1.sy + (t*(0.0-terarray[a].v1.sx));
            terarray[a].v2.sx = 0;

           }
          if(v3yn == true)
           {
            terarray[a].v2.inten1 = ((-terarray[a].v2.sx/float(terarray[a].v3.sx - terarray[a].v2.sx))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v2.sy = terarray[a].v2.sy + (t*(0.0-terarray[a].v2.sx));
            terarray[a].v2.sx = 0;

           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v3.inten1 = ((-terarray[a].v3.sx/float(terarray[a].v1.sx - terarray[a].v3.sx))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v3.sy = terarray[a].v3.sy + (t*(0.0-terarray[a].v3.sx));
            terarray[a].v3.sx = 0;

           }
          if(v2yn == true)
           {
            terarray[a].v3.inten1 = ((-terarray[a].v3.sx/float(terarray[a].v2.sx - terarray[a].v3.sx))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v3.sy = terarray[a].v2.sy + (t*(0.0-terarray[a].v2.sx));
            terarray[a].v3.sx = 0;

           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v2.inten1;
         terarray[numbpolys-1].v2.inten1 = ((-terarray[a].v1.sx/float(terarray[a].v2.sx - terarray[a].v1.sx))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[a].v1.inten1 = ((-terarray[a].v1.sx/float(terarray[a].v3.sx - terarray[a].v1.sx))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v1.inten1;



         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         tempy = terarray[a].v3.sy + t*(0.0-terarray[a].v3.sx);
         tempx = 0;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v2.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v2.sy;
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         terarray[numbpolys-1].v2.sx = 0;
         terarray[numbpolys-1].v2.sy = terarray[a].v1.sy + t*(0.0-terarray[a].v1.sx);
         terarray[a].v1.sx = tempx;
         terarray[a].v1.sy = tempy;
        }
       if(v2yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v3.inten1;
         terarray[numbpolys-1].v2.inten1 = ((-terarray[a].v2.sx/float(terarray[a].v3.sx - terarray[a].v2.sx))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[a].v2.inten1 = ((-terarray[a].v2.sx/float(terarray[a].v1.sx - terarray[a].v2.sx))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v2.inten1;

         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         tempy = terarray[a].v1.sy + t*(0.0-terarray[a].v1.sx);
         tempx = 0;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v3.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v3.sy;
         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         terarray[numbpolys-1].v2.sx = 0;
         terarray[numbpolys-1].v2.sy = terarray[a].v2.sy + t*(0.0-terarray[a].v2.sx);
         terarray[a].v2.sx = tempx;
         terarray[a].v2.sy = tempy;
        }
       if(v3yn == false)
        {

          terarray[numbpolys-1].v3.inten1 = terarray[a].v1.inten1;
         terarray[numbpolys-1].v2.inten1 = ((-terarray[a].v3.sx/float(terarray[a].v1.sx - terarray[a].v3.sx))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[a].v3.inten1 = ((-terarray[a].v3.sx/float(terarray[a].v2.sx - terarray[a].v3.sx))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v3.inten1;

         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         tempy = terarray[a].v2.sy + t*(0.0-terarray[a].v2.sx);
         tempx = 0;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v1.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v1.sy;
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = 0;
         terarray[numbpolys-1].v2.sy = terarray[a].v3.sy + t*(0.0-terarray[a].v3.sx);
         terarray[a].v3.sx = tempx;
         terarray[a].v3.sy = tempy;
        }
       terarray[numbpolys-1].culled = false;
       terarray[numbpolys-1].color = terarray[a].color;
       terarray[numbpolys-1].color1 = terarray[a].color1;

       terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
       terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;
      }


   /* right clip */
    v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.sx > 639)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.sx > 639)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.sx > 639)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout == 3) terarray[a].culled = true;
    if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            terarray[a].v1.inten1 = (((float)(639-terarray[a].v1.sx)/(terarray[a].v2.sx - terarray[a].v1.sx))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = (float)(terarray[a].v2.sy-terarray[a].v1.sy)/(float)(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v1.sy = terarray[a].v1.sy + (t*(639-terarray[a].v1.sx));
            terarray[a].v1.sx = 639;
           }
          if(v3yn == true)
           {
            terarray[a].v1.inten1 = (((float)(639-terarray[a].v1.sx)/(terarray[a].v3.sx - terarray[a].v1.sx))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = (float)(terarray[a].v1.sy-terarray[a].v3.sy)/(float)(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v1.sy = terarray[a].v3.sy + (t*(639-terarray[a].v3.sx));
            terarray[a].v1.sx = 639;
           }
         }
       if(v2yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v2.inten1 = ((float(639-terarray[a].v2.sx)/(terarray[a].v1.sx - terarray[a].v2.sx))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v2.sy = terarray[a].v1.sy + (t*(639-terarray[a].v1.sx));
            terarray[a].v2.sx = 639;
           }
          if(v3yn == true)
           {
            terarray[a].v2.inten1 = ((float(639-terarray[a].v2.sx)/(terarray[a].v3.sx - terarray[a].v2.sx))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v2.sy = terarray[a].v2.sy + (t*(639-terarray[a].v2.sx));
            terarray[a].v2.sx = 639;
           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v3.inten1 = ((float(639-terarray[a].v3.sx)/(terarray[a].v1.sx - terarray[a].v3.sx))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v3.sy = terarray[a].v3.sy + (t*(639-terarray[a].v3.sx));
            terarray[a].v3.sx = 639;
           }
          if(v2yn == true)
           {
            terarray[a].v3.inten1 = ((float(639-terarray[a].v3.sx)/(terarray[a].v2.sx - terarray[a].v3.sx))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v3.sy = terarray[a].v2.sy + (t*(639-terarray[a].v2.sx));
            terarray[a].v3.sx = 639;
           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v2.inten1;
         terarray[numbpolys-1].v2.inten1 = (((639-terarray[a].v1.sx)/float(terarray[a].v2.sx - terarray[a].v1.sx))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[a].v1.inten1 = (((639-terarray[a].v1.sx)/float(terarray[a].v3.sx - terarray[a].v1.sx))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v1.inten1;

         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         tempy = terarray[a].v3.sy + t*(639-terarray[a].v3.sx);
         tempx = 639;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v2.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v2.sy;
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         terarray[numbpolys-1].v2.sx = 639;
         terarray[numbpolys-1].v2.sy = terarray[a].v1.sy + t*(639-terarray[a].v1.sx);
         terarray[a].v1.sx = tempx;
         terarray[a].v1.sy = tempy;
        }
       if(v2yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v3.inten1;
         terarray[numbpolys-1].v2.inten1 = (((639-terarray[a].v2.sx)/float(terarray[a].v3.sx - terarray[a].v2.sx))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[a].v2.inten1 = (((639-terarray[a].v2.sx)/float(terarray[a].v1.sx - terarray[a].v2.sx))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v2.inten1;

         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         tempy = terarray[a].v1.sy + t*(639-terarray[a].v1.sx);
         tempx = 639;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v3.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v3.sy;
         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         terarray[numbpolys-1].v2.sx = 639;
         terarray[numbpolys-1].v2.sy = terarray[a].v2.sy + t*(639-terarray[a].v2.sx);
         terarray[a].v2.sx = tempx;
         terarray[a].v2.sy = tempy;
        }
       if(v3yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v1.inten1;
         terarray[numbpolys-1].v2.inten1 = (((639-terarray[a].v3.sx)/float(terarray[a].v1.sx - terarray[a].v3.sx))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[a].v3.inten1 = (((639-terarray[a].v3.sx)/float(terarray[a].v2.sx - terarray[a].v3.sx))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v3.inten1;

         t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
         tempy = terarray[a].v2.sy + t*(639-terarray[a].v2.sx);
         tempx = 639;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v1.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v1.sy;
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = 639;
         terarray[numbpolys-1].v2.sy = terarray[a].v3.sy + t*(639-terarray[a].v3.sx);
         terarray[a].v3.sx = tempx;
         terarray[a].v3.sy = tempy;
        }
       terarray[numbpolys-1].culled = false;
       terarray[numbpolys-1].color = terarray[a].color;
       terarray[numbpolys-1].color1 = terarray[a].color1;

      terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
       terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;

      }







   /* bottom clip */
    v1yn = true;
    v2yn = true;
    v3yn = true;
    numbout = 0;
    if(terarray[a].v1.sy > 479)
     {
      v1yn = false;
      numbout += 1;
     }
    if(terarray[a].v2.sy > 479)
     {
      v2yn = false;
      numbout += 1;
     }
    if(terarray[a].v3.sy > 479)
     {
      v3yn = false;
      numbout += 1;
     }
    if(numbout == 3) terarray[a].culled = true;

    if(numbout == 2)
       {
        if(v1yn == false)
         {
          if(v2yn == true)
           {
            terarray[a].v1.inten1 = ((float(479-terarray[a].v1.sy)/(terarray[a].v2.sy - terarray[a].v1.sy))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v1.sy = 479;
            terarray[a].v1.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
           }
          if(v3yn == true)
           {
            terarray[a].v1.inten1 = ((float(479-terarray[a].v1.sy)/(terarray[a].v3.sy - terarray[a].v1.sy))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;

            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v1.sy = 479;
            terarray[a].v1.sx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
           }
         }
      if(v2yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v2.inten1 = ((float(479-terarray[a].v2.sy)/(terarray[a].v1.sy - terarray[a].v2.sy))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
            terarray[a].v2.sy = 479;
            terarray[a].v2.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
           }
          if(v3yn == true)
           {
            terarray[a].v2.inten1 = ((float(479-terarray[a].v2.sy)/(terarray[a].v3.sy - terarray[a].v2.sy))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;

            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v2.sy = 479;
            terarray[a].v2.sx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
           }
         }
        if(v3yn == false)
         {
          if(v1yn == true)
           {
            terarray[a].v3.inten1 = ((float(479-terarray[a].v3.sy)/(terarray[a].v1.sy - terarray[a].v3.sy))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
            terarray[a].v3.sy = 479;
            terarray[a].v3.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
           }
          if(v2yn == true)
           {
            terarray[a].v3.inten1 = ((float(479-terarray[a].v3.sy)/(terarray[a].v2.sy - terarray[a].v3.sy))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;

            t = float(terarray[a].v3.sy-terarray[a].v2.sy)/float(terarray[a].v3.sx-terarray[a].v2.sx);
            terarray[a].v3.sy = 479;
            terarray[a].v3.sx = terarray[a].v2.sx + (479-terarray[a].v2.sy)/t;
           }
         }


       }
     if(numbout == 1)
     {
      numbpolys += 1;
      newpolys += 1;
       if(v1yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v2.inten1;
         terarray[numbpolys-1].v2.inten1 = (((479-terarray[a].v1.sy)/float(terarray[a].v2.sy - terarray[a].v1.sy))*(terarray[a].v2.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[a].v1.inten1 = (((479-terarray[a].v1.sy)/float(terarray[a].v3.sy - terarray[a].v1.sy))*(terarray[a].v3.inten1 - terarray[a].v1.inten1)) + terarray[a].v1.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v1.inten1;

         t = float(terarray[a].v3.sy-terarray[a].v1.sy)/float(terarray[a].v3.sx-terarray[a].v1.sx);
         tempy = 479;
         tempx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v2.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v2.sy;
         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         terarray[numbpolys-1].v2.sx = terarray[a].v2.sx + (479-terarray[a].v2.sy)/t;
         terarray[numbpolys-1].v2.sy = 479;
         terarray[a].v1.sx = tempx;
         terarray[a].v1.sy = tempy;
        }
       if(v2yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v3.inten1;
         terarray[numbpolys-1].v2.inten1 = (((479-terarray[a].v2.sy)/float(terarray[a].v3.sy - terarray[a].v2.sy))*(terarray[a].v3.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[a].v2.inten1 = (((479-terarray[a].v2.sy)/float(terarray[a].v1.sy - terarray[a].v2.sy))*(terarray[a].v1.inten1 - terarray[a].v2.inten1)) + terarray[a].v2.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v2.inten1;

         t = float(terarray[a].v2.sy-terarray[a].v1.sy)/float(terarray[a].v2.sx-terarray[a].v1.sx);
         tempy = 479;
         tempx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v3.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v3.sy;
         t = float(terarray[a].v2.sy-terarray[a].v3.sy)/float(terarray[a].v2.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = terarray[a].v3.sx + (479-terarray[a].v3.sy)/t;
         terarray[numbpolys-1].v2.sy = 479;
         terarray[a].v2.sx = tempx;
         terarray[a].v2.sy = tempy;
        }
       if(v3yn == false)
        {
         terarray[numbpolys-1].v3.inten1 = terarray[a].v1.inten1;
         terarray[numbpolys-1].v2.inten1 = (((479-terarray[a].v3.sy)/float(terarray[a].v1.sy - terarray[a].v3.sy))*(terarray[a].v1.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[a].v3.inten1 = (((479-terarray[a].v3.sy)/float(terarray[a].v2.sy - terarray[a].v3.sy))*(terarray[a].v2.inten1 - terarray[a].v3.inten1)) + terarray[a].v3.inten1;
         terarray[numbpolys-1].v1.inten1 = terarray[a].v3.inten1;

         t = float(terarray[a].v2.sy-terarray[a].v3.sy)/float(terarray[a].v2.sx-terarray[a].v3.sx);
         tempy = 479;
         tempx = terarray[a].v2.sx + (479-terarray[a].v2.sy)/t;
         terarray[numbpolys-1].v1.sx = tempx;
         terarray[numbpolys-1].v1.sy = tempy;
         terarray[numbpolys-1].v3.sx = terarray[a].v1.sx;
         terarray[numbpolys-1].v3.sy = terarray[a].v1.sy;
         t = float(terarray[a].v1.sy-terarray[a].v3.sy)/float(terarray[a].v1.sx-terarray[a].v3.sx);
         terarray[numbpolys-1].v2.sx = terarray[a].v1.sx + (479-terarray[a].v1.sy)/t;
         terarray[numbpolys-1].v2.sy = 479;
         terarray[a].v3.sx = tempx;
         terarray[a].v3.sy = tempy;
        }
       terarray[numbpolys-1].culled = false;
       terarray[numbpolys-1].color = terarray[a].color;
       terarray[numbpolys-1].color1 = terarray[a].color1;

       terarray[numbpolys-1].midx = terarray[a].midx;
       terarray[numbpolys-1].midy = terarray[a].midy;
       terarray[numbpolys-1].midz = terarray[a].midz;
       terarray[numbpolys-1].fmidx = terarray[a].fmidx;
       terarray[numbpolys-1].fmidy = terarray[a].fmidy;
       terarray[numbpolys-1].fmidz = terarray[a].fmidz;

      }




   }
  }
  return newpolys;
 }


void terrainclass::removepolys(unsigned short rempolys)
 {
  numbpolys -= rempolys;
 }

int terrainclass::retnumpolys()
 {
  return numbpolys;
 }



