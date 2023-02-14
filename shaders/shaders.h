#pragma once

#include "../math/math.h"






class IShader {
public:
	virtual ~IShader();
	virtual Vector4 vertex(int iface, int nthvert) = 0;
	virtual bool fragment(Vector3 bar) = 0;
};


class S_Shader : public IShader{
public:
	Matrix4x4  uniform_M;   //  Projection*ModelView
	Matrix4x4  uniform_MIT; // (Projection*ModelView).invert_transpose()
	Matrix4x4  uniform_Mshadow; // transform framebuffer screen coordinates to shadowbuffer screen coordinates
	// Matrix4x4<2,3,float> varying_uv;  // triangle uv coordinates, written by the vertex shader, read by the fragment shader
	Matrix3x3  varying_tri; // triangle coordinates before Viewport transform, written by VS, read by FS

	// S_Shader(Matrix M, Matrix MIT, Matrix MS) : uniform_M(M), uniform_MIT(MIT), uniform_Mshadow(MS), varying_uv(), varying_tri() {}
	S_Shader(){};
	virtual ~S_Shader()
	{
		
	};
	virtual Vector4 vertex(int iface, int nthvert) {
		return vec4_new(1,1,1,1);
		// Vector4 gl_Vertex = uniform_MIT[0];
		// // varying_uv.set_col(nthvert, model->uv(iface, nthvert));
		// // Vector4 gl_Vertex = Viewport*Projection*ModelView*embed<4>(model->vert(iface, nthvert));
		// // varying_tri.set_col(nthvert, proj<3>(gl_Vertex/gl_Vertex[3]));
		// return gl_Vertex;
	}

	virtual bool fragment(Vector3 bar) {
		// todo
		// pipe line 的 draw_triangle 使用
		// Vector4 sb_p = uniform_Mshadow*embed<4>(varying_tri*bar); // corresponding point in the shadow buffer
		// sb_p = sb_p/sb_p[3];
		// int idx = int(sb_p[0]) + int(sb_p[1])*width; // index in the shadowbuffer array
		// // float shadow = .3+.7*(shadowbuffer[idx]<sb_p[2]); // magic coeff to avoid z-fighting
		// float shadow = .3+.7*(shadowbuffer[idx]<sb_p[2]+43.34); // magic coeff to avoid z-fighting
		// Vec2f uv = varying_uv*bar;                 // interpolate uv for the current pixel
		// Vector3 n = proj<3>(uniform_MIT*embed<4>(model->normal(uv))).normalize(); // normal
		// Vector3 l = proj<3>(uniform_M  *embed<4>(light_dir        )).normalize(); // light vector
		// Vector3 r = (n*(n*l*2.f) - l).normalize();   // reflected light
		// float spec = pow(std::max(r.z, 0.0f), model->specular(uv));
		// float diff = std::max(0.f, n*l);
		// TGAColor c = model->diffuse(uv);
		// for (int i=0; i<3; i++) color[i] = std::min<float>(20 + c[i]*shadow*(1.2*diff + .6*spec), 255);
		// // for (int i=0; i<3; i++) color[i] = std::min<float>(20, 55);
		return false;
	}
};

