TARGET=calc

ifndef CALCLIB
CALCLIB=..
endif

ifdef OPENBLASLIB
TARGET+=openblas
endif

ifdef ARMPLLIB
TARGET+=armpl
endif

CALCFLAGS=-L${CALCLIB}/lib -I${CALCLIB}/include -lcalc -DCALC
OPENBLASFLAGS=-L${OPENBLASLIB}/lib -I${OPENBLASLIB}/include -lopenblas -DOPENBLAS
ARMPLFLAGS=-L${ARMPLLIB}/lib -I${ARMPLLIB}/include -larmpl -DARMPL

all: ${TARGET}

calc: dgemm.calc
openblas: dgemm.openblas
armpl: dgemm.armpl

dgemm.calc: dgemm.c
	${CC} $^ -o $@ ${CALCFLAGS}
dgemm.openblas: dgemm.c
	${CC} $^ -o $@ ${OPENBLASFLAGS}
dgemm.armpl: dgemm.c
	${CC} $^ -o $@ ${ARMPLFLAGS}

clean:
	rm -f dgemm.calc
	rm -f dgemm.openblas
	rm -f dgemm.armpl
