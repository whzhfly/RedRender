#include <iostream>
#include <cstdlib>

#include "render_system/render_system.h"




void ReleaseScene() {};

bool CheckWindowExist(){
	return true;
};


void GameStart(){


	// Load Scene
	RenderSystem* r_system = new RenderSystem();
	// create world data
	r_system->Init();

	while (CheckWindowExist())
	{
		r_system->RenderTick();
	}
};

int main(int argc, char** argv) {

	// args parse
	// todo

	GameStart();

	// release
}
















