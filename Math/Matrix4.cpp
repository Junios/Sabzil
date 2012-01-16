#include "Matrix4.h"

namespace Sabzil
{
	Matrix4::Matrix4( const float *pTemp )
	{
		m[0][0] = pTemp[0];
		m[0][1] = pTemp[1];
		m[0][2] = pTemp[2];
		m[0][3] = pTemp[3];

		m[1][0] = pTemp[4];
		m[1][1] = pTemp[5];
		m[1][2] = pTemp[6];
		m[1][3] = pTemp[7];

		m[2][0] = pTemp[8];
		m[2][1] = pTemp[9];
		m[2][2] = pTemp[10];
		m[2][3] = pTemp[11];

		m[3][0] = pTemp[12];
		m[3][1] = pTemp[13];
		m[3][2] = pTemp[14];
		m[3][3] = pTemp[15];
	}

	Matrix4::Matrix4( const Matrix4& oTemp )
	{
		_11 = oTemp._11; _12 = oTemp._12; _13 = oTemp._13; _14 = oTemp._14;
		_21 = oTemp._21; _22 = oTemp._22; _23 = oTemp._23; _24 = oTemp._24;
		_31 = oTemp._31; _32 = oTemp._32; _33 = oTemp._33; _34 = oTemp._34;
		_41 = oTemp._41; _42 = oTemp._42; _43 = oTemp._43; _44 = oTemp._44;
	}


	Matrix4::Matrix4( float _11, float _12, float _13, float _14,
			 float _21, float _22, float _23, float _24,
			 float _31, float _32, float _33, float _34,
			 float _41, float _42, float _43, float _44 )
	{
		this->_11 = _11; this->_12 = _12; this->_13 = _13; this->_14 = _14;
		this->_21 = _21; this->_22 = _22; this->_23 = _23; this->_24 = _24;
		this->_31 = _31; this->_32 = _32; this->_33 = _33; this->_34 = _34;
		this->_41 = _41; this->_42 = _42; this->_43 = _43; this->_44 = _44;
	}



	Matrix4::operator float* ()
	{
		return (float*)this;
	}


	Matrix4::operator const float* () const
	{
		return (float*)this;
	}


	Matrix4& Matrix4::operator*= ( const Matrix4& oRhs )
	{
		this->_11 = this->_11 * oRhs._11 + this->_12 * oRhs._21 + this->_13 * oRhs._31 + this->_14 * oRhs._41; 
		this->_12 = this->_11 * oRhs._12 + this->_12 * oRhs._22 + this->_13 * oRhs._32 + this->_14 * oRhs._42; 
		this->_13 = this->_11 * oRhs._13 + this->_12 * oRhs._23 + this->_13 * oRhs._33 + this->_14 * oRhs._43; 
		this->_14 = this->_11 * oRhs._14 + this->_12 * oRhs._42 + this->_13 * oRhs._43 + this->_14 * oRhs._44; 

		this->_21 = this->_21 * oRhs._11 + this->_22 * oRhs._21 + this->_23 * oRhs._31 + this->_24 * oRhs._41; 
		this->_22 = this->_21 * oRhs._12 + this->_22 * oRhs._22 + this->_23 * oRhs._32 + this->_24 * oRhs._42; 
		this->_23 = this->_21 * oRhs._13 + this->_22 * oRhs._23 + this->_23 * oRhs._33 + this->_24 * oRhs._43; 
		this->_24 = this->_21 * oRhs._14 + this->_22 * oRhs._24 + this->_23 * oRhs._34 + this->_24 * oRhs._43; 

		this->_31 = this->_31 * oRhs._11 + this->_32 * oRhs._21 + this->_33 * oRhs._31 + this->_34 * oRhs._41; 
		this->_32 = this->_31 * oRhs._12 + this->_32 * oRhs._22 + this->_33 * oRhs._32 + this->_34 * oRhs._42; 
		this->_33 = this->_31 * oRhs._13 + this->_32 * oRhs._23 + this->_33 * oRhs._33 + this->_34 * oRhs._43; 
		this->_34 = this->_31 * oRhs._14 + this->_32 * oRhs._24 + this->_33 * oRhs._34 + this->_34 * oRhs._43; 


		this->_41 = this->_41 * oRhs._11 + this->_42 * oRhs._21 + this->_43 * oRhs._31 + this->_44 * oRhs._41; 
		this->_42 = this->_41 * oRhs._12 + this->_42 * oRhs._22 + this->_43 * oRhs._32 + this->_44 * oRhs._42; 
		this->_43 = this->_41 * oRhs._13 + this->_42 * oRhs._23 + this->_43 * oRhs._33 + this->_44 * oRhs._43; 
		this->_44 = this->_41 * oRhs._14 + this->_42 * oRhs._24 + this->_43 * oRhs._34 + this->_44 * oRhs._43; 

		return *this;
	}

