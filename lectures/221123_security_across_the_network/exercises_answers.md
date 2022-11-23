# Exercises for Introduction to security and encryption

## Exercises from Chapter 8 of Kurose and Ross on "Security"
* P3
Consider the polyalphabetic system shown in figure 8.4. Will a chosen plaintext attack that is able to get the plaintext encoding of the 
message "The quick brown fox jumps over the lazy dog." be sufficient to decode all messages? Why or why not?

Answer: No. Since polyalphabetic systems use more Ceasar ciphers. The above encoding of the phrase is not enough to decode all messages.

* P8
RSA how to:
    1)  Pick two random prime numbers (greater numbers, harder to crack!)

    2)  Compute: n = pq
                 z = (p - 1)(q - 1)

    3)  Choose a number (e) with two conditions;
        a) Must be a prime.
        b) Must be less then z (totient)
        c) Must not be a factor of z (z / e != 0).

    4)  Find a number d, such that (ed - 1) % z = 0.
                                      or de % n = 1

    5)  Public key: K+(n,e), private key: K-(n,d)

Encrypting and decripting with RSA:


Consider RSA with  p = 7 and q = 13.
a)  What are n and z?
    n = pq = 7 * 13 = 91
    z = (p - 1)(q - 1) = (7 - 1)(13 - 1) = 72

b)  Let e be 17. Why is this an acceptable choice for e?
    Because 17 does not have a common factor z (72) and is a Fermat prime. (2^2^n + 1)

c)  Find d such that de % n = 1
    1) Insert known variables:
        17d % 72 = 1

    2) Write out multiplication of 17 (e). See table below

    3) Compute these numbers % 72 (n). See table below

      i |   1 |   2 |   3 |   4 |   5 |   6 |   7 |   8 |   9 |  10 |  11 |  12 |  13 |  14 |  15 |  16 |  17 |
    ----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    e*i |  17 |  34 |  51 |  68 |  85 | 102 | 119 | 136 | 153 | 170 | 187 | 204 | 221 | 238 | 255 | 272 | 289 |
    ----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    % 2 |  72 |  34 |  51 |  68 |  13 |  30 |  47 |  64 |   9 |  26 |  43 |  60 |   5 |  22 |  39 |  56 |   1 |

    d is computed to be 289. Numbers further up the table that has mod 1. Is better.

d)  Encrypt the message m = 9 using key (n,e). Let c denote the corresponding ciphertext. Show all work.
    1)  Pick two random prime numbers, and compute n and z.
        p = 11, q = 5
        n = pq = 55
        z = (11 - 1)(5 - 1) = 40
    2)  Pick e, such that the two conditions are true.
        e = 7
    3) Compute d, de mod n = 1. Write out table.

    d = 121

* P9
In this problem, we explore the Diffie-Hellman (DH) public-key encryption algorithm, which allows two entities to
agree on shared key. The DH algorithm makes use of a large prime number p and another large number g, less then p.
Both p and g are made public (so the attacker would know them). In DH, Alice and Bo each idependently choose
secret keys, SA and SB, respectively. Alice then computes her public key, TA, by raising g to SA and then taking 
mod p. Bob similarly computes his own public jey TB by raising g to SB and then taking mod p. Alice and Bob then
exchange their public keys over the internet. Alice then calculates the shared secret key S by raising TB to SA and
then taking mod p. Similarly, Bob calculates the shared key S' by raising TA to SB and then taking mid p.

    a) Prove that, in general, Alice and Bob obtain the same symmetric key, that is, prove S = S'.
        Given:
           Alice:              Bob:
            SA: secret key      SB: secret key
            TA = g^SA mod p     TB = g^SB mod p
            S = TB^SA mod p     S' = TA^SB mod p

        Proof: Prove that S = S'
            S = (g^SB mod p)^SA mod p       ### Substitute TB with g^SB % p
            S = ((g^SB)^SA mod p) mod p     ### Apply math rule (1): (a mod p)^b = a^b mod p
            S = ((g^SA)^SB mod p) mod p     ### Apply math rule (2): (a^b)^c = (a^c)^b
            S = (g^SA mod p)^SB mod p       ### Apply math rule (1) in reverse.
            S = TA^SB mod p                 ### substitute (g^SA mod p)

    b) With p = 11 and g = 2, suppose Alice and bob choose privat keys SA = 5 and SB = 12, respectively. Calculate 
    Alice's key and Bob's public keys, TA and TB. Show work.
        TA = g^SA mod p         TB = g^SB mod p
        TA = 2^5 mod 11         TB = 2^12 mod 11
        TA = 32 mod 11          TB = 4096 mod 11
        TA = 10                 TB = 4

* P10
* P13
* P15
* P17
* P19

## Not Promgramming Task
Create a diagram for your solution to A4. This should show each of the different processes/threads and how they communicate with each other. Identify any points of deadlock present and then either justfiy why they won't occur, or redesign your solution. You may find your design is deadlock free, in which case justify this asssessment.

Make a note of any shared variables between different processes/threads and determine if any race conditions will occur. If so, alter your design to account for this either my managing access to those variables or not sharing them at all.

As a note, this is the sort of thing that looks very nice in a report, along with any discussion relating to it.