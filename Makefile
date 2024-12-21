FLAGS := -Wall 

all: 
	$(CC) $(CFLAGS) src/ed.c -o build/ed

clean: 
	rm -rf $(BUILD)/*

