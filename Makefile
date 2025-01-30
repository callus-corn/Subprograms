.SUFFIXES:

LIBNAME=libcalc.so
VERSION=0

ifndef PREFIX
PREFIX=${PWD}
endif

.PHONY: clean lib bench
all: lib

OBJS=src/dgemm.o

${OBJS}:
	${MAKE} -C src/

lib: ${OBJS}
	${CC} -shared -fPIC -o ${LIBNAME}.${VERSION} $^
	ln -fs ${LIBNAME}.${VERSION} ${LIBNAME}
	mkdir -p lib/
	mv ${LIBNAME}.${VERSION} ${LIBNAME} lib/

bench:
	${MAKE} -C bench/

clean:
	${MAKE} -C src/ clean
	${MAKE} -C bench/ clean
	rm -rf lib/
