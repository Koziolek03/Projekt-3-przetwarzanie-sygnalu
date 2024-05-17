from audioop import *

from build.Debug.cmake_example import *


#freq = int(input("Podaj czestotliwosc: "))

#sinus(freq)
#cosinus(freq)
#pila(freq)
#prostokatny(freq)

audio_data = readAudioFile("cmake_example\CantinaBand3.wav")# Wczytanie do pythona pliku dźwiękowego CantinaBand3.wav
print(audio_data) #wyświetlenie wartości poszczególnych sampli
print(visualizeAudio(audio_data)) #wizualizacja za pomocą Gnuplota

audio_filtrated=filtrDolnoprzepustowy(audio_data,100)
print(visualizeAudio(audio_filtrated))

# Szymon generowanie sygnałów sin cos itd, rozmycie gaussa 
# Jakub filtracja 1D i 2D 
