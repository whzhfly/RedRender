#include "common_helper.h"

typedef struct {
    int index;
    vec4_t basecolor_factor;
    float metalness_factor;
    float roughness_factor;
    char base_color_map[LINE_SIZE];
    char metalness_map[LINE_SIZE];
    char roughness_map[LINE_SIZE];
    char normal_map[LINE_SIZE];
    char occlusion_map[LINE_SIZE];
    char emission_map[LINE_SIZE];
    char double_sided[LINE_SIZE];
    char enable_blend[LINE_SIZE];
    float alpha_cutoff;
} ProtoModelMaterial;




static ProtoModelMaterial read_pbrm_material(FILE *file) {
    ProtoModelMaterial material;
    int items;

    items = fscanf(file, " material %d:", &material.index);
    assert(items == 1);
    items = fscanf(file, " basecolor_factor: %f %f %f %f",
                   &material.basecolor_factor.x,
                   &material.basecolor_factor.y,
                   &material.basecolor_factor.z,
                   &material.basecolor_factor.w);
    assert(items == 4);
    items = fscanf(file, " metalness_factor: %f", &material.metalness_factor);
    assert(items == 1);
    items = fscanf(file, " roughness_factor: %f", &material.roughness_factor);
    assert(items == 1);
    items = fscanf(file, " base_color_map: %s", material.base_color_map);
    assert(items == 1);
    items = fscanf(file, " metalness_map: %s", material.metalness_map);
    assert(items == 1);
    items = fscanf(file, " roughness_map: %s", material.roughness_map);
    assert(items == 1);
    items = fscanf(file, " normal_map: %s", material.normal_map);
    assert(items == 1);
    items = fscanf(file, " occlusion_map: %s", material.occlusion_map);
    assert(items == 1);
    items = fscanf(file, " emission_map: %s", material.emission_map);
    assert(items == 1);
    items = fscanf(file, " double_sided: %s", material.double_sided);
    assert(items == 1);
    items = fscanf(file, " enable_blend: %s", material.enable_blend);
    assert(items == 1);
    items = fscanf(file, " alpha_cutoff: %f", &material.alpha_cutoff);
    assert(items == 1);

    UNUSED_VAR(items);
    return material;
}


static void scene_read_pbrm_materials(FILE *file, std::vector<ProtoModelMaterial> & materials) {
    ProtoModelMaterial *materials = NULL;
    int num_materials;
    int items;
    int i;

    items = fscanf(file, " materials %d:", &num_materials);
    assert(items == 1);
    UNUSED_VAR(items);
    for (i = 0; i < num_materials; i++) {
        ProtoModelMaterial material = read_pbrm_material(file);
        assert(material.index == i);
        materials.push_back(material);
    }
}


class MaterialProtoDataHandel{
public:
    std::vector<ProtoModelMaterial> proto_materials;
    MaterialProtoDataHandel(FILE *file, const char* scene_type);
};



MaterialProtoDataHandel::MaterialProtoDataHandel(FILE *file, const char* scene_type){
    scene_read_pbrm_materials(file, proto_materials);
}
