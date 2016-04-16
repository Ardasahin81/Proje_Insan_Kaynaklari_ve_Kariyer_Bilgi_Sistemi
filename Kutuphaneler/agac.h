
void agacioku() {
	
	FILE *dosya=fopen(agacdosya,"rb");
	if(dosya==NULL) {
		dosyahata();
	}
	struct kisibilgi *oku=(struct kisibilgi *) malloc(sizeof(struct kisibilgi));
	while(1) {
		
		
		size_t durum=fread(oku,sizeof(struct kisibilgi),1,dosya);
		
		if(durum<1) {
			break;
		} else {
			
			//~ printf("%s emailli olan okunuyor\n",oku->email);
			//~ if(oku->email[0]==0) {
				//~ break;
			//~ }
			struct dugum *dugumekle=(struct dugum *) malloc(sizeof(struct dugum));
			
			dugumekle->sol=NULL;
			dugumekle->sag=NULL;
			
			oku->okul=NULL;
			oku->is=NULL;
			oku->yabanci=NULL;
			
			int i,j;
			
			for(i=0;i<oku->okulsayisi;i++) {
				//~ printf("%d OKUL OKUNACAK\n",oku->okulsayisi);
				struct egitim *ekle=(struct egitim *)malloc(sizeof(struct egitim));
				
				fread(ekle,sizeof(struct egitim),1,dosya);
				ekle->sonraki=NULL;
				
				
				
				if(oku->okul==NULL) {
					oku->okul=ekle;
					
				} else {
					struct egitim *e=oku->okul;
					
					while(e->sonraki!=NULL) {
						e=e->sonraki;
					}
					e->sonraki=ekle;
				}
				
			}
			
			for(i=0;i<oku->isyerisayisi;i++) {
				//~ printf("%d ISYERI OKUNACAK\n",oku->isyerisayisi);
				struct isyeri *ekle=(struct isyeri *)malloc(sizeof(struct isyeri));
				
				fread(ekle,sizeof(struct isyeri),1,dosya);
				ekle->sonraki=NULL;
				ekle->adres=NULL;
				
				for(j=0;j<ekle->adressayisi;j++) {
					struct isyeriadresleri *eklea=(struct isyeriadresleri *)malloc(sizeof(struct isyeriadresleri));
					
					fread(eklea,sizeof(struct isyeriadresleri),1,dosya);
					eklea->sonraki=NULL;
					
					if(ekle->adres==NULL) {
						ekle->adres=eklea;
					} else {
						struct isyeriadresleri *e=ekle->adres;
						
						while(e->sonraki!=NULL) {
							e=e->sonraki;
						}
						e->sonraki=eklea;
					}
					
				}
				
				if(oku->is==NULL) {
					oku->is=ekle;
				} else {
					struct isyeri *e=oku->is;
					
					while(e->sonraki!=NULL) {
						e=e->sonraki;
					}
					e->sonraki=ekle;
				}
				
				
			}
			
			for(i=0;i<oku->yabancidilsayisi;i++) {
				//~ printf("%d DIL OKUNACAK\n",oku->yabancidilsayisi);
				struct yabancidil *ekle=(struct yabancidil *)malloc(sizeof(struct yabancidil));
				
				fread(ekle,sizeof(struct yabancidil),1,dosya);
				ekle->sonraki=NULL;
				
				if(oku->yabanci==NULL) {
					oku->yabanci=ekle;
					
				} else {
					struct yabancidil *e=oku->yabanci;
					
					while(e->sonraki!=NULL) {
						e=e->sonraki;
					}
					e->sonraki=ekle;
				}
				
			}
			dugumekle->kisi=*oku;
			
			if(root==NULL) {
				
				root=dugumekle;
				//~ printf("ROOTa Eklendi\n");
			} else {
				
				struct dugum *e=root;
				while(1) {
					if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)>=0 && e->sol==NULL) {
						e->sol=dugumekle;
						break;
					} else if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)>=0 && e->sol!=NULL) {
						e=e->sol;
					} else if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)<0 && e->sag==NULL) {
						e->sag=dugumekle;
						break;
					} else if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)<0 && e->sag!=NULL) {
						e=e->sag;
					}
				
				}
				//~ printf("Baska Yere Eklendi\n");
			}
			//~ getch();
		} 
	}
	free(oku);
	fclose(dosya);
	
}

