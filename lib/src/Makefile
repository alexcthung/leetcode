CFLAGS += -Wall -g
CFLAGS += -I../
CFLAGS += -std=gnu11 -D_GNU_SOURCE
LDFLAGS = 

TARGET_C  := $(shell ls *.c)
TARGET_H   = $(TARGET_C:.c=.h)
TARGET_OBJ = $(TARGET_C:.c=.o)
TARGET = libleetcode.a

INC_PATH = ../../include/

all: $(TARGET)
	cp $(TARGET_H) $(INC_PATH)
	mv $(TARGET) ../

$(TARGET): $(TARGET_OBJ)
	$(AR) rcs -o $@ $?

%.o:%.c %.h
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

clean:
	rm -f *.o ../$(TARGET)
	rm -f $(addprefix $(INC_PATH), $(TARGET_H))
