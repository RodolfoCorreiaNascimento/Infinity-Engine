# Compiler
CXX = g++

# Directories
SRCDIR = src
BUILDDIR = build
INCDIR = include/SDL2
LIBDIR = lib

# Compiler flags
CXXFLAGS = -I$(INCDIR)

# Libraries
LIBS = -L$(LIBDIR) -lmingw32 -lSDL2main -lSDL2 -static-libgcc -static-libstdc++

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Executable
EXEC = $(BUILDDIR)/infinity_engine

# Build rules
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(BUILDDIR)/*.o $(EXEC)