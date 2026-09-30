cmake_minimum_required(VERSION 3.10)
project(libtinyini C)

# Nutze den C99-Standard (perfekt für den Code von rxi)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. Haupt-Target: Die Shared Library (.so) für Katkos Engine v2 bauen
add_library(tinyini SHARED src/ini.c)

# 2. Test-Infrastruktur mit Criterion einrichten
# Wir suchen nach der globalen libcriterion.so auf deinem Linux-System
find_library(CRITERION_LIB criterion REQUIRED)

# Das Test-Executable deklarieren
add_executable(ini_tests test_base/test_ini.c)

# Verknüpfe die Tests mit deiner ini.c (über das tinyini-Target) 
# und der globalen Criterion-Bibliothek
target_link_libraries(ini_tests PRIVATE tinyini ${CRITERION_LIB})

# Füge das src-Verzeichnis zu den Include-Pfaden hinzu, damit #include "ini.h" überall klappt
target_include_directories(ini_tests PRIVATE src)
