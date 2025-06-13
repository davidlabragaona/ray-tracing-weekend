all: main.o vec3.o color.o
	gcc -o main main.o vec3.o color.o

tests:
	gcc -o tests src/vec3.c test/tests.c -lcriterion
	
main.o: src/main.c
	gcc -c src/main.c

vec3.o: src/vec3.h src/vec3.c
	gcc -c src/vec3.c

color.o: src/color.h src/color.c
	gcc -c src/color.c

clean:
	rm *.o main tests
