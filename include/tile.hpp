#pragma once
#include <iostream>

class Tile {

private:
	std::string _path;
	int tile_type;
	
public:
	Tile() { _path = ""; tile_type = 100; }
	Tile(std::string path_, int type) { _path = path_; tile_type = type; }
	std::string get_path() const { return _path; } 
	void set_path(std::string path_) { _path = path_; }
	int get_type() const { return tile_type; }
	~Tile() { }
};