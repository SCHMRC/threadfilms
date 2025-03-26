#include <thread>
#include <iostream>
#include <mutex>
#include <unistd.h>
#include <vector>

using namespace std;

int sommaVoti[10] = {0};
int numero_persone_votanti = 0;
float medie[10];
mutex mtx;
string nomiFilm[10] = {
    "Inception", "Interstellar", "Titanic", "Matrix", "Joker",
    "Avatar", "Shrek", "Gladiator", "Toy Story", "Up"};

void task(int nome_persona)
{
    int voti[10];
    for (int i = 0; i < 10; i++)
    {
        voti[i] = rand() % 10 + 1;
        sleep(rand() % 3 + 1);
    }

    mtx.lock();
    numero_persone_votanti++;

    for (int i = 0; i < 10; i++)
    {
        sommaVoti[i] = sommaVoti[i] + voti[i];
    }
    cout << "\033[32mRisultato parziale: " << endl;
    for (int i = 0; i < 10; i++)
    {
        medie[i] = (float)sommaVoti[i] / numero_persone_votanti;
        cout << "\033[37mFilm " << nomiFilm[i] << " : " << medie[i] << endl;
    }

    mtx.unlock();
}

int main()
{
    srand(time(NULL));
    int x = 0;
    cout << "Inserisci il numero di persone che partecipano al sondaggio : ";
    cin >> x;
    vector<thread> persone;

    for (int i = 0; i < x; i++)
    {
        persone.push_back(thread(task, i));
    }

    for (int i = 0; i < x; i++)
    {
        persone[i].join();
    }
    float maxMedie = 0.0;
    int k = 0;
    cout << "risultato finale:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Film " << nomiFilm[i] << " : " << medie[i] << endl;
        if (medie[i] > maxMedie)
        {
            maxMedie = medie[i];
            k = i;
        }
    }

    cout << "Il film che ha la media maggiore è: " << nomiFilm[k] << " con un punteggio di " << maxMedie << endl;
}
