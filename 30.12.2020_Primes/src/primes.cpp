#include <iostream>
#include <vector>

#include "primes.hpp"


GetPrimes::GetPrimes(){};



bool checkIfPrime(int a);           //Function Prototype

TIntVec GetPrimes::findAllPrimes(int n){
    TIntVec primesVec;

    for(auto i = 0; i < n; i++){
        if(checkIfPrime(i)){
            primesVec.emplace_back(i);
        }
    }

    return primesVec;
}


bool checkIfPrime(int a){

    if(a == 2)
        return true;
    if(a < 2)
        return false;
    int i;
    for(i = 2; i <= (a/2); i++){
        if(a % i == 0){
            return false;
        }
    }
    if(i != a)
        return true;
    else
        return false;
}
