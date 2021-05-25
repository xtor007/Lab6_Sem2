#ifndef Ray_hpp
#define Ray_hpp

#include "Tree.hpp"

using namespace std;

class Frame {
private:
	// FIXED FRAME POSITION
	float x = 0, y1 = 0, z1 = 0, y2 = 10, z2 = 10;
	//SHUTTER POSITION
	float xShutter = 5, yShutter = 5, zShutter = 5;

	Tree& tree;
	int height, width;
	float** frame;
	float** generateFrame();
	void fillFrame();
public:
	Frame(int h, int w, Tree& tree) : height(h), width(w), frame(generateFrame()), tree(tree) { fillFrame();  };
	float** getFrame() { return frame; }
};	

#endif /* Ray_hpp */