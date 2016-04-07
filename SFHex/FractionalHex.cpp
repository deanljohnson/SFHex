#include "stdafx.h"
#include "FractionalHex.h"

float FractionalHex::Length() const
{
	return (abs(X) + abs(Y) + abs(Z)) / 2.0f;
}

Hex FractionalHex::Round() const
{
	auto rx = int(roundf(X));
	auto ry = int(roundf(Y));
	auto rz = int(roundf(Z));
	auto xDif = abs(rx - X);
	auto yDif = abs(ry - Y);
	auto zDif = abs(rz - Z);

	if (xDif > yDif && xDif > zDif)
	{
		rx = -ry - rz;
	}
	else if (yDif > zDif)
	{
		ry = -rx - rz;
	}
	else
	{
		rz = -rx - ry;
	}

	return Hex(rx, ry, rz);
}


FractionalHex FractionalHex::operator=(const FractionalHex& rhs)
{
	return FractionalHex(rhs.X, rhs.Y, rhs.Z);
}

FractionalHex FractionalHex::operator+=(const FractionalHex& rhs)
{
	return FractionalHex(X + rhs.X, Y + rhs.Y, Z + rhs.Z);
}

FractionalHex FractionalHex::operator-=(const FractionalHex& rhs)
{
	return FractionalHex(X - rhs.X, Y - rhs.Y, Z - rhs.Z);
}

FractionalHex FractionalHex::operator*=(const FractionalHex& rhs)
{
	return FractionalHex(X * rhs.X, Y * rhs.Y, Z * rhs.Z);
}

FractionalHex FractionalHex::operator/=(const FractionalHex& rhs)
{
	return FractionalHex(X / rhs.X, Y / rhs.Y, Z / rhs.Z);
}

const FractionalHex FractionalHex::operator+(const FractionalHex& other)
{
	return FractionalHex(*this) += other;
}

const FractionalHex FractionalHex::operator-(const FractionalHex& other)
{
	return FractionalHex(*this) -= other;
}

const FractionalHex FractionalHex::operator*(const FractionalHex& other)
{
	return FractionalHex(*this) *= other;
}

const FractionalHex FractionalHex::operator/(const FractionalHex& other)
{
	return FractionalHex(*this) /= other;
}

bool FractionalHex::operator==(const FractionalHex& other) const
{
	return X == other.X && Y == other.Y && Z == other.Z;
}

bool FractionalHex::operator!=(const FractionalHex& other) const
{
	return !(*this == other);
}