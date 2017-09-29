#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./recover card.rawa\n");
        // printf("Usage: ./recover card.rawa\n");
        return 1;
    }
    // open memory card
    char* infile = argv[1];
  
    // open input file 
    FILE* raw_file = fopen(infile, "r");
    if (raw_file == NULL)
    {
        fprintf(stderr,"Forensic image could not open\n");
        // printf("Could not open %s.\n", infile);
        return 2;
    }
    
      int found_JPEG=0,jpgcount=0;
      uint8_t buffer_JPEG[512];
      FILE *img = NULL;
    //   int bug=0;//check bug
      while (fread(buffer_JPEG, 1, 512, raw_file) == 512)
      {
        //check first 4 bytes of each JPEG
        if(buffer_JPEG[0]==0xff&&buffer_JPEG[1]==0xd8&&buffer_JPEG[2]==0xff&&((buffer_JPEG[3]&0xf0)==0xe0))
        {
            found_JPEG=1;
        }
        //Process eacg JPEG
        if(found_JPEG)
        {
            //Close .jpeg
            if(img!=NULL)  fclose(img);  
            // if(!bug)
            // {
            //     printf("found_JPEG_buffer_JPEG[4]:%x\n",buffer_JPEG[4]);
            //     // system("pause");
            //     bug=1;
            // }
            //Create New ,jpeg
            char filename[8];
            sprintf(filename,"%04d.jpg",jpgcount);
            // Open a new JPEG file for writing
            img = fopen(filename, "w");
            // fwrite (buffer_JPEG, 1, 512, img);
            // fwrite (buffer_JPEG, 1, 512, img); //bug fixed here, can't not write buffer_JPEG to img...
            // if(img!=NULL)    fwrite (buffer_JPEG, 1, 512, img);
            jpgcount++;
            found_JPEG=0;
        }
        // if(!bug)
        // {
        //     printf("!found_JPEG_buffer_JPEG[4]:%x\n",buffer_JPEG[4]);
        //     // system("pause");
        //     // bug=1;
        // }
        if(img!=NULL)    fwrite (buffer_JPEG, 1, 512, img);
    }
    // if (img != NULL)    img=NULL; 
    // if (img != NULL) printf("End:img not NULL ");
    return 0;
}