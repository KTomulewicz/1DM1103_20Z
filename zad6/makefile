# co_chcemy_zrobic:od_czego_to_zalezy
# (TAB)co_trzeba_uruchomic_aby_uzyskac_co
#main:main.c studenci.c dziekanat.c studenci.h dziekanat.h
#	cc main.c studenci.c dziekanat.c -o main -Wall --pedantic
# $@ - powtarza nasza nazwe pliku czyli "main"
# $^ - wstawia wszystko co jest w rzedzie wyzej

#touch - robienie nowego pliku
# po wpisaniu make program odpala pierwsza regule po DEPSie

DEPS=mymatlab.o wczytywanie.o operacje.o

# p7_3: $(DEPS) - odwoluje sie do depsa

mymatlab: $(DEPS)
	 cc $(DEPS) -o $@ -Wall --pedantic -lm 
	

# czyli program kompiluje odwolujac sie do DEPSa i powtarza nazwe main


%.o:%.c
	cc -c $^ -o $@

#main.o:mainc.c
#	cc -c $^ -o $@

#studenci.o:studenci.c
#	cc -c $^ -o $@

#dziekanat.o:dziekanat.c
#	cc -c $^ -o $@

clean:
	rm -f mymatlab
	rm -f *.o

test: mymatlab
	valgrind ./mymatlab prod A.txt B.txt 
