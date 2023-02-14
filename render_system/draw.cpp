#include "draw.h"

typedef struct {int min_x, min_y, max_x, max_y;} bbox_t;

// https://zhuanlan.zhihu.com/p/511098074
static int rasterize_triangle(std::shared_ptr<FrameBuffer2D> buffer, RenderProgram* program,
		vec4_t clip_coords[3], void *varying_s){
	int width = buffer.get()->width;
	int height = buffer.get()->height;

	// normalized Device coordinates
	Vector3 ndc_coords[3]; // normal
	Vector2 screen_coords[3];
	float screen_depths[3];
	float recip_w[3]; // reciprocals of w

	int back_face;
	bbox_t bbox; // 坐标的的binding box？
	int i, x, y;


	/* perspective division */


	/* back-face culling */


	/* reciprocals of w */


	/* viewport mapping */


	for (x = bbox.min_x; x <= bbox.max_x; x++) {
		for (y = bbox.min_y; y <= bbox.max_y; y++) {
			Vector3 weights;
			// Vec3f weights = barycentric();// 重心比例
			if (weights.x<0 || weights.y<0 || weights.z<0){
				float depth;
				int index = y * width + x;
				if (depth < buffer.get()->depth_buffer[index]){
					// 插值纹理
					// program.render_shader.get()->fragment();
				}
			}
		}
	}

};


void render_program_draw_triangle(RenderProgram* program, std::shared_ptr<FrameBuffer2D> buffer){
	int num_vertices;
	// int is_culled = rasterize_triangle(framebuffer, program, clip_coords, varyings);
	// if (is_culled) {
	// 	break;
	// }
	/* triangle assembly */
	for (int i = 0; i < num_vertices - 2; i++) {
		int index0 = 0;
		int index1 = i + 1;
		int index2 = i + 2;
		vec4_t clip_coords[3];
		void *varying_s[3];
		int is_culled;

		// clip_coords[0] = program->out_coords[index0];
		// clip_coords[1] = program->out_coords[index1];
		// clip_coords[2] = program->out_coords[index2];
		// varyings[0] = program->out_varyings[index0];
		// varyings[1] = program->out_varyings[index1];
		// varyings[2] = program->out_varyings[index2];

		is_culled = rasterize_triangle(buffer, program, clip_coords, varying_s);
		if (is_culled) {
			break;
		}
	}
};




