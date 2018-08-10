// Copyright 2018

#include <gtest/gtest.h>
#include "Matrix.hpp"

template <typename T, size_t N, size_t M>
::testing::AssertionResult ArraysMatch(const T (&expected)[N][M],
                                       const math::Matrix<N, M> &matrix);
template <typename T, size_t N>
::testing::AssertionResult ArraysMatch(const T (&expected)[N],
                                       const math::Matrix<N, 1> &matrix);

TEST(MatrixTest, MatrixInitialization) {
  const unsigned numberOfElements = 5;
  math::Vector<numberOfElements> a;
  EXPECT_EQ(numberOfElements, a.rowSize());
  EXPECT_EQ((unsigned)1, a.colSize());

  const unsigned row = 5;
  const unsigned col = 10;
  math::Matrix<row, col> b;
  EXPECT_EQ(row, b.rowSize());
  EXPECT_EQ(col, b.colSize());

  math::Vector<3> c({1, 2, 3});
  ArraysMatch({1, 2, 3}, c);

  math::Matrix<3, 3> d({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  ArraysMatch({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, d);
}

TEST(MatrixTest, MatrixMatrixOperators) {
  math::Matrix<3, 3> a({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

  ArraysMatch({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}}, a + a);

  ArraysMatch({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, a - a);

  ArraysMatch({{30, 36, 42}, {66, 81, 96}, {102, 126, 150}}, a * a);
}

TEST(MatrixTest, MatrixSkalarOperators) {
  math::Matrix<3, 3> a({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

  ArraysMatch({{3, 4, 5}, {6, 7, 8}, {9, 10, 11}}, a + 2);

  ArraysMatch({{-1, 0, 1}, {2, 3, 4}, {5, 6, 7}}, a - 2);

  ArraysMatch({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}}, a * 2);

  ArraysMatch({{0.5, 1.0, 1.5}, {2.0, 2.5, 3.0}, {3.5, 4.0, 4.5}}, a / 2);
}

TEST(MatrixTest, TransposeDeterminantInverse) {
  math::Matrix<3, 3> a({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

  math::Vector<3> b({1, 2, 3});

  ArraysMatch({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}, math::transpose(a));

  ArraysMatch({{1, 2, 3}}, math::transpose(b));

  math::Matrix<3, 3> c({{1, -2, 3}, {-4, 5, -6}, {7, 8, 9}});

  EXPECT_FLOAT_EQ(0, math::det(a));
  EXPECT_FLOAT_EQ(-96, math::det(c));

  ArraysMatch({{-0.96875, -0.4375, 0.03125},
               {0.0625, 0.125, 0.0625},
               {0.697917, 0.229167, 0.03125}},
              math::inv(c));
}

TEST(MatrixTest, VectorSpecificFreeFunctions) { EXPECT_TRUE(true); }

// ---------------------------------------------------------

template <typename T, size_t N, size_t M>
::testing::AssertionResult ArraysMatch(const T (&expected)[N][M],
                                       const math::Matrix<N, M> &matrix) {
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < M; ++j) {
      if (expected[i][j] != matrix(i, j)) {
        return ::testing::AssertionFailure()
               << "array[" << i << "] (" << matrix(i, j) << ") != expected["
               << i << "] (" << expected[i][j] << ")";
      }
    }
  }
  return ::testing::AssertionSuccess();
}

template <typename T, size_t N>
::testing::AssertionResult ArraysMatch(const T (&expected)[N],
                                       const math::Vector<N> &vector) {
  for (size_t i = 0; i < N; ++i) {
    if (expected[i] != vector(i)) {
      return ::testing::AssertionFailure()
             << "array[" << i << "] (" << vector(i) << ") != expected[" << i
             << "] (" << expected[i] << ")";
    }
  }
  return ::testing::AssertionSuccess();
}
