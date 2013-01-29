//---------------------------------------------------------------------------
#include<ddraw.h>
#include<math.h>
#include "screen.h"
#include "SHIP.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


shipclass::shipclass(void)
   {
/*section 2*/
    /*top part*/
    shiparray[0].v1.lx = -6.04;
    shiparray[0].v1.ly = -14;
    shiparray[0].v1.lz = 0.25;
    shiparray[0].v2.lx = -2.5;
    shiparray[0].v2.ly = -14;
    shiparray[0].v2.lz = 0.25;
    shiparray[0].v3.lx = -2.5;
    shiparray[0].v3.ly = -14;
    shiparray[0].v3.lz = 0.604;
    shiparray[1].v1.lx = -6.04;
    shiparray[1].v1.ly = -14;
    shiparray[1].v1.lz = -0.25;
    shiparray[1].v2.lx = -2.5;
    shiparray[1].v2.ly = -14;
    shiparray[1].v2.lz = -0.25;
    shiparray[1].v3.lx = -6.04;
    shiparray[1].v3.ly = -14;
    shiparray[1].v3.lz = 0.25;
    shiparray[2].v1.lx = -2.5;
    shiparray[2].v1.ly = -14;
    shiparray[2].v1.lz = -0.25;
    shiparray[2].v2.lx = -2.5;
    shiparray[2].v2.ly = -14;
    shiparray[2].v2.lz = 0.25;
    shiparray[2].v3.lx = -6.04;
    shiparray[2].v3.ly = -14;
    shiparray[2].v3.lz = 0.25;
    shiparray[3].v1.lx = -2.5;
    shiparray[3].v1.ly = -14;
    shiparray[3].v1.lz = -0.604;
    shiparray[3].v2.lx = -2.5;
    shiparray[3].v2.ly = -14;
    shiparray[3].v2.lz = -0.25;
    shiparray[3].v3.lx = -6.04;
    shiparray[3].v3.ly = -14;
    shiparray[3].v3.lz = -0.25;
    shiparray[4].v1.lx = -2.5;
    shiparray[4].v1.ly = -14;
    shiparray[4].v1.lz = 0.25;
    shiparray[4].v2.lx = 2.5;
    shiparray[4].v2.ly = -14;
    shiparray[4].v2.lz = 0.25;
    shiparray[4].v3.lx = -2.5;
    shiparray[4].v3.ly = -14;
    shiparray[4].v3.lz = 0.604;
    shiparray[5].v1.lx = 2.5;
    shiparray[5].v1.ly = -14;
    shiparray[5].v1.lz = 0.25;
    shiparray[5].v2.lx = 2.5;
    shiparray[5].v2.ly = -14;
    shiparray[5].v2.lz = 0.604;
    shiparray[5].v3.lx = -2.5;
    shiparray[5].v3.ly = -14;
    shiparray[5].v3.lz = 0.604;
    shiparray[6].v1.lx = 2.5;
    shiparray[6].v1.ly = -14;
    shiparray[6].v1.lz = -0.25;
    shiparray[6].v2.lx = -2.5;
    shiparray[6].v2.ly = -14;
    shiparray[6].v2.lz = 0.25;
    shiparray[6].v3.lx = -2.5;
    shiparray[6].v3.ly = -14;
    shiparray[6].v3.lz = -0.25;
    shiparray[7].v1.lx = 2.5;
    shiparray[7].v1.ly = -14;
    shiparray[7].v1.lz = -0.25;
    shiparray[7].v2.lx = 2.5;
    shiparray[7].v2.ly = -14;
    shiparray[7].v2.lz = 0.25;
    shiparray[7].v3.lx = -2.5;
    shiparray[7].v3.ly = -14;
    shiparray[7].v3.lz = 0.25;
    shiparray[8].v1.lx = 2.5;
    shiparray[8].v1.ly = -14;
    shiparray[8].v1.lz = -0.604;
    shiparray[8].v2.lx = -2.5;
    shiparray[8].v2.ly = -14;
    shiparray[8].v2.lz = -0.25;
    shiparray[8].v3.lx = -2.5;
    shiparray[8].v3.ly = -14;
    shiparray[8].v3.lz = -0.604;
    shiparray[9].v1.lx = 2.5;
    shiparray[9].v1.ly = -14;
    shiparray[9].v1.lz = -0.604;
    shiparray[9].v2.lx = 2.5;
    shiparray[9].v2.ly = -14;
    shiparray[9].v2.lz = -0.25;
    shiparray[9].v3.lx = -2.5;
    shiparray[9].v3.ly = -14;
    shiparray[9].v3.lz = -0.25;
    shiparray[10].v1.lx = 2.5;
    shiparray[10].v1.ly = -14;
    shiparray[10].v1.lz = 0.25;
    shiparray[10].v2.lx = 6.04;
    shiparray[10].v2.ly = -14;
    shiparray[10].v2.lz = 0.25;
    shiparray[10].v3.lx = 2.5;
    shiparray[10].v3.ly = -14;
    shiparray[10].v3.lz = 0.604;
    shiparray[11].v1.lx = 6.04;
    shiparray[11].v1.ly = -14;
    shiparray[11].v1.lz = -0.25;
    shiparray[11].v2.lx = 2.5;
    shiparray[11].v2.ly = -14;
    shiparray[11].v2.lz = 0.25;
    shiparray[11].v3.lx = 2.5;
    shiparray[11].v3.ly = -14;
    shiparray[11].v3.lz = -0.25;
    shiparray[12].v1.lx = 6.04;
    shiparray[12].v1.ly = -14;
    shiparray[12].v1.lz = -0.25;
    shiparray[12].v2.lx = 6.04;
    shiparray[12].v2.ly = -14;
    shiparray[12].v2.lz = 0.25;
    shiparray[12].v3.lx = 2.5;
    shiparray[12].v3.ly = -14;
    shiparray[12].v3.lz = 0.25;
    shiparray[13].v1.lx = 2.5;
    shiparray[13].v1.ly = -14;
    shiparray[13].v1.lz = -0.604;
    shiparray[13].v2.lx = 6.04;
    shiparray[13].v2.ly = -14;
    shiparray[13].v2.lz = -0.25;
    shiparray[13].v3.lx = 2.5;
    shiparray[13].v3.ly = -14;
    shiparray[13].v3.lz = -0.25;
    /*middle section*/
    shiparray[14].v1.lx = -8.45;
    shiparray[14].v1.ly = -8;
    shiparray[14].v1.lz = -0.35;
    shiparray[14].v2.lx = -6.04;
    shiparray[14].v2.ly = -14;
    shiparray[14].v2.lz = 0.25;
    shiparray[14].v3.lx = -8.45;
    shiparray[14].v3.ly = -8;
    shiparray[14].v3.lz = 0.35;
    shiparray[15].v1.lx = -8.45;
    shiparray[15].v1.ly = -8;
    shiparray[15].v1.lz = -0.35;
    shiparray[15].v2.lx = -6.04;
    shiparray[15].v2.ly = -14;
    shiparray[15].v2.lz = -0.25;
    shiparray[15].v3.lx = -6.04;
    shiparray[15].v3.ly = -14;
    shiparray[15].v3.lz = 0.25;
    shiparray[16].v1.lx = -3.5;
    shiparray[16].v1.ly = -8;
    shiparray[16].v1.lz = -0.845;
    shiparray[16].v2.lx = -6.04;
    shiparray[16].v2.ly = -14;
    shiparray[16].v2.lz = -0.25;
    shiparray[16].v3.lx = -8.45;
    shiparray[16].v3.ly = -8;
    shiparray[16].v3.lz = -0.35;
    shiparray[17].v1.lx = -3.5;
    shiparray[17].v1.ly = -8;
    shiparray[17].v1.lz = -0.845;
    shiparray[17].v2.lx = -2.5;
    shiparray[17].v2.ly = -14;
    shiparray[17].v2.lz = -0.604;
    shiparray[17].v3.lx = -6.04;
    shiparray[17].v3.ly = -14;
    shiparray[17].v3.lz = -0.25;
    shiparray[18].v1.lx = 3.5;
    shiparray[18].v1.ly = -8;
    shiparray[18].v1.lz = -0.845;
    shiparray[18].v2.lx = -2.5;
    shiparray[18].v2.ly = -14;
    shiparray[18].v2.lz = -0.604;
    shiparray[18].v3.lx = -3.5;
    shiparray[18].v3.ly = -8;
    shiparray[18].v3.lz = -0.845;
    shiparray[19].v1.lx = 3.5;
    shiparray[19].v1.ly = -8;
    shiparray[19].v1.lz = -0.845;
    shiparray[19].v2.lx = 2.5;
    shiparray[19].v2.ly = -14;
    shiparray[19].v2.lz = -0.604;
    shiparray[19].v3.lx = -2.5;
    shiparray[19].v3.ly = -14;
    shiparray[19].v3.lz = -0.604;
    shiparray[20].v1.lx = 8.45;
    shiparray[20].v1.ly = -8;
    shiparray[20].v1.lz = -0.35;
    shiparray[20].v2.lx = 2.5;
    shiparray[20].v2.ly = -14;
    shiparray[20].v2.lz = -0.604;
    shiparray[20].v3.lx = 3.5;
    shiparray[20].v3.ly = -8;
    shiparray[20].v3.lz = -0.845;
    shiparray[21].v1.lx = 8.45;
    shiparray[21].v1.ly = -8;
    shiparray[21].v1.lz = -0.35;
    shiparray[21].v2.lx = 6.04;
    shiparray[21].v2.ly = -14;
    shiparray[21].v2.lz = -0.25;
    shiparray[21].v3.lx = 2.5;
    shiparray[21].v3.ly = -14;
    shiparray[21].v3.lz = -0.604;
    shiparray[22].v1.lx = 8.45;
    shiparray[22].v1.ly = -8;
    shiparray[22].v1.lz = 0.35;
    shiparray[22].v2.lx = 6.04;
    shiparray[22].v2.ly = -14;
    shiparray[22].v2.lz = -0.25;
    shiparray[22].v3.lx = 8.45;
    shiparray[22].v3.ly = -8;
    shiparray[22].v3.lz = -0.35;
    shiparray[23].v1.lx = 8.45;
    shiparray[23].v1.ly = -8;
    shiparray[23].v1.lz = 0.35;
    shiparray[23].v2.lx = 6.04;
    shiparray[23].v2.ly = -14;
    shiparray[23].v2.lz = 0.25;
    shiparray[23].v3.lx = 6.04;
    shiparray[23].v3.ly = -14;
    shiparray[23].v3.lz = -0.25;
    /*bottom section*/
    shiparray[24].v1.lx = -6.04;
    shiparray[24].v1.ly = -2;
    shiparray[24].v1.lz = -0.25;
    shiparray[24].v2.lx = -8.45;
    shiparray[24].v2.ly = -8;
    shiparray[24].v2.lz = 0.35;
    shiparray[24].v3.lx = -6.04;
    shiparray[24].v3.ly = -2;
    shiparray[24].v3.lz = 0.25;
    shiparray[25].v1.lx = -6.04;
    shiparray[25].v1.ly = -2;
    shiparray[25].v1.lz = -0.25;
    shiparray[25].v2.lx = -8.45;
    shiparray[25].v2.ly = -8;
    shiparray[25].v2.lz = -0.35;
    shiparray[25].v3.lx = -8.45;
    shiparray[25].v3.ly = -8;
    shiparray[25].v3.lz = 0.35;
    shiparray[26].v1.lx = -2.5;
    shiparray[26].v1.ly = -2;
    shiparray[26].v1.lz = -0.604;
    shiparray[26].v2.lx = -8.45;
    shiparray[26].v2.ly = -8;
    shiparray[26].v2.lz = -0.35;
    shiparray[26].v3.lx = -6.04;
    shiparray[26].v3.ly = -2;
    shiparray[26].v3.lz = -0.25;
    shiparray[27].v1.lx = -2.5;
    shiparray[27].v1.ly = -2;
    shiparray[27].v1.lz = -0.604;
    shiparray[27].v2.lx = -3.5;
    shiparray[27].v2.ly = -8;
    shiparray[27].v2.lz = -0.845;
    shiparray[27].v3.lx = -8.45;
    shiparray[27].v3.ly = -8;
    shiparray[27].v3.lz = -0.35;
    shiparray[28].v1.lx = 2.5;
    shiparray[28].v1.ly = -2;
    shiparray[28].v1.lz = -0.604;
    shiparray[28].v2.lx = -3.5;
    shiparray[28].v2.ly = -8;
    shiparray[28].v2.lz = -0.845;
    shiparray[28].v3.lx = -2.5;
    shiparray[28].v3.ly = -2;
    shiparray[28].v3.lz = -0.604;
    shiparray[29].v1.lx = 2.5;
    shiparray[29].v1.ly = -2;
    shiparray[29].v1.lz = -0.604;
    shiparray[29].v2.lx = 3.5;
    shiparray[29].v2.ly = -8;
    shiparray[29].v2.lz = -0.845;
    shiparray[29].v3.lx = -3.5;
    shiparray[29].v3.ly = -8;
    shiparray[29].v3.lz = -0.845;
    shiparray[30].v1.lx = 6.04;
    shiparray[30].v1.ly = -2;
    shiparray[30].v1.lz = -0.25;
    shiparray[30].v2.lx = 3.5;
    shiparray[30].v2.ly = -8;
    shiparray[30].v2.lz = -0.845;
    shiparray[30].v3.lx = 2.5;
    shiparray[30].v3.ly = -2;
    shiparray[30].v3.lz = -0.604;
    shiparray[31].v1.lx = 6.04;
    shiparray[31].v1.ly = -2;
    shiparray[31].v1.lz = -0.25;
    shiparray[31].v2.lx = 8.45;
    shiparray[31].v2.ly = -8;
    shiparray[31].v2.lz = -0.35;
    shiparray[31].v3.lx = 3.5;
    shiparray[31].v3.ly = -8;
    shiparray[31].v3.lz = -0.845;
    shiparray[32].v1.lx = 6.04;
    shiparray[32].v1.ly = -2;
    shiparray[32].v1.lz = 0.25;
    shiparray[32].v2.lx = 8.45;
    shiparray[32].v2.ly = -8;
    shiparray[32].v2.lz = -0.35;
    shiparray[32].v3.lx = 6.04;
    shiparray[32].v3.ly = -2;
    shiparray[32].v3.lz = -0.25;
    shiparray[33].v1.lx = 6.04;
    shiparray[33].v1.ly = -2;
    shiparray[33].v1.lz = 0.25;
    shiparray[33].v2.lx = 8.45;
    shiparray[33].v2.ly = -8;
    shiparray[33].v2.lz = 0.35;
    shiparray[33].v3.lx = 8.45;
    shiparray[33].v3.ly = -8;
    shiparray[33].v3.lz = -0.35;
/*section 1*/
    /*top section*/
    shiparray[34].v1.lx = -9.66;
    shiparray[34].v1.ly = -2;
    shiparray[34].v1.lz = 0.4;
    shiparray[34].v2.lx = -4;
    shiparray[34].v2.ly = -2;
    shiparray[34].v2.lz = 0.4;
    shiparray[34].v3.lx = -4;
    shiparray[34].v3.ly = -2;
    shiparray[34].v3.lz = 0.966;
    shiparray[35].v1.lx = -9.66;
    shiparray[35].v1.ly = -2;
    shiparray[35].v1.lz = -0.4;
    shiparray[35].v2.lx = -4;
    shiparray[35].v2.ly = -2;
    shiparray[35].v2.lz = -0.4;
    shiparray[35].v3.lx = -9.66;
    shiparray[35].v3.ly = -2;
    shiparray[35].v3.lz = 0.4;
    shiparray[36].v1.lx = -4;
    shiparray[36].v1.ly = -2;
    shiparray[36].v1.lz = -0.4;
    shiparray[36].v2.lx = -4;
    shiparray[36].v2.ly = -2;
    shiparray[36].v2.lz = 0.4;
    shiparray[36].v3.lx = -9.66;
    shiparray[36].v3.ly = -2;
    shiparray[36].v3.lz = 0.4;
    shiparray[37].v1.lx = -4;
    shiparray[37].v1.ly = -2;
    shiparray[37].v1.lz = -0.966;
    shiparray[37].v2.lx = -4;
    shiparray[37].v2.ly = -2;
    shiparray[37].v2.lz = -0.4;
    shiparray[37].v3.lx = -9.66;
    shiparray[37].v3.ly = -2;
    shiparray[37].v3.lz = -0.4;
    shiparray[38].v1.lx = -4;
    shiparray[38].v1.ly = -2;
    shiparray[38].v1.lz = 0.4;
    shiparray[38].v2.lx = 4;
    shiparray[38].v2.ly = -2;
    shiparray[38].v2.lz = 0.4;
    shiparray[38].v3.lx = -4;
    shiparray[38].v3.ly = -2;
    shiparray[38].v3.lz = 0.966;
    shiparray[39].v1.lx = 4;
    shiparray[39].v1.ly = -2;
    shiparray[39].v1.lz = 0.4;
    shiparray[39].v2.lx = 4;
    shiparray[39].v2.ly = -2;
    shiparray[39].v2.lz = 0.966;
    shiparray[39].v3.lx = -4;
    shiparray[39].v3.ly = -2;
    shiparray[39].v3.lz = 0.966;
    shiparray[40].v1.lx = 4;
    shiparray[40].v1.ly = -2;
    shiparray[40].v1.lz = -0.4;
    shiparray[40].v2.lx = -4;
    shiparray[40].v2.ly = -2;
    shiparray[40].v2.lz = 0.4;
    shiparray[40].v3.lx = -4;
    shiparray[40].v3.ly = -2;
    shiparray[40].v3.lz = -0.4;
    shiparray[41].v1.lx = 4;
    shiparray[41].v1.ly = -2;
    shiparray[41].v1.lz = -0.4;
    shiparray[41].v2.lx = 4;
    shiparray[41].v2.ly = -2;
    shiparray[41].v2.lz = 0.4;
    shiparray[41].v3.lx = -4;
    shiparray[41].v3.ly = -2;
    shiparray[41].v3.lz = 0.4;
    shiparray[42].v1.lx = 4;
    shiparray[42].v1.ly = -2;
    shiparray[42].v1.lz = -0.966;
    shiparray[42].v2.lx = -4;
    shiparray[42].v2.ly = -2;
    shiparray[42].v2.lz = -0.4;
    shiparray[42].v3.lx = -4;
    shiparray[42].v3.ly = -2;
    shiparray[42].v3.lz = -0.966;
    shiparray[43].v1.lx = 4;
    shiparray[43].v1.ly = -2;
    shiparray[43].v1.lz = -0.966;
    shiparray[43].v2.lx = 4;
    shiparray[43].v2.ly = -2;
    shiparray[43].v2.lz = -0.4;
    shiparray[43].v3.lx = -4;
    shiparray[43].v3.ly = -2;
    shiparray[43].v3.lz = -0.4;
    shiparray[44].v1.lx = 4;
    shiparray[44].v1.ly = -2;
    shiparray[44].v1.lz = 0.4;
    shiparray[44].v2.lx = 9.66;
    shiparray[44].v2.ly = -2;
    shiparray[44].v2.lz = 0.4;
    shiparray[44].v3.lx = 4;
    shiparray[44].v3.ly = -2;
    shiparray[44].v3.lz = 0.966;
    shiparray[45].v1.lx = 9.66;
    shiparray[45].v1.ly = -2;
    shiparray[45].v1.lz = -0.4;
    shiparray[45].v2.lx = 4;
    shiparray[45].v2.ly = -2;
    shiparray[45].v2.lz = 0.4;
    shiparray[45].v3.lx = 4;
    shiparray[45].v3.ly = -2;
    shiparray[45].v3.lz = -0.4;
    shiparray[46].v1.lx = 9.66;
    shiparray[46].v1.ly = -2;
    shiparray[46].v1.lz = -0.4;
    shiparray[46].v2.lx = 9.66;
    shiparray[46].v2.ly = -2;
    shiparray[46].v2.lz = 0.4;
    shiparray[46].v3.lx = 4;
    shiparray[46].v3.ly = -2;
    shiparray[46].v3.lz = 0.4;
    shiparray[47].v1.lx = 4;
    shiparray[47].v1.ly = -2;
    shiparray[47].v1.lz = -0.966;
    shiparray[47].v2.lx = 9.66;
    shiparray[47].v2.ly = -2;
    shiparray[47].v2.lz = -0.4;
    shiparray[47].v3.lx = 4;
    shiparray[47].v3.ly = -2;
    shiparray[47].v3.lz = -0.4;
    /*middle section*/
    shiparray[48].v1.lx = -9.66;
    shiparray[48].v1.ly = 2;
    shiparray[48].v1.lz = -0.4;
    shiparray[48].v2.lx = -9.66;
    shiparray[48].v2.ly = -2;
    shiparray[48].v2.lz = 0.4;
    shiparray[48].v3.lx = -9.66;
    shiparray[48].v3.ly = 2;
    shiparray[48].v3.lz = 0.4;
    shiparray[49].v1.lx = -9.66;
    shiparray[49].v1.ly = 2;
    shiparray[49].v1.lz = -0.4;
    shiparray[49].v2.lx = -9.66;
    shiparray[49].v2.ly = -2;
    shiparray[49].v2.lz = -0.4;
    shiparray[49].v3.lx = -9.66;
    shiparray[49].v3.ly = -2;
    shiparray[49].v3.lz = 0.4;
    shiparray[50].v1.lx = -4;
    shiparray[50].v1.ly = 2;
    shiparray[50].v1.lz = -0.966;
    shiparray[50].v2.lx = -9.66;
    shiparray[50].v2.ly = -2;
    shiparray[50].v2.lz = -0.4;
    shiparray[50].v3.lx = -9.66;
    shiparray[50].v3.ly = 2;
    shiparray[50].v3.lz = -0.4;
    shiparray[51].v1.lx = -4;
    shiparray[51].v1.ly = 2;
    shiparray[51].v1.lz = -0.966;
    shiparray[51].v2.lx = -4;
    shiparray[51].v2.ly = -2;
    shiparray[51].v2.lz = -0.966;
    shiparray[51].v3.lx = -9.66;
    shiparray[51].v3.ly = -2;
    shiparray[51].v3.lz = -0.4;
    shiparray[52].v1.lx = 4;
    shiparray[52].v1.ly = 2;
    shiparray[52].v1.lz = -0.966;
    shiparray[52].v2.lx = -4;
    shiparray[52].v2.ly = -2;
    shiparray[52].v2.lz = -0.966;
    shiparray[52].v3.lx = -4;
    shiparray[52].v3.ly = 2;
    shiparray[52].v3.lz = -0.966;
    shiparray[53].v1.lx = 4;
    shiparray[53].v1.ly = 2;
    shiparray[53].v1.lz = -0.966;
    shiparray[53].v2.lx = 4;
    shiparray[53].v2.ly = -2;
    shiparray[53].v2.lz = -0.966;
    shiparray[53].v3.lx = -4;
    shiparray[53].v3.ly = -2;
    shiparray[53].v3.lz = -0.966;
    shiparray[54].v1.lx = 9.66;
    shiparray[54].v1.ly = 2;
    shiparray[54].v1.lz = -0.4;
    shiparray[54].v2.lx = 4;
    shiparray[54].v2.ly = -2;
    shiparray[54].v2.lz = -0.966;
    shiparray[54].v3.lx = 4;
    shiparray[54].v3.ly = 2;
    shiparray[54].v3.lz = -0.966;
    shiparray[55].v1.lx = 9.66;
    shiparray[55].v1.ly = 2;
    shiparray[55].v1.lz = -0.4;
    shiparray[55].v2.lx = 9.66;
    shiparray[55].v2.ly = -2;
    shiparray[55].v2.lz = -0.4;
    shiparray[55].v3.lx = 4;
    shiparray[55].v3.ly = -2;
    shiparray[55].v3.lz = -0.966;
    shiparray[56].v1.lx = 9.66;
    shiparray[56].v1.ly = 2;
    shiparray[56].v1.lz = 0.4;
    shiparray[56].v2.lx = 9.66;
    shiparray[56].v2.ly = -2;
    shiparray[56].v2.lz = -0.4;
    shiparray[56].v3.lx = 9.66;
    shiparray[56].v3.ly = 2;
    shiparray[56].v3.lz = -0.4;
    shiparray[57].v1.lx = 9.66;
    shiparray[57].v1.ly = 2;
    shiparray[57].v1.lz = 0.4;
    shiparray[57].v2.lx = 9.66;
    shiparray[57].v2.ly = -2;
    shiparray[57].v2.lz = 0.4;
    shiparray[57].v3.lx = 9.66;
    shiparray[57].v3.ly = -2;
    shiparray[57].v3.lz = -0.4;
    /*bottom section*/
    shiparray[58].v1.lx = -9.66;
    shiparray[58].v1.ly = 2;
    shiparray[58].v1.lz = 0.4;
    shiparray[58].v3.lx = -4;
    shiparray[58].v3.ly = 2;
    shiparray[58].v3.lz = 0.4;
    shiparray[58].v2.lx = -4;
    shiparray[58].v2.ly = 2;
    shiparray[58].v2.lz = 0.966;
    shiparray[59].v1.lx = -9.66;
    shiparray[59].v1.ly = 2;
    shiparray[59].v1.lz = -0.4;
    shiparray[59].v3.lx = -4;
    shiparray[59].v3.ly = 2;
    shiparray[59].v3.lz = -0.4;
    shiparray[59].v2.lx = -9.66;
    shiparray[59].v2.ly = 2;
    shiparray[59].v2.lz = 0.4;
    shiparray[60].v1.lx = -4;
    shiparray[60].v1.ly = 2;
    shiparray[60].v1.lz = -0.4;
    shiparray[60].v3.lx = -4;
    shiparray[60].v3.ly = 2;
    shiparray[60].v3.lz = 0.4;
    shiparray[60].v2.lx = -9.66;
    shiparray[60].v2.ly = 2;
    shiparray[60].v2.lz = 0.4;
    shiparray[61].v1.lx = -4;
    shiparray[61].v1.ly = 2;
    shiparray[61].v1.lz = -0.966;
    shiparray[61].v3.lx = -4;
    shiparray[61].v3.ly = 2;
    shiparray[61].v3.lz = -0.4;
    shiparray[61].v2.lx = -9.66;
    shiparray[61].v2.ly = 2;
    shiparray[61].v2.lz = -0.4;
    shiparray[62].v1.lx = -4;
    shiparray[62].v1.ly = 2;
    shiparray[62].v1.lz = 0.4;
    shiparray[62].v3.lx = 4;
    shiparray[62].v3.ly = 2;
    shiparray[62].v3.lz = 0.4;
    shiparray[62].v2.lx = -4;
    shiparray[62].v2.ly = 2;
    shiparray[62].v2.lz = 0.966;
    shiparray[63].v1.lx = 4;
    shiparray[63].v1.ly = 2;
    shiparray[63].v1.lz = 0.4;
    shiparray[63].v3.lx = 4;
    shiparray[63].v3.ly = 2;
    shiparray[63].v3.lz = 0.966;
    shiparray[63].v2.lx = -4;
    shiparray[63].v2.ly = 2;
    shiparray[63].v2.lz = 0.966;
    shiparray[64].v1.lx = 4;
    shiparray[64].v1.ly = 2;
    shiparray[64].v1.lz = -0.4;
    shiparray[64].v3.lx = -4;
    shiparray[64].v3.ly = 2;
    shiparray[64].v3.lz = 0.4;
    shiparray[64].v2.lx = -4;
    shiparray[64].v2.ly = 2;
    shiparray[64].v2.lz = -0.4;
    shiparray[65].v1.lx = 4;
    shiparray[65].v1.ly = 2;
    shiparray[65].v1.lz = -0.4;
    shiparray[65].v3.lx = 4;
    shiparray[65].v3.ly = 2;
    shiparray[65].v3.lz = 0.4;
    shiparray[65].v2.lx = -4;
    shiparray[65].v2.ly = 2;
    shiparray[65].v2.lz = 0.4;
    shiparray[66].v1.lx = 4;
    shiparray[66].v1.ly = 2;
    shiparray[66].v1.lz = -0.966;
    shiparray[66].v3.lx = -4;
    shiparray[66].v3.ly = 2;
    shiparray[66].v3.lz = -0.4;
    shiparray[66].v2.lx = -4;
    shiparray[66].v2.ly = 2;
    shiparray[66].v2.lz = -0.966;
    shiparray[67].v1.lx = 4;
    shiparray[67].v1.ly = 2;
    shiparray[67].v1.lz = -0.966;
    shiparray[67].v3.lx = 4;
    shiparray[67].v3.ly = 2;
    shiparray[67].v3.lz = -0.4;
    shiparray[67].v2.lx = -4;
    shiparray[67].v2.ly = 2;
    shiparray[67].v2.lz = -0.4;
    shiparray[68].v1.lx = 4;
    shiparray[68].v1.ly = 2;
    shiparray[68].v1.lz = 0.4;
    shiparray[68].v3.lx = 9.66;
    shiparray[68].v3.ly = 2;
    shiparray[68].v3.lz = 0.4;
    shiparray[68].v2.lx = 4;
    shiparray[68].v2.ly = 2;
    shiparray[68].v2.lz = 0.966;
    shiparray[69].v1.lx = 9.66;
    shiparray[69].v1.ly = 2;
    shiparray[69].v1.lz = -0.4;
    shiparray[69].v3.lx = 4;
    shiparray[69].v3.ly = 2;
    shiparray[69].v3.lz = 0.4;
    shiparray[69].v2.lx = 4;
    shiparray[69].v2.ly = 2;
    shiparray[69].v2.lz = -0.4;
    shiparray[70].v1.lx = 9.66;
    shiparray[70].v1.ly = 2;
    shiparray[70].v1.lz = -0.4;
    shiparray[70].v3.lx = 9.66;
    shiparray[70].v3.ly = 2;
    shiparray[70].v3.lz = 0.4;
    shiparray[70].v2.lx = 4;
    shiparray[70].v2.ly = 2;
    shiparray[70].v2.lz = 0.4;
    shiparray[71].v1.lx = 4;
    shiparray[71].v1.ly = 2;
    shiparray[71].v1.lz = -0.966;
    shiparray[71].v3.lx = 9.66;
    shiparray[71].v3.ly = 2;
    shiparray[71].v3.lz = -0.4;
    shiparray[71].v2.lx = 4;
    shiparray[71].v2.ly = 2;
    shiparray[71].v2.lz = -0.4;
/*legs*/
    /*front left leg*/
    shiparray[72].v1.lx = -10.218;
    shiparray[72].v1.ly = 12;
    shiparray[72].v1.lz = -1.128;
    shiparray[72].v2.lx = -4;
    shiparray[72].v2.ly = -2;
    shiparray[72].v2.lz = -0.966;
    shiparray[72].v3.lx = -11.278;
    shiparray[72].v3.ly = 12;
    shiparray[72].v3.lz = -1.234;
    shiparray[73].v1.lx = -10.218;
    shiparray[73].v1.ly = 12;
    shiparray[73].v1.lz = -1.128;
    shiparray[73].v2.lx = -4;
    shiparray[73].v2.ly = 2;
    shiparray[73].v2.lz = -0.966;
    shiparray[73].v3.lx = -4;
    shiparray[73].v3.ly = -2;
    shiparray[73].v3.lz = -0.966;
    shiparray[74].v1.lx = -11.278;
    shiparray[74].v1.ly = 12;
    shiparray[74].v1.lz = -1.234;
    shiparray[74].v2.lx = -9.66;
    shiparray[74].v2.ly = -2;
    shiparray[74].v2.lz = -0.4;
    shiparray[74].v3.lx = -12.339;
    shiparray[74].v3.ly = 12;
    shiparray[74].v3.lz = -1.128;
    shiparray[75].v1.lx = -11.278;
    shiparray[75].v1.ly = 12;
    shiparray[75].v1.lz = -1.234;
    shiparray[75].v2.lx = -4;
    shiparray[75].v2.ly = -2;
    shiparray[75].v2.lz = -0.966;
    shiparray[75].v3.lx = -9.66;
    shiparray[75].v3.ly = -2;
    shiparray[75].v3.lz = -0.4;
/*    shiparray[76].v1.lx = -10.218;
    shiparray[76].v1.ly = 12;
    shiparray[76].v1.lz = -1.128;
    shiparray[76].v2.lx = -9.66;
    shiparray[76].v2.ly = 2;
    shiparray[76].v2.lz = -0.4;
    shiparray[76].v3.lx = -4;
    shiparray[76].v3.ly = 2;
    shiparray[76].v3.lz = -0.966;
    shiparray[77].v1.lx = -10.218;
    shiparray[77].v1.ly = 12;
    shiparray[77].v1.lz = -1.128;
    shiparray[77].v2.lx = -11.278;
    shiparray[77].v2.ly = 12;
    shiparray[77].v2.lz = -1.022;
    shiparray[77].v3.lx = -9.66;
    shiparray[77].v3.ly = 2;
    shiparray[77].v3.lz = -0.4;
*/    /*top foot left front*/
    shiparray[76].v1.lx = -13.278;
    shiparray[76].v1.ly = 12;
    shiparray[76].v1.lz = -0.928;
    shiparray[76].v2.lx = -13.278;
    shiparray[76].v2.ly = 12;
    shiparray[76].v2.lz = -1.328;
    shiparray[76].v3.lx = -9.278;
    shiparray[76].v3.ly = 12;
    shiparray[76].v3.lz = -1.328;
    shiparray[77].v1.lx = -13.278;
    shiparray[77].v1.ly = 12;
    shiparray[77].v1.lz = -0.928;
    shiparray[77].v2.lx = -9.278;
    shiparray[77].v2.ly = 12;
    shiparray[77].v2.lz = -1.328;
    shiparray[77].v3.lx = -9.278;
    shiparray[77].v3.ly = 12;
    shiparray[77].v3.lz = -0.928;
    shiparray[78].v1.lx = -13.278;
    shiparray[78].v1.ly = 12.001;
    shiparray[78].v1.lz = -0.928;
    shiparray[78].v3.lx = -13.278;
    shiparray[78].v3.ly = 12.001;
    shiparray[78].v3.lz = -1.328;
    shiparray[78].v2.lx = -9.278;
    shiparray[78].v2.ly = 12.001;
    shiparray[78].v2.lz = -1.328;
    shiparray[79].v1.lx = -13.278;
    shiparray[79].v1.ly = 12.001;
    shiparray[79].v1.lz = -0.928;
    shiparray[79].v3.lx = -9.278;
    shiparray[79].v3.ly = 12.001;
    shiparray[79].v3.lz = -1.328;
    shiparray[79].v2.lx = -9.278;
    shiparray[79].v2.ly = 12.001;
    shiparray[79].v2.lz = -0.928;

    /*rear left leg*/
    shiparray[80].v1.lx = -11.28;
    shiparray[80].v1.ly = 12;
    shiparray[80].v1.lz = 1.022;
    shiparray[80].v2.lx = -9.66;
    shiparray[80].v2.ly = -2;
    shiparray[80].v2.lz = 0.4;
    shiparray[80].v3.lx = -12.34;
    shiparray[80].v3.ly = 12;
    shiparray[80].v3.lz = 1.128;
    shiparray[81].v1.lx = -11.28;
    shiparray[81].v1.ly = 12;
    shiparray[81].v1.lz = 1.022;
    shiparray[81].v2.lx = -9.66;
    shiparray[81].v2.ly = 2;
    shiparray[81].v2.lz = 0.4;
    shiparray[81].v3.lx = -9.66;
    shiparray[81].v3.ly = -2;
    shiparray[81].v3.lz = 0.4;
    shiparray[82].v1.lx = -11.28;
    shiparray[82].v1.ly = 12;
    shiparray[82].v1.lz = 1.022;
    shiparray[82].v2.lx = -10.22;
    shiparray[82].v2.ly = 12;
    shiparray[82].v2.lz = 1.128;
    shiparray[82].v3.lx = -4;
    shiparray[82].v3.ly = 2;
    shiparray[82].v3.lz = 0.966;
    shiparray[83].v1.lx = -11.28;
    shiparray[83].v1.ly = 12;
    shiparray[83].v1.lz = 1.022;
    shiparray[83].v2.lx = -4;
    shiparray[83].v2.ly = 2;
    shiparray[83].v2.lz = 0.966;
    shiparray[83].v3.lx = -9.66;
    shiparray[83].v3.ly = 2;
    shiparray[83].v3.lz = 0.4;
    /*foot left rear*/
    shiparray[84].v1.lx = -9.28;
    shiparray[84].v1.ly = 12;
    shiparray[84].v1.lz = 1.328;
    shiparray[84].v2.lx = -13.278;
    shiparray[84].v2.ly = 12;
    shiparray[84].v2.lz = 1.328;
    shiparray[84].v3.lx = -13.28;
    shiparray[84].v3.ly = 12;
    shiparray[84].v3.lz = 0.928;
    shiparray[85].v1.lx = -9.28;
    shiparray[85].v1.ly = 12;
    shiparray[85].v1.lz = 1.328;
    shiparray[85].v2.lx = -13.28;
    shiparray[85].v2.ly = 12;
    shiparray[85].v2.lz = 0.928;
    shiparray[85].v3.lx = -9.28;
    shiparray[85].v3.ly = 12;
    shiparray[85].v3.lz = 0.928;
    shiparray[86].v1.lx = -9.28;
    shiparray[86].v1.ly = 12.001;
    shiparray[86].v1.lz = 1.328;
    shiparray[86].v3.lx = -13.278;
    shiparray[86].v3.ly = 12.001;
    shiparray[86].v3.lz = 1.328;
    shiparray[86].v2.lx = -13.28;
    shiparray[86].v2.ly = 12.001;
    shiparray[86].v2.lz = 0.928;
    shiparray[87].v1.lx = -9.28;
    shiparray[87].v1.ly = 12.001;
    shiparray[87].v1.lz = 1.328;
    shiparray[87].v3.lx = -13.28;
    shiparray[87].v3.ly = 12.001;
    shiparray[87].v3.lz = 0.928;
    shiparray[87].v2.lx = -9.28;
    shiparray[87].v2.ly = 12.001;
    shiparray[87].v2.lz = 0.928;


    /*rear right leg*/
    shiparray[88].v1.lx = 11.278;
    shiparray[88].v1.ly = 12;
    shiparray[88].v1.lz = 1.022;
    shiparray[88].v2.lx = 12.34;
    shiparray[88].v2.ly = 12;
    shiparray[88].v2.lz = 1.128;
    shiparray[88].v3.lx = 9.66;
    shiparray[88].v3.ly = 2;
    shiparray[88].v3.lz = 0.4;
    shiparray[89].v1.lx = 12.34;
    shiparray[89].v1.ly = 12;
    shiparray[89].v1.lz = 1.128;
    shiparray[89].v2.lx = 9.66;
    shiparray[89].v2.ly = -2;
    shiparray[89].v2.lz = 0.4;
    shiparray[89].v3.lx = 9.66;
    shiparray[89].v3.ly = 2;
    shiparray[89].v3.lz = 0.4;
    shiparray[90].v1.lx = 10.22;
    shiparray[90].v1.ly = 12;
    shiparray[90].v1.lz = 1.128;
    shiparray[90].v2.lx = 11.28;
    shiparray[90].v2.ly = 12;
    shiparray[90].v2.lz = 1.022;
    shiparray[90].v3.lx = 9.66;
    shiparray[90].v3.ly = 2;
    shiparray[90].v3.lz = 0.4;
    shiparray[91].v1.lx = 10.22;
    shiparray[91].v1.ly = 12;
    shiparray[91].v1.lz = 1.128;
    shiparray[91].v2.lx = 9.66;
    shiparray[91].v2.ly = 2;
    shiparray[91].v2.lz = 0.4;
    shiparray[91].v3.lx = 4.;
    shiparray[91].v3.ly = 2;
    shiparray[91].v3.lz = 0.966;
    /*foot right rear*/
    shiparray[92].v1.lx = 9.28;
    shiparray[92].v1.ly = 12;
    shiparray[92].v1.lz = 1.328;
    shiparray[92].v2.lx = 13.278;
    shiparray[92].v2.ly = 12;
    shiparray[92].v2.lz = 1.328;
    shiparray[92].v3.lx = 13.28;
    shiparray[92].v3.ly = 12;
    shiparray[92].v3.lz = 0.928;
    shiparray[93].v1.lx = 9.28;
    shiparray[93].v1.ly = 12;
    shiparray[93].v1.lz = 1.328;
    shiparray[93].v2.lx = 13.28;
    shiparray[93].v2.ly = 12;
    shiparray[93].v2.lz = 0.928;
    shiparray[93].v3.lx = 9.28;
    shiparray[93].v3.ly = 12;
    shiparray[93].v3.lz = 0.928;
    shiparray[94].v1.lx = 9.28;
    shiparray[94].v1.ly = 12.001;
    shiparray[94].v1.lz = 1.328;
    shiparray[94].v3.lx = 13.278;
    shiparray[94].v3.ly = 12.001;
    shiparray[94].v3.lz = 1.328;
    shiparray[94].v2.lx = 13.28;
    shiparray[94].v2.ly = 12.001;
    shiparray[94].v2.lz = 0.928;
    shiparray[95].v1.lx = 9.28;
    shiparray[95].v1.ly = 12.001;
    shiparray[95].v1.lz = 1.328;
    shiparray[95].v3.lx = 13.28;
    shiparray[95].v3.ly = 12.001;
    shiparray[95].v3.lz = 0.928;
    shiparray[95].v2.lx = 9.28;
    shiparray[95].v2.ly = 12.001;
    shiparray[95].v2.lz = 0.928;

/*front right leg*/
    shiparray[96].v1.lx = 11.28;
    shiparray[96].v1.ly = 12;
    shiparray[96].v1.lz = -1.234;
    shiparray[96].v2.lx = 4;
    shiparray[96].v2.ly = -2;
    shiparray[96].v2.lz = -0.966;
    shiparray[96].v3.lx = 4;
    shiparray[96].v3.ly = 2;
    shiparray[96].v3.lz = -0.966;
    shiparray[97].v1.lx = 11.278;
    shiparray[97].v1.ly = 12;
    shiparray[97].v1.lz = -1.234;
    shiparray[97].v2.lx = 4;
    shiparray[97].v2.ly = 2;
    shiparray[97].v2.lz = -0.966;
    shiparray[97].v3.lx = 10.218;
    shiparray[97].v3.ly = 12;
    shiparray[97].v3.lz = -1.128;
    shiparray[98].v1.lx = 12.339;
    shiparray[98].v1.ly = 12;
    shiparray[98].v1.lz = -1.128;
    shiparray[98].v2.lx = 9.66;
    shiparray[98].v2.ly = -2;
    shiparray[98].v2.lz = -0.4;
    shiparray[98].v3.lx = 4;
    shiparray[98].v3.ly = -2;
    shiparray[98].v3.lz = -0.966;
    shiparray[99].v1.lx = 12.339;
    shiparray[99].v1.ly = 12;
    shiparray[99].v1.lz = -1.128;
    shiparray[99].v2.lx = 4;
    shiparray[99].v2.ly = -2;
    shiparray[99].v2.lz = -0.966;
    shiparray[99].v3.lx = 11.28;
    shiparray[99].v3.ly = 12;
    shiparray[99].v3.lz = -1.234;
    /*foot right front*/
    shiparray[100].v1.lx = 9.28;
    shiparray[100].v1.ly = 12;
    shiparray[100].v1.lz = -1.328;
    shiparray[100].v2.lx = 13.278;
    shiparray[100].v2.ly = 12;
    shiparray[100].v2.lz = -1.328;
    shiparray[100].v3.lx = 13.28;
    shiparray[100].v3.ly = 12;
    shiparray[100].v3.lz = -0.928;
    shiparray[101].v1.lx = 9.28;
    shiparray[101].v1.ly = 12;
    shiparray[101].v1.lz = -1.328;
    shiparray[101].v2.lx = 13.28;
    shiparray[101].v2.ly = 12;
    shiparray[101].v2.lz = -0.928;
    shiparray[101].v3.lx = 9.28;
    shiparray[101].v3.ly = 12;
    shiparray[101].v3.lz = -0.928;
    shiparray[102].v1.lx = 9.28;
    shiparray[102].v1.ly = 12.001;
    shiparray[102].v1.lz = -1.328;
    shiparray[102].v3.lx = 13.278;
    shiparray[102].v3.ly = 12.001;
    shiparray[102].v3.lz = -1.328;
    shiparray[102].v2.lx = 13.28;
    shiparray[102].v2.ly = 12.001;
    shiparray[102].v2.lz = -0.928;
    shiparray[103].v1.lx = 9.28;
    shiparray[103].v1.ly = 12.001;
    shiparray[103].v1.lz = -1.328;
    shiparray[103].v3.lx = 13.28;
    shiparray[103].v3.ly = 12.001;
    shiparray[103].v3.lz = -0.928;
    shiparray[103].v2.lx = 9.28;
    shiparray[103].v2.ly = 12.001;
    shiparray[103].v2.lz = -0.928;
/*flames*/
    shiparray[104].v1.lx = -6.04;
    shiparray[104].v1.ly = 2;
    shiparray[104].v1.lz = 0.396;
    shiparray[104].v2.lx = 0.0;
    shiparray[104].v2.ly = 2;
    shiparray[104].v2.lz = 0.0;
    shiparray[104].v3.lx = -6.04;
    shiparray[104].v3.ly = 2;
    shiparray[104].v3.lz = -0.396;
    shiparray[105].v1.lx = -6.04;
    shiparray[105].v1.ly = 2;
    shiparray[105].v1.lz = -0.396;
    shiparray[105].v2.lx = 0.0;
    shiparray[105].v2.ly = 2;
    shiparray[105].v2.lz = 0.0;
    shiparray[105].v3.lx = -3.54;
    shiparray[105].v3.ly = 2;
    shiparray[105].v3.lz = -0.604;
    shiparray[106].v1.lx = -3.54;
    shiparray[106].v1.ly = 2;
    shiparray[106].v1.lz = -0.604;
    shiparray[106].v2.lx = 0.0;
    shiparray[106].v2.ly = 2;
    shiparray[106].v2.lz = 0.0;
    shiparray[106].v3.lx = 3.54;
    shiparray[106].v3.ly = 2;
    shiparray[106].v3.lz = -0.604;
    shiparray[107].v1.lx = 3.54;
    shiparray[107].v1.ly = 2;
    shiparray[107].v1.lz = -0.604;
    shiparray[107].v2.lx = 0.0;
    shiparray[107].v2.ly = 2;
    shiparray[107].v2.lz = 0.0;
    shiparray[107].v3.lx = 6.04;
    shiparray[107].v3.ly = 2;
    shiparray[107].v3.lz = -0.354;
    shiparray[108].v1.lx = 6.04;
    shiparray[108].v1.ly = 2;
    shiparray[108].v1.lz = -0.354;
    shiparray[108].v2.lx = 0.0;
    shiparray[108].v2.ly = 2;
    shiparray[108].v2.lz = 0.0;
    shiparray[108].v3.lx = 6.04;
    shiparray[108].v3.ly = 2;
    shiparray[108].v3.lz = 0.354;



    /*    shiparray[80].v1.lx = -12.485;
    shiparray[80].v1.ly = 13;
    shiparray[80].v1.lz = -1.177;
    shiparray[80].v2.lx = -10.925;
    shiparray[80].v2.ly = 12;
    shiparray[80].v2.lz = -1.233;
    shiparray[80].v3.lx = -12.339;
    shiparray[80].v3.ly = 12;
    shiparray[80].v3.lz = -1.092;
    shiparray[81].v1.lx = -10.778;
    shiparray[81].v1.ly = 13;
    shiparray[81].v1.lz = -1.249;
    shiparray[81].v2.lx = -10.925;
    shiparray[81].v2.ly = 12;
    shiparray[81].v2.lz = -1.233;
    shiparray[81].v3.lx = -11.778;
    shiparray[81].v3.ly = 13;
    shiparray[81].v3.lz = -1.248;
    shiparray[82].v1.lx = -12.339;
    shiparray[82].v1.ly = 12;
    shiparray[82].v1.lz = -1.092;
    shiparray[82].v2.lx = -11.778;
    shiparray[82].v2.ly = 13;
    shiparray[82].v2.lz = -1.007;
    shiparray[82].v3.lx = -12.485;
    shiparray[82].v3.ly = 13;
    shiparray[82].v3.lz = -1.077;
    shiparray[83].v1.lx = -12.339;
    shiparray[83].v1.ly = 12;
    shiparray[83].v1.lz = -1.092;
    shiparray[83].v2.lx = -11.632;
    shiparray[83].v2.ly = 12;
    shiparray[83].v2.lz = -1.021;
    shiparray[83].v3.lx = -11.778;
    shiparray[83].v3.ly = 13;
    shiparray[83].v3.lz = -1.007;
    shiparray[84].v1.lx = -10.778;
    shiparray[84].v1.ly = 13;
    shiparray[84].v1.lz = -1.248;
    shiparray[84].v2.lx = -10.218;
    shiparray[84].v2.ly = 12;
    shiparray[84].v2.lz = -1.163;
    shiparray[84].v3.lx = -10.925;
    shiparray[84].v3.ly = 12;
    shiparray[84].v3.lz = -1.233;
    shiparray[85].v1.lx = -10.778;
    shiparray[85].v1.ly = 13;
    shiparray[85].v1.lz = -1.248;
    shiparray[85].v2.lx = -10.071;
    shiparray[85].v2.ly = 13;
    shiparray[85].v2.lz = -1.177;
    shiparray[85].v3.lx = -10.218;
    shiparray[85].v3.ly = 12;
    shiparray[85].v3.lz = -1.163;
    shiparray[86].v1.lx = -11.632;
    shiparray[86].v1.ly = 12;
    shiparray[86].v1.lz = -1.021;
    shiparray[86].v2.lx = -10.778;
    shiparray[86].v2.ly = 13;
    shiparray[86].v2.lz = -1.007;
    shiparray[86].v3.lx = -11.778;
    shiparray[86].v3.ly = 13;
    shiparray[86].v3.lz = -1.071;
    shiparray[87].v1.lx = -10.218;
    shiparray[87].v1.ly = 12;
    shiparray[87].v1.lz = -1.163;
    shiparray[87].v2.lx = -10.778;
    shiparray[87].v2.ly = 13;
    shiparray[87].v2.lz = -1.007;
    shiparray[87].v3.lx = -11.632;
    shiparray[87].v3.ly = 12;
    shiparray[87].v3.lz = -1.021;
    shiparray[88].v1.lx = -10.218;
    shiparray[88].v1.ly = 12;
    shiparray[88].v1.lz = -1.163;
    shiparray[88].v2.lx = -10.071;
    shiparray[88].v2.ly = 13;
    shiparray[88].v2.lz = -1.077;
    shiparray[88].v3.lx = -10.778;
    shiparray[88].v3.ly = 13;
    shiparray[88].v3.lz = -1.007;
    shiparray[89].v1.lx = -10.218;
    shiparray[89].v1.ly = 12;
    shiparray[89].v1.lz = -1.163;
    shiparray[89].v2.lx = -10.071;
    shiparray[89].v2.ly = 13;
    shiparray[89].v2.lz = -1.177;
    shiparray[89].v3.lx = -10.071;
    shiparray[89].v3.ly = 13;
    shiparray[89].v3.lz = -1.077;
  */
   int a;
  for(a=104;a<109;a++)
   {
    shiparray[a].culled = false;
   }
  for(a=0;a<104;a++)
   {
    shiparray[a].color.red = 4;
    shiparray[a].color.green = 8;
    shiparray[a].color.blue = 4;

   }
    shiparray[104].color.red = 31;
    shiparray[104].color.green = 8;
    shiparray[104].color.blue = 2;
    shiparray[104].color1.red = 31;
    shiparray[104].color1.green = 0;
    shiparray[104].color1.blue = 0;
    shiparray[105].color.red = 31;
    shiparray[105].color.green = 8;
    shiparray[105].color.blue = 2;
    shiparray[105].color1.red = 31;
    shiparray[105].color1.green = 8;
    shiparray[105].color1.blue = 2;
    shiparray[106].color.red = 31;
    shiparray[106].color.green = 8;
    shiparray[106].color.blue = 2;
    shiparray[106].color1.red = 31;
    shiparray[106].color1.green = 16;
    shiparray[106].color1.blue = 4;
    shiparray[107].color.red = 31;
    shiparray[107].color.green = 8;
    shiparray[107].color.blue = 2;
    shiparray[107].color1.red = 31;
    shiparray[107].color1.green = 8;
    shiparray[107].color1.blue = 2;
    shiparray[108].color.red = 31;
    shiparray[108].color.green = 8;
    shiparray[108].color.blue = 2;
    shiparray[108].color1.red = 31;
    shiparray[108].color1.green = 0;
    shiparray[108].color1.blue = 0;
   for(a = 104;a< 109;a++)
    {
     shiparray[a].v1.inten1 = 1-(abs(106-a)/10.0);
     shiparray[a].v2.inten1 = 1-(abs(106-a)/10.0);
     shiparray[a].v3.inten1 = 1-(abs(106-a)/10.0);
    }




   calcpolynorms();
  calcvernorms();
   }

