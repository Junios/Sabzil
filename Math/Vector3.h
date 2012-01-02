#ifndef __VECTOR3_H__
#define __VECTOR3_H__

namespace Sabzil
{
	class Vector3
	{
	public:
		union
		{
			struct
			{
				float x, y, z;
			};
			float v[3];
		};


		Vector3() {};
		Vector3(const float*);
		Vector3(const Vector3&);
		Vector3(float x, float y, float z);

		// casting
		operator float* ();
		operator const float* () const;

		// assignment operators
		Vector3& operator += (const Vector3&);
		Vector3& operator -= (const Vector3&);
		Vector3& operator *= (const Vector3&);
		Vector3& operator /= (const Vector3&);

		Vector3& operator *= (float );
		Vector3& operator /= (float );

		// binary operators
		Vector3 operator + (const Vector3&) const;
		Vector3 operator - (const Vector3&) const;
		Vector3 operator * (float) const;
		Vector3 operator / (float) const;

		//equal, not equal
		bool operator == (const Vector3&) const;
		bool operator != (const Vector3&) const;

		float Length() const;
		Vector3 Normalize();
		void Identity();
		void Zero();

		float operator[] (int i) { return v[i]; }
		const float operator[] (int i) const { return v[i]; }

		float* GetUnits() { return v; }
		const float* GetUnits() const { return v; }


		//friend
		friend Vector3 operator * (float, const Vector3&);
		friend float Dot(const Vector3&, const Vector3&);
		friend Vector3 Cross(const Vector3&, const Vector3&);
		friend float Distance(const Vector3&, const Vector3&);
	};
}

#endif //__VECTOR3_H__