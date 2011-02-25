#include "net.h"

Net::Net() {
	
}
Net::Net(unsigned int r) {
	regions = r;
	generateNet();
}	// make a map of region # of 4 sectors
	
void Net::generateNet() {
	unsigned int i = 0;
	cy1 = .05 + 1.7/4;
	cy2  = -cy1;
	sectorCount = 0;
	//make first half of the map
	//for (i=0;i<regions;i++) {
		makeRegion(vec2(-1+.1+(1.8/(2*regions))+i*(1.8/regions),cy1));
	//}
}
void Net::makeRegion(vec2 center) {
	double cx = center[0];
	double cy = center[1];
	vector<vec2> v;
	v.push_back(vec2(cx-1.8/(2*regions),cy+1.7/4));
	v.push_back(vec2(cx-1.8/(2*regions),cy));
	v.push_back(vec2(cx-1.8/(4*regions),cy));
	v.push_back(vec2(cx,cy+1.7/8));
	v.push_back(vec2(cx,cy+1.7/4));
	Sector ul(v);
	ul.setLabel(sectorCount++);
	sectors[ul.getLabel()]= ul;
	v.clear();
	
	//test
	for(vector<HalfEdge>::iterator it = ul.getBounds().begin() ; it!=ul.getBounds().end(); it++ ) {
		cout << it->getPos(0.0) << "  " << it->getPos(1.0)<< endl;
	}
	/*
	v.push_back(vec2(cx,cy+1.7/4));
	v.push_back(vec2(cx,cy+1.7/8));
	v.push_back(vec2(cx+1.8/(4*regions),cy));
	v.push_back(vec2(cx+1.8/(2*regions),cy));
	v.push_back(vec2(cx+1.8/(2*regions),cy+1.7/4));
	Sector ur(v);
	ur.setLabel(sectorCount++);
	sectors[ur.getLabel()]=ur;
	v.clear();
	
	v.push_back(vec2(cx,cy-1.7/8));
	v.push_back(vec2(cx,cy-1.7/4));
	v.push_back(vec2(cx+1.8/(2*regions),cy-1.7/4));
	v.push_back(vec2(cx+1.8/(2*regions),cy));
	v.push_back(vec2(cx+1.8/(4*regions),cy));
	Sector lr(v);
	lr.setLabel(sectorCount++);
	sectors[lr.getLabel()] = lr;
	v.clear();
	
	v.push_back(vec2(cx,cy-1.7/8));
	v.push_back(vec2(cx-1.8/(4*regions),cy));
	v.push_back(vec2(cx-1.8/(2*regions),cy));
	v.push_back(vec2(cx-1.8/(2*regions),cy-1.7/4));
	v.push_back(vec2(cx,cy-1.7/4));
	Sector ll(v);
	ll.setLabel(sectorCount++);
	sectors[ll.getLabel()] = ll;
	v.clear();
	*/
}

void Net::draw() {
	for(map<unsigned int, Sector>::iterator it = sectors.begin(); it!=sectors.end(); it++) {
		it->second.draw();
	}
}
