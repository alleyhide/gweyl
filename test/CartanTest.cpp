/**
 * @file   CartanTest.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/09/01
 
 * 
 * @brief  for the tests of class Cartan
 * 
 * Released under the MIT license
 */
#include <iostream>

#include "gweyl.hpp"

int main(void){

    
    try {
        
        gweyl::Cartan S(gweyl::Type::A, 3);
        gweyl::Cartan T(gweyl::Type::A, 3);
        gweyl::Cartan U(gweyl::Type::B, 3);
        gweyl::Cartan V(gweyl::Type::A, 4);
        
        // test operator =
        if (S == T){
            ;//���⤷�ʤ�
        }else{
            std::string msg("test == ");
            std::runtime_error e(msg);
            throw e;
        }

        // test operator !=
        if (S != U){
            ;// ���⤷�ʤ�
        }else{
            std::string msg("test != ");
            std::runtime_error e(msg);
            throw e;
        }

        if (S != V){
            ;// ���⤷�ʤ�
        }else{
            std::string msg("test != ");
            std::runtime_error e(msg);
            throw e;
        }

        // ����
        S = T;
        S = U;
        S = V;
        S = S;
        
    }catch (std::exception &e){
        std::cout << "Error\n what(): ";
        std::cout << e.what();
        std::cout << std::endl;
        return -1;
    }

    return 0;
}
