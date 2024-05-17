from audioop import *
import imageio
from build.Debug.cmake_example import *
import numpy as np
import matplotlib.pyplot as plt
import os

# Pełna ścieżka do pliku image.csv
file_path = 'C:/Users/Gigabyte/Source/Repos/Koziollek03/Projekt-3-przetwarzanie-sygnalu/cmake_example/image.csv'

# Sprawdzenie, czy plik istnieje
if not os.path.isfile(file_path):
    print(f"Plik {file_path} nie istnieje.")
else:
    # Wczytanie macierzy z pliku CSV
    image = np.loadtxt(file_path, delimiter=',')

    # Wizualizacja macierzy za pomocą matplotlib
    plt.imshow(image, cmap='gray', interpolation='nearest')
    plt.colorbar()
    plt.show()

freq = int(input("Podaj czestotliwosc: "))
WszystkieFunkcje(freq)


# ss Szymon generowanie sygnałów sin cos itd, rozmycie gaussa 
# Jakub filtracja 1D i 2D 
