from audioop import *

from build.Debug.cmake_example import *









audio_data = readAudioFile("cmake_example\CantinaBand3.wav")# Wczytanie do pythona pliku dźwiękowego CantinaBand3.wav
print(audio_data) #wyświetlenie wartości poszczególnych sampli
print(visualizeAudio(audio_data)) #wizualizacja za pomocą Gnuplota


# ss Szymon generowanie sygnałów sin cos itd, rozmycie gaussa 
# Jakub filtracja 1D i 2D 
