CFLAGS := -Wall -I./src
SRC := src
BUILD := build
BIN := ed

SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))


all: $(BUILD)/$(BIN)

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	rm -r $(BUILD)
