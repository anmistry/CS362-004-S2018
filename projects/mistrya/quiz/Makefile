CFLAGS = -Wall -fpic -coverage -lm

testme:
	gcc -o testme testme.c -g $(CFLAGS)
	
runtests: testme
	./testme
	

clean:
	rm -f testme testme.o *.gcov *.gcda *.gcno *.so *.out
