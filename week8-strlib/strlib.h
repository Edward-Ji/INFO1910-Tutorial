#ifndef STRLIB_H
#define STRLIB_H

int strlength(const char *);

int strfind(const char *, const char *);

int strequal(const char *, const char *);

void strcopyn(const char *, char *, int);

void strstrip(const char *, char *, char);

int strsplit(const char *, char **, char);

void strjoin(char * const *, char *, int, char);

#endif
