gcc -I ./includes -c hfcal.c -o hfcal.o
gcc -I ./includes -c elliptical.c -o elliptical.o
# instead of making static library
# ar -rcs ./libs/libhfcal.a hfcal.o
# we make a dynamic library
gcc -shared hfcal.o ./libs/libhfcal.dylib 
gcc elliptical.o -L ./libs -lhfcal -o elliptical
