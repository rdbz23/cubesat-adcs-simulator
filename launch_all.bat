@echo off
echo ============================
echo 🔧 Compilation du simulateur
echo ============================

:: Créer le dossier data si nécessaire
if not exist data (
    mkdir data
)

:: Compiler le simulateur
g++ -std=c++17 -Wall src\main.cpp src\Orientation.cpp src\Sensor.cpp src\Actuator.cpp -Iinclude -o cubesat_sim.exe

if %errorlevel% neq 0 (
    echo ❌ Erreur de compilation !
    pause
    exit /b
)

echo ✅ Compilation OK

echo ============================
echo 🚀 Lancement du simulateur
echo ============================

:: Ouvre simulateur dans 1ère fenêtre CMD
start "Simulateur" cmd /k cubesat_sim.exe

timeout /t 1 > nul

echo ============================
echo 📈 Lancement du graphe Python
echo ============================

:: Ouvre graphe Python dans 2e fenêtre CMD
start "Graphe" cmd /k python realtime_plot.py
