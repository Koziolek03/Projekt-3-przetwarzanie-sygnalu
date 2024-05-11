#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <vector>
#include <cmath>
#include <matplot/matplot.h>
#include <set>

namespace py = pybind11;
namespace m = matplot;

void WszystkieFunkcje(int freq) {
    std::vector<double> x = m::linspace(0, 2 * 3.14, 150);

    //Sinus
    m::subplot(2, 2, 1);
    std::vector<double> y1 = m::transform(x, [freq](double t) {
        return sin(t * freq); });
    m::plot(x, y1);

    //Cosinus
    m::subplot(2, 2, 2);
    std::vector<double> y2 = m::transform(x, [freq](double t) { 
        return cos(t * freq); });
    m::plot(x, y2);

    //Pila
    m::subplot(2, 2, 3);
    std::vector<double> y3 = m::transform(x, [freq](double t) { 
        return 2.0 * ((t * freq / (2 * 3.14)) - floor(0.5 + t * freq / (2 * 3.14))); });
    m::plot(x, y3);

    //Prostokatny
    m::subplot(2, 2, 4);
    std::vector<double> y4 = m::transform(x, [freq](double t) { 
        return std::copysign(0.99, std::sin(t * freq)); });
    m::plot(x, y4);

    m::show();
}

PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    m.def("WszystkieFunkcje", &WszystkieFunkcje);
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build