CC = gcc
XX = g++
CFLAGS = -Wall
#CFLAGS += -O2
#CFLAGS += -g

TARGET = main
SOURCES = $(wildcard *.c *cpp)
OBJS = $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCES)))

$(TARGET): $(OBJS)
	$(XX) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.cpp
	$(XX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
