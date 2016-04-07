#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "HexSet.h"
#include "HexUtils.h"

HexSet::HexSet(int rad, const Orientation& o, const sf::Vector2f& cellSize)
	: HexSet::HexSet(o, cellSize)
{
	m_HexSet = std::unordered_set<Hex>();
	BuildHexMap(rad);
}

HexSet::HexSet(int x1, int x2, int y1, int y2, const Orientation& o, const sf::Vector2f& cellSize)
	: HexSet::HexSet(o, cellSize)
{
	m_HexSet = std::unordered_set<Hex>();
	BuildParallelogramMap(x1, x2, y1, y2);
}

HexSet::HexSet(const std::vector<Hex>& hexes, const Orientation& o, const sf::Vector2f& cellSize)
	: HexSet::HexSet(o, cellSize)
{
	m_HexSet = std::unordered_set<Hex>(hexes.begin(), hexes.end());
}

void HexSet::BuildHexMap(int rad)
{
	for (auto q = -rad; q <= rad; q++)
	{
		auto r1 = max(-rad, -q - rad);
		auto r2 = min(rad, -q + rad);
		for (auto r = r1; r <= r2; r++)
		{
			Add(Hex(q, r));
		}
	}
}

void HexSet::BuildParallelogramMap(int q1, int q2, int r1, int r2)
{
	for (auto q = q1; q <= q2; q++)
	{
		for (auto r = r1; r <= r2; r++)
		{
			Add(Hex(q, r));
		}
	}
}

bool HexSet::Add(Hex h)
{
	m_HexSet.emplace(h);
}

void HexSet::Clear() 
{
	m_HexSet.clear();
}

sf::Vector2f HexSet::GetHexPosition(const Hex& h) 
{
	auto pos = HexUtils::HexToPixel(h, m_Layout);
	return getTransform.transformPoint(pos);
}

Hex HexSet::GetNearestWholeHex(const sf::Vector2f& p) 
{
	auto pos = getInverseTransform.transformPoint(p);
	return HexUtils::PixelToWholeHex(pos, m_Layout);
}

template<typedef ForwardIterator>
void HexSet::UnionWith(ForwardIterator begin, ForwardIterator end)
{
	m_HexSet.emplace(begin, end);
}

template<typedef ForwardIterator>
void HexSet::ExceptWith(ForwardIterator begin, ForwardIterator end)
{
	m_HexSet.erase(begin, end);
}

template<typedef ForwardIterator>
void HexSet::IntersectWith(ForwardIterator begin, ForwardIterator end) 
{
	for (std::unordered_set<Hex>::iterator it = begin(); it != end(); it++) 
	{
		if (m_HexSet.find(*it) == m_HexSet.end()) 
		{
			m_HexSet.erase(*it);
		}
	}
}