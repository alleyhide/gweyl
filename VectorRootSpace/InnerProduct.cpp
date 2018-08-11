/**
 * @file   InnerProduct.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/04/30
 * 
 * @brief  inner product of root space
 * 
 * 
 */
#include "gweyl.hpp"
#include "gweyl_private.hpp"


namespace gweyl{

//
// inner product for simply laced root space (A, B, D, E)
//
std::function<rational(Vector&, Vector&)> InnerProductSimplyLaced
= [](Vector& v, Vector& w){
    return inner_prod(v.simpleCoefficients(), w.fundamentalCoefficients());
};

//
// inner product for type B root space
//
std::function<rational(Vector&, Vector&)> InnerProductB
= [](Vector& v, Vector& w){
    NumberVector wNew = w.fundamentalCoefficients();

    unsigned n = wNew.size();
    wNew(n-1) *= rational(1,2);
    
    return inner_prod(v.simpleCoefficients(), wNew);
};

//
// inner product for type C root space
//

std::function<rational(Vector&, Vector&)> InnerProductC
= [](Vector& v, Vector& w){
    NumberVector wNew = w.fundamentalCoefficients();

    unsigned n = wNew.size();
    wNew(n-1) *= rational(2);
    
    return inner_prod(v.simpleCoefficients(), wNew);
};

//
// inner product for type F root space
//

std::function<rational(Vector&, Vector&)> InnerProductF
= [](Vector& v, Vector& w){
    NumberVector wNew = w.fundamentalCoefficients();

    wNew(2) *= rational(1,2);
    wNew(3) *= rational(1,2);
    
    return inner_prod(v.simpleCoefficients(), wNew);
};

//
// inner product for type G root space
//

std::function<rational(Vector&, Vector&)> InnerProductG
= [](Vector& v, Vector& w){
    NumberVector wNew = w.fundamentalCoefficients();

    wNew(1) *= rational(3);
    
    return inner_prod(v.simpleCoefficients(), wNew);
};

//
// table of inner product functions
//
std::map<gweyl::Type, std::function<rational(Vector&, Vector&)>> InnerProductFunctionTable{
    {Type::A, InnerProductSimplyLaced},
    {Type::B, InnerProductB},
    {Type::C, InnerProductC},
    {Type::D, InnerProductSimplyLaced},
    {Type::E, InnerProductSimplyLaced},
    {Type::F, InnerProductF},
    {Type::G, InnerProductG},    
};

rational InnerProduct(Vector& v, Vector& w){
    return InnerProductFunctionTable[v.type()](v, w);
}


}