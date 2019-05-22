#include <iostream>
#include "GRAPH.h"
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;


istream& operator >>(istream& in, Cursuri &c)
{
    delete []c.curs;
    in >> c.nr_note;
    c.curs = new int[c.nr_note];
    for (int i = 0; i < c.nr_note; i++)
        in >> c.curs[i];
    return in;

}

ostream& operator <<(ostream& out, const Cursuri &c)
{
    for (int i = 0; i < c.nr_note; i++)
        out << c.curs[i] << " ";
    out << "\n";
    return out;
}
void Cursuri::calcu_media()
{
    for (int i = 0; i < nr_note; i++)
        media_notelor += curs[i];
    media_notelor = media_notelor / nr_note;
}

Cursuri& Cursuri:: operator=(const Cursuri &curss)
{
     if (this == &curss)
        return *this;
    media_notelor = curss.media_notelor;
    nr_note = curss.nr_note;
    evaluare_sc_oral = curss.evaluare_sc_oral;
    delete[] curs;
    curs = new int[nr_note];
    for (int i = 0; i < nr_note; i++)
    {
        curs[i] =curss.curs[i];
    }
    return (*this);
}

///
istream& operator >>(istream& in, Matematica &m)
{
    m.free_curs();
    int mm;
    cout << "[Matematica - "<< m.ce_fel << "]\nCate teste ati dat la aceasta materie?\n"; in >> mm;
    m.set_nr_note(mm);
    m.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {in >> nota; m.add_nota_la_poz(nota, i);}
        cout <<"\nIntroduceti nota obtinuta la evaluarea scrisa/orala:\n";
    in >> nota;
    m.set_nota_oral_sau_scris(nota);
    m.set_evaluare_sc_oral_curs(m.retur_nota_orala());
    return in;
}
ostream& operator <<(ostream& out, const Matematica &m)
{
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < m.return_nr_note(); i++)
            {   int mmm;
                mmm = m.return_nota_la_poz(i);
                out << mmm << " ";
            }
    out << "\nNota la evaluarea scrisa/orala: " << m.evaluare_scrisa << "\n";

    return out;
}

///

ostream& operator <<(ostream& out, const Programare &p)
{
    cout << "\nNotele obtinute sunt: ";
        for (int i = 0; i < p.return_nr_note(); i++)
            {   int mmm;
                mmm = p.return_nota_la_poz(i);
                out << mmm << " ";
            }
    out << "\nNota la evaluarea scrisa/orala: " << p.evaluare_scrisa << "\n";
    return out;
}

istream& operator >>(istream& in, Programare &m)
{
    m.free_curs();
    int mm;
    cout << "[Programare - "<< m.ce_fel << "]\nCate teste ati dat la aceasta materie?\n"; in >> mm;;
    m.set_nr_note(mm);
    m.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {in >> nota; m.add_nota_la_poz(nota, i);}
        cout <<"\nIntroduceti nota obtinuta la evaluarea scrisa/orala:\n";
    in >> nota;
    m.set_nota_oral_sau_scris(nota);
    m.set_evaluare_sc_oral_curs(m.retur_nota_orala());
    return in;
}

///

istream& operator >>(istream& in, Comunicare_NLP &co)
{
    co.free_curs();
    int mm;
    cout << "[Comunicare NLP]\nCate teste ati dat la aceasta materie?\n";in >> mm;
    co.set_nr_note(mm);
    co.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {in >> nota; co.add_nota_la_poz(nota, i);}
        cout <<"\nIntroduceti nota obtinuta la evaluarea scrisa/orala:\n";
    in >> nota;
    co.set_nota_oral_sau_scris(nota);
    co.set_evaluare_sc_oral_curs(co.retur_nota_orala());
    return in;
}

ostream& operator <<(ostream& out, const Comunicare_NLP &co)
{
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < co.return_nr_note(); i++)
            {   int mmm;
                mmm = co.return_nota_la_poz(i);
                out << mmm << " ";
            }
    out << "\nNota la evaluarea scrisa/orala: " << co.evaluare_scrisa << "\n";
    return out;

}

///

istream& operator >>(istream& in, Limba_straina &m)
{
    m.free_curs();
    int mm;
    cout << "[Limba - "<< m.ce_fel <<"]\nCate teste ati dat la aceasta materie?\n"; in >> mm;
    m.set_nr_note(mm);
    m.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {
            in >> nota; m.add_nota_la_poz(nota, i);
        }
    return in;
}
ostream& operator <<(ostream& out, const Limba_straina &m)
{
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < m.return_nr_note(); i++)
            {   int mmm;
                mmm = m.return_nota_la_poz(i);
                out << mmm << " ";
            }
    return out;
}