void shipclass::calcpolynorms(void)
 {
  int a;
  double temp,magnitude,v1,v2,v3,w1,w2,w3;
  for(a=0;a<109;a++)
  {
   /*calculate polygon normals*/
   v1 = shiparray[a].v2.lx - shiparray[a].v1.lx;
   v2 = shiparray[a].v2.ly - shiparray[a].v1.ly;
   v3 = shiparray[a].v2.lz - shiparray[a].v1.lz;
   w1 = shiparray[a].v3.lx - shiparray[a].v1.lx;
   w2 = shiparray[a].v3.ly - shiparray[a].v1.ly;
   w3 = shiparray[a].v3.lz - shiparray[a].v1.lz;
   shiparray[a].nxv = v2*w3 - v3*w2;
   shiparray[a].nyv = v3*w1 - v1*w3;
   shiparray[a].nzv = v1*w2 - v2*w1;
   /*calculate direction vectors*/
   magnitude = sqrt((shiparray[a].nxv*shiparray[a].nxv) + (shiparray[a].nyv*shiparray[a].nyv) + (shiparray[a].nzv*shiparray[a].nzv));
   if(magnitude == 0)
    temp = 1;
    else
    temp = 1/magnitude;
   shiparray[a].nxv = shiparray[a].nxv*temp;
   shiparray[a].nyv = shiparray[a].nyv*temp;
   shiparray[a].nzv = shiparray[a].nzv*temp;
   /*calculate midpoints*/
   shiparray[a].midx = (shiparray[a].v1.lx + shiparray[a].v2.lx + shiparray[a].v3.lx)*0.333333;
   shiparray[a].midy = (shiparray[a].v1.ly + shiparray[a].v2.ly + shiparray[a].v3.ly)*0.333333;
   shiparray[a].midz = (shiparray[a].v1.lz + shiparray[a].v2.lz + shiparray[a].v3.lz)*0.333333;

  }
 }

