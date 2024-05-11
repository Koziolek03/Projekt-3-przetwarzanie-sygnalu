#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <vector>
#include <cmath>
#include <matplot/matplot.h>
#include <set>

namespace py = pybind11;
namespace m = matplot;

void sinus(int freq) {

    std::vector<double> x = m::linspace(0, 2 * 3.14, 150);
    std::vector<double> y = m::transform(x, [freq](double t) {  
        return sin(t * freq); });
    m::plot(x, y);
    m::show();
}

void cosinus(int freq) {
    std::vector<double> x = m::linspace(0, 2 * 3.14, 150);
    std::vector<double> y = m::transform(x, [freq](double t) {
        return cos(t * freq); });
    m::plot(x, y);
    m::show();
}

void pila(int freq) {
    std::vector<double> x = m::linspace(0, 2 * 3.14, 150);
    std::vector<double> y = m::transform(x, [freq](double t) {
        return 2.0 * ((t * freq / (2 * 3.14)) - floor(0.5 + t * freq / (2 * 3.14))); });
    m::plot(x, y);
    m::show();
}

void prostokatny(int freq) {
    std::vector<double> x = m::linspace(0, 2 * 3.14, 150);
    std::vector<double> y = m::transform(x, [freq](double t) {
        return std::copysign(0.99, std::sin(t * freq)); });
    m::plot(x, y);
    m::show();
}

PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    m.def("sinus", &sinus);
	m.def("cosinus", &cosinus);
	m.def("pila", &pila);
	m.def("prostokatny", &prostokatny);
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build