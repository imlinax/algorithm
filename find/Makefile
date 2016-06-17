CFLAGS += -g -std=c99
OBJS = find.o find_seq.o find_binary.o
find:$(OBJS) sort.so
	$(CC) $^ -o $@ -lm

.o:.c

clean:
	-rm *.o
	-rm find
