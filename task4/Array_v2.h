#pragma once

#include <cstdint>
#include <cstring>


template <typename T>
class Array{
public:
    explicit Array (size_t size, const T& value) : size_(size){
        data_ = static_cast<T*>(static_cast<void*>(new char[size_ * sizeof(T)]));
        for (int i = 0; i < size_; i++){
            new (data_ + i) T(value);
        }
    }

    Array (const Array & rhs) : size_(rhs.size_) {
        data_ = static_cast<T*>(static_cast<void*>(new char[size_ * sizeof(T)]));
        for (int i = 0; i < size_; i++){
            new (data_ + i) T(*(rhs.data_ + i));
        }
    }

    Array (Array && rhs) : size_(rhs.size_), data_(rhs.data_) {
        rhs.data_ = nullptr;
    }
    
    ~Array () {
        for (int i = 0; i < size_; i++){
            (data_ + i)->~T();
        }
        delete [] data_;
    }

    Array& operator=(const Array & rhs){
        if (&rhs == this)
            return *this;
        delete [] data_;
        size_ = rhs.size_;
        data_ = static_cast<T*>(static_cast<void*>(new char[size_ * sizeof(T)]));
        for (int i = 0; i < size_; i++){
            new (data_ + i) T(*(rhs.data_ + i));
        }
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