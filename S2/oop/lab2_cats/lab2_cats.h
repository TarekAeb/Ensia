#ifndef LAB2_CATS_H
#define LAB2_CATS_H

#include <string>
#include <random>

class Cat {
public:
    // Public constructor randomly sets attributes
    Cat();

    // Accessor methods (all attributes should be public for convenience)
    std::string getFurColor() const { return furColor; }
    std::string getEyeColor() const { return eyeColor; }
    std::string getHairLength() const { return hairLength; }
    bool check(const std::vector<Cat>&);

private:
    // Private attributes
    std::string furColor;
    std::string eyeColor;
    std::string hairLength;

    // Private method for generating random attributes
    void generateRandomAttributes();
};

#endif // LAB2_CATS_H
