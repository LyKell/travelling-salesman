# Auteurs : Kevin SAVANE et Tom REDON
# Creation : 09-04-2019
# Modification : 09-04-2019

# Definition des constantes
CC = gcc
CFLAGS = -ansi -Wall -pedantic
EXEC = pvc
LDFLAGS = -lMLV
OBJ = Main.o IGraph.o GestionFichier.o Visite.o Carte.o Ville.o

# Definition des commandes a effectuer
pvc : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

Main.o : Main.c IGraph.h GestionFichier.h Visite.h

IGraph.o : IGraph.c IGraph.h Visite.h

GestionFichier.o : GestionFichier.c GestionFichier.h Visite.h

Visite.o : Visite.c Visite.h Carte.h

Carte.o : Carte.c Carte.h Ville.h

Ville.o : Ville.c Ville.h

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(LDFLAGS)




# Definition des commandes de nettoyage
clean :
	rm -f *.o

mrproper : clean
	rm -f $(EXEC)


# Definition des commandes a appeler
install : $(EXEC)
	mkdir ../bin
	mv $(EXEC) ../bin/$(EXEC)
	make mrproper

uninstall : mrproper
	rm -f ../bin/$(EXEC)
	rm -rf ../bin
