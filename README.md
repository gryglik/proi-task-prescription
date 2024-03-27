# Autor
- Autor: Michał Gryglicki
- Numer indeksu: 331380
# Zadanie:

Proszę zaimplementować klasę reprezentującą receptę. Recepta zawiera dane pacjenta, datę
wystawienia, czas ważności, informację o stanie realizacji (niezrealizowana, częściowo zrealizowana,
całkowicie zrealizowana) oraz listę leków. Na potrzeby tego zadania leki mogą być reprezentowane za
pomocą nazw.

# Przyjęte założenia:
## Klasy
### 1. Date
#### Założenia
Klasa reprezentująca datę za pomocą trzech pól: `(uint) day`, `(uint) month`, `(uint) year` (dzień, miesiąc, rok).
* Sprawdzanie poprawności tworzonego obiektu(daty)
#### Konstruktory
* Kontruktor domyślny - tworzy instancje klasy z datą systemową.
* Konstruktor - tworzy instancje klasy z podanych danych (day, month, year).
* Konstruktor - tworzy instancję klasy za pomocą podanego (string) napisu w formacie dd-mm-yyyy
#### Operatory
* Przeładowane operatory porównania (==, !=, >, >=, <, <=)
#### Metody
* `print()` - zwraca (string) napis z reprezentacją datą w postaci dd-mm-yyyy

### 2. Patient
#### Założenia
Klasa reprezentująca pacjenta za pomocą trzch pól: `(string) name`, `(string) surname`, `(Date) birthDate` (imię, nazwisko, data urodzenia).
* Pole `name` [1, 50] znaków
* Pole `surname` [1, 70] znaków
* Pole `birthDate` [1-1-1900, today]
#### Konstruktory
* Konstruktor domyślny - tworzy instancję klasy z niezainicjalizowanymi polami
#### Metody
* `print()` - zwraca (string) napis z reprezentacją pacjenta w postaci
```
{name} {surname}
{date}
```

### 3. Prescription
#### Założenia
Klasa reprezentująca receptę za pomocą pól: `(Patient) patient`, `(Date) issueDate`, `(Date) expiryDate`, `(States) status`, `(vector<string>) medicines` (pacjent, data wystawienia, data ważności, status, leki)
* Recept nie można wystawić z przyszłą datą.
* Utworzenie recepty z datą wystawienia w przeszłości jest możliwe, w celu importu wcześniej wystawionej recepty do programu.
* Data wygaśnięcia nie może być wcześniejsza niż data wystawienia.
* Status recepty może być zmieniany tylko zgodnie z kierunkiem strzałek
    `in_preparation -> issued -> partly_realised -> realised`
* Nie można wystawić/przekazać do realizacji pustej recepty
#### Konstruktory
* Konstruktor - tworzy instancje klasy, do inicjalizacji obiektu recepty `Prescription` konieczne jest podanie pacjenta `Patient` i daty wygaśnięcia `expiryDate` opcjonalnie można podać datę wystawienia
#### Metody
* `setStatus()` - zmienia statusu recepty
* `search((string) medicine)` - zwraca (bool) informację czy dany lek znajduje się na recepcie
* `modify((string) medicine, (string) new_medicine)` - modyfikuje podany lek na recepcie
* `remove((string) medicine)` - usuwa podany lek z recepty
* `printMedicines()` - zwraca (string) zapis z wszystkimi lekami na recepcie (w kolejności dodawania)
* `print()` - zwraca (string) reprezentację recepty w postaci napisu
```
[ PATIENT ]
{name} {surname}
{date}

[ MEDICINES ]
{medicine_1}
{medicine_2}
.
.
{medicine_n}

[ STATUS ] {status}

[ ISSUE DATE ] {issueDate}

[ EXPIRY DATE ] {expiryDate}
```

# Działanie pliku main
1. Z własną datą wystawienia
```
build/main.exe {imie} {nazwisko} {data urodzenia (dd-mm-yyyy)} {data ważności (dd-mm-yyyy)} {data wystawienia (dd-mm-yyyy)} {lek_1} {lek_2} ... {lek_n} {status (in_preaparation, issued, partly_realised, realised)}
```
np.

```
build/main.exe Michal Gryglicki 30-03-2004 28-03-2024 28-02-2024 Clatra_10_mg Xanax_20_mg issued
```

2. Z systemową (dzisiejszą) datą wystawienia
```
build/main.exe {imie} {nazwisko} {data urodzenia (dd-mm-yyyy)} {data ważności (dd-mm-yyyy)} today {lek_1} {lek_2} ... {lek_n} {status (in_preaparation, issued, partly_realised, realised)}
```
np.
```
build/main.exe Michal Gryglicki 30-03-2004 28-03-2024 today Clatra_10_mg Xanax_20_mg Izotziaja_20mg realised

```

**Uwaga** Poszczególne nazwy leków nie mogą zawierać spacji
# Przemyślenia
Czy metoda prywatna obiektu może rzucać wyjątki?