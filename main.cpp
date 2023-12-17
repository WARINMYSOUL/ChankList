#include "ChunkList.hpp"
#include <iostream>
#include <vector>
#include <random>

using namespace fefu_laboratory_two;

int main() {
    std::vector<ChunkList<int, 5, Allocator<int>>> sestra;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100);


    for (int i = 0; i < 10; i++) {
        std::list<int> l;
        for (int j = 0; j < 5; j++) {
          l.push_back(dist6(rng));
        };
        ChunkList<int, 5, Allocator<int>> letters(l.begin(), l.end());
        sestra.push_back(letters);
    };

    ChunkList_iterator<int> it{};
    for(auto element: sestra){
        for (it = element.begin(); it < element.end(); it++){
            std::cout << *it << std::endl;
        };
    };

    return 0;
}