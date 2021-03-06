#pragma once

#ifndef LAYOUT_H
#define LAYOUT_H

#include "SFML/System.hpp"
#include "Orientation.h"

struct SFHEX_API Layout
{
private:
	sf::Vector2f m_CornerOffsets[6];
	void SetCornerOffsets();

public:
	Layout(Orientation o, sf::Vector2f size, sf::Vector2f origin)
		: Orientation(o), Size(size), Origin(origin)
	{
		SetCornerOffsets();
	};

	~Layout() {};

	const Orientation Orientation;
	const sf::Vector2f Size;
	const sf::Vector2f Origin;
	
	sf::Vector2f GetCornerOffset(int c) const { return m_CornerOffsets[c]; }
};

#endif