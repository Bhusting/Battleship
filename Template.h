#pragma once

template<class T>

class Compare {
public:
	T compare(T num1, T num2) {
		return (num1>num2) ? num1 : num2;
	}
};