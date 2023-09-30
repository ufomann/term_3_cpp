#pragma once

#include <cstdint>
#include <cstring>


template <typename T>
class Array{
public:
    explicit Array (size_t size, const T& value) : size_(size){
        data_ = new T[size_];
        for (int i = 0; i < size; i++){
            data_[i] = value;
        }
    }

    Array (const Array & rhs) : size_(rhs.size_) {
        data_ = new T[size_];
        std::memcpy(data_, rhs.data_, size_ * sizeof(T));
    }

    Array (Array && rhs) : size_(rhs.size_), data_(rhs.data_) {
        rhs.data_ = nullptr;
    }
    
    ~Array () {
        delete [] data_;
    }

    Array& operator=(const Array & rhs){
        if (&rhs == this)
            return *this;
        if (rhs.size_ != size_){
            delete [] data_;
            size_ = rhs.size_;
            data_ = new T[size_];
        }
        std::memcpy(data_, rhs.data_, size_ * sizeof(T));
        return *this;
    }

    Array& operator=(Array && rhs){
        std::swap(rhs.data_, this->data_);
        std::swap(rhs.size_, this->size_);
    }

    T& operator[](size_t idx){
        return *(data_ + idx);
    }

    const T& operator[](size_t idx) const {
        return *(data_ + idx);
    }

    size_t size() const {
        return size_;
    }

private:
    T* data_;
    size_t size_;
};