bool shipclass::cmpvert(vertexstruct temp1,vertexstruct temp2)
 {
  if((floor(temp1.lx*10) == floor(temp2.lx*10)) && (floor(temp1.ly*10) == floor(temp2.ly*10)) && (floor(temp1.lz*10) == floor(temp2.lz*10)))
   return true;
   else return false;
 }

void shipclass::cpyvert(vertexstruct *dest,vertexstruct src)
 {
  dest->lx = src.lx;
  dest->ly = src.ly;
  dest->lz = src.lz;

 }

void shipclass::calcvernorms()
 {
  int vertyn[104][3];
  int polyyn[104];
  int count1,count2,count3;
  vertexstruct current;
  double tempi,tempj,tempk,magnitude;
  for(count1 = 0;count1 < 104;count1++)
   {
    vertyn[count1][0] = 0;
    vertyn[count1][1] = 0;
    vertyn[count1][2] = 0;
   }
  for(;;)
   {
    for(count1 = 0;count1 < 104;count1++)
     {
      polyyn[count1] = 0;
     }
    for(count3 = 0;count3 < 104;count3++)
     {
      if(vertyn[count3][0] == 0)
       {
        count1 = count3;
        count2 = 0;
        break;
       }
      if(vertyn[count3][1] == 0)
       {
        count1 = count3;
        count2 = 1;
        break;
       }
      if(vertyn[count3][2] == 0)
       {
        count1 = count3;
        count2 = 2;
        break;
       }

   /*   for(count2 = 0;count2 < 3;count2++)
       {
        if(vertyn[count1][count2] == 0)
         {
          break;
         }
       }
      if((count2 != 3) && (vertyn[count1][count2] == 0)) break;
 */    }
    if(count3 == 104/* && count2 == 3*/) break;
    vertyn[count1][count2] = 1;
    polyyn[count1] = 1;
    if(count2 == 0) cpyvert(&current,shiparray[count1].v1);
    if(count2 == 1) cpyvert(&current,shiparray[count1].v2);
    if(count2 == 2) cpyvert(&current,shiparray[count1].v3);
    for(count1 = 0;count1 < 104;count1++)
     {
        if(cmpvert(current,shiparray[count1].v1) == true)
         {
          polyyn[count1] = 1;
         vertyn[count1][0] = 1;
         }
        if(cmpvert(current,shiparray[count1].v2) == true)
         {
          polyyn[count1] = 1;
          vertyn[count1][1] = 1;
         }
        if(cmpvert(current,shiparray[count1].v3) == true)
         {
          polyyn[count1] = 1;
          vertyn[count1][2] = 1;
         }

     }
    count3 = 0;
    tempi = 0;
    tempj = 0;
    tempk = 0;

    for(count1 = 0;count1 < 104;count1++)
     {
      if(polyyn[count1] == 1)
       {
        count3++;
        tempi += shiparray[count1].nxv;
        tempj += shiparray[count1].nyv;
        tempk += shiparray[count1].nzv;

       }
     }
    tempi /= count3;
    tempj /= count3;
    tempk /= count3;
    magnitude = sqrt(tempi*tempi + tempj*tempj + tempk*tempk);
   if(magnitude != 0)
    {
    tempi /= magnitude;
    tempj /= magnitude;
    tempk /= magnitude;
    }
    for(count1 = 0;count1 < 104;count1++)
     {
      if(vertyn[count1][0] == 1)
       {
        shiparray[count1].v1.dvx = tempi;
        shiparray[count1].v1.dvy = tempj;
        shiparray[count1].v1.dvz = tempk;
       }
      if(vertyn[count1][1] == 1)
       {
        shiparray[count1].v2.dvx = tempi;
        shiparray[count1].v2.dvy = tempj;
        shiparray[count1].v2.dvz = tempk;
       }
      if(vertyn[count1][2] == 1)
       {
        shiparray[count1].v3.dvx = tempi;
        shiparray[count1].v3.dvy = tempj;
        shiparray[count1].v3.dvz = tempk;
       }
     }
    for(count1 = 0;count1 < 104; count1++)
     {
      for(count2 = 0;count2 < 3;count2++)
       {
        if(vertyn[count1][count2] == 1)
         vertyn[count1][count2] = 2;
       }
     }

   }
 /*shiparray[1].v1.dvx = shiparray[1].v1.dvx;
 shiparray[1].v1.dvy = shiparray[1].v1.dvy;
 shiparray[1].v1.dvz = shiparray[1].v1.dvz;
 shiparray[3].v3.dvx = shiparray[3].v3.dvx;
 shiparray[3].v3.dvy = shiparray[3].v3.dvy;
 shiparray[3].v3.dvz = shiparray[3].v3.dvz;
 shiparray[15].v2.dvx = shiparray[15].v2.dvx;
 shiparray[15].v2.dvy = shiparray[15].v2.dvy;
 shiparray[15].v2.dvz = shiparray[15].v2.dvz;
 shiparray[16].v2.dvx = shiparray[16].v2.dvx;
 shiparray[16].v2.dvy = shiparray[16].v2.dvy;
 shiparray[16].v2.dvz = shiparray[16].v2.dvz;
 shiparray[17].v3.dvx = shiparray[17].v3.dvx;
 shiparray[17].v3.dvy = shiparray[17].v3.dvy;
 shiparray[17].v3.dvz = shiparray[17].v3.dvz;
*/
 }

