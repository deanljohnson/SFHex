#pragma once

#ifndef HEX_H
#define HEX_H

#include <vector>
#include "SFHex.h"
#include <SFML/System/Vector2.hpp>

struct Layout;

struct SFHEX_API Hex
{
	Hex(int x, int y) 
		: X(x), Y(y), Z(-x-y) {};
	Hex(int x, int y, int z)
		: X(x), Y(y), Z(z) {};
	Hex(const Hex& h)
		: X(h.X), Y(h.Y), Z(h.Z) {};
	~Hex() noexcept {};

	const int X, Y, Z;

	//Returns a vector of the locations of this Hex's corners
	std::vector<sf::Vector2f> GetCorners(const Layout& l) const;
	int Length() const;

	Hex operator=(const Hex& rhs);
	Hex operator+=(const Hex& rhs);
	Hex operator-=(const Hex& rhs);
	Hex operator*=(const Hex& rhs);
	Hex operator/=(const Hex& rhs);
	const Hex operator+(const Hex& other);
	const Hex operator-(const Hex& other);
	const Hex operator*(const Hex& other);
	const Hex operator/(const Hex& other);
	bool operator==(const Hex& other) const;
	bool operator!=(const Hex& other) const;

	static const Hex Zero;
};

#endif