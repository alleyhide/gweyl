/**
 * @file   Cartan.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/04/30
 * 
 * @brief  class Cartan
 * 
 * 
 */
#include "gweyl.hpp"
#include "gweyl_private.hpp"

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
        msg += "type:F, n:";
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

Cartan::Cartan(Type X, unsigned n):
    X_(X), rank_(n)
{
    CartanTypeCheckFunctionTable[X_](n);
    return;
}

Cartan::Cartan(){
}

Cartan::~Cartan(){

}

Type Cartan::type() const {
    return X_;
}

Type Cartan::type(){
    return type();
}

unsigned Cartan::rank() const {
    return rank_;
}

unsigned Cartan::rank(){
    return rank();
}

matrix Cartan::CartanMatrix(){
    return gweyl::CartanMatrix(X_, rank_);
}

matrix Cartan::InverseCartanMatrix(){
    return gweyl::InverseCartanMatrix(X_, rank_);
}

Vector Cartan::SimpleRoot(unsigned i){
    NumberVector nv(rank_);
    nv(i-1) = 1;
    Vector v(X_, nv, Coordinate::simple);
    
    return v;
}

Vector Cartan::FundamentalWeight(unsigned i){
    NumberVector nv(rank_);
    nv(i-1) = 1;
    Vector v(X_, nv, Coordinate::simple);
    
    return v;
}

bool Cartan::operator==(const Cartan &rhs){
    return ((X_ == rhs.type()) && (rank_ == rhs.rank()));
}

bool Cartan::operator!=(const Cartan &rhs){
    return !(*this == rhs);
}

#if 0
bool operator==(const Cartan &X, const Cartan &Y){
    return ((X.type() == Y.type()) && (X.rank() == Y.rank()));
}

bool operator!=(const Cartan &X, const Cartan &Y){
    return !(X == Y);
}
#endif


}
