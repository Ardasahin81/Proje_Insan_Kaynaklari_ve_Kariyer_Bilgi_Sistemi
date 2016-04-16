
int filtre_varmi=0;

int filtre[7]={ };

float deneyimsuresi=0;

int yas=0;

char ehliyettipi[3]={ };

void kaydirmacubugu(int max,int l,int kapasite);

int enazlisansmi(struct kisibilgi a) {
	int i;
	struct egitim *e=a.okul;
	for(i=0;i<a.okulsayisi;i++) {
		
		if(e->turu[3]=='a' || e->turu[0]=='D') {
			return 1;
		} else if(e->turu[0]=='Y' && e->turu[7]=='L') {
			return 1;
		}
		
		e=e->sonraki;
	}
	return 0;
	
}

int ingilizcebiliyormu(struct kisibilgi a) {
	int i;
	struct yabancidil *e=a.yabanci;
	
	int dizi[16]={ };
	
	strcpyint(dizi,"ingilizce");
	
	for(i=0;i<a.yabancidilsayisi;i++) {
		
		if(karsilastirint(dizi,e->dil)==0) {
			return 1;
		}
		
		e=e->sonraki;
	}
	
	return 0;
	
}

int birdenfazladilbiliyormu(struct kisibilgi a) {
	
	if(a.yabancidilsayisi>1) {
		return 1;
	} else {
		return 0;
	}
}

int min_deneyim(struct kisibilgi a, float sure) {
	int i;
	
	struct isyeri * e=a.is;
	
	float toplam=0;
	
	for(i=0;i<a.isyerisayisi;i++) {
		
		toplam+=e->sure;
		
		e=e->sonraki;
	}
	
	if(toplam>=sure) {
		return 1;
	} else {
		return 0;
	}
	
}

int deneyimsizmi(struct kisibilgi a) {
	
	if(a.isyerisayisi==0) {
		return 1;
	} else {
		return 0;
	}
	
}

int min_yas(struct kisibilgi a, int yas) {
	
	int yil=2015;
	
	if( yil - a.dogumt <=yas) {
		return 1;
	} else {
		return 0;
	}
	
}

int ehliyet_varmi(struct kisibilgi a, char *ehliyet) {
	
	int i,j=0;
	
	for(i=0;i<strlen(a.ehliyet);i++) {
		
		if(a.ehliyet[i]==ehliyet[j] && ehliyet[j]!='A') {
			
			return 1;
			
		} else if(a.ehliyet[i]==ehliyet[j]) {
			
			if(a.ehliyet[i+1]==ehliyet[j+1]) {
				
				return 1;
				
			}
			
		}
	}
	
	return 0;
	
}