void shipclass::calcpolylight(void)
 {
  int a;
  float view1,view2,view3,dotp,magnitude,temp;

  for(a=0;a<104;a++)
   {
    if(shiparray[a].culled == false)
    {
    view1 = 450 - /*xposition*/shiparray[a].fmidx;
    view2 = -300 - /*yposition*/shiparray[a].fmidy;
    view3 = -240 - shiparray[a].fmidz;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    if(magnitude == 0)
      temp = 1;
      else
       temp = 1/magnitude;
    view1 *= temp;
    view2 *= temp;
    view3 *= temp;

    dotp = view1*shiparray[a].dxv + view2*shiparray[a].dyv + view3*shiparray[a].dzv;
    if(dotp < 0.0)
     {
      shiparray[a].color1.red = shiparray[a].color.red;
      shiparray[a].color1.green = shiparray[a].color.green;
      shiparray[a].color1.blue = shiparray[a].color.blue;

     /* terarray[a].color.red *= 16*dotp;
      terarray[a].color.green *= 16*dotp;
      terarray[a].color.blue *= 16*dotp;
    */ }
     else
     {
         temp = 8*dotp;
         shiparray[a].color1.red = shiparray[a].color.red + shiparray[a].color.red*temp;
         shiparray[a].color1.green = shiparray[a].color.green + shiparray[a].color.green*temp;
         shiparray[a].color1.blue = shiparray[a].color.blue + shiparray[a].color.blue*temp;
         if(shiparray[a].color1.red > 31) shiparray[a].color1.red = 31;
          if(shiparray[a].color1.green > 63) shiparray[a].color1.green = 63;
          if(shiparray[a].color1.blue > 31) shiparray[a].color1.blue = 31;

     }
  }
 }
}

