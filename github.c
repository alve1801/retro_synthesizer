#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define sample_rate 8000 // default for aplay

double freq(int x){return(x==32?0:440*pow(2,(double)(x-49)/12));} // 12tone equal temperament

unsigned char s(int i,double freq){return((unsigned char)(sin((double)i*freq*2*M_PI/sample_rate)*127+127));} // sine wave

void main(){
	unsigned char a,b,*rin;
	FILE*f=fopen("notes","r");
	int tracknum=0,tracklen=0,n=0;double speed=.025;

	// read meta
	tracknum = getc(f)-48;getc(f); // I think it unlikely that I'll ever need more than 9 tracks
	while((a=getc(f))!=10)n=10*n+a-48;speed*=n; // speed
	while((a=getc(f))!=10)tracklen=10*tracklen+a-48; // track length

	// read tracks
	rin=(unsigned char*)malloc(tracklen*tracknum);
	for(n=0;n<tracknum;n++){
		for(int i=0;i<tracklen;i++)
			*(rin+n*tracklen+i) = getc(f);
		getc(f); // newline
	}

	// main loop
	for(int i=0;;i++){
		n=i/(speed*sample_rate);
		n%=tracklen;
		a=0;
		for(int c=0;c<tracknum;c++)
			a+=s(i,freq(rin[c*tracklen+n]))/tracknum;
		putchar(a);
	}
}
