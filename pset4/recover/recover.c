/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
 
 #include <stdio.h>
 #include <stdint.h>
 
 const int BLOCK_SIZE = 512;
 
 int main(int argc, char *argv[])
 {
    FILE *f;
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./recover card.rawa\n");
        // printf("Usage: ./recover card.rawa\n");
        return 1;
    }
    if ((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening the file \"ecard.raw\"...");
        return 1;
    }
    
    uint8_t buf[512];
    
    int counter = 0;
    FILE *fw = NULL;
    
    // Iterate over file contents
    while (fread(buf, BLOCK_SIZE, 1, f))
    {
        // Check if the first four bytes are a JPEG signature
        if (buf[0]==0xff&&buf[1]==0xd8&&buf[2]==0xff&&((buf[3]&0xf0)==0xe0))
        {
            // Close the file, if it is opened
            if (fw != NULL)
                fclose(fw);
            
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
                
            // Open a new JPEG file for writing
            fw = fopen(filename, "w");
            // fwrite(buf, BLOCK_SIZE, 1, fw);
            counter++;
        }
        
        if (fw != NULL)
            fwrite(buf, BLOCK_SIZE, 1, fw);
    }
    
    if (fw != NULL)
        fclose(fw);
    
    fclose(f);
 
    return 0;
 } 