void dugumyaz(struct dugum *a) {
	
	if(a==NULL) {
		return;
	}
	
	FILE *dosya=fopen(agacdosya,"ab");
	
	if(dosya==NULL) {
		dosyahata();
	}
	
	
	fwrite(&(a->kisi),sizeof(struct kisibilgi),1,dosya);
	
	struct egitim *o=a->kisi.okul;
	
	int i,j;
	
	for(i=0;i< a->kisi.okulsayisi;i++) {
		
		fwrite(o,sizeof(struct egitim),1,dosya);
		
		o=o->sonraki;
		
	}
	
	struct isyeri *is=a->kisi.is;
	
	for(i=0;i< a->kisi.isyerisayisi;i++) {
		
		fwrite(is,sizeof(struct isyeri),1,dosya);
		
		struct isyeriadresleri *a=is->adres;
		
		for(j=0;j< is->adressayisi;j++) {
			
			fwrite(a,sizeof(struct isyeriadresleri),1,dosya);
			
			a=a->sonraki;
			
		}
		
		is=is->sonraki;
	}
	
	struct yabancidil * y=a->kisi.yabanci;
	
	for(i=0;i< a->kisi.yabancidilsayisi;i++) {
		
		fwrite(y,sizeof(struct yabancidil),1,dosya);
		
		y=y->sonraki;
		
	}
	
	fclose(dosya);
	
	
	
	
	dugumyaz(a->sol);
	
	dugumyaz(a->sag);
}

void agaciyaz() {
	
	FILE * dosya=fopen(agacdosya,"wb");
	if(dosya==NULL) {
		dosyahata();
	}
	fseek(dosya,0,SEEK_SET);
	fclose(dosya);
	dugumyaz(root);
	//~ printf("agaciyaz 2\n");
	//fclose(dosya);
	
}

void dugumekle(struct kisibilgi *a) {
	
	struct dugum * dugumekle;
	
	dugumekle=(struct dugum *) malloc(sizeof(struct dugum));
	
	dugumekle->sol=NULL;
	dugumekle->sag=NULL;
	dugumekle->kisi=*a;
	
	if(root==NULL) {
		
		root=dugumekle;
		
	} else {
		
		struct dugum *e=root;
		while(1) {
			if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)>=0 && e->sol==NULL) {
				e->sol=dugumekle;
				break;
			} else if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)>=0 && e->sol!=NULL) {
				e=e->sol;
			} else if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)<0 && e->sag==NULL) {
				e->sag=dugumekle;
				break;
			} else if(karsilastirint(dugumekle->kisi.adsoyad,e->kisi.adsoyad)<0 && e->sag!=NULL) {
				e=e->sag;
			}
		
		}

	}
	
}

void dugumtemizle(struct dugum *a) {
	if(a==NULL) {
		return;
	}
	
	if(a->kisi.okul!=NULL) {
		okultemizle(a->kisi.okul);
	}
	if(a->kisi.is!=NULL) {
		isyeritemizle(a->kisi.is);
	}
	if(a->kisi.yabanci!=NULL) {
		yabancidiltemizle(a->kisi.yabanci);
	}
	free(a);
}

