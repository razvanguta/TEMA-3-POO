#include<iostream>
#include<string>
#include<set>
#include<vector>
#include <stdlib.h>
#include <typeinfo>
using namespace std;
class Automobil
{
protected:
    static int nrtotaut;//nr total de automobile
    string zona; //de oras, off-road, drum lung
    string dimensiune; //dimensiune masina (difera de la fiecare tip)
    int nrUsi; //numarul de usi de care dispune fiecare tip
    int nrpersoane; //numarul maxim de persoane care poate fi transportat
    float pret; //pretul fiecarui tip (euro)
public:
    Automobil(string zona = "", string dimensiune = "", float nrUsi = 0, int nrpersoane = 0, float pret = 0);
    friend bool operator<(const Automobil& a1, const Automobil& a2); //supraincarcam < ca fiind prietena pentru a putea accesa set din stl
    //deoarece acesta se foloseste de comparatii intre membrii pentru a stabili
    //o ierarhie, asa ca supraincarcam operator < pentru clasa Automobile
    virtual void citire(istream& in);
    virtual void afisare(ostream& out) const;
    static int getnraut()
    {
        return nrtotaut;
    }
    friend istream& operator>>(istream& in, Automobil& a);
    friend ostream& operator<<(ostream& out, const Automobil& a);
    virtual string getzona() const
    {
        return zona;
    }
    virtual string getdimensiune() const
    {
        return dimensiune;
    }
    virtual int getnrusi() const
    {
        return nrUsi;
    }
    virtual int getnrpersoane() const
    {
        return nrpersoane;
    }
    virtual float getpret() const
    {
        return pret;
    }
    virtual string type() const
    {
        return "Automobil";
    }
    virtual bool getstare()const
    {
        return 1;
    };
    ~Automobil()
    {
        nrtotaut--;
    }
};
int Automobil::nrtotaut = 0;
Automobil::Automobil(string zona, string dimensiune, float nrUsi, int nrpersoane, float pret) :zona(zona), dimensiune(dimensiune), nrUsi(nrUsi), nrpersoane(nrpersoane), pret(pret)
{
    nrtotaut++;
}
bool operator<(const Automobil& a1, const Automobil& a2)
{
    return(a1.getpret() < a2.getpret());
}
void Automobil::citire(istream& in)
{
    cout << "Zona recomandata pentru deplasare: ";
    in >> zona;
    cout << "Dimensiunea masinii: ";
    in >> dimensiune;
    cout << "Numar usi: ";
    in >> nrUsi;
    cout << "Numarul de persoane care pot fi transportate: ";
    in >> nrpersoane;
    cout << "Pret masina in euro: ";
    in >> pret;
}
void Automobil::afisare(ostream& out) const
{
    out << "Zona recomandata pentru deplasare: " << zona << '\n';
    out << "Dimensiunea masinii: " << dimensiune << '\n';
    out << "Numarul de usi: " << nrUsi << '\n';
    out << "Numarul de persoane care pot fi transportate: " << nrpersoane << '\n';
    out << "Pret masina in euro: " << pret << '\n';
}
istream& operator>>(istream& in, Automobil& a)
{
    a.citire(in);
    return in;
}
ostream& operator<<(ostream& out, const Automobil& a)
{
    a.afisare(out);
    return out;
}
///--------------------------------------------------------
class Mini : public Automobil
{
    const bool estesh = true;
public:
    Mini(string zona = "", string dimensiune = "", float nrUsi = 0, int nrpersoane = 0, float pret = 0);
    friend bool operator ==(Mini& m1, Mini& m2);
    Mini& operator=(Mini& m);
    void citire(istream& in);
    void afisare(ostream& out) const;
    bool getstare() const
    {
        return estesh;
    }
    string type()
    {
        return "Mini";
    }

