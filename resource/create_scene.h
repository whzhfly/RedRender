#pragma once

#include "scene_proto.h"
#include "model_resource/mesh.h"
#include "model_resource/skeleton.h"
#include "model_resource/texture.h"
#include "cache_resource.h"





void create_scene(const char * file){
    // create_pbrm_scene 函数
    // create_scene 函数
    // scene_create 函数
    SceneResource& scene_store_resource = resource_manager->create_new_scene(file);
    // 获取场景原型
    // read models
    SceneProtoData* proto_scene = new SceneProtoData(file);


    int num_models = proto_scene->p_models->proto_models.size();
    for (int i = 0; i < num_models; i++) {
        ModelResource&  model_store_resource = resource_manager->create_new_model(scene_store_resource);

        ProtoModel& p_model = proto_scene->p_models->proto_models[i];

        // create mesh skeleton  and store
        RawMesh* mesh = new RawMesh();
        create_model_mesh(p_model.mesh, *mesh);
        model_store_resource.mesh = mesh;

        // create skeleton  and store
        model_store_resource.skeleton = create_model_skeleton(p_model.skeleton);

        // create transform and store
        int t_index = p_model.transform_index;
        ProtoModelTransform& t_transform = proto_scene->p_transforms->transforms[t_index];
        model_store_resource.transform = t_transform.matrix;

        // get material name
        // 这里的material 只是文件名字 还需要具体的导出image 信息
        int m_index = p_model.material_index;
        ProtoModelMaterial& m_material = proto_scene->p_materials->proto_materials[m_index];
        create_and_store_model_material(m_material, model_store_resource);

    }
}

void create_model_mesh(char* model_file, RawMesh& mesh){
    load_obj_to_mesh(model_file, mesh);
}

skeleton_t* create_model_skeleton(char* _file){
    return skeleton_load(_file);
}


void create_and_store_model_material(ProtoModelMaterial& m_material,  ModelResource& model_resource){
    model_resource.material.normal_map = texture_from_file(m_material.base_color_map, USAGE_LDR_DATA);
    model_resource.material.occlusion_map = texture_from_file(m_material.base_color_map, USAGE_LDR_DATA);
    //  color
    model_resource.material.basecolor_map = texture_from_file(m_material.base_color_map, USAGE_HDR_COLOR);
};


