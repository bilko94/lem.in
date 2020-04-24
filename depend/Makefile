all : libft.a gnl.a

libft.a :
	cd libft; make; make clean;mv libft.a ../

gnl.a :
	cd get_next; make; make clean; mv gnl.a ../

re :
	-rm *.a
	make all

clean :
	-rm *.a