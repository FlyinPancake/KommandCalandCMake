# Programozói Dokumentáció
A jelenlegi állapothoz képest a 20. századi Balkán-félsziget egy érthető, letisztázott könyv...
## Működés
A program jelenleg termek között tudja mozgatni a játékost. A játékos a `move IRÁNY` paranccsal mozoghat az égtájak felé. A program nem engedi a játékost bármerre elmenni, hanem csak a kijelölt `layout.txt`-ben lefektetett térképen barangolhat. A program veszélyeket és akadályokat is fog tartalmazni, de ezek még nem készültek el.
## Adatszerkezet
A termek a `rooms` mappában találhatóak, és elrendezésüket a `layout.txt` tartalmazza.
A `layout.txt` tetszőleges szélességű és magasságú, és szobák indexeit tárolja a következő módon: 
| 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 1   | 0   | 0   | 0   |
| 0   | 0   | 0   | 2   | 0   | 0   | 0   |
| 0   | 0   | 3   | 4   | 5   | 0   | 0   |
| 0   | 0   | 6   | 0   | 12  | 0   | 0   |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   |
A "térképet" körülveszi egy 0-ból álló "kerítés". A program csak oda engedi mozogni a játékost, ahol nem 0 mező van, és ott betölti ahoz a mezőhöz tartozó `rooms/SZÁM.txt` filet

