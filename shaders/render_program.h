#pragma once
#include <functional>
#include "../math/math.h"
#include <memory>
#include "../resource/cache_resource.h"
#include "shaders.h"

#define MAX_VARYINGS 10

// 通过Uniform Buffer将MVP矩阵传递到顶点着色器，实现将模型从模型空间到屏幕空间
// 基本就是把 scene 的所有东西 保存到这个uniform上
// 后续的pipeline 就不用管scene 只需要model + program 即可
// pbr_uniforms_t

/*
uniform buffer
用来定义和传递渲染过程中的一些常量数据，例如：坐标系变换矩阵数据、光照参数以及其他自定义常量数据。
Metal中通过一个专门的MTLBuffer来保存和传递这些常量数据，这个buffer就成为Uniform Buffer，
buffer中的数据通过一个结构体来定义和组织。

看下参数信息
model 0:
	mesh: dieselpunk/ground.obj
	skeleton: null
	attached: -1
	material: 0
	transform: 0
material 0:
	basecolor_factor: 1 1 1 1
	metalness_factor: 0
	roughness_factor: 1
	basecolor_map: dieselpunk/ground_basecolor.tga
	metalness_map: null
	roughness_map: dieselpunk/ground_roughness.tga
	normal_map: null
	occlusion_map: null
	emission_map: null
	double_sided: on
	enable_blend: on
	alpha_cutoff: 0
*/

struct uniform_context{
	Vector3 light_dir;
	Vector3 camera_pos;

	Vector4 basecolor_factor;
	float metalness_factor;
	float roughness_factor;

	Matrix4x4 model_matrix;
	Matrix4x4 camera_vp_matrix;
	float ambient_intensity;
	float punctual_intensity;
	 /* metalness workflow */
	/* specular workflow */
	/* additional maps */
	/* render controls */
};



// model 的辅助信息
class RenderProgram{
public:
	// base vertex and fragment
	std::shared_ptr<IShader> render_shader; // qiu vertex 信息
	/* for shaders */
	// varyings uniform attribs 3种
	std::shared_ptr<uniform_context> render_uniform_context;
	/* for clipping */ 
	// 裁切种类
	RenderProgram(ModelResource& source);

};


