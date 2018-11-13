# RG102-vitez-reda-zmaja

> Vitez reda zmaja je RPG igra u kojoj je cilj savladati sve prepreke i dokazati svoje vestine.

### Dnevni rezim igre
![Screen](screenshots/Program_Day.png?raw=true "Current program day view")

### Nocni rezim igre
![Screen](screenshots/Program_Night.png?raw=true "Current program night view")

##  :green_book: O projektu

> Trenutno je moguce ucitati obj fajl kreiran pomocu alata kao sto je Blender3D i pridruziti mu texturu ukoliko je textura kreirana pomocu "unwrap"(UV) metoda, i kreiranje terena. Postoji mogucnost transformacije ucitanog objekta kao sto su rotacija, translacija i skaliranje, takodje je moguce kontrolisati kameru rotiranjem po x i y osi kao i zumiranje tj. pomeranje po z osi kao i podesavanje osvetljenja u igri. Moguce je kreiranje neba i smena dana i noci. 



## :package: Instalacija

### Zahtevano za instalaciju

#### Freeglut 
```
sudo apt install freeglut3-dev
``` 

#### Libglm
```
sudo apt install libglm-dev
``` 

#### Libpng
```
sudo apt install libpng-dev
```
#### Magick++
```
sudo apt install graphicsmagick-libmagick-dev-compat

```

### Upustvo za instalaciju
```
git clone https://github.com/MATF-RG17/RG102-vitez-reda-zmaja.git
```
```
cd RG102-vitez-reda-zmaja
```
```
make
```

### Pokretanje igre
```
cd RG102-vitez-reda-zmaja
```
```
./Test
```

## :video_game: Kontrole
<table>
<tr>
    <th colspan="2">Kontrole kamere</th>
</tr>
<tr>
    <td>:arrow_double_up:  Skrolovanje</td><td>Uvelicavanje</td>
</tr>
<tr>
    <td>:arrow_double_down:  Skrolovanje</td><td>Umanjivanje</td>
</tr>
<tr>
    <td>W</td><td>Rotacija kamere</td>
</tr>
<tr>
    <td>S</td><td>Rotacija kamere</td>
</tr>
<tr>
    <td>A</td><td>Rotacija kamere</td>
</tr>
<tr>
    <td>D</td><td>Rotacija kamere</td>
</tr>
<table>

<table>
<tr>
    <th colspan="2">Kontrole igraca</th>
</tr>
<tr>
    <td>:arrow_up:</td><td>Napred</td>
</tr>
<tr>
    <td>:arrow_down:</td><td>Nazad</td>
</tr>
<tr>
    <td>:arrow_left:</td><td>Levo</td>
</tr>
<tr>
    <td>:arrow_right:</td><td>Desno</td>
</tr>
<table>

<table>
<tr>
    <th colspan="2">Kontrole igre</th>
</tr>
<tr>
    <td>Esc</td><td>Izlaz iz igre</td>
</tr>
<table>

##  :large_blue_circle: Napomena
> Prilikom kreiranja projekta koriscen je YouTube tutorijal [OpenGL 3D Java Game Tutorial](https://www.youtube.com/watch?v=VS8wlS9hF8E&list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP) koji je u velikoj meri pomogao pri razumevanju kreiranja video igara i uticao na izgled i strukturu projekta.

> Za pomoc pri upotrebi OpenGL funkcija koriscen je sajt [Khronos](https://www.khronos.org/registry/OpenGL-Refpages/)

> Da bi postojala mogucnost ucitavanja slozenijih .obj fajlova koriscena je biblioteka [tinyobjloader](https://github.com/syoyo/tinyobjloader) koja je preuzeta sa github-a.

> S obzirom na autorov antitalenat za bilo koji vid umetnosti grafika u projektu je preuzimana sa sajtova kao sto je [Sketchfab](https://sketchfab.com/feed) na kojem se mogu naci 3D objekti slobodni za bilo kakvu upotrebu komercijalnu ili ne. Sve grafike u projektu su kombinacije vise zeljenih objekata sa gore navedenog sajta koje su menjane i prilagodjavane za potrebe projekta, sto znaci da objekti nisu samo kopirani vec je bilo potrebno nauciti rad u Blender-u i uopsteno rad sa 3D grafikom i UV teksturisanjem.
