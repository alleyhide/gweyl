#include <iostream>
#include <boost/assign.hpp>

#include "gweyl.hpp"

int main(int argc, char** argv){

    std::cout << "Hello gweyl!" << std::endl;
    
    try {
        gweyl::Type t = gweyl::Type::E;
        unsigned n = 6;

        gweyl::NumberVector nv1(n);
        nv1(0)=1;
        gweyl::VectorRootSpace v1(t, nv1, gweyl::Coordinate::fundamental);
        gweyl::IrreducibleRepresentation rep1(v1);
        
        int dim = rep1.dimension();

        std::cout << "dimension " << std::to_string(dim) << std::endl;
        


    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    return 0;
}
