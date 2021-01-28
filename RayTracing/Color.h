#pragma once
class Color
{
public:
	float r, g, b, a;
	void SetRGBA(float r, float g, float b, float a);
	void AddRGBA(float r, float g, float b, float a);
	Color(float r, float g, float b, float a);
};

