#include "../include/level_1.hpp"

Level_1::Level_1(std::string path)
{

	std::fstream read_file;
	read_file.open(path);

	if (read_file.is_open())
	{
		int i = 0;
		int j = 0;
		for (std::string data; std::getline(read_file, data, ' '); )
		{
			std::cout << data;
			int value = std::stoi(data);
			switch (value)
			{
			case 100:
				_tile_matrix[i][j] = new Tile("resources/prototile.png");
				break;
			case 101:
				_tile_matrix[i][j] = new Tile("resources/grassup.png");
				break;
			case 102:
				_tile_matrix[i][j] = new Tile("resources/grassdown.png");
				break;
			case 103:
				_tile_matrix[i][j] = new Tile("resources/grassright.png");
				break;
			case 104:
				_tile_matrix[i][j] = new Tile("resources/grassleft.png");
				break;
			case 105:
				_tile_matrix[i][j] = new Tile("resources/prototile.png");
				break;
			case 106:
				_tile_matrix[i][j] = new Tile("resources/grassup.png");
				break;
			case 107:
				_tile_matrix[i][j] = new Tile("resources/grassdown.png");
				break;
			case 108:
				_tile_matrix[i][j] = new Tile("resources/grassright.png");
				break;
			case 109:
				_tile_matrix[i][j] = new Tile("resources/grassleft.png");
				break;
			case 110:
				_tile_matrix[i][j] = new Tile("resources/prototile.png");
				break;
			case 111:
				_tile_matrix[i][j] = new Tile("resources/grassup.png");
				break;
			case 112:
				_tile_matrix[i][j] = new Tile("resources/grassdown.png");
				break;
			case 113:
				_tile_matrix[i][j] = new Tile("resources/grassright.png");
				break;
			default:
				break;
			}
			j++;
			if (j == 50) {
				i++;
				j = 0;
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