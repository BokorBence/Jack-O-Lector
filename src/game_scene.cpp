#include "game_scene.hpp"

Game_scene::Game_scene(SDL_Renderer* r, Scene* next_scene)
{
	next = next_scene;
	renderer = r;
	jack_rect = { 10,10, w, h };
	g_logic = new Game(1);
	jack_sur = IMG_Load("resources/jack_stand.png");
	jack_tex = SDL_CreateTextureFromSurface(renderer, jack_sur);
	surfs[0] = IMG_Load("resources/prototile.png");
	surfs[1] = IMG_Load("resources/grassup.png");
	surfs[2] = IMG_Load("resources/grassdown.png");
	surfs[3] = IMG_Load("resources/grassright.png");
	surfs[4] = IMG_Load("resources/grassleft.png");
	surfs[5] = IMG_Load("resources/grassupright.png");
	surfs[6] = IMG_Load("resources/grassdownleft.png");
	surfs[7] = IMG_Load("resources/grassupleft.png");
	surfs[8] = IMG_Load("resources/grassdownright.png");
	surfs[9] = IMG_Load("resources/grassrightup.png");
	surfs[10] = IMG_Load("resources/grassleftdown.png");
	surfs[11] = IMG_Load("resources/grassleftup.png");
	surfs[12] = IMG_Load("resources/grassrightdown.png");
	surfs[13] = IMG_Load("resources/grass.png");
	int k = sizeof(surfs) / sizeof(surfs[0]);
	for (int i = 0; i < k; ++i) {
		texts[i] = SDL_CreateTextureFromSurface(renderer, surfs[i]);
	}
}


Game_scene::~Game_scene()
{
	if (g_logic != NULL)
	{
		delete g_logic;
	}

}

void Game_scene::init_level(int level_number)
{
	if (level_number > 3 || level_number < 1)
	{
		return;
	}

	switch (level_number)
	{
	case 1: break;
	case 2: break;
	case 3: break;
	}
}


void Game_scene::draw_scene()
{
	jack_rect = { 10,10, w, h };
	SDL_RenderCopy(renderer, jack_tex, NULL, &jack_rect);
	for (int i = 0; i < 38; ++i) {
		for (int j = 0; j < 50; ++j) {
			rectest = {j*16,i*16,16,16};
			switch (g_logic->_level->_tile_matrix[i][j]->get_type()) {
				case 100:
					SDL_RenderCopy(renderer, texts[0], NULL, &rectest);
					break;
				case 101:
					SDL_RenderCopy(renderer, texts[1], NULL, &rectest);
					break;
				case 102:
					SDL_RenderCopy(renderer, texts[2], NULL, &rectest);
					break;
				case 103:
					SDL_RenderCopy(renderer, texts[3], NULL, &rectest);
					break;
				case 104:
					SDL_RenderCopy(renderer, texts[4], NULL, &rectest);
					break;
				case 105:
					SDL_RenderCopy(renderer, texts[5], NULL, &rectest);
					break;
				case 106:
					SDL_RenderCopy(renderer, texts[6], NULL, &rectest);
					break;
				case 107:
					SDL_RenderCopy(renderer, texts[7], NULL, &rectest);
					break;
				case 108:
					SDL_RenderCopy(renderer, texts[8], NULL, &rectest);
					break;
				case 109:
					SDL_RenderCopy(renderer, texts[9], NULL, &rectest);
					break;
				case 110:
					SDL_RenderCopy(renderer, texts[10], NULL, &rectest);
					break;
				case 111:
					SDL_RenderCopy(renderer, texts[11], NULL, &rectest);
					break;
				case 112:
					SDL_RenderCopy(renderer, texts[12], NULL, &rectest);
					break;
				case 113:
					SDL_RenderCopy(renderer, texts[13], NULL, &rectest);
					break;
				default:
					break;
			}
		}
	}
	
}


void Game_scene::handle_events(const SDL_Event &ev)
{

}

