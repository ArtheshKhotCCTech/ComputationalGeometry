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
		static_assert(std::is_arithmetic<coordinate_type>, "Can only store integer or floating point numbers");
		static_assert(dimension >= DIM2, "Vector should atleast be 2D");

		std::array<coordinate_type, dimension> coords;

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
	};

	
	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator==(const Vector<coordinate_type, dimension>)
	{
		for (size_t i = 0; i < dimension; i++) {
			if (!isEqualD(coords[i], _other.coords[i]))
				return false;
		}
		return true;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator!=(const Vector<coordinate_type, dimension>)
	{
		return !(*this == _other);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>&) const
	{
		std::array<coordinate_type, dimension> temp_array;

		for (size_t i = 0; i < dimension; i++) {
			temp_array[i] = coords[i] + _other.coords[i];
		}
		return Vector<coordinate_type, dimension>(temp_array);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>&) const
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

}