#include "stdafx.h"
#include "HexShape.h"
#include "Layout.h"
#include "Hex.h"

HexShape::HexShape(const Layout& l)
	: ConvexShape(6)
{
	auto corners = Hex::Zero.GetCorners(l);

	for (unsigned int i = 0; i < corners.size(); i++)
	{
		auto corner = corners[i];
		setPoint(i, corner);
	}
}
