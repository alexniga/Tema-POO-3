#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <cstring>

using namespace std;

class Cursuri
{
    int *curs;
    double media_notelor;
    int nr_note;
    int evaluare_sc_oral;

public:
    Cursuri(int nr = 1){ media_notelor = 0; evaluare_sc_oral = 0; nr_note = nr; curs = new int[nr];}
    void add_nota_la_poz(int nota, int poz){ curs[poz] = nota;}
    int return_nota_la_poz(int poz)const{return curs[poz];}
    int return_nr_note()const{return nr_note; }
    double return_media_notelor() const {return media_notelor; }
    void set_media(double nr){ media_notelor = nr;}
    void set_nr_note(int nr){nr_note = nr;}
    void set_evaluare_sc_oral_curs(int nr){evaluare_sc_oral = nr; }
    int return_eval_sc_oral_curs(){return evaluare_sc_oral; }
    void free_curs(){ delete[] curs;}
    void realoc_curs(int nr){curs = new int[nr]; }
    virtual void calcu_media();
    virtual~Cursuri(){delete[]curs;}
    friend ostream& operator <<(ostream& out, const Cursuri &c);
    friend istream& operator >>(istream& in, Cursuri &c);
    Cursuri& operator =(const Cursuri &curs);

};
class Matematica: public Cursuri
{
    int evaluare_scrisa;
    char ce_fel[40];

public:
    Matematica():Cursuri(1){}
    void set_nota_oral_sau_scris(int nr){ evaluare_scrisa = nr;}
    int retur_nota_orala(){ return evaluare_scrisa;}
    void set_ce_fel(char ce[40]){ strcpy(ce_fel, ce); }
    string return_ce_fel(){ string nume; nume = ce_fel; return nume; }
    friend ostream& operator <<(ostream& out, const Matematica &m);
    friend istream& operator >>(istream& in, Matematica &m);
    void calcu_media()
    {int not_slaba = 11, nr_not = this->return_nr_note();
        double med = 0;
     for (int i = 0; i < nr_not; i++)
        if (not_slaba > this->return_nota_la_poz(i))
            not_slaba = this->return_nota_la_poz(i);
     for (int i = 0; i < nr_not; i++)
        med += this->return_nota_la_poz(i);
    med -= not_slaba;
    med += this->retur_nota_orala();
    med = med / nr_not;
    this->set_media(med);
    }

};

class Programare: public Cursuri
{
    int evaluare_scrisa;
    char ce_fel[40];

public:
    Programare()
    : Cursuri(1){}
    void set_nota_oral_sau_scris(int nr){ evaluare_scrisa = nr;}
    void set_ce_fel(char ce[40]){ strcpy(ce_fel, ce); }
    string return_ce_fel(){ string nume; nume = ce_fel; return nume; }
    int retur_nota_orala(){ return evaluare_scrisa;}
    friend ostream& operator <<(ostream& out, const Programare &p);
    friend istream& operator >>(istream& in, Programare &p);
    void calcu_media()
    {
        int nr_not = this->return_nr_note();
        double med;
     for (int i = 0; i < nr_not; i++)
        med += this->return_nota_la_poz(i);
    med += this->retur_nota_orala();
    med = med / (nr_not + 1);
    this->set_media(med);
    }


};

class Limba_straina: public Cursuri
{
    char ce_fel[40];

public:
    Limba_straina()
    : Cursuri(1){}
    void set_ce_fel(char ce[40]){ strcpy(ce_fel, ce); }
    string return_ce_fel(){ string nume; nume = ce_fel; return nume; }
    friend ostream& operator <<(ostream& out, const Limba_straina &p);
    friend istream& operator >>(istream& in, Limba_straina &p);
};

