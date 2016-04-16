
void isaretcikoy(int asama,int secili) {
	
	if(asama==1) {
		
		switch(secili) {
			case 1:
				ekran[6][53]='<';
				ekran[6][54]='-';
				break;
			case 2:
				ekran[9][53]='<';
				ekran[9][54]='-';
				break;
			case 3:
				ekran[12][53]='<';
				ekran[12][54]='-';
				break;
			case 4:
				ekran[15][53]='<';
				ekran[15][54]='-';
				break;
			case 5:
				ekran[18][53]='<';
				ekran[18][54]='-';
				break;
			case 6:
				ekran[6][58]='-';
				ekran[6][59]='>';
				break;
			case 7:
				ekran[22][84]='-';
				ekran[22][85]='>';
				break;
			default:
				break;
		}
		
	} else if(asama==2) {
		if(secili==1) {
			ekran[8][49]='<';
			ekran[8][50]='-';
		} else if(secili==2) {
			ekran[12][49]='<';
			ekran[12][50]='-';
		} else if(secili==3) {
			ekran[22][84]='-';
			ekran[22][85]='>';
		} else if(secili==4) {
			ekran[22][28]='<';
			ekran[22][29]='-';
		}
	} else if(asama==31) {
		if(secili==1) {
			ekran[19][66]='<';
			ekran[19][67]='-';
		} else if(secili==2) {
			ekran[22][66]='<';
			ekran[22][67]='-';
		} else if(secili==3) {
			ekran[22][84]='-';
			ekran[22][85]='>';
		} else if(secili==4) {
			ekran[22][28]='<';
			ekran[22][29]='-';
		}
	} else if(asama==32) {
		if(secili==1) {
			ekran[6][70]='<';
			ekran[6][71]='-';
		} else {
			ekran[(secili-1)*3+6][69]='<';
			ekran[(secili-1)*3+6][70]='-';
		}
	} else if(asama==41) {
		if(secili==1) {
			ekran[19][66]='<';
			ekran[19][67]='-';
		} else if(secili==2) {
			ekran[22][66]='<';
			ekran[22][67]='-';
		} else if(secili==3) {
			ekran[22][84]='-';
			ekran[22][85]='>';
		} else if(secili==4) {
			ekran[22][28]='<';
			ekran[22][29]='-';
		}
	} else if(asama==42) {
		if(secili==5) {
			ekran[19][75]='<';
			ekran[19][76]='-';
		} else {
			ekran[(secili-1)*3+6][75]='<';
			ekran[(secili-1)*3+6][76]='-';
		}
	}
	
	
}

