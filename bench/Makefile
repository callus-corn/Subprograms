TARGET=ddot dgemv dgemm
all: ${TARGET}

ddot: ddot.c ../ddot.c
	${CC} ddot.c -o ddot -I.. ../ddot.c
dgemv: dgemv.c ../dgemv.c
	${CC} dgemv.c -o dgemv -I.. ../dgemv.c
dgemm: dgemm.c ../dgemm.c
	${CC} dgemm.c -o dgemm -I.. ../dgemm.c

clean:
	rm ${TARGET}
