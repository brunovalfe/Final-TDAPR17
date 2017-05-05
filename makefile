Final.exe: Final.o 
	gcc -o Final.exe Final.o

Fnal.o: Final.c
	gcc -c Final.c
clean:
	rm*.o