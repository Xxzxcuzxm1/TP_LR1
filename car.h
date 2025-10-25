#ifndef CAR_H
#define CAR_H

#include "base.h"
#include <string>

class Car : public Base {
private:
    std::string color;
    std::string transmissionType;

public:
    Car();
    Car(const std::string& brand, const std::string& model, double engineVolume, 
        const std::string& color, const std::string& transmissionType);
    Car(const Car& other);
    ~Car();

    // Get методы
    std::string getColor() const;
    std::string getTransmissionType() const;

    // Set методы
    void setColor(const std::string& color);
    void setTransmissionType(const std::string& transmissionType);

    void display() const override;
    void edit() override;
    std::string getType() const override;

    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;

    Car& operator=(const Car& other);
};

#endif