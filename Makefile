CXX = g++
CXXFLAGS = -Iinclude -std=c++17
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = main.cpp
OUT = main.exe

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(SRC) -o $(OUT) $(CXXFLAGS) $(LDFLAGS)

clean:
	del $(OUT)
