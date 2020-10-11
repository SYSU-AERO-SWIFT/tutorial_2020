number.out : main.o func.o
	g++ -o number.out main.o func.o `pkg-config --cflags --libs opencv`
main.o : main.cpp header.h
	g++ -c main.cpp
func.o : func.cpp header.h
	g++ -c func.cpp
clean:
	rm main.o func.o	

