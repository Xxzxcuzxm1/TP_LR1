#include "keeper.h"
#include "car.h"
#include "motorcycle.h"
#include "bus.h"
#include <iostream>
#include <stdexcept>

Keeper::Keeper() : data(nullptr), size(0), capacity(0) {
    std::cout << "Keeper: defoult" << std::endl;
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    std::cout << "Keeper: copy" << std::endl;
    data = new Base*[capacity];
    for (int i = 0; i < size; ++i) {
        // Создаем копии объектов
        if (dynamic_cast<Car*>(other.data[i])) {
            data[i] = new Car(*dynamic_cast<Car*>(other.data[i]));
        } else if (dynamic_cast<Motorcycle*>(other.data[i])) {
            data[i] = new Motorcycle(*dynamic_cast<Motorcycle*>(other.data[i]));
        } else if (dynamic_cast<Bus*>(other.data[i])) {
            data[i] = new Bus(*dynamic_cast<Bus*>(other.data[i]));
        }
    }
}

Keeper::~Keeper() {
    std::cout << "Keeper: destructor" << std::endl;
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
}

void Keeper::resize() {
    if (capacity == 0) {
        capacity = 1;
        data = new Base*[capacity];
    } else if (size >= capacity) {
        capacity *= 2;
        Base** newData = new Base*[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
}

bool Keeper::isValidIndex(int index) const {
    return index >= 0 && index < size;
}

void Keeper::add(Base* item) {
    if (!item) {
        throw std::invalid_argument("Empty object");
    }
    resize();
    data[size++] = item;
}

void Keeper::remove(int index) {
    if (!isValidIndex(index)) {
        throw std::out_of_range("Wrong index");
    }
    
    delete data[index];
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}

void Keeper::displayAll() const {
    if (size == 0) {
        std::cout << "Garage is empty" << std::endl;
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        std::cout << "[" << i << "] ";
        data[i]->display();
        std::cout << "------------------------" << std::endl;
    }
}

void Keeper::edit(int index) {
    if (!isValidIndex(index)) {
        throw std::out_of_range("Wrong index");
    }
    data[index]->edit();
}

int Keeper::getSize() const {
    return size;
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File open error: " + filename);
    }
    
    file << size << std::endl;
    for (int i = 0; i < size; ++i) {
        data[i]->saveToFile(file);
    }
    file.close();
    std::cout << "Saved: " << filename << std::endl;
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error read: " + filename);
    }
    
    // Очищаем текущие данные
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    
    file >> size;
    file.ignore();
    
    capacity = size;
    data = new Base*[capacity];
    
    for (int i = 0; i < size; ++i) {
        std::string type;
        std::getline(file, type);
        
        if (type == "Car") {
            Car* car = new Car();
            car->loadFromFile(file);
            data[i] = car;
        } else if (type == "Motorcycle") {
            Motorcycle* motorcycle = new Motorcycle();
            motorcycle->loadFromFile(file);
            data[i] = motorcycle;
        } else if (type == "Bus") {
            Bus* bus = new Bus();
            bus->loadFromFile(file);
            data[i] = bus;
        }
    }
    file.close();
    std::cout << "Loaded: " << filename << std::endl;
}

Base* Keeper::operator[](int index) {
    if (!isValidIndex(index)) {
        throw std::out_of_range("Wrong index");
    }
    return data[index];
}

const Base* Keeper::operator[](int index) const {
    if (!isValidIndex(index)) {
        throw std::out_of_range("Wrong index");
    }
    return data[index];
}

Keeper& Keeper::operator=(const Keeper& other) {
    if (this != &other) {
        // Очищаем текущие данные
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
        
        // Копируем новые данные
        size = other.size;
        capacity = other.capacity;
        data = new Base*[capacity];
        
        for (int i = 0; i < size; ++i) {
            if (dynamic_cast<Car*>(other.data[i])) {
                data[i] = new Car(*dynamic_cast<Car*>(other.data[i]));
            } else if (dynamic_cast<Motorcycle*>(other.data[i])) {
                data[i] = new Motorcycle(*dynamic_cast<Motorcycle*>(other.data[i]));
            } else if (dynamic_cast<Bus*>(other.data[i])) {
                data[i] = new Bus(*dynamic_cast<Bus*>(other.data[i]));
            }
        }
    }
    return *this;
}