#include "stdafx.h"
#include "HexUtils.h"
#include "Layout.h"

sf::Vector2f HexUtils::HexToPixel(const Hex& h, const Layout& l)
{
	auto o = l.Orientation;
	auto x = (o.F0 * h.X + o.F1 * h.Y) * l.Size.x;
	auto y = (o.F2 * h.X + o.F3 * h.Y) * l.Size.y;

	return sf::Vector2f(x + l.Origin.x, y + l.Origin.y);
}