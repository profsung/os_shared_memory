p: producer.cpp
	g++ producer.cpp -o p.out -lrt

c: consumer.cpp
	g++ consumer.cpp -o c.out -lrt

clean:
	rm -f *.o *.out