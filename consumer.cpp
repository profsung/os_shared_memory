#include <sys/mman.h> // shm_open
#include <sys/stat.h> // mode constants
#include <fcntl.h> // O_* constants
#include <unistd.h> // ftruncate close
#include <stdlib.h> // exit()
#include <stdio.h> // printf/scanf

#include "my_defs.h"

int main() {
	int fd;
	for ( ; ;) {
		fd = shm_open(NAME, O_RDONLY, 0666);
		if (fd >= 0) break;
		printf("waiting for producer to create a shared memory ...\n");
		sleep(1);
	}

	int* p_data = (int *)
	   mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
	printf("Consumer successfully opened shared memory.\n");

	for (int i = 0; i < NUMBERS; i++) {
		printf("%d\n", p_data[i]);
	}

	munmap(p_data, SIZE);
	close(fd);
	shm_unlink(NAME); // shared memory is deleted
}