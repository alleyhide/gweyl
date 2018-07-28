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


Type Vector::type() const{
    return space_.type();
}


unsigned Vector::rank(){
    return space_.rank();
}

unsigned Vector::rank() const{
    return space_.rank();
}

bool Vector::operator==(const Vector& rhs){
    if (this->type() != rhs.type()){
        return false;
    }

    if (rank() != rhs.rank()){
        return false;
    }

    if (!equal(fundamentalCoefficients_, rhs.fundamentalCoefficients())){
        return false;
    }

    return true;
}

bool Vector::operator!=(const Vector& rhs){
    return !(*this == rhs);
}

}

