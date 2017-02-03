#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/*
 * This code will read in a file that the user specifies, then it will reverse the file and
 * rewrite the file back in reverse. The file will be saved with a name the the user specifies.
 * I used the following resources to help create this code,
 * - https://github.com/irawoodring/pointer_perils
 * - http://irawoodring.net/courses/343/Project_1_C.html
 * - http://stackoverflow.com/questions/11346154/read-char-from-file
 * - http://www.cs.bu.edu/teaching/c/file-io/intro/
 *
 *
 * Author: Nathan Lindenbaum
 * Date: 2/2/2017
 * Class: CIS343
 */

/*
 * This main method will read input in from the command line. Three arguments will
 * be read; ./reverse <filename of original text>.txt <new file name with reverse>.txt
 *
 * The method uses file_utils.h to read a file, then reverse it and save the new file
 * and the old file remain the same.
 */
int main(int argc, char **argv) {

    // Checks to make sure that the user has inputted the correct number of
    // commands.

    if (argc == 3) {
        char* nBuffer;
        int readFileSize;
        int writeFileSize;

        readFileSize = read_file(argv[1], &nBuffer);
        writeFileSize = write_file(argv[2], nBuffer, readFileSize);

        // Checks to see if the two files are the same
        // If the files are the different sizes, then something has
        // gone wrong
        if(readFileSize != writeFileSize){
            fprintf(stderr, "File sizes don't match, something went wrong.\n");
            exit(EXIT_FAILURE);
        }
        //getting rid of the memory that has been allocated for nBuffer
        free(nBuffer);
    }

    printf("I think everything has worked out, go check! \n");

    return 0;   //following good format by returning 0
}

