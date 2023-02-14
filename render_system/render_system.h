
#pragma once
#include <memory>
#include "../game/space.h"
#include "render_data.h"



class RenderPipelineBase{
public:
	void Initialize(){};
	virtual void forward_render(std::shared_ptr<RenderSpaceData> r, std::shared_ptr<PerFrame> perFrame){};
private:
	virtual void draw_triangle(){};
};


class RenderPipeline: public RenderPipelineBase{
public:
	void forward_render(std::shared_ptr<RenderSpaceData> r, std::shared_ptr<PerFrame> perFrame);
private:
	void draw_triangle();
};

// 管理渲染相关的逻辑
class RenderSystem{
public:
	RenderSystem();
	std::shared_ptr<RenderSpaceData> r_space;
	std::shared_ptr<RenderPipelineBase> r_render_pipeline;
	void Init();
	void RenderTick();
	// ~RenderSystem(){};
};
