#include "../input/model.h"
#include "../input/entity.h"
#include <vector>
#include "light.h"
#include "camera.h"
#include "texture.h"
#include "render_helper.h"

using namespace std;

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;


// move to buffers
class FrameBuffer{
	int width, height;
	uint8_t *color_buffer;
	float *depth_buffer;
};


typedef std::vector<Entity*> sceneRenderEntities;



// control render data
class RenderContext{
public:
	FrameBuffer *m_frame_buffer;
	RenderCamera *m_camera;
	Vec3f m_light_dir;
	Vec2f m_click_pos;
	int single_click;
	int double_click;
	float frame_time;
	float delta_time;
};

class RenderSceneData{
public:
	// light
	AmbientLight      m_ambient_light;
	PDirectionalLight m_directional_light;
	// PointLightList    m_point_light_list;

	// render entities
	sceneRenderEntities m_render_entities;
	RenderCamera* camera; // only one camera for present
	RenderContext* m_render_context;

	// visible objects (updated per frame)

	void InitSceneData();
	void RenderSceneTick();
	void RenderSceneDraw();
	void UpdateVisibleObjects();

};


class PerFrame{
public:
	float frame_time;
	float delta_time;
	Vec3f light_dir;
	Vec3f camera_pos;
	Matrix light_view_matrix;
	Matrix light_proj_matrix;
	Matrix camera_view_matrix;
	Matrix camera_proj_matrix;
	float ambient_intensity;
	float punctual_intensity;
	texture_t *shadow_map;
	int layer_view;

	PerFrame(RenderSceneData* m_scene, RenderContext* render_context){};
};
