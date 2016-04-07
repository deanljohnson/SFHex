#pragma once

#ifndef FRACTIONALHEX_H
#define FRACTIONALHEX_H

#include "Hex.h"

struct SFHEX_API FractionalHex
{
	FractionalHex(float x, float y)
		: X(x), Y(y), Z(-x-y) {};

	FractionalHex(float x, float y, float z)
		: X(x), Y(y), Z(z) {};

	const float X, Y, Z;

	float Length() const;
	Hex Round() const;

	FractionalHex operator=(const FractionalHex& rhs);
	FractionalHex operator+=(const FractionalHex& rhs);
	FractionalHex operator-=(const FractionalHex& rhs);
	FractionalHex operator*=(const FractionalHex& rhs);
	FractionalHex operator/=(const FractionalHex& rhs);
	const FractionalHex operator+(const FractionalHex& other);
	const FractionalHex operator-(const FractionalHex& other);
	const FractionalHex operator*(const FractionalHex& other);
	const FractionalHex operator/(const FractionalHex& other);
	bool operator==(const FractionalHex& other) const;
	bool operator!=(const FractionalHex& other) const;
};

#endif