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

struct Representation::Impl {
    VectorRootSpace highestweight_;
};

Representation::Representation(): pImpl(std::make_unique<Impl>()){
}

Representation::Representation(const Representation &rhs): pImpl(std::make_unique<Impl>()){
    pImpl->highestweight_ = rhs.highestweight();
}

Representation::Representation(VectorRootSpace& hw): pImpl(std::make_unique<Impl>()){
    pImpl->highestweight_ = hw;
}

Representation& Representation::operator=(const Representation& rhs){
    pImpl->highestweight_ = rhs.highestweight();
    return *this;
}

Representation::~Representation(){
}

Type Representation::type(){
    return pImpl->highestweight_.type();
}

Type Representation::type() const{
    return pImpl->highestweight_.type();
}

unsigned Representation::rank(){
    return pImpl->highestweight_.rank();
}

unsigned Representation::rank() const{
    return pImpl->highestweight_.rank();
}

VectorRootSpace Representation::highestweight(){
    return pImpl->highestweight_;
}

VectorRootSpace Representation::highestweight() const{
    return pImpl->highestweight_;
}

bool Representation::operator==(const Representation& rhs){
    return (pImpl->highestweight_ == rhs.highestweight());
}

bool Representation::operator!=(const Representation& rhs){
    return (pImpl->highestweight_ != rhs.highestweight());
}

int Representation::dimension(){
    // implement
    return 0;
}

}
