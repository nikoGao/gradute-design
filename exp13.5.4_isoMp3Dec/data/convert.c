#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

FILE * fpIn, * fpOut;
short x;
int main(void){
	fpIn = fopen("musicD_44p1_128bps.mp3.dec","rb");
	fpOut = fopen("pcmFile.pcm","wb");
	while(fread(&x,sizeof(short),1,fpIn)==1)
	{	
    	x = ((x>>8)&0xff)|((x&0xff)<<8);
    	fwrite(&x,sizeof(short),1,fpOut);
	}
	fclose(fpIn);
	fclost(fpOut);
}
