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

void sinus(int freq) {

    std::vector<double> x = m::linspace(0, 1.0001/freq , 150);
    std::vector<double> y = m::transform(x, [freq](double t) {  
        return sin(t * freq*6.28); });
    m::plot(x, y);
    m::title("Sinus");
    m::xlabel("Czas [s]");
    
    m::show();
}

void cosinus(int freq) {
    std::vector<double> x = m::linspace(0, 1.0001 / freq, 150);
    std::vector<double> y = m::transform(x, [freq](double t) {
        return cos(t * freq * 6.28); });
    m::plot(x, y);
    m::show();
}

 



std::vector<double> readAudioFile(const std::string& filename) {
    // Wczytanie pliku d�wi�kowego za pomoc� biblioteki audiofile
    AudioFile<double> audioFile;
   
    const std::string filePath = filename;
    audioFile.load(filePath);
   
    audioFile.printSummary();

    std::vector<double> dzwiek;
    for (const auto& sample : audioFile.samples[0]) { // Za��my, �e wczytujesz tylko jedn� �cie�k� d�wi�kow�
        // Normalizacja warto�ci do zakresu 0-1
        
        // Skalowanie do zakresu -128 do 127
        double scaledValue = sample;
        // Dodaj przeskalowan� warto�� do wektora
        dzwiek.push_back(scaledValue);

    }
    
    return dzwiek;
}

void visualizeAudio(const std::vector<float>& audio_data) {
    m::plot(audio_data);
    m::title("Wykres d�wi�ku");
    m::xlabel("Kolejne sample");
    m::ylabel("Amplituda");
    m::show();
}







void pila(int freq) {
    std::vector<double> x = m::linspace(0, 1.0001 / freq, 150);
    std::vector<double> y = m::transform(x, [freq](double t) {
        return 2.0 * ((t * freq ) - floor(0.5 + t * freq )); });
    m::plot(x, y);
    m::show();
}

void prostokatny(int freq) {
    std::vector<double> x = m::linspace(0, 1.0001 / freq, 150);
    std::vector<double> y = m::transform(x, [freq](double t) {
        return std::copysign(0.99, std::sin(t * freq * 6.28)); });
    m::plot(x, y);
    m::title("Przebieg prostokatny");
    m::xlabel("Czas [s]");
    m::show();
}

PYBIND11_MODULE(cmake_example, m) {//nag��wki funkcji dla cmake 

    m.def("sinus", &sinus);
    m.def("cosinus", &cosinus);
    m.def("pila", &pila);
    m.def("prostokatny", &prostokatny);
    m.def("readAudioFile", &readAudioFile, "Funkcja wczytuj�ca plik d�wi�kowy");
    m.def("visualizeAudio", &visualizeAudio, "Funkcja wizualizuj�ca d�wi�k");


}

//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build