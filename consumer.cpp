#include <iostream>
using namespace std;
#include <sys/mman.h>
#include <sys/stat.h> // mode constants
#include <fcntl.h> // O_* constants
#include <unistd.h>

const char* NAME = "SHARED_MEMORY";
const int NUMBERS = 5;
const int SIZE = NUMBERS * sizeof(int);

int main() {
	int fd = shm_open(NAME, O_RDONLY, 0666);
	if (fd < 0) {
		cerr << "shm_open() error" << endl;
		exit(1);
	}

	int* p_data = (int *)
	   mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
	cout << "Consumer: mapped address for shared memory: "
	     << p_data << endl;

	for (int i = 0; i < NUMBERS; i++) {
		cout << p_data[i] << endl;
	}

	munmap(p_data, SIZE);
	close(fd);
	shm_unlink(NAME);
}