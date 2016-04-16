
void ekranitemizle() {
	
	int i,j;
	
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			ekran[i][j]=0;
		}
	}
	
}

void yabancidiltemizle(struct yabancidil * a) {
	
	if(a->sonraki!=NULL) {
		yabancidiltemizle(a->sonraki);
	}
	
	free(a);
	a=NULL;
}

void okultemizle(struct egitim *a) {

	if(a->sonraki!=NULL) {
		okultemizle(a->sonraki);
	}
	
	free(a);
	a=NULL;
	
}

void isyeriadrestemizle(struct isyeriadresleri *a) {
	
	if(a->sonraki!=NULL) {
		isyeriadrestemizle(a->sonraki);
	}
	
	free(a);
	a=NULL;
	
}

void isyeritemizle(struct isyeri *a) {
	
	if(a->sonraki!=NULL) {
		isyeritemizle(a->sonraki);
	}
	
	isyeriadrestemizle(a->adres);
	free(a);
	a=NULL;
	
}

void kisiyitemizle(struct kisibilgi *a) {
	
	if(a->yabanci!=NULL) {
		yabancidiltemizle(a->yabanci);
	}
	
	if(a->okul!=NULL) {
		okultemizle(a->okul);
	}
	
	if(a->is!=NULL) {
		isyeritemizle(a->is);
	}
	
	memset(a,0,sizeof(struct kisibilgi));
	
	a->is=NULL;
	a->okul=NULL;
	a->yabanci=NULL;
}
