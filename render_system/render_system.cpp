#include "render_system.h"






/**
 * Render System
 */


RenderSystem::RenderSystem(){};



void RenderSystem::Init(){
	r_space = std::make_shared<RenderSpaceData>();
	r_render_pipeline = std::make_shared<RenderPipeline>();

	// global rendering resource
	// todo

	// setup render scene
	r_space.get()->init_scene_data();

	// initialize render pipeline
	r_render_pipeline.get()->Initialize();
};


void RenderSystem::RenderTick(){
	// init render data

	//update per-frame buffer
	auto per_frame = std::make_shared<PerFrame>(r_space.get()->m_render_context, this->r_space.get());

	// 收集数据
	r_space.get()->update_visible_objects(per_frame);

	// pipeline work
	// 画三角形
	r_render_pipeline.get()->forward_render(r_space, per_frame);

	// window work
	// 接入window api 实现
	// window_draw_buffer
};


/**
 * Render Pipeline
 */


void RenderPipeline::forward_render(std::shared_ptr<RenderSpaceData> r_space, std::shared_ptr<PerFrame> perFrame){

	r_space.get()->render_space_draw_model(perFrame);
};

void RenderPipeline::draw_triangle(){
	// r_space.get()->render_space_draw_model(perFrame);
	// 调用系统接口 渲染 perframe 
};
