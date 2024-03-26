# Zadanie:

Proszę zaimplementować klasę reprezentującą receptę. Recepta zawiera dane pacjenta, datę
wystawienia, czas ważności, informację o stanie realizacji (niezrealizowana, częściowo zrealizowana,
całkowicie zrealizowana) oraz listę leków. Na potrzeby tego zadania leki mogą być reprezentowane za
pomocą nazw.

# Przyjęte założenia:

1. Recepty nie można wystawić z przyszłą datą.
2. Utworzenie recepty z datą wystawienia w przeszłości jest możliwe, w celu importu wcześniej wystawionej recepty do programu.
3. Data wygaśnięcia nie może być wcześniejsza niż data wystawienia.
4. Status recepty może być zmieniany tylko zgodnie z kierunkiem strzałek
    `in_preparation -> issued -> partly_realised -> realised`