
int karaktersayisi(int * d) {
	int sayac=0;
	
	while(*(d++)!=0)
		sayac++;
	
	return sayac;
}

void strcpyintint(int *d, int *a) {
	int i,j=karaktersayisi(a);
		
	for(i=0;i<j;i++) {
		d[i]=a[i];
	}
	d[i]=0;
	
}

void yazdirint(int *d,int x,int y) {
	
	int ks=karaktersayisi(d);
	int i;
	
	for(i=0;i<ks;i++) {
		ekran[x][y++]=d[i];
	}

}

void yazdirintboyut(int *d,int x,int y,int b) {
	
	int i;
	
	for(i=0;i<b;i++) {
		ekran[x][y++]=d[i];
	}
	
}

int karsilastirint(const int *a,const int *b) {
	
	int alfabebuyuk[33]={'A','B','C',710,'D','E','F','G',711,
		'H','I',712,'J','K','L','M','N','O',713,'P','Q','R',
		'S',714,'T','U',715,'V','W','X','Y','Z',' '};
	
	int alfabekucuk[33]={'a','b','c',700,'d','e','f','g',701,
		'h',702,'i','j','k','l','m','n','o',703,'p','q','r',
		's',704,'t','u',705,'v','w','x','y','z',' '};
	
	int i;
	
	int j=0;
	for(i=0;i<33;i++) {
		if(a[j]==0 && b[j]==0) {
			return 0;
		} else if(a[j]==0 && b[j]!=0) {
			return 2;
		} else if(b[j]==0 && a[j]!=0) {
			return -2;
		} else if((a[j]==alfabebuyuk[i] || a[j]==alfabekucuk[i]) && (b[j]==alfabebuyuk[i] || b[j]==alfabekucuk[i])) {
			i=-1;
			j++;
			continue;
		} else if(a[j]==alfabekucuk[i] || a[j]==alfabebuyuk[i]) {
			return 1;
		} else if(b[j]==alfabekucuk[i] || b[j]==alfabebuyuk[i]) {
			return -1;
		}
		
		
	}
	
	return 0;
	
}

void strcpyint(int *d,char *a){
	int j,i=0;
	for(j=0;a[i]!=0;j++) {
		if(a[i]==-59) {
			if(a[i+1]==-97)
				d[j]=704;
			else if(a[i+1]==-98)
				d[j]=714;
			i++;
		} else if(a[i]==-60) {
			if(a[i+1]==-97)
				d[j]=701;
			else if(a[i+1]==-98)
				d[j]=711;
			else if(a[i+1]==-79)
				d[j]=702;
			else if(a[i+1]==-80)
				d[j]=712;
			i++;
		} else if(a[i]==-61) {
			if(a[i+1]==-89)
				d[j]=700;
			else if(a[i+1]==-121)
				d[j]=710;
			else if(a[i+1]==-74)
				d[j]=703;
			else if(a[i+1]==-106)
				d[j]=713;
			else if(a[i+1]==-68)
				d[j]=705;
			else if(a[i+1]==-100)
				d[j]=715;
			i++;
		} else{
			d[j]=a[i];
		}
		i++;
	}
	d[j]=0;
}
