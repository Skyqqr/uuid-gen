.PHONY = all clean debug release
.DEFAULT_GOAL := debug #release
COMPILER = cc
NAME = main.c
OUTPUT = a.o
FLAGS = -luuid
debug:
	$(COMPILER) ${NAME} -o ${OUTPUT} ${FLAGS}
