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
#include "gweyl_private.hpp"

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
    // implement
    return 0;
}

}
