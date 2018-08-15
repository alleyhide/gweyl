#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    char t = argv[1][0];
    
    gweyl::Type X;
    switch (t){
    case 'A':
        X=gweyl::Type::A;
        break;
    case 'B':
        X=gweyl::Type::B;
        break;
    case 'C':
        X=gweyl::Type::C;
        break;
    case 'D':
        X=gweyl::Type::D;
        break;
    case 'E':
        X=gweyl::Type::E;
        break;                
    case 'F':
        X=gweyl::Type::F;
        break;
    case 'G':
        X=gweyl::Type::G;
        break;        
    default:
        std::cout << "Error type " << std::to_string(t);
        return -1;
    }

    unsigned n = atoi(argv[2]);


    try {

        gweyl::RootSpace V(X, n);
        std::vector<gweyl::VectorRootSpace> proots = V.PositiveRoots();

        std::cout << "Positive Roots (simple coef) " << std::endl;
        for (gweyl::VectorRootSpace& x: proots){
            //x.printf();
            gweyl::NumberVector nv = x.simpleCoefficients();
            //std::cout << nv << std::endl;
            std::cout << nv;
        }
        std::cout << std::endl;
        
        
    }catch (std::exception &e){
        
        std::cout << "Error what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    
    return 0;
}
