
void dikdortgenciz(int x,int y, int x2,int y2) {
	
	int i;
	
	for(i=x+1;i<x2;i++) {
		ekran[i][y]=ekran[i][y2]=601;
	}
	for(i=y+1;i<y2;i++) {
		ekran[x][i]=ekran[x2][i]=600;
	}
	
	ekran[x][y]=604;
	ekran[x][y2]=602;
	ekran[x2][y]=605;
	ekran[x2][y2]=603;
	
}

void dikdortgenkutucukciz(int x,int y,int boyut) {
	
	dikdortgenciz(x,y,x+2,y+boyut+1);
	
}

void cerceveciz() {
	int i;
	
	for(i=1;i<satir-1;i++) {
		ekran[i][0]=ekran[i][sutun-1]=501;
	}
	for(i=1;i<sutun-1;i++) {
		ekran[0][i]=ekran[satir-1][i]=500;
	}
	
	ekran[0][0]=504;
	ekran[0][sutun-1]=502;
	ekran[satir-1][0]=505;
	ekran[satir-1][sutun-1]=503;
	
	
}

void giristesec(int x,int y,int x2,int y2) {
	
	dikdortgenciz(x,y,x2,y2);
	int i;
	
	for(i=x+2;i<x2-1;i++) {
		ekran[i][y]=ekran[i][y2]=0;
	}
	
	
}

void girisekraniciz() {
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(8,21,15,47);
	dikdortgenciz(8,66,15,92);
	
	syaz("Programa Hoşgeldiniz!",3,47);
	
	syaz("İşveren Girişi",11,27);
	syaz("Kullanıcı Girişi",11,71);
	syaz("Yazanlar : Arda ŞAHİN - Gökay GÖK",23,76);
	
}

void kullanicigirisekraniciz() {
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(8,11,15,35);
	dikdortgenciz(8,44,15,68);
	dikdortgenciz(8,77,15,101);
	
	syaz(" Kullanıcı girişi yaptınız, yeni başvuru yapabilir, daha ",3,29);
	syaz("önce yaptığınız başvuruyu düzenleyebilir veya başvurunuzu",4,29);
	syaz("silebilirsiniz.",5,49);
	
	syaz("Yeni Başvuru",11,17);
	syaz("Başvuru Düzenle",11,49);
	syaz("/Görüntüle",12,51);
	syaz("Başvuru sil",11,84);
	syaz("Yazanlar : Arda ŞAHİN - Gökay GÖK",23,76);
	
}

void basvuru1ciz() {
	
	ekranitemizle();
	
		
	dikdortgenciz(0,0,3,23);
	
	cerceveciz();
	
	syaz("Yeni İş Başvurusu",2,2);
	
	dikdortgenkutucukciz(5,21,28);
	dikdortgenkutucukciz(8,21,28);
	dikdortgenkutucukciz(11,21,28);
	dikdortgenkutucukciz(14,21,28);
	dikdortgenkutucukciz(17,21,28);
	
	dikdortgenciz(5,92,16,103);
	

	
	syaz("* ile işaretlenenlerin doldurulması zorunludur.                 Sayfa:  1 / 4",2,28);
	
	
	syaz("- Başvuru boyunca kutucuk seçmek için",21,4);
	syaz("Yukarı / (Aşağı / TAB) ok tuşlarını kullanınız.",22,5);
	
	syaz("Ad Soyad *",6,4);
	syaz("Adres (Şehir) *",9,4);
	syaz("Telefon *",12,4);
	syaz("E-Mail *",15,4);
	syaz("Doğum T. (Yıl) *",18,4);
	syaz("Ehliyet :",6,61);
	syaz("A1",6,94);
	syaz("A2",7,94);
	syaz("B",8,94);
	syaz("C",9,94);
	syaz("D",10,94);
	syaz("E",11,94);
	syaz("F",12,94);
	syaz("G",13,94);
	syaz("H",14,94);
	syaz("<- Çık",15,94);
	
	dikdortgenkutucukciz(satir-4,sutun-26,22);
	
	syaz("Sonraki sayfa    --> ",satir-3,sutun-24);
	
	int i;
	
	for(i=5;i<23;i++) {
		ekran[i][56]=601;
	}
	
}

