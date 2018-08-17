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
#include <boost/assign.hpp>

#include "gweyl.hpp"

namespace gweyl {

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsA = [](int n){
    std::vector<VectorRootSpace> proots;

    // a_i + .. + a_j
    for (int i=0; i<n; ++i){
        for (int j=i; j<n; ++j){
            NumberVector nv(n);
            for (int k=i; k<j+1; ++k){
                nv(k) = 1;
            }
            VectorRootSpace v(Type::A, nv, Coordinate::simple);
            proots.push_back(v);
        }
    }

    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsB = [](int n){
    std::vector<VectorRootSpace> proots;

    // a_i + .. + a_j
    for (int i=0; i<n; ++i){
        for (int j=i; j<n; ++j){
            NumberVector nv(n);
            for (int k=i; k<j+1; ++k){
                nv(k) = 1;
            }
            VectorRootSpace v(Type::B, nv, Coordinate::simple);
            proots.push_back(v);
        }
    }

    // a_i + .. + a_{j-1} + 2a_j + .. + 2a_n
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
            NumberVector nv(n);
            for (int k=i; k<j; ++k){
                nv(k) = 1;
            }
            for (int k=j; k<n;++k){
                nv(k) =2;
            }
            VectorRootSpace v(Type::B, nv, Coordinate::simple);
            proots.push_back(v);
        }
    }
    
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsC = [](int n){
    std::vector<VectorRootSpace> proots;

    // a_i + .. + a_j
    for (int i=0; i<n; ++i){
        for (int j=i; j<n; ++j){
            NumberVector nv(n);
            for (int k=i; k<j+1; ++k){
                nv(k) = 1;
            }
            VectorRootSpace v(Type::C, nv, Coordinate::simple);
            proots.push_back(v);
        }
    }

    // a_i + .. + a_{j-1} + 2a_j + .. + 2a_{n-1} + 2a_n
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n-1; ++j){
            NumberVector nv(n);
            for (int k=i; k<j; ++k){
                nv(k) = 1;
            }
            for (int k=j; k<n-1;++k){
                nv(k) =2;
            }
            nv(n-1) = 1;
            VectorRootSpace v(Type::C, nv, Coordinate::simple);
            proots.push_back(v);
        }
    }

    // 2a_i + .. + 2a_{n-1} + a_n
    for (int i=0; i<n-1; ++i){
        NumberVector nv(n);
        for (int j=i; j<n-1; ++j){
            nv(j) = 2;
        }
        nv(n-1) = 1;
        VectorRootSpace v(Type::C, nv, Coordinate::simple);
        proots.push_back(v);
    }
    return proots;
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsD = [](int n){
    std::vector<VectorRootSpace> proots;

    // a_i + .. + a_j
    for (int i=0; i<n-1; ++i){
        for (int j=i; j<n-1; ++j){
            NumberVector nv(n);
            for (int k=i; k<j+1; ++k){
                nv(k) = 1;
            }
            VectorRootSpace v(Type::D, nv, Coordinate::simple);
            proots.push_back(v);
        }
    }

    // a_i + .. + a_n
    for (int i=0; i<n-2; ++i){
        NumberVector nv(n);
        for (int j=i; j<n; ++j){
            nv(j) = 1;
        }
        VectorRootSpace v(Type::D, nv, Coordinate::simple);
        proots.push_back(v);
    }

    // a_n
    {
        NumberVector nv(n);
        nv(n-1) = 1;
        VectorRootSpace v(Type::D, nv, Coordinate::simple);
        proots.push_back(v);
    }

    // a_i + .. + a_{n-2} + a_n
    for (int i=0; i<n-2; ++i){
        NumberVector nv(n);
        for (int j=i; j<n; ++j){
            nv(j) = 1;
        }
        nv(n-2) = 0;
        VectorRootSpace v(Type::D, nv, Coordinate::simple);
        proots.push_back(v);
    }

    // a_i + .. + a_{j-1} + 2a_j + .. + 2a_{n-2} + a_{n-1} + 2a_n
    for (int i=0; i<n-3; ++i){
        for (int j=i+1; j<n-2; ++j){
            NumberVector nv(n);
            for (int k=i; k<j; ++k){
                nv(k) = 1;
            }
            for (int k=j; k<n-2;++k){
                nv(k) = 2;
            }
            nv(n-2) = 1;
            nv(n-1) = 1;
            
            VectorRootSpace v(Type::D, nv, Coordinate::simple);
            proots.push_back(v);
        }
    }

    
    return proots;
};

