#ifndef __MODEL_H__
#define __MODEL_H__
#include <vector>
#include <string>
#include "../math/geometry.h"
#include "image.h"








class ModelMesh {
private:
	std::vector<Vec3f> verts_;
	std::vector<std::vector<Vec3i> > faces_; // attention, this Vec3i means vertex/uv/normal
	std::vector<Vec3f> norms_;
	std::vector<Vec2f> uv_;
	TGAImage diffusemap_;
	TGAImage normalmap_;
	TGAImage specularmap_;
	void load_texture(std::string filename, const char *suffix, TGAImage &img);
public:
	ModelMesh(const char *filename);
	~ModelMesh();
	int nverts();
	int nfaces();
	Vec3f normal(int iface, int nthvert);
	Vec3f normal(Vec2f uv);
	Vec3f vert(int i);
	Vec3f vert(int iface, int nthvert);
	Vec2f uv(int iface, int nthvert);
	TGAColor diffuse(Vec2f uv);
	float specular(Vec2f uv);
	std::vector<int> face(int idx);

	bool RenderVisible(){return true;};
};
#endif //__MODEL_H__


class Program{};
class Skeleton{};
class AxisAlignedBox{
    public:
        AxisAlignedBox() {}
        AxisAlignedBox(const Vector3& center, const Vector3& half_extent);

        void merge(const Vector3& new_point);
        void update(const Vector3& center, const Vector3& half_extent);

        const Vector3& getCenter() const { return m_center; }
        const Vector3& getHalfExtent() const { return m_half_extent; }
        const Vector3& getMinCorner() const { return m_min_corner; }
        const Vector3& getMaxCorner() const { return m_max_corner; }

    private:
        Vector3 m_center {0,0,0};
        Vector3 m_half_extent {0,0,0};

        Vector3 m_min_corner {
            std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};
        Vector3 m_max_corner {
            -std::numeric_limits<float>::max(), -std::numeric_limits<float>::max(), -std::numeric_limits<float>::max()};
};

class RenderModel{
public:
	ModelMesh* m_mesh;
	Program *program;
	Matrix transform;
	AxisAlignedBox m_bounding_box;
	/* for animation */
    Skeleton *skeleton;
    int attached;
    /* for sorting */
    int opaque;
    float distance;
	int faceCnt;
	RenderModel(ModelMesh* mesh): m_mesh(mesh), faceCnt(m_mesh->nfaces()) {

	};

	virtual void ModelUpdate(){};
	virtual void ModelDraw(){};
	virtual void ModelRelease(){};
};