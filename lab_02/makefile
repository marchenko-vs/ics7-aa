CC = g++
SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = out/
UNIT_DIR = unit_tests/
CFLAGS = -Werror -Wall -std=c++20 -Wextra -I$(INC_DIR) -O0

app.exe : $(OBJ_DIR)main.o $(OBJ_DIR)matrix.o $(OBJ_DIR)analysis.o
	$(CC) $^ -o app.exe

$(OBJ_DIR)main.o : $(SRC_DIR)main.cpp $(INC_DIR)matrix.h $(INC_DIR)analysis.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)main.o

$(OBJ_DIR)matrix.o : $(SRC_DIR)matrix.cpp $(INC_DIR)matrix.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)matrix.o

$(OBJ_DIR)analysis.o : $(SRC_DIR)analysis.cpp $(INC_DIR)matrix.h $(INC_DIR)analysis.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)analysis.o

unit_tests.exe : $(OBJ_DIR)check_main.o $(OBJ_DIR)check_default_mul.o \
$(OBJ_DIR)check_winograd.o $(OBJ_DIR)matrix.o $(OBJ_DIR)check_optimized_winograd.o
	$(CC) $^ -lcheck -o unit_tests.exe

$(OBJ_DIR)check_main.o : $(UNIT_DIR)check_main.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_main.o

$(OBJ_DIR)check_default_mul.o : $(UNIT_DIR)check_default_mul.cpp $(SRC_DIR)matrix.cpp $(INC_DIR)matrix.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_default_mul.o

$(OBJ_DIR)check_winograd.o : $(UNIT_DIR)check_winograd.cpp $(SRC_DIR)matrix.cpp $(INC_DIR)matrix.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_winograd.o

$(OBJ_DIR)check_optimized_winograd.o : $(UNIT_DIR)check_optimized_winograd.cpp $(SRC_DIR)matrix.cpp $(INC_DIR)matrix.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_optimized_winograd.o

run : app.exe
	./app.exe

unit : unit_tests.exe
	./unit_tests.exe

clean :
	rm -f app.exe
	rm -f unit_tests.exe
	rm -rf $(OBJ_DIR)
