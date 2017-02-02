LIB = lib
TARGET = $(shell ls | grep -P "^[\d]")

all: $(addsuffix /all, $(TARGET))

%/all: $(LIB)
	cd $(@D);make clean;make

$(LIB): $(addsuffix /library, $(LIB))

%/library:
	cd $(@D);make clean;make

clean-all: clean-lib clean

clean-lib: $(addsuffix /clean, $(LIB))

clean: $(addsuffix /clean, $(TARGET))

%/clean: 
	cd $(@D);make clean;
