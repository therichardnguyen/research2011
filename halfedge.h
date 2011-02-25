#ifndef HALFEDGE_H_
#define HALFEDGE_H_
#include "global.h"
#include "sector.h"

/***** Consider using the half edge data structure + winged edge....
*/
enum {_PATH, _BOUNDARY, _POLE, _NOTHING};

class Sector;
class HalfEdge;

class HalfEdge {
	/* Edge represented as two HalfEdges
	**	(_startPos on this sibling)
	**	_endPos ------>    	<---- forwardEdge 
	**		|
	**		|	
	**		|				<---- sibling
	**		|
	**		v	
	**			sector
	**		^
	**		|
	**		|				<---- this halfEdge
	**		|
	**	_startPos 
	*/
public:
	HalfEdge();
	
	// make a halfEdge without a sibling
	HalfEdge(vec2 start);
	
	// make a halfEdge with a sibling and connect the sibling to this edge
	HalfEdge(vec2 start, HalfEdge &sibling, HalfEdge &forward); 
	
	HalfEdge& operator =(const HalfEdge& e);
	
	// get the sibling of this edge
	HalfEdge * getSibling() {
		return sibling;
	}
	
	// set the sibling of this edge
	void setSibling(HalfEdge &s) {
		sibling = &s;
	}
	
	HalfEdge * getForwardEdge() { 
		return forwardEdge;
	}
	
	void setForwardEdge(HalfEdge &f);
	// get the coordinate of the edge linearly interrpolated with factor t
	vec2 getPos(double t); 
	
	// set the endpoint of this halfEdge to the given 'pos'
	void setPos(vec2 pos) { _startPos = pos; }
	
	
	Sector * getSector() { return sector; }
	
	void setSector(Sector &s) {
		sector = &s;
	}
	
	bool canPass() { return true; }
	
	int iAm() { return _NOTHING; }
	
	void draw();
	
protected:
	vec2 _startPos;
	HalfEdge * sibling;
	HalfEdge * forwardEdge;
	Sector * sector;
};

class Path : public HalfEdge {
	// indicates whether or not a path can cross this edge
	bool canPass() { return false; }
	// indicates what kind of Edge this edge is
	int iAm() { return _PATH; }
};

class Boundary : public HalfEdge {
	// indicates whether or not a path can cross this edge
	bool canPass() { return true; }
	
	// indicates what kind of Edge this edge is
	int iAm() { return _BOUNDARY; }
};

class Pole: public HalfEdge {
	bool canPass() { return false; }
	int iAm() { return _POLE; }
};
#endif