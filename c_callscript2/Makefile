TARGET = call-lua
CC = gcc
OBJS = main.o
LIBS = -llua5.3
CFLAGS = -Wall
RM = rm
.SUFFIXES: .c .o

.PHONY: all
	all:$(TARGET)


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $^ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) -f $(TARGET)

.PHONY: dist_clean
dist_clean:
	$(RM) -f $(TARGET) $(OBJS)
