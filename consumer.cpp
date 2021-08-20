#include <sys/mman.h>
#include <sys/stat.h> // mode constants
#include <fcntl.h> // O_* constants
#include <unistd.h>
#include <iostream>
using namespace std;

#include "mydefs.h"

int main() {
	int fd;
	for ( ; ;) {
		fd = shm_open(NAME, O_RDONLY, 0666);
		if (fd >= 0) break;
		cout << "waiting for producer to create a shared memory ..." << endl;
		sleep(1);
	}

	int* p_data = (int *)
	   mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
	cout << "Consumer successfully opened shared memory." << endl;

	for (int i = 0; i < NUMBERS; i++) {
		cout << p_data[i] << endl;
	}

	munmap(p_data, SIZE);
	close(fd);
	shm_unlink(NAME);
}