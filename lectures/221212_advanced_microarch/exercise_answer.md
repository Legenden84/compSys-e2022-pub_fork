# Øvelser til 12. december

## Opsamling

Brug tid til at afklare spørgsmål A5.

Overskydende øvelser fra forrige uge.

## Øvelser i afviklingsplot

(se note her: https://github.com/diku-compSys/compSys-e2022-pub/blob/main/resources/Afviklingsplot/plot.md)

### Opgave 1

Fe - Instruktionshentning (fetch)
De - Instruktionsafkodning (decode)
Ex - Udførelse af aritmetik (execute)
Mm - Tilgang til lager hvis load eller store (memory)
Wb - Opdatering af registre med resultat (writeback)

IPC = Instruction per cycle

Eks:
                        0  1  2  3  4  5  6  7  8
lw   x11,0(x10)         Fe De Ex Mm Wb

Store Type
Pipeline: Fetch, Decode, Execute, Memory

Branch Type
Pipeline: Fetch, Decode, Execute

Jump
Pipeline: Fetch, Decode

ALU -> R Type
Pipeline: Fetch, Decode, Execute, Write


Opstil et afviklingsplot for en simpel 5-trins pipeline som beskrevet i COD (og i begyndelsen af noten) for to
iterationer af følgende programstump:

~~~
Loop:
    addi x4,x4,1
    slli x11,x4,5
    add  x11,x16,x11
    lw	 x11,8(x11)
    slli x12,x4,2
    add	 x12,x17,x12
    sw   x11,0(x12)
    bge  x9,x4,Loop
~~~

NB: Assume no forwarding (i.e. can only execute when Write-back has been performed)
                        0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22
addi  x4,  x4,    1     Fe  De  Ex  Mm  Wb
slli x11,  x4,    5         Fe  De  De  De  Ex  Mm  Wb
 add x11, x16,  x11             Fe  Fe  Fe  De  De  De  Ex  Mm  Wb
  lw x11,     8(x11)                        Fe  Fe  Fe  De  De  De  Ex  Mm  Wb
slli x12,  x4,    2                                     Fe  Fe  Fe  De  Ex  Mm  Wb
 add x12, x17,  x12                                                 Fe  De  De  Ex  Mm  Wb
  sw x11,     0(x12)                                                    Fe  Fe  Fe  De  De  
 bge  x9,  x4, loop

### Opgave 2

Opstil et afviklingsplot for en 5-trins 2-vejs superskalar pipeline som beskrevet i noten for to
iterationer af programstumpen fra opgave 1.

Hvis der er tvivlspørgsmål undervejs vælges en mulig fortolkning - gå ikke i stå.
Anfør eventuelle antagelser om mikroarkitekturen.
