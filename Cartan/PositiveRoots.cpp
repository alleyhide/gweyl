/**
 * @file   PositiveRoots.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/04/30
 * 
 * @brief  Positive Roots
 * 
 * 
 */

#include <map>
#include <functional>

#include "gweyl.hpp"

namespace gweyl {

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsA = [](int n){
    std::vector<VectorRootSpace> proots;
    // implement
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsB = [](int n){
    std::vector<VectorRootSpace> proots;
    // implement
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsC = [](int n){
    std::vector<VectorRootSpace> proots;
    // implement
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsD = [](int n){
    std::vector<VectorRootSpace> proots;
// implement
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsE = [](int n){
    std::vector<VectorRootSpace> proots;
    // implement
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsF = [](int n){
    std::vector<VectorRootSpace> proots;
    // implement
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsG = [](int n){
    std::vector<VectorRootSpace> proots;
    // implement
    return proots;
};

std::map<gweyl::Type, std::function<std::vector<gweyl::VectorRootSpace>(int)> >
         PositiveRootsFunctionTable {
    {Type::A, PositiveRootsA},
    {Type::B, PositiveRootsB},
    {Type::C, PositiveRootsC},
    {Type::D, PositiveRootsD},
    {Type::E, PositiveRootsE},
    {Type::F, PositiveRootsF},
    {Type::G, PositiveRootsG},

};

std::vector<VectorRootSpace> Cartan::PositiveRoots(void){
    return PositiveRootsFunctionTable[type()](rank());
}

}



