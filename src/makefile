CXX = g++
CXXFLGS = -std=c++11 -W
ARGS = *.cc ./extConcessionaria/*.cc ./Types/*.cc
EXEC = concessionaria

compile:
	@$(CXX) $(CXXFLGS) $(ARGS) -o $(EXEC)
	@echo "run $(EXEC)"
run: compile
	@./$(EXEC)
