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

test-licznik: 
	./mydb baza.csv count_students

test-memory: 
	 valgrind ./mydb baza.csv count_students 

test-dodajs: 
	 ./mydb baza.csv add_student Zuzanna Mroz 2120 mroz@wp.pl

test-dodajp: 
	 ./mydb baza.csv add_subject 11024 Fizyka 2020Z

test-dodajsp: 
	 ./mydb baza.csv add_student_to_course 1D324 2120