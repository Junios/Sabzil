#include <stdio.h>
#include "Vector3.h"
#include "Vector4.h"

#include <iostream>
using namespace std;
using namespace Sabzil;

/////////////
// LINKING //
/////////////
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")


//////////////
// INCLUDES //
//////////////
#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <d3dx10math.h>


ostream& out(D3DXVECTOR4& v)
{
	cout << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";

	return cout;
}

int main()
{
	D3DXVECTOR3 a;

	//Vector4 test code
	cout << "[[[ D3DXVECTOR4 test ]]]" << endl;
	D3DXVECTOR4 dA(1, 1, 1, 1), dB(1, 0, 0, 1), dC(0, 0, 0, 0);

	cout << " - "; out(dA) << " = "; out(-dA) << endl;
	cout << " + "; out(dA) << " = "; out(+dA) << endl;

	out(dA) << " + "; out(dB) << " = "; out(dA + dB) << endl;
	out(dA) << "  -"; out(dB) << " = "; out(dA - dB) << endl;
	out(dA) << " * "; cout << 0.5f << " = "; out(dA * 0.5f) << endl;
	out(dA) << " / "; cout << 2.0f << " = "; out(dA / 2.0f) << endl;

	out(dC) << " += "; out(dA) << " equals to "; dC += dA; out(dC) << endl;
	out(dC) << " -= "; out(dA) << " equals to "; dC -= dA; out(dC) << endl;
	out(dA) << " *= "; cout << 0.5f << " equals to "; dA *= 0.5f; out(dA) << endl;
	out(dA) << " /= "; cout << 2.0f << " equals to "; dA /= 2.0f; out(dA) << endl;
	
	cout << 0.5f << " * "; out(dA) << " = "; out(0.5f * dA) << endl;

	out(dA) << " == "; out(dB) << " equals to "; cout << (dA == dB) << endl;
	out(dA) << " == "; out(dA) << " equals to "; cout << (dA == dA) << endl;
	out(dA) << " != "; out(dB) << " equals to "; cout << (dA != dB) << endl;
	out(dA) << " != "; out(dA) << " equals to "; cout << (dA != dA) << endl;

	cout << endl << "[[[ Vector4 test ]]]" << endl;
	cout << "TODO... 아 졸려-0-" << endl << "2012-01-05 오전 12:19" << endl << "자야겠다zzz" << endl;
	return 0;
}
