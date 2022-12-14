
# Øvelser 14. december

Bemærk at noten om afviklingsplot er opdateret pr 13. december
for at kunne danne baggrund for de følgende opgaver.


## Opgave 1

Denne opgave handler om forskellige out-of-order maskiners ydeevne ved udførelse
af en og samme stump kode.

Husk at angive eventuelle antagelser du måtte gøre i forbindelse med besvarelsen.


Nedenfor ses to iterationer af en løkke-krop udført på en 2-vejs out-of-order mikroarkitktur med max 1 cache tilgang pr clock

1                       0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41
    addi x4,x4,1        Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)        Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x12,x4,2             Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    add  x12,x17,x12          Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    sw   x11,0(x12)              Fa Fb Fc De Fu Al Rn Qu -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    -                                                 Qu -- -- -- -- pk rd st
    bge  x9,x4,Loop              Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    addi x4,x4,1                    Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5                   Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11                   Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)                    Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x12,x4,2                         Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    add  x12,x17,x12                      Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    sw   x11,0(x12)                          Fa Fb Fc De Fu Al Rn Qu -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    -                                                             Qu -- -- -- -- pk rd st           |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    bge  x9,x4,Loop                          Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
2
    addi x4,x4,1                                Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5                               Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11                               Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)                                Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x12,x4,2                                     Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    add  x12,x17,x12                                  Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |
    sw   x11,0(x12)                                      Fa Fb Fc De Fu Al Rn Qu -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |
    -                                                                         Qu -- -- -- -- pk rd st
    bge  x9,x4,Loop                                      Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |
    addi x4,x4,1                                            Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5                                           Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11                                           Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)                                            Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |  |  |  |  |
    slli x12,x4,2                                                 Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |
    add  x12,x17,x12                                              Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |
    sw   x11,0(x12)                                                  Fa Fb Fc De Fu Al Rn Qu -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |  |  |  |  |
    -                                                                                     Qu -- -- -- -- pk rd st           |  |  |  |  |  |  |  |  |
    bge  x9,x4,Loop                                                  Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |
3
    addi x4,x4,1                                                        Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5                                                       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11                                                       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)                                                        Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |
    slli x12,x4,2                                                             Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |
    add  x12,x17,x12                                                          Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |
    sw   x11,0(x12)                                                              Fa Fb Fc De Fu Al Rn Qu -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |
    -                                                                                                 Qu -- -- -- -- pk rd st
    bge  x9,x4,Loop                                                              Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- Ca Cb  |  |  |  |
    addi x4,x4,1                                                                    Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |
    slli x11,x4,5                                                                   Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |
    add  x11,x16,x11                                                                   Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- Ca Cb  |  |  |
    lw   x11,8(x11)                                                                    Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc wb Ca Cb  |  |
    slli x12,x4,2                                                                         Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- Ca Cb  |  |
    add  x12,x17,x12                                                                      Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |
    sw   x11,0(x12)                                                                          Fa Fb Fc De Fu Al Rn Qu -- pk rd ag ma mb mc -- Ca Cb  |
    -                                                                                                             Qu -- -- -- -- pk rd st           |
    bge  x9,x4,Loop                                                                          Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- Ca Cb

Bemærk at store instruktioner opsplittes i to (cache opslag og data skrivning til skrive-kø)
som scheduleres separat.

### Spg 1.1

Hvad er IPC hvis løkken udføres uendeligt mange gange og alle hop forudsiges korrekt ?

loop_n_Cb: 13 -> 25

Cb has a total of 16*n occurences = 16*n
Total clock cycles = 13 -> 25 = 13*n

ICP = 16*n / 13*n = 1.23

### Spg 1.2

Hvad er IPC for 20 gennemløb af løkken?

loop1_Cb:   13 ->  25
loop2_Cb:   21 ->  33
loop3_Cb:   29 ->  41
loop4_Cb:   37 ->  49
loop5_Cb:   45 ->  57
loop6_Cb:   53 ->  65
loop7_Cb:   61 ->  73
loop8_Cb:   69 ->  81
loop9_Cb:   77 ->  89
loop10_Cb:  85 ->  97
loop11_Cb:  93 -> 105
loop12_Cb: 101 -> 113
loop13_Cb: 109 -> 121
loop14_Cb: 117 -> 129
loop15_Cb: 125 -> 137
loop16_Cb: 133 -> 145
loop17_Cb: 141 -> 153
loop18_Cb: 149 -> 161
loop19_Cb: 157 -> 169
loop20_Cb: 165 -> 177

Cb has total of 16*20 occurences = 320
Total clock cycles = 13 -> 177 = 165

ICP = 320 / 165 = 1.94

hint: inkluder omkostningen ved den afsluttende fejlforudsigelse.

