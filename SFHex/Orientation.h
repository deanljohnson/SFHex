#pragma once

#ifndef ORIENTATION_H
#define ORIENTATION_H

#include "SFHex.h"

struct SFHEX_API Orientation
{
	Orientation(float f0, float f1, float f2, float f3,
				float b0, float b1, float b2, float b3,
				float startAngle) 
		: F0(f0), F1(f1), F2(f2), F3(f3), 
		  B0(b0), B1(b1), B2(b2), B3(b3), 
		  StartAngle(startAngle){};
	~Orientation() {};

	const float F0, F1, F2, F3, B0, B1, B2, B3, StartAngle;

	static const Orientation Pointed;
	static const Orientation Flat;
};

#endif