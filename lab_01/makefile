CC = g++
SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = out/
UNIT_DIR = unit_tests/
CFLAGS = -Werror -Wall -Wextra -I$(INC_DIR) -O0 

app.exe : $(OBJ_DIR)main.o $(OBJ_DIR)levenshtein.o
	$(CC) $^ -o app.exe

$(OBJ_DIR)main.o : $(SRC_DIR)main.cpp $(INC_DIR)levenshtein.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)main.o

$(OBJ_DIR)levenshtein.o : $(SRC_DIR)levenshtein.cpp $(INC_DIR)levenshtein.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)levenshtein.o

unit_tests.exe : $(OBJ_DIR)check_main.o $(OBJ_DIR)check_levenshtein.o \
$(OBJ_DIR)levenshtein.o $(OBJ_DIR)check_damerau_levenshtein.o \
$(OBJ_DIR)check_damerau_levenshtein_rec.o $(OBJ_DIR)check_damerau_levenshtein_cache.o
	$(CC) $^ -lcheck -o unit_tests.exe

$(OBJ_DIR)check_main.o : $(UNIT_DIR)check_main.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_main.o

$(OBJ_DIR)check_levenshtein.o : $(UNIT_DIR)check_levenshtein.cpp
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_levenshtein.o

$(OBJ_DIR)check_damerau_levenshtein.o : $(UNIT_DIR)check_damerau_levenshtein.cpp
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_damerau_levenshtein.o

$(OBJ_DIR)check_damerau_levenshtein_rec.o : $(UNIT_DIR)check_damerau_levenshtein_rec.cpp
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_damerau_levenshtein_rec.o

$(OBJ_DIR)check_damerau_levenshtein_cache.o : $(UNIT_DIR)check_damerau_levenshtein_cache.cpp
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_damerau_levenshtein_cache.o

.PHONY : run unit clean

run : app.exe
	./app.exe

unit : unit_tests.exe
	./unit_tests.exe

clean :
	rm -f app.exe
	rm -f unit_tests.exe
	rm -rf $(OBJ_DIR)
