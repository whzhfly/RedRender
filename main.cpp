#include <iostream>
#include <cstdlib>
#include "./render/scene.h"




RenderSceneData* m_scene = nullptr;

void LoadScene(const char *filename){
	ModelMesh* mesh = new ModelMesh(filename);
	RenderModel* model = new RenderModel(mesh);
	Entity* entity = new Entity(model);
	m_scene->m_render_entities.push_back(entity); // 后期可以加入entity相关功能 entity init model
};

void ReleaseScene() {};

bool CheckWindowExist(){
	return true;
};

void LogicTick(){

};

void RenderTick(){
	m_scene->RenderSceneTick();
};


int main(int argc, char** argv) {

	// args parse
	// todo
	// Load Scene
	LoadScene("Assert/african_head.obj");
	while (CheckWindowExist())
	{

		//time call

		// logic Tick
		LogicTick();

		// render Tick
		RenderTick();
	}

	// release
	ReleaseScene();
}
















