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
* Konstruktor szczegółowy - tworzy instancje klasy z podanych danych (day, month, year).
#### Operatory
* Przeładowane operatory porównania (==, !=, >, >=, <, <=)
#### Metody
* print() - zwraca (string) napis z reprezentacją datą w postaci dd-mm-yyyy

### 2. Patient
#### Założenia
Klasa reprezentująca pacjenta za pomocą trzch pól: `(string) name`, `(string) surname`, `(Date) birthDate` (imię, nazwisko, data urodzenia).
* Pole `name` [1, 50] znaków
* Pole `surname` [1, 70] znaków
* Pole `birthDate` [1-1-1900, today]
#### Konstruktory
* Konstruktor domyślny - tworzy instancję klasy z niezainicjalizowanymi polami
#### Metody
* print() - zwraca (string) napis z reprezentacją pacjenta w postaci
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

# Przemyślenia
Czy metoda prywatna obiektu może rzucać wyjątki?