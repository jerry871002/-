# you don't need to re-compile the whole program
read -p "Which country are you in?(UK/US)" country
if [ "${country}" == "UK" ]; then
    gcc -I ./includes -c hfcal_UK.c -o hfcal.o
else
    gcc -I ./includes -c hfcal.c -o hfcal.o
fi
gcc -shared hfcal.o -o ./libs/libhfcal.dylib
./elliptical
