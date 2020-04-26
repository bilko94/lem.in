all : dependencies functions.a
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

functions.a : function
	ar rc functions.a *.o
	-rm *.o

function :
	gcc -c functions/*.c

clean :
	-rm *.a
	-cd depend; make clean

fclean :
	-make clean
	-rm lemin
