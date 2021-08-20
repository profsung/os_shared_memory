p: producer.cpp
	g++ producer.cpp -o p -lrt

c: consumer.cpp
	g++ consumer.cpp -o c -lrt

clean:
	rm -f *.o p c