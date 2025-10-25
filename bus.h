#ifndef BUS_H
#define BUS_H

#include "base.h"
#include <string>

class Bus : public Base {
private:
    int seatedPassengers;
    int totalPassengers;
    std::string destination;

public:
    Bus();
    Bus(const std::string& brand, const std::string& model, double engineVolume, 
        int seatedPassengers, int totalPassengers, const std::string& destination);
    Bus(const Bus& other);
    ~Bus();

    int getSeatedPassengers() const;
    int getTotalPassengers() const;
    std::string getDestination() const;

    void setSeatedPassengers(int seatedPassengers);
    void setTotalPassengers(int totalPassengers);
    void setDestination(const std::string& destination);

    void display() const override;
    void edit() override;
    std::string getType() const override;

    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;

    Bus& operator=(const Bus& other);
};

#endif