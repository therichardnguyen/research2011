#include "halfedge.h"

HalfEdge::HalfEdge(): _startPos(0.0,0.0) {
	sibling = NULL;
	forwardEdge = NULL;
}

HalfEdge::HalfEdge(vec2 v1): _startPos(v1[0],v1[1]) {
	sibling = NULL;
	forwardEdge = NULL;
}

HalfEdge::HalfEdge(vec2 start, HalfEdge &s, HalfEdge &f): _startPos(start[0],start[1]) {
	sibling = &s;
	forwardEdge = &f;
	sibling->sibling = this;
}

void HalfEdge::setForwardEdge(HalfEdge &f) {
	cout << "set Forward Edge " << f.getPos(0.0) << endl;
	forwardEdge = &f;
}
vec2 HalfEdge::getPos(double t = 0.0) {
	vec2 _endPos;
	if (t == 0.0) 
		return _startPos;
	if (getForwardEdge() != NULL) {
		_endPos = getForwardEdge()->getPos(0.0);
	} else { 
		_endPos[0] = 0.0;
		_endPos[1] = 0.0;
	}
	vec2 interPos = _startPos*(1-t) + _endPos*(t);
    return interPos;
}

HalfEdge& HalfEdge::operator =(const HalfEdge& e) {
	_startPos = e._startPos;
	sibling = e.sibling;
	forwardEdge = e.forwardEdge;
	sector = e.sector;
		return *this;
}

void HalfEdge::draw() {
	glBegin(GL_LINES);
	glColor3f(0.2,0.9,0.2);
	glVertex2d(getPos(0.0)[0], getPos(0.0)[1]);
	glVertex2d(getPos(1.0)[0], getPos(1.0)[1]);
	cout << getPos(0.0) << " " << getPos(1.0) << endl;
	glEnd();
}