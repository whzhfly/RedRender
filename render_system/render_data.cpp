
#include "render_data.h"
#include "../game/space.h"


FrameBuffer2D::	FrameBuffer2D(int m_width, int m_height): width(m_width), height(m_height){
		int color_buffer_size = m_width * m_height * 4;
		int depth_buffer_size = sizeof(float) * m_width * m_height;
		color_buffer = (unsigned char*)malloc(color_buffer_size);
		depth_buffer = (float*)malloc(depth_buffer_size);

		frame_buffer_clear_color();
		frame_buffer_clear_depth();
};

void FrameBuffer2D::frame_buffer_clear_color(){
	vec4_t default_color = {0, 0, 0, 1};
		int num_pixels = width * height;
		int i;
		for (i = 0; i < num_pixels; i++) {
			color_buffer[i * 4 + 0] = float_to_uchar(default_color.x);
			color_buffer[i * 4 + 1] = float_to_uchar(default_color.y);
			color_buffer[i * 4 + 2] = float_to_uchar(default_color.z);
			color_buffer[i * 4 + 3] = float_to_uchar(default_color.w);
		}
}


void FrameBuffer2D::frame_buffer_clear_depth(){
		float default_depth = 1;
		int num_pixels = width * height;
		int i;
		for (i = 0; i < num_pixels; i++) {
			depth_buffer[i] = default_depth;
		}
	};
PerFrame::PerFrame(RenderContext* render_context, void* m_scene)
{
	frame_time = render_context->frame_time;
	delta_time = render_context->delta_time;
	light_dir = render_context->m_light_dir;

	camera_pos = render_context->m_camera->get_camera_pos();

	// mpv 矩阵
	// light_view_matrix = 
	// light_proj_matrix
	// camera_view_matrix
	// camera_proj_matrix

	ambient_intensity = ((RenderSpaceData*)m_scene)->ambient_intensity;
	punctual_intensity =((RenderSpaceData*)m_scene)->punctual_intensity;

	// shadow_map = scene->shadow_map;
	layer_view = -1;
};



