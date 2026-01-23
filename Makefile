CXX = g++
CXXFLAGS = -Wall
LFLAGS =
OBJS = mainstatki.o gra.o boat2.o boat3.o boat4.o boat5.o module.o
all: statki
statki: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
clean:
	rm -f *.o statki
.PHONY: all clean