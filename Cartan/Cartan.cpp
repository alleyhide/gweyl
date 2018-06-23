#include "gweyl.hpp"
#include "gweyl_private.hpp"

namespace gweyl{

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

Cartan::~Cartan(){

}

matrix Cartan::CartanMatrix(){
    return gweyl::CartanMatrix(X_, rank_);
}

matrix Cartan::InverseCartanMatrix(){
    return gweyl::InverseCartanMatrix(X_, rank_);
}

}
