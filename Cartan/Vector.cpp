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
// other implementations of Vector is in ../Vector/Vector.cpp
// and constructor of Vector is implemented here
// because of dependencies in cmake
//

Vector::Vector(Type X, NumberVector& v, Coordinate c){

    RootSpace V(X, v.size());

    space_ = V;
    
    if (c == Coordinate::simple){
        simpleCoefficients_ = v;
        matrix A = space_.CartanMatrix();
        fundamentalCoefficients_ = prod(A, v);
    }else {
        matrix P = space_.InverseCartanMatrix();
        simpleCoefficients_ = prod(P, v);
        fundamentalCoefficients_ = v;
    }
}

Vector::Vector(){
}

Vector::~Vector(){
}

}
