#pragma once

#ifndef HEXUTILS_H
#define HEXUTILS_H

#include "Hex.h"
#include "FractionalHex.h"

namespace HexUtils
{
	//Returns the center "pixel" of the given Hex
	sf::Vector2f HexToPixel(const Hex& h, const Layout& l);

	FractionalHex PixelToHex(const sf::Vector2f& p, const Layout& l);
	Hex PixelToWholeHex(const sf::Vector2f& p, const Layout& l);
}

#endif