#pragma once


class Entity {

	private:
		int x;
		int y;
		int d;

	public:
		int get_x(){ return x; }
		int get_y(){ return y; }
		int get_d() { return d; }
		void set_x(int _x) { x = _x; }
		void set_y(int _y) { y = _y; }
		int set_d(int _d) { 
			if (d < 0 || d > 15)
				return -1;
			else
				d = _d;
			return 0; 
		}

		Entity(int _x, int _y);
		Entity(int _x, int _y, int _d);
};