class Resurse_Umane: public Cursuri
{
public:
    Resurse_Umane()
    : Cursuri(1){}
    void calcu_media()
    {
        int not_slaba = 11, not_mare = -1, nr_not = this->return_nr_note();
        double med;
        for (int i = 0; i < nr_not; i++)
        {
            if (not_slaba > this->return_nota_la_poz(i))
                not_slaba = this->return_nota_la_poz(i);
            if (not_mare < this ->return_nota_la_poz(i))
                not_mare = this -> return_nota_la_poz(i);
        }
        for (int i = 0; i < nr_not; i++)
            med += this->return_nota_la_poz(i);
        med = med - not_slaba - not_mare;
        med = med / (nr_not - 2);
        this->set_media(med);
    }
    friend ostream& operator <<(ostream& out, const Resurse_Umane &p);
    friend istream& operator >>(istream& in, Resurse_Umane &p);
};

class Financiar: public Cursuri
{
public:
    Financiar()
    : Cursuri(1){}
    friend ostream& operator <<(ostream& out, const Financiar &p);
    friend istream& operator >>(istream& in, Financiar &p);
};

class Legislatie_auto: public Cursuri
{
public:
    Legislatie_auto()
    : Cursuri(1){}
    friend ostream& operator <<(ostream& out, const Legislatie_auto &p);
    friend istream& operator >>(istream& in, Legislatie_auto &p);
};

class Comunicare_NLP: public Cursuri
{
    int evaluare_scrisa;

public:
    Comunicare_NLP()
    : Cursuri(1){}
    void set_nota_oral_sau_scris(int nr){ evaluare_scrisa = nr;}
    int retur_nota_orala(){ return evaluare_scrisa;}
    friend ostream& operator <<(ostream& out, const Comunicare_NLP &p);
    friend istream& operator >>(istream& in, Comunicare_NLP &p);
    void calcu_media()
    {
        int not_slaba = 11, not_mare = -1, nr_not = this->return_nr_note();
        double med;
        for (int i = 0; i < nr_not; i++)
        {
            if (not_slaba > this->return_nota_la_poz(i))
                not_slaba = this->return_nota_la_poz(i);
            if (not_mare < this ->return_nota_la_poz(i))
                not_mare = this -> return_nota_la_poz(i);
        }
     for (int i = 0; i < nr_not; i++)
        med += this->return_nota_la_poz(i);
    med = med - not_slaba - not_mare;
    med = med / (nr_not - 2);
    if (med > 5)
        this->set_media(this->retur_nota_orala());
    else
        this->set_media(1);

    }

};

class Sofat_auto_practic: public Cursuri
{
    char ce_fel[40];
public:
    Sofat_auto_practic()
    : Cursuri(1){}
    friend ostream& operator <<(ostream& out, const Sofat_auto_practic &p);
    friend istream& operator >>(istream& in, Sofat_auto_practic &p);

};

class Programe
{
   int nr_de_cursuri;
   double nota_program;
   char nivel_program[10];

public:
    Programe(int ce_program);
    void set_nota_program(double nr){nota_program = nr; }
    double return_nota_program(){return nota_program; }
    int return_nr_de_cursuri(){return nr_de_cursuri;}
    void set_nivel(char niv[10]){strcpy(nivel_program, niv); }
    string return_nivel(){string niv; niv = nivel_program; return niv; }
    void calcu_competenta()
    {
        double not_prog = this->return_nota_program();
        if (not_prog >= 5 && not_prog <= 6)
            this->set_nivel("MIC");
        if (not_prog > 6 && not_prog <=8)
            this->set_nivel("MEDIU");
        if (not_prog > 8 && not_prog <= 10)
            this->set_nivel("MARE");
        if (not_prog < 5)
            this->set_nivel("PICAT");
    }
    virtual ~Programe(){}
};

