CFLAGS += -Wall -g
CFLAGS += -I../ -I../include/
CFLAGS += -std=gnu11 -D_GNU_SOURCE
LDFLAGS = -L../lib/ -lleetcode

TARGET_C := $(shell ls *.c)
TARGET_OBJ = $(TARGET_C:.c=.o)
TARGET = $(subst .c,,$(TARGET_C))

all: $(TARGET)

$(TARGET): $(TARGET_OBJ)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

%.o:%.c *.h
	$(CC) $(CFLAGS) -c $@ $< $(LDFLAGS)

clean:
	rm -f *.o $(TARGET)
