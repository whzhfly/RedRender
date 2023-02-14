
#ifndef __RENDER_CAMERA_H__
#define __RENDER_CAMERA_H__

#include "../math/math.h"


extern Matrix4x4 ModelView;
extern Matrix4x4 Viewport;
extern Matrix4x4 Projection;


// void viewport(int x, int y, int w, int h) {
// 	Viewport = Matrix4x4::identity();
// 	Viewport[0][3] = x+w/2.f;
// 	Viewport[1][3] = y+h/2.f;
// 	Viewport[2][3] = 1.f;
// 	Viewport[0][0] = w/2.f;
// 	Viewport[1][1] = h/2.f;
// 	Viewport[2][2] = 0;
// }

// void projection(float coeff) {
// 	Projection = Matrix4x4::identity();
// 	Projection[3][2] = coeff;
// }

// void lookat(Vector3 eye, Vector3 center, Vector3 up) {
// 	Vector3 z = (eye-center).normalize();
// 	Vector3 x = cross(up,z).normalize();
// 	Vector3 y = cross(z,x).normalize();
// 	Matrix4x4 Minv = Matrix4x4::identity();
// 	Matrix4x4 Tr   = Matrix4x4::identity();
// 	for (int i=0; i<3; i++) {
// 		Minv[0][i] = x[i];
// 		Minv[1][i] = y[i];
// 		Minv[2][i] = z[i];
// 		Tr[i][3] = -center[i];
// 	}
// 	ModelView = Minv*Tr;
// }


class RenderCamera{
public:
	// Vector3 Eye;
	Vector3 CameraEyes;
	Vector3 position;

	Matrix4x4 get_transform_Matrix4x4(){
		return mat4_mul_mat4(mat4_mul_mat4(Viewport, Projection), ModelView);
		// return Viewport*Projection*ModelView;
	}
	Vector3 get_camera_pos(){
		return position;
	}
};

#endif