std::vector<std::vector<gweyl::rational> >
PositiveRootsE6_table {
    // left D5
    {1,0,0,0,0,0},
    {1,0,1,0,0,0},
    {1,0,1,1,0,0},//
    {1,0,1,1,1,0},
    {0,0,1,0,0,0},
    {0,0,1,1,0,0},
    {0,0,1,1,1,0},
    {0,0,0,1,0,0},
    {0,0,0,1,1,0},
    {0,0,0,0,1,0},
    {1,1,1,1,1,0},
    {0,1,1,1,1,0},
    {0,1,0,1,1,0},
    {0,1,0,0,0,0},
    {1,1,1,1,0,0},
    {0,1,1,1,0,0},
    {0,1,0,1,0,0},
    {1,1,2,2,1,0},
    {1,1,1,2,1,0},    
    {0,1,1,2,1,0},
    // right D5
    {0,0,0,0,0,1},
    {0,0,0,0,1,1},
    {0,0,0,1,1,1},    
    {0,0,1,1,1,1},
    {0,1,1,1,1,1},
    {0,1,0,1,1,1},
    {0,1,1,2,2,1},
    {0,1,1,2,1,1},
    // more E6
    {1,1,2,2,1,1},
    {1,1,1,2,1,1},
    {1,1,1,1,1,1},
    {1,0,1,1,1,1},
    {1,1,2,3,2,1},
    {1,1,1,2,2,1},
    {1,1,2,2,2,1},
    {1,2,2,3,2,1},
};

std::function<std::vector<VectorRootSpace>()> PositiveRootsE6 = [](){
    std::vector<VectorRootSpace> proots;
    
    for (std::vector<gweyl::rational>& x : PositiveRootsE6_table){
        NumberVector nv(x.size());
        std::copy(x.begin(), x.end(), nv.begin());
        VectorRootSpace v(Type::E, nv, Coordinate::simple);
        proots.push_back(v);
    }
    return proots;
};
    
std::vector<std::vector<gweyl::rational> >
PositiveRootsE7_table {
    {1,0,0,0,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,1,1,0,0,0},
    {0,0,1,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,0,0,1,0,0,0},
    {1,1,2,2,1,1,0},
    {1,1,1,2,1,1,0},
    {1,1,1,1,1,1,0},
    {0,1,1,2,1,1,0},
    {0,1,1,1,1,1,0},
    {0,1,0,1,1,1,0},
    {1,0,1,1,0,0,0},
    {0,1,1,1,0,0,0},
    {0,1,0,1,0,0,0},
    {0,1,0,0,0,0,0},
    {1,0,1,1,1,1,0},
    {0,0,1,1,1,1,0},
    {0,0,0,1,1,1,0},
    {0,0,0,0,1,1,0},
    {0,0,0,1,1,0,0},
    {1,1,2,3,2,1,0},
    {0,1,1,2,2,1,0},
    {1,1,1,2,2,1,0},
    {1,1,2,2,2,1,0},
    {0,0,0,0,1,0,0},
    {1,0,1,1,1,0,0},
    {0,0,1,1,1,0,0},
    {1,1,1,2,1,0,0},
    {1,1,1,1,1,0,0},
    {0,0,0,0,0,1,0},
    {1,1,2,2,1,0,0},
    {0,1,1,1,1,0,0},
    {0,1,1,2,1,0,0},
    {1,2,2,3,2,1,0},
    {0,1,0,1,1,0,0},
    //and more E7
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,1,1},
    {0,0,0,0,1,1,1},
    {1,1,2,2,2,2,1},
    {1,1,2,2,2,1,1},
    {1,1,2,2,1,1,1},
    {1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1},
    {1,1,2,3,3,2,1},
    {1,1,2,3,2,1,1},
    {1,1,2,3,2,2,1},
    {0,0,0,1,1,1,1},
    {1,1,1,2,2,1,1},
    {1,1,1,2,1,1,1},
    {1,1,1,2,2,2,1},
    {2,2,3,4,3,2,1},
    {1,2,2,4,3,2,1},
    {1,0,1,1,1,1,1},
    {0,1,1,1,1,1,1},
    {1,2,2,3,3,2,1},
    {1,2,2,3,2,1,1},
    {1,2,2,3,2,2,1},
    {0,1,0,1,1,1,1},
    {0,1,1,2,2,1,1},
    {0,1,1,2,1,1,1},
    {0,1,1,2,2,2,1},
    {1,2,3,4,3,2,1},
};


