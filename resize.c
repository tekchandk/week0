
// Author : Tek Chand
// 16 February 2019
// Week : 3, Problem : 2



// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main()
{

    // remember filenames
    char *infile = "large.bmp";
    char *outfile = "new_image_resize.bmp";
    float factor;

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }


    do
    {
        printf("factor: ");
        scanf("%f", &factor);
    }while(factor <= 0.0 && factor > 100.0);
    

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf,bf_n;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi,bi_n;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    bi_n = bi;
    bf_n = bf;
    // Determine the new dimensions
    bi_n.biWidth  = bi.biWidth * factor;
    bi_n.biHeight = bi.biHeight * factor;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_n = (4 - (bi_n.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    
    // Determine new image sizes
    bi_n.biSizeImage = (bi_n.biWidth * sizeof(RGBTRIPLE) + padding_n) * abs(bi_n.biHeight);
    bf_n.bfSize = bf.bfSize - bi.biSizeImage + bi_n.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_n, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_n, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline factor times
        for (int j = 0; j < factor; j++)
        {  
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int l = 0; l < factor; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }  
            
            }

            // Add a new padding
            for (int k = 0; k < padding_n; k++)
            {
                fputc(0x00, outptr);
            }
            // Return to the begining of a scale
            if (j < factor - 1)
            {
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }
        }
        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
