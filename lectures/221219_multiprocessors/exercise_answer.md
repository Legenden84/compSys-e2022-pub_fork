# Øvelser til 19. december

1. Øvelser fra i onsdags som ikke blev løst, eller hvor der er stor usikkerhed om deres løsning. Bemærk der er nu offentliggjort vejledende løsninger.

2. Brug tid på at sikre forståelse af A6

3. Der kommer ikke øvelser til dagens stof (heller ikke til eksamen)


## Opgave 1

Spg 1:

Oversæt dette C-fragment til RISC-V assembler

~~~
while (a < limit) { *a++ = *b++; }
~~~

hvor de tre variable a,b og limit alle er af typen pointer to int.

ANSWER:

x10 = a, x11 = b, x12 = limit

loop:
    bge     x10, x12, end
    lw      t1. 0(x11)
    addi    x11, x11, 4
    sw      t1, 0(x10)
    addi    x10, x10, 4
    jal loop

end:



Spg 2:

Konstruer et afviklingsplot der viser afvikling af
to iterationer af løkken i dit program på en simpel 
5-trins pipeline med fuld forwarding.

Eksempel på fuld forwarding:
addi x10, x11, 5    Fe De Ex Mm Wr
addi x11, x10, 10       

Spg 3:

Konstruer et afviklingsplot der viser afvikling af to iterationer af
løkken i dit program på en 2-vejs superskalar in-order maskine med
realistisk cache tilgang.

Gør eventuelt antagelser om branch prediction

Spg 4:

Konstruer er afviklingsplot der viser afvikling af to iterationer
af løkken i dit program på en 2-vejs out-of-order maskine som
beskrevet i noten.
