import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation

LOG_FILE = 'data/log.csv'

import os

def animate(i):
    try:
        # Vérifie que le fichier existe et qu’il a une taille non nulle
        if not os.path.exists(LOG_FILE) or os.stat(LOG_FILE).st_size == 0:
            print("⏳ En attente du fichier log.csv...")
            return

        data = pd.read_csv(LOG_FILE)
        if data.shape[0] < 2:
            return

        plt.cla()

        plt.plot(data['Pitch'], label='Pitch (°)', color='blue')
        plt.plot(data['Yaw'], label='Yaw (°)', color='orange')
        plt.plot(data['Roll'], label='Roll (°)', color='green')

        plt.xlabel("Temps (itérations)")
        plt.ylabel("Angle (°)")
        plt.title("Orientation du CubeSat en temps réel")
        plt.legend(loc='upper right')
        plt.grid(True)
    except Exception as e:
        print("Erreur :", e)


fig = plt.figure()
ani = animation.FuncAnimation(fig, animate, interval=300)  # au lieu de 500 ms

plt.tight_layout()
plt.show()
del ani  # <-- ajoute cette ligne juste après plt.show()
