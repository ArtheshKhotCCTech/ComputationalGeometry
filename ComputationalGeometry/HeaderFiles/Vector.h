#pragma once

#include<iostream>
#include<array>

namespace jmk {

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2

	template<class coordinate_type,size_t dimension = DIM3>
	class Vector {
		static_assert(std::is_arithmetic_v<coordinate_type>, "Can only store integer or floating point numbers");
		static_assert(dimension >= DIM2, "Vector should atleast be 2D");

		std::array<coordinate_type, dimension> coords;

		template<class coordinate_type, size_t dimension>
		friend float dotProduct(const Vector<coordinate_type, dimension>& v1, const Vector<coordinate_type, dimension>& v2);

	public:

		Vector() {}

		Vector(std::array<coordinate_type, dimension> _coords) : coords(_coords) {}

		Vector(coordinate_type _X, coordinate_type _Y, coordinate_type _Z) : coords({ _X, _Y, _Z }) {}

		Vector(coordinate_type _X, coordinate_type _Y) : coords({ _X, _Y}) {}

		//Equality Check
		bool operator==(const Vector < coordinate_type, dimension>);

		//Not Equal Check
		bool operator!=(const Vector < coordinate_type, dimension>);

		//Addition
		Vector<coordinate_type, dimension> operator+ (const Vector < coordinate_type, dimension>&) const;

		//Substraction
		Vector<coordinate_type, dimension> operator- (const Vector < coordinate_type, dimension>&) const;

		//Less than operator
		bool operator<(const Vector < coordinate_type, dimension>&);

		//Greater than operator
		bool operator>(const Vector < coordinate_type, dimension>&);

		//Indexing operator
		coordinate_type operator[](int) const;

		//Assign
		void assign(int dim, coordinate_type value);

		//Magnitude
		float magnitude() const;

		//Normalization
		void normalize();
	};

	typedef Vector<float, DIM2> Vector2f;
	typedef Vector<float, DIM3> Vector3f;

	
	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator==(const Vector<coordinate_type, dimension> _other)
	{
		for (size_t i = 0; i < dimension; i++) {
			if (!isEqualD(coords[i], _other.coords[i]))
				return false;
		}
		return true;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator!=(const Vector<coordinate_type, dimension> _other)
	{
		return !(*this == _other);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>& _other) const
	{
		std::array<coordinate_type, dimension> temp_array;

		for (size_t i = 0; i < dimension; i++) {
			temp_array[i] = coords[i] + _other.coords[i];
		}
		return Vector<coordinate_type, dimension>(temp_array);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>& _other) const
	{
		std::array<coordinate_type, dimension> temp_array;

		for (size_t i = 0; i < dimension; i++) {
			temp_array[i] = coords[i] - _other.coords[i];
		}
		return Vector<coordinate_type, dimension>(temp_array);
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator<(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++) {
			if (this->coords[i] < _other.coords[i]) {
				return true;
			}
			else if (this->coords[i] > _other.coords[i]) {
				return false;
			}
		}
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator>(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++) {
			if (this->coords[i] > _other.coords[i]) {
				return true;
			}
			else if (this->coords[i] < _other.coords[i]) {
				return false;
			}
		}
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline coordinate_type Vector<coordinate_type, dimension>::operator[](int _index) const
	{
		if (_index >= coords.size()) {
			std::cout << "Index out of bound\n";
			return coordinate_type();
		}
		return coords[_index];
	}

	template<class coordinate_type, size_t dimension>
	inline void Vector<coordinate_type, dimension>::assign(int dim, coordinate_type value)
	{
		if (dim >= coords.size()) {
			std::cout << "Index out of bound\n";
		}

		coords[dim] = value;
	}

	template<class coordinate_type, size_t dimension>
	inline float Vector<coordinate_type, dimension>::magnitude() const
	{
		float value = 0.0f;

		for (size_t i = 0; i < dimension; i++) {
			value += pow(coords[i] * 2.0);
		}
		return sqrt(value);
	}

	template<class coordinate_type, size_t dimension>
	inline void Vector<coordinate_type, dimension>::normalize()
	{
		auto mag = magnitude();
		for (size_t i = 0; i < dimension; i++) {
			assign(i, coords[i] / mag);
		}
	}

	template<class coordinate_type, size_t dimension>
	float dotProduct(const Vector<coordinate_type, dimension>& v1, const Vector<coordinate_type, dimension>& v2)
	{
		if (v1.coords.size() != v2.coords.size()) {
			return FLT_MIN;
		}

		float product = 0.0;
		for (size_t i = 0; i < dimension; i++) {
			product += v1[i] * v2[i];
		}
		return product;
	}

	float crossProduct2D(Vector2f v1, Vector2f v2);
	Vector3f crossProduct3D(Vector3f v1, Vector3f v2);
}