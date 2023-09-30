#pragma once

#include <cstdint>
#include <cstring>


template <typename T>
class Array{
public:
    explicit Array (size_t size, const T& value) : size_(size){
        data_ = new char[size_ * sizeof(T)];
        for (int i = 0; i < size_; i++){
            new (data_ + i * sizeof(T)) T(value);
        }
    }

    Array (const Array & rhs) : size_(rhs.size_) {
        data_ = new char[size * sizeof(T)];
        std::memcpy(data_, rhs.data_, size_ * sizeof(T));
    }

    Array (Array && rhs) : size_(rhs.size_), data_(rhs.data_) {
        rhs.data_ = nullptr;
    }
    
    ~Array () {
        for (int i = 0; i < size_; i++){
            static_cast<T*>(static_cast<void*>(data_ + i))->~T();
        }
        delete [] data_;
    }

    Array& operator=(const Array & rhs){
        if (&rhs == this)
            return *this;
        if (rhs.size_ != size_){
            delete [] data_;
            size_ = rhs.size_;
            data_ = new char[size_ * sizeof(T)];
        }
        std::memcpy(data_, rhs.data_, size_ * sizeof(T));
        return *this;
    }

    Array& operator=(Array && rhs){
        std::swap(rhs.data_, this->data_);
        std::swap(rhs.size_, this->size_);
    }

    T& operator[](size_t idx){
        return *static_cast<T*>(static_cast<void*>(data_ + idx * sizeof(T)));
    }

    const T& operator[](size_t idx) const {
        return *(data_ + idx * sizeof(T));
    }

    size_t size() const {
        return size_;
    }

private:
    char* data_;
    size_t size_;
};