#include <iostream>
#include <boost/numeric/ublas/io.hpp>

#include "gweyl.hpp"

int main(int argc, char** argv)
{
    //std::cout << argv[0] << " and " << argv[1] << " and " << argv[2] << std::endl;


    char t = argv[1][0];

    //std::cout << "Type is " << t << std::endl;

    gweyl::Type X;
    switch (t){
    case 'A':
        X=gweyl::Type::A;
        break;
    case 'B':
        X=gweyl::Type::B;
        break;
    case 'C':
        X=gweyl::Type::C;
        break;
    case 'D':
        X=gweyl::Type::D;
        break;
    case 'E':
        X=gweyl::Type::E;
        break;                
    case 'F':
        X=gweyl::Type::F;
        break;
    case 'G':
        X=gweyl::Type::G;
        break;        
    default:
        std::cout << "Error type " << std::to_string(t);
        return -1;
    }

    unsigned n = atoi(argv[2]);

    try {
        //gweyl::matrix CarMat = gweyl::CartanMatrix(X, n);
        gweyl::Cartan T(X, n);
        gweyl::matrix CarMat = T.CartanMatrix();
        std::cout << CarMat << std::endl;
    }catch (std::exception &e){
        std::cout << "Exeption is caught \n what(): ";
        std::cout << e.what();
        std::cout << "\nError test CartanMatrix" << std::endl;
    }
    
    return 0;
}
