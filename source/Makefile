all:
	gcc -I../header *.c -c
	cp *.o ../object
debug:
	gcc -g -I../header *.c -c
	cp *.o ../object
build:
	gcc *.o -o finanApp -lm
	cp finanApp ../build
	rm *.o 
clean:
	rm -r *.o finanApp
	
	
