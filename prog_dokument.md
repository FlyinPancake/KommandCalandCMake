# KommandCaland


## Működés

### Mozgás
A program  termek között tudja mozgatni a játékost. 

A játékos a `move IRÁNY` paranccsal mozoghat az égtájak felé.
 
A program nem engedi a játékost bármerre elmenni, hanem csak a kijelölt `layout.txt`-ben lefektetett térképen barangolhat. A program veszélyeket és akadályokat is fog tartalmazni, de ezek még nem készültek el.

### Tárgyak
A játékos használhatja a tárgyait, megnézheti éppen milyen tárgyakat birtokol, illetve fel is vehet jobb vagy teljesen új tárgyakat is.

A `get` vagy `pickup` paranccsal a szobában lévő tárgyat tudja felvenni a játékos.

Az `inv` parancssal a játékos megnézheti mi van nála

A `use <type>` paranccsal pedig a tárgyakat használhatjuk. A type helyére természetesen a tárgy típusa kerül

### Mentés

A játékot bármikor módunkban áll elmenteni. Erre 3 mentési hely áll lehetőségünkre.

A `save` parancs az aktuális metnésbe ment. Ha a játék új játékként volt indítva, akkor a parancs megkérdezi melyik helyre mentse, és a második és következő mentések már oda történnek.

###Egyéb

A játék az `exit` parancsra visszatér a főmenübe.

Ha mégegyszer el szeretnénk olvasni egy szoba elírását, akkor megtehetjük a `room` paranccsal. 


## Adatszerkezet

###Termek

A termek a `rooms` mappában találhatóak, és elrendezésüket a `layout.txt` tartalmazza.

A `layout.txt` tetszőleges szélességű és magasságú, és szobák indexeit tárolja a következő módon:

  

| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 2 | 0 | 0 | 0 |
| 0 | 0 | 3 | 4 | 5 | 0 | 0 |
| 0 | 0 | 6 | 0 | 12 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |

  

A "térképet" körülveszi egy 0-ból álló "kerítés". A program csak oda engedi mozogni a játékost, ahol nem 0 mező van, és ott betölti ahoz a mezőhöz tartozó `rooms/SZÁM.txt` filet.
A program ezt a táblázatot betölti egy dinamikusan foglalt 2 dimenziós tömbbe, majd ezt használja térképnek.

Egy szoba mindig `szobaszám.txt` formátumban van jelen a rooms mappában.
 
Felépítése egyszerű: 6 pár "/" karakter közé kell írni a 3 releváns adatstringet, a többi információt a program átugorja, így commentnek tekinthetjük.

```
Konvencionálisan a szoba száma, ismertetőjele esetlegesen
/a leírás ami megjelenik a játékosnak is
Ez akár több soros is lehet/
veszély/hand[1] / ha nem is akarunk irányt blokkolni akkor is be kell írni valamilyen veszélyt.
item/tipusa[minosege,neve szokozzel]/
```
A termeket a `ReadChapt()` függvény olvassa be, ami meghívja a specializált `ReadAction()` és `ReadItem()` függvényeket is.

Amikor a termeket a program kiírja akkor a `DrawChapter` függvényt használja

A termek elrendezését a `getMovementTable()` függvény olvassa be.

###Tárgyak

Az inventory egy láncolt lista, bármilyen típusú elemből csak egyet (a legjobbat) tartalmaz. Ezt is elmenti a játék, az játékos pozíciójával egyetemben

Minden tárgynak van típusa minősége és neve is.
> a típus max. 9 karakter hosszú, a név max. 29 karakter hosszú lehet

Minden mentés egy Default hand nevű 100-as minőségű hand típusú tárgyyal kezd.

Új tárgyakar az `addItem` függvény ad hozzá az inventoryhoz. Csak abban az esetben adja viszont hozzá, ha még nincs ilyen 
tárgya a játékosnak, vagy csak rosszabb van belőle.

###Mentés

A játék mindig tárolja a játékos x és y koordinátáit. A mentésben az első sor tartalmazza ezeket a koordinátákat.
A többi sor a játékos inventroyját tárolja `type quality name` rendszerrel 

A 0-s mentés az új játék elindításához szükséges.

A mentés elkészítését a `saveGame` nevű függvény végzi.

Az elmentett játékokat egy `Save` típusban adja vissza a `loadSave` függvény.   

##Funkciók

###Mozgás

A mozgás a `move` paranccsal hajtható végre. Ilyenkor a a játékos csak oda mozoghat amelyik irányba van szoba illetve 
nincs blokkolva. A terem körüli termek számát egy `PossibleDirection` típusú változó tárolja. Ezt az egymásba ágyazott 
`findPD` és `blockingDirection` függvényekkel hozzuk létre.

A játékost a `moveTo` függvény mozgatja a másik terembe, ha lehetséges.

###"Halp"

A segítséget a program a `halp.txt` fileból olvassa be.