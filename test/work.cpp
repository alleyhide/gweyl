#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    std::cout << "Hello gweyl!" << std::endl;
    
    try {
        gweyl::NumberVector nv(2);
        nv(1) = 1;
        gweyl::VectorRootSpace v(gweyl::Type::G, nv, gweyl::Coordinate::fundamental);
        v.printf();


    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    return 0;
}
