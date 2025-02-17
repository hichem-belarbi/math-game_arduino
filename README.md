## 🇬🇧 **English Version**

# 🎮 **Arduino Math Game**

### 👨‍💻 **By HICHEM belarbi**

## 📌 **Description**
This project is an **Arduino-based math game** that challenges the player to solve arithmetic problems within a limited time. The game:
✅ **Displays an arithmetic problem (addition, subtraction, or multiplication)** on an LCD screen.
✅ **Provides four answer choices**, one of which is correct.
✅ **Assigns a button to each answer choice** for selection.
✅ **Checks if the answer is correct**, updating the score if so.
✅ **Includes a 10-second timer** to answer the question.
✅ **Restarts the game if time runs out or the answer is incorrect.**

## 🎮 **Features**
- 📺 **LCD screen to display the problem and choices**
- 🎲 **Randomized arithmetic problems (addition, subtraction, multiplication)**
- ⏳ **10-second countdown timer**
- ✅ **Score tracking for correct answers**
- 🔄 **Game reset after incorrect answers or timeout**
- **Feedback messages for correct, incorrect, and timeout scenarios**

## 🔧 **Hardware Used**
- 💻 **Arduino Uno**
- 📺 **LCD Display (16x2 or similar)**
- 🎮 **4 Push Buttons (one for each answer choice)**
- ⏳ **Timer implementation via Arduino code**

## 🚀 **Operation**
1. **Game Start:** A random arithmetic problem appears on the LCD screen.
2. **Answer Selection:** Four answer choices are displayed, each linked to a push button.
3. **Player Input:** The player presses the button corresponding to the chosen answer.
   - ✅ *Correct Answer:* Displays “Correct!” and increases the score.
   - ❌ *Wrong Answer:* Displays “Wrong!” and resets the game.
   - ⏳ *Timeout:* If no answer is given within 10 seconds, displays “Time Out!”.
4. **Game Restart:** After an incorrect answer or timeout, the screen shows “A new game? Press any button”.
   - If no button is pressed, the game remains in standby mode.
   - Pressing any button starts a new round with a fresh problem.

## 🛫 **Installation and Usage**
1. **Upload the code** to the **Arduino Uno** using the Arduino IDE.
2. **Connect the components** following the wiring diagram (see "pics" folder for schematics).
3. **Start the system** and use the buttons to select answers.
4. **Observe the LCD display** for questions, answers, and feedback messages.

## ⚖️ **License**
This project is **open-source**. Feel free to use and modify it.

---

## 🇫🇷 **Version Française**

# 🎮 **Jeu de Mathématiques sur Arduino**

### 👨‍💻 **Par HICHEM belarbi**

## 📌 **Description**
Ce projet est un **jeu de mathématiques basé sur Arduino**, mettant au défi le joueur de résoudre des opérations arithmétiques en un temps limité. Le jeu :
✅ **Affiche une opération arithmétique (addition, soustraction ou multiplication)** sur un écran LCD.
✅ **Propose quatre choix de réponse**, dont un seul est correct.
✅ **Attribue un bouton à chaque choix** pour la sélection.
✅ **Vérifie si la réponse est correcte** et augmente le score en cas de succès.
✅ **Inclut un chronomètre de 10 secondes** pour répondre.
✅ **Redémarre le jeu en cas de mauvaise réponse ou d'expiration du temps.**

## 🎮 **Fonctionnalités**
- 📺 **Affichage LCD pour l’énoncé et les choix**
- 🎲 **Problèmes arithmétiques aléatoires (addition, soustraction, multiplication)**
- ⏳ **Minuteur de 10 secondes**
- ✅ **Suivi du score pour les bonnes réponses**
- 🔄 **Redémarrage du jeu après une erreur ou une expiration du temps**
- 🎵 **Messages de retour pour bonne réponse, mauvaise réponse et expiration du temps**

## 🔧 **Matériel Utilisé**
- 💻 **Arduino Uno**
- 📺 **Écran LCD (16x2 ou similaire)**
- 🎮 **4 Boutons-poussoirs (un pour chaque choix de réponse)**
- ⏳ **Minuteur géré par le code Arduino**

## 🚀 **Fonctionnement**
1. **Début du Jeu :** Une opération arithmétique aléatoire apparaît sur l'écran LCD.
2. **Sélection de Réponse :** Quatre choix de réponse sont affichés, chacun relié à un bouton-poussoir.
3. **Entrée du Joueur :** Le joueur appuie sur le bouton correspondant à sa réponse.
   - ✅ *Bonne Réponse :* Affiche “Correct !” et augmente le score.
   - ❌ *Mauvaise Réponse :* Affiche “Faux !” et réinitialise le jeu.
   - ⏳ *Temps Écoulé :* Si aucune réponse n'est donnée en 10 secondes, affiche “Temps écoulé !”.
4. **Redémarrage du Jeu :** Après une mauvaise réponse ou un timeout, l'écran affiche “Nouveau jeu ? Appuyez sur un bouton”.
   - Si aucun bouton n'est pressé, le jeu reste en veille.
   - Appuyer sur un bouton démarre une nouvelle partie avec un nouvel exercice.

## 🛫 **Installation et Utilisation**
1. **Téléverser le code** sur l’**Arduino Uno** via l’IDE Arduino.
2. **Brancher les composants** selon le schéma du projet (voir dossier "pics" pour le schéma).
3. **Démarrer le système** et utiliser les boutons pour sélectionner les réponses.
4. **Observer l’affichage LCD** pour voir les questions, les réponses et les messages de feedback.

## ⚖️ **Licence**
Ce projet est **open-source**. Vous pouvez l’utiliser et le modifier librement.