std::function<std::vector<VectorRootSpace>()> PositiveRootsE7 = [](){
    std::vector<VectorRootSpace> proots;

    for (std::vector<gweyl::rational>& x : PositiveRootsE7_table){
        NumberVector nv(x.size());
        std::copy(x.begin(), x.end(), nv.begin());
        VectorRootSpace v(Type::E, nv, Coordinate::simple);
        proots.push_back(v);
    }
    return proots;
};

    
std::vector<std::vector<gweyl::rational> >
PositiveRootsE8_table {
    {1,0,0,0,0,0,0,0},
    {1,0,1,0,0,0,0,0},
    {1,1,1,1,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,1,1,0,0,0,0},
    {0,0,0,1,0,0,0,0},
    {1,1,2,2,1,1,0,0},
    {1,1,1,2,1,1,0,0},
    {1,1,1,1,1,1,0,0},
    {0,1,1,2,1,1,0,0},
    {0,1,1,1,1,1,0,0},
    {0,1,0,1,1,1,0,0},
    {1,0,1,1,0,0,0,0},
    {0,1,1,1,0,0,0,0},
    {0,1,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {1,0,1,1,1,1,0,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,1,1,1,0,0},
    {0,0,0,0,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {1,1,2,3,2,1,0,0},
    {0,1,1,2,2,1,0,0},
    {1,1,1,2,2,1,0,0},
    {1,1,2,2,2,1,0,0},
    {0,0,0,0,1,0,0,0},
    {1,0,1,1,1,0,0,0},
    {0,0,1,1,1,0,0,0},
    {1,1,1,2,1,0,0,0},
    {1,1,1,1,1,0,0,0},
    {0,0,0,0,0,1,0,0},
    {1,1,2,2,1,0,0,0},
    {0,1,1,1,1,0,0,0},
    {0,1,1,2,1,0,0,0},
    {1,2,2,3,2,1,0,0},
    {0,1,0,1,1,0,0,0},
        //and more E7
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,1,1,0},
    {0,0,0,0,1,1,1,0},
    {1,1,2,2,2,2,1,0},
    {1,1,2,2,2,1,1,0},
    {1,1,2,2,1,1,1,0},
    {1,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,1,0},
    {1,1,2,3,3,2,1,0},
    {1,1,2,3,2,1,1,0},
    {1,1,2,3,2,2,1,0},
    {0,0,0,1,1,1,1,0},
    {1,1,1,2,2,1,1,0},
    {1,1,1,2,1,1,1,0},
    {1,1,1,2,2,2,1,0},
    {2,2,3,4,3,2,1,0},
    {1,2,2,4,3,2,1,0},
    {1,0,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {1,2,2,3,3,2,1,0},
    {1,2,2,3,2,1,1,0},
    {1,2,2,3,2,2,1,0},
    {0,1,0,1,1,1,1,0},
    {0,1,1,2,2,1,1,0},
    {0,1,1,2,1,1,1,0},
    {0,1,1,2,2,2,1,0},
    {1,2,3,4,3,2,1,0},
        //and more E8
    {2,2,3,4,3,2,1,1},
    {2,2,3,4,3,2,2,1},
    {0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,1,1},
    {2,3,4,6,5,4,3,2},
    {2,3,4,6,5,4,3,1},
    {2,3,4,6,5,4,2,1},
    {0,1,1,2,2,2,2,1},
    {0,1,1,2,2,2,1,1},
    {2,3,4,6,5,3,2,1},
    {0,1,1,2,2,1,1,1},
    {2,2,3,4,3,3,2,1},
    {0,0,0,0,0,1,1,1},
    {1,1,1,2,2,2,2,1},
    {1,1,1,2,2,2,1,1},
    {1,2,3,4,3,2,2,1},
    {1,2,3,4,3,2,1,1},
    {1,1,2,2,1,1,1,1},
    {1,2,3,4,3,3,2,1},
    {1,1,1,2,2,1,1,1},
    {1,2,2,4,4,3,2,1},
    {2,2,4,5,4,3,2,1},
    {2,3,3,5,4,3,2,1},
    {0,0,1,1,1,1,1,1},
    {0,1,0,1,1,1,1,1},
    {1,1,2,3,3,2,2,1},
    {1,1,2,3,3,2,1,1},
    {1,2,2,3,2,2,2,1},
    {1,2,2,3,2,2,1,1},
    {1,1,2,3,3,3,2,1},
    {1,0,1,1,1,1,1,1},
    {1,3,3,5,4,3,2,1},
    {1,2,2,3,2,1,1,1},
    {2,3,4,6,4,3,2,1},
    {2,3,4,5,4,3,2,1},
    {2,2,3,5,4,3,2,1},
    {2,2,3,4,4,3,2,1},
    {0,1,1,2,1,1,1,1},
    {0,1,1,1,1,1,1,1},
    {0,0,0,1,1,1,1,1},
    {0,0,0,0,1,1,1,1},
    {1,2,2,4,3,2,2,1},
    {1,2,2,3,3,2,2,1},
    {1,1,2,3,2,2,2,1},
    {1,1,2,2,2,2,2,1},
    {1,2,2,4,3,2,1,1},
    {1,2,2,3,3,2,1,1},
    {1,1,2,3,2,2,1,1},
    {1,1,2,2,2,2,1,1},
    {1,1,1,2,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,2,3,2,1,1,1},
    {1,1,2,2,2,1,1,1},
    {1,2,2,4,3,3,2,1},
    {1,2,2,3,3,3,2,1},
    {1,2,3,5,4,3,2,1},
    {1,2,3,4,4,3,2,1},
};


std::function<std::vector<VectorRootSpace>()> PositiveRootsE8 = [](){
    std::vector<VectorRootSpace> proots;

    for (std::vector<gweyl::rational>& x : PositiveRootsE8_table){
        NumberVector nv(x.size());
        std::copy(x.begin(), x.end(), nv.begin());
        VectorRootSpace v(Type::E, nv, Coordinate::simple);
        proots.push_back(v);
    }
    return proots;
};


std::map<int, std::function<std::vector<gweyl::VectorRootSpace>()> >
         PositiveRootsEFunctionTable {
    {6, PositiveRootsE6},
    {7, PositiveRootsE7},
    {8, PositiveRootsE8},
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsE = [](int n){
    return PositiveRootsEFunctionTable[n]();
};

std::vector<std::vector<gweyl::rational> >
PositiveRootsF_table {
    {1,1,1,0},
    {0,1,1,0},
    {0,0,1,0},
    {1,2,3,2},
    {1,2,2,0},
    {1,1,2,0},
    {2,3,4,2},
    {0,1,2,0},
    {1,3,4,2},
    {1,2,4,2},
    {1,0,0,0},
    {1,1,0,0},
    {0,1,2,2},
    {0,1,0,0},
    {1,1,2,2},
    {1,2,2,2},
    {1,2,3,1},
    {0,0,0,1},
    {1,2,2,1},
    {1,1,2,1},
    {0,0,1,1},
    {0,1,1,1},
    {1,1,1,1},
    {0,1,2,1},
};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsF = [](int n){
    std::vector<VectorRootSpace> proots;
    
    for (std::vector<gweyl::rational>& x : PositiveRootsF_table){
        NumberVector nv(x.size());
        std::copy(x.begin(), x.end(), nv.begin());
        VectorRootSpace v(Type::F, nv, Coordinate::simple);
        proots.push_back(v);
    }
    return proots;
};

std::vector<std::vector<gweyl::rational> >
PositiveRootsG_table { {1,0}, {0,1}, {1,1}, {2,1}, {3,1}, {3,2}};

std::function<std::vector<VectorRootSpace>(int)> PositiveRootsG = [](int n){
    
    std::vector<VectorRootSpace> proots;

    for (std::vector<gweyl::rational>& x : PositiveRootsG_table){
        NumberVector nv(x.size());
        std::copy(x.begin(), x.end(), nv.begin());
        VectorRootSpace v(Type::G, nv, Coordinate::simple);
        proots.push_back(v);
    }
    
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



