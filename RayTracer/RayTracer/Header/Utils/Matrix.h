#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Matrix
{
	size_t row, col;
	vector<float> data;

	Matrix();
	Matrix(size_t rows, size_t cols);
	Matrix(vector<float>& const d, size_t rows, size_t cols);
	Matrix(Matrix& const m);
	~Matrix();

	size_t getRow() const {
		return row;
	};
	size_t getCol() const {
		return col;
	};
	void setRow(size_t const rows);
	void setCol(size_t const cols);
	vector<float> getData(Matrix& const m) {
		return m.data;
	};

	static Matrix Translate(float x, float y);
	static Matrix Rotate(float angle);
	static Matrix Scale(float scale);

	vector<float> identity(Matrix& const m);
	Matrix inverse() const;
	void swap(Matrix& m);

	float& operator()(size_t i, size_t j);
	float operator()(size_t i, size_t j) const;
	Matrix& operator*=(Matrix& const m);
	friend Matrix operator*(Matrix& const m, Matrix& const m2);
	Matrix& operator+=(Matrix& const m);
	friend Matrix operator+(Matrix& const m, Matrix& const m2);
	Matrix operator-=(Matrix& const m);
	friend Matrix operator-(Matrix& const m, Matrix& const m2);
	Matrix& operator=(Matrix& const m);
};

ostream& operator<<(ostream& os, Matrix& r);
