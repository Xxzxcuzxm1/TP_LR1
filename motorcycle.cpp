#include "motorcycle.h"

Motorcycle::Motorcycle() : Base(), enginePower(0.0), terrainType("") {
    std::cout << "Motorcycle: default" << std::endl;
}

Motorcycle::Motorcycle(const std::string& brand, const std::string& model, double engineVolume, 
                       double enginePower, const std::string& terrainType)
    : Base(brand, model, engineVolume), enginePower(enginePower), terrainType(terrainType) {
    std::cout << "Motorcycle: parametr" << std::endl;
}

Motorcycle::Motorcycle(const Motorcycle& other) 
    : Base(other), enginePower(other.enginePower), terrainType(other.terrainType) {
    std::cout << "Motorcycle: copy" << std::endl;
}

Motorcycle::~Motorcycle() {
    std::cout << "Motorcycle: destructor" << std::endl;
}

double Motorcycle::getEnginePower() const {
    return enginePower;
}

std::string Motorcycle::getTerrainType() const {
    return terrainType;
}

void Motorcycle::setEnginePower(double enginePower) {
    if (enginePower < 0) {
        throw std::invalid_argument("Engine volume can't be negative");
    }
    this->enginePower = enginePower;
}

void Motorcycle::setTerrainType(const std::string& terrainType) {
    this->terrainType = terrainType;
}

void Motorcycle::display() const {
    std::cout << "Type: Motorcycle" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Engine volume: " << engineVolume << " l" << std::endl;
    std::cout << "Engine power: " << enginePower << " h.p." << std::endl;
    std::cout << "Terrain type: " << terrainType << std::endl;
}

void Motorcycle::edit() {
    std::cout << "Motorcycle edit:" << std::endl;
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Model: ";
    std::cin >> model;
    std::cout << "Engine volume: ";
    std::cin >> engineVolume;
    if (engineVolume < 0) throw std::invalid_argument("Engine volume can't be negative");
    std::cout << "Engine volume: ";
    std::cin >> enginePower;
    if (enginePower < 0) throw std::invalid_argument("Engine power can't be negative");
    std::cout << "Engine power: ";
    std::cin >> terrainType;
}

std::string Motorcycle::getType() const {
    return "Motorcycle";
}

void Motorcycle::saveToFile(std::ostream& out) const {
    out << getType() << std::endl;
    out << brand << std::endl;
    out << model << std::endl;
    out << engineVolume << std::endl;
    out << enginePower << std::endl;
    out << terrainType << std::endl;
}

void Motorcycle::loadFromFile(std::istream& in) {
    std::getline(in, brand);
    std::getline(in, model);
    in >> engineVolume;
    in.ignore();
    in >> enginePower;
    in.ignore();
    std::getline(in, terrainType);
}

Motorcycle& Motorcycle::operator=(const Motorcycle& other) {
    if (this != &other) {
        Base::operator=(other);
        enginePower = other.enginePower;
        terrainType = other.terrainType;
    }
    return *this;
}