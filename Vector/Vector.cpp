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

Vector::Vector(Type X, NumberVector& v, Coordinate c){
    X_ = X;
    rank_ = v.size();
    
    if (c == Coordinate::simple){
        simpleCoefficients_ = v;
        matrix A = CartanMatrix();
        fundamentalCoefficients_ = prod(A, v);
    }else {
        matrix P = InverseCartanMatrix();
        simpleCoefficients_ = prod(P, v);
        fundamentalCoefficients_ = v;
    }
}

Vector::Vector(){
}

Vector::~Vector(){
}
                  
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
#endif

bool equal(const Vector &v, const Vector &w){
    if ((RootSpace&)v != (RootSpace&)w){
        return false;
    }

    //if (v.fundamentalCoefficients() != w.fundamentalCoefficients()){
    //if (!equal(v.fundamentalCoefficients(), w.fundamentalCoefficients())){
    //return false;
    //}

#if 0    
    NumberVector v1 = v.fundamentalCoefficients();
    NumberVector w1 = w.fundamentalCoefficients();
    if (!(gweyl::equal(v1, w1))){

        return false;
    }
#endif
    
    return true;
}

}
