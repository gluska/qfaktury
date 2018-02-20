# QFaktury 0.7.2


1. [Opis](#opis)  
2. [Wymagania](#wymagania)  
3. [Instalacja zależności](#instalacja-zależności)  
4. [Instalacja](#instalacja)  
5. [Usuwanie](#usuwanie)  
6. [Rozwój](#rozwój)  
7. [Uwagi](#uwagi)  
8. [Zgłaszanie błędów](#zgłaszanie-błędów)  
9. [Zmiany w 2018 roku](#zmiany-w-2018-roku)  

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
- eksport danych do plików CSV


<br/>
<br/>


## Wymagania

- dowolna dystrybucja Linux
- biblioteka Qt w wersji wyższej lub równej 5.10.0
- paczki qt5-base qt5-webengine (lub qtbase5-dev qtwebengine5-dev) (dla modułów Qt GUI, Qt Core, Qt Widgets, Qt Print Support, Qt XML, Qt WebEngine, Qt Network)
- zlib w wersji wyższej lub równej 1.2 (wymagane dla paczki quazip)
- quazip w wersji 0.7.3 lub wyższej (wymagane dla tworzenia kopii zapasowych)
- cmake w wersji 3.9 lub wyższej (wymagane dla kompilacji)
- extra-cmake-modules w wersji 1.7.0 lub nowszej (wymagane dla kompilacji)
- php w wersji 7.1 lub wyższej (opcjonalne dla korzystania z danych GUS)
- gksu w wersji 2.0 lub wyższej (opcjonalne dla konfiguracji PHP)
- C++ w wersji 11 (kod używa rozwiązań wprowadzonych właśnie w tej wersji jak np. lambda)
- połączenie z internetem (opcjonalne)
- aktualny czas systemowy (opcjonalne)

Poniżej znajdują się jednak zależności dla konkretnych dystrybucji.

<br/>
<br/>

## Instalacja zależności

# Arch Linux

```
sudo pacman -S zlib gksu php cmake quazip qt5-base qt5-webengine extra-cmake-modules
```

# Ubuntu / Linux Mint

Żeby skompilować i zainstalować qfaktury na ubuntu 16.4 i jego pochodnych np. linuxmint 18.3 trzeba:

dodać dodatkowe repozytoria:

```
sudo add-apt-repository ppa:beineri/opt-qt-5.10.0-xenial
sudo add-apt-repository ppa:aroth/ppa
sudo add-apt-repository ppa:nschloe/cmake-nightly
sudo add-apt-repository ppa:ondrej/php 

sudo apt-get update
```
następnie zainstalować:

```
sudo apt-get install php7.1 php7.1-common zlib1g-dev zlib1g cmake libquazip5-dev qt510-meta-full libgl-dev extra-cmake-modules build-essential
```

następnie po kompilacji i instalacji by program się uruchamiał bez problemów
trzeba usunąć główny pakiet qtbase5-dev w wersji 5.5.1 (bez jego usunięcia 
nie można utworzyć linku symbolicznego, do nowszej wersji qt 5.10 zlokalizowanej w katalogu /opt (system mówi że nie można utworzyć, bo taki już ustnieje)

```
sudo apt-get --purge remove qtbase5-dev
```

na końcu wpisujemy:

```
sudo updatedb
```

i robimy link symboliczny do qt 5.10

```
sudo ln -s /opt/qt510/lib/* /usr/lib/x86_64-linux-gnu/
```
<i>Autorem powyższego poradnika jest [etammable](https://github.com/etammable)</i>

<br/>

# Debian Jessie

```
sudo apt-get install apt-transport-https lsb-release ca-certificates
wget -O /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg
echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php.list
sudo apt-get update
sudo apt get install php7.1 zlib1g-dev zlib1g cmake gksu libquazip5-dev qtbase5-dev qtwebengine5-dev extra-cmake-modules
```

# Debian Sid

```
sudo apt get install php7.1 zlib1g-dev zlib1g cmake gksu libquazip5-dev qtbase5-dev qtwebengine5-dev extra-cmake-modules
```

# Fedora

```
wget http://rpms.remirepo.net/fedora/remi-release-25.rpm
sudo dnf install remi-release-25.rpm
sudo dnf install dnf-plugins-core
sudo dnf config-manager --set-enabled remi-php71
sudo dnf install zlib-devel cmake beesu quazip qt5-qtbase-devel qt5-qtwebengine-devel extra-cmake-modules
```

# OpenSUSE

```
sudo zypper in php7 php7-devel libz1 zlib-devel cmake gksu libgksu libquazip-qt5 libqt5-qtbase libqt5-qtwebengine extra-cmake-modules
```

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

Jeśli posiadasz Arch Linux bądź pokrewny system (Manjaro) możesz wykonać poniższe kroki:

```
git clone https://github.com/archlinux-lucjan/archlinux-poland.git
cd qfaktury-qt5-git
makepkg -sric
```

<br/>
<br/>


## Usuwanie

W zbudowanym katalogu:

`cat install_manifest.txt | sudo xargs rm`

lub (w Arch Linux), jeśli instalacja nastąpiła z PKGBUILD:

`sudo pacman -Rns qfaktury-qt5-git`

<br/>
<br/>



## Rozwój

Program jest co jakiś czas uaktualniany. Plany jego rozbudowy, wykonane zadania i zadania w trakcie testów znajdują się [na tej stronie](https://github.com/juliagoda/qfaktury/projects/1).

Z racji tego, że ostatnio pojawia się coraz więcej niedziałających "pull request", została stworzona nowa gałąź o nazwie "merged", gdzie wszystkie nadesłane zmiany będą trafiać i przechodzić testy.


<br/>
<br/>


## Uwagi

1. Osoby posiadające faktury, listy kontrahentów i towarów z wcześniejszych wersji (mniejszych niż 0.7.0), powinny wykonać kopię zapasową i skopiować je do katalogu "~/.local/share/data/elinux"

2. Osoby posiadające faktury z wcześniejszych commit'ów w razie jakichkolwiek niepoprawnych wyników mogą spróbować ponownie zapisać istniejąca fakturę, edytując ją, ponieważ możliwe, że dotychczasowe commit'y uwzględniają zauważone błędy i uzupełnią także pliki XML dodatkowymi danymi, które pozwolą korzystać z pełnej funkcjonalności programu. Zalecane jest także trzymać kopię zapasową plików w innym miejscu.

3. Aktualizacja aktualnego kursu walut następuje co pół godziny, pod warunkiem połączenia z internetem oraz poprawnego ustawienia czasu systemowego

4. Jeżeli jeszcze nie istnieje katalog "gus" w ścieżce "~/.local/share/data/elinux", zostaniesz poproszony o autoryzację wykonania skryptu, który przygotowuje plik php.ini do korzystania z klienta SOAP oraz pobiera zależności dla podprojektu bazującego na PHP do prawidłowego uruchomienia aplikacji w celu połączenia z Głównym Urzędem Statystycznym. Jeśli chcesz przygotować plik php.ini ręcznie, nie musisz instalować paczki gksu (tylko pamiętaj, by anulować prośbę o wykonanie konfiguracji PHP). Pierwsze połączenie trwa wiele dłużej z powodu generowania zależności i katalogów na przyszłe wykorzystanie.

5. Jeśli nie chcesz używać danych z Głównego Urzędu Statystycznego, nie musisz instalować paczek gksu, beesu (Fedora) oraz php, ponieważ nie są one obligatoryjne do działania programu.



<br/>
<br/>

## Zgłaszanie błędów

W razie zauważonych błędów lub poważnych braków, można stworzyć wątek [w tym dziale](https://github.com/juliagoda/qfaktury/issues), klikając w zielony przycisk "New issue" po prawej stronie, a następnie wprowadzając tytuł i treść.

<br/>
<br/>

## Zmiany w 2018 roku

Jako, że w 2018 roku wchodzą zmiany w wystawianiu faktur, program jest w trakcie przepisywania tak, żeby kod był czytelniejszy, poukładany i nie zawierał wielu zbędnych i nieużywanych danych. Planowana jest także nowa gałąź "Debug", która może okazać się przydatna przy późniejszym wykrywaniu błędów krytycznych ale i logicznych z pomocą np. testów jednostkowych lub/i innych metod.
