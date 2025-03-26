Una rete televisiva vuole sapere quanto piacciono 10 film.
Per questo, chiede a N persone di compilare un questionario.
Ogni persona deve dare un voto (intero da 1 a 10) a ciascuno dei 10 film.
Dopo che una persona ha finito di rispondere, il programma deve:
calcolare e stampare la media attuale (parziale) dei voti per ogni film.
Alla fine, quando tutti hanno risposto, il programma deve stampare:
la media finale dei voti per ogni film,
il nome del film con la media più alta.

Il programma deve essere scritto in C++, utilizzando:
<ul>
<li>la libreria <thread> per creare un thread per ogni persona,</li>
<li>la funzione sleep() per simulare il tempo di risposta,</li>
<li>un array statico per memorizzare i voti,</li>
<li>random() per generare i voti,</li>
<li>mutex per proteggere i dati condivisi quando più thread accedono contemporaneamente.</li>
</ul>
