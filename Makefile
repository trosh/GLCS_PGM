CPPC := g++
MPICC := mpic++
CPPFLAGS := -std=c++11 -Wall -O2 -fopenmp
NP := 2

.PHONY: all run clean

all: main

main: main.cpp Pixels.o Pixmap.o Filter.o PGM.o PixPara.o
	$(MPICC) $(CPPFLAGS) -o$@ Pixels.o Pixmap.o \
	Filter.o PGM.o PixPara.o $<

Pixels.o: Pixels.cpp Pixels.hpp Pixel.hpp
	$(MPICC) $(CPPFLAGS) -o$@ -c $<

Pixmap.o: Pixmap.cpp Pixmap.hpp Pixels.hpp Pixel.hpp
	$(MPICC) $(CPPFLAGS) -o$@ -c $<

Filter.o: Filter.cpp Filter.hpp Pixmap.hpp Pixels.hpp Pixel.hpp
	$(MPICC) $(CPPFLAGS) -o$@ -c $<

PGM.o: PGM.cpp PGM.hpp Pixmap.hpp Pixels.hpp Pixel.hpp
	$(MPICC) $(CPPFLAGS) -o$@ -c $<

PixPara.o: PixPara.cpp PixPara.hpp Pixmap.o Pixmap.hpp
	$(MPICC) $(CPPFLAGS) -o$@ -c $<

run: main
	mpirun -np $(NP) ./$< angry.ppm

clean:
	rm -f *.o main
