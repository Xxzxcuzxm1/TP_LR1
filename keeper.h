#ifndef KEEPER_H
#define KEEPER_H

#include "base.h"
#include <fstream>

class Keeper {
private:
    Base** data;
    int size;
    int capacity;

    void resize();
    bool isValidIndex(int index) const;

public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    void add(Base* item);
    void remove(int index);
    void displayAll() const;
    void edit(int index);
    int getSize() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    Base* operator[](int index);
    const Base* operator[](int index) const;
    Keeper& operator=(const Keeper& other);
};

#endif