# RG102-vitez-reda-zmaja

> Vitez reda zmaja je RPG igra u kojoj je cilj savladati sve prepreke i dokazati svoje vestine.

### Trenutni izgled igre
![Screen](screenshots/Program_Stage9.png?raw=true "Current program view")


##  :green_book: O projektu

> U trenutnoj fazi projekta moguce je ucitati model iz sirokog spektra fajlova(.obj, .fbx, .dae, .3ds, ...). Model se moze sastojati iz vise delova gde svaki deo moze imati tekstutu, podatke o skeletu i animacije(trenutno funkcionise samo ucitavanje animacija ali ne i renderovanje). Model se moze kontrolisati komandama sa tasture a takodje postoji i interakcija sa terenom kreiranim pomocu visinskih mapa tako da ce se model uvek nalaziti na povrsini terena. Moguce su kontrole kamere i to: rotiranje po x i y osi kao i zumiranje tj pomeranje kamere po z osi. Podrzano je ucitavanje kutije neba sa teksturama a takodje i smena dnevnog i nocnog neba u zavisnosti od vremena u igri. Moguce je kreiranje 2d objekata u igri kao sto su tekst ili 2D slike. U zavisnost od izabranog vremena moguce je renderovanje cesticnih sistema pomocu kojih mozemo simulirati sneg ili kisu.

### Za vise informacija o procesu izrade projekta pogledajte [wiki](https://github.com/MATF-RG18/RG146-vitez-reda-zmaja/wiki) stranicu projekta



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
#### FreeType
```
sudo apt install libfreetype6-dev

```

#### Assimp
```
sudo apt install libassimp-dev

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
    <th colspan="2">Kontrole vremena</th>
</tr>
<tr>
    <td>:one:</td><td>Bez padavina(podrazumevan mod u igri)</td>
</tr>
<tr>
    <td>:two:</td><td>Sneg</td>
</tr>
<tr>
    <td>:three:</td><td>Kisa</td>
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
> Prilikom kreiranja projekta koriscen je YouTube tutorijal [OpenGL 3D Java Game Tutorial](https://www.youtube.com/watch?v=VS8wlS9hF8E&list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP) koji je u velikoj meri pomogao pri razumevanju kreiranja video igara i uticao na izgled i strukturu projekta. Takodje su koriscene i veb stranice poput:  [Learn OpenGL](https://learnopengl.com/), [NeHe](http://nehe.gamedev.net/), [OGLDEV](http://ogldev.atspace.co.uk/), [GameDev](https://gamedev.stackexchange.com/), kao i ostale stranice koje sadrze informacije o kreiranju video igara, grafike kao i matematike.

> Za pomoc pri upotrebi OpenGL funkcija koriscen je sajt [Khronos](https://www.khronos.org/registry/OpenGL-Refpages/)

> S obzirom na autorov antitalenat za bilo koji vid umetnosti grafika u projektu je preuzimana sa sajtova kao sto je [Sketchfab](https://sketchfab.com/feed) na kojem se mogu naci 3D objekti slobodni za bilo kakvu upotrebu komercijalnu ili ne. Sve grafike u projektu su kombinacije vise zeljenih objekata sa gore navedenog sajta koje su menjane i prilagodjavane za potrebe projekta, sto znaci da objekti nisu samo kopirani vec je bilo potrebno nauciti rad u Blender-u i uopsteno rad sa 3D grafikom i UV teksturisanjem.
