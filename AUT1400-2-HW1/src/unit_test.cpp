// tests/test_matrix.cpp

#include <gtest/gtest.h>
#include "../include/6.2.hpp"
#include <sstream>

// 测试默认构造 + 值初始化
TEST(MatrixTest, ConstructorWithValue) {
    Matrix<int> m(2, 3, 5);
    EXPECT_EQ(m.rows(), 2);
    EXPECT_EQ(m.cols(), 3);
    EXPECT_EQ(m(0, 0), 5);
    EXPECT_EQ(m(1, 2), 5);
}

// 测试拷贝构造
TEST(MatrixTest, CopyConstructor) {
    Matrix<int> m1(2, 2, 3);
    Matrix<int> m2(m1);
    EXPECT_EQ(m2(0, 0), 3);
    m1(0, 0) = 99;
    EXPECT_EQ(m2(0, 0), 3); // 确保是深拷贝
}

// 测试加法
TEST(MatrixTest, Addition) {
    Matrix<int> m1(2, 2, 2);
    Matrix<int> m2(2, 2, 3);
    Matrix<int> result = m1 + m2;
    EXPECT_EQ(result(0, 0), 5);
    EXPECT_EQ(result(1, 1), 5);
}

// 测试加法维度检查（应抛出异常）
TEST(MatrixTest, AdditionDimensionMismatch) {
    Matrix<int> m1(2, 3);
    Matrix<int> m2(3, 2);
    EXPECT_THROW({
        try {
            auto res = m1 + m2;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrix dimensions must be equal", e.what());
            throw;
        }
    }, std::invalid_argument);
}

// 测试乘法
TEST(MatrixTest, Multiplication) {
    Matrix<int> m1(2, 3, 1); // 全1
    Matrix<int> m2(3, 2, 2); // 全2
    Matrix<int> result = m1 * m2;
    EXPECT_EQ(result.rows(), 2);
    EXPECT_EQ(result.cols(), 2);
    EXPECT_EQ(result(0, 0), 6); // 1*2 + 1*2 + 1*2 = 6
}

// 测试 transpose
TEST(MatrixTest, Transpose) {
    Matrix<int> m(2, 3, 0);
    m(0, 0) = 1; m(0, 1) = 2; m(0, 2) = 3;
    m(1, 0) = 4; m(1, 1) = 5; m(1, 2) = 6;

    Matrix<int> t = Matrix<int>::transpose(m);
    EXPECT_EQ(t.rows(), 3);
    EXPECT_EQ(t.cols(), 2);
    EXPECT_EQ(t(0, 0), 1);
    EXPECT_EQ(t(1, 0), 2);
    EXPECT_EQ(t(2, 0), 3);
    EXPECT_EQ(t(0, 1), 4);
}

// 测试 determinant（2x2）
TEST(MatrixTest, Determinant2x2) {
    Matrix<int> m(2, 2);
    m(0,0) = 1; m(0,1) = 2;
    m(1,0) = 3; m(1,1) = 4;
    EXPECT_DOUBLE_EQ(Matrix<int>::determinant(m), -2);
}

// 测试 determinant（1x1）
TEST(MatrixTest, Determinant1x1) {
    Matrix<int> m(1, 1, 5);
    EXPECT_EQ(Matrix<int>::determinant(m), 5);
}

// 测试 inverse（1x1）
TEST(MatrixTest, Inverse1x1) {
    Matrix<double> m(1, 1, 4);
    Matrix<double> inv = Matrix<double>::inverse(m);
    EXPECT_NEAR(inv(0, 0), 0.25, 1e-6);
}

// 测试 ero_swap
TEST(MatrixTest, EroSwap) {
    Matrix<int> m(2, 2, 0);
    m(0, 0) = 1; m(0, 1) = 2;
    m(1, 0) = 3; m(1, 1) = 4;

    Matrix<int> swapped = Matrix<int>::ero_swap(m, 0, 1);
    EXPECT_EQ(swapped(0, 0), 3);
    EXPECT_EQ(swapped(1, 1), 2);
}

