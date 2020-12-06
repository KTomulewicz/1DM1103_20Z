

all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-dodajs: all
	./mydb baza.csv add_student Zuza Mroz 2120 zuzmroz@wp.pl

test-dodajp: all
	./mydb baza.csv add_przedmiot 1DM1103 Programowanie 2020Z

test-dodajsp: all
	./mydb baza.csv add_student_to_course 1DM1103 949827

test-zlicz: all
	./mydb baza.csv count_students	

test-memory: all
	valgrind ./mydb baza.csv count_students



#student - imie nazwisko nr albumu email

