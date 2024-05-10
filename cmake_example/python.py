from audioop import *

from build.Debug.cmake_example import *


print(graf())

#print(dzielenie(8,2))
 
#print(add(1, 2))
#print(sinus())
p
audio_data=readAudioFile("cmake_example\CantinaBand3.wav")
print(audio_data)
print(visualizeAudio(audio_data))

#print(graf())
# ss Szymon generowanie sygnałów sin cos itd, rozmycie gaussa 
# Jakub filtracja 1D i 2D 
