all : dependencies functions.a
	gcc main.c *.a -o lem-in

re : fclean all

t :
	make re
	./lem-in < maps/visit.map

tl :
	make re
	valgrind --leak-check=full ./lem-in < maps/visit.map

supper : re
	./lem-in < maps/test_big_superposition.map

supperleaks : re
	valgrind --leak-check=full ./lem-in < maps/test_big_superposition.map

dependencies :
	cd libft; make; make clean;mv libft.a ../
	cd get_next; make; make clean; mv gnl.a ../

functions.a : function
	ar rc functions.a *.o
	-rm *.o

function :
	gcc -c functions/*.c
	gcc -c logic/*.c
	gcc -c mover/*.c

clean :
	-rm *.a

fclean : clean
	-rm lem-in
