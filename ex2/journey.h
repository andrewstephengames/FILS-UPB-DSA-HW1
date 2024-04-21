#ifndef JOURNEY_H
#define JOURNEY_H

#include <iostream>
#include <fstream>
#include "myQueue.h"
using namespace std;

struct Oasis
{
    int water;
    int distanceToNext;
};

class JourneyThroughTheDesert
{
private:
    Oasis oasis;
    Queue<Oasis> queueInit;
    Queue<Oasis> queueAux;
    float w;
    int nrOasis, consumption, aux; // aux to see if we can complete the road or not, before computing
public:
    JourneyThroughTheDesert();
    void readInput();
    void execute();
};

#endif // JOURNEY_H
