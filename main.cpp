#include <iostream>
#include <string>
#include <limits>
#include "keeper.h"
#include "car.h"
#include "motorcycle.h"
#include "bus.h"

void displayMenu() {
    std::cout << "\n=== Garage menu ===" << std::endl;
    std::cout << "1. Add car" << std::endl;
    std::cout << "2. Add motorcycle" << std::endl;
    std::cout << "3. Add bus" << std::endl;
    std::cout << "4. Show all vechicles" << std::endl;
    std::cout << "5. Edit vechicle" << std::endl;
    std::cout << "6. Delete vechicle" << std::endl;
    std::cout << "7. Save to file" << std::endl;
    std::cout << "8. Load from file" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose option: ";
}

int getIntInput() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error!: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

double getDoubleInput() {
    double value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error!: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

void addCar(Keeper& keeper) {
    try {
        std::string brand, model, color, transmissionType;
        double engineVolume;
        
        std::cout << "Insert brand: ";
        std::getline(std::cin, brand);
        std::cout << "Insert model: ";
        std::getline(std::cin, model);
        std::cout << "Insert engine volume: ";
        engineVolume = getDoubleInput();
        std::cout << "Insert color: ";
        std::getline(std::cin, color);
        std::cout << "Insert transmission type: ";
        std::getline(std::cin, transmissionType);
        
        Car* car = new Car(brand, model, engineVolume, color, transmissionType);
        keeper.add(car);
        std::cout << "Car added successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void addMotorcycle(Keeper& keeper) {
    try {
        std::string brand, model, terrainType;
        double engineVolume, enginePower;
        
        std::cout << "Insert brand: ";
        std::getline(std::cin, brand);
        std::cout << "Insert model: ";
        std::getline(std::cin, model);
        std::cout << "Insert engine volume: ";
        engineVolume = getDoubleInput();
        std::cout << "Insert engine power: ";
        enginePower = getDoubleInput();
        std::cout << "Insert terrain type: ";
        std::getline(std::cin, terrainType);
        
        Motorcycle* motorcycle = new Motorcycle(brand, model, engineVolume, enginePower, terrainType);
        keeper.add(motorcycle);
        std::cout << "Motorcycle added successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void addBus(Keeper& keeper) {
    try {
        std::string brand, model, destination;
        double engineVolume;
        int seatedPassengers, totalPassengers;
        
        std::cout << "Insert brand: ";
        std::getline(std::cin, brand);
        std::cout << "Insert model: ";
        std::getline(std::cin, model);
        std::cout << "Insert engine volume: ";
        engineVolume = getDoubleInput();
        std::cout << "Insert seated passengers: ";
        seatedPassengers = getIntInput();
        std::cout << "Insert total passengers: ";
        totalPassengers = getIntInput();
        std::cout << "Insert destination: ";
        std::getline(std::cin, destination);
        
        Bus* bus = new Bus(brand, model, engineVolume, seatedPassengers, totalPassengers, destination);
        keeper.add(bus);
        std::cout << "Bus added successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void editVehicle(Keeper& keeper) {
    if (keeper.getSize() == 0) {
        std::cout << "Garage is empty!" << std::endl;
        return;
    }
    
    std::cout << "Insert vechicle index for edit (0-" << keeper.getSize() - 1 << "): ";
    int index = getIntInput();
    
    try {
        keeper.edit(index);
        std::cout << "Vechilcle edited!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void removeVehicle(Keeper& keeper) {
    if (keeper.getSize() == 0) {
        std::cout << "Garage is empty!" << std::endl;
        return;
    }
    
    std::cout << "Insert vechicle index for delete (0-" << keeper.getSize() - 1 << "): ";
    int index = getIntInput();
    
    try {
        keeper.remove(index);
        std::cout << "Vechicle deleted!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void saveToFile(Keeper& keeper) {
    std::string filename;
    std::cout << "Insert filename for save: ";
    std::getline(std::cin, filename);
    
    try {
        keeper.saveToFile(filename);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void loadFromFile(Keeper& keeper) {
    std::string filename;
    std::cout << "Insert filename for load: ";
    std::getline(std::cin, filename);
    
    try {
        keeper.loadFromFile(filename);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    Keeper keeper;
    int choice;
    std::cout << "=== Garage management ===" << std::endl;
    
    do {
        displayMenu();
        choice = getIntInput();
        
        try {
            switch (choice) {
                case 1:
                    addCar(keeper);
                    break;
                case 2:
                    addMotorcycle(keeper);
                    break;
                case 3:
                    addBus(keeper);
                    break;
                case 4:
                    keeper.displayAll();
                    break;
                case 5:
                    editVehicle(keeper);
                    break;
                case 6:
                    removeVehicle(keeper);
                    break;
                case 7:
                    saveToFile(keeper);
                    break;
                case 8:
                    loadFromFile(keeper);
                    break;
                case 0:
                    std::cout << "Exit..." << std::endl;
                    break;
                default:
                    std::cout << "Wrong choose! Try again." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
    } while (choice != 0);
    
    return 0;
}