bin/gate.out: build/main.o build/gate.o build/func.o
	g++ build/main.o build/func.o build/gate.o -o bin/gate.out
build/main.o: src/main.cpp include/header.h
	g++ -c src/main.cpp -I include -o build/main.o
build/func.o: src/func.cpp include/header.h
	g++ -c src/func.cpp -I include -o build/func.o
build/gate.o: src/gate.cpp include/header.h
	g++ -c src/gate.cpp -I include -o build/gate.o
clean:
	rm build/*.o
