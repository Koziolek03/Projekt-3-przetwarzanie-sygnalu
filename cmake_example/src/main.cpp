#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <vector>
#include <cmath>
#include <matplot/matplot.h>
#include <set>
#include <string>

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


std::vector<double> filtrDolnoprzepustowy(std::vector<double>dane, double cutoff) {

    std::vector<double>output;

    double RC = 1.0 / (2.0 * 3.14159265358979323846 * cutoff);
    double dt = 1.0 / 44100.0; // Za³ó¿my, ¿e czêstotliwoœæ próbkowania wynosi 44100 Hz
    double alpha = dt / (RC + dt);

    output.push_back(dane[0]);
    double outputTemp;
    for (long long int i = 1; i < dane.size(); ++i) {
        outputTemp = alpha * dane[i] + (1 - alpha) * output[i - 1];
        output.push_back(outputTemp);
    }

    return output;

}











PYBIND11_MODULE(cmake_example, m) {//nag³ówki funkcji dla cmake 

    
    
    
    m.def("readAudioFile", &readAudioFile, "Funkcja wczytuj¹ca plik dŸwiêkowy");
    m.def("visualizeAudio", &visualizeAudio, "Funkcja wizualizuj¹ca dŸwiêk");
    m.def("filtrDolnoprzepustowy", &filtrDolnoprzepustowy, "Funkcja Filtra 1D");
  
}
//w konsoli wpisac kolejno: cd build, cmake .., cd .., cmake --build build