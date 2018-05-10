gcc -I ./includes -c hfcal.c -o hfcal.o
echo "hfcal.o"
gcc -I ./includes -c elliptical.c -o elliptical.o
echo "elliptical.o"
# instead of making static library
# ar -rcs ./libs/libhfcal.a hfcal.o
# we make a dynamic library
gcc -shared hfcal.o -o ./libs/libhfcal.dylib
echo "libhfcal.dylib"
gcc elliptical.o -L ./libs -lhfcal -o elliptical
echo "elliptical"
