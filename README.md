# 🛰️ CubeSat ADCS Simulator

Ce projet simule un système de **contrôle d'attitude embarqué (ADCS)** pour un CubeSat, en langage **C++**, avec une visualisation en **temps réel** via **Python / matplotlib**.

---

## 🎯 Objectif du projet

- Implémenter un **simulateur logiciel** représentant le comportement d’un satellite en orbite basse.
- Simuler des **capteurs embarqués** (gyroscope, magnétomètre).
- Appliquer un **contrôle d’attitude** (PID simplifié) pour atteindre une orientation cible (Pitch, Yaw, Roll).
- Générer une **télémétrie** en fichier `log.csv`.
- Afficher les courbes en **temps réel** avec `matplotlib`.

---

## 🧱 Fonctionnalités principales

| Module        | Description                                                                 |
|---------------|-----------------------------------------------------------------------------|
| `Orientation` | Gère les angles du satellite (normalisation, mise à jour des axes)         |
| `Sensor`      | Simule les lectures capteurs bruitées (gyroscope, magnétomètre)            |
| `Actuator`    | Applique une correction proportionnelle vers l’orientation cible           |
| `main.cpp`    | Boucle temps réel embarquée, génère les logs à chaque itération            |
| `log.csv`     | Fichier contenant la télémétrie en temps réel                              |
| `realtime_plot.py` | Script Python qui lit le fichier log et affiche les angles en live    |
| `launch_all.bat` | Script d’intégration : compile, exécute le simulateur et lance le graphe |

---

## 🖥️ Démonstration du fonctionnement

- Le simulateur s’exécute à **10 Hz**
- Le système corrige progressivement vers l’orientation cible :
  - **Pitch** (inclinaison)
  - **Yaw** (direction)
  - **Roll** (basculement)
- Le fichier `data/log.csv` est mis à jour à chaque cycle
- Un graphe en **temps réel** affiche l’évolution des axes

---

## 📁 Structure du projet

cubesat-adcs-simulator/
├── include/ # Fichiers headers C++ (Orientation.h, Sensor.h, Actuator.h)
├── src/ # Code source C++
├── data/ # Contient le fichier de télémétrie log.csv
├── realtime_plot.py # Visualisation temps réel avec matplotlib
├── launch_all.bat # Script automatique de compilation + exécution
├── Makefile # Compilation manuelle (Linux)
└── README.md # Vous êtes ici

---

## 🚀 Lancement automatique (Windows)

1. Double-clique sur **`launch_all.bat`**  
   Ou exécute dans le terminal :
   ```bash
   ./launch_all.bat

## Compilation
```bash
make
./cubesat_sim
```

## Auteur
Rayan — Étudiant en **génie logiciel** passionné d’**aérospatial**

J’ai conçu ce projet pour apprendre concrètement le fonctionnement des systèmes embarqués appliqués au spatial, en combinant C++ et visualisation en temps réel. Je suis motivé à contribuer à des projets ambitieux dans l'ingénierie logicielle appliquée à l'aéronautique ou l'espace.