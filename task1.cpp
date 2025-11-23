
#include <iostream>
#include <benchmark/benchmark.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std; 
int sum = 0;
int sumMult = 0;
int sumSub = 0;
int sumBit = 0;
int sumDeps = 0;
int sumSkip = 0;
static void Part1(benchmark::State& state) {
    std::vector<int> A;
    std::vector<int> B;

    //srand(0); 
    for(int i = 0; i < 1000000; i++) {
        srand(0);
        A.push_back(rand());
        B.push_back(rand());
    }

    for (auto _ : state) { 
        for(int i = 0; i < 1000000; i++) {
            sum += A[i] + B[i];
            //benchmark::DoNotOptimize(sum);
        }
        benchmark::DoNotOptimize(sum);
    }
    //cout  << state.iterations();
}

static void Part2(benchmark::State& state) {
    std::vector<int> A;
    std::vector<int> B;

    //srand(0); 
    for(int i = 0; i < 1000000; i++) {
        srand(0);
        A.push_back(rand());
        B.push_back(rand());
    }

    for (auto _ : state) { 
        for(int i = 0; i < 1000000; i++) {
            sum += A[i] + B[i];
            sumMult += A[i] * B[i];
            sumBit += A[i] >> B[i];
            sumSub += A[i] - B[i];
        }
        benchmark::DoNotOptimize(sum);
        benchmark::DoNotOptimize(sumMult);
        benchmark::DoNotOptimize(sumBit);
        benchmark::DoNotOptimize(sumSub);
    }
    //cout  << state.iterations();
}

static void Part3(benchmark::State& state) {
    std::vector<int> A;
    std::vector<int> B;

    //srand(0); 
    for(int i = 0; i < 1000000; i++) {
        srand(0);
        A.push_back(rand());
        B.push_back(rand());
    }

    for (auto _ : state) { 
        for(int i = 0; i < 1000000; i++) {
            sumDeps += (A[i] + B[i]) * (A[i] - B[i]);
        }
        benchmark::DoNotOptimize(sumDeps);
        
    }
    //cout  << state.iterations();
}

static void Part4(benchmark::State& state) {
    std::vector<int> A;
    std::vector<int> B;

    //srand(0); 
    for(int i = 0; i < 1000000; i++) {
        srand(0);
        A.push_back(rand());
        B.push_back(rand());
    }

    for (auto _ : state) { 
        for(int i = 0; i < 1000000; i++) {
            if(A[i]<500000){
                ;
            }
            else{
                sumSkip += A[i] + B[i];
            }
        }
        benchmark::DoNotOptimize(sumSkip);
        
    }
    //cout  << state.iterations();
}


BENCHMARK(Part1);
BENCHMARK(Part2);
BENCHMARK(Part3);
BENCHMARK(Part4);
BENCHMARK_MAIN();


/*
#include <iostream>
#include <vector> 
#include <string> 
using namespace std; 
int sum; int main() { 
    vector<int> A {}; 
    vector<int> B {}; 
    for(int i =0; i < 1000000;i++) { 
        srand(time(0)); A.push_back(rand()); 
        B.push_back(rand()); 
    } 
    for(int i =0; i < 1000000;i++) { 
        sum += A[i] + B[i]; 
    } 
    cout<<sum; 
}
*/
