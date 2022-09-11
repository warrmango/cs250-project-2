
goal: git-commit testmemdump mem myfiledump convert test_bits test_mystring test_array

testmemdump: mymemdump.c testmemdump.c obj/orgmemdump.o
	gcc -std=gnu99 -g -o testmemdump testmemdump.c mymemdump.c obj/orgmemdump.o

mem: mymemdump.c mem.c
	gcc -std=gnu99 -g -o mem mymemdump.c mem.c

myfiledump: myfiledump.c 
	gcc -std=gnu99 -g -o myfiledump myfiledump.c

convert: convert.c
	gcc -g -o convert convert.c

test_bits: test_bits.c
	gcc -g -o test_bits test_bits.c bits.c

test_array: test_array.c array.c
	gcc -std=gnu99 -g -o test_array test_array.c array.c

test_mystring: test_mystring.c mystring.c
	gcc -std=gnu99 -g -o test_mystring test_mystring.c mystring.c

clean:
	rm -f testmemdump myfiledump mem convert test_bits

git-commit:
	git checkout master >> .local.git.out || echo
	git add *.c *.h Makefile >> .local.git.out  || echo
	git commit -a -F testpassed.txt  >> .local.git.out || echo
	git push origin master
