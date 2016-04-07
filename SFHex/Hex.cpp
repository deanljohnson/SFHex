#include "stdafx.h"
#include "Hex.h"
#include "HexUtils.h"
#include "Layout.h"

const Hex Hex::Zero{ 0, 0, 0 };

std::vector<sf::Vector2f> Hex::GetCorners(const Layout& l) const
{
	std::vector<sf::Vector2f> corners {};
	auto center = HexUtils::HexToPixel(*this, l);

	for (auto i = 0; i < 6; i++)
	{
		corners.push_back(center + l.GetCornerOffset(i));
	}

	return corners;
}

int Hex::Length() const
{
	return (abs(X) + abs(Y) + abs(Z)) / 2;
}

Hex Hex::operator=(const Hex& rhs)
{
	return Hex(rhs.X, rhs.Y, rhs.Z);
}

Hex Hex::operator+=(const Hex& rhs)
{
	return Hex(X + rhs.X, Y + rhs.Y, Z + rhs.Z);
}

Hex Hex::operator-=(const Hex& rhs)
{
	return Hex(X - rhs.X, Y - rhs.Y, Z - rhs.Z);
}

Hex Hex::operator*=(const Hex& rhs)
{
	return Hex(X * rhs.X, Y * rhs.Y, Z * rhs.Z);
}

Hex Hex::operator/=(const Hex& rhs)
{
	return Hex(X / rhs.X, Y / rhs.Y, Z / rhs.Z);
}

const Hex Hex::operator+(const Hex& other)
{
	return Hex(*this) += other;
}

const Hex Hex::operator-(const Hex& other)
{
	return Hex(*this) -= other;
}

const Hex Hex::operator*(const Hex& other)
{
	return Hex(*this) *= other;
}

const Hex Hex::operator/(const Hex& other)
{
	return Hex(*this) /= other;
}

bool Hex::operator==(const Hex& other) const
{
	return X == other.X && Y == other.Y && Z == other.Z;
}

bool Hex::operator!=(const Hex& other) const
{
	return !(*this == other);
}