// 测试 concatenate (axis=0)
TEST(MatrixTest, ConcatenateVertical) {
    Matrix<int> m1(2, 2, 1);
    Matrix<int> m2(1, 2, 9);
    Matrix<int> cat = Matrix<int>::concatenate(m1, m2, 0);
    EXPECT_EQ(cat.rows(), 3);
    EXPECT_EQ(cat.cols(), 2);
    EXPECT_EQ(cat(2, 0), 9);
}

// 测试 concatenate (axis=1)
TEST(MatrixTest, ConcatenateHorizontal) {
    Matrix<int> m1(2, 2, 1);
    Matrix<int> m2(2, 1, 8);
    Matrix<int> cat = Matrix<int>::concatenate(m1, m2, 1);
    EXPECT_EQ(cat.rows(), 2);
    EXPECT_EQ(cat.cols(), 3);
    EXPECT_EQ(cat(0, 2), 8);
}

// 测试 upper_triangular
TEST(MatrixTest, UpperTriangular) {
    Matrix<double> m(2, 2);
    m(0,0) = 1; m(0,1) = 2;
    m(1,0) = 2; m(1,1) = 5;

    Matrix<double> upper = Matrix<double>::upper_triangular(m);
    EXPECT_NEAR(upper(0,0), 1, 1e-6);
    EXPECT_NEAR(upper(1,0), 0, 1e-6); // 消元后应为 0
}

TEST(MatrixTest, Subtraction) {
    Matrix<int> m1(2, 2, 5);
    Matrix<int> m2(2, 2, 2);
    Matrix<int> result = m1 - m2;
    EXPECT_EQ(result(0,0), 3);
    EXPECT_EQ(result(1,1), 3);
}

TEST(MatrixTest, SumWithScalar) {
    Matrix<int> m(2, 2, 1);
    Matrix<int> result = Matrix<int>::sum(m, 10);
    EXPECT_EQ(result(0,0), 11);
}

TEST(MatrixTest, MultiplyByScalar) {
    Matrix<int> m(2, 2, 3);
    Matrix<int> result = Matrix<int>::Multiply(m, 4);
    EXPECT_EQ(result(0,0), 12);
}

TEST(MatrixTest, Minor) {
    Matrix<int> m(3, 3);
    m(0,0)=1; m(0,1)=2; m(0,2)=3;
    m(1,0)=4; m(1,1)=5; m(1,2)=6;
    m(2,0)=7; m(2,1)=8; m(2,2)=9;

    Matrix<int> minor = Matrix<int>::minor(m, 0, 0); // 去掉第0行第0列
    EXPECT_EQ(minor.rows(), 2);
    EXPECT_EQ(minor.cols(), 2);
    EXPECT_EQ(minor(0,0), 5);
    EXPECT_EQ(minor(1,1), 9);
}

TEST(MatrixTest, EroMultiply) {
    Matrix<int> m(2, 2, 1);
    Matrix<int> result = Matrix<int>::ero_multiply(m, 0, 5);
    EXPECT_EQ(result(0,0), 5);
    EXPECT_EQ(result(1,0), 1); // 第二行不变
}

TEST(MatrixTest, EroSum) {
    Matrix<int> m(2, 2, 1);
    // R1 ← R1 + 2*R0
    Matrix<int> result = Matrix<int>::ero_sum(m, 0, 2, 1);
    EXPECT_EQ(result(1,0), 3); // 1 + 2*1 = 3
}

TEST(MatrixTest, RandomMatrix) {
    Matrix<double> m(10, 10, 1.0, 5.0);
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.cols(); ++j) {
            EXPECT_GE(m(i,j), 1.0);
            EXPECT_LE(m(i,j), 5.0);
        }
    }
}