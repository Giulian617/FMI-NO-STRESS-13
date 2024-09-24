_"Scoateți ultimul produs. Așezați la loc ultimul produs. Scoateți ultimul produs. Un operator va veni să vă asiste."_

# Cerință

Costel face cumpărăturile la Mega. El acum se află în fața a $N$ case de marcat _self-check_ și are $M$ oameni în fața lui la coadă. Pentru fiecare cumpărător $i$ se cunoaște timpul $t_{i}$ în care își termină checkout-ul. Coada se mișcă în felul următor:

* Primii $N$ oameni de la coadă ocupă primele $N$ case de marcat
* Aceștia își realizează checkout-ul în paralel, iar cumpărătorul $i$ ocupă o casă de marcat timp de $t_i$ minute
* Atunci când un cumpărător termină de facut checkout-ul, acesta pleacă și îi ia locul următorul de la coadă

Se cere să se afle după cât timp ajunge Costel la o casă de marcat.

# Date de intrare

Pe prima linie se găsesc două numere întregi, $N$ și $M$. Pe următoarea linie se găsesc $M$ numere, reprezentând timpii în care oamenii de la coadă își fac checkout-ul.

# Date de ieșire

Pe prima linie se va găsi un singur număr întreg, timpul după care ajunge Costel la o casă de marcat.

# Restricții și precizări

* $1 \leq N, M \leq 200\ 000$;
* $1 \leq t_i \leq 1\ 000\ 000\ 000$;
* Pentru teste în valoare de $6$ puncte, $M < N$;
* Pentru alte teste în valoare de $8$ puncte, $M = N$;
* Pentru alte teste în valoare de $4$ puncte, $N = 1$;
* Pentru alte teste în valoare de $13$ puncte, $t_i$ sunt egale pentru oricare $1 \leq i \leq M$;
* Pentru alte teste în valoare de $27$ de puncte, $M \leq 2000$;

# Exemplul 1

`stdin`
```
2 7
1 6 3 2 3 5 4
```

`stdout`
```
11
```

## Explicație

Sunt 2 case de marcat, iar coada este formată din $7$ oameni ($8$ cu tot cu Costel). Acțiunea se desfășoară în felul următor:

| Coada         | Acțiunea                                                 | Timp rămas la casa 1 | Timp rămas la casa 2 | Timp total |
|---------------|----------------------------------------------------------|----------------------|----------------------|------------|
| 1 6 3 2 3 5 4 |                                                          |                      |                      | 0          |
| 3 2 3 5 4     | Primii doi oameni ocupă casele de marcat                 | 1                    | 6                    | 0          |
| 2 3 5 4       | Pleacă primul om și îi ia locul al treilea               | 3                    | 5                    | 1          |
| 3 5 4         | Pleacă al treilea om și îi ia locul al patrulea          | 2                    | 2                    | 4          |
| 4             | Pleacă ambii oameni simultan și le iau locul următorii 2 | 3                    | 5                    | 6          |
|               | Pleacă al cincilea om și îi ia locul al șaptelea         | 4                    | 2                    | 9          |
|               | Pleacă al șaptelea om și Costel ajunge la casă           | 2                    |                      | 11         |

# Exemplul 2


`stdin`
```
3 2
10000 10000
```

`stdout`
```
0
```

## Explicație

Sunt $3$ case de marcat, dar $2$ oameni la coadă ($3$ cu tot cu Costel). Toți 3 pot ocupa din prima casele de marcat, deci Costel nu va aștepta niciun minut până își face checkout-ul.


