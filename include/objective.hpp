#include "entity.hpp"

class Objective : public Entity {

private:
	bool _finished;
public:
	bool get_finished() { return _finished; }

};