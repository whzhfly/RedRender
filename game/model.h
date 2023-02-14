#ifndef __MODEL_H__
#define __MODEL_H__
#include <vector>
#include <string>
#include "../math/math.h"
#include <memory>
#include "../resource/cache_resource.h"
#include "../render_system/render_data.h"
#include "../shaders/render_program.h"

class ModelMesh{};
class Skeleton{};

// model的 包围盒
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

// // model 本身
class RenderModelBase{};


class PbrRenderModel: public RenderModelBase {
public:
	ModelMesh* m_mesh;
	RenderProgram* m_program;
	AxisAlignedBox m_bounding_box;
	/* for animation */
	Skeleton *skeleton;
	Matrix4x4 transform;
	int attached;
	/* for sorting */
	int opaque;
	float distance;
	PbrRenderModel(ModelResource & model_resource);

	virtual void model_update(std::shared_ptr<PerFrame> frame);
	virtual void model_draw(std::shared_ptr<FrameBuffer2D> buffer);
	virtual void ModelRelease(){};
};
#endif //__MODEL_H__