void basvuru2ciz() {
	
	ekranitemizle();
	
	dikdortgenciz(0,0,3,23);
	
	cerceveciz();
	
	syaz("Yeni İş Başvurusu",2,2);
	
	syaz("Sayfa:  2 / 4",2,92);
	
	dikdortgenkutucukciz(7,22,24);
	dikdortgenkutucukciz(11,22,24);
	
	syaz("Ekle",8,10);
	syaz("Sil",12,10);
	
	syaz("Yabancı Diller :",6,60);
	
	
	dikdortgenkutucukciz(satir-4,sutun-26,22);
	
	syaz("Sonraki sayfa    --> ",satir-3,sutun-24);
	
	dikdortgenkutucukciz(satir-4,3,22);
	
	syaz("<--     Önceki Sayfa",satir-3,5);
	
	dikdortgenciz(8,66,18,98);
	
	
}

void basvuru31ciz() {
	
	ekranitemizle();
	
	dikdortgenciz(0,0,3,23);
	
	cerceveciz();
	
	syaz("Yeni İş Başvurusu",2,2);
	
	syaz("Sayfa:  3 / 4",2,92);
	
	syaz("Okul Adı                                  Tür            Bölüm                           Tarih      Not",5,5);
	
	
	dikdortgenkutucukciz(18,47,16);
	dikdortgenkutucukciz(21,47,16);
	
	syaz("Okul Ekle",19,49);
	syaz("Sil",22,49);
	
	
	dikdortgenkutucukciz(satir-4,sutun-26,22);
	
	syaz("Sonraki sayfa    --> ",satir-3,sutun-24);
	
	dikdortgenkutucukciz(satir-4,3,22);
	
	syaz("<--     Önceki Sayfa",satir-3,5);
	
	dikdortgenciz(6,1,17,111);
	
}

void basvuru32ciz() {
	
	ekranitemizle();
	
	dikdortgenciz(0,0,3,23);
	
	cerceveciz();
	
	syaz("Yeni İş Başvurusu",2,2);
	
	syaz("Sayfa:  3 / 4",2,92);
	
	dikdortgenkutucukciz(5,26,41);
	dikdortgenkutucukciz(8,26,40);
	dikdortgenkutucukciz(11,26,40);
	dikdortgenkutucukciz(14,26,40);
	dikdortgenkutucukciz(17,26,40);
	dikdortgenkutucukciz(20,47,19);
	
	ekran[8][63]=606;
	ekran[9][63]=601;
	ekran[10][63]=608;
	
	ekran[9][65]='>';
	
	
	syaz("Okul Adı *",6,4);
	syaz("Türü *",9,4);
	syaz("Bölümü *",12,4);
	syaz("Not Ort.",15,4);
	syaz("Başla-Bitiş Tarihleri*",18,4);
	syaz("Okulu Ekle",21,49);
	syaz("ESC : Vazgeç",21,27);
	syaz("'-' ile ayırınız. Okulunuz devam edi-",18,72);
	syaz("yorsa sadece başlangıç tarihi giriniz.",19,72);
	
}

void basvuru41ciz() {
	
	
	ekranitemizle();
	
	dikdortgenciz(0,0,3,23);
	
	cerceveciz();
	
	syaz("Yeni İş Başvurusu",2,2);
	
	syaz("Sayfa:  4 / 4",2,92);
	
	syaz("İş yeri adı                          Adres        Çalıştığı Görev                           Süre",5,5);
	
	
	dikdortgenkutucukciz(18,47,16);
	dikdortgenkutucukciz(21,47,16);
	
	syaz("İş Yeri Ekle",19,49);
	syaz("Sil",22,49);
	
	
	dikdortgenkutucukciz(satir-4,sutun-26,22);
	
	syaz("Başvuru Tamamla  --> ",satir-3,sutun-24);
	
	dikdortgenkutucukciz(satir-4,3,22);
	
	syaz("<--     Önceki Sayfa",satir-3,5);
	
	dikdortgenciz(6,1,17,111);
}

void basvuru42ciz() {
	
	ekranitemizle();
	
	dikdortgenciz(0,0,3,23);
	
	cerceveciz();
	
	syaz("Yeni İş Başvurusu",2,2);
	
	syaz("Sayfa:  4 / 4",2,92);
	
	dikdortgenkutucukciz(5,31,41);
	dikdortgenkutucukciz(8,31,41);
	dikdortgenkutucukciz(11,31,41);
	dikdortgenkutucukciz(14,31,41);
	dikdortgenkutucukciz(18,52,19);
	
	ekran[8][74]=ekran[8][75]=ekran[8][76]=ekran[8][77]=600;
	ekran[8][78]=603;
	ekran[7][78]=604;
	ekran[7][79]=ekran[7][80]=ekran[7][81]=ekran[7][82]=ekran[7][83]=600;
	ekran[7][84]='>';
	
	dikdortgenciz(6,85,13,105);
	syaz("Adresler ",6,87);
	syaz("( Örnek :  1.5 )",15,79);
	
	syaz("İş Yeri Adı *",6,9);
	syaz("Adresi (Şehir) *",9,9);
	syaz("Çalıştığı Görev *",12,9);
	syaz("Çalıştığı Süre (Yıl) *",15,9);
	syaz("ESC : Vazgeç",19,32);
	syaz("İş Yeri Ekle",19,54);
	
	
}

