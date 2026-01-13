#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* fpin1, * fpin2, * fpout, *fpout1;

    char infilename1[100], infilename2[100], outfilename[100];
    printf("Input file name 1: ");
    scanf("%s", infilename1);
    printf("Input file name 2: ");
    scanf("%s", infilename2);
    printf("Output file name: ");
    scanf("%s", outfilename);

   
    fpin1 = fopen(infilename1, "rb");
    if (fpin1 == NULL) {
        printf("Error opening first input file.\n");
        exit(1);
    }


    fpin2 = fopen(infilename2, "rb");
    if (fpin2 == NULL) {
        printf("Error opening second input file.\n");
        fclose(fpin1);
        exit(1);
    }

    fpout = fopen(outfilename, "wb");
    if (fpout == NULL) {
        printf("Error opening output file.\n");
        fclose(fpin1);
        fclose(fpin2);
        exit(1);
    }

 
    char magic1[3], magic2[3], magic3[3];
    int width1, height1, width2, height2, width3, height3, maxval1, maxval2, maxval3;
    fscanf(fpin1, "%s %d %d %d%*c", magic1, &width1, &height1, &maxval1);
    fscanf(fpin2, "%s %d %d %d%*c", magic2, &width2, &height2, &maxval2);


    int channel = (strcmp(magic1, "P6") == 0) ? 3 : 1;


    fprintf(fpout, "%s\n%d %d\n%d\n", magic1, width1 + width2, height1, maxval1);

    unsigned char* buffer1 = (unsigned char*)calloc(width1 * channel, sizeof(unsigned char*));
    unsigned char* buffer2 = (unsigned char*)calloc(width2 * channel, sizeof(unsigned char*));


    for (int i = 0; i < height1; i++) {
        fread(buffer1, 1, width1 * channel, fpin1); 
        fread(buffer2, 1, width2 * channel, fpin2); 
        fwrite(buffer1, 1, width1 * channel, fpout); 
        fwrite(buffer2, 1, width2 * channel, fpout); 
    }


    free(buffer1);
    free(buffer2);

    fclose(fpin1);
    fclose(fpin2);
    fclose(fpout);

    printf("%s %d %d %d\n", magic1, width1, height1, maxval1);
    printf("%s %d %d %d\n", magic2, width2, height2, maxval2);
    printf("%s %d %d %d\n", magic2, width1+width2, height2, maxval2);
    return 0;
}
