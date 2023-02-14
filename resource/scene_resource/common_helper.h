#ifndef __COMMON_HELPER_H__
#define __COMMON_HELPER_H__
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "../math/math.h"

#define LINE_SIZE 256

#define UNUSED_VAR(x) ((void)(x))
#define EPSILON 1e-5f
#define PI 3.1415927f

typedef const char * CFileName;


static int equals_to(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}


typedef enum{
    blinn,
    pbrm,
    pbrs,
}SceneProtoDataType;

SceneProtoDataType m_scene_type = SceneProtoDataType(pbrm);

#endif //__COMMON_HELPER_H__
