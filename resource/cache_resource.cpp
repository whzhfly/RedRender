#include "cache_resource.h"


CacheResourceData *resource_manager = nullptr;

SceneResource* CacheResourceData::get_scene_resource(const char* filename){
	auto iter = scene_map.find(filename);
	if (iter == scene_map.end()){
		// error
	}
	return (*iter).second;
};

SceneResource& CacheResourceData::create_new_scene(const char* filename){
	SceneResource sc(filename);
	all_scene.push_back(sc);
	scene_map[filename] = &(all_scene.back());
	return all_scene.back();
}

ModelResource* CacheResourceData::get_model_resource(const char* filename){
	auto iter = model_map.find(filename);
	if (iter == model_map.end()){
		// error
	}
	return (*iter).second;
}; 

ModelResource& CacheResourceData::create_new_model(SceneResource& scene){
	ModelResource m;
	scene.scene_models.push_back(m);
	return scene.scene_models.back();
}

