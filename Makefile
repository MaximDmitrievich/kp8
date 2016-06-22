PROGNAME = list_circle
CC = gcc
CFLAGS = -g -std=c99 -Wall -Werror -Wextra -pedantic -w -pipe -O3 -fno-stack-protector

all: program.c list list.c  clean
	$(CC) $(CFLAGS) program.c -L. -l$(PROGNAME) -Wl,-rpath,. -o $(PROGNAME)

list: list.c list.h 
	$(CC) $(CFLAGS) -c -fPIC list.c
	$(CC) $(CFLAGS) -shared -o lib$(PROGNAME).so -Wl,-soname,lib$(PROGNAME).so list.o


clean:
	rm -f *.o