void bilgileridoldur(struct kisibilgi *a, int asama,int sayfa) {
	
	if(asama==1) {
		
		yazdirint(a->adsoyad,6,23);
		yazdirint(a->adres,9,23);
		syaz(a->tel,12,23);
		
		syaz(a->ehliyet,6,71);
		
		if(strlen(a->email)<27) {
			syaz(a->email,15,23);
		} else {
			char gorunen[28]={ };
			sprintf(gorunen,a->email+strlen(a->email)-27);
			syaz(gorunen,15,22);
			
		}
		char dtyaz[5]= { };
		sprintf(dtyaz,"%d",a->dogumt);
		if(a->dogumt!=0)
			syaz(dtyaz,18,23);
	} else if(asama==2) {
		int satiratla=0;
		int sayac=0;
		struct yabancidil *e=a->yabanci;
		while(e!=NULL) {
			if(sayac>=((sayfa-1)*9) && sayac<((sayfa-1)*9)+9) {
				syaz("-",9+satiratla,68);
				yazdirint(e->dil,9+satiratla,70);
				satiratla++;
			}
			sayac++;
			e=e->sonraki;
		}
	} else if(asama==31) {
		
		int satiratla=0;
		int sayac=0;
		struct egitim *e=a->okul;
		while(e!=NULL) {
			if(sayac>=((sayfa-1)*10) && sayac<((sayfa-1)*10)+10) {
				syaz("-",7+satiratla,3);
				yazdirint(e->adi,7+satiratla,5);
				yazdirint(e->turu,7+satiratla,47);
				yazdirint(e->bolum,7+satiratla,62);
				syaz(e->baslangic,7+satiratla,94);
				syaz("-",7+satiratla,98);
				syaz(e->bitis,7+satiratla,99);
				char notyaz[4]= { };
				sprintf(notyaz,"%d",e->not);
				syaz(notyaz,7+satiratla,105);
				satiratla++;
			}
			sayac++;
			e=e->sonraki;
		}
		
	} else if(asama==41) {
		
		int satiratla=0;
		int sayac=0;
		struct isyeri *e=a->is;
		int kacsatir=0;
		while(e!=NULL) {
			
			struct isyeriadresleri *e2=e->adres;
			
			while(e2!=NULL) {
				kacsatir++;
				e2=e2->sonraki;
			}
			
			e=e->sonraki;
		}
		
		int ** isyerimat;
		
		isyerimat=(int **) malloc(sizeof(int*)*kacsatir);
		
		int i,j;
		
		for(i=0;i<kacsatir;i++) {
			isyerimat[i]=(int *)malloc(sizeof(int)*109);
		}
		
		for(i=0;i<kacsatir;i++) {
			for(j=0;j<109;j++) {
				isyerimat[i][j]=0;
			}
		}
		e=a->is;
		for(i=0;i<kacsatir && e!=NULL;) {
			
			isyerimat[i][1]='-';
			
			strcpyintint(isyerimat[i]+3,e->adi);
			strcpyintint(isyerimat[i]+53,e->gorevi);
			char sureyiyaz[6]={ };
			sprintf(sureyiyaz,"%.1f",e->sure);
			strcpyint(isyerimat[i]+95,sureyiyaz);
			
			struct isyeriadresleri *e2=e->adres;
			
			while(e2!=NULL) {
				
				strcpyintint(isyerimat[i]+40,e2->sehir);
				i++;
				
				e2=e2->sonraki;
			}
			e=e->sonraki;
		}
		satiratla=0;
		i=0;
		sayac=0;
		while(i<kacsatir) {
			
			if(sayac>=((sayfa-1)*10) && sayac<((sayfa-1)*10)+10) {
				yazdirintboyut(isyerimat[i],7+satiratla,2,109);
				satiratla++;
			}
			sayac++;
			i++;
		}
		
		for(i=0;i<kacsatir;i++) {
			free(isyerimat[i]);
		}
		free(isyerimat);
		
	}
	
}