void shipclass::calcverlight(void)
 {
  int a;
  float view1,view2,view3,dotp,magnitude;

  for(a=0;a<104;a++)
   {
    view1 = 450 - xposition/*shiparray[a].v1.vx*/;
    view2 = -300 - yposition/*shiparray[a].v1.vy*/;
    view3 = -240/* - shiparray[a].v1.vz*/;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    view1 /= magnitude;
    view2 /= magnitude;
    view3 /= magnitude;

    dotp = view1*shiparray[a].v1.fvx + view2*shiparray[a].v1.fvy + view3*shiparray[a].v1.fvz;
    if(dotp <= 0.125)
     {
      shiparray[a].v1.inten1 = 1;
     }
     else
     {
      shiparray[a].v1.inten1 = 7.75*dotp;
     }
    if(shiparray[a].v1.inten1 > 7.75)  shiparray[a].v1.inten1 = 7.75;
    if(shiparray[a].v1.inten1 < 1.0)  shiparray[a].v1.inten1 = 1.0;

    view1 = 450 - xposition/*shiparray[a].v2.vx*/;
    view2 = -300 - yposition/*shiparray[a].v2.vy*/;
    view3 = -240/* - shiparray[a].v2.vz*/;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    view1 /= magnitude;
    view2 /= magnitude;
    view3 /= magnitude;

    dotp = view1*shiparray[a].v2.fvx + view2*shiparray[a].v2.fvy + view3*shiparray[a].v2.fvz;
    if(dotp <= 0.125)
     {
      shiparray[a].v2.inten1 = 1;
     }
     else
     {
      shiparray[a].v2.inten1 = 7.75*dotp;
     }
    if(shiparray[a].v2.inten1 > 7.75)  shiparray[a].v2.inten1 = 7.75;
    if(shiparray[a].v2.inten1 < 1.0)  shiparray[a].v2.inten1 = 1.0;

    view1 = 450 - xposition/*shiparray[a].v3.vx*/;
    view2 = -300 - yposition/*shiparray[a].v3.vy*/;
    view3 = -240/* - shiparray[a].v3.vz*/;
    magnitude = sqrt(view1*view1 + view2*view2 + view3*view3);
    view1 /= magnitude;
    view2 /= magnitude;
    view3 /= magnitude;

    dotp = view1*shiparray[a].v3.fvx + view2*shiparray[a].v3.fvy + view3*shiparray[a].v3.fvz;
    if(dotp <= 0.125)
     {
      shiparray[a].v3.inten1 = 1;
     }
     else
     {
      shiparray[a].v3.inten1 = 7.75*dotp;
     }
    if(shiparray[a].v3.inten1 > 7.75)  shiparray[a].v3.inten1 = 7.75;
    if(shiparray[a].v3.inten1 < 1.0)  shiparray[a].v3.inten1 = 1.0;
 /*   shiparray[a].v1.inten1 = 1.0;
    shiparray[a].v2.inten1 = 2.0;
    shiparray[a].v3.inten1 = 3.0;
  */
   }
 }

 void shipclass::transform(int scale,char guryn)
   {
    float matrix[4][4];
    float smatrix[4][4];
    float rtmatrix[4][4];
    int i,j,k,temp;

    if(fire)
     {
      if(thrust <= 2)
       for(i=104;i<109;i++)
        {
         shiparray[i].v2.ly = thrust + 2;
        }
      if(thrust <= 10 && thrust >2)
       {
        temp = rand()%3;
       for(i=104;i<109;i++)
        {
         shiparray[i].v2.ly = (thrust+1)+temp;
        }
       }
      if(thrust > 10)
       {
       temp = rand()%5;
       for(i=104;i<109;i++)
        {
         shiparray[i].v2.ly = thrust+temp;
        }
       }
     }
     else
      for(i=104;i<109;i++)
       {
        shiparray[i].v2.ly = 1;
       }

    smatrix[0][0] = scale;
    smatrix[0][1] = 0;
    smatrix[0][2] = 0;
    smatrix[0][3] = 0;
    smatrix[1][0] = 0;
    smatrix[1][1] = scale;
    smatrix[1][2] = 0;
    smatrix[1][3] = 0;
    smatrix[2][0] = 0;
    smatrix[2][1] = 0;
    smatrix[2][2] = scale;
    smatrix[2][3] = 0;
    smatrix[3][0] = 0;
    smatrix[3][1] = 0;
    smatrix[3][2] = 0;
    smatrix[3][3] = 1;



    rtmatrix[0][0] = cos(-angle);
    rtmatrix[0][1] = sin(-angle);
    rtmatrix[0][2] = 0;
    rtmatrix[0][3] = 0;
    rtmatrix[1][0] = -sin(-angle);
    rtmatrix[1][1] = cos(-angle);
    rtmatrix[1][2] = 0;
    rtmatrix[1][3] = 0;
    rtmatrix[2][0] = 0;
    rtmatrix[2][1] = 0;
    rtmatrix[2][2] = 1;
    rtmatrix[2][3] = 0;
    if(scale == 1)
     {
      rtmatrix[3][0] = (xposition*0.5)-320;
      rtmatrix[3][1] = yposition-240;
     }
     else
      {
       rtmatrix[3][0] = 0;
       rtmatrix[3][1] = 0;
      }
    rtmatrix[3][2] = 10;
    rtmatrix[3][3] = 1;


    for(i=0;i<4;i++)
     for(j=0;j<4;j++)
      {
       matrix[i][j]=0;
       for(k=0;k<4;k++)
        matrix[i][j]+=smatrix[i][k] * rtmatrix[k][j];
      }

     double temp0;
     double temp1;
     double temp2;

     for(i=0;i<109;i++)
      {
/*       temp0=0;
       temp1=0;
       temp2=0;
  */     shiparray[i].v1.vx=shiparray[i].v1.lx*matrix[0][0]+shiparray[i].v1.ly*matrix[1][0]+
            shiparray[i].v1.lz*matrix[2][0]+matrix[3][0];
       shiparray[i].v1.vy=shiparray[i].v1.lx*matrix[0][1]+shiparray[i].v1.ly*matrix[1][1]+
            shiparray[i].v1.lz*matrix[2][1]+matrix[3][1];
       shiparray[i].v1.vz=shiparray[i].v1.lx*matrix[0][2]+shiparray[i].v1.ly*matrix[1][2]+
            shiparray[i].v1.lz*matrix[2][2]+matrix[3][2];
 /*      shiparray[i].v1.vx=temp0;
       shiparray[i].v1.vy=temp1;
       shiparray[i].v1.vz=temp2;
   */
 /*      temp0=0;
       temp1=0;
       temp2=0;
 */      shiparray[i].v2.vx=shiparray[i].v2.lx*matrix[0][0]+shiparray[i].v2.ly*matrix[1][0]+
            shiparray[i].v2.lz*matrix[2][0]+matrix[3][0];
       shiparray[i].v2.vy=shiparray[i].v2.lx*matrix[0][1]+shiparray[i].v2.ly*matrix[1][1]+
            shiparray[i].v2.lz*matrix[2][1]+matrix[3][1];
       shiparray[i].v2.vz=shiparray[i].v2.lx*matrix[0][2]+shiparray[i].v2.ly*matrix[1][2]+
            shiparray[i].v2.lz*matrix[2][2]+matrix[3][2];
/*       shiparray[i].v2.vx=temp0;
       shiparray[i].v2.vy=temp1;
       shiparray[i].v2.vz=temp2;
  */
/*       temp0=0;
       temp1=0;
       temp2=0;
*/       shiparray[i].v3.vx=shiparray[i].v3.lx*matrix[0][0]+shiparray[i].v3.ly*matrix[1][0]+
            shiparray[i].v3.lz*matrix[2][0]+matrix[3][0];
       shiparray[i].v3.vy=shiparray[i].v3.lx*matrix[0][1]+shiparray[i].v3.ly*matrix[1][1]+
            shiparray[i].v3.lz*matrix[2][1]+matrix[3][1];
       shiparray[i].v3.vz=shiparray[i].v3.lx*matrix[0][2]+shiparray[i].v3.ly*matrix[1][2]+
            shiparray[i].v3.lz*matrix[2][2]+matrix[3][2];
/*       shiparray[i].v3.vx=temp0;
       shiparray[i].v3.vy=temp1;
       shiparray[i].v3.vz=temp2;
 */
      }

   for(i=0;i<104;i++)
      {
       shiparray[i].fmidx = (shiparray[i].v1.vx + shiparray[i].v2.vx + shiparray[i].v3.vx)*0.333333;
       shiparray[i].fmidy = (shiparray[i].v1.vy + shiparray[i].v2.vy + shiparray[i].v3.vy)*0.333333;
       shiparray[i].fmidz = (shiparray[i].v1.vz + shiparray[i].v2.vz + shiparray[i].v3.vz)*0.333333;
  /*

       temp0=0;
       temp1=0;
       temp2=0;
       temp0+=shiparray[i].midx*matrix[0][0]+shiparray[i].midy*matrix[1][0]+
            shiparray[i].midz*matrix[2][0]+matrix[3][0];
       temp1+=shiparray[i].midx*matrix[0][1]+shiparray[i].midy*matrix[1][1]+
            shiparray[i].midz*matrix[2][1]+matrix[3][1];
       temp2+=shiparray[i].midx*matrix[0][2]+shiparray[i].midy*matrix[1][2]+
            shiparray[i].midz*matrix[2][2]+matrix[3][2];
       shiparray[i].fmidx=temp0;
       shiparray[i].fmidy=temp1;
       shiparray[i].fmidz=temp2;
  */
    /*calculate polygon normals*/
 /*  v1 = shiparray[i].v2.vx - shiparray[i].v1.vx;
   v2 = shiparray[i].v2.vy - shiparray[i].v1.vy;
   v3 = shiparray[i].v2.vz - shiparray[i].v1.vz;
   w1 = shiparray[i].v3.vx - shiparray[i].v1.vx;
   w2 = shiparray[i].v3.vy - shiparray[i].v1.vy;
   w3 = shiparray[i].v3.vz - shiparray[i].v1.vz;
   shiparray[i].dxv = v2*w3 - v3*w2;
   shiparray[i].dyv = v3*w1 - v1*w3;
   shiparray[i].dzv = v1*w2 - v2*w1;
   /*calculate direction vectors*/
 /*  magnitude = sqrt((shiparray[i].dxv*shiparray[i].dxv) + (shiparray[i].dyv*shiparray[i].dyv) + (shiparray[i].dzv*shiparray[i].dzv));
   shiparray[i].dxv /= magnitude;
   shiparray[i].dyv /= magnitude;
   shiparray[i].dzv /= magnitude;
 */


 /*      temp0=0;
       temp1=0;
       temp2=0;
  */     shiparray[i].dxv=shiparray[i].nxv*rtmatrix[0][0]+shiparray[i].nyv*rtmatrix[1][0]+
            shiparray[i].nzv*rtmatrix[2][0];
       shiparray[i].dyv=shiparray[i].nxv*rtmatrix[0][1]+shiparray[i].nyv*rtmatrix[1][1]+
            shiparray[i].nzv*rtmatrix[2][1];
       shiparray[i].dzv=shiparray[i].nxv*rtmatrix[0][2]+shiparray[i].nyv*rtmatrix[1][2]+
            shiparray[i].nzv*rtmatrix[2][2];
 /*      shiparray[i].dxv=temp0;
       shiparray[i].dyv=temp1;
       shiparray[i].dzv=temp2;
  */

    }

  if(guryn != 1)
   {
    for(i=0;i<104;i++)
     {
       temp0=0;
       temp1=0;
       temp2=0;
       temp0+=shiparray[i].v1.dvx*rtmatrix[0][0]+shiparray[i].v1.dvy*rtmatrix[1][0]+
            shiparray[i].v1.dvz*rtmatrix[2][0];
       temp1+=shiparray[i].v1.dvx*rtmatrix[0][1]+shiparray[i].v1.dvy*rtmatrix[1][1]+
            shiparray[i].v1.dvz*rtmatrix[2][1];
       temp2+=shiparray[i].v1.dvx*rtmatrix[0][2]+shiparray[i].v1.dvy*rtmatrix[1][2]+
            shiparray[i].v1.dvz*rtmatrix[2][2];
       shiparray[i].v1.fvx=temp0;
       shiparray[i].v1.fvy=temp1;
       shiparray[i].v1.fvz=temp2;

       temp0=0;
       temp1=0;
       temp2=0;
       temp0+=shiparray[i].v2.dvx*rtmatrix[0][0]+shiparray[i].v2.dvy*rtmatrix[1][0]+
            shiparray[i].v2.dvz*rtmatrix[2][0];
       temp1+=shiparray[i].v2.dvx*rtmatrix[0][1]+shiparray[i].v2.dvy*rtmatrix[1][1]+
            shiparray[i].v2.dvz*rtmatrix[2][1];
       temp2+=shiparray[i].v2.dvx*rtmatrix[0][2]+shiparray[i].v2.dvy*rtmatrix[1][2]+
            shiparray[i].v2.dvz*rtmatrix[2][2];
       shiparray[i].v2.fvx=temp0;
       shiparray[i].v2.fvy=temp1;
       shiparray[i].v2.fvz=temp2;

       temp0=0;
       temp1=0;
       temp2=0;
       temp0+=shiparray[i].v3.dvx*rtmatrix[0][0]+shiparray[i].v3.dvy*rtmatrix[1][0]+
            shiparray[i].v3.dvz*rtmatrix[2][0];
       temp1+=shiparray[i].v3.dvx*rtmatrix[0][1]+shiparray[i].v3.dvy*rtmatrix[1][1]+
            shiparray[i].v3.dvz*rtmatrix[2][1];
       temp2+=shiparray[i].v3.dvx*rtmatrix[0][2]+shiparray[i].v3.dvy*rtmatrix[1][2]+
            shiparray[i].v3.dvz*rtmatrix[2][2];
       shiparray[i].v3.fvx=temp0;
       shiparray[i].v3.fvy=temp1;
       shiparray[i].v3.fvz=temp2;

     }
   }
  /*float a,b,d,e,j,k,l;
  a = cos(angle);
  b = sin(angle);
  d = -sin(angle);
  e = cos(angle);
  if(scale == 1)
   {
    j = xposition/2;
    k = yposition;
    l = 100*cos(angle);
   }
   else
    (
     j = 320;
     k = 240;
     l = 25*cos(angle);

    )
   int count;
   for(
   */
   }

