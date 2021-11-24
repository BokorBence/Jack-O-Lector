#pragma once


class Entity {

	protected:
		int x;
		int y;
		int d; //0 - down, 1 - right, 2 - up, 3 - left

	public:
		int get_x() const { return x; }
		int get_y() const { return y; }
		int get_d() const { return d; }
		void set_x(int _x) { x = _x; }
		void set_y(int _y) { y = _y; }
		int set_d(int _d) { 
			if (d < 0 || d > 15)
				return -1;
			else
				d = _d;
			return 0; 
		}

		Entity();
		~Entity() { }
		Entity(int _x, int _y);
		Entity(int _x, int _y, int _d);
};