#ifndef __MATRIX4_H__
#define __MATRIX4_H__

namespace Sabzil
{
	class Matrix4
	{
	public:
		union
		{
			struct 
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;

			};
			float m[4][4];
		};

		Matrix4() {};
		Matrix4( const float * );
		Matrix4( const Matrix4& );
		Matrix4( float _11, float _12, float _13, float _14,
				  float _21, float _22, float _23, float _24,
				  float _31, float _32, float _33, float _34,
				  float _41, float _42, float _43, float _44 );

		//float& operator () ( unsigned int Row, unsigned int Col );
		//float  operator () ( unsigned int Row, unsigned int Col ) const;

		operator float* ();
		operator const float* () const;

		Matrix4& operator*= ( const Matrix4& );
		Matrix4& operator+= ( const Matrix4& );
		Matrix4& operator-= ( const Matrix4& );
		Matrix4& operator*= ( float );
		Matrix4& operator/= ( float );

		Matrix4 operator* ( const Matrix4& ) const;
		Matrix4 operator+ ( const Matrix4& ) const;
		Matrix4 operator- ( const Matrix4& ) const;
		Matrix4 operator* ( float ) const;
		Matrix4 operator/ ( float ) const;

		friend Matrix4 operator* ( float, const Matrix4& );

		bool operator== ( const Matrix4& ) const;
		bool operator!= ( const Matrix4& ) const;

		Matrix4 Invert( Matrix4& oOut );
		void Identity();
		void Multyply( Matrix4& oOut, Matrix4& oLhs, Matrix4& oRhs );
		void Transpose();
	};
}


#endif //__Matrix4_H__