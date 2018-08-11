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

VectorRootSpace::VectorRootSpace(Type X, NumberVector& v, Coordinate c){

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

VectorRootSpace::VectorRootSpace(){
}

VectorRootSpace::~VectorRootSpace(){
}

VectorRootSpace::VectorRootSpace(const VectorRootSpace& rhs){
    RootSpace V(rhs.type(), rhs.rank());
    space_ = V;
    simpleCoefficients_ = rhs.simpleCoefficients();
    fundamentalCoefficients_ = rhs.fundamentalCoefficients();
}

VectorRootSpace& VectorRootSpace::operator=(const VectorRootSpace& rhs){

    // this function does not check the equality of root space
    // because *this is may defined invalid
    
    RootSpace V(rhs.type(), rhs.rank());
    space_ = V;
    simpleCoefficients_ = rhs.simpleCoefficients();
    fundamentalCoefficients_ = rhs.fundamentalCoefficients();
    
    return *this;
}


}