void shipclass::cull(void)
 {
  double tempx,tempy,tempz,dotp;
  int a;
  for(a=0;a<109;a++)
   {
    /*calc viewvector*/
     tempx = 0-shiparray[a].fmidx;
      tempy = 0-shiparray[a].fmidy;
      tempz = -50 - shiparray[a].fmidz;
    /*calculate z buffer distance*/
      shiparray[a].dist = sqrt(tempx*tempx + tempy*tempy + tempz*tempz);

   /*   magnitude = sqrt(tempx*tempx + tempy*tempy + tempz*tempz);
      tempx /= magnitude;
      tempy /= magnitude;
      tempz /= magnitude;
  */  /*calc dot product between veiw vector and
      poly normal*/
    dotp = (shiparray[a].dxv*tempx)+(shiparray[a].dyv*tempy)+(shiparray[a].dzv*tempz);
    if((dotp < -0.0) && (a < 104))
    shiparray[a].culled = true;
    else shiparray[a].culled = false;
   }
 }

void shipclass::project(void)
 {
  float temp;
  for(a=0;a<109;a++)
   {
   if(shiparray[a].culled == false)
    {
    temp = 1/(shiparray[a].v1.vz+50.0);
    shiparray[a].v1.sx = 50.0*((shiparray[a].v1.vx)*(temp))+320.0;
    shiparray[a].v1.sy = 50.0*((shiparray[a].v1.vy)*(temp))+240.0;
    temp = 1/(shiparray[a].v2.vz+50.0);

    shiparray[a].v2.sx = 50.0*((shiparray[a].v2.vx)*(temp))+320.0;
    shiparray[a].v2.sy = 50.0*((shiparray[a].v2.vy)*(temp))+240.0;
    temp = 1/(shiparray[a].v3.vz+50.0);
    shiparray[a].v3.sx = 50.0*((shiparray[a].v3.vx)*(temp))+320.0;
    shiparray[a].v3.sy = 50.0*((shiparray[a].v3.vy)*(temp))+240.0;
    }
   }
 }

