#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/*
 * This code will read in a file that the user specifies,  and
 * rewrite the file.. The file will be saved with a name the the user specifies.
 * I used the following resources to help create this code;
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
 * This method will read a file and add it to a buffer.
 * Referenced and reworked from:
 * http://www.cs.bu.edu/teaching/c/file-io/intro/
 *
 * Param: Char *filename, pointer to the file
 * Param: Char **buffer, pointer to the pointer of the buffer that
 *                       holds the file information.
 *
 * Return: int size, size of read file.
 */
int read_file(char* filename, char **buffer){

    FILE *userText = fopen( filename, "r");

    // Checking to see if the file exists/actually was opened.
    // If the file did not open, then it exits with EXIT_FAILURE
    if(userText == NULL){
        fprintf( stderr, "Cannot find file... \n");
        exit(EXIT_FAILURE);

    }

    // File has been created. This checks the file size.
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    // This allocates memory to the buffer's pointer with the size of
    // the size of the file * size of a character
    *buffer = malloc(size * sizeof(char));
    char letter;

    // This runs a loop where it gets the first character in the file,
    // adds it to the buffer, then continues to go on and on until it
    // has reached the end of the file.
    for (int i = 0; i <= size; i ++) {

        letter = (char) fgetc(userText);
        (*buffer)[i] = letter;
    }
    // Closes file and returns the size of the file.
    fclose(userText);
    return size;
}

/*
 * This method will take three params, and write the file backwards into a new file
 * that the user specified. It has error blocking if the file cannot be opened.
 * It will return the new file size. This integer will be used to test against the
 * original size to make sure they are the same.
 *
 * Param: *filename, pointer to the original file.
 * Param: *buffer, pointer to the original buffer.
 * Param: int size, size of the file read into the buffer.
 *
 * Return: nfSize, the new file size
 */

int write_file(char *filename, char *buffer, int size) {

    // create a new file pointer to the original file name.
    FILE* newFile = fopen(filename, "w");

    // Error checking to see if the file was opened,
    // If not, exit failure code sent.
    if(newFile == NULL){
        fprintf(stderr, "Cannot find file... \n");
        exit(EXIT_FAILURE);
    }

    // Loop that will read the original file, char by char,
    // backwards and load it into the buffer.
    for (int i = size - 1; i >= 0; i --){
        fputc(buffer[i], newFile);
    }

    // Closing the new file, (saved)
    fclose(newFile);

    // Checks the newFile's size and returns it.
    struct stat st;
    stat(filename, &st);
    int nfSize = st.st_size;

    return nfSize;
}

