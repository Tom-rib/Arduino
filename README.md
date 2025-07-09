# Arduino# 🚀 Projet Arduino - Modules Interactifs et Station Météo

Bienvenue dans ce projet pédagogique basé sur un kit Arduino ! Vous y trouverez des exercices (nommés **JOB**) progressifs allant des bases de l’électricité aux projets complexes comme une station météo ou un jeu de mémoire.

---

## 🔗 Table des matières

- [🔌 JOB 1 : Mise sous tension](#job-1--mise-sous-tension)
- [📐 JOB 2 : Calcul de la résistance pour une LED](#job-2--calcul-de-la-résistance-pour-une-led)
- [💡 JOB 3 à JOB 4 : Montages de LED](#job-3-à-job-4--montages-de-led)
- [💻 JOB 5 : Installation de l’IDE Arduino](#job-5--installation-de-lide-arduino)
- [🔁 JOB 6 à JOB 8 : Clignotements et variateur](#job-6-à-job-8--clignotements-et-variateur)
- [🔘 JOB 9 à JOB 11 : Interactions LED / Bouton / Ventilateur](#job-9-à-job-11--interactions-led--bouton--ventilateur)
- [📺 JOB 12 à JOB 14 : LCD et interactions](#job-12-à-job-14--lcd-et-interactions)
- [🌈 JOB 15 : LED RGB et potentiomètre](#job-15--led-rgb-et-potentiomètre)
- [⏱️ JOB 16 à JOB 18 : Heure, chronomètre et barre de chargement](#job-16-à-job-18--heure-chronomètre-et-barre-de-chargement)
- [🕹️ JOB 19 : Joystick et directions](#job-19--joystick-et-directions)
- [📏 JOB 20 : Mesure de distance](#job-20--mesure-de-distance)
- [🌦️ Station météo](#station-météo)
- [📊 Tableau de bord](#tableau-de-bord)
- [🧠 Jeu de mémoire](#jeu-de-mémoire)

---

## JOB 1 : Mise sous tension
Branchement électrique de la carte Arduino à une source d’alimentation (USB ou adaptateur secteur).

---

## JOB 2 : Calcul de la résistance pour une LED
Calcul de la résistance idéale (en ohms) pour protéger une LED avec une alimentation de 5V et un courant de 10 mA.  
📄 Résultat à placer dans le fichier `job2.pdf`.

---

## JOB 3 à JOB 4 : Montages de LED
- **JOB 3** : Branchement simple d’une LED allumée en continu, avec résistance.
- **JOB 4** : Montages LED en série et en parallèle (sans code, purement matériel).

---

## JOB 5 : Installation de l’IDE Arduino
Installation de l'environnement de développement Arduino pour écrire, compiler et téléverser du code.

---

## JOB 6 à JOB 8 : Clignotements et variateur
- **JOB 6** : Deux programmes : LEDs clignotant de manière **synchrone** puis **asynchrone**.
- **JOB 7** : Huit LED qui clignotent les unes après les autres.
- **JOB 8** : Allumage progressif d’une LED avec effet de fondu (PWM).

---

## JOB 9 à JOB 11 : Interactions LED / Bouton / Ventilateur
- **JOB 9** : Plusieurs actions sur une LED selon le nombre d’appuis sur le bouton (1x, 2x, 3x, appui long).
- **JOB 10** : Deux LED pilotées par un potentiomètre : l'une s’éteint pendant que l’autre s’allume.
- **JOB 11** : Bouton → LED allumée → après 15s, ventilateur s’allume. Nouvelle pression = ventilateur OFF.

---

## JOB 12 à JOB 14 : LCD et interactions
- **JOB 12** : Affichage “Hello World!” sur un écran LCD 16x2.
- **JOB 13** : Création et affichage d’un smiley personnalisé.
- **JOB 14** : Affichage du **nom du groupe** + **compteur**. Le bouton permet de mettre en pause/reprendre.

---

## JOB 15 : LED RGB et potentiomètre
Utilisation d’un potentiomètre pour modifier la **couleur** d’une LED RGB.

---

## JOB 16 à JOB 18 : Heure, chronomètre et barre de chargement
- **JOB 16** : Affichage de l’heure au format **HH:MM:SS**.
- **JOB 17** : Chronomètre contrôlé par bouton.
- **JOB 18** : Animation de **barre de chargement** sur LCD avec rectangle toutes les 3 secondes.

---

## JOB 19 : Joystick et directions
Lecture du joystick et affichage de la direction (Gauche, Droite, Haut, Bas) sur l’écran LCD.

---

## JOB 20 : Mesure de distance
Utilisation du capteur à ultrasons HC-SR04 pour mesurer une distance et l’afficher sur le LCD.

---

## 🌦️ Station météo
Création d’une **mini-station météo** :
- Température ambiante (TMP36)
- Taux d’humidité (capteur d’humidité sol ou DHT11)
- Affichage cyclique toutes les 2 secondes sur bande RGB et écran LCD ou OLED

🔁 **S’appuie sur les JOB 12, 19 et 20**

---

## 📊 Tableau de bord
Tableau de bord regroupant plusieurs capteurs :
- **Température** : LED bleue (10–18°C), LED rouge (19–21°C), ventilateur (>22°C)
- **Humidité** : LED verte (confortable), LED jaune (inconfort)
- **Luminosité** : via photorésistance
- **Capteur de distance** : Avertissement sonore via buzzer
- **LCD + bouton** : Affichage défilant des mesures

🔁 **Combine les JOB 8, 9, 10, 12, 20**

---

## 🧠 Jeu de mémoire Simons
Jeu interactif :
- Séquence lumineuse aléatoire à mémoriser (LED de différentes couleurs)
- Boutons pour reproduire la séquence
- Affichage du score et niveau sur l’écran LCD
- Signal sonore en cas d’erreur
- Gestion des niveaux de difficulté

🔁 **Utilise JOB 6, 12, 14, boutons et logique aléatoire**

---
