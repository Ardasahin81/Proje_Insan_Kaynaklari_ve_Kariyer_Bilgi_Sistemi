
void okulekle(struct kisibilgi * a,int * okuladi,int * okulturu, int * okulbolumu, char *baslangict, char *bitist, int notu) {
	
	struct egitim *ekle=(struct egitim *) malloc(sizeof(struct egitim));
	
	strcpyintint(ekle->adi,okuladi);
	strcpyintint(ekle->turu,okulturu);
	strcpyintint(ekle->bolum,okulbolumu);
	strcpy(ekle->baslangic,baslangict);
	strcpy(ekle->bitis,bitist);
	ekle->not=notu;
	ekle->sonraki=NULL;
	
	
	
	if(a->okul==NULL) {
		
		a->okul=ekle;
		
		
	} else {
		struct egitim * e=a->okul;
		while(e->sonraki!=NULL) {
			e=e->sonraki;
		}
		e->sonraki=ekle;
		
	}
	a->okulsayisi++;
}

void isyeriekle(struct kisibilgi *a,int *isadi, int *isgorev, float suresi, struct isyeriadresleri * adresi,int adressayi) {
	
	
	struct isyeri *ekle=(struct isyeri *) malloc(sizeof(struct isyeri));
	
	strcpyintint(ekle->adi,isadi);
	strcpyintint(ekle->gorevi,isgorev);
	ekle->sure=suresi;
	ekle->adres=adresi;
	ekle->sonraki=NULL;
	ekle->adressayisi=adressayi;
	
	if(a->is==NULL) {
		
		a->is=ekle;
		
	} else {
		
		struct isyeri * e=a->is;
		
		while(e->sonraki!=NULL) {
			e=e->sonraki;
		}
		
		e->sonraki=ekle;
		
	}
	a->isyerisayisi++;
}

void yabancidilekle(struct kisibilgi * a,int *dili) {
	
	if(a->yabanci==NULL) {
		a->yabanci=(struct yabancidil *) malloc(sizeof(struct yabancidil));
		strcpyintint(a->yabanci->dil,dili);
		a->yabanci->sonraki=NULL;
	} else {
		struct yabancidil *e=a->yabanci;
		
		while(e->sonraki!=NULL) {
			e=e->sonraki;
		}
		
		e->sonraki=(struct yabancidil *) malloc(sizeof(struct yabancidil));
		strcpyintint(e->sonraki->dil,dili);
		e->sonraki->sonraki=NULL;
		
	}
	a->yabancidilsayisi++;
}

int yabancidilsil(struct kisibilgi * a,int *dili) {
	
	if(karsilastirint(a->yabanci->dil,dili)==0) {
		
		struct yabancidil *sil=a->yabanci;
		
		if(a->yabancidilsayisi==1) {
			a->yabanci=NULL;
		} else {
			a->yabanci=a->yabanci->sonraki;
		}
		a->yabancidilsayisi--;
		free(sil);
		
	} else {
		
		struct yabancidil *e=a->yabanci;
		
		while(1) {
			if(e->sonraki==NULL) {
				return -1;
			}
			if(karsilastirint(e->sonraki->dil,dili)!=0) {
				e=e->sonraki;
			} else {
				break;
			}
		}
		
		struct yabancidil *sil=e->sonraki;
		
		e->sonraki=e->sonraki->sonraki;
		
		free(sil);
		a->yabancidilsayisi--;
		return 0;
	}
	
	return -1;
}

int okulsil(struct kisibilgi * a,int sira) {
	
	int i;
	if(sira==1) {
		struct egitim *sil=a->okul;
		
		a->okul=a->okul->sonraki;
		
		free(sil);
		
	} else {
		
		struct egitim *e=a->okul;
		
		for(i=2;i<sira;i++) {
			e=e->sonraki;
		}
		struct egitim *sil=e->sonraki;
		
		e->sonraki=e->sonraki->sonraki;
		
		free(sil);
	}
	
	a->okulsayisi--;
	return 0;
}

int isyerisil(struct kisibilgi * a,int sira) {
	
	int i;
	
	if(sira==1) {
		struct isyeri *sil=a->is;
		a->is=a->is->sonraki;
		free(sil);
	} else {
		struct isyeri *e=a->is;
		
		for(i=2;i<sira;i++) {
			e=e->sonraki;
		}
		struct isyeri *sil=e->sonraki;
		e->sonraki=e->sonraki->sonraki;
		isyeriadrestemizle(sil->adres);
		free(sil);
	}
	a->isyerisayisi--;
	return 0;
}
