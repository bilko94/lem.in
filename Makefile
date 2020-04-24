all : dependencies functions
	gcc main.c functions.a depend/*.a -o lemin

re :
	-rm *.a
	-cd depend; rm *.a
	make

t :
	make re
	./lemin < maps/test.map

dependencies :
	cd depend; make;

functions : readers 
	ar rc functions.a *.o
	-rm *.o

readers :
	gcc -c reader/*.c

clean :
	-rm *.a
	-cd depend; rm *.a
