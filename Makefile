##########################################################
#                                                        #
#             Makefile for lem.in						 #
#                                                        #
# First compiles the library for use in the project      #
# Before compiling the program "lem.in"					 #
#                                                        #
##########################################################

LIB = libft
NAME_CH = checker
NAME_PS = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra

dep.a : libft.a gnl.a
	ar rcs dep.a *.o global.h
	# ranlib dep.a
	rm *.o

libft.a :
	gcc -c ./dependencies/libft/*.c $(FLAGS)

gnl.a :
	gcc -c ./dependencies/get_next_line/get_next_line.c

checker.a : 
	gcc -c ./checker/*.c $(FLAGS)
	ar rcs checker.a *.o global.h 
	rm *.o

tester : dep.a checker.a
	gcc testmain.c checker.a dep.a -o tester $(FLAGS)
	rm *.a
test : tester
	./tester < maps/test.map
