
#include "common_helper.h"





typedef struct {
    int index;
    mat4_t matrix;
} ProtoModelTransform;



static ProtoModelTransform read_transform(FILE *file) {
    ProtoModelTransform transform;
    int items;
    int i;

    items = fscanf(file, " transform %d:", &transform.index);
    assert(items == 1);
    for (i = 0; i < 4; i++) {
        items = fscanf(file, " %f %f %f %f",
                       &transform.matrix.m[i][0],
                       &transform.matrix.m[i][1],
                       &transform.matrix.m[i][2],
                       &transform.matrix.m[i][3]);
        assert(items == 4);
    }

    UNUSED_VAR(items);
    return transform;
}

static ProtoModelTransform *read_transforms(FILE *file, std::vector<ProtoModelTransform> & trs) {
    ProtoModelTransform *transforms = NULL;
    int num_transforms;
    int items;
    int i;

    items = fscanf(file, " transforms %d:", &num_transforms);
    assert(items == 1);
    UNUSED_VAR(items);
    for (i = 0; i < num_transforms; i++) {
        ProtoModelTransform transform = read_transform(file);
        assert(transform.index == i);
        trs.push_back(transform);
    }
    return transforms;
}



class TransformProtoDataHandel{
public:
    std::vector<ProtoModelTransform> transforms;
    TransformProtoDataHandel(FILE *file);
};



TransformProtoDataHandel::TransformProtoDataHandel(FILE *file){
    read_transforms(file, transforms);
}
