all : dependencies functions.a
	gcc main.c functions.a depend/*.a -o lemin

re :
	-rm *.a
	-cd depend; rm *.a
	make

t :
	make re
	./lemin < maps/visit.map

tl :
	make re
	valgrind --leak-check=full ./lemin < maps/visit.map

tld :
	make re
	valgrind --leak-check=full -v --track-origins=yes ./lemin < maps/visit.map

dependencies :
	cd depend; make;

functions.a : function
	ar rc functions.a *.o
	-rm *.o

function :
	gcc -c functions/*.c
	gcc -c logic/*.c

clean :
	-rm *.a
	-cd depend; make clean

fclean :
	-make clean
	-rm lemin
