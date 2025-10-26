#include "bus.h"

Bus::Bus() : Base(), seatedPassengers(0), totalPassengers(0), destination("") {
    std::cout << "Bus: default" << std::endl;
}

Bus::Bus(const std::string& brand, const std::string& model, double engineVolume, 
         int seatedPassengers, int totalPassengers, const std::string& destination)
    : Base(brand, model, engineVolume), seatedPassengers(seatedPassengers), 
      totalPassengers(totalPassengers), destination(destination) {
    std::cout << "Bus: parametr" << std::endl;
}

Bus::Bus(const Bus& other) 
    : Base(other), seatedPassengers(other.seatedPassengers), 
      totalPassengers(other.totalPassengers), destination(other.destination) {
    std::cout << "Bus: copy" << std::endl;
}

Bus::~Bus() {
    std::cout << "Bus: destructor" << std::endl;
}

int Bus::getSeatedPassengers() const {
    return seatedPassengers;
}

int Bus::getTotalPassengers() const {
    return totalPassengers;
}

std::string Bus::getDestination() const {
    return destination;
}

void Bus::setSeatedPassengers(int seatedPassengers) {
    if (seatedPassengers < 0) {
        throw std::invalid_argument("Seated passengers is positive value");
    }
    this->seatedPassengers = seatedPassengers;
}

void Bus::setTotalPassengers(int totalPassengers) {
    if (totalPassengers < 0) {
        throw std::invalid_argument("Total passengers is positive value");
    }
    if (totalPassengers < seatedPassengers) {
        throw std::invalid_argument("Total passengers can't be lower than seated passengers");
    }
    this->totalPassengers = totalPassengers;
}

void Bus::setDestination(const std::string& destination) {
    this->destination = destination;
}

void Bus::display() const {
    std::cout << "Type: Bus" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Engine volume: " << engineVolume << " l" << std::endl;
    std::cout << "Seated passengers: " << seatedPassengers << std::endl;
    std::cout << "Total passengers: " << totalPassengers << std::endl;
    std::cout << "Destination: " << destination << std::endl;
}

void Bus::edit() {
    std::cout << "Bus edit:" << std::endl;
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Model: ";
    std::cin >> model;
    std::cout << "Engine volume: ";
    std::cin >> engineVolume;
    if (engineVolume < 0) throw std::invalid_argument("Engine volume can't be negative");
    std::cout << "Seated passengers: ";
    std::cin >> seatedPassengers;
    if (seatedPassengers < 0) throw std::invalid_argument("Seated passengers can't be negative");
    std::cout << "Total passengers: ";
    std::cin >> totalPassengers;
    if (totalPassengers < 0) throw std::invalid_argument("Total passengers can't be negative");
    if (totalPassengers < seatedPassengers) throw std::invalid_argument("Total passengers can't be lower than seated passengers");
    std::cout << "Destination: ";
    std::cin >> destination;
}

std::string Bus::getType() const {
    return "Bus";
}

void Bus::saveToFile(std::ostream& out) const {
    out << getType() << std::endl;
    out << brand << std::endl;
    out << model << std::endl;
    out << engineVolume << std::endl;
    out << seatedPassengers << std::endl;
    out << totalPassengers << std::endl;
    out << destination << std::endl;
}

void Bus::loadFromFile(std::istream& in) {
    std::getline(in, brand);
    std::getline(in, model);
    in >> engineVolume;
    in.ignore();
    in >> seatedPassengers;
    in.ignore();
    in >> totalPassengers;
    in.ignore();
    std::getline(in, destination);
}

Bus& Bus::operator=(const Bus& other) {
    if (this != &other) {
        Base::operator=(other);
        seatedPassengers = other.seatedPassengers;
        totalPassengers = other.totalPassengers;
        destination = other.destination;
    }
    return *this;
}