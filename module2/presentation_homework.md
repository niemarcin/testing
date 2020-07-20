<!-- .slide: data-background="#111111" -->

# Testowanie

## Praca domowa

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Pre-work

* Przeczytaj [GMock for Dummies](https://github.com/google/googletest/blob/master/googlemock/docs/for_dummies.md)
* Zapoznaj się z testami w repozytorium [Pizzas](https://github.com/ziobron/Pizzas). Znajdziesz tam trochę kodu używającego mocków `TEST_F(PizzeriaTest, calculatePriceForPizzaMock)` oraz plik `test/mocks/PizzaMock.hpp`.
* Dopisz własne testy / mocki wedle uznania

___

## Bowling - nowy projekt

Obejrzyj [wideo Uncle Boba o TDD ](https://trello-attachments.s3.amazonaws.com/5b20ebcd819b419f2d65c274/5b5d70bf109bc670f6d8d10d/90fb5c9305b6e8092df116da1c845210/fm_CleanCode-E6-P2-540p.mp4).

Do zrozumienia punktacji gry w kręgle przydatny może być [ten opis zasad](bowling_rules.txt)

W nowych grupach napiszcie aplikację, która będzie zliczać punkty w kręgielni.

___
<!-- .slide: style="font-size: 0.9em" -->

## Bowling 🎳

Wymagania (8 XP za każde spełnione):

* liczenie punktów cząstkowych (dla niepełnych ramek, np: `3-|X|4/|5`)
* liczenie punktów całościowych - [opis zasad](bowling_rules.txt)
* walidacja inputu z niepełnymi ramkami dla kilku graczy (patrz następny slajd)
* input z wielu plików w jednym katalogu, każdy plik z kilkoma graczami reprezentuje inny tor (zalecane użycie [Filesystem library z C++17](https://en.cppreference.com/w/cpp/filesystem))
* wyświetlanie wyników na ekranie z podziałem na tory (ze statusem gry) i graczy oraz zapis do jednego pliku (następny slajd)
* program (main.cpp) ma przyjmować 2 parametry z linii komend. Pierwszy to katalog, w którym będą pliki txt ze stanami gier na torach, a drugi opcjonalny to plik wyjściowy, w którym mają zostać zapisane przetworzone wyniki. Jeśli drugi parametr nie zostanie podany to wyniki mają zostać wypisane na ekran. Przykład użycia: `./bowling inputDirectory results.txt`. Program oczywiście ma działać i realizować powierzone zadanie.
* program (main.cpp) po podaniu parametru -h lub --help ma wyświetlać krótką informację o tym co robi i jak go używać (czyli punkt powyżej)

___
<!-- .slide: style="font-size: 0.8em" -->

### Bowling - input

`lane1.txt`

```text
Name1:X|4-|3
Name2:34|X|0-
:X|22|33
```

`lane2.txt` (pusty)

`lane3.txt`

```text
Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81
Radek:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||
```

### Bowling - output

```text
### Lane 1: game in progress ###
Name1 30
Name2 44
34
### Lane 2: no game ###
### Lane 3: game finished ###
Michael 167
Radek 90
```

___

## Wymagania organizacyjne

* tablica dla projektu z podziałem na karteczki po planningu
* skonfigurowane Continuous Integration i system budowania
* praca przez pull requesty (każdy PR ma mieć nr i opis z karteczki, musi przejść wewnętrzne Code Review
* zawartość tablicy może się zmieniać w miarę odkrywania nowych wymagań (i na pewno to co założycie na początku się zmieni i dojdzie dużo rzeczy, których nie przewidzieliście)
* od samego początku spróbujcie pracować w trybie TDD
* każda funkcjonalność musi być przetestowana; brak testów = niespełnione wymaganie.
* pracujcie na forkach repo `coders-school/testing`
* po implementacji wszystkich wymagań PR do `coders-school/testing:master`
