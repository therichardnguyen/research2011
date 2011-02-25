#ifndef NET_H_
#define NET_H_
#include "global.h"
#include "vertex.h"
#include "sector.h"

class Net {
public:
	Net();
	Net(unsigned int r);	// make a map of region # of 4 sectors
	
	void generateNet();
	void makeRegion(vec2 center);
	
	void draw();
protected:
	map<unsigned int,Sector> sectors;
	map<unsigned int,Vertex> vertices;
	double cy1;
	double cy2;
	unsigned int regions;
	unsigned int sectorCount;
};
#endif /* MAP_H_ */