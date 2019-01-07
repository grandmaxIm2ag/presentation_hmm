CC=g++
CFLAGS=-Wall -std=c++11
EXEC_NAME=main
INCLUDES =
LIBS=
SRC=$(wildcard src/*.cpp)
OBJ_FILES=$(SRC:.cpp=.o)
INSTALL_DIR=bin

all : $(EXEC_NAME)

clean :
	rm -rf $(EXEC_NAME) $(OBJ_FILES) $(INSTALL_DIR)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

install: $(EXEC_NAME)
	mkdir $(INSTALL_DIR)
	mv $(EXEC_NAME) $(INSTALL_DIR)
