#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <vector>
#include <cmath>
#include <matplot/matplot.h>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <pybind11/numpy.h>
#include <AudioFile.h>

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


std::vector<double> readAudioFile(const std::string& filename) {
    // Wczytanie pliku dŸwiêkowego za pomoc¹ biblioteki audiofile
    AudioFile<double> audioFile;
   
    const std::string filePath = filename;
    audioFile.load(filePath);
   
    audioFile.printSummary();

    std::vector<double> dzwiek;
    for (const auto& sample : audioFile.samples[0]) { // Za³ó¿my, ¿e wczytujesz tylko jedn¹ œcie¿kê dŸwiêkow¹
        // Normalizacja wartoœci do zakresu 0-1
        
        // Skalowanie do zakresu -128 do 127
        double scaledValue = sample;
        // Dodaj przeskalowan¹ wartoœæ do wektora
        dzwiek.push_back(scaledValue);

    }
    
    return dzwiek;
}

void visualizeAudio(const std::vector<float>& audio_data) {
    m::plot(audio_data);
    m::title("Wykres dŸwiêku");
    m::xlabel("Czas [s]");
    m::ylabel("Amplituda");
    m::show();
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


PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    m.def("add", &add);
    m.def("sinus", &sinus);
    m.def("multi", &multi);
    m.def("graf", &graf);
	m.def("dzielenie", &dzielenie);
    m.def("readAudioFile", &readAudioFile, "Funkcja wczytuj¹ca plik dŸwiêkowy");
    m.def("visualizeAudio", &visualizeAudio, "Funkcja wizualizuj¹ca dŸwiêk");
  
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build