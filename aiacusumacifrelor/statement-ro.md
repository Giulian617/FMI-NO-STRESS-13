# Cerință

Se dă un număr natural $Q$ și $Q$ numere naturale $x$, cărora li se pot aplica un număr arbitrat de transformări. O transformare constă în următoarele tipuri de operații:

* Adunare sau înmulțire cu $2$ ($x \leftarrow x + 2$ sau $x \leftarrow x \cdot 2$);
* Adunare sau înmulțire cu $3$ ($x \leftarrow x + 3$ sau $x \leftarrow x \cdot 3$);
* Adunare sau înmulțire cu $5$ ($x \leftarrow x + 5$ sau $x \leftarrow x \cdot 5$);
* Adunare sau înmulțire cu $7$ ($x \leftarrow x + 7$ sau $x \leftarrow x \cdot 7$).

Pentru fiecare număr din cele $Q$ date, se cere numărul minim de transformări care trebuie aplicate astfel încât suma cifrelor numărului rezultat să fie divizibilă cu $9$.

# Date de intrare

Pe prima linie se găsește un număr natural $Q$. Pe fiecare din următoarele $Q$ linii se găsește câte un număr natural $x$.

# Date de ieșire

Pe linia $i$ se va afișa numărul minim de transformări aplicate celui de-al $i$-lea număr.

# Restricții și precizări

* $1 \leq Q \leq 10^5$;
* $1 \leq x \leq 10^{18}$;
* Pentru $70$ de puncte, $1 \leq x \leq 10^9$;

# Exemplu

`stdin`
```
3
4
9
23895791
```

`stdout`
```
1
0
2
```

## Explicație

Pentru $x = 4$, acesta se poate aduna cu $5$, obținând astfel $9$.
Pentru $x = 9$, acesta are deja suma cifrelor divizibilă cu $9$.
Pentru $x = 23895793$, aplicăm două transformări:
1. $x \leftarrow x + 2$, acesta devenind egal cu $23895795$;
2. $x \leftarrow x \cdot 3$, acesta devenind egal cu $71687385$, care are suma cifrelor $45$.