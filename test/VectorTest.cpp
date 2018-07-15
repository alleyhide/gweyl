#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    try {
        gweyl::NumberVector nv1(3);
        gweyl::NumberVector nv2(4);
        gweyl::NumberVector nv3(3);
        gweyl::NumberVector nv4(3);

        nv4(0)=-1;
        
        // NumberVector ==
        if (nv1 == nv3){
            ;
        }else {
            std::string msg("NumberVector test != ");
            std::runtime_error e(msg);
            throw e;
        }
        
        // NumberVector !=
        if (nv1 != nv2){
            ;
        }else {
            std::string msg("NumberVector test != ");
            std::runtime_error e(msg);
            throw e;
        }

        if (nv1 != nv4){
            ;
        }else {
            std::string msg("NumberVector test != ");
            std::runtime_error e(msg);
            throw e;
        }
        
        
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    
    gweyl::NumberVector nv(3);
    nv(0) = 1;
    gweyl::Vector v(gweyl::Type::A, nv, gweyl::Coordinate::simple);

    
    
    v.printf();

    return 0;
}
