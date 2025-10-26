#include "base.h"

Base::Base() : brand(""), model(""), engineVolume(0.0) {
    std::cout << "Base: default" << std::endl;
}

Base::Base(const std::string& brand, const std::string& model, double engineVolume) 
    : brand(brand), model(model), engineVolume(engineVolume) {
    std::cout << "Base: parametr" << std::endl;
}

Base::Base(const Base& other) 
    : brand(other.brand), model(other.model), engineVolume(other.engineVolume) {
    std::cout << "Base: copy" << std::endl;
}

Base::~Base() {
    std::cout << "Base: destructor" << std::endl;
}

std::string Base::getBrand() const {
    return brand;
}

std::string Base::getModel() const {
    return model;
}

double Base::getEngineVolume() const {
    return engineVolume;
}

void Base::setBrand(const std::string& brand) {
    this->brand = brand;
}

void Base::setModel(const std::string& model) {
    this->model = model;
}

void Base::setEngineVolume(double engineVolume) {
    if (engineVolume < 0) {
        throw std::invalid_argument("Volume is positive number");
    }
    this->engineVolume = engineVolume;
}

Base& Base::operator=(const Base& other) {
    if (this != &other) {
        brand = other.brand;
        model = other.model;
        engineVolume = other.engineVolume;
    }
    return *this;
}

bool Base::operator==(const Base& other) const {
    return brand == other.brand && model == other.model && engineVolume == other.engineVolume;
}