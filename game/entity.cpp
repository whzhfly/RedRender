#include "entity.h"
#include "space.h"






/**
 * EntityManager
*/



EntityManager* entity_manager = nullptr;

GameEntity* EntityManager::create_entity(){
	GameEntity * en =  new GameEntity();
	entities.push_back(*en);
	return en;
};





/**
 * GameEntity
*/


void GameEntity::init_resource(ModelResource & model_resource){
	m_model = new PbrRenderModel(model_resource);
};

bool GameEntity::render_visible(){
	return true;
}