	Matrix4& Matrix4::operator+= ( const Matrix4& oRhs )
	{
		this->_11 += oRhs._11; this->_12 += oRhs._12; this->_13 += oRhs._13; this->_14 += oRhs._14;
		this->_21 += oRhs._21; this->_22 += oRhs._22; this->_23 += oRhs._23; this->_24 += oRhs._24;
		this->_31 += oRhs._31; this->_32 += oRhs._32; this->_33 += oRhs._33; this->_34 += oRhs._34;
		this->_41 += oRhs._41; this->_42 += oRhs._42; this->_43 += oRhs._43; this->_44 += oRhs._44;

		return *this;
	}

	Matrix4& Matrix4::operator-= ( const Matrix4& oRhs )
	{
		this->_11 -= oRhs._11; this->_12 -= oRhs._12; this->_13 -= oRhs._13; this->_14 -= oRhs._14;
		this->_21 -= oRhs._21; this->_22 -= oRhs._22; this->_23 -= oRhs._23; this->_24 -= oRhs._24;
		this->_31 -= oRhs._31; this->_32 -= oRhs._32; this->_33 -= oRhs._33; this->_34 -= oRhs._34;
		this->_41 -= oRhs._41; this->_42 -= oRhs._42; this->_43 -= oRhs._43; this->_44 -= oRhs._44;

		return *this;
	}


	Matrix4& Matrix4::operator*= ( float fTemp )
	{
		this->_11 *= fTemp; this->_12 *= fTemp; this->_13 *= fTemp; this->_14 *= fTemp;
		this->_21 *= fTemp; this->_22 *= fTemp; this->_23 *= fTemp; this->_24 *= fTemp;
		this->_31 *= fTemp; this->_32 *= fTemp; this->_33 *= fTemp; this->_34 *= fTemp;
		this->_41 *= fTemp; this->_42 *= fTemp; this->_43 *= fTemp; this->_44 *= fTemp;

		return *this;
	}

	Matrix4& Matrix4::operator/= ( float fTemp )
	{
		this->_11 /= fTemp; this->_12 /= fTemp; this->_13 /= fTemp; this->_14 /= fTemp;
		this->_21 /= fTemp; this->_22 /= fTemp; this->_23 /= fTemp; this->_24 /= fTemp;
		this->_31 /= fTemp; this->_32 /= fTemp; this->_33 /= fTemp; this->_34 /= fTemp;
		this->_41 /= fTemp; this->_42 /= fTemp; this->_43 /= fTemp; this->_44 /= fTemp;

		return *this;
	}


