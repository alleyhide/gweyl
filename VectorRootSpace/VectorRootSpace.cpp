/**
 * @file   VectorRootSpace.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/07/07
 * 
 * @brief  class VectorRootSpace
 * 
 * 
 */



#include "gweyl.hpp"
#include "gweyl_private.hpp"


namespace gweyl{

//
// constructor of VectorRootSpace is implemented in ../Cartan/VectorRootSpace.cpp
// because of dependencies in cmake
//


void VectorRootSpace::printf(){
    std::cout << "simple " << simpleCoefficients_ << std::endl;
    std::cout << "fundamental " << fundamentalCoefficients_ << std::endl;
}

NumberVector VectorRootSpace::simpleCoefficients() const{
    return simpleCoefficients_;
}

NumberVector VectorRootSpace::simpleCoefficients(){
    return simpleCoefficients();
}

NumberVector VectorRootSpace::fundamentalCoefficients() const{
    return fundamentalCoefficients_;
}

NumberVector VectorRootSpace::fundamentalCoefficients(){
    return fundamentalCoefficients();
}



Type VectorRootSpace::type(){
    return space_.type();
}


Type VectorRootSpace::type() const{
    return space_.type();
}


unsigned VectorRootSpace::rank(){
    return space_.rank();
}

unsigned VectorRootSpace::rank() const{
    return space_.rank();
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
    
    if (!equal(fundamentalCoefficients_, rhs.fundamentalCoefficients())){
        return false;
    }

    return true;
}

bool VectorRootSpace::operator!=(const VectorRootSpace& rhs){
    return !(*this == rhs);
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

    simpleCoefficients_ += rhs.simpleCoefficients();
    fundamentalCoefficients_ += rhs.fundamentalCoefficients();

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

    simpleCoefficients_ -= rhs.simpleCoefficients();
    fundamentalCoefficients_ -= rhs.fundamentalCoefficients();

    return *this;
}

VectorRootSpace& VectorRootSpace::operator*=(rational r){
    simpleCoefficients_ *= r;
    fundamentalCoefficients_ *= r;

    return *this;
}

}

