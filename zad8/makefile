DEPS=main.o baza.o 

mydb: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic 

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o

test: 
	valgrind ./mydb baza.csv list_students
#działa

test-licznik: 
	./mydb baza.csv count_students
#działa

test-memory: 
	 valgrind ./mydb baza.csv count_students 
#działa

test-dodajs: 
	 ./mydb baza.csv add_student Maks Pudelko 4200 maksior@wffw.pl
#działa

test-dodajp: 
	 ./mydb baza.csv add_subject 1dm1102 gzk 2020Z
#działa

test-dodajo: 
	 ./mydb baza.csv add_ocena 1D3143 2121 5 super
#działa

test-sortuj-rosnaco-student-nazwisko:
	./mydb baza.csv sortuj_rosnaco_student
#działa - sortowanie od A do Z

test-sortuj-malejaco-student-nazwisko:
	./mydb baza.csv sortuj_malejaco_student
#działa - sortowanie od Z do A

test-sortuj-rosnaco-przedmiot-kod:
	./mydb baza.csv sortuj_rosnaco_przedmiot_kod
#działa - od najmniejszego kodu

test-sortuj-malejaco-przedmiot-kod:
	./mydb baza.csv sortuj_malejaco_przedmiot_kod
#działa - od najwiekszego kodu

test-sortuj-rosnaco-przedmiot-nazwa:
	./mydb baza.csv sortuj_rosnaco_przedmiot_nazwa
#działa - sortowanie od A do Z

test-sortuj-malejaco-przedmiot-nazwa:
	./mydb baza.csv sortuj_malejaco_przedmiot_nazwa
#działa - sortowanie od Z do A

test-szukaj-po-przedmiot:
	./mydb baza.csv szukaj_po_przedmiot 1D324
#dziala
test-szukaj-oceny-po-albumie:
	./mydb baza.csv szukaj_oceny_po_albumie 2121
#dziala