///

istream& operator >>(istream& in, Resurse_Umane &m)
{
    m.free_curs();
    int mm;
    cout << "[Resurse Umane]\nCate teste ati dat la aceasta materie?\n"; in >> mm;
    m.set_nr_note(mm);
    m.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {
            in >> nota; m.add_nota_la_poz(nota, i);
        }
    return in;
}
ostream& operator <<(ostream& out, const Resurse_Umane &m)
{
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < m.return_nr_note(); i++)
            {   int mmm;
                mmm = m.return_nota_la_poz(i);
                out << mmm << " ";
            }
    return out;
}
///

istream& operator >>(istream& in, Financiar &m)
{
    m.free_curs();
    int mm;
    cout << "[Financiar]\nCate teste ati dat la aceasta materie?\n"; in >> mm;
    m.set_nr_note(mm);
    m.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {
            in >> nota; m.add_nota_la_poz(nota, i);
        }
    return in;
}
ostream& operator <<(ostream& out, const Financiar &m)
{
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < m.return_nr_note(); i++)
            {   int mmm;
                mmm = m.return_nota_la_poz(i);
                out << mmm << " ";
            }
    return out;
}
///

istream& operator >>(istream& in, Legislatie_auto &m)
{
    m.free_curs();
    int mm;
    cout << "[Legislatie auto]\nCate teste ati dat la aceasta materie?\n"; in >> mm;
    m.set_nr_note(mm);
    m.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {
            in >> nota; m.add_nota_la_poz(nota, i);
        }
    return in;
}
ostream& operator <<(ostream& out, const Legislatie_auto &m)
{
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < m.return_nr_note(); i++)
            {   int mmm;
                mmm = m.return_nota_la_poz(i);
                out << mmm << " ";
            }
    return out;
}
///

