// Bill Louden
// recover JPEG files from a disk
// there may be many (~50)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *pict_in = argv[1];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover image");
        return 1;
    }
    // open memory card - in this case card.raw
    FILE *inptr = fopen(pict_in, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", pict_in);
        return 2;
    }

    // create an temp array to hold 512 bytes of search block
    unsigned char temp[512];

    //  create variables to track the picture file and to track the number of jpegs in file
    int picture_file = 0;
    int jpegnumber = 0;

    // Create outfile name and pict_file
    char outfile[20];
    FILE *pict_file;

    // Read 512 bytes in as 1 block until EOF
    // ...find out if fread got 512 bytes before EOF
    // ...loop through temp to EOF < 512 byes to fail.

    while (fread(&temp, 512, 1, inptr))
    {
        // Check first 4 bytes of temp block if it is start of a JPEG
        if (temp[0] == 0xff &&
            temp[1] == 0xd8 &&
            temp[2] == 0xff &&
            (temp[3] & 0xf0) == 0xe0)
            // if all conditions met, then this is the start of a new JPEG
        {
            // open pict_file if not already open
            if (picture_file)
            {
                // close the opened file
                fclose(pict_file);

                // set picture_file to false
                picture_file = 0;

                // create new file name
                sprintf(outfile, "%03d.jpg", jpegnumber);

                // show file name output
                //eprintf("The name of the new file is %s\n", outfile);

                // apply and open new outfile
                pict_file = fopen(outfile, "a");

                // set picture_file to true
                picture_file = 1;

                // Increment our jpegnumber count
                jpegnumber++;
            }
            if (!picture_file)
            {
                // create a new file and open it
                sprintf(outfile, "%03d.jpg", jpegnumber);
                pict_file = fopen(outfile, "w");

                picture_file = 1;

                jpegnumber++;
            }
            // write temp to pict_file
            fwrite(&temp, 512, 1, pict_file);
        }
        // if not picture_file...this is not the start of a new JPEG
        else
        {
            if (picture_file)
            {
                // Write the block to the file
                fwrite(&temp, 512, 1, pict_file);
            }
            if (!picture_file)
            {
                // Do nothing, start new loop
            }

        }

    }

    // while search is done, then EOF
    // Close the initial image file
    fclose(inptr);

    // close any open jpeg file
    fclose(pict_file);

    return 0;
}

