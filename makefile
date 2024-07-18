CC = gcc 
LIBS= -lpthread

all: et ep para_mm

etime.o: etime.c
	$(CC) -c etime.c -o etime.o
	
ep: ep.o etime.o
	$(CC) -o ep ep.o etime.o
ep.o: ep.c
	$(CC) -c ep.c -o ep.o	

et: et.o etime.o
	$(CC) -o et et.o etime.o $(LIBS)
et.o: et.c
	$(CC) -c et.c -o et.o $(LIBS)

para_mm: para_mm.o etime.o
	$(CC) -o para_mm para_mm.o etime.o $(LIBS)
para_mm.o: para_mm.c
	$(CC) -c para_mm.c -o para_mm.o $(LIBS)

clean:
	rm *.o -f ep et para_mm
	