void shipclass::moveship(double diftime)
  {
   if(diftime < 0)
    diftime = 0;
   diftime *= 0.001;
   if(fire)
    {
     fuel -= thrust * diftime * 5;
    }
   if(fuel <= 0)
    {
     fuel = 0;
     fire = false;
    }
   if(fire)
    {
     xaccel = 0.54044 * thrust * cos(angle+1.570796);
     yaccel = ((-0.54044 * thrust * sin(angle+1.570796)) + 1.62);
    }
    else
     {
      xaccel = 0;
      yaccel = 1.62;
     }
   newxv = oldxv + xaccel * (diftime);
   newyv = oldyv + yaccel * (diftime);
   xchange = oldxv * (diftime) + 0.5 * xaccel * diftime * diftime;
   ychange = oldyv * diftime + 0.5 * yaccel * diftime * diftime;
   yposition += 2 * ychange;
   xposition += 2 * xchange;
   oldxv = newxv;
   oldyv = newyv;

  }

void shipclass::resetvars()
 {
  xposition = 0;
  yposition = 0;
  altitude = 0;
  angle = 0;
  thrust = 0;
  fuel = 0;
  xaccel = 0;
  yaccel = 0;
  newxv = 0;
  newyv = 0;
  oldxv = 0;
  oldyv = 0;
  xchange = 0;
  ychange = 0;
  fire = false;
 }

 float shipclass::retxpos(void)
   {
    return xposition;
   }
  float shipclass::retypos(void)
   {
    return yposition;
   }
  float shipclass::retthrust(void)
   {
    return thrust;
   }
  float shipclass::retfuel(void)
   {
    return fuel;
   }
  int shipclass::retaltitude(void)
   {
    return altitude;
   }
  int shipclass::retangle(void)
   {
    return angle*57.29578;
   }
  double shipclass::retyvelocity()
   {
    return newyv;
   }
  bool shipclass::retfire(void)
   {
    return fire;
   }

  void shipclass::setxpos(int xpos)
   {
    xposition = xpos;
   }
  void shipclass::setypos(int ypos)
   {
    yposition = ypos;
   }
  void shipclass::setangle(float ang)
   {
    angle = ang;
   }
  void shipclass::setthrust(float th)
   {
    if(th < 0) th = 0;
    if(th > 20) th = 20;
    thrust = th;
   }
  void shipclass::setfuel(float fl)
   {
    fuel = fl;
   }
  void shipclass::setaltitude(int alt)
   {
    altitude = alt;
   }
  void shipclass::setfire(bool fr)
   {
    fire = fr;
   }
  void shipclass::addangle(float ang)
   {
    angle += ang;
    if(angle>3.141593)
     angle -= 6.28319;
    if(angle<-3.141593)
     angle += 6.28319;

   }
  void shipclass::addthrust(float th)
   {
    thrust += th;

    if(thrust < 0) thrust = 0;
    if(thrust > 20) thrust = 20;
   }