	//성능에서 복사가 일어나서 무지 느리다. -_-; 
	//복제가 안 일어나는 함수로 바꾼다. 그래도 우선 만들어는 놓자 ㅋㅋ 
	Matrix4 Matrix4::operator* ( const Matrix4& oRhs ) const
	{
		Matrix4 oTemp;

		oTemp._11 = this->_11 * oRhs._11 + this->_12 * oRhs._21 + this->_13 * oRhs._31 + this->_14 * oRhs._41; 
		oTemp._12 = this->_11 * oRhs._12 + this->_12 * oRhs._22 + this->_13 * oRhs._32 + this->_14 * oRhs._42; 
		oTemp._13 = this->_11 * oRhs._13 + this->_12 * oRhs._23 + this->_13 * oRhs._33 + this->_14 * oRhs._43; 
		oTemp._14 = this->_11 * oRhs._14 + this->_12 * oRhs._42 + this->_13 * oRhs._43 + this->_14 * oRhs._44; 

		oTemp._21 = this->_21 * oRhs._11 + this->_22 * oRhs._21 + this->_23 * oRhs._31 + this->_24 * oRhs._41; 
		oTemp._22 = this->_21 * oRhs._12 + this->_22 * oRhs._22 + this->_23 * oRhs._32 + this->_24 * oRhs._42; 
		oTemp._23 = this->_21 * oRhs._13 + this->_22 * oRhs._23 + this->_23 * oRhs._33 + this->_24 * oRhs._43; 
		oTemp._24 = this->_21 * oRhs._14 + this->_22 * oRhs._24 + this->_23 * oRhs._34 + this->_24 * oRhs._44; 

		oTemp._31 = this->_31 * oRhs._11 + this->_32 * oRhs._21 + this->_33 * oRhs._31 + this->_34 * oRhs._41; 
		oTemp._32 = this->_31 * oRhs._12 + this->_32 * oRhs._22 + this->_33 * oRhs._32 + this->_34 * oRhs._42; 
		oTemp._33 = this->_31 * oRhs._13 + this->_32 * oRhs._23 + this->_33 * oRhs._33 + this->_34 * oRhs._43; 
		oTemp._34 = this->_31 * oRhs._14 + this->_32 * oRhs._24 + this->_33 * oRhs._34 + this->_34 * oRhs._44; 

		oTemp._41 = this->_41 * oRhs._11 + this->_42 * oRhs._21 + this->_43 * oRhs._31 + this->_44 * oRhs._41; 
		oTemp._42 = this->_41 * oRhs._12 + this->_42 * oRhs._22 + this->_43 * oRhs._32 + this->_44 * oRhs._42; 
		oTemp._43 = this->_41 * oRhs._13 + this->_42 * oRhs._23 + this->_43 * oRhs._33 + this->_44 * oRhs._43; 
		oTemp._44 = this->_41 * oRhs._14 + this->_42 * oRhs._24 + this->_43 * oRhs._34 + this->_44 * oRhs._44; 

		return oTemp;
	}


	void Matrix4::Multyply( Matrix4& oOut, Matrix4& oLhs, Matrix4& oRhs )
	{
		oOut._11 = oLhs._11 * oRhs._11 + oLhs._12 * oRhs._21 + oLhs._13 * oRhs._31 + oLhs._14 * oRhs._41; 
		oOut._12 = oLhs._11 * oRhs._12 + oLhs._12 * oRhs._22 + oLhs._13 * oRhs._32 + oLhs._14 * oRhs._42; 
		oOut._13 = oLhs._11 * oRhs._13 + oLhs._12 * oRhs._23 + oLhs._13 * oRhs._33 + oLhs._14 * oRhs._43; 
		oOut._14 = oLhs._11 * oRhs._14 + oLhs._12 * oRhs._42 + oLhs._13 * oRhs._43 + oLhs._14 * oRhs._44; 

		oOut._21 = oLhs._21 * oRhs._11 + oLhs._22 * oRhs._21 + oLhs._23 * oRhs._31 + oLhs._24 * oRhs._41; 
		oOut._22 = oLhs._21 * oRhs._12 + oLhs._22 * oRhs._22 + oLhs._23 * oRhs._32 + oLhs._24 * oRhs._42; 
		oOut._23 = oLhs._21 * oRhs._13 + oLhs._22 * oRhs._23 + oLhs._23 * oRhs._33 + oLhs._24 * oRhs._43; 
		oOut._24 = oLhs._21 * oRhs._14 + oLhs._22 * oRhs._24 + oLhs._23 * oRhs._34 + oLhs._24 * oRhs._44; 

		oOut._31 = oLhs._31 * oRhs._11 + oLhs._32 * oRhs._21 + oLhs._33 * oRhs._31 + oLhs._34 * oRhs._41; 
		oOut._32 = oLhs._31 * oRhs._12 + oLhs._32 * oRhs._22 + oLhs._33 * oRhs._32 + oLhs._34 * oRhs._42; 
		oOut._33 = oLhs._31 * oRhs._13 + oLhs._32 * oRhs._23 + oLhs._33 * oRhs._33 + oLhs._34 * oRhs._43; 
		oOut._34 = oLhs._31 * oRhs._14 + oLhs._32 * oRhs._24 + oLhs._33 * oRhs._34 + oLhs._34 * oRhs._44; 

		oOut._41 = oLhs._41 * oRhs._11 + oLhs._42 * oRhs._21 + oLhs._43 * oRhs._31 + oLhs._44 * oRhs._41; 
		oOut._42 = oLhs._41 * oRhs._12 + oLhs._42 * oRhs._22 + oLhs._43 * oRhs._32 + oLhs._44 * oRhs._42; 
		oOut._43 = oLhs._41 * oRhs._13 + oLhs._42 * oRhs._23 + oLhs._43 * oRhs._33 + oLhs._44 * oRhs._43; 
		oOut._44 = oLhs._41 * oRhs._14 + oLhs._42 * oRhs._24 + oLhs._43 * oRhs._34 + oLhs._44 * oRhs._44; 
	}


