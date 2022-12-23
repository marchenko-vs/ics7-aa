CC = g++
SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = obj/
UNIT_DIR = unit_tests/
CFLAGS = -Werror -Wall -std=c++20 -Wextra -I$(INC_DIR)

app.exe : $(OBJ_DIR)main.o $(OBJ_DIR)sort.o $(OBJ_DIR)testing_sort.o
	$(CC) $^ -o app.exe

$(OBJ_DIR)main.o : $(SRC_DIR)main.cpp $(INC_DIR)testing_sort.h $(INC_DIR)sort.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)main.o

$(OBJ_DIR)sort.o : $(SRC_DIR)sort.cpp $(INC_DIR)sort.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)sort.o

$(OBJ_DIR)testing_sort.o : $(SRC_DIR)testing_sort.cpp \
$(INC_DIR)sort.h $(INC_DIR)testing_sort.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)testing_sort.o

unit_tests.exe : $(OBJ_DIR)check_main.o $(OBJ_DIR)check_cocktail_sort.o \
$(OBJ_DIR)check_radix_sort.o $(OBJ_DIR)check_bucket_sort.o $(OBJ_DIR)sort.o
	$(CC) $^ -lcheck -o unit_tests.exe

$(OBJ_DIR)check_main.o : $(UNIT_DIR)check_main.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_main.o

$(OBJ_DIR)check_cocktail_sort.o : $(UNIT_DIR)check_cocktail_sort.cpp $(INC_DIR)sort.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_cocktail_sort.o

$(OBJ_DIR)check_radix_sort.o : $(UNIT_DIR)check_radix_sort.cpp $(INC_DIR)sort.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_radix_sort.o

$(OBJ_DIR)check_bucket_sort.o : $(UNIT_DIR)check_bucket_sort.cpp $(INC_DIR)sort.h
	$(CC) $(CFLAGS) $< -c -o $(OBJ_DIR)check_bucket_sort.o

unit : unit_tests.exe
	./unit_tests.exe

run : app.exe
	./app.exe

clean :
	rm -f app.exe
	rm -f unit_tests.exe
	rm -rf $(OBJ_DIR)
