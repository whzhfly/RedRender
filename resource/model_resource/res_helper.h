#pragma once
/*
    引用外部的math库
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "../../math/math.h"
#define LINE_SIZE 256


/* misc functions */

static const char *private_get_extension(const char *filename) {
    const char *dot_pos = strrchr(filename, '.');
    return dot_pos == NULL ? "" : dot_pos + 1;
};
