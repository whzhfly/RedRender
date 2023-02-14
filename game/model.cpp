#include "model.h"
#include "../render_system/draw.h"








/**
 * @brief 
 * PbrRenderModel
 */



// void RenderModel::create_render_program(){
// 	m_program = RenderProgram();
// 	m_program->render_shader = std::make_shared<S_Shader>();
// 	m_program->render_uniform_context = std::make_shared<uniform_context>();
// }

PbrRenderModel::PbrRenderModel(ModelResource & model_resource){
	// init program
	


	// init mesh
};

void PbrRenderModel::model_update(std::shared_ptr<PerFrame> frame){
	// // update uniform
	// //

	// // m_program->render_uniform_context
	// // m_program->render_shader
	// m_program->render_uniform_context.get()->ambient_intensity = frame.get()->ambient_intensity;
	// m_program->render_uniform_context.get()->camera_pos = frame.get()->camera_pos;
	// // m_program->render_uniform_context.get()->camera_vp_matrix = frame.get().

	// m_program->render_uniform_context.get()->light_dir = frame.get()->light_dir;
	// // Vector3 camera_pos;

	// // Matrix model_matrix;
	// // Matrix camera_vp_matrix;



};


void PbrRenderModel::model_draw(std::shared_ptr<FrameBuffer2D> buffer){
	// m_program->render_shader.get()
	// m_program->render_shader.get()->vertex();

	// for (int i=0; i<faceCnt; i++){
	// 	Vertex vertex[3];
	// 	for (int j=0; j<3; j++){
	// 		vertex[j].position = m_mesh->vert(i,j);
	// 		// vertex.tex_coord = m_mesh->diffuse(i,j);
	// 		// vertex.joint =
	// 		// vertex.normal = .
	// 		// vertex.tangent = .
	// 		// vertex.weight = .
	// 	};
	// 	// graphics_draw_triangle
	// 	draw_triangle(m_program, buffer);
	// }
	render_program_draw_triangle(m_program, buffer);
};
