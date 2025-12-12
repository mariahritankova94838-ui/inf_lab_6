
#pragma once
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;

inline void Calculate(float x, float y, float& S, float& R, float& C) {
	if (x <= 0) {
		throw invalid_argument("x должен быть > 0");
	}
	R = sqrt(x * x) + sqrt(y * y) / exp(log(x));
	S = pow(cos(3.14159 * x / 4), 2);
	C = max(R, S);
}
