#include "sector.h"

Sector::Sector() {
	
}
Sector::Sector(vector<vec2> corners) {
	unsigned int i;
	// no vertex yet
	vertex = NULL;
	
	for (i=0; i<corners.size(); i++) {
		bounds.push_back(HalfEdge(corners[i]));
	}
	for (i=0;i<bounds.size();i++) {	
		if (i < (bounds.size()-1))
			bounds[i].setForwardEdge(bounds[(i+1)]);
		else 
			bounds[i].setForwardEdge(bounds[0]);
	}
} 

	

vector<HalfEdge> Sector::getBounds() {
	return bounds;
} 	// returns a list of the bounding edges for this sector


vector<Sector> Sector::getNeighborSectors() {
	vector<Sector> neighbors;
	for (vector<HalfEdge>::iterator it = bounds.begin(); it != bounds.end(); it++) {
		if (it->canPass() && it->getSibling() != NULL) {
			neighbors.push_back(*(it->getSibling()->getSector()));
		}
	}
	return neighbors;
} 

void Sector::draw() {
	//draw the interior of the sector
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,.9); 
	for(vector<HalfEdge>::iterator it = bounds.begin(); it!=bounds.end(); it++) {
		glVertex2d((it->getPos(0.0))[0],(it->getPos(0.0))[1]);
	}
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0); 
	for(vector<HalfEdge>::iterator it = bounds.begin(); it!=bounds.end(); it++) {
		glVertex2d((it->getPos(0.0))[0],(it->getPos(0.0))[1]);
	}
	glEnd();
	// ask the bounds to draw themselves
	for(vector<HalfEdge>::iterator it = bounds.begin(); it!=bounds.end(); it++) {
		it->draw();
	}
	
	// draw the vertex
	if (vertex != NULL)
		vertex->draw();
}

