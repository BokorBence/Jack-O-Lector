#include "scene.hpp"

Scene::~Scene()
{

}

Scene::Scene()
{
	renderer = NULL;
	needs_to_be_popped = false;
	push_over_me = NULL;
}