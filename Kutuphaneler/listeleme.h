
int listebirsatir=0,listebirsatiratla=0,listeikisatir=0,listeucsatir=0;



void duzeyhesapla(struct dugum *a, int duzey) {
	
	if(a==NULL) {
		return;
	}
	
	a->kisi.duzey=duzey;
	
	duzeyhesapla(a->sol,duzey+1);
	duzeyhesapla(a->sag,duzey+1);
	
}

void derinlik_toplamkayit(struct dugum *a) {
	
	if(a==NULL) {
		return;
	}
	
	if(a->kisi.duzey>=derinlik) {
		derinlik=a->kisi.duzey+1;
	}
	
	toplamkayit++;
	
	derinlik_toplamkayit(a->sol);
	derinlik_toplamkayit(a->sag);
	
}

void listebirsatirsay(struct dugum *a) {
	
	if(a==NULL) {
		return;
	}
	listebirsatir+=3;
	
	struct yabancidil * e=a->kisi.yabanci;
	
	if(e==NULL) {
		listebirsatir++;
	}
	
	while(e!=NULL) {
		
		listebirsatir++;
		e=e->sonraki;
		
	}
	
	
	listebirsatirsay(a->sol);
	listebirsatirsay(a->sag);
}

void listeikisatirsay(struct dugum *a) {
	
	if(a==NULL) {
		return;
	}
	listeikisatir+=3;
	
	struct egitim * e=a->kisi.okul;
	
	
	while(e!=NULL) {
		
		listeikisatir++;
		e=e->sonraki;
		
	}
	
	listeikisatirsay(a->sol);
	listeikisatirsay(a->sag);
	
}

void listeucsatirsay(struct dugum *a) {
	
	if(a==NULL) {
		return;
	}
	listeucsatir+=3;
	
	struct isyeri * e=a->kisi.is;
	
	
	while(e!=NULL) {
		
		struct isyeriadresleri *e2=e->adres;
		
		while(e2!=NULL) {
			listeucsatir++;
			e2=e2->sonraki;
		}
		
		e=e->sonraki;
		
	}
	
	listeucsatirsay(a->sol);
	listeucsatirsay(a->sag);
	
	
}

