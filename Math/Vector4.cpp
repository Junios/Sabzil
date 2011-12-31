#include "Vector4.h"
#include "math.h"

// constructor
Vector4::Vector4(void)
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

Vector4::Vector4(const float* src)
{
	this->x = src[0];
	this->y = src[1];
	this->z = src[2];
	this->w = src[3];
}

Vector4::Vector4(const Vector4& src)
{
	this->x = src.x;
	this->y = src.y;
	this->z = src.z;
	this->w = src.w;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
	
// casting operators
Vector4::operator float* ()
{
	return v;
}

Vector4::operator const float* () const
{
	return v;
}

// assignment operators(by another vector)
Vector4& Vector4::operator += (const Vector4& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;

	return (*this);
}

Vector4& Vector4::operator -= (const Vector4& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;

	return (*this);
}

Vector4& Vector4::operator *= (const Vector4& rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	this->w *= rhs.w;

	return (*this);
}

Vector4& Vector4::operator /= (const Vector4& rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	this->w /= rhs.w;

	return (*this);
}

// assignment operators(by scalar)
Vector4& Vector4::operator *= (float s)
{
	this->x *= s;
	this->y *= s;
	this->z *= s;
	this->w *= s;

	return (*this);
}

Vector4& Vector4::operator /= (float d)
{
	const float fOnePerD = 1.0f / d;
	this->x *= fOnePerD;
	this->y *= fOnePerD;
	this->z *= fOnePerD;
	this->w *= fOnePerD;

	return (*this);
}

// binary operators
Vector4 Vector4::operator + (const Vector4& rhs) const
{
	return Vector4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

Vector4 Vector4::operator - (const Vector4& rhs) const
{
	return Vector4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
}

Vector4 Vector4::operator * (float s) const
{
	return Vector4(this->x * s, this->y * s, this->z * s, this->w * s);
}

Vector4 Vector4::operator / (float d) const
{
	const float fOnePerD = 1.0f / d;
	return Vector4(this->x * fOnePerD, this->y * fOnePerD, this->z * fOnePerD, this->w * fOnePerD);
}

// equality and inequality operators
bool Vector4::operator == (const Vector4& rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w);
}

bool Vector4::operator != (const Vector4& rhs) const
{
	return (this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w);
}

// indexing operators
float Vector4::operator[] (int i)
{
	return this->v[i];
}

const float Vector4::operator[] (int i) const
{
	return this->v[i];
}

// unary operator
Vector4 Vector4::operator - () const
{
	return Vector4(-this->x, -this->y, -this->z, -this->w);
}

float Vector4::Length() const
{
	return sqrtf( (this->x * this->x)
				+ (this->y * this->y)
				+ (this->z * this->z)
				+ (this->w * this->w) );
}

float Vector4::LengthSquared() const
{
	return ( (this->x * this->x)
			+ (this->y * this->y)
			+ (this->z * this->z)
			+ (this->w * this->w) );
}

Vector4 Vector4::Normalize()
{
	const float fOnePerLength = 1.0f / sqrtf( (this->x * this->x)
										+ (this->y * this->y)
										+ (this->z * this->z)
										+ (this->w * this->w) );

	this->x *= fOnePerLength;
	this->y *= fOnePerLength;
	this->z *= fOnePerLength;
	this->w *= fOnePerLength;

	return (*this);
}

void Vector4::Unit()
{
	this->x = this->y = this->z = this->w = 1.0f;
}

void Vector4::Zero()
{
	this->x = this->y = this->z = this->w = 0.0f;
}

// friends
Vector4 operator * (float s, const Vector4& rhs)
{
	return Vector4(s * rhs.x, s * rhs.y, s * rhs.z, s * rhs.w);
}

float Dot(const Vector4& lhs, const Vector4& rhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
}

float Distance(const Vector4& lhs, const Vector4& rhs)
{
	return sqrtf( ((rhs.x - lhs.x) * (rhs.x - lhs.x))
				+ ((rhs.y - lhs.y) * (rhs.y - lhs.y))
				+ ((rhs.z - lhs.z) * (rhs.z - lhs.z))
				+ ((rhs.w - lhs.w) * (rhs.w - lhs.w)) );
}

float DistanceSquared(const Vector4& lhs, const Vector4& rhs)
{
	return ( ((rhs.x - lhs.x) * (rhs.x - lhs.x))
			+ ((rhs.y - lhs.y) * (rhs.y - lhs.y))
			+ ((rhs.z - lhs.z) * (rhs.z - lhs.z))
			+ ((rhs.w - lhs.w) * (rhs.w - lhs.w)) );
}
