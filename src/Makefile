INCLUDE=-I../include

all: dgemm.o

dgemm.o: dgemm.c 
	${CC} -c -fPIC dgemm.c ${INCLUDE}

clean:
	rm -rf *.o
