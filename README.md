# 🪨📄✂️ Shifumi - Jeu Pierre Feuille Ciseaux en GTK

Shifumi est une application graphique simple développée en C avec la bibliothèque **GTK+3**, permettant de jouer au célèbre jeu "Pierre - Feuille - Ciseaux" contre un bot.

---

## 🔧 Fonctionnalités

- Interface graphique avec GTK 3
- Choix entre Pierre, Feuille, ou Ciseaux
- Réaction instantanée du bot avec choix aléatoire
- Affichage du résultat (Gagné / Perdu / Égalité)
- Bouton pour rejouer
- Design personnalisé via CSS

---

## 🛠️ Installation

### Depuis le setup Windows

1. Télécharge le fichier `install_Shifumi.exe` dans le dossier `installeur/`
2. Lance l’installeur et suis les étapes
3. Lance le jeu depuis le raccourci ou le menu démarrer

### Compilation manuelle (Linux ou MinGW)

```bash
gcc main.c -o Shifumi `pkg-config --cflags --libs gtk+-3.0`
