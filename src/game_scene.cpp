#include "game_scene.hpp"

Game_scene::Game_scene(SDL_Renderer* r, Scene* win_scene, Scene* lose_scene)
{
	win = win_scene;
	lose = lose_scene;
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
	surfs[37] = IMG_Load("resources/whole.png");
	surfs[38] = IMG_Load("resources/jackbagright.png");
	surfs[39] = IMG_Load("resources/jackleft.png");
	surfs[40] = IMG_Load("resources/jackbagleft.png");
	surfs[41] = IMG_Load("resources/jackback.png");
	surfs[42] = IMG_Load("resources/jackbagblack.png");

	guard_surfs[0] = IMG_Load("resources/downrightguard.png");
	guard_surfs[1] = IMG_Load("resources/downleftguard.png");
	guard_surfs[2] = IMG_Load("resources/uprightguard.png");
	guard_surfs[3] = IMG_Load("resources/upleftguard.png");

	int k = sizeof(surfs) / sizeof(surfs[0]);
	for (int i = 0; i < k; ++i) {
		texts[i] = SDL_CreateTextureFromSurface(renderer, surfs[i]);
	}

	for (int i = 0; i < 4; ++i) {
		guard_texts[i] = SDL_CreateTextureFromSurface(renderer, guard_surfs[i]);
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
	g_logic->gameStep();
	for (int i = 0; i < 38; ++i) {
		for (int j = 0; j < 50; ++j) {
			rectest = { j * 16,i * 16,16,16 };
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
				if (!g_logic->get_objective()) { SDL_RenderCopy(renderer, texts[21], NULL, &rectest); }
				else { SDL_RenderCopy(renderer, texts[37], NULL, &rectest); }
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
	jack_rect = { g_logic->get_jack_x(),g_logic->get_jack_y(), w, h };
	if (!g_logic->get_objective()) {
		if(g_logic->get_jack_d() == 1 || g_logic->get_jack_d() == 0)
			SDL_RenderCopy(renderer, jack_tex, NULL, &jack_rect);
		if(g_logic->get_jack_d() == 2)
			SDL_RenderCopy(renderer, texts[41], NULL, &jack_rect);
		if (g_logic->get_jack_d() == 3)
			SDL_RenderCopy(renderer, texts[39], NULL, &jack_rect);
	}
	else 
	{ 
		if (g_logic->get_jack_d() == 1 || g_logic->get_jack_d() == 0)
			SDL_RenderCopy(renderer, texts[38], NULL, &jack_rect);
		if (g_logic->get_jack_d() == 2)
			SDL_RenderCopy(renderer, texts[42], NULL, &jack_rect);
		if (g_logic->get_jack_d() == 3)
			SDL_RenderCopy(renderer, texts[40], NULL, &jack_rect);
	}
	

	for (int i = 0; i < g_logic->get_num_of_guards(); ++i) {

		if (g_logic->get_guard(i)->get_one_way()) {
			jack_rect = { g_logic->get_guard(i)->get_x(), g_logic->get_guard(i)->get_y(), w, h };
			SDL_RenderCopy(renderer, guard_texts[0], NULL, &jack_rect);
		}
		if (g_logic->get_guard(i)->get_horizontal() && !g_logic->get_guard(i)->get_one_way()) {
			jack_rect = { g_logic->get_guard(i)->get_x(), g_logic->get_guard(i)->get_y(), w, h };
			SDL_RenderCopy(renderer, guard_texts[1], NULL, &jack_rect);
		}
		if (!g_logic->get_guard(i)->get_horizontal() && !g_logic->get_guard(i)->get_one_way()) {
			jack_rect = { g_logic->get_guard(i)->get_x(), g_logic->get_guard(i)->get_y(), w, h };
			SDL_RenderCopy(renderer, guard_texts[2], NULL, &jack_rect);
		}
	}
}


void Game_scene::handle_events(const SDL_Event &ev)
{
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_w) {
		g_logic->keyBoardInput('w');
	}
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_a) {
		g_logic->keyBoardInput('a');
	}
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_s) {
		g_logic->keyBoardInput('s');
	}
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_d) {
		g_logic->keyBoardInput('d');
	}

	if (g_logic->get_game_over() && !g_logic->get_win())
	{
		push_over_me = lose;
	}

	if (g_logic->get_game_over() && g_logic->get_win())
	{
		push_over_me = win;
	}
}

