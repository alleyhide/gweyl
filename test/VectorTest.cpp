#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    try {
        
        gweyl::NumberVector nv(3);
        nv(0) = 1;
        gweyl::Vector v(gweyl::Type::A, nv, gweyl::Coordinate::simple);
        //v.printf();
        
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    
    
    
    


    return 0;
}
