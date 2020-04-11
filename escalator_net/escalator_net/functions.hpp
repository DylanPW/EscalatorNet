/* static class that encapsulates functions for a 
*/
#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include "types.hpp"
#include <algorithm>

// 
enum FunctionTypes {
	sigmoid
};

// List of templated functions for use
template <typename T>
class Functions {
public:
	// function ptr for this type of function
	using function_ptr = T(*)(T);

	// Implementation of sigmoid function
	static T sigmoid(T x) {
		return 1 / (1 + exp(-x));
	}

	// Implementation of sigmoid derivative
	static T sigmoidDerivative(T x) {
		return sigmoid(x) * (1 - sigmoid(x));
	}

	// Returns corresponding function
	static function_ptr getFunction(FunctionTypes type) {
		switch (type) {
		case FunctionTypes::sigmoid:
			return Functions::sigmoid;

		default:
			return nullptr;
		}
	}

	// Returns corresponding function derivative
	static function_ptr getFunctionDerivative(FunctionTypes type) {
		switch (type) {
		case FunctionTypes::sigmoid:
			return Functions::sigmoidDerivative;

		default:
			return nullptr;
		}
	}
};

#endif