#include "Vector3.h"
#include "math.h"

namespace Sabzil
{
	Vector3::Vector3(const float* src)
	{
		x = src[0];
		y = src[1];
		z = src[2];
	}

	Vector3::Vector3(const Vector3& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}

	Vector3::Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	// casting
	Vector3::operator float* ()
	{
		return (float*)&v;
	}
	Vector3::operator const float* () const
	{
		return (float*)&v;
	}

	// assignment operators
	Vector3& Vector3::operator += (const Vector3& _src)
	{
		x += _src.x;
		y += _src.y;
		z += _src.z;

		return (*this);
	}

	Vector3& Vector3::operator -= (const Vector3& _src)
	{
		x -= _src.x;
		y -= _src.y;
		z -= _src.z;

		return (*this);
	}

	Vector3& Vector3::operator *= (const Vector3& _src)
	{
		x *= _src.x;
		y *= _src.y;
		z *= _src.z;

		return (*this);
	}

	Vector3& Vector3::operator /= (const Vector3& _src)
	{
		x /= _src.x;
		y /= _src.y;
		z /= _src.z;

		return (*this);
	}



	Vector3& Vector3::operator *= (float s)
	{
		x *= s;
		y *= s;
		z *= s;

		return (*this);
	}

	Vector3& Vector3::operator /= (float s)
	{
		x /= s;
		y /= s;
		z /= s;

		return (*this);
	}

	// binary operators
	Vector3 Vector3::operator + (const Vector3& _rhs) const
	{
		return Vector3(x+_rhs.x, y+_rhs.y, z+_rhs.z);
	}

	Vector3 Vector3::operator - (const Vector3& _rhs) const
	{
		return Vector3(x-_rhs.x, y-_rhs.y, z-_rhs.z);
	}

	Vector3 Vector3::operator * (float s) const
	{
		return Vector3(x*s, y*s, z*s);
	}

	Vector3 Vector3::operator / (float s) const
	{
		return Vector3(x/s, y/s, z/s);
	}


	//equal, not equal
	bool Vector3::operator == (const Vector3& _new) const
	{
		return ( (x == _new.x) && (y == _new.y) && (z == _new.z) ) ? true : false;
	}

	bool Vector3::operator != (const Vector3& _new) const
	{
		return ( (x != _new.x) || (y != _new.y) || (z != _new.z) ) ? true : false;
	}

	// unary operator
	Vector3 Vector3::operator - () const
	{
		return Vector3(-x, -y, -z);
	}

	float Vector3::Length() const
	{
		return sqrtf( x * x + y * y + z * z );
	}

	float Vector3::LengthSquared() const
	{
		return ( x * x + y * y + z * z );
	}

	Vector3 Vector3::Normalize()
	{
		float fLength = Length();
		//if( fLength < 1e-8f )
		//	return fLength;

		x /= fLength;
		y /= fLength;
		z /= fLength;

		return (*this);
	}

	void Vector3::Identity()
	{
		x = y = z = 1.0f;
	}

	void Vector3::Zero()
	{
		x = y = z = 0.0f;
	}



	//friend
	Vector3 operator * (float s, const Vector3& rhs)
	{
		return Vector3((s*rhs.x), (s*rhs.y), (s*rhs.z));
	}

	float Dot(const Vector3 &lhs, const Vector3 &rhs)
	{
		return (lhs.x*rhs.x) + (lhs.y*rhs.y) + (lhs.z*rhs.z);
	}

	Vector3 Cross(const Vector3 &lhs, const Vector3 &rhs)
	{
		return Vector3(lhs.y*rhs.z - lhs.z*rhs.y, lhs.z*rhs.x - lhs.x*rhs.z, lhs.x*rhs.y - lhs.y*rhs.x);
	}


	float Distance(const Vector3 &lhs, const Vector3 &rhs)
	{
		return sqrtf( (lhs.x-rhs.x) * (lhs.x-rhs.x) + (lhs.y-rhs.y)*(lhs.y-rhs.y) + (lhs.z-rhs.z)*(lhs.z-rhs.z) );
	}

	float DistanceSquared(const Vector3 &lhs, const Vector3 &rhs)
	{
		return (lhs.x-rhs.x) * (lhs.x-rhs.x) + (lhs.y-rhs.y)*(lhs.y-rhs.y) + (lhs.z-rhs.z)*(lhs.z-rhs.z);
	}

}
