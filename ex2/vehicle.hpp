#ifndef VEHICLE_HPP_

#define VEHICLE_HPP_

#include <queue>

struct Oasis {
    int water;
    int distanceToNext;
};

struct Vehicle {
    std::queue water;
    Vehicle();
};

#endif // VEHICLE_HPP_
