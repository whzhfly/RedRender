#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "light_handel.h"
#include "model_handel.h"
#include "material_handel.h"
#include "transform_handel.h"



class SceneProtoData{
public:
    SceneProtoDataType scene_type;
    LightProtoData* p_light;
    MaterialProtoDataHandel* p_materials;
    TransformProtoDataHandel* p_transforms;
    ModelProtoDataHandel* p_models;
    SceneProtoData(const char* file_name);
};

SceneProtoData::SceneProtoData(const char* file_name)
{
    char scene_type[LINE_SIZE];
    FILE *file;
    int items;

    file = fopen(file_name, "rb");
    assert(file != NULL);
    items = fscanf(file, " type: %s", scene_type);
    assert(items == 1);
    // UNUSED_VAR(items);
    SceneProtoData* scene;
    if (equals_to(scene_type, "blinn")) {
        // scene_light_t light = read_light(file);
        // scene_blinn_t *materials = read_blinn_materials(file);
        // ProtoModelTransform *transforms = read_transforms(file);
        // scene_model_t *models = read_models(file);
        // scene = create_blinn_scene(&light, materials, transforms, models, root);
        // darray_free(materials);
        // darray_free(transforms);
        // darray_free(models);
    } else if (equals_to(scene_type, "pbrm")) {
        p_light = new LightProtoData(file);
        p_materials = new MaterialProtoDataHandel(file, scene_type);
        p_transforms = new TransformProtoDataHandel(file);
        p_models = new ModelProtoDataHandel(file, scene_type);
    } else if (equals_to(scene_type, "pbrs")) {
        // scene_light_t light = read_light(file);
        // scene_pbrs_t *materials = read_pbrs_materials(file);
        // ProtoModelTransform *transforms = read_transforms(file);
        // scene_model_t *models = read_models(file);
        // scene = create_pbrs_scene(&light, materials, transforms, models, root);
        // darray_free(materials);
        // darray_free(transforms);
        // darray_free(models);
    } else {
        assert(0);
        scene = NULL;
    }
    fclose(file);
};

