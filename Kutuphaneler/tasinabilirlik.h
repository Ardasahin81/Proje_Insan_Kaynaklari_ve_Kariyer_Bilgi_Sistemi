#ifdef _WIN32

	int oncekiekran[satir][sutun]={ };

	void pencereboyutunuayarla(){
		
		system("mode 113,31");
		
		
	}

	/** 3 karakter içerenler linux için(Windows'un varsayılan karakterlerinde yok)

	/ * *ust: u alt: a sag: s sol: o */

	char  _kos[2] = {205};
	char  _kua[2] = {186};
	char  _koa[2] = {187};
	char  _kuo[2] = {188};
	char  _ksa[2] = {201};
	char  _kus[2] = {200};
	char  _kosa[2] = {203};
	char  _kosua[2] = {206};
	char  _kosu[2] = {202};
	char  _kuao[2] = {185};
	char  _kuas[2] = {204};


	char  _ios[2] = {196};
	char  _iua[2] = {179};
	char  _ioa[2] = {191};
	char  _iuo[2] = {217};
	char  _isa[2] = {218};
	char  _ius[2] = {192};
	char  _iosa[2] = {194};
	char  _iosua[2] = {197};
	char  _iosu[2] = {193};
	char  _iuao[2] = {180};
	char  _iuas[2] = {195};

	char _ksaiou[4] = {-30,-107,-122};
	char _koaisu[4] = {-30,-107,-123};
	char _ksuioa[4] = {-30,-107,-124};
	char _kuoisa[4] = {-30,-107,-125};

	char _sagayatik[2] = {47};
	char _solayatik[2] = {92};
	char _carpi[2] = {88};

	char _tc[2]= { 135 };
	char _tC[2]= { 128};
	char _tg[2]= { 167 };
	char _tG[2]= { 166 };
	char _ti[2]= { 141 };
	char _tI[2]= { 152 };
	char _to[2]= { 148 };
	char _tO[2]= { 153 };
	char _ts[2]= { 159 };
	char _tS[2]= { 158 };
	char _tu[2]= { 129 };
	char _tU[2]= { 154 };

	char _kara[2] = {219 }; /* Siyah blok */
	char _karakare[2] = {254 }; /* Siyah kare blok */
	char _bayraksiyah[4] = {-30,-102,-111};
	char _bayrakbeyaz[4] = {-30,-102,-112};
	char _paragrafisareti[2] = {244};
	char _balikgozu[4] = {-30,-105,-119};
	char _ouboskure[4] = {-30,-105,-107};

	#include <conio.h>

	int tusal(void) {
		int i=1;
		int a[10]={ };

		a[0]=getch();
		while(kbhit())
			a[i++]=getch();

		if(a[0]==224 && a[1]==72) //YUKARI
			return 741;
		else if(a[0]==224 && a[1]==80) //AŞAĞI
			return 742;
		else if(a[0]==224 && a[1]==77) //SAĞA
			return 743;
		else if(a[0]==224 && a[1]==75) //SOLA
			return 744;
		else if(a[0]==0 && a[1]==59) //F1
			return 751;
		else if(a[0]==0 && a[1]==60) //F2
			return 752;
		else if(a[0]==0 && a[1]==61) //F3
			return 753;
		else if(a[0]==0 && a[1]==62) //F4
			return 754;
		else if(a[0]==0 && a[1]==63) //F5
			return 755;
		else if(a[0]==0 && a[1]==64) //F6
			return 756;
		else if(a[0]==0 && a[1]==65) //F7
			return 757;
		else if(a[0]==0 && a[1]==66) //F8
			return 758;
		else if(a[0]==224 && a[1]==83) //DELETE
			return 772;
		else if(a[0]==224 && a[1]==73) //PAGE UP
			return 774;
		else if(a[0]==224 && a[1]==81) //PAGE DOWN
			return 775;
		else if(a[0]==224 && a[1]==71) //HOME
			return 776;
		else if(a[0]==224 && a[1]==79) //END
			return 777;
		else if(a[0]==13 && a[1]==0) //ENTER
			return 778;
		else if(a[0]==8 || a[0]==127) //BACKSPACE
			return 773;
		else if(a[0]==9)//TAB
			return 771;
		else if(a[0]==27 && a[1]==0) //ESC
			return 770;
		else if(a[0]==135) //ç
			return 700;
		else if(a[0]==167) //ğ
			return 701;
		else if(a[0]==141) //ı
			return 702;
		else if(a[0]==148) //ö
			return 703;
		else if(a[0]==159) //ş
			return 704;
		else if(a[0]==129) //ü
			return 705;
		else if(a[0]==128) //Ç
			return 710;
		else if(a[0]==166) //Ğ
			return 711;
		else if(a[0]==152) //İ
			return 712;
		else if(a[0]==153) //Ö
			return 713;
		else if(a[0]==158) //Ş
			return 714;
		else if(a[0]==154) //Ü
			return 715;
		else if(a[0]<255)
			return a[0];
		return -1;
	}

	#include <windows.h>
	#include <stdbool.h>

	/**
	  * @PARAM:		x		ekranda gidilecek noktanin x koordinati
	  *				y		ekranda gidilecek noktanin y koordinati
	  *
	  * @OUTPUT:	Imleci konsol ekraninda belirtilen koordinata tasir.
	  */
	void GotoXY(short x, short y){ 
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; 
		COORD position = { x, y } ; 
		SetConsoleCursorPosition( hStdout, position ) ; 
	}
	void yazdir() {
		int i,j;
		GotoXY(0,0);
		for(i=0;i<satir;i++) {
			for(j=0;j<sutun;j++) {
				if(oncekiekran[i][j]!= ekran[i][j]) {
					GotoXY(j,i);
				switch (ekran[i][j]) {
					case 504:
						printf("%s",_ksa);
						break;
					case 604:
						printf("%s",_isa);
						break;
					case 500:
						printf("%s",_kos);
						break;
					case 600:
						printf("%s",_ios);
						break;
					case 501:
						printf("%s",_kua);
						break;
					case 601:
						printf("%s",_iua);
						break;
					case 502:
						printf("%s",_koa);
						break;
					case 602:
						printf("%s",_ioa);
						break;
					case 503:
						printf("%s",_kuo);
						break;
					case 603:
						printf("%s",_iuo);
						break;
					case 505:
						printf("%s",_kus);
						break;
					case 605:
						printf("%s",_ius);
						break;
					case 506:
						printf("%s",_kosa);
						break;
					case 606:
						printf("%s",_iosa);
						break;
					case 507:
						printf("%s",_kosua);
						break;
					case 607:
						printf("%s",_iosua);
						break;
					case 508:
						printf("%s",_kosu);
						break;
					case 608:
						printf("%s",_iosu);
						break;
					case 509:
						printf("%s",_kuao);
						break;
					case 609:
						printf("%s",_iuao);
						break;
					case 510:
						printf("%s",_kuas);
						break;
					case 610:
						printf("%s",_iuas);
						break;
					case 550:
						printf("%s",_ksaiou);
						break;
					case 551:
						printf("%s",_koaisu);
						break;
					case 552:
						printf("%s",_ksuioa);
						break;
					case 553:
						printf("%s",_kuoisa);
						break;
					case 541:
						printf("%s",_sagayatik);
						break;
					case 542:
						printf("%s",_solayatik);
						break;
					case 543:
						printf("%s",_carpi);
						break;
					case 700:
						printf("%s",_tc);
						break;
					case 701:
						printf("%s",_tg);
						break;
					case 702:
						printf("%s",_ti);
						break;
					case 703:
						printf("%s",_to);
						break;
					case 704:
						printf("%s",_ts);
						break;
					case 705:
						printf("%s",_tu);
						break;
					case 710:
						printf("%s",_tC);
						break;
					case 711:
						printf("%s",_tG);
						break;
					case 712:
						printf("%s",_tI);
						break;
					case 713:
						printf("%s",_tO);
						break;
					case 714:
						printf("%s",_tS);
						break;
					case 715:
						printf("%s",_tU);
						break;
					case 801:
						printf("%s",_kara);
						break;
					case 802:
						printf("%s",_karakare);
						break;
					case 811:
						printf("%s",_bayraksiyah);
						break;
					case 812:
						printf("%s",_bayrakbeyaz);
						break;
					case 813:
						printf("%s",_paragrafisareti);
						break;
					case 814:
						printf("%s",_balikgozu);
						break;
					case 815:
						printf("%s",_ouboskure);
					case 0:
						printf(" ");
						break;
					default:
						printf("%c",ekran[i][j]);
					
				}
				oncekiekran[i][j]=ekran[i][j];
				}
			}
			
			
			printf("\n");
			
		}
	}

	void syaz(char *a,int x,int y){ /** int ekran dizisinde x y koordinatlarına yazmak için (Türkçe karakterler) */
		int j,i=0;
		for(j=y;a[i]!=0;j++) {
			if(a[i]==-59) {
				if(a[i+1]==-97)
					ekran[x][j]=704;
				else if(a[i+1]==-98)
					ekran[x][j]=714;
				i++;
			} else if(a[i]==-60) {
				if(a[i+1]==-97)
					ekran[x][j]=701;
				else if(a[i+1]==-98)
					ekran[x][j]=711;
				else if(a[i+1]==-79)
					ekran[x][j]=702;
				else if(a[i+1]==-80)
					ekran[x][j]=712;
				i++;
			} else if(a[i]==-61) {
				if(a[i+1]==-89)
					ekran[x][j]=700;
				else if(a[i+1]==-121)
					ekran[x][j]=710;
				else if(a[i+1]==-74)
					ekran[x][j]=703;
				else if(a[i+1]==-106)
					ekran[x][j]=713;
				else if(a[i+1]==-68)
					ekran[x][j]=705;
				else if(a[i+1]==-100)
					ekran[x][j]=715;
				i++;
			} else{
				ekran[x][j]=a[i];
			}
			i++;
		}
	}

	void dosyayayazdir( int ** dizi, int x, int y,FILE *dosya) {
		
		int i,j;
		
		for(i=0;i<x;i++) {
			for(j=0;j<y;j++) {
				switch (dizi[i][j]) {
					case 504:
						fprintf(dosya,"%s",_ksa);
						break;
					case 604:
						fprintf(dosya,"%s",_isa);
						break;
					case 500:
						fprintf(dosya,"%s",_kos);
						break;
					case 600:
						fprintf(dosya,"%s",_ios);
						break;
					case 501:
						fprintf(dosya,"%s",_kua);
						break;
					case 601:
						fprintf(dosya,"%s",_iua);
						break;
					case 502:
						fprintf(dosya,"%s",_koa);
						break;
					case 602:
						fprintf(dosya,"%s",_ioa);
						break;
					case 503:
						fprintf(dosya,"%s",_kuo);
						break;
					case 603:
						fprintf(dosya,"%s",_iuo);
						break;
					case 505:
						fprintf(dosya,"%s",_kus);
						break;
					case 605:
						fprintf(dosya,"%s",_ius);
						break;
					case 506:
						fprintf(dosya,"%s",_kosa);
						break;
					case 606:
						fprintf(dosya,"%s",_iosa);
						break;
					case 507:
						fprintf(dosya,"%s",_kosua);
						break;
					case 607:
						fprintf(dosya,"%s",_iosua);
						break;
					case 508:
						fprintf(dosya,"%s",_kosu);
						break;
					case 608:
						fprintf(dosya,"%s",_iosu);
						break;
					case 509:
						fprintf(dosya,"%s",_kuao);
						break;
					case 609:
						fprintf(dosya,"%s",_iuao);
						break;
					case 510:
						fprintf(dosya,"%s",_kuas);
						break;
					case 610:
						fprintf(dosya,"%s",_iuas);
						break;
					case 550:
						fprintf(dosya,"%s",_ksaiou);
						break;
					case 551:
						fprintf(dosya,"%s",_koaisu);
						break;
					case 552:
						fprintf(dosya,"%s",_ksuioa);
						break;
					case 553:
						fprintf(dosya,"%s",_kuoisa);
						break;
					case 541:
						fprintf(dosya,"%s",_sagayatik);
						break;
					case 542:
						fprintf(dosya,"%s",_solayatik);
						break;
					case 543:
						fprintf(dosya,"%s",_carpi);
						break;
					case 700:
						fprintf(dosya,"ç");
						break;
					case 701:
						fprintf(dosya,"ğ");
						break;
					case 702:
						fprintf(dosya,"ı");
						break;
					case 703:
						fprintf(dosya,"ö");
						break;
					case 704:
						fprintf(dosya,"ş");
						break;
					case 705:
						fprintf(dosya,"ü");
						break;
					case 710:
						fprintf(dosya,"Ç");
						break;
					case 711:
						fprintf(dosya,"Ğ");
						break;
					case 712:
						fprintf(dosya,"İ");
						break;
					case 713:
						fprintf(dosya,"Ö");
						break;
					case 714:
						fprintf(dosya,"Ş");
						break;
					case 715:
						fprintf(dosya,"Ü");
						break;
					case 801:
						fprintf(dosya,"%s",_kara);
						break;
					case 802:
						fprintf(dosya,"%s",_karakare);
						break;
					case 811:
						fprintf(dosya,"%s",_bayraksiyah);
						break;
					case 812:
						fprintf(dosya,"%s",_bayrakbeyaz);
						break;
					case 813:
						fprintf(dosya,"%s",_paragrafisareti);
						break;
					case 814:
						fprintf(dosya,"%s",_balikgozu);
						break;
					case 815:
						fprintf(dosya,"%s",_ouboskure);
					case 0:
						fprintf(dosya," ");
						break;
					case 401:
						j=y;
						break;
					default:
						fprintf(dosya,"%c",dizi[i][j]);
					
				}
			}
			
			fprintf(dosya,"\n");
			
		}
		
	}