void basvuru5ciz() {
	
	ekranitemizle();
	
	dikdortgenciz(0,0,3,23);
	
	cerceveciz();
	
	syaz("Yeni İş Başvurusu",2,2);
	
	
	syaz("İŞLEM TAMAMLANDI",2,44);
	syaz(" Başvurunuz başarıyla alınmıştır. Eğer daha sonra değişiklik",9,25);
	syaz("yapmak, bilgilerinizi görüntülemek, veya kaydınızı silmek is-",10,25);
	syaz("terseniz isminiz ve telefon numaranızla başvuru bilgilerinize",11,25);
	syaz("ulaşıp değişiklik yapabilir / silebilirsiniz.",12,25);
	syaz(" Çıkmak için ENTER'a basınız...",16,25);
	
}

void basvurusilciz() {
	
	ekranitemizle();
	cerceveciz();
	
	dikdortgenkutucukciz(9,39,28);
	dikdortgenkutucukciz(12,39,28);
	
	syaz("Başvurunuzu silmek için adınızı soyadınızı ve telefon",5,29);
	syaz("numaranızı giriniz.",6,45);
	
	syaz("Ad Soyad",10,22);
	syaz("Telefon",13,22);
	
	syaz("ESC : Vazgeç    ENTER : Onayla",17,39);
	
	
}

void basvuruduzenleciz() {
	
	ekranitemizle();
	cerceveciz();
	
	dikdortgenkutucukciz(9,39,28);
	dikdortgenkutucukciz(12,39,28);
	
	syaz("Başvurunuzu düzenlemek için adınızı soyadınızı ve telefon",5,27);
	syaz("numaranızı giriniz.",6,45);
	
	syaz("Ad Soyad",10,22);
	syaz("Telefon",13,22);
	
	syaz("ESC : Vazgeç    ENTER : Onayla",17,39);
	
	
}

void liste1ciz() {
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(4,1,19,108);
	
	dikdortgenciz(2,2,4,34);
	dikdortgenciz(2,35,4,50);
	dikdortgenciz(2,51,4,71);
	dikdortgenciz(2,72,4,90);
	
	ekran[4][2]=603;
	int i;
	
	for(i=3;i<=33;i++) {
		ekran[4][i]=0;
	}
	ekran[4][34]=605;
	
	ekran[4][35]=ekran[4][50]=ekran[4][51]=ekran[4][71]=ekran[4][72]=ekran[4][90]=608;
	
	ekran[6][1]=610;
	ekran[6][108]=609;
	
	for(i=2;i<108;i++) {
		ekran[6][i]=600;
	}
	
	
	
	syaz("İletişim - Temel Bilgiler",3,6);
	syaz("Okul",3,39);
	syaz("İş Tecrübesi",3,55);
	syaz("Filtreler",3,76);
	
	syaz("Derinlik :       Toplam Kayıt:        Sıralama : Inorder       ESC : ÇIK       'A' : Adından Kişi Ara",20,4);
	syaz("Yukarı/Aşağı ok tuşlarıyla kaydır, Sağ/Sol ok tuşlarıyla kategori, 'S' tuşuyla sıralama türü değiştir.",22,4);
	
	syaz(">",3,4);
	
	char yazi[5]={ };
	
	sprintf(yazi,"%d",derinlik);
	
	syaz(yazi,20,15);
	
	memset(yazi,0,sizeof(char)*5);
	
	sprintf(yazi,"%d",toplamkayit);
	
	syaz(yazi,20,35);
	
	
	syaz("Adres",5,4);
	syaz("Telefon",5,16);
	syaz("E-mail",5,29);
	syaz("Doğum T.",5,60);
	syaz("Ehliyet",5,70);
	syaz("Yabancı Dil",5,90);
	
	
}

