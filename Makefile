.SUFFIXES: .c .o
CC = gcc
CCFLAGS = -g -Wall -pedantic
EXEC = main
OBJS = hashtable.o main.o crc64.o freeMem.o

${EXEC}: ${OBJS}
	${CC} ${CCFLAGS} -o ${EXEC} ${OBJS}

.c.o:
	${CC} ${CCFLAGS} -c $<

crc64.o: crc64.c crc64.h
freeMem.o: freeMem.c freeMem.h
hashtable.o: hashtable.c hashtable.h
main.o: main.c

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} ${OBJS}
