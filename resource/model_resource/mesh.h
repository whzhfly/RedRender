#include "res_helper.h"



#ifndef MESH_H
#define MESH_H

typedef struct {
    vec3_t position;
    vec2_t tex_coord;
    vec3_t normal; // 法向切线
    vec4_t tangent; // 定点的切线方向
    vec4_t joint;
    vec4_t weight;
} vertex_t;

struct raw_obj_t{
    // base
    std::vector<vec3_t> positions;
    std::vector<vec2_t> tex_coords;
    std::vector<vec3_t> normals;
    // animation
    std::vector<vec4_t> tangents;
    std::vector<vec4_t> joints;
    std::vector<vec4_t> weights;
    // indices
    std::vector<int> position_indices;
    std::vector<int> tex_coord_indices;
    std::vector<int> normal_indices;
};

class RawMesh {
public:
    int num_faces;
    std::vector<vertex_t> vertex_s;
    vec3_t center;
};



void build_mesh(raw_obj_t & raw_obj, RawMesh & mesh) {
    vec3_t bbox_min = vec3_new(+1e6, +1e6, +1e6);
    vec3_t bbox_max = vec3_new(-1e6, -1e6, -1e6);
    int num_indices = raw_obj.position_indices.size();
    int num_faces = num_indices / 3;

    std::vector<vertex_t>& vertices = mesh.vertex_s;

    assert(num_faces > 0 && num_faces * 3 == num_indices);
    assert(raw_obj.position_indices.size() == num_indices);
    assert(raw_obj.tex_coord_indices.size() == num_indices);
    assert(raw_obj.normal_indices.size() == num_indices);

    for (int i = 0; i < num_indices; i++) {
        int position_index = raw_obj.position_indices[i];
        int tex_coord_indices_index = raw_obj.tex_coord_indices[i];
        int normal_index = raw_obj.normal_indices[i];
        assert(position_index >= 0 && position_index < raw_obj.positions.size());
        assert(tex_coord_indices_index >= 0 && tex_coord_indices_index < raw_obj.tex_coord_indices.size());
        assert(normal_index >= 0 && normal_index < raw_obj.normals.size());

        // get right vertex data
        vertices[i].position = raw_obj.positions[position_index];
        vertices[i].tex_coord = raw_obj.tex_coords[tex_coord_indices_index];
        vertices[i].normal = raw_obj.normals[normal_index];

        // init tangents
        if (!raw_obj.tangents.empty()) {
            int tangent_index = position_index;
            assert(tangent_index >= 0 && tangent_index < raw_obj.tangents.size());
            vertices[i].tangent = raw_obj.tangents[tangent_index];
        } else {
            vertices[i].tangent = vec4_new(1, 0, 0, 1);
        }

        // inti joints
        if (!raw_obj.joints.empty()) {
            int joint_index = position_index;
            assert(joint_index >= 0 && joint_index < raw_obj.joints.size());
            vertices[i].joint = raw_obj.joints[joint_index];
        } else {
            vertices[i].joint = vec4_new(0, 0, 0, 0);
        }
        // inti weights
        if (!raw_obj.weights.empty()) {
            int weight_index = position_index;
            assert(weight_index >= 0 && weight_index < raw_obj.weights.size());
            vertices[i].weight = raw_obj.weights[weight_index];
        } else {
            vertices[i].weight = vec4_new(0, 0, 0, 0);
        }

        // find 找到模型的包围框
        bbox_min = vec3_min(bbox_min, vertices[i].position);
        bbox_max = vec3_max(bbox_max, vertices[i].position);
    }


    mesh.num_faces = num_faces;
    mesh.center = vec3_div(vec3_add(bbox_min, bbox_max), 2);
};

void load_obj_to_mesh(const char *filename, RawMesh& mesh) {

    // 判断 是否 obj 结尾
    // if (strcmp(filename, "obj") == 0) {
    //     return load_obj(filename);
    // } else {
    //     assert(0);
    //     return NULL;
    // }

    // base
    raw_obj_t raw_obj;
    char line[LINE_SIZE];
    FILE *file;

    file = fopen(filename, "rb");
    assert(file != NULL);
    while (1) {
        int items;
        if (fgets(line, LINE_SIZE, file) == NULL) {
            break;
        } else if (strncmp(line, "v ", 2) == 0) {               /* position */
            vec3_t position;
            items = sscanf(line, "v %f %f %f",
                        &position.x, &position.y, &position.z);
            assert(items == 3);
            raw_obj.positions.push_back(position);
        } else if (strncmp(line, "vt ", 3) == 0) {              /* tex_coord */
            vec2_t tex_coord;
            items = sscanf(line, "vt %f %f",
                        &tex_coord.x, &tex_coord.y);
            assert(items == 2);
            raw_obj.tex_coords.push_back(tex_coord);
        } else if (strncmp(line, "vn ", 3) == 0) {              /* normal */
            vec3_t normal;
            items = sscanf(line, "vn %f %f %f",
                        &normal.x, &normal.y, &normal.z);
            assert(items == 3);
            raw_obj.normals.push_back(normal);
        } else if (strncmp(line, "f ", 2) == 0) {               /* face */
            int i;
            int pos_indices[3], uv_indices[3], n_indices[3];
            items = sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d",
                        &pos_indices[0], &uv_indices[0], &n_indices[0],
                        &pos_indices[1], &uv_indices[1], &n_indices[1],
                        &pos_indices[2], &uv_indices[2], &n_indices[2]);
            assert(items == 9);
            for (i = 0; i < 3; i++) {
                raw_obj.position_indices.push_back(pos_indices[i] - 1);
                raw_obj.tex_coord_indices.push_back(uv_indices[i] - 1);
                raw_obj.normal_indices.push_back(n_indices[i] - 1);
            }
        } else if (strncmp(line, "# ext.tangent ", 14) == 0) {  /* tangent */
            vec4_t tangent;
            items = sscanf(line, "# ext.tangent %f %f %f %f",
                        &tangent.x, &tangent.y, &tangent.z, &tangent.w);
            assert(items == 4);
            raw_obj.tangents.push_back(tangent);
        } else if (strncmp(line, "# ext.joint ", 12) == 0) {    /* joint */
            vec4_t joint;
            items = sscanf(line, "# ext.joint %f %f %f %f",
                        &joint.x, &joint.y, &joint.z, &joint.w);
            assert(items == 4);
            raw_obj.joints.push_back(joint);
        } else if (strncmp(line, "# ext.weight ", 13) == 0) {   /* weight */
            vec4_t weight;
            items = sscanf(line, "# ext.weight %f %f %f %f",
                        &weight.x, &weight.y, &weight.z, &weight.w);
            assert(items == 4);
            raw_obj.weights.push_back(weight);
        }
    }
    build_mesh(raw_obj, mesh);
    // raw_obj 自动销毁
    fclose(file);

}


#endif