	Matrix4 Matrix4::operator+ ( const Matrix4& oRhs ) const
	{
		Matrix4 oTemp;

		oTemp._11 += oRhs._11; oTemp._12 += oRhs._12; oTemp._13 += oRhs._13; oTemp._14 += oRhs._14;
		oTemp._21 += oRhs._21; oTemp._22 += oRhs._22; oTemp._23 += oRhs._23; oTemp._24 += oRhs._24;
		oTemp._31 += oRhs._31; oTemp._32 += oRhs._32; oTemp._33 += oRhs._33; oTemp._34 += oRhs._34;
		oTemp._41 += oRhs._41; oTemp._42 += oRhs._42; oTemp._43 += oRhs._43; oTemp._44 += oRhs._44;

		return oTemp;
	}


	Matrix4 Matrix4::operator- ( const Matrix4& oRhs ) const
	{
		Matrix4 oTemp;

		oTemp._11 -= oRhs._11; oTemp._12 -= oRhs._12; oTemp._13 -= oRhs._13; oTemp._14 -= oRhs._14;
		oTemp._21 -= oRhs._21; oTemp._22 -= oRhs._22; oTemp._23 -= oRhs._23; oTemp._24 -= oRhs._24;
		oTemp._31 -= oRhs._31; oTemp._32 -= oRhs._32; oTemp._33 -= oRhs._33; oTemp._34 -= oRhs._34;
		oTemp._41 -= oRhs._41; oTemp._42 -= oRhs._42; oTemp._43 -= oRhs._43; oTemp._44 -= oRhs._44;

		return oTemp;
	}


	Matrix4 Matrix4::operator* ( float fTemp ) const
	{
		Matrix4 oTemp;

		oTemp._11 *= fTemp; oTemp._12 *= fTemp; oTemp._13 *= fTemp; oTemp._14 *= fTemp;
		oTemp._21 *= fTemp; oTemp._22 *= fTemp; oTemp._23 *= fTemp; oTemp._24 *= fTemp;
		oTemp._31 *= fTemp; oTemp._32 *= fTemp; oTemp._33 *= fTemp; oTemp._34 *= fTemp;
		oTemp._41 *= fTemp; oTemp._42 *= fTemp; oTemp._43 *= fTemp; oTemp._44 *= fTemp;

		return oTemp;
	}


	Matrix4 Matrix4::operator/ ( float fTemp ) const
	{
		Matrix4 oTemp;

		oTemp._11 /= fTemp; oTemp._12 /= fTemp; oTemp._13 /= fTemp; oTemp._14 /= fTemp;
		oTemp._21 /= fTemp; oTemp._22 /= fTemp; oTemp._23 /= fTemp; oTemp._24 /= fTemp;
		oTemp._31 /= fTemp; oTemp._32 /= fTemp; oTemp._33 /= fTemp; oTemp._34 /= fTemp;
		oTemp._41 /= fTemp; oTemp._42 /= fTemp; oTemp._43 /= fTemp; oTemp._44 /= fTemp;

		return oTemp;
	}


	bool Matrix4::operator== ( const Matrix4& oRhs ) const
	{
		if ( this->_11 == oRhs._11 && this->_12 == oRhs._12 && this->_13 == oRhs._13 && this->_14 == oRhs._14 &&
			this->_21 == oRhs._21 && this->_22 == oRhs._22 && this->_23 == oRhs._23 && this->_24 == oRhs._24 &&
			this->_31 == oRhs._31 && this->_32 == oRhs._32 && this->_33 == oRhs._33 && this->_34 == oRhs._34 &&
			this->_41 == oRhs._41 && this->_42 == oRhs._42 && this->_43 == oRhs._43 && this->_44 == oRhs._44 )
		{
			return true;
		}

		return false;
	}