void filtrelenmisleriyaz(struct dugum *a,char *dosyaadi) {
	
	if(a==NULL) {
		return;
	}
	
	filtrelenmisleriyaz(a->sol,dosyaadi);
	
	
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
		
		int i,j;
		
		struct dugum *e=a;
		
		int ozelliksatir=0;
		
		ozelliksatir+=9;
		
		if(e->kisi.yabancidilsayisi>1) {
			ozelliksatir+=e->kisi.yabancidilsayisi - 1;
		}
		
		ozelliksatir+=3;
		
		if(e->kisi.okulsayisi==0) {
			ozelliksatir+=1;
		} else {
			ozelliksatir+= (e->kisi.okulsayisi) *7;
		}
		
		ozelliksatir+=3;
		
		if(e->kisi.isyerisayisi==0) {
			ozelliksatir+=1;
		} else {
			ozelliksatir+= (e->kisi.isyerisayisi) * 6;
		}
		
		int ** ozellikliste;
		
		ozellikliste=(int **) malloc(sizeof(int*)*ozelliksatir);


		for(i=0;i<ozelliksatir;i++) {
			ozellikliste[i]=(int *)malloc(sizeof(int)*104);
		}
		
		for(i=0;i<ozelliksatir;i++) {
			for(j=0;j<104;j++) {
				ozellikliste[i][j]=0;
			}
		}
		
		int satiratla=0;
		
		strcpyint(ozellikliste[satiratla]+1,"----- ");
		strcpyintint(ozellikliste[satiratla]+7,e->kisi.adsoyad);
		
		satiratla+=2;
		
		strcpyint(ozellikliste[satiratla]+1,"Telefon : ");
		strcpyint(ozellikliste[satiratla]+11,e->kisi.tel);
		
		satiratla++;
		
		strcpyint(ozellikliste[satiratla]+1, "Adres :");
		strcpyintint(ozellikliste[satiratla]+9,e->kisi.adres);
		satiratla++;
		
		strcpyint(ozellikliste[satiratla]+1,"E-Mail :");
		strcpyint(ozellikliste[satiratla]+10,e->kisi.email);
		
		satiratla++;
		
		strcpyint(ozellikliste[satiratla]+1,"Doğum Tarihi :");
		
		char yaz[10]={ };
		
		sprintf(yaz,"%d",e->kisi.dogumt);
		
		strcpyint(ozellikliste[satiratla]+16,yaz);
		
		memset(yaz,0,sizeof(char)*10);
		
		satiratla++;
		
		strcpyint(ozellikliste[satiratla]+1,"Ehliyet : ");
		strcpyint(ozellikliste[satiratla]+11,e->kisi.ehliyet);
		
		satiratla+=2;
		
		strcpyint(ozellikliste[satiratla]+1,"Yabancı Dil : ");
		
		struct yabancidil *a=e->kisi.yabanci;
		
		for(i=0;i<e->kisi.yabancidilsayisi;i++) {
			
			strcpyintint(ozellikliste[satiratla++]+14,a->dil);
			a=a->sonraki;
			
		}
		
		satiratla++;
		
		strcpyint(ozellikliste[satiratla]+1,"<<<<   Okul Bilgileri   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		
		satiratla+=2;
		
		struct egitim *b=e->kisi.okul;
		
		for(i=0;i<e->kisi.okulsayisi;i++) {
			strcpyintint(ozellikliste[satiratla]+1,b->adi);
			strcpyint(ozellikliste[satiratla]+41,"-------------------------------");
			satiratla+=2;
			
			strcpyint(ozellikliste[satiratla]+1,"Tür : ");
			strcpyintint(ozellikliste[satiratla]+7,b->turu);
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"Bölüm :");
			strcpyintint(ozellikliste[satiratla]+9,b->bolum);
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"Tarih :");
			strcpyint(ozellikliste[satiratla]+9,b->baslangic);
			strcpyint(ozellikliste[satiratla]+13,"-");
			strcpyint(ozellikliste[satiratla]+14,b->bitis);
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"Not :");
			
			sprintf(yaz,"%d",b->not);
			strcpyint(ozellikliste[satiratla]+7,yaz);
			
			memset(yaz,0,sizeof(char)*10);
			
			satiratla+=2;
			
			b=b->sonraki;
			
		}
		
		strcpyint(ozellikliste[satiratla]+1,"<<<<<  İş Yeri Bilgileri >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		satiratla+=2;
		
		struct isyeri * c=e->kisi.is;
		
		for(i=0;i<e->kisi.isyerisayisi;i++) {
			
			strcpyintint(ozellikliste[satiratla]+1,c->adi);
			strcpyint(ozellikliste[satiratla]+36,"------------------------------------");
			satiratla+=2;
			
			int sutunatla=0;
			
			struct isyeriadresleri *d=c->adres;
			
			strcpyint(ozellikliste[satiratla]+1,"Adres :");
			
			for(j=0;j<c->adressayisi;j++) {
				
				strcpyintint(ozellikliste[satiratla]+9+sutunatla,d->sehir);
				
				sutunatla+=karaktersayisi(d->sehir);
				
				strcpyint(ozellikliste[satiratla]+9+sutunatla,",");
				
				sutunatla+=2;
				
				d=d->sonraki;
			}
			
			strcpyint(ozellikliste[satiratla]+9+sutunatla-2," ");
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"Çalıştığı Görev :");
			
			strcpyintint(ozellikliste[satiratla]+19,c->gorevi);
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"Süre (Yıl) : ");
			
			sprintf(yaz,"%.1f",c->sure);
			
			strcpyint(ozellikliste[satiratla]+14,yaz);
			
			memset(yaz,0,sizeof(char)*10);
			
			satiratla+=2;
			
			c=c->sonraki;
			
		}
		
		strcpyint(ozellikliste[satiratla]+1,">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		
		FILE *dosya=fopen(dosyaadi,"a+");
		
		
		if(dosya==NULL) {
			dosyahata();
		}
		
		dosyayayazdir(ozellikliste,ozelliksatir,73,dosya);
		
	
		fclose(dosya);
		
		for(i=0;i<ozelliksatir;i++) {
			free(ozellikliste[i]);
		}
		
		free(ozellikliste);
		
		
	}
	
	filtrelenmisleriyaz(a->sag,dosyaadi);
	
}

