
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE* fd, char* p, int len) {
    //the exact lines of the memorydump will have if len % 16 = 0,

    FILE * fd = stdout;
    int lineNum = len / 16;
    int remainder = len % 16;

    //every 16 bytes, create a line of dump output in hexadecimal
    for (int j = 0; j < lineNum; j++) {

        //print starting address of bytes in this line of output
        fprintf(fd, "0x%016lX: ", (unsigned long)(p + j * 16));

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
        fprintf(fd, "0x%016lX: ", (unsigned long)(p + lineNum * 16));

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