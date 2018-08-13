#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    try {

        std::cout << "Hello gweyl 1" << std::endl;
        
        gweyl::NumberVector nv1(3);
        gweyl::NumberVector nv2(4);
        gweyl::NumberVector nv3(3);
        gweyl::NumberVector nv4(3);

        nv4(0)=-1;

        std::cout << "Hello gweyl 2" << std::endl;
        
        // NumberVector ==
        //if (nv1 == nv3){
        if (gweyl::equal(nv1, nv3)){
            ;
        }else {
            std::string msg("NumberVector test != ");
            std::runtime_error e(msg);
            throw e;
        }

        std::cout << "Hello gweyl 3" << std::endl;
        
        // NumberVector !=
        //if (nv1 != nv2){
        if (!(gweyl::equal(nv1, nv2))){
            ;
        }else {
            std::string msg("NumberVector test != ");
            std::runtime_error e(msg);
            throw e;
        }

        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v2(gweyl::Type::A, nv2, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v3(gweyl::Type::A, nv3, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v4(gweyl::Type::A, nv4, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v5(gweyl::Type::B, nv4, gweyl::Coordinate::simple);


        std::cout << "Hello gweyl 4" << std::endl;
        
        // Vector !=
        if (v1 != v4){
        //if (!gweyl::equal(v1,v4)){
            ;
        }else {
            std::string msg("Vector test != 0001");
            std::runtime_error e(msg);
            throw e;
        }

        std::cout << "Hello gweyl 5" << std::endl;

        // Vector ==
        if (v1 == v3){
            ;
        }else {
            std::string msg("Vector test != 0002");
            std::runtime_error e(msg);
            throw e;
        }

        std::cout << "Hello gweyl 6" << std::endl;
        
        // Vector !=
        if (v1 != v2){
        
            ;
        }else {
            std::string msg("Vector test != 0003");
            std::runtime_error e(msg);
            throw e;
        }

        std::cout << "Hello gweyl 7" << std::endl;

        if (v1 != v4){
            ;
        }else {
            std::string msg("Vector test != 0004");
            std::runtime_error e(msg);
            throw e;
        }

        std::cout << "Hello gweyl 8" << std::endl;
        
        if (v1 != v5){
            ;
        }else {
            std::string msg("Vector test != 0005");
            std::runtime_error e(msg);
            throw e;
        }
        
        
        gweyl::VectorRootSpace w1 = v1;
        gweyl::VectorRootSpace w4 = v4;
        if (w1 == v1){
            ;
        }else {
            std::string msg("Vector test substitute  0001");
            std::runtime_error e(msg);
            throw e;
        }

        if (w4 != v1){
            ;
        }else {
            std::string msg("Vector test substitute  0002");
            std::runtime_error e(msg);
            throw e;
        }
        
        
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    

    try {

        //nv1 + nv2 = nv3
        
        gweyl::NumberVector nv1(4);
        nv1(0) = 1;nv1(1) = 0;nv1(2) = 0;nv1(3) = 0;
        gweyl::NumberVector nv2(4);
        nv2(0) = 0;nv2(1) = 1;nv2(2) = 0;nv2(3) = 0;
        gweyl::NumberVector nv3(4);
        nv3(0) = 1;nv3(1) = 1;nv3(2) = 0;nv3(3) = 0;
        gweyl::NumberVector nv4(4);
        nv4(0) = 1;nv4(1) = 0;nv4(2) = 0;nv4(3) = 0;
        gweyl::NumberVector nv5(4);
        nv5(0) = 3;nv5(1) = 3;nv5(2) = 0;nv5(3) = 0;
        
        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v2(gweyl::Type::A, nv2, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v3(gweyl::Type::A, nv3, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v4(gweyl::Type::A, nv4, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v5(gweyl::Type::A, nv5, gweyl::Coordinate::simple);

        v1 += v2;

        //v1.printf();
        //v3.printf();
        
        if (v3 == v1){
            ;
        }else {
            std::string msg("Vector test +=  0001");
            std::runtime_error e(msg);
            throw e;
        }

        v1 -= v2;
        if (v4 == v1){
            ;
        }else {
            std::string msg("Vector test -=  0001");
            std::runtime_error e(msg);
            throw e;
        }

        v3 *= 3;
        if (v3 == v5){
            ;
        }else {
            std::string msg("Vector test *=  0001");
            std::runtime_error e(msg);
            throw e;
        }

        
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }


    
    try {
        gweyl::NumberVector nv1(4);
        nv1(0) = 1;nv1(1) = 0;nv1(2) = 0;nv1(3) = 0;

        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v2(gweyl::Type::A, nv1, gweyl::Coordinate::fundamental);

        gweyl::RootSpace V(gweyl::Type::A, 4);

        gweyl::VectorRootSpace v3 = V.SimpleRoot(1);
        gweyl::VectorRootSpace v4 = V.FundamentalWeight(1);

        if (v1 == v3){
            ;
        }else {
            std::string msg("Vector test simple root  0001");
            std::runtime_error e(msg);
            throw e;
        }

        //v2.printf();
        //v4.printf();
        if (v2 == v4){
            ;
        }else {
            std::string msg("Vector test fundamental weight  0001");
            std::runtime_error e(msg);
            throw e;
        }
        
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    
    try {
        // v3 = v1 + v2
        gweyl::NumberVector nv1(4);
        nv1(0) = 1;nv1(1) = 0;nv1(2) = 0;nv1(3) = 0;
        gweyl::NumberVector nv2(4);
        nv2(0) = 0;nv2(1) = 1;nv2(2) = 0;nv2(3) = 0;
        gweyl::NumberVector nv3(4);
        nv3(0) = 1;nv3(1) = 1;nv3(2) = 0;nv3(3) = 0;
        gweyl::NumberVector nv4(4);
        nv4(0) = 5;nv4(1) = 5;nv4(2) = 0;nv4(3) = 0;
                
        gweyl::VectorRootSpace v1(gweyl::Type::A, nv1, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v2(gweyl::Type::A, nv2, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v3(gweyl::Type::A, nv3, gweyl::Coordinate::simple);
        gweyl::VectorRootSpace v4(gweyl::Type::A, nv4, gweyl::Coordinate::simple);


        gweyl::VectorRootSpace w1 = v1 + v2;
        if (w1 == v3){
            ;
        }else {
            std::string msg("Vector +  0001");
            std::runtime_error e(msg);
            throw e;
        }

        gweyl::VectorRootSpace w2 = w1 - v1;
        if (w2 == v2){
            ;
        }else {
            std::string msg("Vector test -  0001");
            std::runtime_error e(msg);
            throw e;
        }


        gweyl::VectorRootSpace w3 = w1 * 5;
        if (w3 == v4){
            ;
        }else {
            std::string msg("Vector test *  0001");
            std::runtime_error e(msg);
            throw e;
        }


        gweyl::VectorRootSpace w4 = 5 * w1;
        if (w4 == v4){
            ;
        }else {
            std::string msg("Vector test *  0002");
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
