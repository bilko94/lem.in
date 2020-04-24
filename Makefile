all : dependencies functions
	gcc main.c functions.a depend/*.a -o main

re :
	-rm *.a
	cd depend; rm *.a
	make
t :
	make re
	./main < maps/test.map

dependencies :
	cd depend; make;

functions : readers 
	ar rc functions.a *.o
	-rm *.o

readers :
	gcc -c reader/*.c
