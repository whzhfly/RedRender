#pragma once

#include "entity.h"
#include <memory>
#include <vector>
#include "light.h"
#include "camera.h"
#include "../render_system/render_data.h"
#include "../resource/cache_resource.h"

typedef std::vector<GameEntity*> sceneRenderEntities;
typedef std::vector<GameEntity*> visibleEntities;



class RenderSpaceData{
public:

	// render light
	float ambient_intensity;
	float punctual_intensity;

	// light
	AmbientLight      m_ambient_light;
	PDirectionalLight m_directional_light;
	// PointLightList    m_point_light_list;

	RenderCamera*  m_camera; // only one camera for present
	RenderContext* m_render_context;

	// render entities
	sceneRenderEntities m_render_entities;
	visibleEntities m_visible_entities;

	// visible objects (updated per frame)
	void init_scene_data();
	void create_entity_by_model(ModelResource& model_resource);
	void render_space_draw_model(std::shared_ptr<PerFrame>);
	void update_visible_objects(std::shared_ptr<PerFrame> frame);

};

