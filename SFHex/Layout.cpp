#include "stdafx.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>
#include "Layout.h"

sf::Vector2f CornerOffset(int c, const Layout& l)
{
	auto angle = 2.0 * M_PI * (c + l.Orientation.StartAngle / 6.0);

	return sf::Vector2f(l.Size.x * float(cos(angle)), l.Size.y * float(sin(angle)));
}

void Layout::SetCornerOffsets()
{
	for (auto i = 0; i < 6; i++)
	{
		m_CornerOffsets[i] = CornerOffset(i, *this);
	}
}