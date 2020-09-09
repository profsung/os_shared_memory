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
	int fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
	if (fd < 0) {
		cerr << "shm_open( ) error";
		exit(1);
	}
	ftruncate(fd, SIZE);
	int* p_data = (int *)
	   mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	cout << "Producer: mapped address for shared memory: "
	     << p_data << endl;

	for (int i = 0; i < NUMBERS; i++) {
		p_data[i] = i + 1000;
	}

	munmap(p_data, SIZE);
	close(fd);
}