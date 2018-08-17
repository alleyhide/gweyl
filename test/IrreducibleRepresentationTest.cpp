#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    try {
        // default constructor
        gweyl::IrreducibleRepresentation rep1;

        // constructor
        gweyl::NumberVector nv1(4);
        nv1(0)=1; nv1(1)=2; nv1(2)=3; nv1(3)=4;
        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::fundamental);
        gweyl::IrreducibleRepresentation rep2(v1);

        // copy constructor
        gweyl::IrreducibleRepresentation rep3(rep2);

        // copy
        gweyl::IrreducibleRepresentation rep4 = rep3;

        // type
        gweyl::Type X=rep4.type();
        if (X == gweyl::Type::A){
            ;
        }else {
            std::string msg("IrreducibleRepresentation test type ");
            std::runtime_error e(msg);
            throw e;
        }

        // rank
        unsigned n=rep4.rank();
        if (n == 4){
            ;
        }else {
            std::string msg("IrreducibleRepresentation test rank ");
            std::runtime_error e(msg);
            throw e;
        }

        // highest weight
        gweyl::VectorRootSpace hw = rep4.highestweight();
        if (hw == v1){
            ;
        }else {
            std::string msg("IrreducibleRepresentation test highestweight ");
            std::runtime_error e(msg);
            throw e;
        }

        // ==
        if (rep4 == rep2){
            ;
        }else {
            std::string msg("IrreducibleRepresentation test == ");
            std::runtime_error e(msg);
            throw e;
        }

        // !=
        gweyl::NumberVector nv5(4);
        nv5(0)=1; nv5(1)=2; nv5(2)=3; nv5(3)=5;
        gweyl::VectorRootSpace v5(gweyl::Type::A, nv5, gweyl::Coordinate::fundamental);
        gweyl::IrreducibleRepresentation rep5(v5);
        if (rep4 != rep5){
            ;
        }else {
            std::string msg("IrreducibleRepresentation test != ");
            std::runtime_error e(msg);
            throw e;
        }

    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    // constructor not dominant
    try {
        gweyl::NumberVector nv1(4);
        nv1(0)=1; nv1(1)=2; nv1(2)=3; nv1(3)=-4;
        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::fundamental);
        gweyl::IrreducibleRepresentation rep(v1);

        // the following is error
        std::cout << "Error: not dominant" << std::endl;
        
    } catch(...) {
        ;
    }

    // constructor not integral
    try {
        gweyl::NumberVector nv1(4);
        nv1(0)=1; nv1(1)=2; nv1(2)=3; nv1(3)=gweyl::rational(1,2);
        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::fundamental);
        gweyl::IrreducibleRepresentation rep(v1);

        // the following is error
        std::cout << "Error: not integral" << std::endl;
        
    } catch(...) {
        ;
    }
        
    //dimension
    try {
        gweyl::NumberVector nv1(4);
        nv1(0)=1; nv1(1)=0; nv1(2)=0; nv1(3)=0;
        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::fundamental);
        gweyl::IrreducibleRepresentation rep1(v1);

        int dim = rep1.dimension();

        if (dim == 5){
            ;
        }else {
            std::string msg("dimension A 4 pi_1 ");
            std::runtime_error e(msg);
            throw e;
        }
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    return 0;
}
