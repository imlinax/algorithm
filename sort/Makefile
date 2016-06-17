CFLAGS += -g
FIND_OBJS =  sort_maopao.o sort_select.o sort_insert.o sort_quick.o swap.o 
FIND_OBJS += sort_shell.o sort_merge.o sort_heap.o
MAIN_OBJS = sort.o calc_time.o
CFLAGS = -g -O1 -std=c99
LIBS = -lm
sort:$(FIND_OBJS) $(MAIN_OBJS)
	$(CC)  $^ -o $@ -lm

%o:%c

sort.so:$(FIND_OBJS)
	$(CC) -fPIC -shared -o $@ $^
clean:
	-rm -f sort
	-rm -f *.o
	-rm -f sort.so
