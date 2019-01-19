#include <iostream>
#include <cmath>
#include <string>

typedef struct{
    float positionX;
    float velocity;
    float mass;
} Particle1D;


int main()
{
    Particle1D bigBox;

    std::cout << "Enter initial velocity for big box: ";
    std::cin >> bigBox.velocity;

    std::cout << "Enter the mass for big box: ";
    std::cin>> bigBox.mass;

    std::cout << "Calculating..." << std::endl;

}

