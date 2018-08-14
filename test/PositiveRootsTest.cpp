#include <iostream>

#include "gweyl.hpp"

int main(int argc, char** argv){


    try {

        if (1){
            ;
        }else {
            std::string msg("Positive Roots  0001");
            std::runtime_error e(msg);
            throw e;
        }

        
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    
    return 0;
}