	bool Matrix4::operator!= ( const Matrix4& oRhs ) const
	{
		if ( this->_11 == oRhs._11 && this->_12 == oRhs._12 && this->_13 == oRhs._13 && this->_14 == oRhs._14 &&
			this->_21 == oRhs._21 && this->_22 == oRhs._22 && this->_23 == oRhs._23 && this->_24 == oRhs._24 &&
			this->_31 == oRhs._31 && this->_32 == oRhs._32 && this->_33 == oRhs._33 && this->_34 == oRhs._34 &&
			this->_41 == oRhs._41 && this->_42 == oRhs._42 && this->_43 == oRhs._43 && this->_44 == oRhs._44 )
		{
			return false;
		}

		return true;
	}


	Matrix4 operator* ( float fTemp, const Matrix4& oRhs )
	{
		Matrix4 oTemp;

		oTemp._11 = fTemp * oRhs._11; oTemp._12 = fTemp * oRhs._11; oTemp._13 = fTemp * oRhs._13; oTemp._14 = fTemp * oRhs._14;
		oTemp._21 = fTemp * oRhs._21; oTemp._22 = fTemp * oRhs._22; oTemp._23 = fTemp * oRhs._23; oTemp._24 = fTemp * oRhs._24;
		oTemp._31 = fTemp * oRhs._31; oTemp._32 = fTemp * oRhs._32; oTemp._33 = fTemp * oRhs._33; oTemp._34 = fTemp * oRhs._34;
		oTemp._41 = fTemp * oRhs._41; oTemp._42 = fTemp * oRhs._42; oTemp._43 = fTemp * oRhs._43; oTemp._44 = fTemp * oRhs._44;

		return oTemp;
	}


	void Matrix4::Identity()
	{
		this->_11 = this->_22 = this->_33 = this->_44 = 1.0f;
	}


