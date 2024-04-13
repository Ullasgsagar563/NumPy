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

#include <iostream>
#include <sstream>
#include <cstring>
#include "map.h" // Include your custom map header
#include "Vector.h" // Include your custom vector header

using namespace std;

template<typename T>
class CustomArray {
private:
    Vector<T> data;

public:
    void createArray(const Vector<T>& elements) {
        data = elements;
    }

    size_t size() const {
        return data.getSize();
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    // Retrieve element by index
    T getElement(size_t index) const {
        if (index < data.getSize()) {
            return data[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    // Compute sum of elements
    double sum() const {
        if constexpr (is_arithmetic<T>::value) {
            double sum = 0;
            for (const auto& val : data) {
                sum += static_cast<double>(val);
            }
            return sum;
        } else {
            throw logic_error("Sum not supported for non-arithmetic types");
        }
    }

    // Find minimum value
    T min() const {
        if constexpr (is_arithmetic<T>::value) {
            T minimum = data[0];
            for (const auto& val : data) {
                if (val < minimum) {
                    minimum = val;
                }
            }
            return minimum;
        } else {
            throw logic_error("Minimum not supported for non-arithmetic types");
        }
    }

    // Find maximum value
    T max() const {
        if constexpr (is_arithmetic<T>::value) {
            T maximum = data[0];
            for (const auto& val : data) {
                if (val > maximum) {
                    maximum = val;
                }
            }
            return maximum;
        } else {
            throw logic_error("Maximum not supported for non-arithmetic types");
        }
    }
};

template<typename T>
void init_arr(Map<string, CustomArray<T>>& store_arrays, const string& arr_name, const Vector<T>& values) {
    CustomArray<T> arr;
    arr.createArray(values);
    store_arrays.insert(arr_name, arr);
    cout << "Array " << arr_name << " created." << endl;
}

template<typename T>
void print_arr(const Map<string, CustomArray<T>>& store_arrays, const string& arr_name) {
    if (store_arrays.contains(arr_name)) {
        const auto& arr = store_arrays[arr_name];
        cout << arr_name << " = [";
        for (size_t i = 0; i < arr.size(); ++i) {
            if constexpr (is_same<T, char>::value) {
                cout << "\'" << arr[i] << "\'";
            } else {
                cout << arr[i];
            }
            if (i < arr.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    } else {
        cout << "Array " << arr_name << " not found." << endl;
    }
}

template<typename T>
void get_arr_size(const Map<string, CustomArray<T>>& store_arrays, const string& arr_name) {
    if (store_arrays.contains(arr_name)) {
        cout << "Size of " << arr_name << ": " << store_arrays[arr_name].size() << endl;
    } else {
        cout << "Array " << arr_name << " not found." << endl;
    }
}

template<typename T>
void retrieve_element(const Map<string, CustomArray<T>>& store_arrays, const string& arr_name, size_t index) {
    if (store_arrays.contains(arr_name)) {
        try {
            cout << "Element at index " << index << " in array " << arr_name << ": " << store_arrays[arr_name].getElement(index) << endl;
        } catch (const out_of_range& e) {
            cout << "Index out of range for array " << arr_name << endl;
        }
    } else {
        cout << "Array " << arr_name << " not found." << endl;
    }
}

template<typename T>
void array_sum(const Map<string, CustomArray<T>>& store_arrays, const string& arr_name) {
    if (store_arrays.contains(arr_name)) {
        try {
            cout << "Sum of elements in array " << arr_name << ": " << store_arrays[arr_name].sum() << endl;
        } catch (const logic_error& e) {
            cout << e.what() << endl;
        }
    } else {
        cout << "Array " << arr_name << " not found." << endl;
    }
}

template<typename T>
void array_min(const Map<string, CustomArray<T>>& store_arrays, const string& arr_name) {
    if (store_arrays.contains(arr_name)) {
        try {
            cout << "Minimum value in array " << arr_name << ": " << store_arrays[arr_name].min() << endl;
        } catch (const logic_error& e) {
            cout << e.what() << endl;
        }
    } else {
        cout << "Array " << arr_name << " not found." << endl;
    }
}

template<typename T>
void array_max(const Map<string, CustomArray<T>>& store_arrays, const string& arr_name) {
    if (store_arrays.contains(arr_name)) {
        try {
            cout << "Maximum value in array " << arr_name << ": " << store_arrays[arr_name].max() << endl;
        } catch (const logic_error& e) {
            cout << e.what() << endl;
        }
    } else {
        cout << "Array " << arr_name << " not found." << endl;
    }
}

int main() {
    string input;
    Map<string, CustomArray<string>> store_arrays_string;
    Map<string, CustomArray<char>> store_arrays_char;
    Map<string, CustomArray<double>> store_arrays_double;
    
    while (true) {
        cout << "Enter command: ";
        getline(cin, input);

        if (input == "exit") {
            break;
        } else if (input.find('=') != string::npos) {
            size_t equal_pos = input.find('=');
            string arr_name = input.substr(0, equal_pos);
            Vector<string> string_values;
            Vector<char> char_values;
            Vector<double> double_values;

            // Check the input type
            if (input.find("\"") != string::npos) { // It's a string
                size_t start_pos = input.find("[");
                size_t end_pos = input.find("]");
                string values_str = input.substr(start_pos + 1, end_pos - start_pos - 1);
                stringstream ss(values_str);
                string value;
                while (getline(ss, value, ',')) {
                    string_values.push_back(value);
                }
                init_arr(store_arrays_string, arr_name, string_values);
            } else if (input.find("'") != string::npos) { // It's a char array
                size_t start_pos = input.find("[");
                size_t end_pos = input.find("]");
                string values_str = input.substr(start_pos + 1, end_pos - start_pos - 1);
                for (char c : values_str) {
                    if (c != ',' && c != ' ') {
                        char_values.push_back(c);
                    }
                }
                init_arr(store_arrays_char, arr_name, char_values);
            } else { // It's a numeric array
                size_t start_pos = input.find("[");
                size_t end_pos = input.find("]");
                string values_str = input.substr(start_pos + 1, end_pos - start_pos - 1);
                stringstream ss(values_str);
                string value;
                while (getline(ss, value, ',')) {
                    double_values.push_back(stod(value));
                }
                init_arr(store_arrays_double, arr_name, double_values);
            }
        } else if (input.find(".size") != string::npos) {
            size_t dot_pos = input.find('.');
            string arr_name = input.substr(0, dot_pos);
            get_arr_size(store_arrays_string, arr_name);
            get_arr_size(store_arrays_char, arr_name);
            get_arr_size(store_arrays_double, arr_name);
        } else if (input.find("print(") != string::npos && input.back() == ')') {
            size_t open_bracket_pos = input.find('(');
            string arr_name = input.substr(open_bracket_pos + 1, input.size() - open_bracket_pos - 2);
            print_arr(store_arrays_string, arr_name);
            print_arr(store_arrays_char, arr_name);
            print_arr(store_arrays_double, arr_name);
        } else if (input.find('[') != string::npos && input.find(']') != string::npos) { // Retrieve element by index
            size_t open_bracket_pos = input.find('[');
            size_t close_bracket_pos = input.find(']');
            string arr_name = input.substr(0, open_bracket_pos);
            size_t index = stoi(input.substr(open_bracket_pos + 1, close_bracket_pos - open_bracket_pos - 1));
            retrieve_element(store_arrays_string, arr_name, index);
            retrieve_element(store_arrays_char, arr_name, index);
            retrieve_element(store_arrays_double, arr_name, index);
        } else if (input.find(".sum") != string::npos) { // Compute sum
            size_t dot_pos = input.find('.');
            string arr_name = input.substr(0, dot_pos);
            array_sum(store_arrays_double, arr_name);
        } else if (input.find(".min") != string::npos) { // Find minimum
            size_t dot_pos = input.find('.');
            string arr_name = input.substr(0, dot_pos);
            array_min(store_arrays_double, arr_name);
        } else if (input.find(".max") != string::npos) { // Find maximum
            size_t dot_pos = input.find('.');
            string arr_name = input.substr(0, dot_pos);
            array_max(store_arrays_double, arr_name);
        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
