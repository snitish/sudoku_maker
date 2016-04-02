CXX ?= g++
CXXFLAGS = -std=c++11

gen_sudoku: gen_sudoku.cpp
	$(CXX) $(CXXFLAGS) -o gen_sudoku gen_sudoku.cpp