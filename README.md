# Doodle Jump brainrot mode

Recrearea jocului Doodle Jump cu un twist italienesc memetic

Joc platformer 2D scris în C++ folosind biblioteca SFML. Jucătorul îl controlează pe Brr Brr Patapim care trebuie să sară între platforme pentru a câștiga puncte, evitând-o pe Lirili Larila, care apare periodic.

Atunci cand patapim atinge platforme, e propulsat automat in sus. In caz ca platforma e de tip trambulina, saritura e pe masura.

## Controale

- Săgeți stânga/dreapta: Mișcare stânga/dreapta

## Scorul

- Crește cu 1 atunci când treci de o platformă
- Scorul se actualizează în timp real în colțul stânga sus
- High score-ul este salvat între sesiuni

## Obstacole

- Apare un obstacol mișcător (Lirili) la fiecare 25 de puncte
- Dacă lovești obstacolul sau cazi sub ultima platformă, e game over



## Moșteniri și Clase
- Character (clasa de bază)
  - Player (derivată)
  - Obstacle (derivată)

## Funcții Virtuale
- update() - funcție virtuală pură implementată diferit în Player și Obstacle
- getBounds() - virtuală cu implementare specifică în Obstacle pentru hitbox mai mic

## Excepții
- GameException (clasa de bază)
  - TextureLoadException
  - HighScoreException

Utilizate în:
- Încărcare texturi
- Citire/scriere high score

## Caracteristici Tehnice
- STL: Folosire std::vector pentru platforme
- Metode const: Implementate pentru acces sigur la date
- Separare cod: Header/sursă pentru toate clasele majore
- Fără using namespace std: Cod curat și explicit

## Templates
- clasa template este Platform
- functia libera template este checkCollision

## Design Patterns
- Singleton pentru clasa Game
- Object pool pentru reciclarea platformelor