	Matrix4 Matrix4::Invert( Matrix4& oOut )
	{
		float* fMatrixs = (float*)this;
		float* fOuts = (float*)oOut;

		float det = fMatrixs[3]*fMatrixs[6]*fMatrixs[9]*fMatrixs[12] - fMatrixs[2]*fMatrixs[7]*fMatrixs[9]*fMatrixs[12] -
					fMatrixs[3]*fMatrixs[5]*fMatrixs[10]*fMatrixs[12] + fMatrixs[1]*fMatrixs[7]*fMatrixs[10]*fMatrixs[12] +
					fMatrixs[2]*fMatrixs[5]*fMatrixs[11]*fMatrixs[12] - fMatrixs[1]*fMatrixs[6]*fMatrixs[11]*fMatrixs[12] -
					fMatrixs[3]*fMatrixs[6]*fMatrixs[8]*fMatrixs[13] + fMatrixs[2]*fMatrixs[7]*fMatrixs[8]*fMatrixs[13] +
					fMatrixs[3]*fMatrixs[4]*fMatrixs[10]*fMatrixs[13] - fMatrixs[0]*fMatrixs[7]*fMatrixs[10]*fMatrixs[13] -
					fMatrixs[2]*fMatrixs[4]*fMatrixs[11]*fMatrixs[13] + fMatrixs[0]*fMatrixs[6]*fMatrixs[11]*fMatrixs[13] +
					fMatrixs[3]*fMatrixs[5]*fMatrixs[8]*fMatrixs[14] - fMatrixs[1]*fMatrixs[7]*fMatrixs[8]*fMatrixs[14] -
					fMatrixs[3]*fMatrixs[4]*fMatrixs[9]*fMatrixs[14] + fMatrixs[0]*fMatrixs[7]*fMatrixs[9]*fMatrixs[14] +
					fMatrixs[1]*fMatrixs[4]*fMatrixs[11]*fMatrixs[14] - fMatrixs[0]*fMatrixs[5]*fMatrixs[11]*fMatrixs[14] -
					fMatrixs[2]*fMatrixs[5]*fMatrixs[8]*fMatrixs[15] + fMatrixs[1]*fMatrixs[6]*fMatrixs[8]*fMatrixs[15] +
					fMatrixs[2]*fMatrixs[4]*fMatrixs[9]*fMatrixs[15] - fMatrixs[0]*fMatrixs[6]*fMatrixs[9]*fMatrixs[15] -
					fMatrixs[1]*fMatrixs[4]*fMatrixs[10]*fMatrixs[15] + fMatrixs[0]*fMatrixs[5]*fMatrixs[10]*fMatrixs[15];

		if( det != 0.0f )
		{
			fOuts[0] = ( (-fMatrixs[7])*fMatrixs[10]*fMatrixs[13] + fMatrixs[6]*fMatrixs[11]*fMatrixs[13] + fMatrixs[7]*fMatrixs[9]*fMatrixs[14] -
						fMatrixs[5]*fMatrixs[11]*fMatrixs[14] - fMatrixs[6]*fMatrixs[9]*fMatrixs[15] + fMatrixs[5]*fMatrixs[10]*fMatrixs[15] ) / det;
			fOuts[1] = ( fMatrixs[3]*fMatrixs[10]*fMatrixs[13] - fMatrixs[2]*fMatrixs[11]*fMatrixs[13] - fMatrixs[3]*fMatrixs[9]*fMatrixs[14] +
						fMatrixs[1]*fMatrixs[11]*fMatrixs[14] + fMatrixs[2]*fMatrixs[9]*fMatrixs[15] - fMatrixs[1]*fMatrixs[10]*fMatrixs[15] ) / det;
			fOuts[2] = ( (-fMatrixs[3])*fMatrixs[6]*fMatrixs[13] + fMatrixs[2]*fMatrixs[7]*fMatrixs[13] + fMatrixs[3]*fMatrixs[5]*fMatrixs[14] -
						fMatrixs[1]*fMatrixs[7]*fMatrixs[14] - fMatrixs[2]*fMatrixs[5]*fMatrixs[15] + fMatrixs[1]*fMatrixs[6]*fMatrixs[15] ) / det;
			fOuts[3] = ( fMatrixs[3]*fMatrixs[6]*fMatrixs[9] - fMatrixs[2]*fMatrixs[7]*fMatrixs[9] - fMatrixs[3]*fMatrixs[5]*fMatrixs[10] +
						fMatrixs[1]*fMatrixs[7]*fMatrixs[10] + fMatrixs[2]*fMatrixs[5]*fMatrixs[11] - fMatrixs[1]*fMatrixs[6]*fMatrixs[11] ) / det;
			fOuts[4] = ( fMatrixs[7]*fMatrixs[10]*fMatrixs[12] - fMatrixs[6]*fMatrixs[11]*fMatrixs[12] - fMatrixs[7]*fMatrixs[8]*fMatrixs[14] +
						fMatrixs[4]*fMatrixs[11]*fMatrixs[14] + fMatrixs[6]*fMatrixs[8]*fMatrixs[15] - fMatrixs[4]*fMatrixs[10]*fMatrixs[15])/det;
			fOuts[5] =  (-fMatrixs[3]*fMatrixs[10]*fMatrixs[12] + fMatrixs[2]*fMatrixs[11]*fMatrixs[12] + fMatrixs[3]*fMatrixs[8]*fMatrixs[14] -
						fMatrixs[0]*fMatrixs[11]*fMatrixs[14] - fMatrixs[2]*fMatrixs[8]*fMatrixs[15] + fMatrixs[0]*fMatrixs[10]*fMatrixs[15])/det;
			fOuts[6] = ( fMatrixs[3]*fMatrixs[6]*fMatrixs[12] - fMatrixs[2]*fMatrixs[7]*fMatrixs[12] - fMatrixs[3]*fMatrixs[4]*fMatrixs[14] +
						fMatrixs[0]*fMatrixs[7]*fMatrixs[14] + fMatrixs[2]*fMatrixs[4]*fMatrixs[15] - fMatrixs[0]*fMatrixs[6]*fMatrixs[15])/det;
			fOuts[7] = ( -fMatrixs[3]*fMatrixs[6]*fMatrixs[8] + fMatrixs[2]*fMatrixs[7]*fMatrixs[8] + fMatrixs[3]*fMatrixs[4]*fMatrixs[10] -
						fMatrixs[0]*fMatrixs[7]*fMatrixs[10] - fMatrixs[2]*fMatrixs[4]*fMatrixs[11] + fMatrixs[0]*fMatrixs[6]*fMatrixs[11])/det;
			fOuts[8] = ( -fMatrixs[7]*fMatrixs[9]*fMatrixs[12] + fMatrixs[5]*fMatrixs[11]*fMatrixs[12] + fMatrixs[7]*fMatrixs[8]*fMatrixs[13] -
						fMatrixs[4]*fMatrixs[11]*fMatrixs[13] - fMatrixs[5]*fMatrixs[8]*fMatrixs[15] + fMatrixs[4]*fMatrixs[9]*fMatrixs[15])/det;
			fOuts[9] = ( fMatrixs[3]*fMatrixs[9]*fMatrixs[12] - fMatrixs[1]*fMatrixs[11]*fMatrixs[12] - fMatrixs[3]*fMatrixs[8]*fMatrixs[13] +
						fMatrixs[0]*fMatrixs[11]*fMatrixs[13] + fMatrixs[1]*fMatrixs[8]*fMatrixs[15] - fMatrixs[0]*fMatrixs[9]*fMatrixs[15])/det;
			fOuts[10] = ( -fMatrixs[3]*fMatrixs[5]*fMatrixs[12] + fMatrixs[1]*fMatrixs[7]*fMatrixs[12] + fMatrixs[3]*fMatrixs[4]*fMatrixs[13] -
						fMatrixs[0]*fMatrixs[7]*fMatrixs[13] - fMatrixs[1]*fMatrixs[4]*fMatrixs[15] + fMatrixs[0]*fMatrixs[5]*fMatrixs[15])/det;
			fOuts[11] = ( fMatrixs[3]*fMatrixs[5]*fMatrixs[8] - fMatrixs[1]*fMatrixs[7]*fMatrixs[8] - fMatrixs[3]*fMatrixs[4]*fMatrixs[9] +
						fMatrixs[0]*fMatrixs[7]*fMatrixs[9] + fMatrixs[1]*fMatrixs[4]*fMatrixs[11] - fMatrixs[0]*fMatrixs[5]*fMatrixs[11])/det;
			fOuts[12] = ( fMatrixs[6]*fMatrixs[9]*fMatrixs[12] - fMatrixs[5]*fMatrixs[10]*fMatrixs[12] - fMatrixs[6]*fMatrixs[8]*fMatrixs[13] +
						fMatrixs[4]*fMatrixs[10]*fMatrixs[13] + fMatrixs[5]*fMatrixs[8]*fMatrixs[14] - fMatrixs[4]*fMatrixs[9]*fMatrixs[14])/det;
			fOuts[13] = ( -fMatrixs[2]*fMatrixs[9]*fMatrixs[12] + fMatrixs[1]*fMatrixs[10]*fMatrixs[12] + fMatrixs[2]*fMatrixs[8]*fMatrixs[13] -
						fMatrixs[0]*fMatrixs[10]*fMatrixs[13] - fMatrixs[1]*fMatrixs[8]*fMatrixs[14] + fMatrixs[0]*fMatrixs[9]*fMatrixs[14])/det;
			fOuts[14] = ( fMatrixs[2]*fMatrixs[5]*fMatrixs[12] - fMatrixs[1]*fMatrixs[6]*fMatrixs[12] - fMatrixs[2]*fMatrixs[4]*fMatrixs[13] +
						fMatrixs[0]*fMatrixs[6]*fMatrixs[13] + fMatrixs[1]*fMatrixs[4]*fMatrixs[14] - fMatrixs[0]*fMatrixs[5]*fMatrixs[14])/det;
			fOuts[15] = ( -fMatrixs[2]*fMatrixs[5]*fMatrixs[8] + fMatrixs[1]*fMatrixs[6]*fMatrixs[8] + fMatrixs[2]*fMatrixs[4]*fMatrixs[9] -
						fMatrixs[0]*fMatrixs[6]*fMatrixs[9] - fMatrixs[1]*fMatrixs[4]*fMatrixs[10] + fMatrixs[0]*fMatrixs[5]*fMatrixs[10])/det;
		}
		else
		{
			float fTemps[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 1.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 1.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f };
			Matrix4 oTemp(fTemps);
			return oTemp;
		}

		Matrix4 oTemp(fOuts);
		return oTemp;
	}



	void Matrix4::Transpose()
	{
		Matrix4 oTemp(*this);

		this->_12 = oTemp._21;
		this->_13 = oTemp._31;
		this->_14 = oTemp._41;
		this->_21 = oTemp._12;
		this->_31 = oTemp._13;
		this->_41 = oTemp._14;
		this->_23 = oTemp._32;
		this->_32 = oTemp._23;
		this->_24 = oTemp._42;
		this->_34 = oTemp._43;
		this->_42 = oTemp._24;
		this->_43 = oTemp._34;


		//for( int i = 0; i < 4; ++i )
		//	for( int j = 0; j < 4; ++j )
		//	{
		//		(*this).m[j][i] = oTemp.m[i][j]; 
		//		printf ("%d, %d -> %d, %d\n", j+1,i+1, i+1,j+1);
		//	}
	}
}