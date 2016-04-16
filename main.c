#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define satir 25
#define sutun 113
#define agacdosya "kullanicibilgileri.bin"

int ekran[satir][sutun]= { };
int tus=0;

struct yabancidil {
	int dil[16];
	struct yabancidil * sonraki;
};

struct egitim {
	int adi[41];
	int turu[14];
	int bolum[31];
	char baslangic[5];
	char bitis[5];
	int not;
	struct egitim * sonraki;
};

struct isyeriadresleri {
	int sehir[12];
	struct isyeriadresleri * sonraki;
	
};

struct isyeri {
	int adi[36];
	int gorevi[41];
	float sure;
	int adressayisi;
	struct isyeriadresleri* adres;
	struct isyeri *sonraki;
};

struct kisibilgi {
	int adsoyad[26];
	int adres[12];
	char tel[11];
	char email[36];
	int dogumt;
	char ehliyet[20];
	int duzey;
	int okulsayisi;
	struct egitim* okul;
	int isyerisayisi;
	struct isyeri* is;
	int yabancidilsayisi;
	struct yabancidil* yabanci;
};

struct dugum {
	struct kisibilgi kisi;
	struct dugum *sol;
	struct dugum *sag; 
};

struct dugum *root=NULL;

int toplamkayit=0,derinlik=0;

void dosyahata();


#include "Kutuphaneler/tasinabilirlik.h"
#include "Kutuphaneler/temizle.h"
#include "Kutuphaneler/cizimler.h"
#include "Kutuphaneler/intstring.h"
#include "Kutuphaneler/eklecikar.h"
#include "Kutuphaneler/alim.h"
#include "Kutuphaneler/agac.h"
#include "Kutuphaneler/basvuru.h"
#include "Kutuphaneler/filtre.h"
#include "Kutuphaneler/listeleme.h"
#include "Kutuphaneler/giris.h"


void dosyahata() {
	ekranitemizle();
	
	syaz("DOSYA İŞLEMLERİ SIRASINDA HATA OLUŞTU!",10,10);
	yazdir();
	
	tusal();
	
	exit(1);
	
}


int main() {
	
	pencereboyutunuayarla();
	
	/** Dosya yoksa oluşturma işlemi */
	
	FILE *dosya=fopen(agacdosya,"rb");
	
	if(dosya==NULL) {
		dosya=fopen(agacdosya,"wb");
		if(dosya==NULL) {
			dosyahata();
		}
	} 
	fclose(dosya);
	
	agacioku();
	
	
	giris();
	
	
	
	return 0;
}
