CFLAGS=-O3 -std=c11 -I.
CXXFLAGS=-O3 -std=c++11
LDFLAGS=
DEPS = fraction.h
LD=g++
fraction: fraction.o
	$(LD) $(LDFLAGS) fraction.o  -o fraction

