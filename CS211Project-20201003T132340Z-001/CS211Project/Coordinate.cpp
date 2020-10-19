//
// Created by Michael Whitford on 5/10/20.
//

#include "Coordinate.h"

Coordinate::Coordinate(){
    index = -1;
    lat = 0.0;
    lon = 0.0;
    visited = false;
}

Coordinate::Coordinate(int i, double x, double y, bool visit = false){
    index = i;
    lat = y;
    lon = x;
    visited = visit;
}

int Coordinate::getDistance(Coordinate& c){

    //convert from degrees to radians
    double lat1 = ((M_PI) / 180) * this->lat;
    double long1 = ((M_PI) / 180) * this->lon;
    double lat2 = ((M_PI) / 180) * c.lat;
    double long2 = ((M_PI) / 180) * c.lon;

    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    double ans = (double)(pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2));

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    double R = 6371;

    // Calculate the result
    ans *= R;

    return (int)ans;
}

void Coordinate::travel(Coordinate loc, int& time){//method to go to next airport
    if(loc.isVisited()){
        std::cout << loc.index << "INVALID: already visited" << endl;
        return;
    }
    else{
        double tTime = ((double) this->getDistance(loc)) / 800.0; //Travel at 800kph
        time += tTime + 0.5; //half hour to land/unload/take off
        loc.visit(); //mark location as visited
    }
}

void Coordinate::print(){
    std::cout << this->lat << "  ";
    std::cout << this->lon;
}



bool Coordinate::isVisited(){ return visited; }
void Coordinate::setLat(double l){this->lat = l;}
void Coordinate::setLong(double l){this->lon = l;}
void Coordinate::setIndex(int i){this->index = i;}
double Coordinate::getLat(){return this->lat;}
double Coordinate::getLong(){return this->lon;}
void Coordinate::visit(){this->visited = true;}
int Coordinate::getIndex(){return this->index;}
void Coordinate::printIndex() {cout << this->index << ", ";}
