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
	surfs[14] = IMG_Load("resources/grave.png");
	surfs[15] = IMG_Load("resources/grave2.png");
	surfs[16] = IMG_Load("resources/grave3.png");
	surfs[17] = IMG_Load("resources/pinedown.png");
	surfs[18] = IMG_Load("resources/pinemid.png");
	surfs[19] = IMG_Load("resources/pineup.png");
	surfs[20] = IMG_Load("resources/bush.png");
	surfs[21] = IMG_Load("resources/objective.png");
	surfs[22] = IMG_Load("resources/horizontalwall.png");
	surfs[23] = IMG_Load("resources/verticalwall.png");
	surfs[24] = IMG_Load("resources/walldown.png");
	surfs[25] = IMG_Load("resources/wallup.png");
	surfs[26] = IMG_Load("resources/wallleft.png");
	surfs[27] = IMG_Load("resources/wallright.png");
	surfs[28] = IMG_Load("resources/wallupleft.png");
	surfs[29] = IMG_Load("resources/wallupright.png");
	surfs[30] = IMG_Load("resources/walldownleft.png");
	surfs[31] = IMG_Load("resources/walldownright.png");
	surfs[32] = IMG_Load("resources/wallendleft.png");
	surfs[33] = IMG_Load("resources/wallendright.png");
	surfs[34] = IMG_Load("resources/superwall.png");
	surfs[35] = IMG_Load("resources/longgrave1.png");
	surfs[36] = IMG_Load("resources/longgrave2.png");
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
				case 300:
					SDL_RenderCopy(renderer, texts[14], NULL, &rectest);
					break;
				case 301:
					SDL_RenderCopy(renderer, texts[15], NULL, &rectest);
					break;
				case 302:
					SDL_RenderCopy(renderer, texts[16], NULL, &rectest);
					break;
				case 303:
					SDL_RenderCopy(renderer, texts[35], NULL, &rectest);
					break;
				case 304:
					SDL_RenderCopy(renderer, texts[36], NULL, &rectest);
					break;
				case 400:
					SDL_RenderCopy(renderer, texts[17], NULL, &rectest);
					break;
				case 401:
					SDL_RenderCopy(renderer, texts[18], NULL, &rectest);
					break;
				case 402:
					SDL_RenderCopy(renderer, texts[19], NULL, &rectest);
					break;
				case 403:
					SDL_RenderCopy(renderer, texts[20], NULL, &rectest);
					break;
				case 500:
					SDL_RenderCopy(renderer, texts[21], NULL, &rectest);
					break;
				case 200:
					SDL_RenderCopy(renderer, texts[22], NULL, &rectest);
					break;
				case 201:
					SDL_RenderCopy(renderer, texts[23], NULL, &rectest);
					break;
				case 202:
					SDL_RenderCopy(renderer, texts[24], NULL, &rectest);
					break;
				case 203:
					SDL_RenderCopy(renderer, texts[25], NULL, &rectest);
					break;
				case 204:
					SDL_RenderCopy(renderer, texts[26], NULL, &rectest);
					break;
				case 205:
					SDL_RenderCopy(renderer, texts[27], NULL, &rectest);
					break;
				case 206:
					SDL_RenderCopy(renderer, texts[28], NULL, &rectest);
					break;
				case 207:
					SDL_RenderCopy(renderer, texts[29], NULL, &rectest);
					break;
				case 208:
					SDL_RenderCopy(renderer, texts[30], NULL, &rectest);
					break;
				case 209:
					SDL_RenderCopy(renderer, texts[31], NULL, &rectest);
					break;
				case 210:
					SDL_RenderCopy(renderer, texts[32], NULL, &rectest);
					break;
				case 211:
					SDL_RenderCopy(renderer, texts[33], NULL, &rectest);
					break;
				case 212:
					SDL_RenderCopy(renderer, texts[34], NULL, &rectest);
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