int basvuruform(struct kisibilgi * a,int secenek) {
	
	int secili=1;
	int asama=1;
	
	int etkin[9]={ };//Etkin ehliyet
	
	int buf[16]={ };//Yabancı dil alim
	
	int buf1[41]={ }; // okul adi
	int buf2[14]={ }; // okul turu
	int buf3[31]={ }; // bolumu
	char buf4[10]={ }; // baslangic t bitis t
	int buf5=0; // okul notu;
	
	int buf6[36]={ }; // is yeri adi
	int buf7[41]={ }; // is gorev
	char buf8[5]={ }; // calisma suresi
	int buf9=0; // adres sayisi
	struct isyeriadresleri *buf10=NULL;
	int buf11[12]={ }; //adres
	
	int sayfa=1;
	while(1) {
		
		if(asama==1) {
			
			basvuru1ciz();
			isaretcikoy(asama,secili);
			
			bilgileridoldur(a,asama,0);
			
			yazdir();
			
			tus=tusal();
			
			if(tus==741 && secili>1) {
				secili--;
			} else if( (tus==742 || tus==771) && secili<7) {
				secili++;
			} else if(tus==778 && secili==7) {
				
				if(a->adsoyad[0]==0 || a->adres[0]==0 || a->tel[0]==0 || a->email[0]==0 || a->dogumt==0) {
					
					syaz("^ Devam etmek için lütfen eksik yerleri doldurunuz.",19,58);
					yazdir();
					tus=tusal();
					if(tus==770) {
						return -1;
					}
					
				} else {
					secili=1;
					asama=2;
				}
			} else if(tus==770) {
				return -1;
			} else {
				
				if(secili==1) {
					adsoyadal(a);
				} else if(secili==2) {
					adresal(a);
				} else if(secili==3) {
					telefonal(a);
				} else if(secili==4) {
					emailal(a);
				} else if(secili==5) {
					dogumtarihial(a);
				} else if(secili==6) {
					char karsilik[7]={'B','C','D','E','F','G','H'};
					int i;
					int ks;
					int seciliehliyet=1;
					while(1) {
						syaz("                    ",6,71);
						for(i=6;i<16;i++) {
							ekran[i][101]=0;
						}
						
						for(i=0;i<9;i++) {
							if(etkin[i]==1) {
								ekran[i+6][99]='x';
							} else {
								ekran[i+6][99]=0;
							}
						}
						
						ekran[(seciliehliyet-1)+6][101]='<';
						ks=0;
						sprintf(a->ehliyet,"               ");
						if(etkin[0]==1) {
							sprintf(a->ehliyet+ks,"A1,");
							ks+=3;
						}
						
						if(etkin[1]==1) {
							sprintf(a->ehliyet+ks,"A2,");
							ks+=3;
						}
						
						for(i=0;i<7;i++) {
							if(etkin[i+2]==1) {
								sprintf(a->ehliyet+ks,"%c,",karsilik[i]);
								ks+=2;
							}
						}
						if(ks!=0)
							a->ehliyet[ks-1]=0;
						
						syaz(a->ehliyet,6,71);
						
						yazdir();
						tus=tusal();
						
						if(tus==741 && seciliehliyet>1) {
							seciliehliyet--;
						} else if(tus==742 && seciliehliyet<10) {
							seciliehliyet++;
						} else if(tus==778 && seciliehliyet!=10) {
							etkin[seciliehliyet-1]=(etkin[seciliehliyet-1]+1)%2;
						} else if(tus==778 && seciliehliyet==10) {
							break;
						} else if(tus==770) {
							break;
						}
						
						
					}
				}
				
			}
		} else if(asama==2) {
			
			basvuru2ciz();
			isaretcikoy(asama,secili);
			bilgileridoldur(a,asama,sayfa);
			char sayfagosterge[10]= { };
			sprintf(sayfagosterge,"<%2d /%2d >",sayfa,(a->yabancidilsayisi/9)+1);
			syaz(sayfagosterge,19,90);
			
			yazdirint(buf,8,24);
			
			yazdir();
			
			tus=tusal();
			
			if(tus==741 && secili>1) {
				secili--;
			} else if( (tus==742 || tus==771) && secili<4) {
				secili++;
			} else if(tus==744 && sayfa>1) {
				sayfa--;
			} else if(tus==743 && sayfa<(a->yabancidilsayisi/9)+1) {
				sayfa++;
			} else if(tus==770) {
				return -1;
			} else if(tus==778) {
				if(secili==3) {
					secili=1;
					asama=31;
					sayfa=1;
				} else if(secili==4) {
					secili=7;
					asama=1;
				} else if(secili==1) {
					
					if(buf[0]!=0) {
						yabancidilekle(a,buf);
						int i;
						for(i=0;i<15;i++) {
							buf[i]=0;
						}
					}
					
				} else if(secili==2 && a->yabancidilsayisi>0) {
					
					syaz("Yukarı/Aşağı yön tuşlarını kullanarak silmek",15,11);
					syaz("istediğiniz dili seçiniz ve ENTER'a basınız.",16,10);
					
					int silsira=1;
					
					while(1) {
						
						syaz("                      ",12,24);
						
						struct yabancidil *sil=a->yabanci;
						int i;
						for(i=1;i<silsira;i++) {
							sil=sil->sonraki;
							
						}
						
						yazdirint(sil->dil,12,24);
						
						yazdir();
						
						tus=tusal();
						
						if(tus==770) {
							break;
						} else if(tus==741 && silsira>1) {
							silsira--;
						} else if(tus==742 && silsira<a->yabancidilsayisi) {
							silsira++;
						} else if(tus==778) {
							
							yabancidilsil(a,sil->dil);
							break;
						}
						
						
					}
					
					
					
				}
			} else {
				
				if(secili==1) {
					
					yabancidilal(buf);
					
				}
				
				
				
			}
			
			
		} else if(asama==31) {
			
			basvuru31ciz();
			isaretcikoy(asama,secili);
			bilgileridoldur(a,asama,sayfa);
			char sayfagosterge[10]= { };
			sprintf(sayfagosterge,"<%2d /%2d >",sayfa,(a->okulsayisi/10)+1);
			syaz(sayfagosterge,18,102);
			
			yazdir();
			
			tus=tusal();
			
			if(tus==741 && secili>1) {
				secili--;
			} else if( (tus==742 || tus==771) && secili<4) {
				secili++;
			}  else if(tus==744 && sayfa>1) {
				sayfa--;
			} else if(tus==743 && sayfa<(a->okulsayisi/10)+1) {
				sayfa++;
			} else if(tus==770) {
				return -1;
			} else if( tus==778) {
				
				if(secili==1) {
					asama=32;
				} else if(secili==2 && a->okulsayisi>0) {
					
					int i,j;
					
					for(i=7;i<17;i++) {
						for(j=2;j<111;j++) {
							ekran[i][j]=0;
						}
					}
					
					syaz("Yukarı / Aşağı yön tuşlarıyla silmek istediğiniz okulu seçip ENTER'a basınız.",12,18);
					
					int silsira=1;
					
					while(1) {
						
						syaz("                                                                                                             ",8,2);
						
						struct egitim * sil=a->okul;
						
						for(i=1;i<silsira;i++) {
							sil=sil->sonraki;
						}
						
						yazdirint(sil->adi,8,5);
						yazdirint(sil->turu,8,47);
						yazdirint(sil->bolum,8,62);
						
						yazdir();
						
						tus=tusal();
						
						if(tus==770) {
							break;
						} if(tus==741 && silsira>1) {
							silsira--;
						} else if(tus==742 && silsira<a->okulsayisi) {
							silsira++;
						} else if(tus==778) {
							okulsil(a,silsira);
							break;
						}
						
					}
					
				} else if(secili==3) {
					secili=1;
					asama=41;
					sayfa=1;
				} else if(secili==4) {
					secili=3;
					asama=2;
					sayfa=1;
				}
			}
			
		} else if(asama==32) {
			basvuru32ciz();
			isaretcikoy(asama,secili);
			
			yazdirint(buf1,6,28);
			yazdirint(buf2,9,28);
			yazdirint(buf3,12,28);
			char notyaz[4]= { };
			sprintf(notyaz,"%d",buf5);
			if(buf5!=0)
				syaz(notyaz,15,28);
			syaz(buf4,18,28);
			
			
			yazdir();
			
			tus=tusal();
			
			if(tus==741 && secili>1) {
				secili--;
			} else if( (tus==742 || tus==771) && secili<6) {
				secili++;
			} else if( tus==778) {
				if(secili==2) {
					int secilitur=1;
					int i;
					memset(buf2,0,sizeof(int)*13);
					dikdortgenciz(8,72,14,90);
			
					ekran[9][69]='<';
					ekran[9][70]='-';
					
					syaz("Lise",9,74);
					syaz("Lisans",10,74);
					syaz("Yüksek Okul",11,74);
					syaz("Yüksek Lisans",12,74);
					syaz("Doktora",13,74);
					
					while(1) {
						syaz("                    ",9,28);
						for(i=9;i<14;i++) {
							ekran[i][88]=0;
						}
						
						ekran[(secilitur-1)+9][88]='<';
						
						
						yazdirint(buf2,9,28);
						
						yazdir();
						tus=tusal();
						
						if(tus==741 && secilitur>1) {
							secilitur--;
						} else if(tus==742 && secilitur<5) {
							secilitur++;
						} else if(tus==778) {
							if(secilitur==1) {
								strcpyint(buf2,"Lise");
							} else if(secilitur==2) {
								strcpyint(buf2,"Lisans");
							} else if(secilitur==3) {
								strcpyint(buf2,"Y ksek Okul");
								buf2[1]=705;
							} else if(secilitur==4) {
								strcpyint(buf2,"Y ksek Lisans");
								buf2[1]=705;
							} else if(secilitur==5) {
								strcpyint(buf2,"Doktora");
							}
							break;
						} else if(tus==770) {
							break;
						}
					
					}
					
					
				} else if(secili==6) {
					
					if(buf1[0]==0 || buf2[0]==0 || buf3[0]==0 || buf4[0]==0) {
						
						syaz("!!!   * ile işaretlenmiş alanları boş bırakmayınız.",2,26);
						
						yazdir();
						
						tus=tusal();
						
						if(tus==770) {
							memset(buf1,0,sizeof(int)*40);
							memset(buf2,0,sizeof(int)*13);
							memset(buf3,0,sizeof(int)*30);
							memset(buf4,0,sizeof(char)*9);
							buf5=0;
							
							asama=31;
							secili=1;
						}
						
					} else {
					
						char bol1[5]={ };
						
						if(buf4[4]=='-') {
							sprintf(bol1,"%s",buf4+5);
						} else {
							sprintf(bol1,"DEVM");
						}
						buf4[4]='\0';
						okulekle(a,buf1,buf2,buf3,buf4,bol1,buf5);
						
						memset(buf1,0,sizeof(int)*40);
						memset(buf2,0,sizeof(int)*13);
						memset(buf3,0,sizeof(int)*30);
						memset(buf4,0,sizeof(char)*9);
						buf5=0;
						
						asama=31;
						secili=1;
					}
				}
			} else if(tus==770) {
				
				memset(buf1,0,sizeof(int)*40);
				memset(buf2,0,sizeof(int)*13);
				memset(buf3,0,sizeof(int)*30);
				memset(buf4,0,sizeof(char)*9);
				buf5=0;
				
				asama=31;
				secili=1;
				
			} else {
				
				if(secili==1) {
					okuladial(buf1);
				} else if(secili==3) {
					okulbolumal(buf3);
				} else if(secili==4) {
					okulnotal(&buf5);
				} else if(secili==5) {
					okultarihal(buf4);
				}
				
				
			}
			
			
			
		} else if(asama==41) {
			basvuru41ciz();
			isaretcikoy(asama,secili);
			bilgileridoldur(a,asama,sayfa);
			struct isyeri *satirsay=a->is;
			int kacsatir=0;
			while(satirsay!=NULL) {
				
				struct isyeriadresleri *satirsay2=satirsay->adres;
				
				while(satirsay2!=NULL) {
					kacsatir++;
					satirsay2=satirsay2->sonraki;
				}
				
				satirsay=satirsay->sonraki;
			}
			char sayfagosterge[10]= { };
			sprintf(sayfagosterge,"<%2d /%2d >",sayfa,(kacsatir/10)+1);
			syaz(sayfagosterge,18,102);
			
			yazdir();
			
			tus=tusal();
			
			if(tus==741 && secili>1) {
				secili--;
			} else if( (tus==742 || tus==771) && secili<4) {
				secili++;
			}  else if(tus==744 && sayfa>1) {
				sayfa--;
			} else if(tus==743 && sayfa<(kacsatir/10)+1) {
				sayfa++;
			} else if(tus==770) {
				return -1;
			} else if(tus==778) {
				
				if(secili==1) {
					
					asama=42;
					
				} else if(secili==2 && a->isyerisayisi>0) {
					
					int i,j;
					
					for(i=7;i<17;i++) {
						for(j=2;j<111;j++) {
							ekran[i][j]=0;
						}
					}
					
					syaz("Yukarı / Aşağı yön tuşlarıyla iş yerini seçiniz ve silmek için ENTER'a basınız.",12,16);
					
					int silsira=1;
					
					while(1) {
						
						syaz("                                                                                                  ",8,3);
						
						struct isyeri * e=a->is;
						
						for(i=1;i<silsira;i++) {
							e=e->sonraki;
						}
						
						yazdirint(e->adi,8,5);
						yazdirint(e->gorevi,8,55);
						
						yazdir();
						
						tus=tusal();
						
						if(tus==770) {
							break;
						} if(tus==741 && silsira >1) {
							silsira--;
						} else if(tus== 742 && silsira<a->isyerisayisi) {
							silsira++;
						} else if(tus==778) {
							isyerisil(a,silsira);
							break;
						}
						
					}
					
				} else if(secili==3) {
					asama=5;
					secili=1;
				} else if(secili==4) {
					sayfa=1;
					asama=31;
					secili=3;
				}
				
			}
			
			
		} else if(asama==42) {
			
			basvuru42ciz();
			isaretcikoy(asama,secili);
			yazdirint(buf6,6,33);
			yazdirint(buf11,9,33);
			yazdirint(buf7,12,33);
			syaz(buf8,15,33);
			struct isyeriadresleri *e=buf10;
			int satiratla=0;
			while(e!=NULL) {
				syaz("-",7+satiratla,87);
				yazdirint(e->sehir,7+satiratla,89);
				satiratla++;
				e=e->sonraki;
			}
			
			yazdir();
			
			tus=tusal();
			
			if(tus==741 && secili>1) {
				secili--;
			} else if( (tus==742 || tus==771) && secili<5) {
				secili++;
			} else if(tus==778) {
				if(secili==2) {
					if(buf11[0]!=0) {
						if(buf10==NULL) {
							
							buf10=(struct isyeriadresleri *) malloc(sizeof(struct isyeriadresleri));
							buf10->sonraki=NULL;
							strcpyintint(buf10->sehir,buf11);
							memset(buf11,0,sizeof(int)*11);
							buf9++;
							
						} else {
							
							struct isyeriadresleri *eklenecekyer=buf10;
							while(eklenecekyer->sonraki!=NULL) {
								eklenecekyer=eklenecekyer->sonraki;
							}
							eklenecekyer->sonraki=(struct isyeriadresleri *) malloc(sizeof(struct isyeriadresleri));
							eklenecekyer->sonraki->sonraki=NULL;
							strcpyintint(eklenecekyer->sonraki->sehir,buf11);
							memset(buf11,0,sizeof(int)*11);
							buf9++;
						}
					}
				} else if(secili==5) {
					
					if(buf6[0]==0 || buf7[0]==0 || buf8[0]==0 || buf9==0) {
						
						syaz("!!!   * ile işaretlenmiş alanları boş bırakmayınız.",2,26);
						
						yazdir();
						
						tus=tusal();
						
						if(tus==770) {
							asama=41;
							secili=1;
							memset(buf6,0,sizeof(int)*35);
							memset(buf7,0,sizeof(int)*40);
							memset(buf8,0,sizeof(char)*4);
							buf9=0;
							if(buf10!=NULL) {
								isyeriadrestemizle(buf10);
							}
							memset(buf11,0,sizeof(int)*11);
							
						}
						
					} else {
						
						isyeriekle(a,buf6,buf7,(float)atof(buf8),buf10,buf9);
						asama=41;
						secili=1;
						memset(buf6,0,sizeof(int)*35);
						memset(buf7,0,sizeof(int)*40);
						memset(buf8,0,sizeof(char)*4);
						buf9=0;
						buf10=NULL;
						memset(buf11,0,sizeof(int)*11);
					}
				}
				
			} else if(tus==770) {
				
				asama=41;
				secili=1;
				memset(buf6,0,sizeof(int)*35);
				memset(buf7,0,sizeof(int)*40);
				memset(buf8,0,sizeof(char)*4);
				buf9=0;
				if(buf10!=NULL) {
					isyeriadrestemizle(buf10);
				}
				buf10=NULL;
				memset(buf11,0,sizeof(int)*11);
				
			} else {
				if(secili==1) {
					isyeriadial(buf6);
				} else if(secili==2) {
					isyeriadresal(buf11);
				} else if(secili==3) {
					isyerigoreval(buf7);
				} else if(secili==4) {
					isyerisureal(buf8);
				}
				
			}
			
			
		} else if(asama==5) {
			
			basvuru5ciz();
			yazdir();
			while(tusal()!=778);
			
			return 1;
			
		}
		
		
	}
	
}

