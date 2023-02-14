
#ifndef __RENDER_DATA_H__
#define __RENDER_DATA_H__
#include <vector>
#include <memory>
#include "../math/math.h"
#include "../game/camera.h"
// https://stackoverflow.com/questions/6554492/error-class-has-not-been-declared-despite-header-inclusion-and-the-code-compil


// move to buffers
class FrameBuffer2D{
public:
	int width, height;
	uint8_t *color_buffer;
	float *depth_buffer;
	FrameBuffer2D(int m_width, int m_height);
	void frame_buffer_clear_color();
	void frame_buffer_clear_depth();
};

// render system data
class RenderContext{
public:
	RenderContext(){
		int width = 1000, height = 800;
		m_frame_buffer = std::make_shared<FrameBuffer2D>(width, height);
	};
	// simple t
	std::shared_ptr<FrameBuffer2D> m_frame_buffer;
	RenderCamera* m_camera;

	// light
	Vector3 m_light_dir;
	Vector2 m_click_pos;


	// config
	int single_click;
	int double_click;
	float frame_time;
	float delta_time;
};

class PerFrame{
public:
	float frame_time;
	float delta_time;
	Vector3 light_dir;
	Vector3 camera_pos;
	Matrix4x4 light_view_matrix;
	Matrix4x4 light_proj_matrix;
	Matrix4x4 camera_view_matrix;
	Matrix4x4 camera_proj_matrix;
	float ambient_intensity;
	float punctual_intensity;
	void *shadow_map; // texture_t 类型
	int layer_view;

	PerFrame(RenderContext* render_context, void* m_scene);
};





#endif //__SCENE_H__
