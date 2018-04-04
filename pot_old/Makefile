
INCLUDE=-I/home/vit/include -I/home/vit/progs/src/eigen-eigen-67e894c6cd8f -I/home/vit/intel/mkl/include

all: spectra.exe

spectra.exe: matrix.o leg_arr.o pot.o libwignerSymbols.so.0.2.0  
	g++ -o spectra.exe  matrix.o leg_arr.o pot.o libwignerSymbols.so.0.2.0 /home/vit/intel/mkl/lib/intel64/libmkl_rt.so

matrix.o: matrix.cpp
	g++ -c matrix.cpp $(INCLUDE)

pot.o: pot.h pot.cpp
	g++ -c pot.cpp $(INCLUDE)

leg_arr.o: leg_arr.cpp leg_arr.h
	g++ -c leg_arr.cpp $(INCLUDE)


