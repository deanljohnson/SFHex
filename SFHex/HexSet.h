#pragma once

#ifndef HEXSET_H
#define HEXSET_H

#include <SFML/Graphics/Transformable.hpp>
#include <unordered_set>
#include "Hex.h"
#include "Layout.h"

class SFHEX_API HexSet : sf::Transformable
{
private:
	HexSet(const Orientation& o, const sf::Vector2f& cellSize)
		: Layout(o, cellSize, sf::Vector2f(0, 0)) {};

	std::unordered_set<Hex> m_HexSet;
protected:
	Layout Layout;

public:
	HexSet(int rad, const Orientation& o, const sf::Vector2f& cellSize);
	HexSet(int x1, int x2, int y1, int y2, const Orientation& o, const sf::Vector2f& cellSize);
	HexSet(std::vector<Hex> hexes, const Orientation& o, const sf::Vector2f& cellSize);

	bool Add(Hex h);
	void UnionWith(const Hex hexes[]);
	void ExceptWith(const Hex hexes[]);
	void Clear();
	sf::Vector2f GetHexPosition(const Hex& h);
	Hex GetNearestWholeHex(sf::Vector2f p);
};

#endif
