/**
 * @file   work.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/09/01
 
 * 
 * @brief  for the experimental tests of gweyl
 * 
 * Released under the MIT license
 */
#include <iostream>
#include <boost/assign.hpp>

#include "gweyl.hpp"

using namespace gweyl;

struct RepresentationTheory {
    IrreducibleRepresentation rep;
    std::vector<matrix> PositiveSingleRootVectorAction;
    std::vector<matrix> NegativeSingleRootVectorAction;
    bool calculated{false};
};

std::vector<RepresentationTheory> g_RepresentationTheory_A1;




int main(int argc, char** argv){

    std::cout << "Hello gweyl!" << std::endl;
    
    try {
        // L(pi_1)
        NumberVector nv1(1);
        nv1(0) = 1;
        VectorRootSpace v1(Type::A, nv1, Coordinate::fundamental);
        IrreducibleRepresentation rep1(v1);

        int m = rep1.dimension();
        std::cout << "A1 pi_1 dimension " << std::to_string(m) << std::endl;
        
        RepresentationTheory repth1;
        repth1.rep = rep1;

        matrix E1p(m,m);
        E1p(0,1) = 1;
        repth1.PositiveSingleRootVectorAction.push_back(E1p);
        
        matrix E1m(m,m);
        E1p(1,0) = 1;
        repth1.NegativeSingleRootVectorAction.push_back(E1m);

        repth1.calculated = true;

        g_RepresentationTheory_A1.push_back(repth1);

    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    return 0;
}
