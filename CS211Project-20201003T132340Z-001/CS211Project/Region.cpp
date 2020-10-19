//
// Created by Michael Whitford on 5/12/20.
//


#include "Region.h"


Region::Region(){
    visited = false;
    stops.empty();
}
Region::Region(const vector<Coordinate>& v){
    visited = false;
    stops = v;
}

Coordinate& Region::shortest(Coordinate c){ //finds distance to shortest coordinate in a region to the current Coordinate
    int stops = this->stops.size();
    int shrt = INT_MAX;
    int index;
    int d;

    for(int i = 0; i < stops; i++){//iterates through each stop and gets the distance
        d = c.getDistance(this->getStops().at(i));

        if(d < shrt){
            shrt = d;
            index = i;
        }
    }
    return this->getStops().at(index);
}

void Region::setStops(const vector<Coordinate>& v) {stops = v;}
bool Region::isVisited() {return visited;}
void Region::visit() {this->visited = true;}
vector<Coordinate>& Region::getStops() {return stops;}