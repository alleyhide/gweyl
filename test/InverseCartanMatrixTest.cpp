#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){

    char t = argv[1][0];

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

    
    bool myCheck=false;
    if (argc == 4){
        myCheck = true;
    }

    try {
        gweyl::Cartan T(X, n);
        
        gweyl::matrix P = T.InverseCartanMatrix();

        if (myCheck == true){
            gweyl::matrix A = T.CartanMatrix();
            gweyl::matrix testmat1 = prod(A, P);
            gweyl::matrix testmat2 = prod(P, A);
            
            //std::cout << testmat1 << std::endl;
            //std::cout << testmat2 << std::endl;

            unsigned m = A.size1();
            unsigned n = A.size2();
            for (unsigned i = 0;i<m; ++i){
                for (unsigned j=0;j<n; ++j){
                    if (i==j){
                        if (testmat1(i,j) != 1){
                            std::runtime_error e("AP is not identity matrix");
                            throw e;
                        }
                        if (testmat2(i,j) != 1){
                            std::runtime_error e("PA is not identity matrix");
                            throw e;
                        }
                    }else {
                        if (testmat1(i,j) != 0){
                            std::runtime_error e("AP is not identity matrix");
                            throw e;
                        }
                        if (testmat2(i,j) != 0){
                            std::runtime_error e("PA is not identity matrix");
                            throw e;
                        }
                    }
                }
            }
            
        }

        std::cout << P << std::endl;
        
    } catch (std::exception &e){
        std::cout << "Exeption is caught \n what(): ";
        std::cout << e.what();
        std::cout << "\nError test CartanMatrix InverseCartanMatrix" << std::endl;
    }
    
    return 0;
}
