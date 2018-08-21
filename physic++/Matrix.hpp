#pragma once

#include <iostream>
#include <math.h>

namespace math
{
template <size_t numberOfRows, size_t numberOfCols>
class Matrix final
{
	using Matrix_t = Matrix<numberOfRows, numberOfCols>;

  private:
	double data[numberOfRows][numberOfCols]{};

	Matrix_t dealWithZeros(Matrix_t matrix);

  public:
	Matrix() = default;
	template <typename T, size_t N>
	Matrix(const T (&list)[N]);
	template <typename T, size_t N, size_t M>
	Matrix(const T (&list)[N][M]);

	constexpr size_t rowSize();
	constexpr size_t colSize();

	void fill(double x);
	void diag(double x);

	double & operator()(unsigned i, unsigned j);
	const double & operator()(unsigned i, unsigned j) const;

	double & operator()(unsigned i);
	const double & operator()(unsigned i) const;

	Matrix_t & operator+=(double other);
	Matrix_t & operator-=(double other);
	Matrix_t & operator*=(double other);

	Matrix_t & operator+=(const Matrix_t & other);
	Matrix_t & operator-=(const Matrix_t & other);
};

// ---------------Vector alias---------------
template <size_t numberOfElems>
using Vector = Matrix<numberOfElems, 1>;

// ---------------Free functions---------------
template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfCols, numberOfRows> transpose(const Matrix<numberOfRows, numberOfCols> & matrix);

template <size_t numberOfRows, size_t numberOfCols>
double det(Matrix<numberOfRows, numberOfCols> matrix);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> inv(Matrix<numberOfRows, numberOfCols> matrix);

template <size_t numberOfElems>
double norm(const Vector<numberOfElems> & vector);

template <size_t numberOfElems>
double dotProduct(const Vector<numberOfElems> & left_vector,
                  const Vector<numberOfElems> & right_vector);

// ---------------Operators---------------
template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator+(const Matrix<numberOfRows, numberOfCols> & l_other,
                                             const Matrix<numberOfRows, numberOfCols> & r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator-(const Matrix<numberOfRows, numberOfCols> & l_other,
                                             const Matrix<numberOfRows, numberOfCols> & r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfRows> operator*(const Matrix<numberOfRows, numberOfCols> & l_other,
                                             const Matrix<numberOfCols, numberOfRows> & r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator+(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator-(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator*(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator/(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator+(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator-(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator*(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other);

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator/(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other);

} // namespace math

template <size_t numberOfRows, size_t numberOfCols>
std::ostream & operator<<(std::ostream & stream,
                          const math::Matrix<numberOfRows, numberOfCols> & matrix);

// ---------------Implementation---------------

namespace math
{
template <size_t numberOfRows, size_t numberOfCols>
template <typename T, size_t N>
Matrix<numberOfRows, numberOfCols>::Matrix(const T (&list)[N])
{
	static_assert(numberOfCols == 1);
	static_assert(numberOfRows == N);

	for(size_t i = 0; i < N; ++i)
	{
		data[i][0] = list[i];
	}
}

template <size_t numberOfRows, size_t numberOfCols>
template <typename T, size_t N, size_t M>
Matrix<numberOfRows, numberOfCols>::Matrix(const T (&list)[N][M])
{
	static_assert(numberOfRows == N);
	static_assert(numberOfCols == M);

	for(size_t i = 0; i < N; ++i)
	{
		for(size_t j = 0; j < M; ++j)
		{
			data[i][j] = list[i][j];
		}
	}
}

template <size_t numberOfRows, size_t numberOfCols>
constexpr size_t Matrix<numberOfRows, numberOfCols>::rowSize()
{
	return numberOfRows;
}

template <size_t numberOfRows, size_t numberOfCols>
constexpr size_t Matrix<numberOfRows, numberOfCols>::colSize()
{
	return numberOfCols;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfCols, numberOfRows> transpose(const Matrix<numberOfRows, numberOfCols> & matrix)
{
	Matrix<numberOfCols, numberOfRows> tmp;
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			tmp(j, i) = matrix(i, j);
		}
	}
	return tmp;
}

template <size_t numberOfRows, size_t numberOfCols>
void Matrix<numberOfRows, numberOfCols>::fill(double x)
{
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			data[i][j] = x;
		}
	}
}

template <size_t numberOfRows, size_t numberOfCols>
void Matrix<numberOfRows, numberOfCols>::diag(double x)
{
	static_assert(numberOfRows == numberOfCols, "diag() -> matrix must be square.");

	for(size_t i = 0; i < numberOfRows; ++i)
	{
		data[i][i] = x;
	}
}

template <size_t numberOfRows, size_t numberOfCols>
double & Matrix<numberOfRows, numberOfCols>::operator()(unsigned i, unsigned j)
{
	return data[i][j];
}

template <size_t numberOfRows, size_t numberOfCols>
const double & Matrix<numberOfRows, numberOfCols>::operator()(unsigned i, unsigned j) const
{
	return data[i][j];
}

template <size_t numberOfRows, size_t numberOfCols>
double & Matrix<numberOfRows, numberOfCols>::operator()(unsigned i)
{
	static_assert(numberOfCols == 1);
	return data[i][0];
}

template <size_t numberOfRows, size_t numberOfCols>
const double & Matrix<numberOfRows, numberOfCols>::operator()(unsigned i) const
{
	static_assert(numberOfCols == 1);
	return data[i][0];
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> & Matrix<numberOfRows, numberOfCols>::operator+=(double other)
{
	*this = *this + other;
	return *this;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> & Matrix<numberOfRows, numberOfCols>::operator-=(double other)
{
	*this = *this - other;
	return *this;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> & Matrix<numberOfRows, numberOfCols>::operator*=(double other)
{
	*this = *this * other;
	return *this;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> & Matrix<numberOfRows, numberOfCols>::
operator+=(const Matrix<numberOfRows, numberOfCols> & other)
{
	*this = *this + other;
	return *this;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> & Matrix<numberOfRows, numberOfCols>::
operator-=(const Matrix<numberOfRows, numberOfCols> & other)
{
	*this = *this - other;
	return *this;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> dealWithZeros(Matrix<numberOfRows, numberOfCols> matrix)
{
	unsigned t = 0;
	while(matrix(t, 0) == 0)
	{
		++t;
		if(t >= numberOfRows)
		{
			return Matrix<numberOfRows, numberOfCols>();
		}

		if(matrix(t, 0) != 0)
		{
			for(size_t i = 0; i < numberOfCols; ++i)
			{
				matrix(0, i) += matrix(t, i);
			}
		}
	}

	return matrix;
}

//------------------------------------------------------------------------------

template <size_t numberOfRows, size_t numberOfCols>
double det(Matrix<numberOfRows, numberOfCols> matrix)
{
	static_assert(numberOfRows == numberOfCols, "Only square matrices have determinant.");

	matrix = dealWithZeros(matrix);

	// calculating determinant
	double result = 1;
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = i + 1; j < numberOfRows; ++j)
		{
			double w = (matrix(i, i) == 0) ? (0) : (matrix(j, i) / matrix(i, i));
			for(size_t k = 0; k < numberOfCols; ++k)
			{
				matrix(j, k) -= matrix(i, k) * w;
			}
		}
		result *= matrix(i, i);
	}

	return result;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> inv(Matrix<numberOfRows, numberOfCols> matrix)
{
	static_assert(numberOfRows == numberOfCols, "Only square matrices are invertable.");

	// Create block matrix
	Matrix<numberOfRows, 2 * numberOfCols> tmp;
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			tmp(i, j) = matrix(i, j);
		}
		tmp(i, i + numberOfCols) = 1;
	}
	tmp = dealWithZeros(tmp);
	// if tmp == 0 return

	// Calculate inverted matrix
	for(size_t k = 0; k < tmp.rowSize(); ++k)
	{
		double at = tmp(k, k);
		for(size_t r = 0; r < tmp.colSize(); ++r)
		{
			tmp(k, r) = at == 0 ? 0 : tmp(k, r) / at;
		}

		for(size_t i = 0; i < tmp.rowSize(); ++i)
		{
			double bt = tmp(i, k);
			if(k != i)
			{
				for(size_t r = 0; r < tmp.colSize(); ++r)
				{
					tmp(i, r) -= tmp(k, r) * bt;
				}
			}
		}
	}

	// Extracting inverted matrix
	matrix.fill(0);
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			matrix(i, j) = tmp(i, j + numberOfCols);
		}
	}

	return matrix;
}

template <size_t numberOfElems>
double dotProduct(const Vector<numberOfElems> & left_vector,
                  const Vector<numberOfElems> & right_vector)
{
	double accumulator = 0;
	for(size_t i = 0; i < numberOfElems; ++i)
	{
		accumulator += (left_vector(i) * right_vector(i));
	}
	return accumulator;
}

template <size_t numberOfElems>
double norm(const Vector<numberOfElems> & vector)
{
	return sqrt(dotProduct(vector, vector));
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator+(const Matrix<numberOfRows, numberOfCols> & l_other,
                                             const Matrix<numberOfRows, numberOfCols> & r_other)
{
	Matrix<numberOfRows, numberOfCols> result;
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			result(i, j) = l_other(i, j) + r_other(i, j);
		}
	}
	return result;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator-(const Matrix<numberOfRows, numberOfCols> & l_other,
                                             const Matrix<numberOfRows, numberOfCols> & r_other)
{
	return l_other + (-1 * r_other);
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfRows> operator*(const Matrix<numberOfRows, numberOfCols> & l_other,
                                             const Matrix<numberOfCols, numberOfRows> & r_other)
{
	Matrix<numberOfRows, numberOfRows> result;

	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfRows; ++j)
		{
			for(size_t k = 0; k < numberOfCols; ++k)
			{
				result(i, j) += l_other(i, k) * r_other(k, j);
			}
		}
	}
	return result;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator+(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other)
{
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			l_other(i, j) += r_other;
		}
	}
	return l_other;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator-(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other)
{
	return l_other + (-1 * r_other);
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator*(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other)
{
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			l_other(i, j) *= r_other;
		}
	}
	return l_other;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator/(Matrix<numberOfRows, numberOfCols> l_other,
                                             double r_other)
{
	return l_other * (1 / r_other);
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator+(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other)
{
	return r_other + l_other;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator-(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other)
{
	return r_other - l_other;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator*(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other)
{
	return r_other * l_other;
}

template <size_t numberOfRows, size_t numberOfCols>
Matrix<numberOfRows, numberOfCols> operator/(double l_other,
                                             Matrix<numberOfRows, numberOfCols> r_other)
{
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			r_other(i, j) = l_other / r_other(i, j);
		}
	}
	return r_other;
}

} // namespace math

template <size_t numberOfRows, size_t numberOfCols>
std::ostream & operator<<(std::ostream & stream,
                          const math::Matrix<numberOfRows, numberOfCols> & matrix)
{
	for(size_t i = 0; i < numberOfRows; ++i)
	{
		for(size_t j = 0; j < numberOfCols; ++j)
		{
			stream << matrix(i, j) << "\t";
		}
		stream << "\n";
	}

	return stream;
}