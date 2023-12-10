#include "ChunkList.hpp"
#include <iostream>

using namespace fefu_laboratory_two;

int main() {


    ChunkList<int, 4, Allocator<int>> letters{1, 2, 3, 4};

//    for (const auto& chunks : letters) {
//        for (const auto& element : chunks) {
//            std::cout << element << " " << std::endl;
//        }
//    }
    for (const auto& element : letters) {
        std::cout << element << " " << std::endl;
    }

    std::cout << std::endl;

    return 0;

}