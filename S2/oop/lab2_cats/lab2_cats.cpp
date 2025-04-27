#include "lab2_cats.h"
#include <iostream>
#include <vector>
#include <random>

void Cat::generateRandomAttributes() {
    std::vector<std::string> furColors = {"black", "grey", "brown"};
    std::vector<std::string> eyeColors = {"green", "blue", "brown"};
    std::vector<std::string> hairLengths = {"short", "long"};

    furColor = furColors[std::random_device()() % furColors.size()];
    eyeColor = eyeColors[std::random_device()() % eyeColors.size()];
    hairLength = hairLengths[std::random_device()() % hairLengths.size()];
}

Cat::Cat() {
    generateRandomAttributes();
}

// Non-member function to check for fights
bool Cat::check(const std::vector<Cat>& cats) {
    int greyCount = 0, brownCount = 0;
    int blackGreenCount = 0, blackBlueCount = 0, blackBrownCount = 0;

    for (const Cat& cat : cats) {
        if (cat.getFurColor() == "grey") {
            greyCount++;
        } else if (cat.getFurColor() == "brown") {
            brownCount++;
        } else if (cat.getFurColor() == "black") {
            if (cat.getEyeColor() == "green") {
                blackGreenCount++;
            } else if (cat.getEyeColor() == "blue") {
                blackBlueCount++;
            } else if (cat.getEyeColor() == "brown") {
                blackBrownCount++;
            }
        }
    }

    return (greyCount > brownCount ||
            (blackGreenCount > 0 && blackBlueCount > 0 && blackBrownCount == 1));
}