Nedenfor ses to iterationer af den samme løkke-krop på en 4-vejs out-of-order mikroarkitektur med max 2 cache tilgange pr clock.
1                       0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
    addi x4,x4,1        Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11    Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)     Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    slli x12,x4,2          Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    add  x12,x17,x12       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    sw   x11,0(x12)        Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    -                                           Qu -- -- -- -- -- -- pk rd st  |  |  |  |  |  |  |  |  |  |  |  |  |
    bge  x9,x4,Loop        Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |
    addi x4,x4,1              Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5             Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11          Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)           Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |  |  |  |
    slli x12,x4,2                Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |
    add  x12,x17,x12             Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |  |
    sw   x11,0(x12)              Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |  |  |  |  |
    -                                                 Qu -- -- -- -- -- -- pk rd st  |  |  |  |  |  |  |  |  |  |  |
    bge  x9,x4,Loop              Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |  |
2
    addi x4,x4,1                    Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |  |
    slli x11,x4,5                   Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |  |
    add  x11,x16,x11                Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |  |  |
    lw   x11,8(x11)                 Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |  |  |
    slli x12,x4,2                      Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |  |  |  |  |
    add  x12,x17,x12                   Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |  |
    sw   x11,0(x12)                    Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |  |  |
    -                                                       Qu -- -- -- -- -- -- pk rd st  |  |  |  |  |  |  |  |  |
    bge  x9,x4,Loop                    Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- -- Ca Cb  |  |  |  |  |  |
    addi x4,x4,1                          Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |  |  |  |
    slli x11,x4,5                         Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |  |
    add  x11,x16,x11                      Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- Ca Cb  |  |  |  |  |  |
    lw   x11,8(x11)                       Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |  |  |
    slli x12,x4,2                            Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |  |  |
    add  x12,x17,x12                         Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |  |  |
    sw   x11,0(x12)                          Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc -- Ca Cb  |  |  |  |  |
    -                                                             Qu -- -- -- -- -- -- pk rd st  |  |  |  |  |  |  |
    bge  x9,x4,Loop                          Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- -- Ca Cb  |  |  |  |
3
    addi x4,x4,1                                Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |
    slli x11,x4,5                               Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |
    add  x11,x16,x11                            Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |
    lw   x11,8(x11)                             Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |
    slli x12,x4,2                                  Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |
    add  x12,x17,x12                               Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |
    sw   x11,0(x12)                                Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc -- Ca Cb  |  |  |
    -                                                                   Qu -- -- -- -- -- -- pk rd st  |  |  |  |  |
    bge  x9,x4,Loop                                Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- -- Ca Cb  |  |
    addi x4,x4,1                                      Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |
    slli x11,x4,5                                     Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |
    add  x11,x16,x11                                  Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- Ca Cb  |  |
    lw   x11,8(x11)                                   Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |
    slli x12,x4,2                                        Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |
    add  x12,x17,x12                                     Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |
    sw   x11,0(x12)                                      Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ag ma mb mc -- Ca Cb  |
    -                                                                         Qu -- -- -- -- -- -- pk rd st  |  |  |
    bge  x9,x4,Loop                                      Fa Fb Fc De Fu Al Rn Qu pk rd ex -- -- -- -- -- -- -- Ca Cb

## Spg 1.3

Hvad er IPC for 20 gennemløb af løkken?

loop1_Cb:  13 -> 22
loop2_Cb:  17 -> 26
loop3_Cb:  21 -> 30
loop4_Cb:  25 -> 34
loop5_Cb:  29 -> 38
loop6_Cb:  33 -> 42
loop7_Cb:  37 -> 46
loop8_Cb:  41 -> 50
loop9_Cb:  45 -> 54
loop10_Cb: 49 -> 58
loop11_Cb: 53 -> 62
loop12_Cb: 57 -> 66
loop13_Cb: 61 -> 70
loop14_Cb: 65 -> 74
loop15_Cb: 69 -> 78
loop16_Cb: 73 -> 82
loop17_Cb: 77 -> 86
loop18_Cb: 81 -> 90
loop19_Cb: 85 -> 94
loop20_Cb: 89 -> 98

Cb has total of 16*20 occurences = 320
Total clock cycles = 13 -> 98 = 86

ICP = 320 / 86 = 3.72

Nedenfor ses to iterationer af den samme løkkekrop på en 8-vejs out-of-order mikroarkitektur
med max 3 cache tilgange pr clock

1                       0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22
    addi x4,x4,1        Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |  |
    slli x11,x4,5       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |  |
    add  x11,x16,x11    Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb Ca Cb  |  |  |  |  |  |  |
    lw   x11,8(x11)     Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |  |  |
    slli x12,x4,2       Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |
    add  x12,x17,x12    Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |
    sw   x11,0(x12)     Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc -- Ca Cb  |  |  |
    -                                        Qu -- -- -- -- -- -- -- pk rd st  |  |  |  |  |
    bge  x9,x4,Loop     Fa Fb Fc De Fu Al Rn Qu -- pk rd ex -- -- -- -- -- -- Ca Cb  |  |  |
    addi x4,x4,1           Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |  |  |
    slli x11,x4,5          Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |  |  |
    add  x11,x16,x11       Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- Ca Cb  |  |  |
    lw   x11,8(x11)        Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |  |
    slli x12,x4,2          Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- -- Ca Cb  |  |
    add  x12,x17,x12       Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- -- Ca Cb  |  |
    sw   x11,0(x12)        Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc -- Ca Cb  |  |
    -                                           Qu -- -- -- -- -- -- -- pk rd st  |  |  |  |
    bge  x9,x4,Loop        Fa Fb Fc De Fu Al Rn Qu -- pk rd ex -- -- -- -- -- -- Ca Cb  |  |
