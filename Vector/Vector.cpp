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

#if 0
bool operator==(const matrix &X, const matrix &Y){
    return !(X != Y);
}


bool operator!=(const matrix &X, const matrix &Y){
    if (X.size1() != Y.size1()){
        return true;
    }

    if (X.size2() != Y.size2()){
        return true;
    }

    for (unsigned i=0; i<X.size1(); ++i){
        for (unsigned j=0; j<X.size2(); ++j){
            if (X(i, j) != Y(i, j)){
                return true;
            }
        }
    }
    
    return false;        
}

bool operator==(const NumberVector &v, const NumberVector &w){
    return !(v != w);
}

bool operator!=(const NumberVector &v, const NumberVector &w){
    if (v.size() != w.size()){
        return true;
    }

    for (unsigned i=0; i<v.size(); ++i){
        if (v(i) != w(i)){
            return true;
        }
    }
    return false;
}
#endif

bool equals(const matrix &X, const matrix &Y){
    if (X.size1() != Y.size1()){
        return false;
    }

    if (X.size2() != Y.size2()){
        return false;
    }

    for (unsigned i=0; i<X.size1(); ++i){
        for (unsigned j=0; j<X.size2(); ++j){
            if (X(i, j) != Y(i, j)){
                return false;
            }
        }
    }
    
    return true;        
}

bool equals(const NumberVector &v, const NumberVector &w){
    if (v.size() != w.size()){
        return false;
    }

    for (unsigned i=0; i<v.size(); ++i){
        if (v(i) != w(i)){
            return false;
        }
    }
    return true;
}


Vector::Vector(Type X, NumberVector& v, Coordinate c){
    X_ = X;
    rank_ = v.size();

    CartanMatrix_ = CartanMatrix();
    InverseCartanMatrix_ = InverseCartanMatrix();

    if (c == Coordinate::simple){
        simpleCoefficients_ = v;
        fundamentalCoefficients_ = prod(CartanMatrix_, v);
    }else {
        simpleCoefficients_ = prod(InverseCartanMatrix_, v);
        fundamentalCoefficients_ = v;
    }
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


}
