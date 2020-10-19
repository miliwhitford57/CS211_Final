
#include <iostream>
#include "Coordinate.h"


using namespace std;

Region& chooseRegion(Region rArray[], Coordinate c) { //finds the next closest region to current Coordinate
    int last = 0;
    int index = 0;
    Region& r = rArray[0];

    for(int i = 0; i<6; i++)  {
        if(!rArray[i].isVisited()){
            int last = 0;
            int shortest = INT_MAX;
            int ind;

            //For each region, iterate though the stops to find the closest coordinate
            for (int it = 0; it < rArray[i].getStops().size(); it++) {
                if ((c.getDistance(rArray[i].getStops().at(it)) < last) && (c.getDistance(rArray[i].getStops().at(it)) > 100)) {
                    last = c.getDistance(rArray[i].getStops().at(it));
                    ind = it;
                }
                if(last < shortest){
                    shortest = last;
                    index = ind;
                    r = rArray[i];
                }
            }

        }
    }

return r;
}



int main() {
    Coordinate* currentC;
    Region* currentR;
    vector<Coordinate> lNA;
    vector<Coordinate> lSA;
    vector<Coordinate> lEU;
    vector<Coordinate> lAF;
    vector<Coordinate> lAS;
    vector<Coordinate> lOC;
    Coordinate x[1001];
    Region regions[6];
    int time = 0;

    //initilize array of coordinates
    for(int i = 0; i<1001; i++){
        x[i].setIndex(i);
        double newLat; cin >> newLat;
        x[i].setLat(newLat);
        double newLong; cin >> newLong;
        x[i].setLong(newLong);
    }

    //designate locations to apropriate regions
    for(int i = 0;i<1001;i++){
        if(((x[i].getLat() <= 67) && (x[i].getLat() >= 16)) && ((x[i].getLong() <= -47) && (x[i].getLong() >= -159))){
            lNA.push_back(x[i]);
            //if(current.getDistance(x[i]) < current.getDistance())
        }
        else if(((x[i].getLat() <= 12) && (x[i].getLat() >= -54)) && ((x[i].getLong() <= -37) && (x[i].getLong() >= -89))){
            lSA.push_back(x[i]);
        }
        else if(((x[i].getLat() <= 68.8) && (x[i].getLat() >= 24.5)) && ((x[i].getLong() <= 42) && (x[i].getLong() >= -23))){
            lEU.push_back(x[i]);
        }
        else if(((x[i].getLat() <= 5) && (x[i].getLat() >= -35)) && ((x[i].getLong() <= 49) && (x[i].getLong() >= 8))){
            lAF.push_back(x[i]);
        }
        else if(((x[i].getLat() <= 57.4) && (x[i].getLat() >= 6.7)) && ((x[i].getLong() <= 145) && (x[i].getLong() >= 42.8))){
            lAS.push_back(x[i]);
        }
        else if(((x[i].getLat() <= 6.2) && (x[i].getLat() >= -50)) && ((x[i].getLong() <= 179.7) && (x[i].getLong() >= 98.6))){
            lOC.push_back(x[i]);
        }
        else{
            lEU.push_back(x[i]);
        }
    }

    //initialize regions
    Region NA;
    NA.setStops(lNA);
    Region SA;
    SA.setStops(lSA);
    Region EU;
    EU.setStops(lEU);
    Region AFRICA;
    AFRICA.setStops(lAF);
    Region ASIA;
    ASIA.setStops(lAS);
    Region OCEANIA;
    OCEANIA.setStops(lOC);

    //initialize first location
    currentR = &EU;
    currentC = &EU.getStops()[0];
    currentC->visit();


    Region regionAr[6] = {NA,SA,EU,AFRICA,ASIA,OCEANIA};

    //set the number of regions left
    int regionsLeft = 6;

    //Visit every coordinate until all Regions are visited
    while(regionsLeft > 0) {

        //init values for current region
        int stops = currentR->getStops().size();
        int stopsLeft = stops;
        int n = 0;
        Coordinate& next = currentR->getStops().at(0);

        while(stopsLeft > 0) {

            for (int i = 0; i < stops; i++) {//go through every Coordinate in region to find shortest

                int d1 = currentC->getDistance(next);

                if ((!currentR->getStops().at(i).isVisited()) &&
                    (d1 < currentC->getDistance(currentR->getStops().at(i)))) {
                    next = currentR->getStops().at(i);
                    n = i;
                }

                if (i == (stops - 1)) {//once at final value in region, travel to shortest
                    currentC->visit();
                    currentC->travel(next, time);
                    currentC = &currentR->getStops().at(n);;
                    currentC->printIndex();
                    stopsLeft--;
                }
            }
        }

        //Once all coordinates are visited, determine next closest region
        Region &newRegion = chooseRegion(regionAr, *currentC);
        Coordinate newCoordinate = newRegion.shortest(*currentC);

        //mark current region as visited and go to next region
        currentC->travel(newCoordinate, time);
        currentC = &newCoordinate;
        currentC->printIndex();
        currentC->visit();
        currentR = &newRegion;
        currentR->visit();
        regionsLeft--;
    }

    return 0;
}