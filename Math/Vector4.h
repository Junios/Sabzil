#ifndef __VECTOR4_H__
#define __VECTOR4_H__

class Vector4
{
public:
	union
	{
		struct
		{
			float x, y, z, w;
		};
		float v[4];
	};

	// constructor
	Vector4();
	Vector4(const float*);
	Vector4(const Vector4&);
	Vector4(float, float, float, float = 1.0f);

	// casting operators
	operator float* ();
	operator const float* () const;

	// assignment operators(by another vector)
	Vector4& operator += (const Vector4&);
	Vector4& operator -= (const Vector4&);
	Vector4& operator *= (const Vector4&);
	Vector4& operator /= (const Vector4&);

	// assignment operators(by scalar)
	Vector4& operator *= (float);
	Vector4& operator /= (float);

	// binary operators
	Vector4 operator + (const Vector4&) const;
	Vector4 operator - (const Vector4&) const;
	Vector4 operator * (float) const;
	Vector4 operator / (float) const;

	// equality and inequality operators
	bool operator == (const Vector4&) const;
	bool operator != (const Vector4&) const;

	// indexing operators
	float operator[] (int);
	const float operator[] (int) const;

	// unary operator
	Vector4 operator - () const;

	float Length() const;
	float LengthSquared() const;
	Vector4 Normalize();
	void Unit();
	void Zero();

	// friends
	friend Vector4 operator * (float, const Vector4&);
	friend float Dot(const Vector4&, const Vector4&);
	friend float Distance(const Vector4&, const Vector4&);
	friend float DistanceSquared(const Vector4&, const Vector4&);
};

#endif