int dugumsil(int *isim, char *tel,int ozel) {
	
	struct dugum *e=root;
	
	
	if(karsilastirint(root->kisi.adsoyad,isim)==0 && strcmp(root->kisi.tel,tel)==0) {
		
		
		if(root->sol==NULL && root->sag==NULL) {
			
			dugumtemizle(root);
			root=NULL;
			return 1;
		} else if(root->sol!=NULL && root->sag!=NULL) {
			
			struct dugum *suc=root->sag;
			
			while(suc->sol!=NULL) {
				suc=suc->sol;
			}
			
			struct kisibilgi yedek=suc->kisi;
			
			
			dugumsil(suc->kisi.adsoyad,suc->kisi.tel,2);
			
			
			root->kisi=yedek;
			return 2;
		} else {
			
			if(root->sol!=NULL) {
				struct dugum *sil=root;
				
				root=root->sol;
				
				dugumtemizle(sil);
				
			} else {
				
				struct dugum *sil=root;
				
				root=root->sag;
				
				dugumtemizle(sil);
				
			}
			return 3;
		}
		
	}
	
	while(1) {
		
		if(karsilastirint(isim,e->kisi.adsoyad)>0 && e->sol==NULL) {
			
			return -1;
			
		} else if(karsilastirint(isim,e->kisi.adsoyad)<0 && e->sag==NULL) {
			
			return -1;
			
		} else if(karsilastirint(isim,e->kisi.adsoyad)>0 && e->sol!=NULL) {
			
			e=e->sol;
			
		} else if(karsilastirint(isim,e->kisi.adsoyad)<0 && e->sag!=NULL) {
			
			e=e->sag;
			
		} else if(karsilastirint(e->kisi.adsoyad,isim)==0 && strcmp(e->kisi.tel,tel)==0) {
			
			struct dugum *eonceki=root;
			
			
			while(1) {
				if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)>0) {
					if(karsilastirint(e->kisi.adsoyad,eonceki->sol->kisi.adsoyad)==0 && strcmp(e->kisi.tel,eonceki->sol->kisi.tel)==0) {
						
						break;
						
					} else {
						eonceki=eonceki->sol;
					}
					
					
				} else if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)<0) {
					if(karsilastirint(e->kisi.adsoyad,eonceki->sag->kisi.adsoyad)==0 && strcmp(e->kisi.tel,eonceki->sag->kisi.tel)==0) {
						
						break;
						
					} else {
						eonceki=eonceki->sag;
					}
					
				}
				
			}
			
			if(e->sol==NULL && e->sag==NULL) {
				if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)>0) {
					
					eonceki->sol=NULL;
				} else if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)<0) {
					
					eonceki->sag=NULL;
				}
				if(ozel!=2) {
					dugumtemizle(e);
				} else {
					free(e);
				}
				return 4;
			} else if( e->sol!=NULL && e->sag!=NULL) {
				
				struct dugum *suc=e->sag;
				
				while(suc->sol!=NULL) {
					suc=suc->sol;
				}
				
				struct kisibilgi yedek=suc->kisi;
				
				dugumsil(suc->kisi.adsoyad,suc->kisi.tel,2);
				
				e->kisi=yedek;
				return 5;
			} else {
				
				if(e->sol!=NULL) {
					if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)>0) {
						eonceki->sol=e->sol;
					} else if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)<0) {
						eonceki->sag=e->sol;
					}
				} else {
					if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)>0) {
						eonceki->sol=e->sag;
					} else if(karsilastirint(e->kisi.adsoyad,eonceki->kisi.adsoyad)<0) {
						eonceki->sag=e->sag;
					}
					
				}
				return 6;
				
			}
		} else {
			return -1;
		}
		
		
	}
	
	return 0;
}

void agacitemizle(struct dugum *a) {
	
	if(a==NULL) {
		return;
	}
	
	agacitemizle(a->sol);
	agacitemizle(a->sag);
	dugumtemizle(a);
	a=NULL;
}

struct dugum * kisiara(int *isim, char *tel) {
	
	struct dugum *e=root;
	while(e!=NULL) {
		if(karsilastirint(e->kisi.adsoyad,isim)==0 && strcmp(e->kisi.tel,tel)==0) {
			
			return e;
			
		} else if(karsilastirint(isim,e->kisi.adsoyad)>=0) {
			e=e->sol;
		} else if(karsilastirint(isim,e->kisi.adsoyad)<0) {
			e=e->sag;
		} 
		
	}
	return NULL;
}

struct dugum * adindankisiara(int *isim) {
	
	struct dugum *e=root;
	while(e!=NULL) {
		if(karsilastirint(e->kisi.adsoyad,isim)==0) {
			
			return e;
			
		} else if(karsilastirint(isim,e->kisi.adsoyad)>0) {
			e=e->sol;
		} else {
			e=e->sag;
		}
		
	}
	return NULL;
	
}
