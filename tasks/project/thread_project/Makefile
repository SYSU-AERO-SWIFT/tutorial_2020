bin/wr.out: build/main.o build/thread.o
	g++ build/main.o build/thread.o -o bin/wr.out -pthread -std=c++11
build/main.o: src/main.cpp include/header.h
	g++ -c src/main.cpp -o build/main.o -I include  -std=c++11
build/thread.o: src/thread.cpp include/header.h
	g++ -c src/thread.cpp -o build/thread.o -I include -std=c++11
clean:
	rm build/main.o build/thread.o
