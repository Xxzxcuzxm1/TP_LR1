#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "base.h"
#include <string>

class Motorcycle : public Base {
private:
    double enginePower;
    std::string terrainType;

public:
    Motorcycle();
    Motorcycle(const std::string& brand, const std::string& model, double engineVolume, 
               double enginePower, const std::string& terrainType);
    Motorcycle(const Motorcycle& other);
    ~Motorcycle();

    double getEnginePower() const;
    std::string getTerrainType() const;

    void setEnginePower(double enginePower);
    void setTerrainType(const std::string& terrainType);

    void display() const override;
    void edit() override;
    std::string getType() const override;

    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;

    Motorcycle& operator=(const Motorcycle& other);
};

#endif