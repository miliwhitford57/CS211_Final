//
// Created by Michael Whitford on 5/10/20.
//

#pragma once


#include "Region.h"
#include <cmath>
#include <iostream>

/*
 * This class corresponds to a latitude and longitude location.
 * Medicine must be delivered to each one of these
 */
class Coordinate {
    int index;
    double lat;
    double lon;
    bool visited;
public:
    Coordinate();
    Coordinate(int,double,double,bool);
    ~Coordinate() = default;
    Coordinate(const Coordinate&) = default;
    Coordinate& operator=(const Coordinate&) = default;
    void travel(Coordinate, int&);
    int getDistance(Coordinate&);
    double getLong();
    double getLat();
    int getIndex();
    void setLat(double);
    void setLong(double);
    void setIndex(int);
    void visit();
    bool isVisited();
    void print(void);
    void printIndex();
    friend class Plane;
    friend class Region;
    //friend void deliverMedicinetoRegion(Plane, Region);
};

