#include <vector>
#include <iostream>


class Matrix{

    size_t mColumns;
    size_t mRows;

    public:
    std::vector<double> mData;

    Matrix() : mColumns(0), mRows(0), mData(){};
    Matrix(size_t rows, size_t columns) 
    : mRows(rows),
      mColumns(columns),
      mData(rows * columns, 0.0)
    {   
    }

    ~Matrix (){}

    double get(size_t row, size_t column) const
    {
        return mData[row * mColumns + column];
    }

    void set(size_t row, size_t column, double value)
    {
        mData[row * mColumns + column] = value;
    }

    Matrix transpose()
    {
        Matrix result(mRows, mColumns);
        for(size_t r = 0; r < mRows; ++r){
            for(size_t c = 0; c < mColumns; c++){
                result.set(r, c, get(r, c));
            }
        }

        return result;

    }

    Matrix add(Matrix &other)
    {
        if (mRows != other.mRows || mColumns != other.mColumns)
        {
            std::cout << "Dimensions do not match" << std::endl;
        }

        Matrix result(mRows, mColumns);
        for(size_t i = 0; i < mData.size(); i++){
            result.mData = mData[i] + other.data[i];
        }

        return result;
    }

    Matrix biasAdd(Matrix &other)
    {
        if (mRows != other.mRows || other.mColumns != 1)
        {
            std::cout << "Dimensions do not match" << std::endl;
        }

        Matrix result(mRows, mColumns);

        /*
          TODO: Calculasion of bias addition.
        */

        for(size_t r = 0; r < mRows; ++r){
            double bias = other.get(r,0);
            for(size_t c=0; c < mColumns; c++){
                result.set(r, c, get(r, c) + bias);
            }
        }

        return result;

    }

    Matrix scalarMult(double scalar)
    {

        Matrix result(mRows, mColumns);

        for(size_t i = 0; i < mData.size(); i++){
            result.mData[i] = mData[i] * scalar;
        }

        return result;
        
    }

    Matrix multi(Matrix &other)
    {
        if (mRows != other.mRows || mColumns != other.mColumns)
        {
            std::cout << "Dimensions do not match" << std::endl;
        }

        Matrix result(mRows, other.mColumns);
        double val = 0.0;

        for(size_t r = 0; r < result.mRows; r++){
            for(size_t c = 0; c < result.mColumns; c++){

                for (size_t i = 0; i < mColumns; ++i){
                    val += get(r, i) * other.get(i, c);
                }

                result.set(r, c, val);
                
            }
        }

        return result;
    }

    Matrix hadamard(Matrix &other)
    {
        /*
          TODO: Calculasion of hadamard product.
        */

        if (mRows != other.mRows || mColumns != other.mColumns)
        {
            std::cout << "Dimensions do not match" << std::endl;
        }

        Matrix result(mRows, mColumns);

        for(size_t i = 0; i < mData.size(); i++){
            result.mData[i] = mData[i] * other.mData[i];
        }

        return result;

        

    }

    Matrix kronecker(Matrix &other)
    {
        /*
          TODO: Calculasion of kronecker product.
        */

        size_t newRows = mRows * other.mRows;
        size_t newColumns = mColumns * other.mColumns;
        Matrix result(newRows, newColumns);

        for(size_t r = 0; r < mRows; r++){
            for(size_t c = 0; c < mColumns; c++){
                double val = get(r, c);
                for(size_t i = 0; i < other.mRows; i++){
                    for(size_t j = 0; j < other.mColumns; j++){
                        result.set(r * other.mRows + i, c * other.mColumns + j, val * other.get(i, j));
                    }
                }
            }
        }

        return result;
    }

    Matrix horizontalConcat(Matrix &other)
    {
        if (mRows != other.mRows)
        {
            std::cout << "Dimensions do not match" << std::endl;
        }

        /*
          TODO: Calculasion of horizontal concatination.
        */

        size_t newColumns = mColumns + other.mColumns;
        Matrix result(mRows, newColumns);

        //This seems a bit fishy, check again
        for(size_t r = 0; r < mRows; r++){
            for(size_t c = 0; c < mColumns; c++){
                result.set(r, c, get(r, c));
            }

            for(size_t c = 0; c < other.mColumns; c++){
                result.set(r, mColumns + c, other.get(r, c));
            }

        }

        return result;

    }

    Matrix mean()
    {
        /*
          TODO: Calculasion of mean of the matrix.
        */

        size_t n = mData.size();
        Matrix result(mRows, 1);
        double sum = 0.0;

        for(size_t r = 0; r < mRows; r++)
        {
            for(size_t c = 0; c < mColumns; c++){
                sum += get(r, c);
            }
            result.set(r, 0, sum/mColumns);
        }
        return result;

    }

    void print()
    {
        /*
          TODO: print the matrix
        */

        for(size_t r = 0; r < mRows; r++){
            for(size_t c = 0; c < mColumns; c++){
                std::cout<< get(r,c) << " ";
            }

            std::cout << std::endl;
        }
    }


}