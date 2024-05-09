#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <vector>
#include <cmath>
#include <matplot/matplot.h>
#include <set>

namespace py = pybind11;
namespace m = matplot;

int add(int i, int j) {
    return i + j;
}

int multi(int i, int j) {

    return i * j;
}

int graf() {


    std::set<std::vector<double>> Y = {
        {16, 5, 9, 4}, {2, 11, 7, 14}, {3, 10, 6, 15}, {13, 8, 12, 1} };
    m::plot(Y);

    m::show();
    return 0;
}
 
double dzielenie(int i, int j) {

	return i / j;
}


std::vector<double> sinus() {

    std::vector<double> x = m::linspace(0, 2 * 3.14, 300);
    std::vector<double> y1 = m::transform(x, [&](auto x) { return sin(x); });
    //std::vector<double> y2 = m::transform(x, [](auto x) { return sin(x - 0.25); });
    //std::vector<double> y3 = m::transform(x, [](auto x) { return sin(x - 0.5); });

    m::plot(x, y1);

    m::show();

    return x;
}

std::vector<double> cosinus() {

    std::vector<double> x = m::linspace(0, 10, 150);
    std::vector<double> y = m::transform(x, [](auto x) { return cos(5 * x); });
    m::plot(x, y);//->color({ 0.f, 0.7f, 0.9f });
    //m::title("2-D Line Plot");
   // m::xlabel("x");
   // m::ylabel("cos(5x)");

    m::show();
    return x;
}

std::vector<double> pila( int freq) {
    std::vector<double> x = m::linspace(0, 2 * 3.14, 300);
    std::vector<double> y = m::transform(x, [freq](double t) {
        return 2.0 * (t * freq - floor(0.5 + t * freq)); });
    m::plot(x, y);
    m::show();
    return y;
}


PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    m.def("add", &add);
    m.def("sinus", &sinus);
    m.def("multi", &multi);
    m.def("graf", &graf);
	m.def("dzielenie", &dzielenie);
	m.def("cosinus", &cosinus);
	m.def("pila", &pila);
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build