CC = gcc
SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = out/
UNIT_DIR = unit_tests/
CFLAGS = -Werror -Wall -I$(INC_DIR) -O0

app.exe : $(OBJ_DIR)main.o $(OBJ_DIR)array.o
	$(CC) $^ -o app.exe

$(OBJ_DIR)main.o : $(SRC_DIR)main.c $(INC_DIR)array.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)main.o

$(OBJ_DIR)array.o : $(SRC_DIR)array.c $(INC_DIR)array.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)array.o

unit_tests.exe : $(OBJ_DIR)check_main.o $(OBJ_DIR)check_merge_sort.o $(OBJ_DIR)array.o
	$(CC) $^ -lcheck -o unit_tests.exe

$(OBJ_DIR)check_main.o : $(UNIT_DIR)check_main.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_main.o

$(OBJ_DIR)check_merge_sort.o : $(UNIT_DIR)check_merge_sort.c $(SRC_DIR)array.c $(INC_DIR)array.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_merge_sort.o

run : app.exe
	./app.exe

unit : unit_tests.exe
	./unit_tests.exe

clean :
	rm -f app.exe
	rm -f unit_tests.exe
	rm -rf $(OBJ_DIR)
