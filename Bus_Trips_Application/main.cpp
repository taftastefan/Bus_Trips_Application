#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<sstream>
#include<vector>
using namespace std;

int gcd(int a, int h)
{
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

string RSA(string message) {
    double p = 17;
    double q = 19;

    string encryptedMessage;

    double n = p * q;

    double e = 2;
    double phi = (p - 1) * (q - 1);
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    for(int i = 0; i < message.length(); i++) {

        double msg = static_cast<double>(message[i]);

        double c = pow(msg, e);
        c = fmod(c, n);

        char encryptedLetter = static_cast<char>(c);

        encryptedMessage.push_back(encryptedLetter);
    }

    return encryptedMessage;
}

bool isChar(char c) {

    return((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z'));
}
bool isDigit(const char c) {

    return (c >= '0' && c <= '9');
}
//Regex
bool isValid(string email) {

    if(!isChar(email[0])) {
        return 0;
    }

    int a = -1, b = -1;

    for(int i = 0; i < email.length(); i++) {
        if(email[i] == '@')
            a = i;
        else if(email[i] == '.')
            b = i;
    }

    if(a == -1 || b == -1)
        return 0;

    if(a > b)
        return 0;

    return !(b >= (email.length() - 1));
}
bool isValid1(string parola)
{   int a = 0, b = 0, c = 0;
    if(parola.length() < 8)
    {
        cout<<"Parola este prea scurta.";
        return 0;
    }
    for(int i = 0; i < parola.length(); i++)
    {
        if(parola[i] >= '0' && parola[i] <= '9')
        c++;
        else if(parola[i] >= 'a' && parola[i] <= 'z')
        a++;
        else if(parola[i] >= 'A' && parola[i] <= 'Z')
        b++;
        }
        try {
    if (c == 0) {
        throw "Parola nu contine cifre.";
    }

    if (b == 0) {
        throw "Parola nu contine majuscule.";
    }

    if (a + b + c == parola.length()) {
        throw "Parola nu contine caractere speciale.";
    }

} catch (const char* message) {
    cout << message << endl;
    return 0;
}
        return 1;
}

string statie_plecare(bool cf)
{

    ifstream orase;
    string oras;
    bool oras_gasit;

    // Deschide fișierul "orase.txt"
    orase.open("orase.txt");
    string plecare;

    // Solicită orașul de plecare de la utilizator
    cout << "Plecare: ";
    cin >> plecare;

    // Caută orașul în fișierul citit
    while (getline(orase, oras)) {
        if (!oras.compare(plecare)) {
            oras_gasit = true;
        }
    }

    // Dacă orașul nu este găsit, afișează un mesaj de eroare și cere utilizatorului să reintroducă orașul
    if (!oras_gasit) {
        cout << plecare << " nu exista in baza de date. Incercati din nou!\n";
        plecare = statie_plecare(oras_gasit);
    }

    // Închide fișierul "orase.txt"
    orase.close();

    // Returnează orașul de plecare
    return plecare;
}

string statie_destinatie(bool cf) {

    ifstream orase;
    string oras;
    bool oras_gasit;

    // Deschide fișierul "orase.txt"
    orase.open("orase.txt");

    string destinatie;

    // Solicită destinația de la utilizator
    cout << "Destinatie: ";
    cin >> destinatie;

    // Caută destinația în fișierul citit
    while (getline(orase, oras)) {
        if (!oras.compare(destinatie)) {
            oras_gasit = true;
        }
    }

    // Dacă destinația nu este găsită, afișează un mesaj de eroare și cere utilizatorului să reintroducă destinația
    if (!oras_gasit) {
        cout << destinatie << " nu exista in baza de date. Incercati din nou!\n";
        destinatie = statie_destinatie(oras_gasit);
    }

    // Închide fișierul "orase.txt"
    orase.close();

    // Returnează destinația validată
    return destinatie;
}

class Autocar {

    public:
        string Id;
        string plecare, destinatie;
        string pret, c1;
        string an, luna, ziua, ora, minute;

        void adaugare_cursa() {
            int d, m, y, h, mi;
            bool cf1 = false, cf2 = false;
            cout<<"ID: ";
            cin>>Id;

            plecare  = statie_plecare(cf1);
            destinatie = statie_destinatie(cf2);
            cout<<"Numar de locuri disponibile si pretul unui bilet ";
            cin>>c1>>pret;
            cout<<"Date calatoriei (dd/mm/yyyy hh:mm):\n";
            cout<<"Ziua: ";
            cin>>d;
            cout<<"Luna: ";
            cin>>m;
            cout<<"An: ";
            cin>>y;
            cout<<"Ora: ";
            cin>>h;
            cout<<"Minute: ";
            cin>>mi;

            while(y < 2023) {
                cout<<"Data invalida. Va rugam introduceti din nou anul. (anul >= 2023)\n";
                cout<<"An: ";
                cin>>y;
            }

            while( m < 0 || m > 12) {
                cout<<"Data invalida. Va rugam introduceti din nou luna. ( luna <= 12 && luna >= 0\n";
                cout<<"Luna: ";
                cin>>m;
            }

            if( y % 4 == 0) {
                if( m == 2 && d > 29) {
                    cout<<"Data invalida. Va rugam introduceti din nou ziua in conformitate cu restul datelor. (ziua <= 29)\n";
                    cout<<"Ziua: ";
                    cin>>d;
                }
            }
            else {
                if(m == 2 && d > 28) {
                    cout<<"Data invalida. Va rugam introduceti din nou ziua in conformitate cu restul datelor. (ziua <= 28)\n";
                    cout<<"Ziua: ";
                    cin>>d;
                }

                else
                    if((m == 1 || m == 3 || m == 5 || m ==7 || m == 8 || m == 10 || m == 12) && d > 31) {
                        cout<<"Data invalida. Va rugam introduceti din nou ziua in conformitate cu restul datelor. (ziua <= 31)\n";
                        cout<<"Ziua:";
                        cin>>d;
                    }
                    else
                        if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
                            cout<<"Data invalida. Va rugam introduceti din nou ziua in conformitate cu restul datelor. (ziua <= 30)\n";
                            cout<<"Ziua: ";
                            cin>>d;
                        }
            }

            while( h > 23 || h < 0) {
                cout<<"Ora invalida. Va rugam introduceti din nou ora. ( ora <= 23 && ora >= 00)\n";
                cout<<"Ora: ";
                cin>>h;
            }

            while( mi > 59 || mi < 0) {
                cout<<"Ora invalida. Va rugam introduceti din nou minutele. ( minute <= 59 && minute >= 00)\n";
                cout<<"Minute: ";
                cin>>mi;
            }

            ofstream autocaroutput;
            ifstream autocarinput;
            autocarinput.open ("autocar.csv");
            autocaroutput.open ("autocar.csv",ios::app);

            if(autocarinput.is_open())
                autocaroutput<<Id<<','<<plecare<<','<<destinatie<<','<<c1<<','<<pret<<','<<d<<','<<m<<','<<y<<','<<h<<','<<mi<<endl;

            cout<<"Cursa a fost adaugata in baza de date\n";

            autocarinput.close();
            autocaroutput.close();

        }

        void stergere_cursa() {

            cout<<"Introduceti ID-ul cursei pe care vreti sa o stergeti: ";
            cin>>Id;

            string Id1, linie;
            bool cursa_gasita = false;
            ifstream autocar;
            ofstream fictiv;

            fictiv.open("fictiv.csv");
            autocar.open("autocar.csv");

            while(getline(autocar, Id1, ',')) {
                getline(autocar, linie);
                if(Id1.compare(Id)) {
                    fictiv<<Id1<<','<<linie<<endl;
                }
                else {
                    cursa_gasita = true;
                }
            }

            fictiv.close();
            autocar.close();
            remove("autocar.csv");
            rename("fictiv.csv","autocar.csv");

            if(cursa_gasita) {
                cout<<Id<<" Cursa stearsa din baza de date\n";
            }
            else {
                cout<<Id<<" Cursa nu a fost gasita. Va rugam incercati din nou.\n\n";
                stergere_cursa();
            }

        }

        int cautare_cursa(vector<Autocar> &cursedisponibile) {

            int k = 0;

            cout<<"Statia de plecare: ";
            cin>>plecare;
            cout<<"Statia de sosire: ";
            cin>>destinatie;

            string plecare1, destinatie1, Id1, c12, pret1, d, m, y, h, mi;
            bool destinatie_gasita = false, plecare_gasita = false;

            ifstream autocar;

            autocar.open("autocar.csv");

            while(getline(autocar, Id1, ',')) {
                getline(autocar, plecare1, ',');
                getline(autocar, destinatie1, ',');
                getline(autocar, c12, ',');
                getline(autocar, pret1, ',');
                getline(autocar, d, ',');
                getline(autocar, m, ',');
                getline(autocar, y, ',');
                getline(autocar, h, ',');
                getline(autocar, mi);
                if(!plecare1.compare(plecare) && !destinatie1.compare(destinatie)) {
                    destinatie_gasita = true;
                    plecare_gasita = true;

                    cursedisponibile[k].Id = Id1;
                    cursedisponibile[k].plecare = plecare1;
                    cursedisponibile[k].destinatie = destinatie1;
                    cursedisponibile[k].c1 = c12;
                    cursedisponibile[k].pret = pret1;
                    cursedisponibile[k].ziua =d;
                    cursedisponibile[k].luna = m;
                    cursedisponibile[k].an = y;
                    cursedisponibile[k].ora = h;
                    cursedisponibile[k].minute =  mi;
                    cout<<"ID: " <<Id1 <<endl;
                    cout<<"De la: " <<plecare1 <<"\nLa: " <<destinatie1 <<endl;
                    cout<<"Data: " <<d <<'/'<<m<<'/'<<y<<' '<<h<<':'<<mi<<endl;
                    cout<<c1 <<" Locuri disponibile "<<c12<< " cu pretul "  <<pret1 <<" fiecare\n";


                }
                k++;
            }
            if(!destinatie_gasita || !plecare_gasita) {

                cout<<"Nu exista curse intre " <<plecare <<" si " <<destinatie <<". Va rugam introduceti alta cursa.\n\n";
                cursedisponibile.clear();
                return cautare_cursa(cursedisponibile);
            }

            return k;
        }


};


class Operator {

    public:
        string username, parola;
        bool acces;
        Operator() {
            acces = 0;
        }

        void login() {
            cout<<"username: ";
            cin>>username;

            string user, pass;
            ifstream operatori;
            bool user_gasit = false;

            operatori.open("Operatori.csv");

            while(getline(operatori, user, ',')) {
                getline(operatori, pass);
                if(!user.compare(username)) {
                    user_gasit = true;
                    cout << "parola: ";
                    cin >> parola;
                    if(!pass.compare(parola)) {
                        cout << "Login reusit!\n\n";
                        return;
                    }
                    else {
                        cout << "Parola incorecta!\n\n";
                        login();
                    }
                }
            }
            if(!user_gasit) {
                cout << "Username-ul nu a fost gasit.\n\n";
                login();
            }
        }


};



class Client {

    public:
        string parola, username;
        bool acces;
        Client() {
            acces = 0;
        }

        void login() {
            cout<<"username: ";
            cin>>username;

            string user, pass;
            ifstream clienti;
            bool user_gasit = false;

            clienti.open("Clienti.csv");

            while(getline(clienti, user, ',')) {
                getline(clienti, pass);
                if(!user.compare(username)) {
                    user_gasit = true;
                    cout << "parola: ";
                    cin >> parola;
                    if(!pass.compare(RSA(parola))) {
                        cout << "Login reusit.\n\n";
                        return;
                    }
                    else {
                        cout << "Parola incorecta.\n\n";
                        login();
                    }
                }
            }
            if(!user_gasit) {
                cout << "Username-ul nu a fost gasit.\n\n";
                login();
            }
        }

        void inregistrare() {
            string line, pass, user, confirmare_parola;
            string s;
            bool user_gasit = false;

            ofstream clientioutput;
            ifstream clientiinput;
            clientiinput.open ("Clienti.csv");
            clientioutput.open ("Clienti.csv",ios::app);

            cout<<"Introduceti username-ul (email): ";
            cin>> username;

            bool rasp  = isValid(username);

            if (rasp) {
                while(getline(clientiinput, user, ',')) {
                    getline(clientiinput, pass);
                    if(!user.compare(username)) {
                        user_gasit = true;
                        cout << "Username-ul exista deja.\nIntroduceti alt username: ";
                        cin >> username;
                        clientiinput.clear();
                        clientiinput.seekg (0, ios::beg);
                    }
                }

                cout<<"Introduceti parola: ";
                cin>>parola;
                bool rasp1 = isValid1(parola);
                while(!rasp1)
                {
                    cout<<"Introduceti o alta parola: ";
                    cin>>parola;
                    rasp1 = isValid1(parola);
                }
                cout<<"Confirmati parola: ";
                cin>>confirmare_parola;

                while(parola != confirmare_parola) {

                    cout<<"\nParolele nu se potrivesc. Incercati din nou.\n";
                    cout<<"\nIntroduceti parola: ";
                    cin>>parola;
                     bool rasp1 = isValid1(parola);
                while(!rasp1)
                {
                    cout<<"Introduceti o alta parola: ";
                    cin>>parola;
                    rasp1 = isValid1(parola);
                }
                    cout<<"Confirmati parola: ";
                    cin>>confirmare_parola;
                }

                if(clientiinput.is_open())
                    clientioutput<<username<<','<<RSA(parola)<<endl;
                else

                clientiinput.close();
                clientioutput.close();

                cout<<"Inregistrarea s-a efectuat cu succes.\n";
            }
            else {
                cout<<"\nFolositi un format de email valid (exemplu@your.mail)\n\n";
                inregistrare();
            }
        }

        void rezervare(string user) {
            string username = user;
            vector<Autocar> cursedisponibile(100);
            Autocar cautare;
            int n = 0;
            int alegere;

            n = cautare.cautare_cursa(cursedisponibile);

            bool ok = false;
            while(!ok) {
                cout<<"Selectati cursa\n";
                cin>>alegere;
                alegere--;
                if(alegere > n-1) {
                    cout<<alegere+1 <<" Cursa selectata nu exista\n";
                }
                else {

                    ofstream rezervari;
                    rezervari.open("rezervari.csv", ios::app);
                    rezervari<<username<<','<<cursedisponibile[alegere].Id<<','<<cursedisponibile[alegere].plecare<<','<<cursedisponibile[alegere].destinatie<<','<<cursedisponibile[alegere].ziua<<','<<cursedisponibile[alegere].luna<<','<<cursedisponibile[alegere].an<<','<<cursedisponibile[alegere].ora<<','<<cursedisponibile[alegere].minute<<endl;
                    cout<<"Rezervarea s-a realizat cu succes.\n\n";
                    ok = true;
                }
            }

        }

};

void interfata();
void OperatorMenu();
int optiuneinvalida(int);
void ClientMenu();
void OperatorAfterLogin();
void ClientAfterLogin(string);

int optiuneinvalida(int opt) {
    int optiune;
    cout<<"\n     Va rugam introduceti o optiune corespunzatoare\n";
    cout<<"\nOptiune: ";
    cin>>optiune;
    return optiune;
}

void OperatorMenu() {

    int alegere;
    Operator operator1;
    Autocar autocar1;

    cout<<"\n      Operator\n\n";
    cout<<"     1 - Login                   \n     2 - Intoarcere la meniul principal     \n     3 - Iesire                    \n";
    cout<<"\nOption: ";
    cin>>alegere;

    while(alegere < 1 || alegere > 3) {
        alegere = optiuneinvalida(alegere);
    }

    switch (alegere) {
    case 1:
        cout << endl;
        operator1.login();
        OperatorAfterLogin();
        break;
    case 2:
        interfata();
        break;
    case 3:
        cout<<"Va mai asteptam!";
        return;
    default:
        cout << "Opțiune invalidă. Te rog să alegi din nou." << endl;
        break;
}

}

void ClientMenu() {

    int alegere;
    Client client1;
    Autocar autocar1, autocar2[100];
    string user;

    cout<<"\n     Client\n\n";
    cout<<"     1 - Login                   \n     2 - Inregistrare            \n     3 - Intoarcere la meniul principal     \n     4 - Iesire\n";
    cout<<"\nOptiune: ";
    cin>>alegere;

    while(alegere < 1 || alegere > 4) {
         alegere = optiuneinvalida(alegere);
    }

    switch (alegere) {
    case 1:
        cout << endl;
        client1.login();
        user = client1.username;
        ClientAfterLogin(user);
        break;
    case 2:
        cout << endl;
        client1.inregistrare();
        ClientMenu();
        break;
    case 3:
        interfata();
        break;
    case 4:
        cout<<"Va mai asteptam!";
        return;
    default:
        cout << "Opțiune invalidă. Te rog să alegi din nou." << endl;
        break;
}
}

void interfata() {

    int optiune;
    Client client1;

    cout<<"\n      Bine ati venit pe pagina noastra!    \n\n";
    cout<<"     1- Operator     \n     2 - Client      \n     3 - Iesire        \n";
    cout<<"\nOptiune: ";
    cin>>optiune;

    while(optiune < 0 || optiune > 3) {
        optiune = optiuneinvalida(optiune);
    }

    switch(optiune) {

        case 1:
            OperatorMenu();
            break;
        case 2:
            ClientMenu();
            break;
        case 3:
            cout<<"Va mai asteptam!";
            return;
    }
}

void OperatorAfterLogin() {

    Autocar autocar1;
    Operator operator1;
    int alegere;

        cout<<"\n   1 - Adaugati o cursa in baza de bate            \n   2 - Stergeti o cursa din baza de date       \n";
        cout<<"   3 - Intoarcere la meniul Operator     \n   4 - Iesire                             \n";
        cout<<"\nOptiune: ";
        cin>>alegere;

        while(alegere < 1 || alegere > 4) {
         alegere = optiuneinvalida(alegere);
    }

        switch (alegere) {
    case 1:
        cout << endl;
        autocar1.adaugare_cursa();
        OperatorAfterLogin();
        break;
    case 2:
        cout << endl;
        autocar1.stergere_cursa();
        OperatorAfterLogin();
        break;
    case 3:
        OperatorMenu();
        break;
    case 4:
        cout<<"Va mai asteptam!";
        return;
    default:
        cout << "Opțiune invalidă. Te rog să alegi din nou." << endl;
        break;
}

}

void ClientAfterLogin(string username) {
    string user  = username;
    int alegere;
    Autocar autocar1;
    vector<Autocar> autocar2(100);
    Client client1;

    cout<<"\n   1 - Cauta o cursa              \n   2 - Fa o rezervare          \n   3 - Intoarcere la meniul Client     \n   4 - Iesire\n";
        cout<<"\nOptiune: ";
        cin>>alegere;

        while(alegere < 1 || alegere > 4) {
         alegere = optiuneinvalida(alegere);
    }

        switch (alegere) {
    case 1:
        cout << endl;
        autocar1.cautare_cursa(autocar2);
        ClientAfterLogin(user);
        break;
    case 2:
        cout << endl;
        client1.rezervare(user);
        ClientAfterLogin(user);
        break;
    case 3:
        ClientMenu();
        break;
    case 4:
        cout<<"Va mai asteptam!";
        return;
    default:
        cout << "Opțiune invalidă. Te rog să alegi din nou." << endl;
        break;
}

}

int main() {
    interfata();
    return 0;

}
