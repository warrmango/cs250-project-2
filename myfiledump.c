
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void filedump(char * p , int len) {
    FILE * fd = stdout;
    int lineNum = len / 16;
    int remainder = len % 16;

    //every 16 bytes, create a line of dump output in hexadecimal
    for (int j = 0; j < lineNum; j++) {

        //print starting address of bytes in this line of output
        fprintf(fd, "0x%016lX: ", (unsigned long)(j * 16));

        //print sixteen bytes in memory from starting address
        for (int i = 0; i < 16; i++) {
            int c = p[i + j * 16] & 0xFF;
            fprintf(fd, "%02X ", c);
        }
        fprintf(fd, " ");

        //going through the 16 bytes and printing each byte as an
        //ASCII charcter if possible, otherwise print the "."
        for (int i = 0; i < 16; i++) {
            int c = *(p + i + j * 16) & 0xFF;
            if (c < 32 || c >= 127) c = '.';
            fprintf(fd, "%c", c);

        }
        fprintf(fd, "\n");
    }

    //print an extra line with fewer than 16 adresses with
    //the similar process like the single step iteration above
    if (remainder != 0) {
        fprintf(fd, "0x%016lX: ", (unsigned long)(lineNum * 16));

        for (int i = 0; i < 16; i++) {
            if (i <remainder) {
                int c = p[i + lineNum * 16] & 0xFF;
                fprintf(fd, "%02X ", c);
            }
            else {
                fprintf(fd, "   ");
            }
        }
        fprintf(fd, " ");

        for (int i = 0; i < 16; i++) {
            if (i <remainder) {
                int c = *(p + i + lineNum * 16) & 0xFF;
                if (c < 32 || c >= 127) c = '.';
                fprintf(fd, "%c", c);
            }
        }
        fprintf(fd, "\n");
    }

	
}

int
main(int argc, char **argv) {
  FILE *file = fopen(argv[1], "r");
  if (!file) {
    printf("Error opening file \"invalidfile\"\n");
    return 0;
  }
  fseek(file, 0, SEEK_END);  
  int fileSize = ftell(file);
  //move the pointer to the end of file and record the total size of this file
   fseek(file, 0, SEEK_SET); 
  //reset pointer to the beginning
  if (argc == 3) {
    fileSize = fileSize > atoi(argv[2]) ? atoi(argv[2]) : fileSize;
  }
  //make sure the size is proper
  char buff[fileSize + 1];
  fread(buff, fileSize, 1, file);
  fclose(file);
  filedump(buff,fileSize);
  //put the result of fileDump into an array
}


