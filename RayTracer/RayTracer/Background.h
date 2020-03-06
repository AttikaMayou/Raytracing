#pragma once

#include "vec3.h"

struct Background
{
	const color sky{ 0.5f, 0.7f, 1.0f };
	const color ground{ 1.f, 1.f, 1.f };

	color Get(const vec3& dir)
	{
		// conversion [-1;+1] vers [0;1]
		// equivalent de (y + 1) / 2
		float t = dir.y * 0.5f + 0.5f;
		//interpolation lineaire (lerp)
		//A*t + B*(1 - t)
		//A + t*(B - A)
		return sky*t + ground*(1.f - t);
	}
};
