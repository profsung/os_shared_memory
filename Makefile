p: producer.cpp
	g++ producer.cpp -o p -lrt

c: consumer.cpp
	g++ consumer.cpp -o c -lrt

clean:
	rm -f *.o p c *.zip

zip:
	zip shared_mem.zip *.h *.cpp Makefile