void liste2ciz() {
	
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(4,1,19,108);
	
	dikdortgenciz(2,2,4,34);
	dikdortgenciz(2,35,4,50);
	dikdortgenciz(2,51,4,71);
	dikdortgenciz(2,72,4,90);
	
	ekran[4][35]=603;
	int i;
	
	for(i=36;i<=49;i++) {
		ekran[4][i]=0;
	}
	ekran[4][50]=605;
	
	ekran[4][2]=ekran[4][34]=ekran[4][51]=ekran[4][71]=ekran[4][72]=ekran[4][90]=608;
	
	ekran[6][1]=610;
	ekran[6][108]=609;
	
	for(i=2;i<108;i++) {
		ekran[6][i]=600;
	}
	
	
	syaz("İletişim - Temel Bilgiler",3,6);
	syaz("Okul",3,39);
	syaz("İş Tecrübesi",3,55);
	syaz("Filtreler",3,76);
	
	syaz("Derinlik :       Toplam Kayıt:        Sıralama : Inorder       ESC : ÇIK       'A' : Adından Kişi Ara",20,4);
	syaz("Yukarı/Aşağı ok tuşlarıyla kaydır, Sağ/Sol ok tuşlarıyla kategori, 'S' tuşuyla sıralama türü değiştir.",22,4);
	
	syaz(">",3,37);
	char yazi[5]={ };
	
	sprintf(yazi,"%d",derinlik);
	
	syaz(yazi,20,15);
	
	memset(yazi,0,sizeof(char)*5);
	
	sprintf(yazi,"%d",toplamkayit);
	
	syaz(yazi,20,35);
	
	syaz("Okul Adı",5,4);
	syaz("Tür",5,45);
	syaz("Bölüm",5,61);
	syaz("Tarih",5,93);
	syaz("Not",5,104);
	
	
}

void liste3ciz() {
	
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(4,1,19,108);
	
	dikdortgenciz(2,2,4,34);
	dikdortgenciz(2,35,4,50);
	dikdortgenciz(2,51,4,71);
	dikdortgenciz(2,72,4,90);
	
	ekran[4][51]=603;
	int i;
	
	for(i=52;i<=70;i++) {
		ekran[4][i]=0;
	}
	ekran[4][71]=605;
	
	ekran[4][2]=ekran[4][34]=ekran[4][50]=ekran[4][35]=ekran[4][72]=ekran[4][90]=608;
	
	ekran[6][1]=610;
	ekran[6][108]=609;
	
	for(i=2;i<108;i++) {
		ekran[6][i]=600;
	}
	

	syaz("İletişim - Temel Bilgiler",3,6);
	syaz("Okul",3,39);
	syaz("İş Tecrübesi",3,55);
	syaz("Filtreler",3,76);
	
	syaz("Derinlik :       Toplam Kayıt:        Sıralama : Inorder       ESC : ÇIK       'A' : Adından Kişi Ara",20,4);
	syaz("Yukarı/Aşağı ok tuşlarıyla kaydır, Sağ/Sol ok tuşlarıyla kategori, 'S' tuşuyla sıralama türü değiştir.",22,4);
	
	syaz(">",3,53);
	char yazi[5]={ };
	
	sprintf(yazi,"%d",derinlik);
	
	syaz(yazi,20,15);
	
	memset(yazi,0,sizeof(char)*5);
	
	sprintf(yazi,"%d",toplamkayit);
	
	syaz(yazi,20,35);
	
	syaz("İş Yeri Adı",5,4);
	syaz("Adres",5,40);
	syaz("Çalıştığı Görev",5,52);
	syaz("Süre",5,93);
}

void liste4ciz() {
	
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(4,1,19,108);
	
	dikdortgenciz(2,2,4,34);
	dikdortgenciz(2,35,4,50);
	dikdortgenciz(2,51,4,71);
	dikdortgenciz(2,72,4,90);
	
	ekran[4][72]=603;
	int i;
	
	for(i=73;i<=90;i++) {
		ekran[4][i]=0;
	}
	ekran[4][90]=605;
	
	ekran[4][2]=ekran[4][34]=ekran[4][50]=ekran[4][35]=ekran[4][51]=ekran[4][71]=608;
	
	

	syaz("İletişim - Temel Bilgiler",3,6);
	syaz("Okul",3,39);
	syaz("İş Tecrübesi",3,55);
	syaz("Filtreler",3,76);
	
	syaz(">",3,74);
	
	syaz("'E' : Eklenecek filtre seç             ESC : ÇIK              ENTER : Ara            'K' : Filtre kaldır ",20,2);
	
	syaz("Filtreler                         Filtre Ekle",6,7);
	
	syaz("En az lisans mezunu",8,45);
	syaz("İngilizce bilen",9,45);
	syaz("Birden fazla dil bilen",10,45);
	syaz("Deneyim süresi",11,45);
	syaz("Deneyimsiz adaylar",12,45);
	syaz("Belirli yaş altı adaylar",13,45);
	syaz("Ehliyet tipi",14,45);
	
	for(i=8;i<15;i++) {
		ekran[i][4]='-';
	}
	
}

