#include "stdafx.h"
#include <math.h>
#include "Orientation.h"

const Orientation Orientation::Pointed 
	{ sqrtf(3), sqrtf(3) / 2, 0, 3 / 2,
	  sqrtf(3) / 3, -1 / 3, 0, 2 / 3, .5 };

const Orientation Orientation::Flat
	{ 3 / 2, 0, sqrtf(3) / 3, sqrtf(3),
	  2 / 3, 0, -1 / 3, sqrtf(3) / 3, 0 };