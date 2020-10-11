++ := g++
FLAGS := -std=c++11 -w
SRC := src
INC := include
BUILD := build
BIN := bin
INCLUDE := -I./$(INC)

$(BIN)/数码管识别: $(BUILD)/数码管识别.o $(BUILD)/myFunction_sim.o
	@mkdir -p $(BIN)
	$(++) $(FLAGS) $(INCLUDE) $^ -o $@ `pkg-config --cflags --libs opencv`

$(BUILD)/数码管识别.o: $(SRC)/数码管识别.cpp $(INC)/myFunction_sim.hpp
	@mkdir -p $(BUILD)
	$(++) $(FLAGS) $(INCLUDE) -c -o $@ $< `pkg-config --cflags --libs opencv`

$(BUILD)/myFunction_sim.o: $(SRC)/myFunction_sim.cpp $(INC)/myFunction_sim.hpp
	@mkdir -p $(BUILD)
	$(++) $(FLAGS) $(INCLUDE) -c -o $@ $< `pkg-config --cflags --libs opencv`

.PHONY: clean
clean:
	rm -rf $(BUILD)
	rm -rf $(BIN)/main
