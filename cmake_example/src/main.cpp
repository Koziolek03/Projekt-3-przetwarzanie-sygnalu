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
    m::xlabel("Kolejne sample");
    m::ylabel("Amplituda");
    m::show();
}








PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    
    
    
    m.def("readAudioFile", &readAudioFile, "Funkcja wczytuj¹ca plik dŸwiêkowy");
    m.def("visualizeAudio", &visualizeAudio, "Funkcja wizualizuj¹ca dŸwiêk");
  
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build