CXX = g++
CXXFLGS = -std=c++11 -W
ARGS = $(wildcard *.cc ./Concessionaria/*.cc ./Types/*.cc ./Problems/*.cc ./Staff/*.cc)
EXEC = concessionaria

compile:
	@$(CXX) $(CXXFLGS) $(ARGS) -o $(EXEC)
	@echo "do: make run NAME_CONCESSIONARIA=<name>"
run: compile
	@./$(EXEC) $(NAME_CONCESSIONARIA)
