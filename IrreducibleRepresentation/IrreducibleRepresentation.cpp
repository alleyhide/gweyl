/**
 * @file   Representation.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/08/16
 * 
 * @brief  class Representation
 * 
 * 
 */
#include <map>
#include <memory>

#include "gweyl.hpp"

namespace gweyl{

struct IrreducibleRepresentation::Impl {
    VectorRootSpace highestweight_;
};

IrreducibleRepresentation::IrreducibleRepresentation(): pImpl(std::make_unique<Impl>()){
}

IrreducibleRepresentation::IrreducibleRepresentation(const IrreducibleRepresentation &rhs): pImpl(std::make_unique<Impl>()){
    pImpl->highestweight_ = rhs.highestweight();
}

IrreducibleRepresentation::IrreducibleRepresentation(VectorRootSpace& hw): pImpl(std::make_unique<Impl>()){
    if (!hw.isDominantIntegral()){
        std::string msg{"Irreducible representation error: highest weight must be dominant integral. "};
        std::runtime_error e(msg);
        throw e;
    }
    pImpl->highestweight_ = hw;
}

IrreducibleRepresentation& IrreducibleRepresentation::operator=(const IrreducibleRepresentation& rhs){
    pImpl->highestweight_ = rhs.highestweight();
    return *this;
}

IrreducibleRepresentation::~IrreducibleRepresentation(){
}

Type IrreducibleRepresentation::type(){
    return pImpl->highestweight_.type();
}

Type IrreducibleRepresentation::type() const{
    return pImpl->highestweight_.type();
}

unsigned IrreducibleRepresentation::rank(){
    return pImpl->highestweight_.rank();
}

unsigned IrreducibleRepresentation::rank() const{
    return pImpl->highestweight_.rank();
}

VectorRootSpace IrreducibleRepresentation::highestweight(){
    return pImpl->highestweight_;
}

VectorRootSpace IrreducibleRepresentation::highestweight() const{
    return pImpl->highestweight_;
}

bool IrreducibleRepresentation::operator==(const IrreducibleRepresentation& rhs){
    return (pImpl->highestweight_ == rhs.highestweight());
}

bool IrreducibleRepresentation::operator!=(const IrreducibleRepresentation& rhs){
    return (pImpl->highestweight_ != rhs.highestweight());
}

int IrreducibleRepresentation::dimension(){
    RootSpace RS(type(), rank());

    std::vector<VectorRootSpace> proots = RS.PositiveRoots();
    VectorRootSpace rho = RS.Rho();
    VectorRootSpace hw_rho = pImpl->highestweight_ + rho;
    
    // Weyl dimension formula
 
    rational numerator = 1;
    rational denominator = 1;
    for (VectorRootSpace& x: proots){
        numerator *= InnerProduct(hw_rho, x);
        denominator *= InnerProduct(rho, x);
    }
    rational dim =numerator / denominator;

    if (dim.denominator() != 1){
        std::string msg{"Dimension formula error. The dimesion does not become integer."};
        msg += std::to_string(dim.numerator());
        msg += "/";
        msg += std::to_string(dim.denominator());
        std::runtime_error e(msg);
        throw e;
    }
    
    int dim_int = dim.numerator();
    
    return dim_int;
}

}
