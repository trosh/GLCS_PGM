CPPC := g++
CPPFLAGS := -std=c++11 -Wall -O2 -fopenmp

.PHONY: all run clean

all: main

main: main.cpp Pixels.o Pixmap.o Filter.o PGM.o Convolution.hpp
	$(CPPC) $(CPPFLAGS) -o$@ Pixels.o Pixmap.o Filter.o PGM.o $<

Pixels.o: Pixels.cpp Pixels.hpp Pixel.hpp
	$(CPPC) $(CPPFLAGS) -o$@ -c $<

Pixmap.o: Pixmap.cpp Pixmap.hpp Pixels.hpp Pixel.hpp
	$(CPPC) $(CPPFLAGS) -o$@ -c $<

Filter.o: Filter.cpp Filter.hpp Pixmap.hpp Pixels.hpp Pixel.hpp
	$(CPPC) $(CPPFLAGS) -o$@ -c $<

PGM.o: PGM.cpp PGM.hpp Pixmap.hpp Pixels.hpp Pixel.hpp
	$(CPPC) $(CPPFLAGS) -o$@ -c $<

run: main
	./$< angry.ppm

clean:
	rm -f *.o main
