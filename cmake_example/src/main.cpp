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
 


std::vector<double> sinus() {

    std::vector<double> x = m::linspace(0, 2 * 3.14, 300);
    std::vector<double> y1 = m::transform(x, [&](auto x) { return sin(x); });
    //std::vector<double> y2 = m::transform(x, [](auto x) { return sin(x - 0.25); });
    //std::vector<double> y3 = m::transform(x, [](auto x) { return sin(x - 0.5); });

    m::plot(x, y1);

    m::show();

    //return x;
}


PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    m.def("add", &add);
    m.def("sinus", &sinus);
    m.def("multi", &multi);
    m.def("graf", &graf);


}
