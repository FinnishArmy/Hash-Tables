.SUFFIXES: .c .o
CC = gcc
CCFLAGS = -g -Wall -pedantic
EXEC = main
OBJS = hashtable.o main.o

${EXEC}: ${OBJS}
	${CC} ${CCFLAGS} -o ${EXEC} ${OBJS}

.c.o:
	${CC} ${CCFLAGS} -c $<

hashtable.o: hashtable.c hashtable.h
main.o: main.c

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} ${OBJS}
