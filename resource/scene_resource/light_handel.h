#include "common_helper.h"

typedef struct {
    vec3_t background;
    char environment[LINE_SIZE];
    char skybox[LINE_SIZE];
    char shadow[LINE_SIZE];
    float ambient;
    float punctual;
} scene_light_t;



static scene_light_t read_light(FILE *file) {
    scene_light_t light;
    char header[LINE_SIZE];
    int items;

    items = fscanf(file, " %s", header);
    assert(equals_to(header, "lighting:"));
    items = fscanf(file, " background: %f %f %f",
                   &light.background.x,
                   &light.background.y,
                   &light.background.z);
    assert(items == 3);
    items = fscanf(file, " environment: %s", light.environment);
    assert(items == 1);
    items = fscanf(file, " skybox: %s", light.skybox);
    assert(items == 1);
    items = fscanf(file, " shadow: %s", light.shadow);
    assert(items == 1);
    items = fscanf(file, " ambient: %f", &light.ambient);
    assert(items == 1);
    items = fscanf(file, " punctual: %f", &light.punctual);
    assert(items == 1);
    // 消除编译器警告 void(xx)
    UNUSED_VAR(items); // 转化为空类型 (void)0的作用相当于函数返回类型为void限定，它仅是一个占位符表达式，什么都不做。
    return light;
}






class LightProtoData{
public:
    LightProtoData(FILE *file);
};



LightProtoData::LightProtoData(FILE *file){
    read_light(file);
}
