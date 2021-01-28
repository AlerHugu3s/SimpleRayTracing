#include "Color.h"

void Color::SetRGBA(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Color::AddRGBA(float r, float g, float b, float a)
{
	this->r += r;
	this->g += g;
	this->b += b;
	this->a += a;

	if (this->r > 1) this->r = 1;
	if (this->g > 1) this->g = 1;
	if (this->b > 1) this->b = 1;
	if (this->a > 1) this->a = 1;
}

Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
