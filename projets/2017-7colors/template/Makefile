all: 7colors

7colors: 7colors.o
	gcc 7colors.o -o 7colors

7colors.o: 7colors.c
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter 7colors.c -c -g

clean::
	rm -f *.o *~
