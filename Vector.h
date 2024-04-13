#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> // For std::size_t
#include <stdexcept> // For std::out_of_range

template<typename T>
class Vector {
private:
    T* data;
    std::size_t capacity;
    std::size_t size;

    void resize(std::size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (std::size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Vector() : data(nullptr), capacity(0), size(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            std::size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resize(newCapacity);
        }
        data[size++] = value;
    }

    T& operator[](std::size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    std::size_t getSize() const {
        return size;
    }
};

#endif // VECTOR_H