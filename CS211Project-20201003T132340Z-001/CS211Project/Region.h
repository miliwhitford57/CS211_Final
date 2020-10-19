//
// Created by Michael Whitford on 5/12/20.
//

#pragma once

#include "Coordinate.h"

class Plane;
class Coordinate;

#include <vector>

using namespace std;

/*
 * This class encapsulates a number of regions as well
 * as an indicator to tell the user if it's been visited
 */

class Region {
protected:
    vector<Coordinate> stops;
    bool visited;
public:
    explicit Region();
    explicit Region(const vector<Coordinate>&);
    bool isVisited();
    void visit();
    void setStops(const vector<Coordinate>& );
    vector<Coordinate>& getStops();
    Coordinate& shortest(Coordinate);
};

