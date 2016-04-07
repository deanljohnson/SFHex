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

FractionalHex HexUtils::PixelToHex(const sf::Vector2f& p, const Layout& l) 
{
	auto o = l.Orientation;
	auto pt = sf::Vector2f((p.x - l.Origin.x) / l.Size.x, (p.y - l.Origin.y) / l.Size.y);

	auto x = o.B0*pt.x + o.B1*pt.y;
	auto y = o.B2*pt.x + o.B3*pt.y;

	return FractionalHex(x, y);
}

Hex HexUtils::PixelToWholeHex(const sf::Vector2f& p, const Layout& l)
{
	auto o = l.Orientation;
	auto pt = sf::Vector2f((p.x - l.Origin.x) / l.Size.x, (p.y - l.Origin.y) / l.Size.y);

	auto x = o.B0*pt.x + o.B1*pt.y;
	auto y = o.B2*pt.x + o.B3*pt.y;

	return FractionalHex(x, y).Round();
}