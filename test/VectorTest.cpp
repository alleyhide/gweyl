#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    gweyl::NumberVector nv(3);
    nv(0) = 1;
    gweyl::Vector v(gweyl::Type::A, nv, gweyl::Coordinate::simple);

    v.printf();

    return 0;
}
