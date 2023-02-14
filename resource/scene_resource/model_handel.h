#include "common_helper.h"

typedef struct {
    int index;
    char mesh[LINE_SIZE];
    char skeleton[LINE_SIZE];
    int attached_index;
    int material_index;
    int transform_index;
} ProtoModel;


static ProtoModel read_model(FILE *file) {
    ProtoModel model;
    int items;

    items = fscanf(file, " model %d:", &model.index);
    assert(items == 1);
    items = fscanf(file, " mesh: %s", model.mesh);
    assert(items == 1);
    items = fscanf(file, " skeleton: %s", model.skeleton);
    assert(items == 1);
    items = fscanf(file, " attached: %d", &model.attached_index);
    assert(items == 1);
    items = fscanf(file, " material: %d", &model.material_index);
    assert(items == 1);
    items = fscanf(file, " transform: %d", &model.transform_index);
    assert(items == 1);

    UNUSED_VAR(items);
    return model;
}


static void scene_read_model(FILE *file, std::vector<ProtoModel> & models) {
/*
    model 0:
        xx
        xx
    model 1:
        xx
        xx
*/
    ProtoModel *models = NULL;
    int num_models;
    int items;
    int i;

    items = fscanf(file, " models %d:", &num_models);
    assert(items == 1);
    UNUSED_VAR(items);
    for (i = 0; i < num_models; i++) {
        ProtoModel model = read_model(file);
        assert(model.index == i);
        models.push_back(model);
    }
}


class ModelProtoDataHandel{
public:
    std::vector<ProtoModel> proto_models;
    ModelProtoDataHandel(FILE *file, const char* scene_type);
};



ModelProtoDataHandel::ModelProtoDataHandel(FILE *file, const char* scene_type){
    scene_read_model(file, proto_models);
}
