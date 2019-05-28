CC=gcc
CFLAGS=-I. -lavcodec -lavformat -lavutil -lswresample
DEPS = spd.h
OBJ = main.o spd.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

spd_check: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm *.o spd_check 