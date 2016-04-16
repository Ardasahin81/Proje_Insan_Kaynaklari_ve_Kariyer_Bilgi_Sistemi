
void kullanicigiris() {
	int secili=1;
	
	while(1) {
		
		kullanicigirisekraniciz();
		
		if(secili==1) {
			giristesec(7,10,16,36);
		} else if(secili==2) {
			giristesec(7,43,16,69);
		} else if(secili==3) {
			giristesec(7,76,16,102);
		}
		
		
		yazdir();
		
		tus=tusal();
		
		if(tus==743 && secili<3) {
			secili++;
		} else if(tus==744 && secili>1) {
			secili--;
		} else if(tus==770) {
			return;
		} else if(tus==778) {
			
			if(secili==1) {
				struct kisibilgi *yeni;
				yeni=(struct kisibilgi *) malloc(sizeof(struct kisibilgi));
				memset(yeni,0,sizeof(struct kisibilgi));
				yeni->okul=NULL;
				yeni->yabanci=NULL;
				yeni->is=NULL;

				if(basvuruform(yeni,0)==1) {
					
					dugumekle(yeni);

					agaciyaz();

					agacitemizle(root);
					root=NULL;
					
					agacioku();
					
				}
				free(yeni);
				
			} else if(secili==2) {
				
				basvuruduzenle();
				
			} else if(secili==3) {
				
				basvurusil();
				
			}
			
		}
	}
}

