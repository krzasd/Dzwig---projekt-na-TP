#include "stdafx.h"

void PaintCrane( HDC hdc )
{
	Graphics graphics( hdc );
	Pen penCrane1 ( Color( 255, 255, 0 ) );
	PointF Pt[ 133 ];
	Pt[0].X = 110; //prawa granica trzonu d�wigu
	Pt[0].Y = 650;
	Pt[1].X = 100;
	Pt[1].Y = 650;
	Pt[2].X = 110;
	Pt[2].Y = 640;
	Pt[3].X = 100;
	Pt[3].Y = 640;
	Pt[4].X = 110;
	Pt[4].Y = 630;
	Pt[5].X = 100;
	Pt[5].Y = 630;
	Pt[6].X = 110;
	Pt[6].Y = 620;
	Pt[7].X = 100;
	Pt[7].Y = 620;
	Pt[8].X = 110;
	Pt[8].Y = 610;
	Pt[9].X = 100;
	Pt[9].Y = 610;
	Pt[10].X = 110;
	Pt[10].Y = 600;
	Pt[11].X = 100;
	Pt[11].Y = 600;
	Pt[12].X = 110;
	Pt[12].Y = 590;
	Pt[13].X = 100;
	Pt[13].Y = 590;
	Pt[14].X = 110;
	Pt[14].Y = 580;
	Pt[15].X = 100;
	Pt[15].Y = 580;
	Pt[16].X = 110;
	Pt[16].Y = 570;
	Pt[17].X = 100;
	Pt[17].Y = 570;
	Pt[18].X = 110;
	Pt[18].Y = 560;
	Pt[19].X = 100;
	Pt[19].Y = 560;
	Pt[20].X = 110;
	Pt[20].Y = 550;
	Pt[21].X = 100;
	Pt[21].Y = 550;
	Pt[22].X = 110;
	Pt[22].Y = 540;
	Pt[23].X = 100;
	Pt[23].Y = 540;
	Pt[24].X = 110;
	Pt[24].Y = 530;
	Pt[25].X = 100;
	Pt[25].Y = 530;
	Pt[26].X = 110;
	Pt[26].Y = 520;
	Pt[27].X = 100;
	Pt[27].Y = 520;
	Pt[28].X = 110;
	Pt[28].Y = 510;
	Pt[29].X = 100;
	Pt[29].Y = 510;
	Pt[30].X = 110;
	Pt[30].Y = 500;
	Pt[31].X = 100;
	Pt[31].Y = 500;
	Pt[32].X = 110;
	Pt[32].Y = 490;
	Pt[33].X = 100;
	Pt[33].Y = 490;
	Pt[34].X = 110;
	Pt[34].Y = 480;
	Pt[35].X = 100;
	Pt[35].Y = 480;
	Pt[36].X = 110;
	Pt[36].Y = 470;
	Pt[37].X = 100;
	Pt[37].Y = 470;
	Pt[38].X = 110; 
	Pt[38].Y = 460;
	Pt[39].X = 100;
	Pt[39].Y = 460;
	Pt[40].X = 110;
	Pt[40].Y = 450;
	Pt[41].X = 100;
	Pt[41].Y = 450;
	Pt[42].X = 110;
	Pt[42].Y = 440; 
	Pt[43].X = 100;
	Pt[43].Y = 440;
	Pt[44].X = 110;
	Pt[44].Y = 430;
	Pt[45].X = 100;
	Pt[45].Y = 430;
	Pt[46].X = 110;
	Pt[46].Y = 420;
	Pt[47].X = 100;
	Pt[47].Y = 420;
	Pt[48].X = 110;
	Pt[48].Y = 410;
	Pt[49].X = 100;
	Pt[49].Y = 410;
	Pt[50].X = 110;
	Pt[50].Y = 400;
	Pt[51].X = 100;
	Pt[51].Y = 400;
	Pt[52].X = 110;
	Pt[52].Y = 390;
	Pt[53].X = 100;
	Pt[53].Y = 390;
	Pt[54].X = 110;
	Pt[54].Y = 380;
	Pt[55].X = 100;
	Pt[55].Y = 380;
	Pt[56].X = 110;
	Pt[56].Y = 370;
	Pt[57].X = 100;
	Pt[57].Y = 370;
	Pt[58].X = 110;
	Pt[58].Y = 360;
	Pt[59].X = 100;
	Pt[59].Y = 360;
	Pt[60].X = 110;
	Pt[60].Y = 350;
	Pt[61].X = 100;
	Pt[61].Y = 350;
	Pt[62].X = 110;
	Pt[62].Y = 340;
	Pt[63].X = 100;
	Pt[63].Y = 340;
	Pt[64].X = 110;
	Pt[64].Y = 330;
	Pt[65].X = 100;
	Pt[65].Y = 330;
	Pt[66].X = 110;
	Pt[66].Y = 320;
	Pt[67].X = 100;
	Pt[67].Y = 320;
	Pt[68].X = 110;
	Pt[68].Y = 310;
	Pt[69].X = 100;
	Pt[69].Y = 310;
	Pt[70].X = 110;
	Pt[70].Y = 300;
	Pt[71].X = 100;
	Pt[71].Y = 300;
	Pt[72].X = 110;
	Pt[72].Y = 290;
	Pt[73].X = 100;
	Pt[73].Y = 290;
	Pt[74].X = 110;
	Pt[74].Y = 280;
	Pt[75].X = 100;
	Pt[75].Y = 280;
	Pt[76].X = 110;
	Pt[76].Y = 270;
	Pt[77].X = 100;
	Pt[77].Y = 270;
	Pt[78].X = 110;
	Pt[78].Y = 260; 
	Pt[79].X = 100;
	Pt[79].Y = 260;
	Pt[80].X = 110;
	Pt[80].Y = 250;
	Pt[81].X = 100;
	Pt[81].Y = 250;
	Pt[82].X = 110;
	Pt[82].Y = 240;
	Pt[83].X = 100;
	Pt[83].Y = 240;
	Pt[84].X = 110;
	Pt[84].Y = 230;
	Pt[85].X = 100;
	Pt[85].Y = 230;
	Pt[86].X = 110;
	Pt[86].Y = 220;
	Pt[87].X = 100;
	Pt[87].Y = 220;
	Pt[88].X = 110;
	Pt[88].Y = 210;
	Pt[89].X = 100;
	Pt[89].Y = 210;
	Pt[90].X = 110;
	Pt[90].Y = 200;
	Pt[91].X = 100;
	Pt[91].Y = 200;
	Pt[92].X = 110;
	Pt[92].Y = 190;
	Pt[93].X = 100;
	Pt[93].Y = 190;
	Pt[94].X = 110;
	Pt[94].Y = 180;
	Pt[95].X = 100;
	Pt[95].Y = 180;
	Pt[96].X = 110;
	Pt[96].Y = 170;
	Pt[97].X = 100;
	Pt[97].Y = 170;
	Pt[98].X = 110;
	Pt[98].Y = 160;
	Pt[99].X = 100;
	Pt[99].Y = 160;
	Pt[100].X = 110;
	Pt[100].Y = 150;
	Pt[101].X = 100;
	Pt[101].Y = 150;
	Pt[102].X = 110;
	Pt[102].Y = 140;
	Pt[103].X = 100;
	Pt[103].Y = 140;
	Pt[104].X = 110;
	Pt[104].Y = 130;
	Pt[105].X = 100;
	Pt[105].Y = 130;
	Pt[106].X = 110;
	Pt[106].Y = 120;
	Pt[107].X = 100;
	Pt[107].Y = 120;
	Pt[108].X = 110;
	Pt[108].Y = 110;
	Pt[109].X = 100;
	Pt[109].Y = 110;
	Pt[110].X = 110;
	Pt[110].Y = 100;
	Pt[111].X = 100;
	Pt[111].Y = 100;
	Pt[112].X = 110;
	Pt[112].Y =  90;
	Pt[113].X = 100;
	Pt[113].Y =  90;
	Pt[114].X = 110;
	Pt[114].Y =  80;
	Pt[115].X = 100;
	Pt[115].Y =  80;
	Pt[116].X = 110;
	Pt[116].Y =  70;
	Pt[117].X = 100;
	Pt[117].Y =  70;
	Pt[118].X = 110;
	Pt[118].Y =  60;
	Pt[119].X = 100;
	Pt[119].Y =  60;
	Pt[120].X = 110;
	Pt[120].Y =  50;
	Pt[121].X = 100;
	Pt[121].Y =  50;
	Pt[122].X = 110;
	Pt[122].Y =  40;
	Pt[123].X = 100;
	Pt[123].Y =  40;
	Pt[124].X = 110;
	Pt[124].Y =  30;
	Pt[125].X = 100;
	Pt[125].Y =  30;
	Pt[126].X = 110;
	Pt[126].Y =  20;
	Pt[127].X = 100;
	Pt[127].Y =  20;
	Pt[128].X = 110;
	Pt[128].Y =  10;
	Pt[129].X = 110;
	Pt[129].Y = 650;
	Pt[130].X = 100;
	Pt[130].Y = 650;
	Pt[131].X = 100;
	Pt[131].Y =  20;
	Pt[132].X = 110;
	Pt[132].Y =  10;

	//graphics.DrawRectangle( &penCrane, 50, , 
	graphics.DrawPolygon( &penCrane1, Pt, 133 );

	Pen penCrane2 ( Color( 255, 255, 0 ) );
	PointF Pt2[ 134 ];
	Pt2[0].X =  40;
	Pt2[0].Y =  48;
	Pt2[1].X =  40;
	Pt2[1].Y =  58; //dolna granica ramienia d�wigu
	Pt2[2].X =  50;
	Pt2[2].Y =  48;
	Pt2[3].X =  60;
	Pt2[3].Y =  58;
	Pt2[4].X =  70;
	Pt2[4].Y =  48;
	Pt2[5].X =  80;
	Pt2[5].Y =  58;
	Pt2[6].X =  90;
	Pt2[6].Y =  48;
	Pt2[7].X = 100;
	Pt2[7].Y =  58;
	Pt2[8].X = 110;
	Pt2[8].Y =  58;
	Pt2[9].X = 120;
	Pt2[9].Y =  48;
	Pt2[10].X = 130;
	Pt2[10].Y =  58;
	Pt2[11].X = 140;
	Pt2[11].Y =  48;
	Pt2[12].X = 150;
	Pt2[12].Y =  58;
	Pt2[13].X = 160;
	Pt2[13].Y =  48;
	Pt2[14].X = 170;
	Pt2[14].Y =  58;
	Pt2[15].X = 180;
	Pt2[15].Y =  48;
	Pt2[16].X = 190;
	Pt2[16].Y =  58;
	Pt2[17].X = 200;
	Pt2[17].Y =  48;
	Pt2[18].X = 210;
	Pt2[18].Y =  58;
	Pt2[19].X = 220;
	Pt2[19].Y =  48;
	Pt2[20].X = 230;
	Pt2[20].Y =  58;
	Pt2[21].X = 240;
	Pt2[21].Y =  48;
	Pt2[22].X = 250;
	Pt2[22].Y =  58;
	Pt2[23].X = 260;
	Pt2[23].Y =  48;
	Pt2[24].X = 270;
	Pt2[24].Y =  58;
	Pt2[25].X = 280;
	Pt2[25].Y =  48;
	Pt2[26].X = 290;
	Pt2[26].Y =  58;
	Pt2[27].X = 300;
	Pt2[27].Y =  48;
	Pt2[28].X = 310;
	Pt2[28].Y =  58;
	Pt2[29].X = 320;
	Pt2[29].Y =  48;
	Pt2[30].X = 330;
	Pt2[30].Y =  58;
	Pt2[31].X = 340;
	Pt2[31].Y =  48;
	Pt2[32].X = 350;
	Pt2[32].Y =  58;
	Pt2[33].X = 360;
	Pt2[33].Y =  48;
	Pt2[34].X = 370;
	Pt2[34].Y =  58;
	Pt2[35].X = 380;
	Pt2[35].Y =  48;
	Pt2[36].X = 390;
	Pt2[36].Y =  58;
	Pt2[37].X = 400;
	Pt2[37].Y =  48;
	Pt2[38].X = 410;
	Pt2[38].Y =  58;
	Pt2[39].X = 420;
	Pt2[39].Y =  48;
	Pt2[40].X = 430;
	Pt2[40].Y =  58;
	Pt2[41].Y =  48;
	Pt2[41].X = 440;
	Pt2[42].Y =  58;
	Pt2[42].X = 450;
	Pt2[43].Y =  48;
	Pt2[43].X = 460;
	Pt2[44].Y =  58;
	Pt2[44].X = 470;
	Pt2[45].Y =  48;
	Pt2[45].X = 480;
	Pt2[46].Y =  58;
	Pt2[46].X = 490;
	Pt2[47].Y =  48;
	Pt2[47].X = 500;
	Pt2[48].Y =  58;
	Pt2[48].X = 510;
	Pt2[49].Y =  48;
	Pt2[49].X = 520;
	Pt2[50].Y =  58;
	Pt2[50].X = 530;
	Pt2[51].Y =  48;
	Pt2[51].X = 540;
	Pt2[52].Y =  58;
	Pt2[52].X = 550;
	Pt2[53].Y =  48;
	Pt2[53].X = 560;
	Pt2[54].Y =  58;
	Pt2[54].X = 570;
	Pt2[55].Y =  48;
	Pt2[55].X = 580;
	Pt2[56].Y =  58;
	Pt2[56].X = 590;
	Pt2[57].Y =  48;
	Pt2[57].X = 600;
	Pt2[58].Y =  58;
	Pt2[58].X = 610;
	Pt2[59].Y =  48;
	Pt2[59].X = 620;
	Pt2[60].Y =  58;
	Pt2[60].X = 630;
	Pt2[61].Y =  48;
	Pt2[61].X = 640;
	Pt2[62].Y =  58;
	Pt2[62].X = 650;
	Pt2[63].Y =  48;
	Pt2[63].X = 660;
	Pt2[64].Y =  58;
	Pt2[64].X = 670;
	Pt2[65].Y =  48;
	Pt2[65].X = 680;
	Pt2[66].Y =  58;
	Pt2[66].X = 690;
	Pt2[67].Y =  48;
	Pt2[67].X = 700;
	Pt2[68].Y =  58;
	Pt2[68].X = 710;
	Pt2[69].Y =  48;
	Pt2[69].X = 720;
	Pt2[70].Y =  58;
	Pt2[70].X = 730;
	Pt2[71].Y =  48;
	Pt2[71].X = 740;
	Pt2[72].Y =  58;
	Pt2[72].X = 750;
	Pt2[73].Y =  48;
	Pt2[73].X = 760;
	Pt2[74].Y =  58;
	Pt2[74].X = 770;
	Pt2[75].Y =  48;
	Pt2[75].X = 780;
	Pt2[76].Y =  58;
	Pt2[76].X = 790;
	Pt2[77].Y =  48;
	Pt2[77].X = 800;
	Pt2[78].Y =  58;
	Pt2[78].X = 810;
	Pt2[79].Y =  48;
	Pt2[79].X = 820;
	Pt2[80].Y =  58;
	Pt2[80].X = 830;
	Pt2[81].Y =  48;
	Pt2[81].X = 840;
	Pt2[82].Y =  58;
	Pt2[82].X = 850;
	Pt2[83].Y =  48;
	Pt2[83].X = 860;
	Pt2[84].Y =  58;
	Pt2[84].X = 870;
	Pt2[85].Y =  48;
	Pt2[85].X = 880;
	Pt2[86].Y =  58;
	Pt2[86].X = 890;
	Pt2[87].Y =  48;
	Pt2[87].X = 900;
	Pt2[88].Y =  58;
	Pt2[88].X = 910;
	Pt2[89].Y =  48;
	Pt2[89].X = 920;
	Pt2[90].Y =  58;
	Pt2[90].X = 930;
	Pt2[91].Y =  48;
	Pt2[91].X = 940;
	Pt2[92].Y =  58;
	Pt2[92].X = 950;
	Pt2[93].Y =  48;
	Pt2[93].X = 960;
	Pt2[94].Y =  58;
	Pt2[94].X = 970;
	Pt2[95].Y =  48;
	Pt2[95].X = 980;
	Pt2[96].Y =  58;
	Pt2[96].X = 990;
	Pt2[97].Y =  48;
	Pt2[97].X = 1000;
	Pt2[98].Y =  58;
	Pt2[98].X = 1010;
	Pt2[99].Y =  48;
	Pt2[99].X = 1020;
	Pt2[100].Y =  58;
	Pt2[100].X = 1030;
	Pt2[101].Y =  48;
	Pt2[101].X = 1040;
	Pt2[102].Y =  58;
	Pt2[102].X = 1050;
	Pt2[103].Y =  48;
	Pt2[103].X = 1060;
	Pt2[104].Y =  58;
	Pt2[104].X = 1070;
	Pt2[105].Y =  48;
	Pt2[105].X = 1080;
	Pt2[106].Y =  58;
	Pt2[106].X = 1090;
	Pt2[107].Y =  48;
	Pt2[107].X = 1100;
	Pt2[108].Y =  58;
	Pt2[108].X = 1110;
	Pt2[109].Y =  48;
	Pt2[109].X = 1120;
	Pt2[110].Y =  58;
	Pt2[110].X = 1130;
	Pt2[111].Y =  48;
	Pt2[111].X = 1140;
	Pt2[112].Y =  58;
	Pt2[112].X = 1150;
	Pt2[113].Y =  48;
	Pt2[113].X = 1160;
	Pt2[114].Y =  58;
	Pt2[114].X = 1170;
	Pt2[115].Y =  48;
	Pt2[115].X = 1180;
	Pt2[116].Y =  58;
	Pt2[116].X = 1190;
	Pt2[117].Y =  48;
	Pt2[117].X = 1200;
	Pt2[118].Y =  58;
	Pt2[118].X = 1210;
	Pt2[119].Y =  48;
	Pt2[119].X = 1220;	
	Pt2[120].Y =  58;
	Pt2[120].X = 1230;
	Pt2[121].Y =  48;
	Pt2[121].X = 1240;
	Pt2[122].Y =  58;
	Pt2[122].X = 1250;
	Pt2[123].Y =  48;
	Pt2[123].X = 1260;
	Pt2[124].Y =  58;
	Pt2[124].X = 1270;
	Pt2[125].Y =  48;
	Pt2[125].X = 1280;
	Pt2[126].Y =  58;
	Pt2[126].X = 1290;
	Pt2[127].Y =  48;
	Pt2[127].X = 1300;
	Pt2[128].Y =  58;
	Pt2[128].X = 1310;
	Pt2[129].Y =  48;
	Pt2[129].X = 1320;
	Pt2[130].X = 1330;
	Pt2[130].Y =  58;
	Pt2[131].X =  40;
	Pt2[131].Y =  58;
	Pt2[132].X =  40;
	Pt2[132].Y =  48;
	Pt2[133].X = 1320;
	Pt2[133].Y =  48;



	graphics.DrawPolygon( &penCrane2, Pt2, 134 );

	Pen penCrane3 ( Color( 255, 255, 255 ) );
	PointF Pt3[ 6 ];
	Pt3[0].X =  40;
	Pt3[0].Y =  48;
	Pt3[1].X = 110;
	Pt3[1].Y =  20;
	Pt3[2].X = 160;
	Pt3[2].Y =  48;
	Pt3[3].X = 110;
	Pt3[3].Y =  20;
	Pt3[4].X = 240;
	Pt3[4].Y =  48;
	Pt3[5].X = 110;
	Pt3[5].Y =  20;
	

	graphics.DrawPolygon( &penCrane3, Pt3, 6 );


	Pen penCrane4 ( Color( 255, 255, 255 ) );
	PointF Pt4[ 13 ];
	Pt4[0].X =  12;
	Pt4[0].Y =  63;
	Pt4[1].X =  12;
	Pt4[1].Y =  43;
	Pt4[2].X =  19;
	Pt4[2].Y =  43;
	Pt4[3].X =  19;
	Pt4[3].Y =  63;
	Pt4[4].X =  26;
	Pt4[4].Y =  63;
	Pt4[5].X =  26;
	Pt4[5].Y =  43;
	Pt4[6].X =  33;
	Pt4[6].Y =  43;
	Pt4[7].X =  33;
	Pt4[7].Y =  63;
	Pt4[8].X =  40;
	Pt4[8].Y =  63;
	Pt4[9].X =  40;
	Pt4[9].Y =  43;
	Pt4[10].X =  12;
	Pt4[10].Y =  43;
	Pt4[11].X =  12;
	Pt4[11].Y =  63;
	Pt4[12].X =  40;
	Pt4[12].Y =  63;

	graphics.DrawPolygon( &penCrane4, Pt4, 13 );

	Pen penCrane5 ( Color( 255, 255, 255 ) );
	PointF Pt5[ 13 ];
	Pt5[0].X =  80;
	Pt5[0].Y = 670;
	Pt5[1].X = 130;
	Pt5[1].Y = 670;
	Pt5[2].X = 130;
	Pt5[2].Y = 665;
	Pt5[3].X =  80;
	Pt5[3].Y = 665;
	Pt5[4].X =  80;
	Pt5[4].Y = 660;
	Pt5[5].X = 130;
	Pt5[5].Y = 660;
	Pt5[6].X = 130;
	Pt5[6].Y = 655;
	Pt5[7].X =  80;
	Pt5[7].Y = 655;
	Pt5[8].X =  80;
	Pt5[8].Y = 650;
	Pt5[9].X = 130;
	Pt5[9].Y = 650;
	Pt5[10].X = 130;
	Pt5[10].Y = 670;
	Pt5[11].X =  80;
	Pt5[11].Y = 670;
	Pt5[12].X =  80;
	Pt5[12].Y = 650;

	graphics.DrawPolygon( &penCrane5, Pt5, 13 );

	Pen penCrane6 ( Color( 255, 255, 255 ) );
	PointF Pt6[ 20 ];
	Pt6[0].X =  95;
	Pt6[0].Y = 671;
	Pt6[1].X = 115;
	Pt6[1].Y = 671;
	Pt6[2].X = 115;
	Pt6[2].Y = 660;
	Pt6[3].X =  95;
	Pt6[3].Y = 660;
	Pt6[4].X =  95;
	Pt6[4].Y = 650;
	Pt6[5].X = 115;
	Pt6[5].Y = 650;
	Pt6[6].X = 115;
	Pt6[6].Y = 640;
	Pt6[7].X =  95;
	Pt6[7].Y = 640;
	Pt6[8].X =  95;
	Pt6[8].Y = 630;
	Pt6[9].X = 115;
	Pt6[9].Y = 630;
	Pt6[10].X = 115;
	Pt6[10].Y = 620;
	Pt6[11].X =  95;
	Pt6[11].Y = 620;
	Pt6[12].X =  92;
	Pt6[12].Y = 620;
	Pt6[13].X =  92;
	Pt6[13].Y = 614;
	Pt6[14].X = 118;
	Pt6[14].Y = 614;
	Pt6[15].X = 118;
	Pt6[15].Y = 620;
	Pt6[16].X = 115;
	Pt6[16].Y = 620;
	Pt6[17].X = 115;
	Pt6[17].Y = 671;
	Pt6[18].X =  95;
	Pt6[18].Y = 671;
	Pt6[19].X =  95;
	Pt6[19].Y = 620;
	

	graphics.DrawPolygon( &penCrane6, Pt6, 20 );


	Pen penCrane7 ( Color( 255, 255, 255 ) );
	PointF Pt7[ 9 ];
	Pt7[0].X =  70;
	Pt7[0].Y = 683;
	Pt7[1].X =  70;
	Pt7[1].Y = 680;
	Pt7[2].X = 100;
	Pt7[2].Y = 680;
	Pt7[3].X = 100;
	Pt7[3].Y = 683;
	Pt7[4].X = 100;
	Pt7[4].Y = 680;
	Pt7[5].X =  85;
	Pt7[5].Y = 680;
	Pt7[6].X = 100;
	Pt7[6].Y = 650;
	Pt7[7].X =  85;
	Pt7[7].Y = 680;
	Pt7[8].X =  70;
	Pt7[8].Y = 680;

	graphics.DrawPolygon( &penCrane7, Pt7, 9 );

	Pen penCrane8 ( Color( 255, 255, 255 ) );
	PointF Pt8[ 9 ];
	Pt8[0].X = 140;
	Pt8[0].Y = 683;
	Pt8[1].X = 140;
	Pt8[1].Y = 680;
	Pt8[2].X = 110;
	Pt8[2].Y = 680;
	Pt8[3].X = 110;
	Pt8[3].Y = 683;
	Pt8[4].X = 110;
	Pt8[4].Y = 680;
	Pt8[5].X = 125;
	Pt8[5].Y = 680;
	Pt8[6].X = 110;
	Pt8[6].Y = 650;
	Pt8[7].X = 125;
	Pt8[7].Y = 680;
	Pt8[8].X = 140;
	Pt8[8].Y = 680;

	graphics.DrawPolygon( &penCrane8, Pt8, 9 );


	Pen penCrane9 ( Color( 255, 255, 0 ) );
	PointF Pt9[ 5 ];
	Pt9[0].X =  98;
	Pt9[0].Y =  80;
	Pt9[1].X = 120;
	Pt9[1].Y =  80;
	Pt9[2].X = 120;
	Pt9[2].Y =  65;
	Pt9[3].X = 112;
	Pt9[3].Y =  72;
	Pt9[4].X = 98;
	Pt9[4].Y =  72;

	graphics.DrawPolygon( &penCrane9, Pt9, 5 );

	Pen penCrane10 ( Color( 255, 255, 255 ) );
	PointF Pt10[ 4 ];
	Pt10[0].X = 110;
	Pt10[0].Y =  60;
	Pt10[1].X = 120;
	Pt10[1].Y =  60;
	Pt10[2].X = 120;
	Pt10[2].Y =  65;
	Pt10[3].X = 120;
	Pt10[3].Y =  60;

	graphics.DrawPolygon( &penCrane10, Pt10, 4 );


}