void aramayap() {
	
	int yedek[10][50]={ };
	
	int i,j;
	
	for(i=0;i<10;i++) {
		for(j=0;j<50;j++) {
			yedek[i][j]=ekran[i+8][j+29];
			ekran[i+8][j+29]=0;
		}
	}
	
	
	
	dikdortgenciz(8,29,17,78);
	
	ekran[13][76]='<';
	ekran[13][77]='-';
	
	syaz("Aramak istediğiniz kişinin adını-soyadını",9,33);
	syaz("yazınız.",10,32);
	
	dikdortgenkutucukciz(12,32,42);
	
	syaz("ESC : Vazgeç                 ENTER : Ara",16,34);
	
	int isim[26]={ };
	
	while(1) {
		syaz("                                          ",13,33);
		
		yazdirint(isim,13,34);
		
		
		
		yazdir();
		
		tus=tusal();
		
		if(tus==770) {
			
			for(i=0;i<10;i++) {
				for(j=0;j<50;j++) {
					ekran[i+8][j+29]=yedek[i][j];
				}
			}
			return;
		} else if(tus==778) {
			
			struct dugum *e=adindankisiara(isim);
			
			if(e==NULL) {
				
				syaz("                                            ",9,32);
				syaz("                                            ",10,32);
				syaz("Kayıt bulunamadı!",10,33);
				
				yazdir();
				
				if(tusal()==778) {
					
					memset(isim,0,sizeof(int)*25);
					
					continue;
					
				} else {
					return;
				}
			}
			
			ekranitemizle();
			cerceveciz();
			
			dikdortgenciz(4,2,19,108);
			
			syaz("ESC : Çık                                                                        'Y' : Yazdır",20,6);
			
			syaz("Yukarı/Aşağı ok tuşlarıyla kaydır.",22,37);
			
			
			int ozelliksatir=0;
			
			ozelliksatir+=9;
			
			if(e->kisi.yabancidilsayisi>1) {
				ozelliksatir+=e->kisi.yabancidilsayisi - 1;
			}
			
			ozelliksatir+=3;
			
			if(e->kisi.okulsayisi==0) {
				ozelliksatir+=1;
			} else {
				ozelliksatir+= (e->kisi.okulsayisi) *7;
			}
			
			ozelliksatir+=3;
			
			if(e->kisi.isyerisayisi==0) {
				ozelliksatir+=1;
			} else {
				ozelliksatir+= (e->kisi.isyerisayisi) * 6;
			}
			
			int ** ozellikliste;
			
			ozellikliste=(int **) malloc(sizeof(int*)*ozelliksatir);


			for(i=0;i<ozelliksatir;i++) {
				ozellikliste[i]=(int *)malloc(sizeof(int)*104);
			}
			
			for(i=0;i<ozelliksatir;i++) {
				for(j=0;j<104;j++) {
					ozellikliste[i][j]=0;
				}
			}
			
			int satiratla=0;
			
			strcpyint(ozellikliste[satiratla]+1,"----- ");
			strcpyintint(ozellikliste[satiratla]+7,e->kisi.adsoyad);
			
			satiratla+=2;
			
			strcpyint(ozellikliste[satiratla]+1,"Telefon : ");
			strcpyint(ozellikliste[satiratla]+11,e->kisi.tel);
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1, "Adres :");
			strcpyintint(ozellikliste[satiratla]+9,e->kisi.adres);
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"E-Mail :");
			strcpyint(ozellikliste[satiratla]+10,e->kisi.email);
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"Doğum Tarihi :");
			
			char yaz[10]={ };
			
			sprintf(yaz,"%d",e->kisi.dogumt);
			
			strcpyint(ozellikliste[satiratla]+16,yaz);
			
			memset(yaz,0,sizeof(char)*10);
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"Ehliyet : ");
			strcpyint(ozellikliste[satiratla]+11,e->kisi.ehliyet);
			
			satiratla+=2;
			
			strcpyint(ozellikliste[satiratla]+1,"Yabancı Dil : ");
			
			struct yabancidil *a=e->kisi.yabanci;
			
			for(i=0;i<e->kisi.yabancidilsayisi;i++) {
				
				strcpyintint(ozellikliste[satiratla++]+14,a->dil);
				a=a->sonraki;
				
			}
			
			satiratla++;
			
			strcpyint(ozellikliste[satiratla]+1,"<<<<   Okul Bilgileri   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
			
			satiratla+=2;
			
			struct egitim *b=e->kisi.okul;
			
			for(i=0;i<e->kisi.okulsayisi;i++) {
				strcpyintint(ozellikliste[satiratla]+1,b->adi);
				strcpyint(ozellikliste[satiratla]+41,"-------------------------------");
				satiratla+=2;
				
				strcpyint(ozellikliste[satiratla]+1,"Tür : ");
				strcpyintint(ozellikliste[satiratla]+7,b->turu);
				
				satiratla++;
				
				strcpyint(ozellikliste[satiratla]+1,"Bölüm :");
				strcpyintint(ozellikliste[satiratla]+9,b->bolum);
				
				satiratla++;
				
				strcpyint(ozellikliste[satiratla]+1,"Tarih :");
				strcpyint(ozellikliste[satiratla]+9,b->baslangic);
				strcpyint(ozellikliste[satiratla]+13,"-");
				strcpyint(ozellikliste[satiratla]+14,b->bitis);
				
				satiratla++;
				
				strcpyint(ozellikliste[satiratla]+1,"Not :");
				
				sprintf(yaz,"%d",b->not);
				strcpyint(ozellikliste[satiratla]+7,yaz);
				
				memset(yaz,0,sizeof(char)*10);
				
				satiratla+=2;
				
				b=b->sonraki;
				
			}
			
			strcpyint(ozellikliste[satiratla]+1,"<<<<<  İş Yeri Bilgileri >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
			satiratla+=2;
			
			struct isyeri * c=e->kisi.is;
			
			for(i=0;i<e->kisi.isyerisayisi;i++) {
				
				strcpyintint(ozellikliste[satiratla]+1,c->adi);
				strcpyint(ozellikliste[satiratla]+36,"------------------------------------");
				satiratla+=2;
				
				int sutunatla=0;
				
				struct isyeriadresleri *d=c->adres;
				
				strcpyint(ozellikliste[satiratla]+1,"Adres :");
				
				for(j=0;j<c->adressayisi;j++) {
					
					strcpyintint(ozellikliste[satiratla]+9+sutunatla,d->sehir);
					
					sutunatla+=karaktersayisi(d->sehir);
					
					strcpyint(ozellikliste[satiratla]+9+sutunatla,",");
					
					sutunatla+=2;
					
					d=d->sonraki;
				}
				
				strcpyint(ozellikliste[satiratla]+9+sutunatla-2," ");
				
				satiratla++;
				
				strcpyint(ozellikliste[satiratla]+1,"Çalıştığı Görev :");
				
				strcpyintint(ozellikliste[satiratla]+19,c->gorevi);
				
				satiratla++;
				
				strcpyint(ozellikliste[satiratla]+1,"Süre (Yıl) : ");
				
				sprintf(yaz,"%.1f",c->sure);
				
				strcpyint(ozellikliste[satiratla]+14,yaz);
				
				memset(yaz,0,sizeof(char)*10);
				
				satiratla+=2;
				
				c=c->sonraki;
				
			}
			int l=0;
			while(1) {
				
				satiratla=0;
				
				for(i=l;i<ozelliksatir && i < l+14;i++) {
					
					yazdirintboyut(ozellikliste[i],satiratla+5,3,104);
					satiratla++;
				}
				
				for(i=0;i<14;i++) {
					ekran[5+i][110]=0;
				}
				
				
				kaydirmacubugu(ozelliksatir,l,14);
				
				yazdir();
				
				tus=tusal();
				
				if(tus==741 && l>0) {
					l--;
				} else if(tus==742 && l<ozelliksatir-14) {
					l++;
				} else if(tus==770) {
					
					for(i=0;i<ozelliksatir;i++) {
						free(ozellikliste[i]);
					}
					
					free(ozellikliste);
					
					return;
					
				} else if(tus=='y' || tus=='Y') {
					
					
					for(i=0;i<10;i++) {
						for(j=0;j<50;j++) {
							ekran[i+8][j+29]=0;
						}
					}
					
					dikdortgenciz(8,29,17,78);
					
					ekran[13][76]='<';
					ekran[13][77]='-';
					
					syaz("Oluşturmak istediğiniz dosyanın adını",9,33);
					syaz("yazınız.( *.txt otomatik eklenir.)",10,32);
					
					dikdortgenkutucukciz(12,32,42);
					
					syaz("ESC : Vazgeç                 ENTER : Yaz",16,34);
					
					
					char dosyaadi[46]={ };
					
					while(1) {
						syaz("                                          ",13,33);
						
						syaz(dosyaadi,13,34);
						
						yazdir();
						
						tus=tusal();
						
						if(tus==770) {
							
							for(i=0;i<10;i++) {
								for(j=0;j<50;j++) {
									ekran[i+8][j+29]=yedek[i][j];
								}
							}
							break;
						} else if(tus==778) {
							
							int ks=strlen(dosyaadi);
							
							dosyaadi[ks++]='.';
							dosyaadi[ks++]='t';
							dosyaadi[ks++]='x';
							dosyaadi[ks++]='t';
							
							
							FILE * dosya=fopen(dosyaadi,"r");
							
							if(dosya==NULL) {
								
								dosya=fopen(dosyaadi,"w");
								
								
								dosyayayazdir(ozellikliste,ozelliksatir,73,dosya);
								
								fclose(dosya);
								
								for(i=0;i<10;i++) {
									for(j=0;j<50;j++) {
										ekran[i+8][j+29]=0;
									}
								}
								
								dikdortgenciz(8,29,17,78);
								
								syaz("Dosyaya Yazdırma Başarılı",12,35);
								
								yazdir();
								
								tusal();
								
								break;
							} else {
								fclose(dosya);
								
								syaz("HATA! Bu dosya adı kullanılıyor",15,38);
								
								memset(dosyaadi,0,sizeof(char)*41);
								
								yazdir();
								tusal();
								
							}
						} else {
							
							int ks=strlen(dosyaadi);
							
							if( ( isalpha(tus) || tus==' ' || tus=='.' || isdigit(tus)) && ks<41) {
								dosyaadi[ks]=tus;
							} else if(tus==773) {
								dosyaadi[--ks]=0;
							}
							
						}
						
						
						
					}
					
					
				}
				
				
			}
			
		} else {
			
			int ks=karaktersayisi(isim);
			
			if( (harfmi() || tus==' ' ) && ks<25) {
				
				isim[ks]=tus;
				
			} else if(tus==773) {
				isim[--ks]=0;
			}
			
		}
		
		
		
	}
	
	
}


