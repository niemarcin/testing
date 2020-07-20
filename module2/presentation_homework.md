<!-- .slide: data-background="#111111" -->

# Testowanie

## Praca domowa

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Pytania z rozmów kwalifikacyjnych

* <!-- .element: class="fragment fade-in" --> Co to są testy jednostkowe?
* <!-- .element: class="fragment fade-in" --> Czy testy jednostkowe to testy white-box czy black-box?
* <!-- .element: class="fragment fade-in" --> Jakie pokrycie kodu testami jest odpowiednie?
* <!-- .element: class="fragment fade-in" --> Jakie znasz narzędzia, które obliczają pokrycie kodu testami?
* <!-- .element: class="fragment fade-in" --> Jakie znasz frameworki do testowania?
* <!-- .element: class="fragment fade-in" --> Który framework uważasz za najciekawszy i dlaczego?
* <!-- .element: class="fragment fade-in" --> Jak przetestować kod, który powoduje rzucenie wyjątku?
* <!-- .element: class="fragment fade-in" --> Jak przetestować kod, który ma powodować crash aplikacji?

___

## Pre-work

* Przeczytaj [GMock for Dummies](https://github.com/google/googletest/blob/master/googlemock/docs/for_dummies.md)
* Zapoznaj się z testami w repozytorium [Pizzas](https://github.com/ziobron/Pizzas). Znajdziesz tam trochę kodu używającego mocków `TEST_F(PizzeriaTest, calculatePriceForPizzaMock)` oraz plik `test/mocks/PizzaMock.hpp`.
* Dopisz własne testy / mocki wedle uznania

___

## Bowling 🎳 - nowy projekt

Obejrzyj [wideo Uncle Boba o TDD](https://trello-attachments.s3.amazonaws.com/5b20ebcd819b419f2d65c274/5b5d70bf109bc670f6d8d10d/90fb5c9305b6e8092df116da1c845210/fm_CleanCode-E6-P2-540p.mp4).

Do zrozumienia punktacji gry w kręgle przydatny może być opis zasad. Jest on dołączony na końcu prezentacji lub dostępny [tutaj](https://github.com/coders-school/testing/blob/master/module2/bowling_rules.txt)

W nowych grupach napiszcie aplikację, która będzie zliczać punkty w kręgielni.

___
<!-- .slide: style="font-size: 0.9em" -->

## Bowling 🎳

### Wymagania (+10 XP za każde spełnione):

* liczenie punktów cząstkowych (dla niepełnych ramek, np: `3-|X|4/|5`)
* liczenie punktów całościowych - [opis zasad](https://github.com/coders-school/testing/blob/master/module2/bowling_rules.txt)
* walidacja inputu z niepełnymi ramkami dla kilku graczy (patrz następny slajd)
* input z wielu plików w jednym katalogu, każdy plik z kilkoma graczami reprezentuje inny tor (zalecane użycie [Filesystem library z C++17](https://en.cppreference.com/w/cpp/filesystem))
* wyświetlanie wyników na ekranie z podziałem na tory (ze statusem gry) i graczy oraz zapis do jednego pliku (następny slajd)
* program (`main.cpp`) ma przyjmować 2 parametry z linii komend. Pierwszy to katalog, w którym będą pliki txt ze stanami gier na torach, a drugi opcjonalny to plik wyjściowy, w którym mają zostać zapisane przetworzone wyniki. Jeśli drugi parametr nie zostanie podany to wyniki mają zostać wypisane na ekran. Przykład użycia: `./bowling inputDirectory results.txt`. Program oczywiście ma działać i realizować powierzone zadanie.
* program (`main.cpp`) po podaniu parametru `-h` lub `--help` ma wyświetlać krótką informację o tym co robi i jak go używać (czyli punkt powyżej)

#### Dostarczenie do końca sierpnia +20 XP

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

___

## Bowling - zasady liczenia punktów

```text
Each game, or "line" of bowling, includes ten turns,
or "frames" for the bowler.

In each frame, the bowler gets up to two tries to
knock down all ten pins.

If the first ball in a frame knocks down all ten pins,
this is called a "strike". The frame is over. The score
for the frame is ten plus the total of the pins knocked
down in the next two balls.

If the second ball in a frame knocks down all ten pins,
this is called a "spare". The frame is over. The score
for the frame is ten plus the number of pins knocked
down in the next ball.

If, after both balls, there is still at least one of the
ten pins standing the score for that frame is simply
the total number of pins knocked down in those two balls.

If you get a spare in the last (10th) frame you get one
more bonus ball. If you get a strike in the last (10th)
frame you get two more bonus balls.
These bonus throws are taken as part of the same turn.
If a bonus ball knocks down all the pins, the process
does not repeat. The bonus balls are only used to
calculate the score of the final frame.

The game score is the total of all frame scores.

Examples:

X indicates a strike
/ indicates a spare
- indicates a miss
| indicates a frame boundary
The characters after the || indicate bonus balls

X|X|X|X|X|X|X|X|X|X||XX
Ten strikes on the first ball of all ten frames.
Two bonus balls, both strikes.
Score for each frame == 10 + score for next two
balls == 10 + 10 + 10 == 30
Total score == 10 frames x 30 == 300

9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||
Nine pins hit on the first ball of all ten frames.
Second ball of each frame misses last remaining pin.
No bonus balls.
Score for each frame == 9
Total score == 10 frames x 9 == 90

5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5
Five pins on the first ball of all ten frames.
Second ball of each frame hits all five remaining
pins, a spare.
One bonus ball, hits five pins.
Score for each frame == 10 + score for next one
ball == 10 + 5 == 15
Total score == 10 frames x 15 == 150

X|7/|9-|X|-8|8/|-6|X|X|X||81
Total score == 167
```
