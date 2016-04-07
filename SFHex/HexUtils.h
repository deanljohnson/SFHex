#pragma once

#ifndef HEXUTILS_H
#define HEXUTILS_H

#include "Hex.h"

namespace HexUtils
{
	//Returns the center "pixel" of the given Hex
	sf::Vector2f HexToPixel(const Hex& h, const Layout& l);
}

#endif