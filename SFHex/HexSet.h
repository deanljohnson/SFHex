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

	void BuildHexMap(int rad);
	void BuildParallelogramMap(int x1, int x2, int y1, int y2);

	std::unordered_set<Hex> m_HexSet;
protected:
	Layout m_Layout;

public:
	HexSet(int rad, const Orientation& o, const sf::Vector2f& cellSize);
	HexSet(int x1, int x2, int y1, int y2, const Orientation& o, const sf::Vector2f& cellSize);
	HexSet(const std::vector<Hex>& hexes, const Orientation& o, const sf::Vector2f& cellSize);

	bool Add(Hex h);
	void Clear();
	sf::Vector2f GetHexPosition(const Hex& h);
	Hex GetNearestWholeHex(const sf::Vector2f& p);

	template<typedef ForwardIterator>
	void UnionWith(ForwardIterator begin, ForwardIterator end);

	template<typedef ForwardIterator>
	void ExceptWith(ForwardIterator begin, ForwardIterator end);
};

#endif
