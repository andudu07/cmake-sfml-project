Recreare a jocului doodle jump cu un twist italienesc memetic

--Joc platformer 2D scris in C++ folosind biblioteca SFML. Jucatorul il controleaza pe Brr Brr Patapim care trebuie sa sara intre platforme pentru a castiga puncte, evitand-o pe Lirili Larila, care apare periodic.

Reguli ale Jocului:

Controale:
Sageti stanga/dreapta : Miscare stanga/dreapta
SPACE: Saritura
Scorul:
Creste cu 1 atunci cand treci de o platforma
Scorul se actualizeaza in timp real in coltul stanga sus
High score-ul este salvat intre sesiuni
Obstacole:
Apare un obstacol miscator (Lirili) la fiecare 25 de puncte
Daca lovesti obstacolul sau cazi sub ultima platforma, e game over

--Mosteniri si Clase

Ierarhie de clase:
Character (clasa de baza)
Player (derivata)
Obstacle (derivata)

--Functii Virtuale

update() - functie virtuala pura implementata diferit in Player si Obstacle

getBounds() - virtuala cu implementare specifica in Obstacle pentru hitbox mai mic

--Exceptii

GameException (clasa de baza)
TextureLoadException
HighScoreException
GameStateException

Au fost utilizate in:

Incarcare texturi
Citire/scriere high score
Validarea starii jocului


--STL

--Folosire std::vector pentru platforme

--Metode const



--Functii statice: in managerul de resurse
--Separare cod: header/sursa pentru toate clasele majore
--Fara using namespace std