void filtre1ciz() {
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(4,1,19,108);
	
	dikdortgenciz(2,2,4,34);
	dikdortgenciz(2,35,4,50);
	dikdortgenciz(2,51,4,71);
	
	ekran[4][2]=603;
	int i;
	
	for(i=3;i<=33;i++) {
		ekran[4][i]=0;
	}
	ekran[4][34]=605;
	
	ekran[4][35]=ekran[4][50]=ekran[4][51]=ekran[4][71]=608;
	
	ekran[6][1]=610;
	ekran[6][108]=609;
	
	for(i=2;i<108;i++) {
		ekran[6][i]=600;
	}
	
	
	
	syaz("İletişim - Temel Bilgiler",3,6);
	syaz("Okul",3,39);
	syaz("İş Tecrübesi",3,55);
	
	syaz("ESC : Filtre listesini kapat                                               'Y' : Listeyi dosyaya yazdır",20,3);
	syaz("Yukarı/Aşağı ok tuşlarıyla kaydır, Sağ/Sol ok tuşlarıyla kategori değiştir.",22,4);
	
	syaz(">",3,4);
	
	
	syaz("Adres",5,4);
	syaz("Telefon",5,16);
	syaz("E-mail",5,29);
	syaz("Doğum T.",5,60);
	syaz("Ehliyet",5,70);
	syaz("Yabancı Dil",5,90);
	
}

void filtre2ciz() {
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(4,1,19,108);
	
	dikdortgenciz(2,2,4,34);
	dikdortgenciz(2,35,4,50);
	dikdortgenciz(2,51,4,71);
	
	ekran[4][35]=603;
	int i;
	
	for(i=36;i<=49;i++) {
		ekran[4][i]=0;
	}
	ekran[4][50]=605;
	
	ekran[4][2]=ekran[4][34]=ekran[4][51]=ekran[4][71]=608;
	
	ekran[6][1]=610;
	ekran[6][108]=609;
	
	for(i=2;i<108;i++) {
		ekran[6][i]=600;
	}
	
	
	syaz("İletişim - Temel Bilgiler",3,6);
	syaz("Okul",3,39);
	syaz("İş Tecrübesi",3,55);
	
	syaz("ESC : Filtre listesini kapat                                               'Y' : Listeyi dosyaya yazdır",20,3);
	syaz("Yukarı/Aşağı ok tuşlarıyla kaydır, Sağ/Sol ok tuşlarıyla kategori değiştir.",22,4);
	
	syaz(">",3,37);
	
	syaz("Okul Adı",5,4);
	syaz("Tür",5,45);
	syaz("Bölüm",5,61);
	syaz("Tarih",5,93);
	syaz("Not",5,104);
	
}

void filtre3ciz() {
	ekranitemizle();
	cerceveciz();
	
	dikdortgenciz(4,1,19,108);
	
	dikdortgenciz(2,2,4,34);
	dikdortgenciz(2,35,4,50);
	dikdortgenciz(2,51,4,71);
	
	ekran[4][51]=603;
	int i;
	
	for(i=52;i<=70;i++) {
		ekran[4][i]=0;
	}
	ekran[4][71]=605;
	
	ekran[4][2]=ekran[4][34]=ekran[4][50]=ekran[4][35]=608;
	
	ekran[6][1]=610;
	ekran[6][108]=609;
	
	for(i=2;i<108;i++) {
		ekran[6][i]=600;
	}
	

	syaz("İletişim - Temel Bilgiler",3,6);
	syaz("Okul",3,39);
	syaz("İş Tecrübesi",3,55);
	
	syaz("ESC : Filtre listesini kapat                                               'Y' : Listeyi dosyaya yazdır",20,3);
	syaz("Yukarı/Aşağı ok tuşlarıyla kaydır, Sağ/Sol ok tuşlarıyla kategori değiştir.",22,4);
	
	syaz(">",3,53);
	
	syaz("İş Yeri Adı",5,4);
	syaz("Adres",5,40);
	syaz("Çalıştığı Görev",5,52);
	syaz("Süre",5,93);
	
	
}