void shipclass::drawship(unsigned short* surf,char guryn,int bits,LPDIRECTDRAWSURFACE lpddsback,short zbuffer[640][480],int pitch)
 {
   
  /* temp1 = top vertex:  temp2 = counterclockwise vertex: temp3 = clockwize vertex */
 /* DDSURFACEDESC ddsd;
  ddsd.dwSize = sizeof(ddsd);
 */ int count;
  if(fire) count = 109;
  else count = 104;
 /* if (lpddsback->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL) == DD_OK)
   {
  unsigned short* surf;

  surf = (unsigned short*)ddsd.lpSurface;
  */

  for(a=0;a<count;a++)
   {
    if(!(shiparray[a].culled))
     {
      if((shiparray[a].v1.sy <= shiparray[a].v2.sy) && (shiparray[a].v1.sy <= shiparray[a].v3.sy))
       {
        if(guryn == 1) polydraw(surf,/*ddsd,*/shiparray[a].v1.sx,shiparray[a].v2.sx,shiparray[a].v3.sx,shiparray[a].v1.sy,shiparray[a].v2.sy,shiparray[a].v3.sy,shiparray[a].dist,shiparray[a].color1,bits,zbuffer,lpddsback,pitch);
        else
         {
         if(a >= 104) gpolydraw(surf,/*ddsd,*/shiparray[a].v1.sx,shiparray[a].v2.sx,shiparray[a].v3.sx,shiparray[a].v1.sy,shiparray[a].v2.sy,shiparray[a].v3.sy,shiparray[a].dist,shiparray[a].color,shiparray[a].v1.inten1,shiparray[a].v2.inten1,shiparray[a].v3.inten1,true,bits,zbuffer,pitch);
         else gpolydraw(surf,/*ddsd,*/shiparray[a].v1.sx,shiparray[a].v2.sx,shiparray[a].v3.sx,shiparray[a].v1.sy,shiparray[a].v2.sy,shiparray[a].v3.sy,shiparray[a].dist,shiparray[a].color,shiparray[a].v1.inten1,shiparray[a].v2.inten1,shiparray[a].v3.inten1,false,bits,zbuffer,pitch);
         }


/*        temp1 = shiparray[a].v1;
        temp2 = shiparray[a].v2;
        temp3 = shiparray[a].v3;
/*        tempy1 = terarray[a].v1.sy;
        tempy2 = terarray[a].v2.sy;
        tempy3 = terarray[a].v3.sy;
  */
       }
      if((shiparray[a].v2.sy < shiparray[a].v1.sy) && (shiparray[a].v2.sy < shiparray[a].v3.sy))
       {
        if(guryn == 1) polydraw(surf,/*ddsd,*/shiparray[a].v2.sx,shiparray[a].v3.sx,shiparray[a].v1.sx,shiparray[a].v2.sy,shiparray[a].v3.sy,shiparray[a].v1.sy,shiparray[a].dist,shiparray[a].color1,bits,zbuffer,lpddsback,pitch);
        else
         {
         if(a >= 104) gpolydraw(surf,/*ddsd,*/shiparray[a].v2.sx,shiparray[a].v3.sx,shiparray[a].v1.sx,shiparray[a].v2.sy,shiparray[a].v3.sy,shiparray[a].v1.sy,shiparray[a].dist,shiparray[a].color,shiparray[a].v2.inten1,shiparray[a].v3.inten1,shiparray[a].v1.inten1,true,bits,zbuffer,pitch);
         else gpolydraw(surf,/*ddsd,*/shiparray[a].v2.sx,shiparray[a].v3.sx,shiparray[a].v1.sx,shiparray[a].v2.sy,shiparray[a].v3.sy,shiparray[a].v1.sy,shiparray[a].dist,shiparray[a].color,shiparray[a].v2.inten1,shiparray[a].v3.inten1,shiparray[a].v1.inten1,false,bits,zbuffer,pitch);
         }


/*        temp1 = shiparray[a].v2;
        temp2 = shiparray[a].v3;
        temp3 = shiparray[a].v1;
      /*  tempy1 = terarray[a].v2.sy;
        tempy2 = terarray[a].v3.sy;
        tempy3 = terarray[a].v1.sy;
       */
       }
      if((shiparray[a].v3.sy <= shiparray[a].v2.sy) && (shiparray[a].v3.sy < shiparray[a].v1.sy))
       {
          if(guryn == 1) polydraw(surf,/*ddsd,*/shiparray[a].v3.sx,shiparray[a].v1.sx,shiparray[a].v2.sx,shiparray[a].v3.sy,shiparray[a].v1.sy,shiparray[a].v2.sy,shiparray[a].dist,shiparray[a].color1,bits,zbuffer,lpddsback,pitch);
        else
         {
         if(a >= 104) gpolydraw(surf,/*ddsd,*/shiparray[a].v3.sx,shiparray[a].v1.sx,shiparray[a].v2.sx,shiparray[a].v3.sy,shiparray[a].v1.sy,shiparray[a].v2.sy,shiparray[a].dist,shiparray[a].color,shiparray[a].v3.inten1,shiparray[a].v1.inten1,shiparray[a].v2.inten1,true,bits,zbuffer,pitch);
         else gpolydraw(surf,/*ddsd,*/shiparray[a].v3.sx,shiparray[a].v1.sx,shiparray[a].v2.sx,shiparray[a].v3.sy,shiparray[a].v1.sy,shiparray[a].v2.sy,shiparray[a].dist,shiparray[a].color,shiparray[a].v3.inten1,shiparray[a].v1.inten1,shiparray[a].v2.inten1,false,bits,zbuffer,pitch);
         }

/*        temp1 = shiparray[a].v3;
        temp2 = shiparray[a].v1;
        temp3 = shiparray[a].v2;
       /* tempy1 = terarray[a].v3.sy;
        tempy2 = terarray[a].v1.sy;
        tempy3 = terarray[a].v2.sy;
       */
       }
   /*     if(guryn == 1) polydraw(surf,ddsd,temp1.sx,temp2.sx,temp3.sx,temp1.sy,temp2.sy,temp3.sy,shiparray[a].dist,shiparray[a].color1,bits,zbuffer,lpddsback);
        else
         {
         if(a >= 104) gpolydraw(surf,ddsd,temp1.sx,temp2.sx,temp3.sx,temp1.sy,temp2.sy,temp3.sy,shiparray[a].dist,shiparray[a].color,temp1.inten1,temp2.inten1,temp3.inten1,shiparray[a].color1,true,bits,zbuffer);
         else gpolydraw(surf,ddsd,temp1.sx,temp2.sx,temp3.sx,temp1.sy,temp2.sy,temp3.sy,shiparray[a].dist,shiparray[a].color,temp1.inten1,temp2.inten1,temp3.inten1,shiparray[a].color1,false,bits,zbuffer);
         }
 */    }

   }
/* } lpddsback->Unlock(NULL);
 */





/*
  colortype tempcolor;
  tempcolor.red = 31;
  tempcolor.green = 63;
  tempcolor.blue = 31;

  for(a=0;a<109;a++)
   {
    if(shiparray[a].culled == false)
     {
      linedraw(shiparray[a].v1.sx,shiparray[a].v1.sy,shiparray[a].v2.sx,shiparray[a].v2.sy,shiparray[a].color1);
      linedraw(shiparray[a].v2.sx,shiparray[a].v2.sy,shiparray[a].v3.sx,shiparray[a].v3.sy,shiparray[a].color1);
      linedraw(shiparray[a].v1.sx,shiparray[a].v1.sy,shiparray[a].v3.sx,shiparray[a].v3.sy,shiparray[a].color1);
     }

   }
 */
 }