    ~Mini() {}
};
Mini::Mini(string zona, string dimensiune, float nrUsi, int nrpersoane, float pret) :Automobil(zona, dimensiune, nrUsi, nrpersoane, pret)
{
}
bool operator ==(Mini& m1, Mini& m2)
{
    if (m1.zona == m2.zona && m1.dimensiune == m2.dimensiune && m1.nrUsi == m2.nrUsi && m1.nrpersoane == m2.nrpersoane && m1.pret == m2.pret)
        return true;
    else
        return false;
}
Mini& Mini:: operator=(Mini& m)
{
    zona = m.zona;
    dimensiune = m.dimensiune;
    nrUsi = m.nrUsi;
    nrpersoane = m.nrpersoane;
    pret = m.pret;
    return *this;
}
void Mini::citire(istream& in)
{
    Automobil::citire(in);
}
void Mini::afisare(ostream& out) const
{
    Automobil::afisare(out);
}
///--------------------------------------------------------
class Mica : public Automobil
{
    const bool estesh = 0;
public:
    Mica(string zona = "", string dimensiune = "", float nrUsi = 0, int nrpersoane = 0, float pret = 0);
    friend bool operator ==(Mica& m1, Mica& m2);
    Mica& operator=(Mica& m);
    void citire(istream& in);
    void afisare(ostream& out) const;
    bool getstare() const
    {
        return estesh;
    }
    string type()
    {
        return "Mica";
    }
    ~Mica() {}
};
Mica::Mica(string zona, string dimensiune, float nrUsi, int nrpersoane, float pret) :Automobil(zona, dimensiune, nrUsi, nrpersoane, pret)
{
}
bool operator ==(Mica& m1, Mica& m2)
{
    if (m1.zona == m2.zona && m1.dimensiune == m2.dimensiune && m1.nrUsi == m2.nrUsi && m1.nrpersoane == m2.nrpersoane && m1.pret == m2.pret)
        return true;
    else
        return false;
}
Mica& Mica:: operator=(Mica& m)
{
    zona = m.zona;
    dimensiune = m.dimensiune;
    nrUsi = m.nrUsi;
    nrpersoane = m.nrpersoane;
    pret = m.pret;
    return *this;
}
void Mica::citire(istream& in)
{
    Automobil::citire(in);
}
void Mica::afisare(ostream& out) const
{
    Automobil::afisare(out);
}
///---------------------------------------------------------
class Compacta : public Automobil
{
    const bool estesh = 0;
    string model; // hatchback, combi sau sedan
public:
    Compacta(string model = "", string zona = "", string dimensiune = "", float nrUsi = 0, int nrpersoane = 0, float pret = 0);
    friend bool operator ==(Compacta& m1, Compacta& m2);
    Compacta& operator=(Compacta& c);
    void citire(istream& in);
    bool getstare() const
    {
        return estesh;
    }
    string getmodel() const
    {
        return model;
    }
    void afisare(ostream& out) const;
    string type()
    {
        return "Compacta";
    }
    ~Compacta() {}
};
Compacta::Compacta(string model, string zona, string dimensiune, float nrUsi, int nrpersoane, float pret) :Automobil(zona, dimensiune, nrUsi, nrpersoane, pret), model(model)
{
}
bool operator ==(Compacta& m1, Compacta& m2)
{
    if (m1.model == m2.model && m1.zona == m2.zona && m1.dimensiune == m2.dimensiune && m1.nrUsi == m2.nrUsi && m1.nrpersoane == m2.nrpersoane && m1.pret == m2.pret)
        return true;
    else
        return false;
}
Compacta& Compacta:: operator=(Compacta& c)
{
    zona = c.zona;
    dimensiune = c.dimensiune;
    nrUsi = c.nrUsi;
    nrpersoane = c.nrpersoane;
    pret = c.pret;
    model = c.model;
    return *this;
}
void Compacta::citire(istream& in)
{
    Automobil::citire(in);
    cout << "Model: ";
    in >> model;

}
void Compacta::afisare(ostream& out) const
{
    Automobil::afisare(out);
    cout << "Model: ";
    out << model << '\n';
}
///--------------------------------------------------------
class Monovolum : public Automobil
{
    vector <pair<int, int> > ziluna; //retinem ziua si luna din vara in care sunt prevazute promotii
    int nrziluna;
    int anfabricat; //anul in care masina a fost fabricata
    int anachizitie; //anul in care masina este (re)achizitionata
    int ziactuala; //ziua in care masina este (re)achizitionata
    int lunaactuala;//luna  in care masina este (re)achizitionata
    bool estesh;
public:
    Monovolum(int anfabricat = 0, int anachizitie = 0, int ziactuala = 0, int lunaactuala = 0, bool estesh = true, string zona = "", string dimensiune = "", float nrUsi = 0, int nrpersoane = 0, float pret = 0);
    friend bool operator ==(Monovolum& m1, Monovolum& m2);
    Monovolum& operator=(Monovolum& m);
    void citire(istream& in);
    void afisare(ostream& out) const;
    string type()
    {
        return "Monovolum";
    }
    bool getstare()const
    {
        return estesh;
    }
    ~Monovolum() {}
};
Monovolum::Monovolum(int anfabricat, int anachizitie, int ziactuala, int lunaactuala, bool estesh, string zona, string dimensiune, float nrUsi, int nrpersoane, float pret) :Automobil(zona, dimensiune, nrUsi, nrpersoane, pret), anfabricat(anfabricat), anachizitie(anachizitie), lunaactuala(lunaactuala), ziactuala(ziactuala), estesh(estesh)
{
}
bool operator ==(Monovolum& m1, Monovolum& m2)
{
    if (m1.anfabricat == m2.anfabricat && m1.zona == m2.zona && m1.dimensiune == m2.dimensiune && m1.nrUsi == m2.nrUsi && m1.nrpersoane == m2.nrpersoane && m1.pret == m2.pret)
        return true;
    else
        return false;
}
Monovolum& Monovolum:: operator=(Monovolum& m)
{
    zona = m.zona;
    dimensiune = m.dimensiune;
    nrUsi = m.nrUsi;
    nrpersoane = m.nrpersoane;
    pret = m.pret;
    nrziluna = m.nrziluna;
    anfabricat = m.anfabricat;
    anachizitie = m.anachizitie;
    ziactuala = m.ziactuala;
    lunaactuala = m.lunaactuala;
    estesh = m.estesh;
    for (int i = 0; i < ziluna.size(); i++)
    {
        ziluna[i] = m.ziluna[i];
    }
    return *this;
}
void Monovolum::citire(istream& in)
{
    Automobil::citire(in);
    cout << "Zilele si luniile din vara in care se afla reducerea(Cate zile si luni apoi acelea): ";
    in >> nrziluna;
    int zi, luna;
    for (int i = 0; i < nrziluna; i++)
    {
        try
        {
            in >> zi >> luna;
            if (luna < 6 || luna>8)
                throw 1;
            else if (luna == 6 && (zi > 30 || zi < 1) || luna == 7 && (zi > 31 || zi < 1) || luna == 8 && (zi > 31 || zi < 1))
                throw 1;
        }
        catch (int x)
        {
            cout << "Data nu a fost corect introdusa\n";
            exit(EXIT_FAILURE);
        }
        ziluna.push_back(make_pair(zi, luna));
    }
    cout << "Anul fabricatiei masinii: ";
    in >> anfabricat;
    cout << "Anul in care vrem sa achizitionam: ";
    in >> anachizitie;
    cout << "Ziua in care vrem sa achizitionam: ";
    in >> ziactuala;
    cout << "Luna in care vrem sa achizitionam: ";
    in >> lunaactuala;
    cout << "Este masina second hand (apasati 1 daca da/apasati 0 daca nu): ";
    try {
        int aux;
        in >> aux;
        if (aux == 1)
            estesh = true;
        else if (aux == 0)
            estesh = false;
        else throw false;
    }
    catch (bool x)
    {
        cout << "INTRODU 1/0";
        exit(EXIT_FAILURE);
    }
    if (estesh == true)
    {
        int reducerezilevara = 0;
        for (int i = 0; i < ziluna.size(); i++)
        {
            if (ziluna[i].first == ziactuala && ziluna[i].second == lunaactuala)
                reducerezilevara = 0.1 * pret;
        }
        //din pretul total scadem atat reducerea pentru zileledevara daca exista cat si pentru vechime
        pret = pret - double(double(double(anachizitie - anfabricat) / 100) * pret) - reducerezilevara; //reducere in functie nr de ani vechime,
        // de ex pentru un model vechi de 5 ani se prevede reducere de 5%
    }
}
void Monovolum::afisare(ostream& out) const
{
    out << "Zona recomandata pentru deplasare: " << zona << '\n';
    out << "Dimensiunea masinii: " << dimensiune << '\n';
    out << "Numarul de usi: " << nrUsi << '\n';
    out << "Numarul de persoane care pot fi transportate: " << nrpersoane << '\n';
    out << "Pretul in euro dupa aplicarea eventualelor reduceri (vechime, anumita data din vara): " << pret << '\n';
    out << "Anul in care a fost fabricata masina: " << anfabricat << '\n';
}
///-------------------------------------------------
template <class T>
class Vanzare
{
    T* stoc;
    T* vandute;
    int nrstoc;
    int nrvand;
public:
    Vanzare();
    void addmasina(T& c);
    int getmasini()
    {
        return nrstoc;
    }
    int getvandut()
    {
        return nrvand;
    }
    T& operator -=(T& c);
    void afismasini();
    void afisvand();
    ~Vanzare();
};
template<class T>
Vanzare<T>::Vanzare()
{
    nrstoc = 0;
    nrvand = 0;
    try
    {
        stoc = new T[1001];
        vandute = new T[1001];
    }
    catch (bad_alloc x)
    {
        cout << "Alocation failure\n";
    }
}
template <class T>
T& Vanzare<T>:: operator-=(T& c)
{
    try
    {
        if (nrstoc == 0)
            throw false;
        bool ok = false;
        int poz;
        for (int i = 0; i < nrstoc; i++)
            if (stoc[i] == c)
                ok = true, poz = i;
        if (ok == false)
            throw false;
        vandute[nrvand++] = stoc[poz];
        if (ok == true)
        {
            for (int i = poz; i < nrstoc; i++)
                stoc[i] = stoc[i + 1];
            nrstoc--;
        }
    }
    catch (bool x)
    {
        cout << "NU EXISTA O MASINA " << c.type() << " CU ACESTE CARACTERISTICI INTRODUSE\n";
    }
}
template<class T>
void Vanzare<T>::addmasina(T& c)
{
    stoc[nrstoc++] = c;
}
template<class T>
void Vanzare<T>::afismasini()
{
    if (nrstoc == 0)
    {
        cout << "NU EXISTA MASINI IN STOC\n\n";
        return;
    }
    for (int i = 0; i < nrstoc; i++)
        cout << stoc[i] << endl;
}
template<class T>
void Vanzare<T>::afisvand()
{
    if (nrvand == 0)
    {
        cout << "NU EXISTA MASINI VANDUTE\n\n";
        return;
    }
    for (int i = 0; i < nrvand; i++)
        cout << vandute[i] << endl;
}
template <class T>
Vanzare<T>::~Vanzare()
{
    delete[] stoc;
    delete[] vandute;
}
///----------------------------
template<>
class Vanzare<Monovolum>
{
    Monovolum* stoc;
    Monovolum* vandute;
    int nrstoc;
    int nrvand;
    int nrsh;
public:
    Vanzare();
    void addmasina(Monovolum& c);
    int getmasini()
    {
        return nrstoc;
    }
    int getvandut()
    {
        return nrvand;
    }
    int getnrsh()
    {
        return nrsh;
    }
    Monovolum& operator -=(Monovolum& c);
    void afismasini();
    void afisvand();
    ~Vanzare();

};
Vanzare<Monovolum>::Vanzare()
{
    nrstoc = 0;
    nrvand = 0;
    nrsh = 0;
    try
    {
        stoc = new Monovolum[1001];
        vandute = new Monovolum[1001];
    }
    catch (bad_alloc x)
    {
        cout << "Alocation failure\n";
    }
}
Monovolum& Vanzare<Monovolum>:: operator-=(Monovolum& c)
{
    try
    {
        if (nrstoc == 0)
            throw false;
        bool ok = false;
        int poz;
        for (int i = 0; i < nrstoc; i++)
            if (stoc[i] == c)
                ok = true, poz = i;
        if (ok == false)
            throw false;
        if (stoc[poz].getstare() == true)
            nrsh--;
        vandute[nrvand++] = stoc[poz];
        if (ok == true)
        {
            for (int i = poz; i < nrstoc; i++)
                stoc[i] = stoc[i + 1];
            nrstoc--;
        }
        else
            throw false;
    }
    catch (bool x)
    {
        cout << "NU EXISTA O MASINA " << c.type() << " CU ACESTE CARACTERISTICI INTRODUSE\n";
    }
}
void Vanzare<Monovolum>::addmasina(Monovolum& c)
{
    stoc[nrstoc++] = c;
    if (c.getstare() == true)
        nrsh++;
}
void Vanzare<Monovolum>::afismasini()
{
    if (nrstoc == 0)
    {
        cout << "NU EXISTA MASINI IN STOC\n\n";
        return;
    }
    for (int i = 0; i < nrstoc; i++)
        cout << stoc[i] << endl;
}
void Vanzare<Monovolum>::afisvand()
{
    if (nrvand == 0)
    {
        cout << "NU EXISTA MASINI VANDUTE\n\n";
        return;
    }
    for (int i = 0; i < nrvand; i++)
        cout << vandute[i] << endl;
}
Vanzare<Monovolum>::~Vanzare()
{
    delete[] stoc;
    delete[] vandute;
}
int main()
{
    ///citirea a n obiecte folosindu-ne de structura din enunt.
    cout << "CITIREA A N OBIECTE FOLOSINDU-NE DE STRUCTURA DIN ENUNT SI AFISAREA LOR\n";
    set<pair<Automobil*, bool> > stoc;
    Automobil** v;
    int n;
    cout << "Numarul de obiecte: ";
    cin >> n;
    v = new Automobil * [n];
    for (int i = 0; i < n; i++)
    {
        string tip;
        cout << "Tipul autoturismului " << i + 1 << ": ";
        cin >> tip;
        try {
            if (tip == "Mini")
            {
                v[i] = new Mini;
                cin >> *v[i];
                stoc.insert(make_pair(v[i], false));
            }
            else if (tip == "Mica")
            {
                v[i] = new Mica;
                cin >> *v[i];
                stoc.insert(make_pair(v[i], false));
            }
            else if (tip == "Compacta")
            {
                v[i] = new Compacta;
                cin >> *v[i];
                stoc.insert(make_pair(v[i], false));
            }
            else if (tip == "Monovolum")
            {
                v[i] = new Monovolum;
                cin >> *v[i];
                stoc.insert(make_pair(v[i], (*v[i]).getstare()));
            }
            else
                throw false;

        }
        catch (bad_alloc x)
        {
            cout << "Alocation Failure\n";
            exit(EXIT_FAILURE);
        }
        catch (bool x)
        {
            cout << "Incearca sa introduci un tip valid(Mini,Mica,Compacta,Monovolum)\n";
            exit(EXIT_FAILURE);
        }
    }
    cout << endl << "AFISARE:\n";
    set<pair<Automobil*, bool> >::iterator it;
    for (it = stoc.begin(); it != stoc.end(); it++)
    {
        cout << *(*it).first;
        if ((*it).second == true)
            cout << "Masina este second hand" << '\n' << '\n';
        else
            cout << "Masina este noua" << '\n' << '\n';
    }



    /// MENIU GESTIONARE STOC MASINI
    cout << "---------------------------------------\n";
    cout << "Gestionarea stocului de masini\n";
    int op = INT_MAX;
    Vanzare<Mini> stocMini;
    Vanzare<Mica> stocMica;
    Vanzare<Compacta> stocCompacta;
    Vanzare<Monovolum> stocMonovolum;
    cout << "Alege operatiuniile dorite din meniul de mai jos\n\n";
    cout << "1: Adauga in stoc o masina de tipul Mini\n";
    cout << "2: Adauga in stoc o masina de tipul Mica\n";
    cout << "3: Adauga in stoc o masina de tipul Compacta\n";
    cout << "4: Adauga in stoc o masina de tipul Monovolum\n";
    cout << "5: Vinde o masina din stoc de tipul Mini\n";
    cout << "6: Vinde o masina din stoc de tipul Mica\n";
    cout << "7: Vinde o masina din stoc de tipul Compacta\n";
    cout << "8: Vinde o masina din stoc de tipul Monovolum\n";
    cout << "9: Vezi numarul de masini din stoc pe fiecare categorie in parte\n";
    cout << "10: Vezi masiniile din stoc pe fiecare categorie in parte\n";
    cout << "11: Vezi numarul de masini vandute pe fiecare categorie in parte\n";
    cout << "12: Vezi masiniile vandute pe fiecare categorie in parte\n";
    cout << "13: Cate masini din stoc sunt noi sau second hand(DOAR PENTRU MONOVOLUME)\n";
    cout << "0: STOP\n";
    while (true)
    {
        try
        {
            cout << "\nOperatiunea: ";
            cin >> op;
            if (op == 0)
                break;
            if (op == 1)
            {
                Mini newMini;
                cin >> newMini;
                stocMini.addmasina(newMini);
            }
            else if (op == 2)
            {
                Mica newMica;
                cin >> newMica;
                stocMica.addmasina(newMica);
            }
            else if (op == 3)
            {
                Compacta newCompacta;
                cin >> newCompacta;
                stocCompacta.addmasina(newCompacta);
            }
            else if (op == 4)
            {
                Monovolum newMonovolum;
                cin >> newMonovolum;
                stocMonovolum.addmasina(newMonovolum);
            }
            else if (op == 5)
            {
                cout << "Introdu caracteristiciile masinii Mini pe care vrei sa o cumperi\n";
                Mini cumpMini;
                cin >> cumpMini;
                stocMini -= cumpMini;
            }
            else if (op == 6)
            {
                cout << "Introdu caracteristiciile masinii Mici pe care vrei sa o cumperi\n";
                Mica cumpMica;
                cin >> cumpMica;
                stocMica -= cumpMica;
            }
            else if (op == 7)
            {
                cout << "Introdu caracteristiciile masinii Compacte pe care vrei sa o cumperi\n";
                Compacta cumpCompacta;
                cin >> cumpCompacta;
                stocCompacta -= cumpCompacta;
            }
            else if (op == 8)
            {
                cout << "Introdu caracteristiciile masinii Monovolum pe care vrei sa o cumperi\n";
                Monovolum cumpMonovolum;
                cin >> cumpMonovolum;
                stocMonovolum -= cumpMonovolum;
            }
            else if (op == 9)
            {
                cout << "In stoc se afla " << stocMini.getmasini() << " masini mini\n";
                cout << "In stoc se afla " << stocMica.getmasini() << " masini mici\n";
                cout << "In stoc se afla " << stocCompacta.getmasini() << " masini Compacte\n";
                cout << "In stoc se afla " << stocMonovolum.getmasini() << " masini Monovolume\n";
                cout << "In total se afla " << stocMini.getmasini() + stocMica.getmasini() + stocCompacta.getmasini() + stocMonovolum.getmasini() << " masini in stoc\n";
            }
            else if (op == 10)
            {
                cout << "Masiniile mini din stoc:\n";
                stocMini.afismasini();
                cout << "Masiniile mici din stoc:\n";
                stocMica.afismasini();
                cout << "Masiniile compacte din stoc:\n";
                stocCompacta.afismasini();
                cout << "Masiniile monovolum din stoc:\n";
                stocMonovolum.afismasini();
            }
            else if (op == 11)
            {
                cout << "S-au vandut " << stocMini.getvandut() << " masini mini\n";
                cout << "S-au vandut " << stocMica.getvandut() << " masini mici\n";
                cout << "S-au vandut " << stocCompacta.getvandut() << " masini Compacte\n";
                cout << "S-au vandut " << stocMonovolum.getvandut() << " masini Monovolum\n";
                cout << "In total se afla " << stocMini.getvandut() + stocMica.getvandut() + stocCompacta.getvandut() + stocMonovolum.getvandut() << " masini vandute\n";
            }
            else if (op == 12)
            {
                cout << "Masiniile mini vandute:\n";
                stocMini.afisvand();
                cout << "Masiniile mici vandute:\n";
                stocMica.afisvand();
                cout << "Masiniile compacte vandute:\n";
                stocCompacta.afisvand();
                cout << "Masiniile compacte vandute:\n";
                stocMonovolum.afisvand();
            }
            else if (op == 13)
            {
                cout << "In stoc sunt " << stocMonovolum.getmasini() - stocMonovolum.getnrsh() << " Monovolume noi\n";
                cout << "In stoc sunt " << stocMonovolum.getnrsh() << " Monovolume second hand\n";
            }
            else throw false;
        }
        catch (bool x)
        {
            cout << "Introdu o operatiune valida\n";
        }
    }

    return 0;
}
