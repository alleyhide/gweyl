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

        gweyl::Vector v1(gweyl::Type::A, nv1, gweyl::Coordinate::simple);
        gweyl::Vector v2(gweyl::Type::A, nv2, gweyl::Coordinate::simple);
        gweyl::Vector v3(gweyl::Type::A, nv3, gweyl::Coordinate::simple);
        gweyl::Vector v4(gweyl::Type::A, nv4, gweyl::Coordinate::simple);
        gweyl::Vector v5(gweyl::Type::B, nv4, gweyl::Coordinate::simple);


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
        
        
        gweyl::Vector w1 = v1;
        gweyl::Vector w4 = v4;
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


        

    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    
    
    
    


    return 0;
}
