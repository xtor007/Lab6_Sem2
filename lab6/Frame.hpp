#ifndef Ray_hpp
#define Ray_hpp

#include "Tree.hpp"

using namespace std;

class Frame {
private:
	// FIXED FRAME POSITION
	float x = -10, z1 = -1, y1 = -1, z2 = 1, y2 = 1;
	//SHUTTER POSITION
	float xShutter = -5, yShutter = 0, zShutter = 0;

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