class FINANTIST: public Programe
{
protected:
    Matematica mat;
    Financiar fin;
public:
    FINANTIST()
    : Programe(1){}
    friend istream& operator >>(istream& in, FINANTIST &f);
    friend ostream& operator <<(ostream& out, const FINANTIST &f);
    void copiaza_mat(Matematica &m){ this->mat = m;}
    void copiaza_fin(Financiar &f){ this->fin = f;}
    void calculeaza_nota()
    {
        int ok = 1;
        double nota_prog;
        mat.calcu_media();
        fin.calcu_media();
        if (mat.return_media_notelor() < 5 || fin.return_media_notelor() < 5)
            ok = 0;
        nota_prog = mat.return_media_notelor() + fin.return_media_notelor();
        nota_prog /= this->return_nr_de_cursuri();
        if (ok == 1)
            this->set_nota_program(nota_prog);
        else
            this->set_nota_program(1);
    }

};

class MANAGER: public Programe
{
protected:
    Resurse_Umane res_uman;
    Financiar fin;
    Limba_straina limba;
public:
    MANAGER()
    :Programe(2){}
    friend istream& operator >>(istream& in, MANAGER &f);
    friend ostream& operator <<(ostream& out, const MANAGER &f);
     void calculeaza_nota()
    {
        double nota_prog, ok = 1;;
        res_uman.calcu_media();
        fin.calcu_media();
        limba.calcu_media();
        nota_prog = res_uman.return_media_notelor() + fin.return_media_notelor() + limba.return_media_notelor();
        if (res_uman.return_media_notelor() < 5 || fin.return_media_notelor() < 5 || limba.return_media_notelor() < 5)
            ok = 0;
        nota_prog /= this->return_nr_de_cursuri();
        if (ok == 1)
            this->set_nota_program(nota_prog);
        else
            this->set_nota_program(1);
    }

};

class PROGRAMATOR: public Programe
{
    Matematica algebra;
    Matematica analiza;
    Matematica geometrie;
    Programare prog;
    Limba_straina limba;
public:
    PROGRAMATOR()
    : Programe(3){}
    friend istream& operator >>(istream& in, PROGRAMATOR &f);
    friend ostream& operator <<(ostream& out, const PROGRAMATOR &f);
     void calculeaza_nota()
    {
        int ok = 1;
        double nota_prog;
        algebra.calcu_media();
        analiza.calcu_media();
        geometrie.calcu_media();
        prog.calcu_media();
        limba.calcu_media();
        nota_prog = algebra.return_media_notelor() + analiza.return_media_notelor() + limba.return_media_notelor() + geometrie.return_media_notelor() + prog.return_media_notelor();
        if (algebra.return_media_notelor() < 5 || analiza.return_media_notelor() < 5 || limba.return_media_notelor() < 5 || geometrie.return_media_notelor() < 5 || prog.return_media_notelor() < 5)
            ok = 0;
        nota_prog /= this->return_nr_de_cursuri();
        if (ok == 1)
            this->set_nota_program(nota_prog);
        else
            this->set_nota_program(1);
    }

};

class PROGRAMATORI: public Programe
{
    MANAGER manager;
    Programare prog;
    Comunicare_NLP nlp;
public:
    PROGRAMATORI()
    : Programe(4){}
    friend istream& operator >>(istream& in, PROGRAMATORI &f);
    friend ostream& operator <<(ostream& out, const PROGRAMATORI &f);
    double return_nota_la_manager(){return manager.return_nota_program();}
    void calculeaza_nota()
    {
        double nota_prog, ok = 1;;
        manager.calculeaza_nota();
        prog.calcu_media();
        nlp.calcu_media();
        nota_prog = prog.return_media_notelor() + nlp.return_media_notelor() + manager.return_nota_program();
        if (prog.return_media_notelor() < 5 || nlp.return_media_notelor() < 5 || manager.return_nota_program() < 5)
            ok = 0;
        nota_prog /= this->return_nr_de_cursuri();
        if (ok == 1)
            this->set_nota_program(nota_prog);
        else
            this->set_nota_program(1);
    }

};

