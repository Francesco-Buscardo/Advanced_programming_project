CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
SRC = $(wildcard *.cc ./Departments/*.cc ./Types/*.cc ./Problems/*.cc ./Staff/*.cc ./Customer/*.cc)
OBJ = $(SRC:.cc=.o)
EXEC = concessionaria

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

compile: all
	@echo "Build completed."

run: all
	@./$(EXEC) $(NAME_CONCESSIONARIA)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC) $(NAME_CONCESSIONARIA)
