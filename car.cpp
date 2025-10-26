#include "car.h"

Car::Car() : Base(), color(""), transmissionType("") {
    std::cout << "Car: default" << std::endl;
}

Car::Car(const std::string& brand, const std::string& model, double engineVolume, 
         const std::string& color, const std::string& transmissionType)
    : Base(brand, model, engineVolume), color(color), transmissionType(transmissionType) {
    std::cout << "Car: parametr" << std::endl;
}

Car::Car(const Car& other) : Base(other), color(other.color), transmissionType(other.transmissionType) {
    std::cout << "Car: copy" << std::endl;
}

Car::~Car() {
    std::cout << "Car: destructor" << std::endl;
}

std::string Car::getColor() const {
    return color;
}

std::string Car::getTransmissionType() const {
    return transmissionType;
}

void Car::setColor(const std::string& color) {
    this->color = color;
}

void Car::setTransmissionType(const std::string& transmissionType) {
    this->transmissionType = transmissionType;
}

void Car::display() const {
    std::cout << "Type: car" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Engine volume: " << engineVolume << " l" << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Transmission type: " << transmissionType << std::endl;
}

void Car::edit() {
    std::cout << "Car edit:" << std::endl;
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Model: ";
    std::cin >> model;
    std::cout << "Engine volume: ";
    std::cin >> engineVolume;
    if (engineVolume < 0) throw std::invalid_argument("Engine volume can't be negative");
    std::cout << "Color: ";
    std::cin >> color;
    std::cout << "Transmission type: ";
    std::cin >> transmissionType;
}

std::string Car::getType() const {
    return "Car";
}

void Car::saveToFile(std::ostream& out) const {
    out << getType() << std::endl;
    out << brand << std::endl;
    out << model << std::endl;
    out << engineVolume << std::endl;
    out << color << std::endl;
    out << transmissionType << std::endl;
}

void Car::loadFromFile(std::istream& in) {
    std::getline(in, brand);
    std::getline(in, model);
    in >> engineVolume;
    in.ignore();
    std::getline(in, color);
    std::getline(in, transmissionType);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Base::operator=(other);
        color = other.color;
        transmissionType = other.transmissionType;
    }
    return *this;
}