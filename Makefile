all: test


test: a.out
	cat ./input.test.txt | ./a.out

a.out: main.c
	gcc main.c -o a.out

clean:
	rm ./a.out