#else

	void pencereboyutunuayarla(){
		
		system("printf '\e[8;31;113t'");
		
		
	}

	/**ust: u alt: a sağ: s sol: o */
	char  _kos[4] = {-30,-108,-127};
	char  _kua[4] = {-30,-108,-125};
	char  _koa[4] = {-30,-108,-109};
	char  _kuo[4] = {-30,-108,-101};
	char  _ksa[4] = {-30,-108,-113};
	char  _kus[4] = {-30,-108,-105};
	char  _kosa[4] = {-30,-108,-77};
	char  _kosua[4] = {-30,-107,-117};
	char  _kosu[4] = {-30,-108,-69};
	char  _kuao[4] = {-30,-108,-85};
	char  _kuas[4] = {-30,-108,-93};


	char  _ios[4] = {-30,-108,-128};
	char  _iua[4] = {-30,-108,-126};
	char  _ioa[4] = {-30,-108,-112};
	char  _iuo[4] = {-30,-108,-104};
	char  _isa[4] = {-30,-108,-116};
	char  _ius[4] = {-30,-108,-108};
	char  _iosa[4] = {-30,-108,-84};
	char  _iosua[4] = {-30,-108,-68};
	char  _iosu[4] = {-30,-108,-76};
	char  _iuao[4] = {-30,-108,-92};
	char  _iuas[4] = {-30,-108,-100};

	char _ksaiou[4] = {-30,-107,-122};
	char _koaisu[4] = {-30,-107,-123};
	char _ksuioa[4] = {-30,-107,-124};
	char _kuoisa[4] = {-30,-107,-125};

	char _sagayatik[4] = {-30,-107,-79};
	char _solayatik[4] = {-30,-107,-78};
	char _carpi[4] = {-30,-107,-77};

	char _tc[3]= { -61,-89 };
	char _tC[3]= { -61,-121 };
	char _tg[3]= { -60,-97 };
	char _tG[3]= { -60,-98 };
	char _ti[3]= { -60,-79 };
	char _tI[3]= { -60,-80 };
	char _to[3]= { -61,-74 };
	char _tO[3]= { -61,-106 };
	char _ts[3]= { -59,-97 };
	char _tS[3]= { -59,-98 };
	char _tu[3]= { -61,-68 };
	char _tU[3]= { -61,-100 };

	char _kara[4] = {-30,-106,-120 }; /* Siyah blok */
	char _karakare[4] = {-30,-106,-96 }; /* Siyah kare blok */
	char _bayraksiyah[4] = {-30,-102,-111};
	char _bayrakbeyaz[4] = {-30,-102,-112};
	char _paragrafisareti[3] = {-62,-74};
	char _balikgozu[4] = {-30,-105,-119};
	char _ouboskure[4] = {-30,-105,-107};

	#include <unistd.h>
	#include <fcntl.h>
	#include <termios.h>

	int kbhit(void) {
	  struct termios oldt, newt;
	  int ch;
	  int oldf;
	 
	  tcgetattr(STDIN_FILENO, &oldt);
	  newt = oldt;
	  newt.c_lflag &= ~(ICANON | ECHO);
	  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	 
	  ch = getchar();
	 
	  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	  fcntl(STDIN_FILENO, F_SETFL, oldf);
	 
	  if(ch != EOF)
	  {
		ungetc(ch, stdin);
		return 1;
	  }
	 
	  return 0;
	}
	static struct termios old, new;

	void initTermios(int echo) {
	  tcgetattr(0, &old); /* grab old terminal i/o settings */
	  new = old; /* make new settings same as old settings */
	  new.c_lflag &= ~ICANON; /* disable buffered i/o */
	  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
	}

	void resetTermios(void) {
	  tcsetattr(0, TCSANOW, &old);
	}

	char getch_(int echo) {
	  char ch;
	  initTermios(echo);
	  ch = getchar();
	  resetTermios();
	  return ch;
	}

	char getch(void) {
	  return getch_(0);
	}

	char getche(void) {
	  return getch_(1);
	}

	int tusal(void) {
		int i=1;
		int a[10]={ };
		
		a[0]=getch();
		while(kbhit())
			a[i++]=getch();
		
		if(a[0]==27 && a[1]==91 && a[2]==65) //YUKARI
			return 741;
		else if(a[0]==27 && a[1]==91 && a[2]==66) //AŞAĞI
			return 742;
		else if(a[0]==27 && a[1]==91 && a[2]==67) //SAĞA
			return 743;
		else if(a[0]==27 && a[1]==91 && a[2]==68) //SOLA
			return 744;
		else if(a[0]==27 && a[1]==79 && a[2]==80) //F1
			return 751;
		else if(a[0]==27 && a[1]==79 && a[2]==81) //F2
			return 752;
		else if(a[0]==27 && a[1]==79 && a[2]==82) //F3
			return 753;
		else if(a[0]==27 && a[1]==79 && a[2]==83) //F4
			return 754;
		else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==53 && a[4]==126) //F5
			return 755;
		else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==55 && a[4]==126) //F6
			return 756;
		else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==56 && a[4]==126) //F7
			return 757;
		else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==57 && a[4]==126) //F8
			return 758;
		else if(a[0]==27 && a[1]==91 && a[2]==51 && a[3]==126) //DELETE
			return 772;
		else if(a[0]==27 && a[1]==91 && a[2]==53 && a[3]==126) //PAGE UP
			return 774;
		else if(a[0]==27 && a[1]==91 && a[2]==54 && a[3]==126) //PAGE DOWN
			return 775;
		else if(a[0]==27 && a[1]==91 && a[2]==72) //HOME
			return 776;
		else if(a[0]==27 && a[1]==91 && a[2]==70) //END
			return 777;
		else if(a[0]==10 && a[1]==0) 
			return 778;
		else if(a[0]==8 || a[0]==127) //BACKSPACE
			return 773;
		else if(a[0]==9)//TAB
			return 771;
		else if(a[0]==27 && a[1]==0) //ESC
			return 770;
		else if(a[0]==-61 && a[1]==-89) //ç
			return 700;
		else if(a[0]==-60 && a[1]==-97) //ğ
			return 701;
		else if(a[0]==-60 && a[1]==-79) //ı
			return 702;
		else if(a[0]==-61 && a[1]==-74) //ö
			return 703;
		else if(a[0]==-59 && a[1]==-97) //ş
			return 704;
		else if(a[0]==-61 && a[1]==-68) //ü
			return 705;
		else if(a[0]==-61 && a[1]==-121) //Ç
			return 710;
		else if(a[0]==-60 && a[1]==-98) //Ğ
			return 711;
		else if(a[0]==-60 && a[1]==-80) //İ
			return 712;
		else if(a[0]==-61 && a[1]==-106) //Ö
			return 713;
		else if(a[0]==-59 && a[1]==-98) //Ş
			return 714;
		else if(a[0]==-61 && a[1]==-100) //Ü
			return 715;
		else if(a[0]<255)
			return a[0];
		return -1;
	}

	void yazdir() {
		int i,j;
		system("clear");
		for(i=0;i<satir;i++) {
			for(j=0;j<sutun;j++) {
				switch (ekran[i][j]) {
					case 504:
						printf("%s",_ksa);
						break;
					case 604:
						printf("%s",_isa);
						break;
					case 500:
						printf("%s",_kos);
						break;
					case 600:
						printf("%s",_ios);
						break;
					case 501:
						printf("%s",_kua);
						break;
					case 601:
						printf("%s",_iua);
						break;
					case 502:
						printf("%s",_koa);
						break;
					case 602:
						printf("%s",_ioa);
						break;
					case 503:
						printf("%s",_kuo);
						break;
					case 603:
						printf("%s",_iuo);
						break;
					case 505:
						printf("%s",_kus);
						break;
					case 605:
						printf("%s",_ius);
						break;
					case 506:
						printf("%s",_kosa);
						break;
					case 606:
						printf("%s",_iosa);
						break;
					case 507:
						printf("%s",_kosua);
						break;
					case 607:
						printf("%s",_iosua);
						break;
					case 508:
						printf("%s",_kosu);
						break;
					case 608:
						printf("%s",_iosu);
						break;
					case 509:
						printf("%s",_kuao);
						break;
					case 609:
						printf("%s",_iuao);
						break;
					case 510:
						printf("%s",_kuas);
						break;
					case 610:
						printf("%s",_iuas);
						break;
					case 550:
						printf("%s",_ksaiou);
						break;
					case 551:
						printf("%s",_koaisu);
						break;
					case 552:
						printf("%s",_ksuioa);
						break;
					case 553:
						printf("%s",_kuoisa);
						break;
					case 541:
						printf("%s",_sagayatik);
						break;
					case 542:
						printf("%s",_solayatik);
						break;
					case 543:
						printf("%s",_carpi);
						break;
					case 700:
						printf("%s",_tc);
						break;
					case 701:
						printf("%s",_tg);
						break;
					case 702:
						printf("%s",_ti);
						break;
					case 703:
						printf("%s",_to);
						break;
					case 704:
						printf("%s",_ts);
						break;
					case 705:
						printf("%s",_tu);
						break;
					case 710:
						printf("%s",_tC);
						break;
					case 711:
						printf("%s",_tG);
						break;
					case 712:
						printf("%s",_tI);
						break;
					case 713:
						printf("%s",_tO);
						break;
					case 714:
						printf("%s",_tS);
						break;
					case 715:
						printf("%s",_tU);
						break;
					case 801:
						printf("%s",_kara);
						break;
					case 802:
						printf("%s",_karakare);
						break;
					case 811:
						printf("%s",_bayraksiyah);
						break;
					case 812:
						printf("%s",_bayrakbeyaz);
						break;
					case 813:
						printf("%s",_paragrafisareti);
						break;
					case 814:
						printf("%s",_balikgozu);
						break;
					case 815:
						printf("%s",_ouboskure);
					case 0:
						printf(" ");
						break;
					default:
						printf("%c",ekran[i][j]);
					
				}
			}
			
			
			printf("\n");
			
		}
	}

	void syaz(char *a,int x,int y){ /** int ekran dizisinde x y koordinatlarına yazmak için (Türkçe karakterler) */
		int j,i=0;
		for(j=y;a[i]!=0;j++) {
			if(a[i]==-59) {
				if(a[i+1]==-97)
					ekran[x][j]=704;
				else if(a[i+1]==-98)
					ekran[x][j]=714;
				i++;
			} else if(a[i]==-60) {
				if(a[i+1]==-97)
					ekran[x][j]=701;
				else if(a[i+1]==-98)
					ekran[x][j]=711;
				else if(a[i+1]==-79)
					ekran[x][j]=702;
				else if(a[i+1]==-80)
					ekran[x][j]=712;
				i++;
			} else if(a[i]==-61) {
				if(a[i+1]==-89)
					ekran[x][j]=700;
				else if(a[i+1]==-121)
					ekran[x][j]=710;
				else if(a[i+1]==-74)
					ekran[x][j]=703;
				else if(a[i+1]==-106)
					ekran[x][j]=713;
				else if(a[i+1]==-68)
					ekran[x][j]=705;
				else if(a[i+1]==-100)
					ekran[x][j]=715;
				i++;
			} else{
				ekran[x][j]=a[i];
			}
			i++;
		}
	}

	void dosyayayazdir( int ** dizi, int x, int y,FILE *dosya) {
		
		int i,j;
		
		for(i=0;i<x;i++) {
			for(j=0;j<y;j++) {
				switch (dizi[i][j]) {
					case 504:
						fprintf(dosya,"%s",_ksa);
						break;
					case 604:
						fprintf(dosya,"%s",_isa);
						break;
					case 500:
						fprintf(dosya,"%s",_kos);
						break;
					case 600:
						fprintf(dosya,"%s",_ios);
						break;
					case 501:
						fprintf(dosya,"%s",_kua);
						break;
					case 601:
						fprintf(dosya,"%s",_iua);
						break;
					case 502:
						fprintf(dosya,"%s",_koa);
						break;
					case 602:
						fprintf(dosya,"%s",_ioa);
						break;
					case 503:
						fprintf(dosya,"%s",_kuo);
						break;
					case 603:
						fprintf(dosya,"%s",_iuo);
						break;
					case 505:
						fprintf(dosya,"%s",_kus);
						break;
					case 605:
						fprintf(dosya,"%s",_ius);
						break;
					case 506:
						fprintf(dosya,"%s",_kosa);
						break;
					case 606:
						fprintf(dosya,"%s",_iosa);
						break;
					case 507:
						fprintf(dosya,"%s",_kosua);
						break;
					case 607:
						fprintf(dosya,"%s",_iosua);
						break;
					case 508:
						fprintf(dosya,"%s",_kosu);
						break;
					case 608:
						fprintf(dosya,"%s",_iosu);
						break;
					case 509:
						fprintf(dosya,"%s",_kuao);
						break;
					case 609:
						fprintf(dosya,"%s",_iuao);
						break;
					case 510:
						fprintf(dosya,"%s",_kuas);
						break;
					case 610:
						fprintf(dosya,"%s",_iuas);
						break;
					case 550:
						fprintf(dosya,"%s",_ksaiou);
						break;
					case 551:
						fprintf(dosya,"%s",_koaisu);
						break;
					case 552:
						fprintf(dosya,"%s",_ksuioa);
						break;
					case 553:
						fprintf(dosya,"%s",_kuoisa);
						break;
					case 541:
						fprintf(dosya,"%s",_sagayatik);
						break;
					case 542:
						fprintf(dosya,"%s",_solayatik);
						break;
					case 543:
						fprintf(dosya,"%s",_carpi);
						break;
					case 700:
						fprintf(dosya,"%s",_tc);
						break;
					case 701:
						fprintf(dosya,"%s",_tg);
						break;
					case 702:
						fprintf(dosya,"%s",_ti);
						break;
					case 703:
						fprintf(dosya,"%s",_to);
						break;
					case 704:
						fprintf(dosya,"%s",_ts);
						break;
					case 705:
						fprintf(dosya,"%s",_tu);
						break;
					case 710:
						fprintf(dosya,"%s",_tC);
						break;
					case 711:
						fprintf(dosya,"%s",_tG);
						break;
					case 712:
						fprintf(dosya,"%s",_tI);
						break;
					case 713:
						fprintf(dosya,"%s",_tO);
						break;
					case 714:
						fprintf(dosya,"%s",_tS);
						break;
					case 715:
						fprintf(dosya,"%s",_tU);
						break;
					case 801:
						fprintf(dosya,"%s",_kara);
						break;
					case 802:
						fprintf(dosya,"%s",_karakare);
						break;
					case 811:
						fprintf(dosya,"%s",_bayraksiyah);
						break;
					case 812:
						fprintf(dosya,"%s",_bayrakbeyaz);
						break;
					case 813:
						fprintf(dosya,"%s",_paragrafisareti);
						break;
					case 814:
						fprintf(dosya,"%s",_balikgozu);
						break;
					case 815:
						fprintf(dosya,"%s",_ouboskure);
					case 0:
						fprintf(dosya," ");
						break;
					case 401:
						j=y;
						break;
					default:
						fprintf(dosya,"%c",dizi[i][j]);
					
				}
			}
			
			fprintf(dosya,"\n");
			
		}
		
	}

#endif