istream& operator >>(istream& in, Sofat_auto_practic &m)
{
    m.free_curs();
    int mm;
    cout << "[Sofat auto practic]\nCate teste ati dat la aceasta materie?\n"; in >> mm;
    m.set_nr_note(mm);
    m.realoc_curs(mm);
    int nota;
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < mm; i++)
        {
            in >> nota; m.add_nota_la_poz(nota, i);
        }
    return in;
}
ostream& operator <<(ostream& out, const Sofat_auto_practic &m)
{
    cout << "\nNotele obtinute sunt: ";
    for (int i = 0; i < m.return_nr_note(); i++)
            {   int mmm;
                mmm = m.return_nota_la_poz(i);
                out << mmm << " ";
            }
    return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator >>(istream& in, FINANTIST &f)
{
    f.mat.set_ce_fel("ALGEBRA");
    f.set_nota_program(0);
    in >> f.mat;
    in >> f.fin;
    return in;
}

ostream& operator <<(ostream& out, const FINANTIST &f)
{
    out << f.mat;
    out << f.fin;
    return out;
}
///

istream& operator >>(istream& in, MANAGER &f)
{
    f.set_nota_program(0);
    f.limba.set_ce_fel("ENGLEZA");
    in >> f.res_uman;
    in >> f.fin;
    in >> f.limba;
    return in;
}

ostream& operator <<(ostream& out, const MANAGER &f)
{
    out << f.res_uman;
    out << f.fin;
    out << f.limba;
    return out;
}
///

istream& operator >>(istream& in, PROGRAMATOR &f)
{
    f.set_nota_program(0);
    f.algebra.set_ce_fel("ALGEBRA");
    f.analiza.set_ce_fel("ANALIZA");
    f.geometrie.set_ce_fel("GEOMETRIE");
    f.prog.set_ce_fel("OOP C++");
    f.limba.set_ce_fel("ENGLEZA");
    in >> f.algebra;
    in >> f.analiza;
    in >> f.geometrie;
    in >> f.prog;
    in >> f.limba;
    return in;
}

ostream& operator <<(ostream& out, const PROGRAMATOR &f)
{
    out << f.algebra;
    out << f.analiza;
    out << f.geometrie;
    out << f.prog;
    out << f.limba;
    return out;
}
///

istream& operator >>(istream& in, PROGRAMATORI &pro)
{
    pro.set_nota_program(0);
    pro.prog.set_ce_fel("BAZE DE DATE");
    in >> pro.manager;
    in >> pro.prog;
    in >> pro.nlp;
    return in;
}

ostream& operator <<(ostream& out, const PROGRAMATORI &p)
{
    out << p.manager;
    out << p.prog;
    out << p.nlp;
    return out;
}
///

istream& operator >>(istream& in, SOFER &s)
{
    s.set_nota_program(0);
    in >> s.leg_auto;
    in >> s.sofa;
    return in;
}

ostream& operator <<(ostream& out, const SOFER &s)
{
    out << s.leg_auto;
    out << s.sofa;
    return out;
}
///

istream& operator >>(istream& in, MANAGER_ECHIPA_TIRI &m)
{
    m.set_nota_program(0);
    m.turca.set_ce_fel("TURCA");
    in >> m.turca;
    in >> m.manager;
    in >> m.leg_auto;
    return in;
}

ostream& operator <<(ostream& out, const MANAGER_ECHIPA_TIRI &m)
{
    out << m.turca;
    out << m.manager;
    out << m.leg_auto;
    return out;
}

///
Programe:: Programe(int ce_program)
{
    if (ce_program == 1){ this-> nr_de_cursuri = 2;}//finantit
    if (ce_program == 2){ this-> nr_de_cursuri = 3;}//manager
    if (ce_program == 3){ this-> nr_de_cursuri = 5;}//programator
    if (ce_program == 4){ this-> nr_de_cursuri = 3;}//programatoriii
    if (ce_program == 5){ this-> nr_de_cursuri = 2;}//sofer
    if (ce_program == 6){ this-> nr_de_cursuri = 3;}//manager tiristi
}


istream& operator >>(istream& in, Fisa_Evaluare &fisa)
{
    char nu[15], pre[15];
    int nr_program;
    std::cout << "Introduceti numele si primul/unicul prenume!!!! \n"; in >> nu >> pre; fisa.set_nume_prenume(nu,pre);system("CLS");
    cout << "1: FINANTIST\n2: MANAGER\n3: PROGRAMATOR\n4: MANAGER ECHIPA DE PROGRAMATORI\n5: SOFER\n6: MANAGER ECHIPA DE TIRISTI\n\n";
    std::cout << "Alegeti numarul programului: \n"; in >> nr_program; fisa.set_ce_program(nr_program);system("CLS");
//    if (fisa.return_ce_program() == 1)
//    {
//        fisa.set_ce_program_char("FINANTIST");
//        //cout << fisa.return_nume_program() << "\n";
//        in >> fisa.finantist;
//    }
string nivel;
    switch(fisa.return_ce_program())
    {
    case 1:
        fisa.set_ce_program_char("FINANTIST");
        in >> fisa.finantist;
        fisa.finantist.calculeaza_nota();
        fisa.finantist.calcu_competenta();
        nivel = fisa.finantist.return_nivel();
        fisa.set_ce_competenta(nivel);
        fisa.set_ce_medie(fisa.finantist.return_nota_program());
        break;
    case 2:
        fisa.set_ce_program_char("MANAGER");
        in >> fisa.manager;
        fisa.manager.calculeaza_nota();
        fisa.manager.calcu_competenta();
        fisa.set_ce_competenta(fisa.manager.return_nivel());
        fisa.set_ce_medie(fisa.manager.return_nota_program());
        break;
    case 3:
        fisa.set_ce_program_char("PROGRAMATOR");
        in >> fisa.programator;
        fisa.programator.calculeaza_nota();
        fisa.programator.calcu_competenta();
        fisa.set_ce_competenta(fisa.programator.return_nivel());
        fisa.set_ce_medie(fisa.programator.return_nota_program());
        break;
    case 4:
        fisa.set_ce_program_char("MANAGER_ECHIPA_PROGRAMATORI");
        in >> fisa.programatori;
        fisa.programatori.calculeaza_nota();
        fisa.programatori.calcu_competenta();
        fisa.set_ce_competenta(fisa.programatori.return_nivel());
        fisa.set_ce_medie(fisa.programatori.return_nota_program());
        break;
    case 5:
        fisa.set_ce_program_char("SOFER");
        in >> fisa.sofer;
        fisa.sofer.calculeaza_nota();
        fisa.sofer.calcu_competenta();
        fisa.set_ce_competenta(fisa.sofer.return_nivel());
        fisa.set_ce_medie(fisa.sofer.return_nota_program());
        break;
    case 6:
        fisa.set_ce_program_char("MANAGER_ECHIPA_DE_TIRISTI");
        in >> fisa.manager_tiristi;
        fisa.manager_tiristi.calculeaza_nota();
        fisa.manager_tiristi.calcu_competenta();
        fisa.set_ce_competenta(fisa.manager_tiristi.return_nivel());
        fisa.set_ce_medie(fisa.manager_tiristi.return_nota_program());
        break;
    }
    return in;
}

int Statistica[7][4];
void add_in_statistica(int i, int j)
{
    Statistica[i][j]++;
}

void afisare(double nr)
{
    if (nr >= 5 && nr < 6)
        cout << "MIC";
    if (nr >= 6 && nr < 8)
        cout << "MEDIU";
    if (nr >= 8)
        cout << "MARE";
    if (nr < 5)
        cout << "PICAT";

}

int main()
{
    int n;

    cout << "Introduceti numarul de cursanti: \n"; cin >> n;
    system("CLS");
//    Fisa_Evaluare cur;
//    cin >> cur;

    Fisa_Evaluare *cursanti = new Fisa_Evaluare[n];
    for (int i = 0; i < n; i++)
    {   int poz;
        cin >> cursanti[i];
        cursanti[i].afisare_nume_prenume();
        cout << " -> MEDIA NOTELOR: " << cursanti[i].return_ce_medie() << "     COMPETENTA: " << cursanti[i].return_ce_competenta() << "\n";
        if (cursanti[i].return_ce_medie() < 5)
        {
            cout << "\n\n     ATI PICAT! :(\n\n Doriti sa refaceti acest PROGRAM?\n 1: DA        2:NU\n"; int m; cin >> m; system("CLS");
            if (m == 1)
            { cout <<"Reintroduceti datele noi obtinute:\n";
                cin >> cursanti[i];
                cursanti[i].afisare_nume_prenume();
                cout << " -> MEDIA NOTELOR: " << cursanti[i].return_ce_medie() << "     COMPETENTA: " << cursanti[i].return_ce_competenta() << "\n";
            }
        }
        else
        {
            cout <<"\n\n     BRAVOOO!\n\n";
        }
        double not_prog = cursanti[i].return_ce_medie();
        if (not_prog >= 5 && not_prog <= 6)
            poz = 1;
        if (not_prog > 6 && not_prog <=8)
            poz = 2;
        if (not_prog > 8 && not_prog <= 10)
            poz = 3;
        if (cursanti[i].return_ce_medie() >= 5)
            {add_in_statistica(cursanti[i].return_ce_program(), poz);
            if (cursanti[i].return_ce_program() == 4 || cursanti[i].return_ce_program() == 6)
                {
                    if (cursanti[i].return_nota_la_manager() >= 5 && cursanti[i].return_nota_la_manager() <= 6)
                        poz = 1;
                    if (cursanti[i].return_nota_la_manager() > 6 && cursanti[i].return_nota_la_manager() <= 8)
                        poz = 2;
                    if (cursanti[i].return_nota_la_manager() > 8 && cursanti[i].return_nota_la_manager() <= 10)
                        poz = 3;
                        cursanti[i].afisare_nume_prenume();
                        cout << " -> MEDIA NOTELOR: " << cursanti[i].return_nota_la_manager() << "     COMPETENTA: "; afisare(cursanti[i].return_nota_la_manager()); cout << "\n";
                    add_in_statistica(2, poz);
                }
            }
        cout <<"1: NEXT         2: EXIT           3:SHOW STATISTIC\n";
        int nn; cin >> nn;
        if (nn == 1)system("CLS");
        if (nn == 2) {i = n + 1; system("CLS"); return 0;}
        if (nn == 3){system("CLS");
            cout << "FINANTIST:   MIC: " << Statistica[1][1] << "  MEDIU: " << Statistica[1][2] << " MARE: " << Statistica[1][3] << "\n";
            cout << "MANAGER:   MIC: " << Statistica[2][1] << "  MEDIU: " << Statistica[2][2] << " MARE: " << Statistica[2][3] << "\n";
            cout << "PROGRAMATOR:   MIC: " << Statistica[3][1] << "  MEDIU: " << Statistica[3][2] << " MARE: " << Statistica[3][3] << "\n";
            cout << "MANAGER ECHIPA DE PROGRAMATORI:   MIC: " << Statistica[4][1] << "  MEDIU: " << Statistica[4][2] << " MARE: " << Statistica[4][3] << "\n";
            cout << "SOFER:   MIC: " << Statistica[5][1] << "  MEDIU: " << Statistica[5][2] << " MARE: " << Statistica[5][3] << "\n";
            cout << "MANAGER ECHIPA DE TIRISTI:   MIC: " << Statistica[6][1] << "  MEDIU: " << Statistica[6][2] << " MARE: " << Statistica[6][3] << "\n";
         cout <<"\n1: CLOSE         2: EXIT\n";
        int nnn; cin >> nnn;
        if (nnn == 1)system("CLS");
        if (nnn == 2) {i = n + 1; system("CLS"); return 0;}
        }
    }
    delete[] cursanti;
    return 0;
}
