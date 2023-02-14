#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "model.h"
#include "../math/math.h"
#include "../resource/cache_resource.h"
#include "model.h"

// 对应的 GameEntity game_object
class GameEntity{
public:
	PbrRenderModel* m_model;
	bool render_visible();
	void init_resource(ModelResource &);
};

class EntityManager{
public:
	GameEntity* create_entity();
	std::vector<GameEntity> entities;
};



extern EntityManager* entity_manager;

#endif //__ENTITY_H__
