#ifndef SECTOR_H_
#define SECTOR_H_

#include "global.h"
#include "halfedge.h"
#include "vertex.h"

enum { UPPERLEFT, UPPERRIGHT, LOWERRIGHT, LOWERLEFT};

class HalfEdge;
class Vertex;

class Sector {
	/**  ------->		|
	 **					|	Boundary Edges are the set of Halfedges 	
	 **					|	pointing in the counter clockwise direction
	 **		sector		v
	 **		fill:color
	 **	^	contains 
	 **	|	[0-1 vertices]
	 **	|
	 **	|		<--------
	 **/
public:
	Sector();
	Sector(vector<vec2> corners); // construct sector with the given corner points
	
	vector<HalfEdge> getBounds(); 	// returns a list of the bounding edges for this sector
	
	vector<HalfEdge> getPermiableEdges();	// returns a list of the bounded edges that can be passed
	
	Vertex * getVertex() {
		return vertex;
	}	// indicates whether or not this sector has a vertex placed in it
								// if there is then make a copy of the vertex
								
	vector<Sector> getNeighborSectors(); // returns a list of the neighboring sectors that are accessable 
	
	void draw();	// draw the sector
	
	void fill(int c) {color = c;}	// floods this sector with the 'color'
	
	int getColor() { return color;}	// returns the 'color' for this sector
	
	void setLabel(unsigned int l) { label = l;}
	
	int getLabel() {return label;}
protected:
	int color;
	unsigned int label;
	vector<HalfEdge> bounds;
	Vertex * vertex;
};
#endif