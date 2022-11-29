# Øvelsesopgaver for 28/11

COD:
* A4:
    One logic function that is used for a variety of purposes
    (including within adders and to compute parity) is exclusive XOR. The output of a
    two-input exclusive OR function is true only if exactly one of the inputs is true.
    Show the truth table for a two-input exclusive OR function and implement this
    function using AND gates, OR gates, and inverters.

    AND: AB == A*B == A and B
    OR: A + B == A or B
    NOT: Ã == B

    XOR truth table:
       A |   B | XOR
    -----+-----+-----
       0 |   0 |   0
    -----+-----+-----  Sum case
       1 |   0 |   1   (A B') + (A' B)
    -----+-----+-----
       0 |   1 |   1
    -----+-----+-----
       1 |   1 |   0
    -----+-----+-----
     B' = not B

    ANSWER: AB' + A'B

* A.5:
    Prove that the NOR gate is universal by showing how to build
    the AND, OR, and NOT functions using a two-input NOR gate.

     Not OR truth table:
       A |   B | NOR
    -----+-----+-----
       0 |   0 |   1
    -----+-----+-----
       1 |   0 |   0
    -----+-----+-----
       0 |   1 |   0
    -----+-----+-----
       1 |   1 |   0
    -----+-----+-----

* A.11: (very important for understanding pensum)
    Assume that X consists of 3 bits, x2 x1 x0. Write four
    logic functions that are true if and only if;
        1) X contains only one 0
        2) X contains an even number of 0s
        3) X when interpreted as an unsigned binary number is less than 4
        4) X when interpreted as a signed (two’s complement) number is negative
    ANSWER: 1) xxx
            2) xxx
            3) xxx
            4) xxx


* A.13: (very important for understanding pensum)
    Assume that X consists of 3 bits, x2 x1 x0, and Y
    consists of 3 bits, y2 y1 y0. Write logic functions that are true if and only if
        1) X < Y, where X and Y are thought of as unsigned binary numbers
        2) X < Y, where X and Y are thought of as signed (two’s complement) numbers
        3) X = Y

* A.24:
    The ALU supported set on less than (slt) using just the sign bit
    of the adder. Let’s try a set on less than operation using the values − 7ten and 6ten. To
    make it simpler to follow the example, let’s limit the binary representations to 4 bits:
    1001_2 and 0110_2.

        1001_2 − 0110_2 = 1001_2 + 1010_2 = 0011_2

    This result would suggest that −7> 6, which is clearly wrong. Hence, we must
    factor in overflow in the decision. Modify the 1-bit ALU in Figure A.5.10 on page
    A-33 to handle slt correctly. Make your changes on a photocopy of this figure to
    save time.

* A.39:
    Construct a 3-bit counter using three D flip-
    flops and a selection of gates. The inputs should consist of a signal that resets the
    counter to 0, called reset, and a signal to increment the counter, called inc. The
    outputs should be the value of the counter. When the counter has value 7 and is
    incremented, it should wrap around and become 0.

Ekstraopgaver for de særligt interesserede:
A.26, A.27, A.31, A.32

NandGame: et godt spil til at lære og forstå logik
https://nandgame.com/ (se hvor langt i kan komme)
