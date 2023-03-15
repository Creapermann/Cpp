#include <array>
#include <cmath>
#include <iostream>
#include <random>

constexpr int n = 100;
const double e = std::exp(1.0);

bool findBestCandidate(std::array<int, n> candidates)
{
    int sampleSize = std::round(n/e);
    
    int bestCandidateInSampleSize = 0;
    for(int i = 0; i < sampleSize; ++i)
    {
        if(candidates[i] > candidates[bestCandidateInSampleSize])
            bestCandidateInSampleSize = i;
    }
    
    for(int i = sampleSize; i < n; ++i)
    {
        if(candidates[i] >= candidates[bestCandidateInSampleSize])
            return true;
    }
    
    return false;
}

int main()
{
    int avg = 0;
    
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,n*n+1);
    
    for(int i = 0; i < 1000; ++i)
    {
        for(int k = 0; k < 100; ++k)
        {
            std::array<int, n> candidates;
            for(int s = 0; s < n; ++s)
            {
                candidates[s] = dist(rng);
            }
            
            if(findBestCandidate(candidates))
                ++avg;
        }
    }
    
    double probablity = (double)avg/(double)1000;
    std::cout << "Chance: " << 100 - probablity << "\n";
    
    return 0;
}