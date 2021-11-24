#include "../include/level_1.hpp"

Level_1::Level_1(std::string path)
{

	std::ifstream read_file;
	read_file.open(path);

if (read_file.is_open()) {
		int data;
		int i = 0;
		int j = 0;
		while (read_file) {
			data = read_file.get();
			if (data == ' ') {
				j++;
			}
			else if (data == '\n')
			{
				j = 0;
				i++;
			}
			else {
				int value = data - 48;
				switch (value)
				{
				case 0:
					_tile_matrix[i][j] = new Tile("background");
					//std::cerr << "B" << std::endl;
					break;
				case 1:
					_tile_matrix[i][j] = new Tile("wall");
					//std::cerr << "W" << std::endl;
					break;
				case 2:
					_tile_matrix[i][j] = new Tile("tree/bush");
					//std::cerr << "F" << std::endl;
					break;
				case 3:
					_tile_matrix[i][j] = new Tile("grave");
					//std::cerr << "G" << std::endl;
					break;
				case 4:
					_tile_matrix[i][j] = new Tile("objective");
					//std::cerr << "O" << std::endl;
					break;
				default:
					break;
				}
			}
		}
	}
	
	read_file.close();

	jack = new walkingEntity(3, 2, 0);
	_objective = false;
	guards[0] = new Guard(5, 5, 1, true, 4);
	guards[1] = new Guard(12, 6, 0, false, 5);
	guards[2] = new Guard(14, 2, 1, true, 8);

}

Level_1::~Level_1() {

	for (int i = 0;i < 38;++i)
	{
		for (int j = 0; j < 50;++j)
		{
			delete _tile_matrix[i][j];
		}
	}

	delete guards[0];
	delete guards[1];
	delete guards[2];
	delete jack;

}