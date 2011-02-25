#include "vertex.h"

Vertex::Vertex() {
	
}

Vertex::Vertex(vec2 position): pos(position[0],position[1]) {
	
}

Vertex::Vertex(vec2 position, unsigned int l): pos(position[0],position[1]) {
	label = l;
}

void Vertex::draw() {
	glBegin(GL_POINTS);
	glColor3f(0.9,0.2,0.2);
	glVertex2d(pos[0],pos[1]);
	glEnd();
}