all : encoder

encoder : encoder.o gozinta.o
	gcc -g encoder.o gozinta.o -o encoder

encoder.o : encoder.c
	gcc -c encoder.c  

gozinta : gozinta.o
	gcc gozinta.o -o gozinta

gozinta.o : gozinta.c
	gcc -c gozinta.c 
	
clean : *.o
	rm -rf *.o
