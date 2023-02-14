#include "space.h"
#include "camera.h"
#include "../math/math.h"


// render function todo

void UpdateVisibleObjectsDirectionalLight(RenderSpaceData* m_scene, RenderContext* m_context){};



void updateVisibleObjectsPointLight(RenderSpaceData* m_scene, RenderContext* m_context){
	// // m_point_lights_visible_mesh_nodes.clear();
	// int point_light_num = 1; // todo oxygenC
	// //  for (const RenderEntity& entity : m_render_entities)
	// for (auto & entity : m_scene->m_render_entities){
	// 	BoundingBox mesh_asset_bounding_box {entity->m_model->m_bounding_box.getMinCorner(),
	// 											entity->m_model->m_bounding_box.getMaxCorner()};


	// 	bool intersect_with_point_lights = true;
	// 	// for (size_t i = 0; i < point_light_num; i++)
	// 	// {
	// 	// 	if (!BoxIntersectsWithSphere(
	// 	// 			BoundingBoxTransform(mesh_asset_bounding_box, GLMUtil::fromMat4x4(entity.m_model_matrix)),
	// 	// 			point_lights_bounding_spheres[i]))
	// 	// 	{
	// 	// 		intersect_with_point_lights = false;
	// 	// 		break;
	// 	// 	}
	// 	// }

	// 	if (intersect_with_point_lights){
	// 		entity->m_model->model_draw();
	// 		// m_point_lights_visible_mesh_nodes.emplace_back();
	// 		// RenderMeshNode& temp_node = m_point_lights_visible_mesh_nodes.back();

	// 		// temp_node.model_matrix = &entity.m_model_matrix;

	// 		// assert(entity.m_joint_matrices.size() <= m_mesh_vertex_blending_max_joint_count);
	// 		// if (!entity.m_joint_matrices.empty())
	// 		// {
	// 		// 	temp_node.joint_count    = static_cast<uint32_t>(entity.m_joint_matrices.size());
	// 		// 	temp_node.joint_matrices = entity.m_joint_matrices.data();
	// 		// }
	// 		// temp_node.node_id = entity.m_instance_id;

	// 		// VulkanMesh& mesh_asset           = render_resource->getEntityMesh(entity);
	// 		// temp_node.ref_mesh               = &mesh_asset;
	// 		// temp_node.enable_vertex_blending = entity.m_enable_vertex_blending;

	// 		// VulkanPBRMaterial& material_asset = render_resource->getEntityMaterial(entity);
	// 		// temp_node.ref_material            = &material_asset;
	// 	}
	// }
};



/*
** space function
*/

void RenderSpaceData::init_scene_data(){


	// init by resource
	auto* src = resource_manager->get_scene_resource("Assert/obj");

	// setup render scene
	// m_ambient_light = AmbientLight{vec3_new(1,1,1)};
	// m_directional_light = PDirectionalLight{vec3_new(1,1,1), vec3_new(1,1,1)};

	// camera init
	// todo shared ptr 
	m_camera = new RenderCamera();

	// context init
	// 配置的参数
	// 比如开启某个功能 黑白 xx 等
	m_render_context = new RenderContext();
	m_render_context->m_light_dir = {m_ambient_light.m_irradiance};
	m_render_context->m_camera = m_camera;
	// m_render_context.

	for (auto& model: src->scene_models){
		create_entity_by_model(model);
	}
}




void RenderSpaceData::create_entity_by_model(ModelResource& model_resource){
	// init by resource

	GameEntity* entity = entity_manager->create_entity();
	entity->init_resource(model_resource);
	m_render_entities.push_back(entity);

	m_visible_entities.push_back(entity);
};




void RenderSpaceData::render_space_draw_model(std::shared_ptr<PerFrame>){
	// 只针对model

	for (auto & entity : m_visible_entities){
		entity->m_model->model_draw(m_render_context->m_frame_buffer);
	}

}

void RenderSpaceData::update_visible_objects(std::shared_ptr<PerFrame> frame){
	// entity update
	// entity uniform update
	UpdateVisibleObjectsDirectionalLight(this, m_render_context);
	updateVisibleObjectsPointLight(this, m_render_context);
	// updateVisibleObjectsMainCamera(render_resource, camera);
	// updateVisibleObjectsAxis(render_resource);
	// updateVisibleObjectsParticle(render_resource);

	m_visible_entities.clear();
	for (auto & entity : m_render_entities){
		if (entity->render_visible())
		{
			entity->m_model->model_update(frame);
			m_visible_entities.push_back(entity);
		}
	}
}

