
#include "model.h"











class Entity{

public:
	RenderModel* m_model;
	Entity(RenderModel* m) : m_model(m) {};
	bool RenderVisible(){return true;};
};