#include <iostream>
#include <iterator>
#include <stdexcept>

template<typename T>
class MyVector {
private:
    T* data;
    size_t capacity;
    size_t length;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < length; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    MyVector() : data(new T[1]), capacity(1), length(0) {}

    MyVector(const MyVector& other)
        : data(new T[other.capacity]), capacity(other.capacity), length(other.length) {
        for (size_t i = 0; i < length; ++i)
            data[i] = other.data[i];
    }

    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this;

        delete[] data;
        capacity = other.capacity;
        length = other.length;
        data = new T[capacity];
        for (size_t i = 0; i < length; ++i)
            data[i] = other.data[i];
        return *this;
    }

    ~MyVector() {
        delete[] data;
    }

    void remove_at(size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < length - 1; ++i)
            data[i] = data[i + 1];
        --length;
    }

    void push_back(const T& value) {
        if (length == capacity)
            resize(capacity * 2);
        data[length++] = value;
    }

    void clear() {
        delete[] data;
        data = new T[1];
        capacity = 1;
        length = 0;
    }

    T& operator[](size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const {
        return length;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyVector& vec) {
        for (size_t i = 0; i < vec.length; ++i)
            os << vec.data[i] << " ";
        return os;
    }

    class Iterator : public std::iterator<std::forward_iterator_tag, T> {
    private:
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}

        T& operator*() const { return *ptr; }
        T* operator->() const { return ptr; }

        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }

        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    Iterator begin() const { return Iterator(data); }
    Iterator end() const { return Iterator(data + length); }
};
