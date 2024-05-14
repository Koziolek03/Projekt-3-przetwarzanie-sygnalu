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








PYBIND11_MODULE(cmake_example, m) {//nag��wki funkcji dla cmake 

    
    
    
    m.def("readAudioFile", &readAudioFile, "Funkcja wczytuj�ca plik d�wi�kowy");
    m.def("visualizeAudio", &visualizeAudio, "Funkcja wizualizuj�ca d�wi�k");
  
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build