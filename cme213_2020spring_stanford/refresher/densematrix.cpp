//
// Created by tai94bn on 5/12/2020.
//
#include <iostream>
#include <ostream>
#include <stdexcept>

// same idea as typedef
using uint = unsigned int;

// TODO: template this class with a type T
// What do we need to change in the method signature or member
class DenseMatrix
{
public:
    DenseMatrix(uint rows, uint cols)
    {
        this->n_rows = rows;
        this->n_cols = cols;
        this->elements = new int[this->n_rows * this->n_cols];
    }

    DenseMatrix(const DenseMatrix<T>& dm)
    {
        this->n_rows = dm.n_rows;
        this->n_cols = dm.n_cols;
        this->elements = new T[this->n_rows * this->n_cols];
        std::memcpy(this->elements, dm.elements, this->n_rows * this->n_cols * sizeof(T));
    }

    ~DenseMatrix()
    {
        if (this->elements)
        {
            delete[] this->elements;
            this->elements = nullptr;
        }
    }

    DenseMatrix operator +(const DenseMatrix& dm)
    {
        return DenseMatrix(0, 0);
    }

    const int& operator ()(uint row, uint col) const
    {
        return 0;
    }

    int& operator ()(uint row, uint col)
    {
        return 0;
    }

    friend std::ostream& operator <<(std::ostream& stream, DenseMatrix dm)
    {
        return stream;
    }

private:
    uint n_rows;
    uint n_cols;
    int *elements;

    void print(std::ostream& stream)
    {
        for (uint i = 0; i < this->n_rows; i++)
        {
            for (uint j = 0; j < this->n_cols, j++)
            {
                stream << "[placeholder]" << "";
            }
            stream << std:endl;
        }
    }
};

int main()
{
    DenseMatrix a(2, 4);
    DenseMatrix b(2, 4);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a(i, j) = i + j;
            b(i, j) = 1;
        }
    }

    DenseMatrix c = a + b;
    std::cout << "A: " << std::endl;
    std::cout << a << std::endl;
    std::cout << "B: " << std::endl << b << std::endl;
    std::cout << "C = A + B:" << std::endl << c << std::endl;
    return 0;
}