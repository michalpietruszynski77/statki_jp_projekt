# statki_jp_projekt
Program to gra w statki PvP. Zawiera następujące klasy:
-gra -Zawiera planszę gracza, na której rozstawia swoje statki, oraz przeciwnika, na której oddaje strzały. Zawiera również metodę odpowiedzialną za oddawanie strzałów.
-boat2 -Klasa definiująca statek długości dwóch modułów, będąca klasą podstawową dla klas definiująchych statki innej długości. Zawiera parametry określające współrzędne modułów oraz ilość nieuszkodzonych modułów. Zawiera metody służące do ustawienia statków na planszy, tak żeby statki mieściły się na planszy i nie kolidowały ze sobą. Zawiera również metodę sprawdzającą czy statek został trafiony oraz czy został zatopiony.
-pozostałe klasy określające statki innej długości dziedziczą po klasie boat2 metody, lub dostosowują je do innej długości statku.
-module -Klasa zawierająca współrzędne modułu oraz jego stan(trafiony/nietrafiony)
Na początku gry każdy z graczy ustawia po kolei swoje statki, najpierw wpisując współrzędne początku statku, a następnie wybierając z opcji wyświetlonych na terminalu współrzędne końca statku. Po ustawieniu wszystkich statków możliwy jest reset planszy i ponowne rozstawienie. Kiedy obaj gracze rozstawią swoje statki rozpoczyna się gra. Gracze strzelają na zmianę wpisując współrzędne strzału. Jeżeli gracz trafił statek przeciwnika, strzela dalej, aż spudłuje. Gra toczy się do momentu aż któremuś z graczy nie zostanie już żaden niezatopiony statek. Wynik gry zapisywany jest do pliku wyniki.txt.
Program posiada plik Makefile do łatwej kompilacji. Aby skompilować program należy użyć komendy "make". Aby uruchomić program należy wpisać na terminalu "./statki".

W celu przestestowania działania programu należy wpisać jedną z poniższych list poleceń w terminalu:
1) Test bez rozstawiania z przykładową planszą: 3,b,2,c,2,d,2,e,2,f,2,b,5,b,6,b,7,b,8,e,4,f,4,g,4,h,7,h,8,h,9,i,2,i,3,i,5,j,5,e,8,f,8
2) Pełen test programu: 1,b,2,1,b,5,4,e,4,1,h,7,4,i,2,4,i,5,1,f,8,3,1
