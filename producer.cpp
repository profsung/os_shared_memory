#include <sys/mman.h> // shm_open
#include <sys/stat.h> // mode constants
#include <fcntl.h> // O_* constants
#include <unistd.h> // fork pipe
#include <stdlib.h> // exit()
#include <stdio.h> // printf/scanf

#include "my_defs.h"

int main() {
	int fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
	if (fd < 0) {
		exit(1);
	}
	ftruncate(fd, SIZE);
	int* p_data = (int *)
	   mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	printf("Producer has created shared memory\n");

	for (int i = 0; i < NUMBERS; i++) {
		p_data[i] = i + 1000;
	}

	munmap(p_data, SIZE);
	close(fd);
	// shm_unlink(NAME); // if unlinked, other process cannot use
	// let the consumer unlink when done
}