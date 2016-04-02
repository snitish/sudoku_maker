#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

int gen_sudoku(std::vector<std::vector<int>>& puzzle)
{
	srand(time(NULL));
	int num_failures = 0;
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			std::set<int> avoid;
			for (int jp = 0; jp<j; jp++)
				avoid.insert(puzzle[i][jp]);
			for (int ip = 0; ip<i; ip++)
				avoid.insert(puzzle[ip][j]);
			int cube_st_i = 3*int(i/3);
			int cube_st_j = 3*int(j/3);
			for (int c = 0; c < 9; c++)
			{
				int cube_i = cube_st_i + c/3;
				int cube_j = cube_st_j + c%3;
				if (cube_i == i && cube_j == j)
					break;
				avoid.insert(puzzle[cube_i][cube_j]);
			}

			std::vector<int> allowed;
			for (int n = 1; n <= 9; n++)
			{
				if (avoid.find(n) == avoid.end())
					allowed.push_back(n);
			}
			if (allowed.size() == 0)
			{
				num_failures++;
				i = 0;
				j = 0;
				continue;
			}
			puzzle[i][j] = allowed[rand()%allowed.size()];
		}
	}

	return num_failures;
}

int main(int argc, char *argv[])
{
	// Generate puzzle
	std::vector<std::vector<int>> puzzle(9, std::vector<int>(9));
	int num_failures = gen_sudoku(puzzle);
	std::cout << "Number of failures: " << num_failures << std::endl;

	// Print puzzle
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
			std::cout << puzzle[i][j] << "  ";
		std::cout << std::endl << std::endl;
	}

	return 0;
}