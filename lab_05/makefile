CC = g++
SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = out/
UNIT_DIR = unit_tests/
CFLAGS = -Werror -Wall -I$(INC_DIR) -O0

app.exe : $(OBJ_DIR)main.o $(OBJ_DIR)conveyor.o $(OBJ_DIR)search.o $(OBJ_DIR)fio.o
	$(CC) $^ -o app.exe

$(OBJ_DIR)main.o : $(SRC_DIR)main.cpp $(INC_DIR)conveyor.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)main.o

$(OBJ_DIR)conveyor.o : $(SRC_DIR)conveyor.cpp $(INC_DIR)conveyor.h $(INC_DIR)search.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)conveyor.o

$(OBJ_DIR)fio.o : $(SRC_DIR)fio.cpp $(INC_DIR)fio.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)fio.o

$(OBJ_DIR)search.o : $(SRC_DIR)search.cpp $(INC_DIR)search.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)search.o

unit_tests.exe : $(OBJ_DIR)check_main.o $(OBJ_DIR)check_default_algorithm.o \
$(OBJ_DIR)search.o $(OBJ_DIR)check_kmp_algorithm.o
	$(CC) $^ -lcheck -o unit_tests.exe

$(OBJ_DIR)check_main.o : $(UNIT_DIR)check_main.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_main.o

$(OBJ_DIR)check_default_algorithm.o : $(UNIT_DIR)check_default_algorithm.c \
$(SRC_DIR)search.cpp $(INC_DIR)search.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_default_algorithm.o

$(OBJ_DIR)check_kmp_algorithm.o : $(UNIT_DIR)check_kmp_algorithm.c \
$(SRC_DIR)search.cpp $(INC_DIR)search.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_kmp_algorithm.o

run : app.exe
	./app.exe

unit : unit_tests.exe
	./unit_tests.exe

clean :
	rm -f app.exe
	rm -f *.log
	rm -f unit_tests.exe
	rm -rf $(OBJ_DIR)
