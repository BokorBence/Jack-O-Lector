#pragma once
#include <iostream>

class Tile {

private:
	std::string _path;
	
public:
	Tile() { _path = ""; }
	Tile(std::string path_) { _path = path_; }
	std::string get_path() const { return _path; } 
	void set_path(std::string path_) { _path = path_; }
	~Tile() { }
};