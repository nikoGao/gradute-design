/*
 * convert.c
 *
 *  Created on: 2017Äê3ÔÂ18ÈÕ
 *      Author: Niko
 */
#include <stdio.h>
FILE *fpIn, *fpOut;
short x;
#define FILE_PATH "E:\\Graduate Design\\exp13.5.4_isoMp3Dec\\data\\musicD_44p1_128bps.mp3.dec"
#define OUTPUT_FILE "E:\\Graduate Design\\exp13.5.4_isoMp3Dec\\data\\pcmFile.pcm"

void main() {
	// your code goes here
	fpIn = fopen(FILE_PATH, "rb");
	fpOut = fopen(OUTPUT_FILE, "wb");
	while (fread(&x, sizeof(short), 1, fpIn) == 1)
	{
		x = ((x >> 8) & 0xff) | ((x & 0xff) << 8);
		fwrite(&x, sizeof(short), 1, fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);
}
