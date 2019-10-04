//Bill Louden
//Resizes a 24-bit uncompressed BMP by a factor of multiplier using the "recopy" method.

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize number infile outfile\n");
        return 1;
	}
    int multiplier = atoi(argv[1]);
    if (multiplier > 99 || multiplier <= 0)
    {
        printf("Enter a positive number less than 100\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

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

    // Declare infile's and outfile's header files
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    BITMAPFILEHEADER out_bf;
    BITMAPINFOHEADER out_bi;

    // read infile's BITMAPFILEHEADER
    //BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    // read infile's BITMAPINFOHEADER
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // check that infile is a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //  copy existing bitfile headers before resizing
    out_bf = bf;
    out_bi = bi;

    // change outfile's height and width values based on multiplier...
    out_bi.biWidth = bi.biWidth * multiplier;
    out_bi.biHeight = bi.biHeight * multiplier;

    //  calculate infile and outfile padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Modify outfile's sbiSizeImage in bitmapinfoheader
    out_bi.biSizeImage = (out_bi.biWidth * sizeof(RGBTRIPLE) + out_padding) * abs(out_bi.biHeight);
    out_bf.bfSize = out_bi.biSizeImage + out_bf.bfOffBits;


    // write outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // determine padding for scanlines
    //int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    // write new multiplied data to outfile

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //resize veritcal
        for (int vert = 0; vert < multiplier; vert++)
        {
            // iterate over pixels in in-file scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // resize horizontal and write to outfile
                for (int h = 0; h < multiplier; h++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                // write RGB triple to outfile
                // original code            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (after multiplied)
            for (int k = 0; k < out_padding; k++)
            {
                fputc(0x00, outptr);
            }

            // we need to move pointer back to begining of the scanline
            // width is in pixels not bytes, so use sizeof(RGBTRIPLE)
            // fseek moves the pointer to a "byte" location and we are reading triples which are pixels.
            // 1 pixel = sizeof(RGBTRIPLE) is 3 bytes...but... 1 padding = 1 byte

            fseek(inptr, -((bi.biWidth * sizeof(RGBTRIPLE)) + padding), SEEK_CUR);

        }


        // move pointer to the end of the last scanline so we cane pickup the next scanline
        fseek(inptr, (bi.biWidth * sizeof(RGBTRIPLE)) + padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
