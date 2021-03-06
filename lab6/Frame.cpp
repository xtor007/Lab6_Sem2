#include "Frame.hpp"

float*** Frame::generateFrame() {
	float*** matrix = new float**[height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new float*[width];
        for (int j=0;j<3;j++) {
            matrix[i][j] = new float[3];
        }
	}
	return matrix;
}

void Frame::fillFrame() {
	float stepH = (z2 - z1) / height,
		  stepW = (y2 - y1) / width;
	int countPixelH = 0, countPixelW = 0;
	for (float countH = z1; countH < z2 - stepH; countH += stepH, countPixelH++) { 
		for (float countW = y1; countW < y2 - stepW; countW += stepW, countPixelW++) {
			Ray dotRay(x, countW, countH, xShutter, yShutter, zShutter);
			float *value = tree.findInTree(dotRay);
            frame[countPixelH][countPixelW] = value;
		}
		countPixelW = 0;
	}
}
