#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> // for size_t
#include <stdexcept> // for exceptions

template<typename T>
class vector {
private:
    T* data;
    size_t capacity;
    size_t size;

public:
    vector() : data(nullptr), capacity(0), size(0) {}
    explicit vector(size_t initial_capacity) : data(new T[initial_capacity]), capacity(initial_capacity), size(0) {}
    ~vector() { delete[] data; }

    void push_back(const T& value) {
        if (size == capacity) {
            size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        data[size++] = value;
    }

    size_t getCapacity() const {
        return capacity;
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    const T& operator[](size_t index) const {
        if (index < size) {
            return data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }
};

#endif // VECTOR_H