void listebirisirala(int ** listebir,struct dugum *a,int si) {
	
	if(a==NULL) {
		return;
	}
	
	if(si==1) { //inorder
		listebirisirala(listebir,a->sol,si);
		
		if(filtre_varmi==1) {
			
			int uyarmi=1;
			
			if(filtre[0]==1) {
				if(enazlisansmi(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[1]==1) {
				if(ingilizcebiliyormu(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[2]==1) {
				if(birdenfazladilbiliyormu(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[3]==1) {
				if(min_deneyim(a->kisi,deneyimsuresi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[4]==1) {
				if(deneyimsizmi(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[5]==1) {
				if(min_yas(a->kisi,yas)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[6]==1) {
				if(ehliyet_varmi(a->kisi,ehliyettipi)!=1) {
					uyarmi=0;
				}
			}
			if(uyarmi==1) {
				strcpyintint(listebir[listebirsatiratla]+0,a->kisi.adsoyad);
				int i;
				for(i=0;i<76;i++) {
					listebir[listebirsatiratla][i+25]='-';
				}
				char duzeyyaz[4]={ };
				
				sprintf(duzeyyaz,"%3d",a->kisi.duzey);
				
				strcpyint(listebir[listebirsatiratla]+101,duzeyyaz);
				
				listebirsatiratla+=2;
				
				strcpyintint(listebir[listebirsatiratla]+1,a->kisi.adres);
				strcpyint(listebir[listebirsatiratla]+13,a->kisi.tel);
				char emyaz[36]={ };
				if(strlen(a->kisi.email)>30) {
					strcpy(emyaz,a->kisi.email);
					sprintf(emyaz+28,"..");
					
					strcpyint(listebir[listebirsatiratla]+26,emyaz);
				} else {
					strcpyint(listebir[listebirsatiratla]+26,a->kisi.email);
				}
				
				char dtyaz[5]={ };
				sprintf(dtyaz,"%d",a->kisi.dogumt);
				strcpyint(listebir[listebirsatiratla]+57,dtyaz);
				
				
				
				strcpyint(listebir[listebirsatiratla]+67,a->kisi.ehliyet);
				
				struct yabancidil *e=a->kisi.yabanci;
				
				if(e==NULL) {
					listebirsatiratla++;
				}
				
				while(e!=NULL) {
					
					strcpyintint(listebir[listebirsatiratla++]+87,e->dil);
					
					e=e->sonraki;
					
				}
				
				listebirsatiratla++;
			}
			
			
			
		} else {
			strcpyintint(listebir[listebirsatiratla]+0,a->kisi.adsoyad);
			int i;
			for(i=0;i<76;i++) {
				listebir[listebirsatiratla][i+25]='-';
			}
			char duzeyyaz[4]={ };
			
			sprintf(duzeyyaz,"%3d",a->kisi.duzey);
			
			strcpyint(listebir[listebirsatiratla]+101,duzeyyaz);
			
			listebirsatiratla+=2;
			
			strcpyintint(listebir[listebirsatiratla]+1,a->kisi.adres);
			strcpyint(listebir[listebirsatiratla]+13,a->kisi.tel);
			char emyaz[36]={ };
			if(strlen(a->kisi.email)>30) {
				strcpy(emyaz,a->kisi.email);
				sprintf(emyaz+28,"..");
				
				strcpyint(listebir[listebirsatiratla]+26,emyaz);
			} else {
				strcpyint(listebir[listebirsatiratla]+26,a->kisi.email);
			}
			
			char dtyaz[5]={ };
			sprintf(dtyaz,"%d",a->kisi.dogumt);
			strcpyint(listebir[listebirsatiratla]+57,dtyaz);
			
			
			
			strcpyint(listebir[listebirsatiratla]+67,a->kisi.ehliyet);
			
			struct yabancidil *e=a->kisi.yabanci;
			
			if(e==NULL) {
				listebirsatiratla++;
			}
			
			while(e!=NULL) {
				
				strcpyintint(listebir[listebirsatiratla++]+87,e->dil);
				
				e=e->sonraki;
				
			}
			
			listebirsatiratla++;
		}
		listebirisirala(listebir,a->sag,si);
	} else if(si==2) { //postorder
		
		listebirisirala(listebir,a->sol,si);
		listebirisirala(listebir,a->sag,si);
		
		strcpyintint(listebir[listebirsatiratla]+0,a->kisi.adsoyad);
		int i;
		for(i=0;i<76;i++) {
			listebir[listebirsatiratla][i+25]='-';
		}
		char duzeyyaz[4]={ };
		
		sprintf(duzeyyaz,"%3d",a->kisi.duzey);
		
		strcpyint(listebir[listebirsatiratla]+101,duzeyyaz);
		listebirsatiratla+=2;
		
		strcpyintint(listebir[listebirsatiratla]+1,a->kisi.adres);
		strcpyint(listebir[listebirsatiratla]+13,a->kisi.tel);
		char emyaz[36]={ };
		if(strlen(a->kisi.email)>30) {
			strcpy(emyaz,a->kisi.email);
			sprintf(emyaz+29,"..");
			
			strcpyint(listebir[listebirsatiratla]+26,emyaz);
		} else {
			strcpyint(listebir[listebirsatiratla]+26,a->kisi.email);
		}
		
		char dtyaz[5]={ };
		sprintf(dtyaz,"%d",a->kisi.dogumt);
		strcpyint(listebir[listebirsatiratla]+57,dtyaz);
		
		
		
		strcpyint(listebir[listebirsatiratla]+67,a->kisi.ehliyet);
		
		struct yabancidil *e=a->kisi.yabanci;
		if(e==NULL) {
			listebirsatiratla++;
		}
		
		while(e!=NULL) {
			
			strcpyintint(listebir[listebirsatiratla++]+87,e->dil);
			
			e=e->sonraki;
			
		}
		
		listebirsatiratla++;
		
		
		
		
	} else if(si==3) { //preorder
		
		strcpyintint(listebir[listebirsatiratla]+0,a->kisi.adsoyad);
		int i;
		for(i=0;i<76;i++) {
			listebir[listebirsatiratla][i+25]='-';
		}
		char duzeyyaz[4]={ };
		
		sprintf(duzeyyaz,"%3d",a->kisi.duzey);
		
		strcpyint(listebir[listebirsatiratla]+101,duzeyyaz);
		listebirsatiratla+=2;
		
		strcpyintint(listebir[listebirsatiratla]+1,a->kisi.adres);
		strcpyint(listebir[listebirsatiratla]+13,a->kisi.tel);
		char emyaz[36]={ };
		if(strlen(a->kisi.email)>30) {
			strcpy(emyaz,a->kisi.email);
			sprintf(emyaz+29,"..");
			
			strcpyint(listebir[listebirsatiratla]+26,emyaz);
		} else {
			strcpyint(listebir[listebirsatiratla]+26,a->kisi.email);
		}
		
		char dtyaz[5]={ };
		sprintf(dtyaz,"%d",a->kisi.dogumt);
		strcpyint(listebir[listebirsatiratla]+57,dtyaz);
		
		
		
		strcpyint(listebir[listebirsatiratla]+67,a->kisi.ehliyet);
		
		struct yabancidil *e=a->kisi.yabanci;
		if(e==NULL) {
			listebirsatiratla++;
		}
		
		while(e!=NULL) {
			
			strcpyintint(listebir[listebirsatiratla++]+87,e->dil);
			
			e=e->sonraki;
			
		}
		
		listebirsatiratla++;
		
		listebirisirala(listebir,a->sol,si);
		listebirisirala(listebir,a->sag,si);
		
	}
}

void listeikiyisirala( int ** listeiki,struct dugum *a, int si) {
	
	if(a==NULL) {
		return;
	}
	
	if(si==1) {
		
		listeikiyisirala(listeiki,a->sol,si);
		if(filtre_varmi==1) {
			
			int uyarmi=1;
			
			if(filtre[0]==1) {
				if(enazlisansmi(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[1]==1) {
				if(ingilizcebiliyormu(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[2]==1) {
				if(birdenfazladilbiliyormu(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[3]==1) {
				if(min_deneyim(a->kisi,deneyimsuresi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[4]==1) {
				if(deneyimsizmi(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[5]==1) {
				if(min_yas(a->kisi,yas)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[6]==1) {
				if(ehliyet_varmi(a->kisi,ehliyettipi)!=1) {
					uyarmi=0;
				}
			}
			if(uyarmi==1) {
				strcpyintint(listeiki[listebirsatiratla]+0,a->kisi.adsoyad);
				int i;
				for(i=0;i<76;i++) {
					listeiki[listebirsatiratla][i+25]='-';
				}
				char duzeyyaz[4]={ };
				
				sprintf(duzeyyaz,"%3d",a->kisi.duzey);
				
				strcpyint(listeiki[listebirsatiratla]+101,duzeyyaz);
				listebirsatiratla+=2;
				
				
				struct egitim *e =a->kisi.okul;
				
				while(e!=NULL) {
					strcpyintint(listeiki[listebirsatiratla]+1,e->adi);
					strcpyintint(listeiki[listebirsatiratla]+42,e->turu);
					strcpyintint(listeiki[listebirsatiratla]+58,e->bolum);
					strcpyint(listeiki[listebirsatiratla]+90,e->baslangic);
					listeiki[listebirsatiratla][94]='-';
					strcpyint(listeiki[listebirsatiratla]+95,e->bitis);
					
					char notyaz[4]={ };
					
					sprintf(notyaz,"%d",e->not);
					
					if(e->not==0) {
						listeiki[listebirsatiratla][101]='E';
					} else {
						strcpyint(listeiki[listebirsatiratla]+101,notyaz);
					}
					
					listebirsatiratla++;
					
					e=e->sonraki;
				}
				listebirsatiratla++;
			}
			
			
		} else {
			strcpyintint(listeiki[listebirsatiratla]+0,a->kisi.adsoyad);
			int i;
			for(i=0;i<76;i++) {
				listeiki[listebirsatiratla][i+25]='-';
			}
			char duzeyyaz[4]={ };
			
			sprintf(duzeyyaz,"%3d",a->kisi.duzey);
			
			strcpyint(listeiki[listebirsatiratla]+101,duzeyyaz);
			listebirsatiratla+=2;
			
			
			struct egitim *e =a->kisi.okul;
			
			while(e!=NULL) {
				strcpyintint(listeiki[listebirsatiratla]+1,e->adi);
				strcpyintint(listeiki[listebirsatiratla]+42,e->turu);
				strcpyintint(listeiki[listebirsatiratla]+58,e->bolum);
				strcpyint(listeiki[listebirsatiratla]+90,e->baslangic);
				listeiki[listebirsatiratla][94]='-';
				strcpyint(listeiki[listebirsatiratla]+95,e->bitis);
				
				char notyaz[4]={ };
				
				sprintf(notyaz,"%d",e->not);
				
				if(e->not==0) {
					listeiki[listebirsatiratla][101]='E';
				} else {
					strcpyint(listeiki[listebirsatiratla]+101,notyaz);
				}
				
				listebirsatiratla++;
				
				e=e->sonraki;
			}
			listebirsatiratla++;
		}
		listeikiyisirala(listeiki,a->sag,si);
		
	} else if(si==2) {
		
		listeikiyisirala(listeiki,a->sol,si);
		listeikiyisirala(listeiki,a->sag,si);
		
		
		strcpyintint(listeiki[listebirsatiratla]+0,a->kisi.adsoyad);
		int i;
		for(i=0;i<76;i++) {
			listeiki[listebirsatiratla][i+25]='-';
		}
		char duzeyyaz[4]={ };
		
		sprintf(duzeyyaz,"%3d",a->kisi.duzey);
		
		strcpyint(listeiki[listebirsatiratla]+101,duzeyyaz);
		listebirsatiratla+=2;
		
		
		struct egitim *e =a->kisi.okul;
		
		while(e!=NULL) {
			strcpyintint(listeiki[listebirsatiratla]+1,e->adi);
			strcpyintint(listeiki[listebirsatiratla]+42,e->turu);
			strcpyintint(listeiki[listebirsatiratla]+58,e->bolum);
			strcpyint(listeiki[listebirsatiratla]+90,e->baslangic);
			listeiki[listebirsatiratla][94]='-';
			strcpyint(listeiki[listebirsatiratla]+95,e->bitis);
			
			char notyaz[4]={ };
			
			sprintf(notyaz,"%d",e->not);
			
			if(e->not==0) {
				listeiki[listebirsatiratla][101]='E';
			} else {
				strcpyint(listeiki[listebirsatiratla]+101,notyaz);
			}
			
			listebirsatiratla++;
			
			e=e->sonraki;
		}
		listebirsatiratla++;
		
		
	} else if(si==3) {
		
		
		strcpyintint(listeiki[listebirsatiratla]+0,a->kisi.adsoyad);
		int i;
		for(i=0;i<76;i++) {
			listeiki[listebirsatiratla][i+25]='-';
		}
		char duzeyyaz[4]={ };
		
		sprintf(duzeyyaz,"%3d",a->kisi.duzey);
		
		strcpyint(listeiki[listebirsatiratla]+101,duzeyyaz);
		listebirsatiratla+=2;
		
		
		struct egitim *e =a->kisi.okul;
		
		while(e!=NULL) {
			strcpyintint(listeiki[listebirsatiratla]+1,e->adi);
			strcpyintint(listeiki[listebirsatiratla]+42,e->turu);
			strcpyintint(listeiki[listebirsatiratla]+58,e->bolum);
			strcpyint(listeiki[listebirsatiratla]+90,e->baslangic);
			listeiki[listebirsatiratla][94]='-';
			strcpyint(listeiki[listebirsatiratla]+95,e->bitis);
			
			char notyaz[4]={ };
			
			sprintf(notyaz,"%d",e->not);
			
			if(e->not==0) {
				listeiki[listebirsatiratla][101]='E';
			} else {
				strcpyint(listeiki[listebirsatiratla]+101,notyaz);
			}
			
			listebirsatiratla++;
			
			e=e->sonraki;
		}
		listebirsatiratla++;
		
		listeikiyisirala(listeiki,a->sol,si);
		listeikiyisirala(listeiki,a->sag,si);
		
	}
	
	
}

void listeucusirala(int ** listeuc,struct dugum *a, int si) {
	
	if(a==NULL) {
		return;
	}
	
	if(si==1) {
		
		listeucusirala(listeuc,a->sol,si);
		if(filtre_varmi==1) {
			
			int uyarmi=1;
			
			if(filtre[0]==1) {
				if(enazlisansmi(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[1]==1) {
				if(ingilizcebiliyormu(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[2]==1) {
				if(birdenfazladilbiliyormu(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[3]==1) {
				if(min_deneyim(a->kisi,deneyimsuresi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[4]==1) {
				if(deneyimsizmi(a->kisi)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[5]==1) {
				if(min_yas(a->kisi,yas)!=1) {
					uyarmi=0;
				}
			}
			if(filtre[6]==1) {
				if(ehliyet_varmi(a->kisi,ehliyettipi)!=1) {
					uyarmi=0;
				}
			}
			if(uyarmi==1) {
				strcpyintint(listeuc[listebirsatiratla]+0,a->kisi.adsoyad);
				int i;
				for(i=0;i<76;i++) {
					listeuc[listebirsatiratla][i+25]='-';
				}
				char duzeyyaz[4]={ };
				
				sprintf(duzeyyaz,"%3d",a->kisi.duzey);
				
				strcpyint(listeuc[listebirsatiratla]+101,duzeyyaz);
				listebirsatiratla+=2;
				
				struct isyeri *e =a->kisi.is;
				
				while(e!=NULL) {
					strcpyintint(listeuc[listebirsatiratla]+1,e->adi);
					strcpyintint(listeuc[listebirsatiratla]+49,e->gorevi);
					
					char sureyaz[7]={ };
					
					sprintf(sureyaz,"%.1f",e->sure);
					strcpyint(listeuc[listebirsatiratla]+90,sureyaz);
					
					struct isyeriadresleri *e2=e->adres;
					while(e2!=NULL) {
						strcpyintint(listeuc[listebirsatiratla]+37,e2->sehir);
						listebirsatiratla++;
						e2=e2->sonraki;
						
					}
					
					e=e->sonraki;
				}
				listebirsatiratla++;
			}
			
		} else {
			strcpyintint(listeuc[listebirsatiratla]+0,a->kisi.adsoyad);
			int i;
			for(i=0;i<76;i++) {
				listeuc[listebirsatiratla][i+25]='-';
			}
			char duzeyyaz[4]={ };
			
			sprintf(duzeyyaz,"%3d",a->kisi.duzey);
			
			strcpyint(listeuc[listebirsatiratla]+101,duzeyyaz);
			listebirsatiratla+=2;
			
			struct isyeri *e =a->kisi.is;
			
			while(e!=NULL) {
				strcpyintint(listeuc[listebirsatiratla]+1,e->adi);
				strcpyintint(listeuc[listebirsatiratla]+49,e->gorevi);
				
				char sureyaz[7]={ };
				
				sprintf(sureyaz,"%.1f",e->sure);
				strcpyint(listeuc[listebirsatiratla]+90,sureyaz);
				
				struct isyeriadresleri *e2=e->adres;
				while(e2!=NULL) {
					strcpyintint(listeuc[listebirsatiratla]+37,e2->sehir);
					listebirsatiratla++;
					e2=e2->sonraki;
					
				}
				
				e=e->sonraki;
			}
			listebirsatiratla++;
		}
		listeucusirala(listeuc,a->sag,si);
		
	} else if(si==2) {
		listeucusirala(listeuc,a->sol,si);
		listeucusirala(listeuc,a->sag,si);
		
		strcpyintint(listeuc[listebirsatiratla]+0,a->kisi.adsoyad);
		int i;
		for(i=0;i<76;i++) {
			listeuc[listebirsatiratla][i+25]='-';
		}
		char duzeyyaz[4]={ };
		
		sprintf(duzeyyaz,"%3d",a->kisi.duzey);
		
		strcpyint(listeuc[listebirsatiratla]+101,duzeyyaz);
		listebirsatiratla+=2;
		
		struct isyeri *e =a->kisi.is;
		
		while(e!=NULL) {
			strcpyintint(listeuc[listebirsatiratla]+1,e->adi);
			strcpyintint(listeuc[listebirsatiratla]+49,e->gorevi);
			
			char sureyaz[7]={ };
			
			sprintf(sureyaz,"%.1f",e->sure);
			strcpyint(listeuc[listebirsatiratla]+90,sureyaz);
			
			struct isyeriadresleri *e2=e->adres;
			while(e2!=NULL) {
				strcpyintint(listeuc[listebirsatiratla]+37,e2->sehir);
				listebirsatiratla++;
				e2=e2->sonraki;
				
			}
			
			e=e->sonraki;
		}
		listebirsatiratla++;
		
	} else if(si==3) {
		strcpyintint(listeuc[listebirsatiratla]+0,a->kisi.adsoyad);
		int i;
		for(i=0;i<76;i++) {
			listeuc[listebirsatiratla][i+25]='-';
		}
		char duzeyyaz[4]={ };
		
		sprintf(duzeyyaz,"%3d",a->kisi.duzey);
		
		strcpyint(listeuc[listebirsatiratla]+101,duzeyyaz);
		listebirsatiratla+=2;
		
		struct isyeri *e =a->kisi.is;
		
		while(e!=NULL) {
			strcpyintint(listeuc[listebirsatiratla]+1,e->adi);
			strcpyintint(listeuc[listebirsatiratla]+49,e->gorevi);
			
			char sureyaz[7]={ };
			
			sprintf(sureyaz,"%.1f",e->sure);
			strcpyint(listeuc[listebirsatiratla]+90,sureyaz);
			
			struct isyeriadresleri *e2=e->adres;
			while(e2!=NULL) {
				strcpyintint(listeuc[listebirsatiratla]+37,e2->sehir);
				listebirsatiratla++;
				e2=e2->sonraki;
				
			}
			
			e=e->sonraki;
		}
		listebirsatiratla++;
		
		listeucusirala(listeuc,a->sol,si);
		listeucusirala(listeuc,a->sag,si);
	}
	
}

void kaydirmacubugu(int max,int l,int kapasite) {
	
	int i;
	
	if(max<=kapasite) {
		
		for(i=0;i<14;i++) {
			ekran[5+i][110]=801;
		}
		
	} else {
		
		int boyut= floor(1.0*kapasite / (max/13.0));
		
		int a=ceil( (  (float)l)  / (max/13.0));
		
		for(i=0;i<14;i++) {
			if(i>=a && i<=a+boyut) {
				ekran[i+5][110]=801;
			}
			
		}
		
		if( l!=max-kapasite && ekran[18][110]==801) {
			
			ekran[18][110]=0;
			ekran[18-boyut-1][110]=801;
			
		}
		
		
	}
	
}



