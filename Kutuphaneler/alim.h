
int harfmi() {
	
	if(isalpha(tus) || (tus>=700 && tus<=715) || tus=='.' || tus==' ') {
		return 1;
	}
	
	return 0;	
}

void adsoyadal(struct kisibilgi *a) {
	int ks=karaktersayisi(a->adsoyad);
	
	if(harfmi() && ks<25) {
		a->adsoyad[ks]=tus;
	} else if(tus==773 && ks>0) {
		a->adsoyad[--ks]=0;
	}
	
}

void adresal(struct kisibilgi *a) {
	int ks=karaktersayisi(a->adres);
	
	if(harfmi() && ks<11) {
		a->adres[ks]=tus;
	} else if(tus==773 && ks>0) {
		a->adres[--ks]=0;
	}
}

void telefonal(struct kisibilgi *a) {
	int ks=strlen(a->tel);
	
	if(isdigit(tus) && ks<10) {
		a->tel[ks]=tus;
	} else if(tus==773 && ks>0) {
		a->tel[--ks]=0;
	}
}

void emailal(struct kisibilgi *a) {
	int ks=strlen(a->email);
	
	if((isdigit(tus) || isalpha(tus) || ispunct(tus) ) && ks<35) {
		a->email[ks]=tus;
	} else if(tus==773 && ks>0) {
		a->email[--ks]=0;
	}
	
}

void dogumtarihial(struct kisibilgi *a) {
	
	if(isdigit(tus) && a->dogumt<1000) {
		a->dogumt=(a->dogumt*10)+(tus-'0');
	} else if(tus==773 && a->dogumt>0) {
		a->dogumt/=10;
	}
	
}

void yabancidilal(int *d) {
	
	int ks=karaktersayisi(d);
	
	if(harfmi() && ks<15) {
		d[ks]=tus;
	} else if(tus==773 && ks>0) {
		d[--ks]=0;
	}
	
}

void okuladial(int *d) {
	
	int ks=karaktersayisi(d);
	
	if( (harfmi() || isdigit(tus) || tus=='-') && ks<40) {
		d[ks]=tus;
	} else if(tus==773 && ks>0) {
		d[--ks]=0;
	}
	
}

void okulbolumal(int *d) {
	
	int ks=karaktersayisi(d);
	
	if( (harfmi() || isdigit(tus) || tus=='-') && ks<30) {
		d[ks]=tus;
	} else if(tus==773 && ks>0) {
		d[--ks]=0;
	}
	
}

void okulnotal(int *d) {
	
	if(isdigit(tus) && *d<11) {
		*d=( (*d) *10)+(tus-'0');
	} else if(tus==773 && *d>0) {
		*d/=10;
	}
	
	if(*d>100)
		*d=100;
	
}

void okultarihal(char *d) {
	
	int ks=strlen(d);
	
	if((isdigit(tus) || tus=='-') && ks<9) {
		d[ks]=tus;
	} else if(tus==773) {
		d[--ks]=0;
	}
	
}

void isyeriadial(int *d) {
	
	
	int ks=karaktersayisi(d);
	
	if( (harfmi() || isdigit(tus)) && ks<35) {
		d[ks]=tus;
	} else if(tus==773 && ks>0) {
		d[--ks]=0;
	}
	
}

void isyerigoreval(int *d) {
	
	int ks=karaktersayisi(d);
	
	if( (harfmi() || isdigit(tus)) && ks<40) {
		d[ks]=tus;
	} else if(tus==773 && ks>0) {
		d[--ks]=0;
	}
	
}

void isyerisureal(char *d) {
	
	int ks=strlen(d);
	
	if( (tus=='.' || isdigit(tus)) && ks<4) {
		d[ks]=tus;
	} else if(tus==773 && ks>0) {
		d[--ks]=0;
	}
	
}

void isyeriadresal(int *d) {
	
	int ks=karaktersayisi(d);
	
	if( harfmi() && ks<11) {
		d[ks]=tus;
	} else if(tus==773 && ks>0) {
		d[--ks]=0;
	}
	
}