2
    addi x4,x4,1              Fa Fb Fc De Fu Al Rn Qu pk rd ex wb Ca Cb  |  |  |  |  |  |  |
    slli x11,x4,5             Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb Ca Cb  |  |  |  |  |  |
    add  x11,x16,x11          Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb Ca Cb  |  |  |  |  |
    lw   x11,8(x11)           Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb  |
    slli x12,x4,2             Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- -- Ca Cb  |
    add  x12,x17,x12          Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- -- Ca Cb  |
    sw   x11,0(x12)           Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc -- Ca Cb  |
    -                                              Qu -- -- -- -- -- -- -- pk rd st  |  |  |
    bge  x9,x4,Loop           Fa Fb Fc De Fu Al Rn Qu -- pk rd ex -- -- -- -- -- -- Ca Cb  |
    addi x4,x4,1                 Fa Fb Fc De Fu Al Rn Qu pk rd ex wb -- -- -- -- -- Ca Cb  |
    slli x11,x4,5                Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- Ca Cb  |
    add  x11,x16,x11             Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- Ca Cb  |
    lw   x11,8(x11)              Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc wb Ca Cb
    slli x12,x4,2                Fa Fb Fc De Fu Al Rn Qu -- pk rd ex wb -- -- -- -- -- Ca Cb
    add  x12,x17,x12             Fa Fb Fc De Fu Al Rn Qu -- -- pk rd ex wb -- -- -- -- Ca Cb
    sw   x11,0(x12)              Fa Fb Fc De Fu Al Rn Qu -- -- -- pk rd ag ma mb mc -- Ca Cb
    -                                                 Qu -- -- -- -- -- -- -- pk rd st  |  |
    bge  x9,x4,Loop              Fa Fb Fc De Fu Al Rn Qu -- pk rd ex -- -- -- -- -- -- Ca Cb

### Spg 1.4

Hvad er IPC for 20 gennemløb af løkken.

loop1_Cb:  13 -> 20
loop2_Cb:  15 -> 22
loop3_Cb:  17 -> 24
loop4_Cb:  19 -> 26
loop5_Cb:  21 -> 28
loop6_Cb:  23 -> 30
loop7_Cb:  25 -> 32
loop8_Cb:  27 -> 34
loop9_Cb:  29 -> 36
loop10_Cb: 31 -> 38
loop11_Cb: 33 -> 40
loop12_Cb: 35 -> 42
loop13_Cb: 37 -> 44
loop14_Cb: 39 -> 46
loop15_Cb: 41 -> 48
loop16_Cb: 43 -> 50
loop17_Cb: 45 -> 52
loop18_Cb: 47 -> 54
loop19_Cb: 49 -> 56
loop20_Cb: 51 -> 58

Cb has a total of 16 * 20 occurences = 320
Total clock cycles = 13 -> 58 = 56

ICP = 320 / 56 = 3.72 = 5.52


### Spg 1.5

hvad vil IPC være for 20 gennemløb af løkken på en 12-vejs ooo med max 4 cache tilgange pr clock ?

Giv en solid begrundelse for dit svar. Opstil om nødvendigt et afviklingsplot.



## Opgave 2

Opstil en risc-v kodesekvens:

 * hvor en load der følger efter en store tilgår samme adresse og derfor skal "se" data fra store instruktionen
 * hvor store data endnu ikke er tilgængelig i store-køen på det tidspunkt, hvor load instruktionen skal bruge det

diskuter/opstil/giv en mere præcis definition af det sidste af disse to krav.


## Opgave 3

### Spg 1

Opstil en risc-v kodesekvens:

 * hvor en load der følger efter en store tilgår samme adresse og derfor skal "se" data fra store instruktionen
 * hvor store addressen endnu ikke er tilgængelig i store-køen på det tidspunkt, hvor load instruktionen har brug
   for at sammenligne addresser.

diskuter/opstil/giv en mere præcis definition af det sidste af disse to krav.

### Spg 2

Opstil et afviklingsplot som illustrerer ovenstående på en 4-vejs out-of-order mikroarkitektur med en
cache tilgang pr clock. Diskuter evt hvornår load instruktionen tidligst kan gennemføre et writeback.

### Spg 3

I forlængelse af spg 2. Diskuter hvornår en instruktion som afhænger af load-instruktionen tidligst
vil kunne begynde udførelse.