void basvurusil() {
	
	int secili=1;
	
	int isim[26]={ };
	char tel[11]={ };
	
	while(1) {
		basvurusilciz();
		
		ekran[7+(secili*3)][70]='<';
		
		yazdirint(isim,10,41);
		syaz(tel,13,41);
		
		yazdir();
		
		tus=tusal();
		
		if(tus==741 && secili>1) {
			secili--;
		} else if((tus==742 || tus==771) && secili<2) {
			secili++;
		} else if(tus==770) {
			return;
		} else if(tus==778) {
			int hatasatir=0;
			
			int hatavarmi=0;
			
			if(isim[0]==0) {
				
				syaz("HATA! Lütfen ad soyad giriniz.",hatasatir++ + 20,34);
				hatavarmi=1;
				
			}
			
			if(tel[0]==0) {
				
				syaz("HATA! Lütfen telefon numarası giriniz.", hatasatir++ + 20,34);
				hatavarmi=1;
				
			}
			
			if(hatavarmi==1) {
				yazdir();
				if(tusal()==770) {
					return;
				}
				
			} else {
				
				if((dugumsil(isim,tel,0))==-1) {
					
					syaz("Girdiğiniz bilgilerin kaydı bulunamadı!",hatasatir+20,37);
					yazdir();
					if(tusal()==770) {
						return;
					}
				} else {
					
					
					memset(isim,0,sizeof(int)*25);
					memset(tel,0,sizeof(char)*10);
					
					agaciyaz();
					
					
					agacitemizle(root);
					
					root=NULL;
					
					
					agacioku();
					
					return;
					
				}
				
			}
			
		} else {
			
			if(secili==1) {
				
				int ks=karaktersayisi(isim);
				
				if(harfmi() && ks<25) {
					isim[ks]=tus;
				} else if(tus==773 && ks>0) {
					isim[--ks]=0;
				}
				
			} else if(secili==2) {
				
				int ks=strlen(tel);
				
				if(isdigit(tus) && ks<10) {
					tel[ks]=tus;
				} else if(tus==773 && ks>0) {
					tel[--ks]=0;
				}
				
			}
			
		}
		
	}
	
	
}

