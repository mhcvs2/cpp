
gcc -c bill.c fred.c
-----------------------
gcc -c main.cpp
gcc -o main main.o mylib/fred.o
----------------------------
ar crv libfoo.a bill.o fred.o
gcc -o main main.o mylib/libfoo.a
gcc -o main main.o -L./mylib -lfoo