CC=g++
CXXFLAGS=-I. -std=c++11
DEPS = Client.h
OBJ = main.o Client.o
LIBS=-lws2_32

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o client