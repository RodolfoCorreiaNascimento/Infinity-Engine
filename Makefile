CXX := g++
CXXFLAGS := -Iinclude/SDL2
LDFLAGS := -Llib -lmingw32 -lSDL2main -lSDL2 -static-libgcc -static-libstdc++
TARGET := build/infinity_engine
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,obj/%.o,$(SRCS))
OBJ_DIR := obj
BUILD_DIR := build

all: $(BUILD_DIR) $(OBJ_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(OBJ_DIR)
