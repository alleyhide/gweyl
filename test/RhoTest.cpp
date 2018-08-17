#include <iostream>

#include "gweyl.hpp"


void testRho(gweyl::Type t, unsigned n, const char* a_msg){
    
    try {
        gweyl::RootSpace V(t, n);
        gweyl::VectorRootSpace z=V.Zero();


        gweyl::NumberVector nv1(n);
        gweyl::VectorRootSpace v1(t, nv1, gweyl::Coordinate::simple);

        if (v1 == z){
            ;
        }else {
            std::string msg("VectorRootSpace test Zero 0001");
            std::runtime_error e(msg);
            throw e;
        }

        gweyl::VectorRootSpace r=V.Rho();
        
        gweyl::NumberVector nv2(n);

        for (unsigned i=0; i<n; ++i){
            nv2(i)=1;
        }
        
        gweyl::VectorRootSpace v2(t, nv2, gweyl::Coordinate::fundamental);
        if (v2 == r){
            ;
        }else {
            std::string msg("VectorRootSpace test Rho 0001");
            std::runtime_error e(msg);
            throw e;
        }

        std::vector<gweyl::VectorRootSpace> proots = V.PositiveRoots();
        gweyl::VectorRootSpace r2=V.Zero();
        for (gweyl::VectorRootSpace& x : proots){
            r2 += x;
        }
        r2 *= gweyl::rational(1,2);

        if (r2 == r){
            ;
        }else {
            std::string msg("VectorRootSpace test Rho 0002");
            std::runtime_error e(msg);
            throw e;
        }

        
    }catch (std::exception &e){
        std::cout << a_msg;
        std::cout << " Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return ;
    }


    
    return;
}

int main(int argc, char** argv){

    testRho(gweyl::Type::A, 1, "A1");
    testRho(gweyl::Type::A, 2, "A2");
    testRho(gweyl::Type::A, 3, "A3");
    testRho(gweyl::Type::A, 4, "A4");

    testRho(gweyl::Type::B, 2, "B2");
    testRho(gweyl::Type::B, 3, "B3");
    testRho(gweyl::Type::B, 4, "B4");
    
    testRho(gweyl::Type::C, 2, "C2");
    testRho(gweyl::Type::C, 3, "C3");
    testRho(gweyl::Type::C, 4, "C4");
    
    testRho(gweyl::Type::D, 4, "D4");
    testRho(gweyl::Type::D, 5, "D5");
    testRho(gweyl::Type::D, 6, "D6");

    testRho(gweyl::Type::E, 6, "E6");
    testRho(gweyl::Type::E, 7, "E7");
    testRho(gweyl::Type::E, 8, "E8");

    testRho(gweyl::Type::F, 4, "F4");

    testRho(gweyl::Type::G, 2, "G2");

    
    return 0;
}
