#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //iterate to make sure only one argument is inputted

    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    char *input_file = argv[1]; //to remember the filename

    FILE *inptr = fopen(input_file, "r");

    //checking validity of file
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s \n", input_file);
        return 2;
    }

    unsigned char *buffer = malloc(512);
    int counter = 0; //to count the images

    FILE *outptr;

    while (fread(buffer, 512, 1, inptr))
    {
        //looking for a new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //break out of loop and close the previous jpeg
            if (counter < 0)
            {
                fclose(outptr);
            }

            char newfile[7]; //creating a new image file
            sprintf(newfile, "%03i.jpg", counter);

            outptr = fopen(newfile, "w");

            //check if a new jpeg has been successfully created
            if (outptr == NULL)
            {
                fclose(inptr);
                free(buffer);
                fprintf(stderr, "Could not create JPEG %s \n", newfile);
                return 3;
            }

            counter++;
        }

        //in case the first JPEG isn't found yet
        if (!counter)
        {
            continue;
        }

        fwrite(buffer, 512, 1, outptr); //write jpeg into file
    }

    fclose(outptr); //close the last jpeg file
    fclose(inptr); //close the infile

    free(buffer);

    return 0;

}
