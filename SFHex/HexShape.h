#pragma once

#ifndef HEXSHAPE_H
#define HEXSHAPE_H

#include "SFHex.h"
#include <SFML/Graphics/ConvexShape.hpp>

struct Layout;

class SFHEX_API HexShape : sf::ConvexShape
{
	explicit HexShape(const Layout& l);
};

#endif 