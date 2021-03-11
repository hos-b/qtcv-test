#include <pybind11/pybind11.h>

int add(int a, int b) {
	return a + b;
}

/* compile with
   g++ -shared -std=c++11 -DMS_WIN64 -fPIC -I"C:/Program Files/Python37/include"
   -Ibind/pybind11/include -Wall  -L"C:/Program Files/Python37/libs" example.cpp
   -o example.cp37-win_amd64.pyd -lpython37
*/

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin";
    m.def("add", &add, "A function which adds two numbers");
}