BUILD := ./build 
SRC := ./src 
FLAGS := -Wall 

all: 
	$(CC) $(CFLAGS) $(SRC)/ed.c -o $(BUILD)/ed

clean: 
	rm -rf $(BUILD)/*

