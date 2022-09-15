INC_DIR = headers
OBJ_DIR = modules
CC = g++ -g3 -g -std=c++11 

ergasia3: main.o $(OBJ_DIR)/creature.o $(OBJ_DIR)/good_creature.o $(OBJ_DIR)/bad_creature.o $(OBJ_DIR)/creature_society.o

	$(CC) -o ergasia3 main.o $(OBJ_DIR)/creature.o $(OBJ_DIR)/good_creature.o $(OBJ_DIR)/bad_creature.o $(OBJ_DIR)/creature_society.o

run:

	./ergasia3 20 200 2 3 3

valgrind:

	valgrind --leak-check=yes ./ergasia3 5 20 10 10 10

gdb:
	gdb ./ergasia3 5 200 10 10 10

clean: 

	rm -f *.o modules/*.o

	
	

