# QFaktury 0.7.1


1. [Opis](#opis)  
2. [Wymagania](#wymagania)
3. [Instalacja](#instalacja)  
4. [Rozwój](#rozwój)  
5. [Uwagi](#uwagi)  
6. [Zgłaszanie błędów](#zgłaszanie-błędów)  

<br/>
<br/>

## Opis

Stale rozwijana aplikacja do obsługi faktur. Aktualnie pozwala na zapis, edycję i drukowanie faktur VAT, Brutto, RR, Pro Forma, Rachunku, Korekty i Duplikatu. Dodatkowo pozwala na dodanie kontrahenta oraz towaru bądź usługi do tworzonej faktury. Program oferuje:

- zmianę waluty według aktualnego kursu ze strony NBP
- walidację wprowadzanych danych oraz sprawdzanie sum kontrolnych
- wybór trzech szablonów drukowania
- wydrukowanie listy kontrahentów wraz z danymi
- wybór motywu
- wybór kodowania
- prowadzenie organizera z kalendarzem
- przedstawienie słownie kwoty na fakturze w formacie od dziesiątek po miliardy wraz z wartościami po przecinku
- dodanie własnych elementów do listy wyborów stawek VAT, metod płatności, powodów korekty, sposobu numeracji faktur, dopisku, jednostek
- stworzenie i wczytywanie kopii zapasowej plików konfiguracyjnych oraz głównego katalogu
- dodanie kolejnych sprzedawców/oddziałów
- wysłanie e-mail do kontrahentów wraz z załącznikami z możliwością korzystania z gotowych szablonów
- korzystanie z danych Głównego Urzędu Statystycznego z podaniem numeru NIP


<br/>
<br/>


## Wymagania

- dowolna dystrybucja Linux
- biblioteka Qt w wersji wyższej lub równej 5.0.0
- paczki qt5-base qt5-webengine (dla modułów Qt GUI, Qt Core, Qt Widgets, Qt Print Support, Qt XML, Qt WebEngine, Qt Network)
- zlib w wersji wyższej lub równej 1.2
- quazip w wersji 0.7.3 lub wyższej
- cmake w wersji 3.9 lub wyższej
- php w wersji 7.1 lub wyższej
- gksu w wersji 2.0 lub wyższej
- połączenie z internetem (opcjonalne)
- aktualny czas systemowy (opcjonalne)

<br/>
<br/>

## Instalacja zależności

# Arch Linux

``

# Ubuntu

``

# Debian

``

# Fedora

``

# OpenSUSE

``

# Linux Mint

``

<br/>
<br/>


## Instalacja

Wykonujemy pobranie katalogu z plikami w wybranej przez siebie ścieżce i wpisujemy polecenia:

```
git clone -b testing https://github.com/juliagoda/qfaktury.git
cd qfaktury
mkdir zbudowane
cd zbudowane
cmake ..
make
sudo make install
```

<br/>
<br/>




## Rozwój

Program jest co jakiś czas uaktualniany. Plany jego rozbudowy, wykonane zadania i zadania w trakcie testów znajdują się [na tej stronie](https://github.com/juliagoda/qfaktury/projects/1).


<br/>
<br/>


## Uwagi

1. Osoby posiadające faktury, listy kontrahentów i towarów z wcześniejszych wersji (mniejszych niż 0.7.0), powinny wykonać kopię zapasową i skopiować je do katalogu "~/.local/share/data/elinux"

2. Osoby posiadające faktury z wcześniejszych commit'ów w razie jakichkolwiek niepoprawnych wyników mogą spróbować ponownie zapisać istniejąca fakturę, edytując ją, ponieważ możliwe, że dotychczasowe commit'y uwzględniają zauważone błędy i uzupełnią także pliki XML dodatkowymi danymi, które pozwolą korzystać z pełnej funkcjonalności programu. Zalecane jest także trzymać kopię zapasową plików w innym miejscu.

3. Aktualizacja aktualnego kursu walut następuje co pół godziny, pod warunkiem połączenia z internetem oraz poprawnego ustawienia czasu systemowego

4. Jeżeli jeszcze nie istnieje katalog "gus" w ścieżce "~/.local/share/data/elinux", zostaniesz poproszony o autoryzację wykonania skryptu, który przygotowuje plik php.ini do korzystania z klienta SOAP oraz pobiera zależności dla podprojektu bazującego na PHP do prawidłowego uruchomienia aplikacji w celu połączenia z Głównym Urzędem Statystycznym"


<br/>
<br/>

## Zgłaszanie błędów

W razie zauważonych błędów lub poważnych braków, można stworzyć wątek [w tym dziale](https://github.com/juliagoda/qfaktury/issues), klikając w zielony przycisk "New issue" po prawej stronie, a następnie wprowadzając tytuł i treść.
