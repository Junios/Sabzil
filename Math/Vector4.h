#ifndef __VECTOR4_H__
#define __VECTOR4_H__

namespace Sabzil
{
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

		Vector4();
		Vector4(const float*);
		Vector4(const Vector4&);
		Vector4(float, float, float, float = 1.0f);

		operator float* ();
		operator const float* () const;

		Vector4& operator += (const Vector4&);
		Vector4& operator -= (const Vector4&);
		Vector4& operator *= (const Vector4&);
		Vector4& operator /= (const Vector4&);

		Vector4& operator *= (float);
		Vector4& operator /= (float);

		Vector4 operator + (const Vector4&) const;
		Vector4 operator - (const Vector4&) const;
		Vector4 operator * (float) const;
		Vector4 operator / (float) const;

		bool operator == (const Vector4&) const;
		bool operator != (const Vector4&) const;

		float operator[] (int);
		const float operator[] (int) const;

		Vector4 operator - () const;

		float Length() const;
		float LengthSquared() const;
		Vector4 Normalize();
		void Identity();
		void Zero();

		friend Vector4 operator * (float, const Vector4&);
		friend float Dot(const Vector4&, const Vector4&);
		friend float Distance(const Vector4&, const Vector4&);
		friend float DistanceSquared(const Vector4&, const Vector4&);
	};
}

#endif