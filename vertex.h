#ifndef VERTEX_H_
#define VERTEX_H_
#include "global.h"
#include "sector.h"

class Sector;

class Vertex {
public:
	Vertex();
	Vertex(vec2 pos);	// constructs the vertex @ the given position
	Vertex(vec2 pos, unsigned int label);	// constructs the vertex @ the given position with the given name
	
	void setLabel(unsigned int l) {label = l;}
	unsigned int getLabel() {return label;}	// returns the label of this vertex, returns -1 if there is no label
	void draw();
	
protected:
	vec2 pos;
	unsigned int label;
	vector<Vertex> neighbors;	// could possibly be edges but vertex seems more intuitive right now
	Sector * container;
};
#endif