void isverengiris() {
	
	duzeyhesapla(root,0);
	derinlik=0;
	toplamkayit=0;
	derinlik_toplamkayit(root);
	filtre_varmi=0;
	int secili=1;
	
	listebirsatir=0;
	listebirsatiratla=0;
	listeikisatir=0;
	listeucsatir=0;
	
	int l1=0,l2=0,l3=0;
		
	listebirsatirsay(root);
	listeikisatirsay(root);
	listeucsatirsay(root);
	
	
	int ** listebir;
	
	listebir=(int **) malloc(sizeof(int*)*listebirsatir);
	
	int i,j;
	
	for(i=0;i<listebirsatir;i++) {
		listebir[i]=(int *)malloc(sizeof(int)*104);
	}
	
	for(i=0;i<listebirsatir;i++) {
		for(j=0;j<104;j++) {
			listebir[i][j]=0;
		}
	}
	
	int siratip1=1,siratip2=1,siratip3=1;
	listebirisirala(listebir,root,siratip1);
	
	int ** listeiki;
	
	listeiki=(int **) malloc(sizeof(int*)*listeikisatir);
	
	
	for(i=0;i<listeikisatir;i++) {
		listeiki[i]=(int *)malloc(sizeof(int)*104);
	}
	
	for(i=0;i<listeikisatir;i++) {
		for(j=0;j<104;j++) {
			listeiki[i][j]=0;
		}
	}
	
	listebirsatiratla=0;
	
	listeikiyisirala(listeiki,root,siratip2);
	
	int ** listeuc;
	
	
	listeuc=(int **) malloc(sizeof(int*)*listeucsatir);
	
	
	for(i=0;i<listeucsatir;i++) {
		listeuc[i]=(int *)malloc(sizeof(int)*104);
	}
	
	for(i=0;i<listeucsatir;i++) {
		for(j=0;j<104;j++) {
			listeuc[i][j]=0;
		}
	}
	
	listebirsatiratla=0;
	listeucusirala(listeuc,root,siratip3);
	
	
	
	int sec=0;
	
	char deneyimsureal[5]={ };
	memset(filtre,0,sizeof(int)*7);
	int filtreisim[7][25]={ };
	
	int filtre_sayisi=0;
	
	deneyimsuresi=0;
	yas=0;
	memset(ehliyettipi,0,sizeof(char)*2);
	
	while(1) {
		
		if(secili==1) {
			liste1ciz();
			kaydirmacubugu(listebirsatir,l1,12);
			if(siratip1==1) {
				
				syaz("Inorder  ",20,53);
				
			} else if(siratip1==2) {
				syaz("Postorder",20,53);
			} else if(siratip1==3) {
				syaz("Preorder ",20,53);
			}
			int satiratla=0;
			for(i=l1;i<listebirsatir && i < l1+12;i++) {
				
				yazdirintboyut(listebir[i],satiratla+7,3,104);
				satiratla++;
			}
			
			yazdir();
		
			tus=tusal();
			
			if(tus==744 && secili>1) {
				secili--;
			} else if(tus==743 && secili<3) {
				secili++;
			} else if(tus==770) {
				for(i=0;i<listebirsatir;i++) {
					free(listebir[i]);
				}
				free(listebir);
				for(i=0;i<listeikisatir;i++) {
					free(listeiki[i]);
				}
				free(listeiki);
				for(i=0;i<listeucsatir;i++) {
					free(listeuc[i]);
				}
				free(listeuc);
				return;
			} else if(tus==741 && l1>0) {
				l1--;
			} else if(tus==742 && l1<listebirsatir-12) {
				l1++;
			} else if(tus=='s' || tus=='S') {
				listebirsatiratla=0;
				for(i=0;i<listebirsatir;i++) {
					for(j=0;j<104;j++) {
						listebir[i][j]=0;
					}
				}
				siratip1++;
				if(siratip1>3) {
					siratip1%=3;
				}
				listebirisirala(listebir,root,siratip1);
			} else if(tus=='A' || tus=='a') {
				
				aramayap();
				
			}
			
		} else if(secili==2) {
			liste2ciz();
			
			kaydirmacubugu(listeikisatir,l2,12);
			
			if(siratip2==1) {
				
				syaz("Inorder  ",20,53);
				
			} else if(siratip2==2) {
				syaz("Postorder",20,53);
			} else if(siratip2==3) {
				syaz("Preorder ",20,53);
			}
			int satiratla=0;
			for(i=l2;i<listeikisatir && i < l2+12;i++) {
				
				yazdirintboyut(listeiki[i],satiratla+7,3,104);
				satiratla++;
			}
			
			yazdir();
		
			tus=tusal();
			
			if(tus==744 && secili>1) {
				secili--;
			} else if(tus==743 && secili<3) {
				secili++;
			} else if(tus==770) {
				for(i=0;i<listebirsatir;i++) {
					free(listebir[i]);
				}
				free(listebir);
				for(i=0;i<listeikisatir;i++) {
					free(listeiki[i]);
				}
				free(listeiki);
				for(i=0;i<listeucsatir;i++) {
					free(listeuc[i]);
				}
				free(listeuc);
				return;
			} else if(tus==741 && l2>0) {
				l2--;
			} else if(tus==742 && l2<listeikisatir-12) {
				l2++;
			} else if(tus=='s' || tus=='S') {
				listebirsatiratla=0;
				for(i=0;i<listeikisatir;i++) {
					for(j=0;j<104;j++) {
						listeiki[i][j]=0;
					}
				}
				siratip2++;
				if(siratip2>3) {
					siratip2%=3;
				}
				listeikiyisirala(listeiki,root,siratip2);
			} else if(tus=='A' || tus=='a') {
				
				aramayap();
				
			}
			
		} else if(secili==3) {
			
			liste3ciz();
			
			kaydirmacubugu(listeucsatir,l3,12);
			
			if(siratip3==1) {
				
				syaz("Inorder  ",20,53);
				
			} else if(siratip3==2) {
				syaz("Postorder",20,53);
			} else if(siratip3==3) {
				syaz("Preorder ",20,53);
			}
			int satiratla=0;
			for(i=l3;i<listeucsatir && i < l3+12;i++) {
				
				yazdirintboyut(listeuc[i],satiratla+7,3,104);
				satiratla++;
			}
			
			yazdir();
		
			tus=tusal();
			
			if(tus==744 && secili>1) {
				secili--;
			} else if(tus==743 && secili<4) {
				secili++;
			} else if(tus==770) {
				for(i=0;i<listebirsatir;i++) {
					free(listebir[i]);
				}
				free(listebir);
				for(i=0;i<listeikisatir;i++) {
					free(listeiki[i]);
				}
				free(listeiki);
				for(i=0;i<listeucsatir;i++) {
					free(listeuc[i]);
				}
				free(listeuc);
				return;
			} else if(tus==741 && l3>0) {
				l3--;
			} else if(tus==742 && l3<listeucsatir-12) {
				l3++;
			} else if(tus=='s' || tus=='S') {
				listebirsatiratla=0;
				for(i=0;i<listeucsatir;i++) {
					for(j=0;j<104;j++) {
						listeuc[i][j]=0;
					}
				}
				siratip3++;
				if(siratip3>3) {
					siratip3%=3;
				}
				listeucusirala(listeuc,root,siratip3);
			} else if(tus=='A' || tus=='a') {
				
				aramayap();
				
			}
			
		} else if(secili==4) {
			
			liste4ciz();
			
			
			int satiratla=0;
			
			strcpyint(filtreisim[0],"En az lisans mezunu");
			strcpyint(filtreisim[1],"İngilizce bilen");
			strcpyint(filtreisim[2],"Birden fazla dil bilen");
			
			char ismeyaz[25]={ };
			
			sprintf(ismeyaz,"En az %.1f yil deneyim",deneyimsuresi);
			
			strcpyint(filtreisim[3],ismeyaz);
			
			strcpyint(filtreisim[4],"Deneyimsiz");
			
			for(i=0;i<25;i++) {
				ismeyaz[i]=0;
			}
			
			sprintf(ismeyaz,"%d yas alti",yas);
			
			strcpyint(filtreisim[5],ismeyaz);
			
			for(i=0;i<25;i++) {
				ismeyaz[i]=0;
			}
			
			sprintf(ismeyaz,"%s tip ehliyeti olan",ehliyettipi);
			
			strcpyint(filtreisim[6],ismeyaz);
			
			
			for(i=0;i<7;i++) {
				if(filtre[i]==1) {
					yazdirint(filtreisim[i],8+satiratla,6);
					satiratla++;
				}
				
			}
			
			yazdir();
			
			tus=tusal();
			
			
			if(tus==744 ) {
				secili--;
			} else if(tus==778) {
				
				filtre_varmi=1;
				
				int lfiltre1,lfiltre2,lfiltre3;
				
				listebirsatiratla=0;
				
				int i,j;
				
				for(i=0;i<listebirsatir;i++) {
					for(j=0;j<104;j++) {
						listebir[i][j]=0;
					}
				}
				for(i=0;i<listeikisatir;i++) {
					for(j=0;j<104;j++) {
						listeiki[i][j]=0;
					}
				}
				for(i=0;i<listeucsatir;i++) {
					for(j=0;j<104;j++) {
						listeuc[i][j]=0;
					}
				}
				listebirisirala(listebir,root,1);
				lfiltre1=listebirsatiratla;
				listebirsatiratla=0;
				listeikiyisirala(listeiki,root,1);
				lfiltre2=listebirsatiratla;
				listebirsatiratla=0;
				listeucusirala(listeuc,root,1);
				lfiltre3=listebirsatiratla;
				
				int fsecili=1;
				l1=0;
				l2=0;
				l3=0;
				while(1) {
					
					
					if(tus=='y' || tus== 'Y') {
						
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
									fclose(dosya);
									
									filtrelenmisleriyaz(root,dosyaadi);
									
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
					
					if(fsecili==1) {
						filtre1ciz();
						
						kaydirmacubugu(lfiltre1,l1,12);
						
						int satiratla=0;
						for(i=l1;i<lfiltre1 && i < l1+12;i++) {
							
							yazdirintboyut(listebir[i],satiratla+7,3,104);
							satiratla++;
						}
						
						yazdir();
					
						tus=tusal();
						
						if(tus==744 && fsecili>1) {
							fsecili--;
						} else if(tus==743 && fsecili<3) {
							fsecili++;
						} else if(tus==770) {
							filtre_varmi=0;
							break;
						} else if(tus==741 && l1>0) {
							l1--;
						} else if(tus==742 && l1<lfiltre1-12) {
							l1++;
						} 
						
					} else if(fsecili==2) {
						filtre2ciz();
						kaydirmacubugu(lfiltre2,l2,12);
						int satiratla=0;
						for(i=l2;i<lfiltre2 && i < l2+12;i++) {
							
							yazdirintboyut(listeiki[i],satiratla+7,3,104);
							satiratla++;
						}
						
						yazdir();
					
						tus=tusal();
						
						if(tus==744 && fsecili>1) {
							fsecili--;
						} else if(tus==743 && fsecili<3) {
							fsecili++;
						} else if(tus==770) {
							filtre_varmi=0;
							break;
						} else if(tus==741 && l2>0) {
							l2--;
						} else if(tus==742 && l2<lfiltre2-12) {
							l2++;
						} 
						
					} else if(fsecili==3) {
						filtre3ciz();
						kaydirmacubugu(lfiltre3,l3,12);
						
						int satiratla=0;
						for(i=l3;i<lfiltre3 && i < l3+12;i++) {
							
							yazdirintboyut(listeuc[i],satiratla+7,3,104);
							satiratla++;
						}
						
						yazdir();
					
						tus=tusal();
						
						if(tus==744 && fsecili>1) {
							fsecili--;
						} else if(tus==743 && fsecili<3) {
							fsecili++;
						} else if(tus==770) {
							filtre_varmi=0;
							break;
						} else if(tus==741 && l3>0) {
							l3--;
						} else if(tus==742 && l3<lfiltre3-12) {
							l3++;
						} 
						
					}
				}
				
				for(i=0;i<listebirsatir;i++) {
					for(j=0;j<104;j++) {
						listebir[i][j]=0;
					}
				}
				
				for(i=0;i<listeikisatir;i++) {
					for(j=0;j<104;j++) {
						listeiki[i][j]=0;
					}
				}
				
				for(i=0;i<listeucsatir;i++) {
					for(j=0;j<104;j++) {
						listeuc[i][j]=0;
					}
				}
				
				filtre_varmi=0;
				listebirsatiratla=0;
				listeucusirala(listeuc,root,siratip3);
				listebirsatiratla=0;
				listeikiyisirala(listeiki,root,siratip2);
				listebirsatiratla=0;
				listebirisirala(listebir,root,siratip1);
			} else if(tus==770) {
				for(i=0;i<listebirsatir;i++) {
					free(listebir[i]);
				}
				free(listebir);
				for(i=0;i<listeikisatir;i++) {
					free(listeiki[i]);
				}
				free(listeiki);
				for(i=0;i<listeucsatir;i++) {
					free(listeuc[i]);
				}
				free(listeuc);
				return;
			} else if(tus=='e' || tus=='E') {
				
				
				
				for(i=0;i<7;i++) {
					
					if(filtre[i]==0) {
						sec=i+1;
						break;
					}
				}
				
				if(sec!=0) {
					
					while(1){
						
						for(i=1;i<8;i++)  {
							ekran[i+7][43]=0;
						}
						
						ekran[sec+7][43]='>';
						int eklendimi=0;
						
						yazdir();
						
						tus=tusal();
						
						if(tus==770) {
							//~ for(i=0;i<listebirsatir;i++) {
								//~ free(listebir[i]);
							//~ }
							//~ free(listebir);
							//~ for(i=0;i<listeikisatir;i++) {
								//~ free(listeiki[i]);
							//~ }
							//~ free(listeiki);
							//~ for(i=0;i<listeucsatir;i++) {
								//~ free(listeuc[i]);
							//~ }
							//~ free(listeuc);
							//~ return;
							break;
						} else if(tus==741) {
							for(i=sec-2;i>=0;i--) {
								if(filtre[i]==0) {
									sec=i+1;
									break;
								}
							}
						} else if(tus==742) {
							
							for(i=sec;i<7;i++) {
								if(filtre[i]==0) {
									sec=i+1;
									break;
								}
							}
							
						} else if(tus==778) {
							
							if(sec==4) {
								memset(deneyimsureal,0,sizeof(char)*4);
								while(1) {
									
									dikdortgenkutucukciz(10,77,23);
									
									syaz("         ",11,79);
									
									syaz(deneyimsureal,11,79);
									
									yazdir();
									
									tus=tusal();
									
									if(tus==770) {
										
										deneyimsuresi=0;
										memset(deneyimsureal,0,sizeof(char)*4);
										syaz("                          ",10,77);
										syaz("                          ",11,77);
										syaz("                          ",12,77);
										break;
										
									} else if( tus==778) {
										
										deneyimsuresi=atof(deneyimsureal);
										memset(deneyimsureal,0,sizeof(char)*4);
										syaz("                          ",10,77);
										syaz("                          ",11,77);
										syaz("                          ",12,77);
										eklendimi=1;
										filtre[3]=1;
										filtre_sayisi++;
										break;
									} else {
										int ks=strlen(deneyimsureal);
										
										if((isdigit(tus) || tus=='.') && ks<4) {
											deneyimsureal[ks]=tus;
										} else if(tus==773 && ks>0) {
											deneyimsureal[--ks]=0;
										}
										
									}
									
									
								}
								
								
							} else if(sec==6) {
								
								memset(deneyimsureal,0,sizeof(char)*4);
								
								while(1) {
									
									dikdortgenkutucukciz(10,77,23);
									
									syaz("         ",11,79);
									
									syaz(deneyimsureal,11,79);
									
									yazdir();
									
									tus=tusal();
									
									if(tus==770) {
										
										yas=0;
										memset(deneyimsureal,0,sizeof(char)*4);
										syaz("                          ",10,77);
										syaz("                          ",11,77);
										syaz("                          ",12,77);
										break;
										
									} else if( tus==778) {
										
										yas=atoi(deneyimsureal);
										memset(deneyimsureal,0,sizeof(char)*4);
										syaz("                          ",10,77);
										syaz("                          ",11,77);
										syaz("                          ",12,77);
										eklendimi=1;
										filtre[5]=1;
										filtre_sayisi++;
										break;
									} else {
										int ks=strlen(deneyimsureal);
										
										if( isdigit(tus) && ks<4) {
											deneyimsureal[ks]=tus;
										} else if(tus==773 && ks>0) {
											deneyimsureal[--ks]=0;
										}
										
									}
									
									
								}
								
							} else if(sec==7) {
								
								dikdortgenciz(5,92,15,103);
								
								syaz("A1",6,94);
								syaz("A2",7,94);
								syaz("B",8,94);
								syaz("C",9,94);
								syaz("D",10,94);
								syaz("E",11,94);
								syaz("F",12,94);
								syaz("G",13,94);
								syaz("H",14,94);
								
								memset(ehliyettipi,0,sizeof(char)*2);
								
								int seciliehliyet=1;
								while(1) {
									
									
									for(i=6;i<15;i++) {
										ekran[i][101]=0;
									}
									
									ekran[(seciliehliyet-1)+6][101]='<';
									
									
									yazdir();
									tus=tusal();
									
									if(tus==741 && seciliehliyet>1) {
										seciliehliyet--;
									} else if(tus==742 && seciliehliyet<9) {
										seciliehliyet++;
									} else if(tus==778) {
										
										switch(seciliehliyet) {
											case 1:
												strcpy(ehliyettipi,"A1");
												break;
											case 2:
												strcpy(ehliyettipi,"A2");
												break;
											case 3:
												strcpy(ehliyettipi,"B");
												break;
											case 4:
												strcpy(ehliyettipi,"C");
												break;
											case 5:
												strcpy(ehliyettipi,"D");
												break;
											case 6:
												strcpy(ehliyettipi,"E");
												break;
											case 7:
												strcpy(ehliyettipi,"F");
												break;
											case 8:
												strcpy(ehliyettipi,"G");
												break;
											case 9:
												strcpy(ehliyettipi,"H");
												break;
											default:
											break;
										}
										
										filtre[6]=1;
										filtre_sayisi++;
										eklendimi=1;
										break;
										
									} else if(tus==770) {
										break;
									}
									
									
								}
								
							} else {
								
								filtre[sec-1]=1;
								filtre_sayisi++;
								break;
							}
							
						}
						
						if(eklendimi==1) {
							break;
						}
						
					}
					
				}
				
			} else if(tus=='k' || tus=='K') {
				
				int sec=1;
				
				if(sec<=filtre_sayisi) {
					
					while(1) {
						
						for(i=1;i<=7;i++) {
							ekran[i+7][4]='-';
						}
						
						ekran[sec+7][4]='>';
						
						
						yazdir();
						
						tus=tusal();
						
						
						if(tus==770) {
							//~ for(i=0;i<listebirsatir;i++) {
								//~ free(listebir[i]);
							//~ }
							//~ free(listebir);
							//~ for(i=0;i<listeikisatir;i++) {
								//~ free(listeiki[i]);
							//~ }
							//~ free(listeiki);
							//~ for(i=0;i<listeucsatir;i++) {
								//~ free(listeuc[i]);
							//~ }
							//~ free(listeuc);
							//~ return;
							break;
						} else if(tus==741 && sec>1) {
							sec--;
						} else if(tus==742 && sec<filtre_sayisi) {
							sec++;
						} else if(tus==778) {
							
							int say=0;
							
							for(i=0;i<7;i++) {
								if(filtre[i]==1) {
									say++;
									if(say==sec) {
										
										filtre[i]=0;
										filtre_sayisi--;
									}
								}
							}
							break;
							
						}
						
					}
					
					
				}
				
			}
			
		}
		
	}
	
}

int giris() {

	int secili=1;
	
	while(1) {
		girisekraniciz();
		
		if(secili==1) {
			giristesec(7,20,16,48);
		} else if(secili==2) {
			giristesec(7,65,16,93);
		}
		
		
		yazdir();
		
		tus=tusal();
		
		if(tus==743 && secili<2) {
			secili++;
		} else if(tus==744 && secili>1) {
			secili--;
		} else if(tus==778) {
			
			if(secili==1) {
				isverengiris();
			} else if(secili==2) {
				kullanicigiris();
			}
			
		}
	}
	
	
	return 0;
}
