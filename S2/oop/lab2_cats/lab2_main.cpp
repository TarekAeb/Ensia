#include<iostream>
#include<vector>
#include"lab2_cats.h"
using namespace std;
int main() {
    const int maxCats = 7;
    std::vector<Cat> room;

    while (room.size() < maxCats) {
        std::cout << "Press Enter to add a cat. Press Q to quit." << std::endl;
        char input = std::cin.get();

        if (input == 'Q') {
            break;
        }

        Cat newCat;
        room.push_back(newCat);

        if (newCat.check(room)) {
            std::cout << "Fight! Removing the last cat." << std::endl;
            room.pop_back();
        } else {
            std::cout << "Added cat: fur=" << newCat.getFurColor() << ", eye="
                      << newCat.getEyeColor() << ", hair=" << newCat.getHairLength() << std::endl;
        }
    }

    std::cout << "Room is full with " << room.size() << " cats." << std::endl;

    return 0;
}