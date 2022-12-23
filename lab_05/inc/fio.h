#ifndef _FIO_H_ // file input-output
#define _FIO_H_

#include <stdio.h>

int fscan_text(FILE *f, char text[]);
int fscan_substrings(FILE *f, char substrings[50][50]);

#endif // _FIO_H_
