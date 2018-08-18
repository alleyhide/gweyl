/**
 * @file   Vector.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/07/07
 * 
 * @brief  class Vector
 * 
 * 
 */
#include <iostream>
#include <boost/numeric/ublas/io.hpp>

#include "gweyl.hpp"

namespace gweyl{

struct VectorRootSpace::Impl {
    RootSpace space_;
    NumberVector simpleCoefficients_;///< coefficients for simple roots coordinate
    NumberVector fundamentalCoefficients_;///< coefficients for fundamental weights coordinate
};

VectorRootSpace::VectorRootSpace(Type X, NumberVector& v, Coordinate c)    
    : pImpl(std::make_unique<Impl>())
{
    RootSpace V(X, v.size());

    pImpl->space_ = V;
    
    if (c == Coordinate::simple){
        pImpl->simpleCoefficients_ = v;
        matrix A = pImpl->space_.CartanMatrix();
        pImpl->fundamentalCoefficients_ = prod(A, v);
    }else {
        matrix P = pImpl->space_.InverseCartanMatrix();
        pImpl->simpleCoefficients_ = prod(P, v);
        pImpl->fundamentalCoefficients_ = v;
    }
}

VectorRootSpace::VectorRootSpace(): pImpl(std::make_unique<Impl>())
{
}

VectorRootSpace::~VectorRootSpace(){
}

VectorRootSpace::VectorRootSpace(const VectorRootSpace& rhs): pImpl(std::make_unique<Impl>())
{
    RootSpace V(rhs.type(), rhs.rank());
    pImpl->space_ = V;
    pImpl->simpleCoefficients_ = rhs.simpleCoefficients();
    pImpl->fundamentalCoefficients_ = rhs.fundamentalCoefficients();
}

VectorRootSpace& VectorRootSpace::operator=(const VectorRootSpace& rhs){

    // this function does not check the equality of root space
    // because *this is may defined invalid
    
    RootSpace V(rhs.type(), rhs.rank());
    pImpl->space_ = V;
    pImpl->simpleCoefficients_ = rhs.simpleCoefficients();
    pImpl->fundamentalCoefficients_ = rhs.fundamentalCoefficients();
    
    return *this;
}


void VectorRootSpace::printf(){
    std::cout << "simple " << pImpl->simpleCoefficients_ << std::endl;
    std::cout << "fundamental " << pImpl->fundamentalCoefficients_ << std::endl;
}

NumberVector VectorRootSpace::simpleCoefficients() const{
    return pImpl->simpleCoefficients_;
}

NumberVector VectorRootSpace::simpleCoefficients(){
    return pImpl->simpleCoefficients_;
}

NumberVector VectorRootSpace::fundamentalCoefficients() const{
    return pImpl->fundamentalCoefficients_;
}

NumberVector VectorRootSpace::fundamentalCoefficients(){
    return pImpl->fundamentalCoefficients_;
}



Type VectorRootSpace::type(){
    return pImpl->space_.type();
}


Type VectorRootSpace::type() const{
    return pImpl->space_.type();
}


unsigned VectorRootSpace::rank(){
    return pImpl->space_.rank();
}

unsigned VectorRootSpace::rank() const{
    return pImpl->space_.rank();
}

bool VectorRootSpace::isInSameSpace(const VectorRootSpace& rhs){
    if (this->type() != rhs.type()){
        return false;
    }

    if (rank() != rhs.rank()){
        return false;
    }
    return true;
}

bool VectorRootSpace::operator==(const VectorRootSpace& rhs){

    if (!isInSameSpace(rhs)){
        return false;
    }
    
    if (!equal(pImpl->fundamentalCoefficients_, rhs.fundamentalCoefficients())){
        return false;
    }

    return true;
}

bool VectorRootSpace::operator!=(const VectorRootSpace& rhs){
    return !(*this == rhs);
}


VectorRootSpace& VectorRootSpace::operator+=(const VectorRootSpace& rhs){

    if (!isInSameSpace(rhs)){
        std::string msg{"+= of VectorRootSpace error "};
        msg += "LHS ";
        msg += std::to_string(static_cast<int>(type()));
        msg += " ";
        msg += std::to_string(rank());
        msg += ", RHS ";
        msg += std::to_string(static_cast<int>(rhs.type()));
        msg += " ";
        msg += std::to_string(rhs.rank());
        std::runtime_error e(msg);
        throw e;
    }

    pImpl->simpleCoefficients_ += rhs.simpleCoefficients();
    pImpl->fundamentalCoefficients_ += rhs.fundamentalCoefficients();

    return *this;
}

VectorRootSpace& VectorRootSpace::operator-=(const VectorRootSpace& rhs){

    if (!isInSameSpace(rhs)){
        std::string msg{"-= of VectorRootSpace error "};
        msg += "LHS ";
        msg += std::to_string(static_cast<int>(type()));
        msg += " ";
        msg += std::to_string(rank());
        msg += ", RHS ";
        msg += std::to_string(static_cast<int>(rhs.type()));
        msg += " ";
        msg += std::to_string(rhs.rank());
        std::runtime_error e(msg);
        throw e;
    }

    pImpl->simpleCoefficients_ -= rhs.simpleCoefficients();
    pImpl->fundamentalCoefficients_ -= rhs.fundamentalCoefficients();

    return *this;
}

VectorRootSpace& VectorRootSpace::operator*=(rational r){
    pImpl->simpleCoefficients_ *= r;
    pImpl->fundamentalCoefficients_ *= r;

    return *this;
}

bool VectorRootSpace::dominant(){

    NumberVector nv = fundamentalCoefficients();
    for (rational x : nv){
        if (x < 0){
            return false;
        }
    }
    
    return true;
}

bool VectorRootSpace::integral(){

    NumberVector nv = fundamentalCoefficients();
    for (rational x : nv){
        if (x.denominator() != 1){
            return false;
        }
    }
    
    return true;
}

bool VectorRootSpace::isDominantIntegral(){
    return ((dominant()) && (integral()));
}

VectorRootSpace operator+(const VectorRootSpace& v1, const VectorRootSpace& v2){
    VectorRootSpace w(v1);
    w += v2;
    return w;
}


VectorRootSpace operator-(const VectorRootSpace& v1, const VectorRootSpace& v2){
    VectorRootSpace w(v1);
    w -= v2;
    return w;
}

VectorRootSpace operator*(const VectorRootSpace& v1, const rational r){
    VectorRootSpace w(v1);
    w *= r;
    return w;
}


VectorRootSpace operator*(const rational r, const VectorRootSpace& v1){
    VectorRootSpace w(v1);
    w *= r;
    return w;
}



}
