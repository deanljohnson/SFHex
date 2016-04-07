#include "stdafx.h"
#include <vector>
#include "HexSet.h"

HexSet::HexSet(int rad, const Orientation& o, const sf::Vector2f& cellSize)
	: HexSet::HexSet(o, cellSize)
{
	BuildHexMap(rad, this);
}

HexSet::HexSet(int x1, int x2, int y1, int y2, const Orientation& o, const sf::Vector2f& cellSize)
	: HexSet::HexSet(o, cellSize)
{
	BuildParallelogramMap(x1, x2, y1, y2);
}

HexSet::HexSet(std::vector<Hex> hexes, const Orientation& o, const sf::Vector2f& cellSize)
	: HexSet::HexSet(o, cellSize)
{
	m_HexSet = std::unordered_set<Hex>(hexes.begin(), hexes.end());
}
