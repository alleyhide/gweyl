/**
 * @file   Vector.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/07/07
 * 
 * @brief  class Vector
 * 
 * 
 */



#include "gweyl.hpp"
#include "gweyl_private.hpp"


namespace gweyl{

//
// constructor of Vector is implemented in ../Cartan/Vector.cpp
// because of dependencies in cmake
//


void Vector::printf(){
    std::cout << "simple " << simpleCoefficients_ << std::endl;
    std::cout << "fundamental " << fundamentalCoefficients_ << std::endl;
}

NumberVector Vector::simpleCoefficients() const{
    return simpleCoefficients_;
}

NumberVector Vector::simpleCoefficients(){
    return simpleCoefficients();
}

NumberVector Vector::fundamentalCoefficients() const{
    return fundamentalCoefficients_;
}

NumberVector Vector::fundamentalCoefficients(){
    return fundamentalCoefficients();
}



Type Vector::type(){
    return space_.type();
}


unsigned Vector::rank(){
    return space_.rank();
}

#if 0
bool operator==(const Vector &v, const Vector &w){
    if ((RootSpace&)v != (RootSpace&)w){
        return false;
    }

    //if (v.fundamentalCoefficients() != w.fundamentalCoefficients()){
    if (!equals(v.fundamentalCoefficients(), w.fundamentalCoefficients())){
        return false;
    }

    return true;
}


bool operator!=(const Vector &v, const Vector &w){
    return !(v == w);            
}


bool equal(const Vector &v, const Vector &w){
    if ((RootSpace&)v != (RootSpace&)w){
        return false;
    }

    //if (v.fundamentalCoefficients() != w.fundamentalCoefficients()){
    //if (!equal(v.fundamentalCoefficients(), w.fundamentalCoefficients())){
    //return false;
    //}


    NumberVector v1 = v.fundamentalCoefficients();
    NumberVector w1 = w.fundamentalCoefficients();
    if (!(gweyl::equal(v1, w1))){

        return false;
    }

    
    return true;
}
#endif
}

