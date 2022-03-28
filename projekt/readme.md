# 2048
==========

Hru lze pouzivat, jak v terminalu, tak i v sdl grafice.   Pomoci Makefile se propoji vsechny potrebnecasti dohromady. 

## Terminal
 Pro build hry v terminalu:

```
make 2048
```
hra se spusti po provedeni 

```
./2048 a b 
```      
kde a, b odpovidaji pozadovanemu poctu radku a sloupcu, resp.

Hra v terminalu se ovlada pomoci klaves a,s,w,d (pohyby vlevo, dolu, nahoru,vpravo). Cilem hry je pospojovat cisla do hodnoty 2048. Pokud se pole naplni a neni umoznen pohyb, hrac prohrava. Hru lze vypnout pomoci klavesy x.

## Build v SDL grafice:

```
make 2048sdl
```
hra se spusti po provedeni 

```
./2048sdl a b 
```      
kde a, b odpovidaji pozadovanemu poctu sloupcu a radku, resp.

Hra se ovlada pomoci sipek (navigacni klavesy). 




