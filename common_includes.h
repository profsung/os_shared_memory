#include <sys/mman.h> // shm_open
#include <sys/stat.h> // mode constants
#include <fcntl.h> // O_* constants
#include <unistd.h> // fork pipe
#include <stdlib.h> // exit()
#include <stdio.h> // printf/scanf

const char* NAME = "SHARED_MEMORY";
const int NUMBERS = 5;
const int SIZE = NUMBERS * sizeof(int);