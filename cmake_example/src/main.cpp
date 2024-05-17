#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <vector>
#include <cmath>
#include <matplot/matplot.h>
#include <iostream>
#include <fstream>
#include <set>



namespace py = pybind11;
namespace m = matplot;

void WszystkieFunkcje(int freq) {
    std::vector<double> x = m::linspace(0, 2 * 3.14, 300);

    //Sinus
	m::subplot(2, 2, 1);//robi w jednym oknie 4 wykresy, 2 wiersze i 2 kolumny, 1 to, ¿e bedzie w pierwsyzm oknie
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

void zdj() {
    const int width = 10;
    const int height = 10;
    std::vector<std::vector<int>> image(height, std::vector<int>(width, 0));

    // Generowanie przyk³adowej macierzy pikseli (np. prosty gradient)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            image[y][x] = x + y;
        }
    }

    // Pe³na œcie¿ka do pliku CSV
    std::ofstream file("C:/Users/Gigabyte/Source/Repos/Koziollek03/Projekt-3-przetwarzanie-sygnalu/cmake_example/image.csv");
    if (file.is_open()) {
        for (const auto& row : image) {
            for (size_t col = 0; col < row.size(); ++col) {
                file << row[col];
                if (col < row.size() - 1) file << ",";
            }
            file << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu!" << std::endl;
    }
}

PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    m.def("zdj", &zdj);
    m.def("WszystkieFunkcje", &WszystkieFunkcje);
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build