#ifndef FILE_UTILS_H
#define FILE_UTILS_H

/*
 * Header file for files_utils.c. It shows what are the two methods
 * that will be used in the c file.
 *
 * Author: Nathan Lindenbaum
 * Date: 2/1/2017
 * Class: CIS343
 */

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

#endif //FILE_UTILS_H
