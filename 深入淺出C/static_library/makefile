encrypt.o: encrypt.c
	gcc -c encrypt.c -I ./include -o encrypt.o

checksum.o: checksum.c
	gcc -c checksum.c -I ./include -o checksum.o

libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o

bank_vault: bank_vault.c libhfsecurity.a
	gcc bank_vault.c -L . -I ./include -lhfsecurity -o bank_vault
