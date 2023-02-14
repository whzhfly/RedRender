#pragma once

#include <map>
#include <string>
#include <memory>
#include <vector>
#include "../math/math.h"
#include "model_resource/texture.h"


class ModelMaterial{
public:
	// material
	Vector3 light_dir;
	Vector3 camera_pos;
	Matrix4x4 model_matrix;
	mat3_t normal_matrix;
	Matrix4x4 light_vp_matrix;
	Matrix4x4 camera_vp_matrix;
	Matrix4x4 *joint_matrices;
	mat3_t *joint_n_matrices;
	float ambient_intensity;
	float punctual_intensity;
	texture_t *shadow_map;
	/* metalness workflow */
	vec4_t basecolor_factor;
	float metalness_factor;
	float roughness_factor;
	texture_t *basecolor_map;
	texture_t *metalness_map;
	texture_t *roughness_map;
	/* specular workflow */
	vec4_t diffuse_factor;
	Vector3 specular_factor;
	float glossiness_factor;
	texture_t *diffuse_map;
	texture_t *specular_map;
	texture_t *glossiness_map;
	/* additional maps */
	texture_t *normal_map;
	texture_t *occlusion_map;
	texture_t *emission_map;
	// /* environment maps */
	// ibldata_t *ibldata;
	// /* render controls */
	// workflow_t workflow;
	float alpha_cutoff;
	int shadow_pass;
	int layer_view;
};

class ModelResource{
public:
	// mesh
	void* mesh; // RawMesh 格式
	void* skeleton;//
	Matrix4x4 transform;
	ModelMaterial material;
};


class SceneResource{
public:
	const char* scene_name;
	// skybox
	Vector4 background;
	 /* light intensity */
    float ambient_intensity;
    float punctual_intensity;
	 /* shadow mapping */
    framebuffer_t *shadow_buffer;
    texture_t *shadow_map;

	SceneResource(const char* _file) : scene_name(_file) {};
	std::vector<ModelResource> scene_models;
};


class CacheResourceData{
public:
	std::vector<SceneResource> all_scene;
	std::map<std::string, SceneResource*> scene_map;
	std::map<std::string, ModelResource*> model_map;

	SceneResource* get_scene_resource(const char* filename);
	ModelResource* get_model_resource(const char* filename);

	SceneResource& create_new_scene(const char* filename);
	ModelResource& create_new_model(SceneResource& scene);
};



extern CacheResourceData *resource_manager;





