TARGET = $(shell ls | grep -P "^[\d]")


all: $(addsuffix /all, $(TARGET))

%/all:
	cd $(@D);make clean;make

clean: $(addsuffix /clean, $(TARGET))

%/clean: 
	cd $(@D);make clean;
