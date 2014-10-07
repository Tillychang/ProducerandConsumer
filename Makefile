NY:clean
	CC=g++
	CFLAGS=-Wall -g
	BIN=test.exe
	OBJS=main.o MutexLock.o Condition.o Thread.o Buffer1.o producer.o consumer.o
	LIBS=-lpthread
$(BIN):$(OBJS)
		$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		rm -f *.o $(BIN) 


