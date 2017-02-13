$ make
gcc -Wall -Wextra -Werror -c main.c
gcc -Wall -Wextra -Werror -c point.c
gcc -g main.o point.o -o prog
$ ./prog
2: 30, 60
$ make clean
rm -f main.o point.o prog