void basvuruduzenle() {
	
	int secili=1;
	
	int isim[26]={ };
	char tel[11]={ };
	
	while(1) {
		basvuruduzenleciz();
		
		ekran[7+(secili*3)][70]='<';
		
		yazdirint(isim,10,41);
		syaz(tel,13,41);
		
		yazdir();
		
		tus=tusal();
		
		if(tus==741 && secili>1) {
			secili--;
		} else if((tus==742 || tus==771) && secili<2) {
			secili++;
		} else if(tus==770) {
			return;
		} else if(tus==778) {
			int hatasatir=0;
			
			int hatavarmi=0;
			
			if(isim[0]==0) {
				
				syaz("HATA! Lütfen ad soyad giriniz.",hatasatir++ + 20,34);
				hatavarmi=1;
				
			}
			
			if(tel[0]==0) {
				
				syaz("HATA! Lütfen telefon numarası giriniz.", hatasatir++ + 20,34);
				hatavarmi=1;
				
			}
			
			if(hatavarmi==1) {
				yazdir();
				if(tusal()==770) {
					return;
				}
				
			} else {
				struct dugum *ara;
				if((ara=kisiara(isim,tel))==NULL) {
					
					syaz("Girdiğiniz bilgilerin kaydı bulunamadı!",hatasatir+20,37);
					yazdir();
					if(tusal()==770) {
						return;
					}
				} else {
					
					basvuruform(&ara->kisi,1);
					
					memset(isim,0,sizeof(int)*25);
					memset(tel,0,sizeof(char)*10);
					
					agaciyaz();
					agacitemizle(root);
					root=NULL;
					agacioku();
					
					return;
					
				}
				
			}
			
		} else {
			
			if(secili==1) {
				
				int ks=karaktersayisi(isim);
				
				if(harfmi() && ks<25) {
					isim[ks]=tus;
				} else if(tus==773 && ks>0) {
					isim[--ks]=0;
				}
				
			} else if(secili==2) {
				
				int ks=strlen(tel);
				
				if(isdigit(tus) && ks<10) {
					tel[ks]=tus;
				} else if(tus==773 && ks>0) {
					tel[--ks]=0;
				}
				
			}
			
		}
		
	}
	
}

