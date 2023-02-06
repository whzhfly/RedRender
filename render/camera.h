

#include "../math/geometry.h"


Matrix ModelView;
Matrix Viewport;
Matrix Projection;


void viewport(int x, int y, int w, int h) {
	Viewport = Matrix::identity();
	Viewport[0][3] = x+w/2.f;
	Viewport[1][3] = y+h/2.f;
	Viewport[2][3] = 1.f;
	Viewport[0][0] = w/2.f;
	Viewport[1][1] = h/2.f;
	Viewport[2][2] = 0;
}

void projection(float coeff) {
	Projection = Matrix::identity();
	Projection[3][2] = coeff;
}

void lookat(Vec3f eye, Vec3f center, Vec3f up) {
	Vec3f z = (eye-center).normalize();
	Vec3f x = cross(up,z).normalize();
	Vec3f y = cross(z,x).normalize();
	Matrix Minv = Matrix::identity();
	Matrix Tr   = Matrix::identity();
	for (int i=0; i<3; i++) {
		Minv[0][i] = x[i];
		Minv[1][i] = y[i];
		Minv[2][i] = z[i];
		Tr[i][3] = -center[i];
	}
	ModelView = Minv*Tr;
}


class RenderCamera{
public:
	// Vec3f Eye;
	Vec3f CameraEyes;

	Matrix GetTransformMatrix(){
		return Viewport*Projection*ModelView;
	}
};




