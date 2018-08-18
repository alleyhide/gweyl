#include <iostream>
#include <boost/assign.hpp>

#include "gweyl.hpp"

using namespace gweyl;

struct RepData {
    IrreducibleRepresentation rep;
    bool calculated{false};
    std::vector<matrix> PositiveSingleRootVectorAction;
    std::vector<matrix> NegativeSingleRootVectorAction;
};

std::vector<RepData> g_Data;


class Representation {
public:
    Representation(){
    }
    ~Representation(){
    }

    Representation(VectorRootSpace& hw){
        IrreducibleRepresentation rep(hw);
        rep_ = rep;
    }

    
    
private:
    IrreducibleRepresentation rep_;
    
    bool calculated{false};
    std::vector<matrix> PositiveSingleRootVectorAction;
    std::vector<matrix> NegativeSingleRootVectorAction;
};




int main(int argc, char** argv){

    std::cout << "Hello gweyl!" << std::endl;
    
    try {
        


    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    return 0;
}
