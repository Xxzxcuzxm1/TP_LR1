#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

class Base {
protected:
    std::string brand;
    std::string model;
    double engineVolume;

public:
    Base();
    Base(const std::string& brand, const std::string& model, double engineVolume);
    Base(const Base& other);
    virtual ~Base();

    // Get методы
    std::string getBrand() const;
    std::string getModel() const;
    double getEngineVolume() const;

    // Set методы
    void setBrand(const std::string& brand);
    void setModel(const std::string& model);
    void setEngineVolume(double engineVolume);

    // Виртуальные методы
    virtual void display() const = 0;
    virtual void edit() = 0;
    virtual std::string getType() const = 0;
    
    // Операторы
    Base& operator=(const Base& other);
    bool operator==(const Base& other) const;

    // Методы для работы с файлом
    virtual void saveToFile(std::ostream& out) const = 0;
    virtual void loadFromFile(std::istream& in) = 0;
};

#endif