#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
    private:
        T   *arr;
        unsigned int _size;
    public:
        Array() : _size(0){
            std::cout << "Constructor called" << std::endl;
            this->arr = new T[this->_size];
        }

        Array(unsigned int n) : _size(n){
            std::cout << "Constructor with _size called" << std::endl;
            this->arr = new T[this->_size];
        }

        Array(const Array& other) : _size(other._size){
            std::cout << "Copy constructor called" << std::endl;
            this->arr = NULL;
            *this = other;
        }

        Array& operator=(const Array& other){
            if (this->arr){
                delete [] this->arr;
            }
            if (other._size != 0){
                this->_size = other._size;
                this->arr = new T[this->_size];
                for (size_t i = 0; i < this->_size; i++)
                    this->arr[i] = other.arr[i];
                return *this;
            }
            this->_size = 0;
            this->arr = new T[this->_size];
            return *this;
        }

        T& operator[](unsigned int index){
            if (index >= this->_size || this->arr == NULL){
                throw std::runtime_error(" Index out of bounds");
            }
            return this->arr[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= this->_size || this->arr == NULL){
                throw std::runtime_error(" Index out of bounds");
            }
            return this->arr[index];
        }

        ~Array(){
            if (this->arr != NULL)
                delete [] this->arr;
        }

        //Getter
        unsigned int size() const{
            return (this->_size);
        }
};


#endif