class SOFER: public Programe
{
    Legislatie_auto leg_auto;
    Sofat_auto_practic sofa;
public:
    SOFER()
    : Programe(5){}
    friend istream& operator >>(istream& in, SOFER &f);
    friend ostream& operator <<(ostream& out, const SOFER &f);
    void calculeaza_nota()
    {
        double nota_prog, ok = 1;;
        leg_auto.calcu_media();
        sofa.calcu_media();
        nota_prog = leg_auto.return_media_notelor() + sofa.return_media_notelor();
        if (leg_auto.return_media_notelor() < 5 || sofa.return_media_notelor() < 5)
            ok = 0;
        nota_prog /= this->return_nr_de_cursuri();
        if (ok == 1)
            this->set_nota_program(nota_prog);
        else
            this->set_nota_program(1);
    }
};

class MANAGER_ECHIPA_TIRI: public Programe
{
    Limba_straina turca;
    MANAGER manager;
    Legislatie_auto leg_auto;
public:
    MANAGER_ECHIPA_TIRI()
    : Programe(6){}
    friend istream& operator >>(istream& in, MANAGER_ECHIPA_TIRI &f);
    friend ostream& operator <<(ostream& out, const MANAGER_ECHIPA_TIRI &f);
    double return_nota_la_manager(){return manager.return_nota_program();}
    void calculeaza_nota()
    {
        double nota_prog, ok = 1;;
        turca.calcu_media();
        leg_auto.calcu_media();
        manager.calculeaza_nota();
        nota_prog = turca.return_media_notelor() + leg_auto.return_media_notelor() + manager.return_nota_program();
        if (leg_auto.return_media_notelor() < 5 || turca.return_media_notelor() < 5 || manager.return_nota_program() < 5)
            ok = 0;
        nota_prog /= this->return_nr_de_cursuri();
        if (ok == 1)
            this->set_nota_program(nota_prog);
        else
            this->set_nota_program(1);
    }
};

class Fisa_Evaluare
{
    char numele[15];
    char prenumele[15];
    pair <int, char[15]> ce_program;
    pair <double, string> medie_competenta;
    pair <double, string> e_manager_medie_nivel;
    FINANTIST finantist;
    MANAGER manager;
    PROGRAMATOR programator;
    PROGRAMATORI programatori;
    SOFER sofer;
    MANAGER_ECHIPA_TIRI manager_tiristi;
public:
    void set_nume_prenume(char *num, char *prenum){ strcpy(numele, num); strcpy(prenumele, prenum); }
    void afisare_nume_prenume(){ std::cout << numele << " " << prenumele;}
    void set_ce_program(int in){ ce_program.first = in;}
    double return_nota_la_manager(){double i,ii; i = programatori.return_nota_la_manager(); ii = manager_tiristi.return_nota_la_manager(); if (ce_program.first == 4)return i; else return ii;}
    void set_ce_medie(double nr){ medie_competenta.first = nr; }
    double return_medie_MANAGER(){ return e_manager_medie_nivel.first;}
    void set_e_manager_medie(double it){ e_manager_medie_nivel.first = it;}
    void set_e_manager_nivel(string com){ e_manager_medie_nivel.second = com;}
    void calculeaza_media_notelor();
    void set_ce_competenta(string com){ medie_competenta.second = com;}
    void set_ce_program_char(char nume_pro[15]){ strcpy(ce_program.second, nume_pro);}
    int return_ce_program(){return ce_program.first; }
    double return_ce_medie(){ return medie_competenta.first;}
    string return_ce_competenta(){ string compe; compe = medie_competenta.second; return compe;}
    string return_nume_program(){ string nume; nume = ce_program.second; return nume; }
    Fisa_Evaluare(){};
    ~Fisa_Evaluare(){};
    friend ostream& operator <<(ostream& out, const Fisa_Evaluare &v2);
    friend istream& operator >>(istream& in, Fisa_Evaluare &v2);
};

class Cursant
{
    Fisa_Evaluare fisa;
public:
    friend ostream& operator <<(ostream& out, const Cursant &cursant);
    friend istream& operator >>(istream& in, Cursant &cursant);
};

#endif // CLASS_H_INCLUDED
