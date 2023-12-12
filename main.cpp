#include "ChunkList.hpp"
#include <iostream>

using namespace fefu_laboratory_two;

int main() {
    ChunkList<int, 4, Allocator<int>> letters{1, 2, 3, 4};

    ChunkList_iterator<int> it{};

    for (it = letters.begin(); it < letters.end(); it++){
        std::cout << *it << std::endl;
    };

    return 0;

}