p: producer.cpp
	g++ producer.cpp -lrt  -o p

c: consumer.cpp
	g++ consumer.cpp -lrt -o c

clean:
	rm -f *.o p c *.zip

zip:
	zip shared_mem.zip *.h *.cpp Makefile