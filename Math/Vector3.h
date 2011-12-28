#ifndef __VECTOR3_H__
#define __VECTOR3_H__


//#ifndef D3DMATRIX_DEFINED
//typedef struct _D3DMATRIX {
//	union {
//		struct {
//			float        _11, _12, _13, _14;
//			float        _21, _22, _23, _24;
//			float        _31, _32, _33, _34;
//			float        _41, _42, _43, _44;
//
//		};
//		float m[4][4];
//	};
//} D3DMATRIX;

namespace Junios
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
};

#endif //__VECTOR3_H__