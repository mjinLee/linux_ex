CC = gcc
CFLAGS = -Wall -g
LDFLAGS =
LDLIBS =

#all: calculator mywork

all: calculator

#mywork:
#	date
#	cal

#addsub.o: addsub.c addsub.h
#	gcc -c addsub.c

calculator: calculator.o addsub.o muldiv.o
#	gcc -o calculator calculator.o addsub.o muldiv.o
#	$(CC) $(LDFLAGS) -o calculator calculator.o addsub.o muldiv.o $(LDLIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS) 

calculator.o: calculator.c addsub.h muldiv.h
#	gcc -c calculator.c
#	$(CC) $(CFLAGS) -c calculator.c
#	$(CC) $(CFLAGS) -c $< 

addsub.o: addsub.c addsub.h
#	gcc -c addsub.c
#	$(CC) $(CFLAGS) -c addsub.c
#	$(CC) $(CFLAGS) -c $< 

muldiv.o: muldiv.c muldiv.h
#	gcc -c muldiv.c
#	$(CC) $(CFLAGS) -c muldiv.c
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o calculator
addsub.o: addsub.c addsub.h
calculator.o: calculator.c addsub.h muldiv.h
muldiv.o: muldiv.c muldiv.h
