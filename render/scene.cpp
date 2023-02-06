#include "scene.h"
#include "camera.h"
















void RenderSceneData::InitSceneData(){

	// camera init
	RenderCamera camera;
	Matrix transform = camera.GetTransformMatrix();

	// Init context

	// // entity init
	// for (auto entity : m_render_entities){
	// 	for (int faceIndex=0;faceIndex<entity->nfaces();faceIndex++){
	// 	}
	// }

	// xx
}

void RenderSceneData::RenderSceneTick(){



	// camera update
	Matrix transform = camera->GetTransformMatrix();


	 // prepare render command context
	m_render_context->m_light_dir = m_directional_light.m_direction;


	//update per-frame buffer
	PerFrame per_frame(this, m_render_context);


	// update per-frame visible objects

	// prepare pipeline's render passes data
	RenderSceneDraw();

	// render one frame
	// draw_layer_view();
};

void RenderSceneData::RenderSceneDraw(){
	// entity update

	// void RenderScene::updateVisibleObjectsDirectionalLight(std::shared_ptr<RenderResource> render_resource,
                                                        //    std::shared_ptr<RenderCamera>   camera)
	for (auto & entity : m_render_entities){
		if (entity->RenderVisible()) continue;
		for (int faceIndex=0;faceIndex<entity->m_model->faceCnt;faceIndex++){
		}
	}

	UpdateVisibleObjects();
}

void RenderSceneData::UpdateVisibleObjects(){
	// entity update
	UpdateVisibleObjectsDirectionalLight(this, m_render_context);
	updateVisibleObjectsPointLight(this, m_render_context);
	// updateVisibleObjectsMainCamera(render_resource, camera);
	// updateVisibleObjectsAxis(render_resource);
	// updateVisibleObjectsParticle(render_resource);
}


// render function todo

void UpdateVisibleObjectsDirectionalLight(RenderSceneData* m_scene, RenderContext* m_context){};
void updateVisibleObjectsPointLight(RenderSceneData* m_scene, RenderContext* m_context){
	// m_point_lights_visible_mesh_nodes.clear();
	int point_light_num = 1; // todo oxygenC
	//  for (const RenderEntity& entity : m_render_entities)
	for (auto & entity : m_scene->m_render_entities){
		BoundingBox mesh_asset_bounding_box {entity->m_model->m_bounding_box.getMinCorner(),
												entity->m_model->m_bounding_box.getMaxCorner()};


		bool intersect_with_point_lights = true;
		// for (size_t i = 0; i < point_light_num; i++)
		// {
		// 	if (!BoxIntersectsWithSphere(
		// 			BoundingBoxTransform(mesh_asset_bounding_box, GLMUtil::fromMat4x4(entity.m_model_matrix)),
		// 			point_lights_bounding_spheres[i]))
		// 	{
		// 		intersect_with_point_lights = false;
		// 		break;
		// 	}
		// }

		if (intersect_with_point_lights){
			entity->m_model->ModelDraw();
			// m_point_lights_visible_mesh_nodes.emplace_back();
			// RenderMeshNode& temp_node = m_point_lights_visible_mesh_nodes.back();

			// temp_node.model_matrix = &entity.m_model_matrix;

			// assert(entity.m_joint_matrices.size() <= m_mesh_vertex_blending_max_joint_count);
			// if (!entity.m_joint_matrices.empty())
			// {
			// 	temp_node.joint_count    = static_cast<uint32_t>(entity.m_joint_matrices.size());
			// 	temp_node.joint_matrices = entity.m_joint_matrices.data();
			// }
			// temp_node.node_id = entity.m_instance_id;

			// VulkanMesh& mesh_asset           = render_resource->getEntityMesh(entity);
			// temp_node.ref_mesh               = &mesh_asset;
			// temp_node.enable_vertex_blending = entity.m_enable_vertex_blending;

			// VulkanPBRMaterial& material_asset = render_resource->getEntityMaterial(entity);
			// temp_node.ref_material            = &material_asset;
		}
	}
};


