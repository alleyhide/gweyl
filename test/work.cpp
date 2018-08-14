#include <iostream>
#include <boost/assign.hpp>

#include "gweyl.hpp"

int main(int argc, char** argv){

    std::cout << "Hello gweyl!" << std::endl;
    
    try {
        //gweyl::NumberVector nv(2);
        //nv(1) = 1;
        std::vector<std::vector<gweyl::rational> > vv{{1,0}, {0,1}, {1,1}};

        for (std::vector<gweyl::rational>& x : vv){
            
            gweyl::NumberVector nv(x.size());
            std::copy(x.begin(), x.end(), nv.begin());
            //std::cout << "nv " << nv;
            gweyl::VectorRootSpace v(gweyl::Type::G, nv, gweyl::Coordinate::simple);
            v.printf();
        }
        


    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    return 0;
}
