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
			if (data == "201\n201") {
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 201);
				i++;
				j = 0;
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 201);
				j++;
			}
			else
			if (data == "208\n201") {
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 208);
				i++;
				j = 0;
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 201);
				j++;
			}
			else
			if (data == "201\n207") {
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 201);
				i++;
				j = 0;
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 207);
				j++;
			}
			else
			if (data == "205\n201") {
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 205);
				i++;
				j = 0;
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 201);
				j++;
			}
			else
			if (data == "201\n204") {
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 201);
				i++;
				j = 0;
				_tile_matrix[i][j] = new Tile("resources/prototile.png", 204);
				j++;
			}
			else
			{
				int value = std::stoi(data);
				_tile_matrix[i][j] = new Tile("resources/prototile.png", value);
				j++;
			}
			
		}
	}

	read_file.close();

	_objective = false;

}

Level_1::Level_1(Level l, std::string path)
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
				_tile_matrix[i][j] = new Tile("resources/prototile.png", value);
				break;
			case 101:
				_tile_matrix[i][j] = new Tile("resources/grassup.png", value);
				break;
			case 102:
				_tile_matrix[i][j] = new Tile("resources/grassdown.png", value);
				break;
			case 103:
				_tile_matrix[i][j] = new Tile("resources/grassright.png", value);
				break;
			case 104:
				_tile_matrix[i][j] = new Tile("resources/grassleft.png", value);
				break;
			case 105:
				_tile_matrix[i][j] = new Tile("resources/grassupright.png", value);
				break;
			case 106:
				_tile_matrix[i][j] = new Tile("resources/grassdownleft.png", value);
				break;
			case 107:
				_tile_matrix[i][j] = new Tile("resources/grassupleft.png", value);
				break;
			case 108:
				_tile_matrix[i][j] = new Tile("resources/grassdownright.png", value);
				break;
			case 109:
				_tile_matrix[i][j] = new Tile("resources/grassleft.png", value);
				break;
			case 110:
				_tile_matrix[i][j] = new Tile("resources/prototile.png", value);
				break;
			case 111:
				_tile_matrix[i][j] = new Tile("resources/grassup.png", value);
				break;
			case 112:
				_tile_matrix[i][j] = new Tile("resources/grassdown.png", value);
				break;
			case 113:
				_tile_matrix[i][j] = new Tile("resources/grassright.png", value);
				break;
			default:
				_tile_matrix[i][j] = new Tile("resources/grassright.png", value);
				break;
			}
			j++;
			if (j == 50) {
				i++;
				j = 0;
			}
		}
	}
	for (int i = 0; i < 38; ++i) {
		for (int j = 0; j < 50; ++j) {
			std::cout << _tile_matrix[i][j]->get_type();
		}
	}

	read_file.close();


}

Level_1::~Level_1() {

	for (int i = 0;i < 38;++i)
	{
		for (int j = 0; j < 50;++j)
		{
			delete _tile_matrix[i][j];
		}
	}

	delete jack;

}