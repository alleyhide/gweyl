/**
 * @file   Cartan.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/04/30
 * 
 * @brief  class Cartan
 * 
 * Released under the MIT license
 */
#include <map>
#include <memory>

#include "gweyl.hpp"

namespace gweyl{

//
// Check 'n' for type A
// @param[in] n
//
std::function<void(int)> checkCartanTypeA = [](int n){
    if (n < 1){
        std::string msg{"Cartan classification error "};
        msg += "type:A, n:";
        msg += std::to_string(n);
        msg += "\n Remark n must be >= 1";
        std::runtime_error e(msg);
        throw e;
    }
    return;
};

//
// Check 'n' for type B
// @param[in] n
//
std::function<void(int)> checkCartanTypeB = [](int n){
    if (n<2){
        std::string msg{"Cartan classification error "};
        msg += "type:B, n:";
        msg += std::to_string(n);
        msg += "\n Remark n must be >= 2";
        std::runtime_error e(msg);
        throw e;
    }
    return;
};

//
// Check 'n' for type C
// @param[in] n
//
std::function<void(int)> checkCartanTypeC = [](int n){
    if (n < 2){
        std::string msg{"Cartan classification error "};
        msg += "type:C, n:";
        msg += std::to_string(n);
        msg += "\n Remark n must be >= 2";
        std::runtime_error e(msg);
        throw e;
    }
    
    return;
};

//
// Check 'n' for type D
// @param[in] n
//
std::function<void(int)> checkCartanTypeD = [](int n){
    if (n < 4){
        std::string msg{"Cartan classification error "};
        msg += "type:D, n:";
        msg += std::to_string(n);
        msg += "\n Remark n must be >= 4";
        std::runtime_error e(msg);
        throw e;
    }

    return;
};

//
// Check 'n' for type E
// @param[in] n
//
std::function<void(int)> checkCartanTypeE = [](int n){
    if ((n < 6) || (n > 8)){
        std::string msg{"Cartan classification error "};
        msg += "type:E, n:";
        msg += std::to_string(n);
        msg += "\n Remark n must be 6,7 or 8";
        std::runtime_error e(msg);
        throw e;
    }

    return;
};

//
// Check 'n' for type F
// @param[in] n
//
std::function<void(int)> checkCartanTypeF = [](int n){

    if (n != 4){
        std::string msg{"Cartan classification error "};
        msg += "type:F, n:";
        msg += std::to_string(n);
        msg += "\n Remark n must be 4";
        std::runtime_error e(msg);
        throw e;
    }

    return;
};

//
// Check 'n' for type G
// @param[in] n
//
std::function<void(int)> checkCartanTypeG = [](int n){
    if (n != 2){
        std::string msg{"Cartan classification error "};
        msg += "type:G, n:";
        msg += std::to_string(n);
        msg += "\n Remark n must be 2";
        std::runtime_error e(msg);
        throw e;
    }
        
    return;
};

//
// table of check functions
//
std::map<gweyl::Type, std::function<void(int)>> CartanTypeCheckFunctionTable {
    {Type::A, checkCartanTypeA},
    {Type::B, checkCartanTypeB},
    {Type::C, checkCartanTypeC},
    {Type::D, checkCartanTypeD},
    {Type::E, checkCartanTypeE},
    {Type::F, checkCartanTypeF},
    {Type::G, checkCartanTypeG},    
};

struct Cartan::Impl {
    Type X_{Type::invalid};
    unsigned rank_{0};
};

Cartan::Cartan(Type X, unsigned n): pImpl(std::make_unique<Impl>())
{
    CartanTypeCheckFunctionTable[X](n);
    pImpl->X_ = X;
    pImpl->rank_ = n;
    return;
}

Cartan::Cartan(const Cartan &rhs): pImpl(std::make_unique<Impl>()){
    pImpl->X_ = rhs.type();
    pImpl->rank_ = rhs.rank();
}

Cartan& Cartan::operator=(const Cartan& rhs){
    pImpl->X_ = rhs.type();
    pImpl->rank_ = rhs.rank();
    return *this;
}


Cartan::Cartan(): pImpl(std::make_unique<Impl>()){
}

Cartan::~Cartan(){

}

Type Cartan::type() const {
    return pImpl->X_;
}

Type Cartan::type(){
    return pImpl->X_;
}

unsigned Cartan::rank() const {
    return pImpl->rank_;
}

unsigned Cartan::rank(){
    return pImpl->rank_;
}

matrix Cartan::CartanMatrix(){
    return gweyl::CartanMatrix(type(), rank());
}

matrix Cartan::InverseCartanMatrix(){
    return gweyl::InverseCartanMatrix(type(), rank());
}

VectorRootSpace Cartan::SimpleRoot(unsigned i){
    NumberVector nv(rank());
    nv(i-1) = 1;
    VectorRootSpace v(type(), nv, Coordinate::simple);
    
    return v;
}

VectorRootSpace Cartan::FundamentalWeight(unsigned i){
    NumberVector nv(rank());
    nv(i-1) = 1;
    VectorRootSpace v(type(), nv, Coordinate::fundamental);
    
    return v;
}

VectorRootSpace Cartan::Zero(){
    NumberVector nv(rank());
    VectorRootSpace v(type(), nv, Coordinate::fundamental);
    return v;
}

VectorRootSpace Cartan::Rho(){
    NumberVector nv(rank());
    for (rational &x: nv){
        x = 1;
    }
    VectorRootSpace v(type(), nv, Coordinate::fundamental);

    return v;
}

bool Cartan::operator==(const Cartan &rhs){
    return ((type() == rhs.type()) && (rank() == rhs.rank()));
}

bool Cartan::operator!=(const Cartan &rhs){
    return !(*this == rhs);
}



}
