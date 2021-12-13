// Lab3 ООП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

struct NOTEBOOK {
public:
    char model[80];
    struct size {
    public:
        float x;
        float y;
        float z;
    }r;
    float w;
    int price;
    int chastota;
};

NOTEBOOK name[100];
int n;
bool prov;

void Vuvod(NOTEBOOK a[100], int n);
void Zapis();
void File();
void print(NOTEBOOK a[100], int n);

int main()
{
    NOTEBOOK itog[100];
    NOTEBOOK x;
    int i,j;
    cout << "Sozdaem zapis: " << endl;
    Zapis();
    File();//
    int k;
    k = 0;
    if (prov == true) {
        for (i = 0; i < n; i++) {
            if (name[i].chastota >= 120) {
                k = k + 1;
                itog[k] = name[i];
            }
        }
        if (k > 0) {
            for (i = 1; i < k; i++) {
                for (j = i+1; j < k+1; j++) {
                    if (itog[i].price <= itog[j].price) {
                        x = itog[i];
                        itog[i] = itog[j];
                        itog[j] = x;
                    }
                }
            }
           
        }
        else {
            cout << endl <<  "Net zapisey: chastota prosessora >= 120 MGs";
        } Vuvod(itog, k);
    }
    return 0;
}

void Zapis() { //создает файл с записью по заданной в условии структурой
    int i;
    prov = true;

    cout << "Kolichestvo: ";
    cin >> n;
    if ((!n)|(n<0)) {
        cout << "Vvedeno nevernoe znachenie.";
    }
    for (i = 0; i < n; i++) {
       cout << endl <<"Vvedite name model: ";
       cin >> name[i].model;
       if (!name[i].model) {
           cout << "Error.";
           prov = false;
           break;
       }
       cout << endl << "Vvedite razmer x: ";
       cin >> name[i].r.x;
       if ((!name[i].r.x)|(name[i].r.x<0)) {
           cout << "Error."; prov = false; break;
       }
       cout << endl << "Vvedite razmer y: ";
       cin >> name[i].r.y;
       if ((!name[i].r.y) | (name[i].r.y < 0)) {
           cout << "Error."; prov = false; break;
       }
       cout << endl << "Vvedite razmer z: ";
       cin >> name[i].r.z;
       if ((!name[i].r.z) | (name[i].r.z < 0)) {
           cout << "Error."; prov = false; break;
       }
       cout << endl << "Vvedite ves: ";
       cin >> name[i].w;
       if ((!name[i].w)|(name[i].w<0)) {
           cout << "Error."; prov = false; break;
       }
       cout << endl << "Vvedite price: ";
       cin >> name[i].price;
       if ((!name[i].price)|(name[i].price<0)) {
           cout << "Error."; prov = false; break;
       }
       cout << endl << "Vvedite chastotu prosessora: ";
       cin >> name[i].chastota;
       if ((!name[i].chastota) | (name[i].chastota < 0)) {
           cout << "Error."; prov = false; break;
       }
       cout << endl;
    }
    if (prov == true) {
        ofstream out("test.txt");
        if (!out) {
            cout << "can not open the file!\n";
        }
        out << n << endl;

        for (i = 0; i < n; i++) {
            out << name[i].model << endl;
            out << name[i].r.x << endl;
            out << name[i].r.y << endl;
            out << name[i].r.z << endl;
            out << name[i].w << endl;
            out << name[i].price << endl;
            out << name[i].chastota << endl << endl;
        }
        out.close();
    }
}

void File() {
register int i;
if (prov == true) {
    ifstream in("test.txt");
    if (!in) {
        cout << "can not open the file!\n";
    }
    if (in.is_open()) {
    int num;
    in >> n;
    num = n;
    for (i = 0; i < num; i++) {
        cout << endl;
        in >> name[i].model;
        in >> name[i].r.x;
        in >> name[i].r.y;
        in >> name[i].r.z;
        in >> name[i].w;
        in >> name[i].price;
        in >> name[i].chastota;
    }
    print(name, num);
    in.close();
    }
}
}

void print(NOTEBOOK a[100], int num) { //просто выводит на экран структуру которая есть 
    int i;
    for (i = 0; i < num; i++) {
        cout << endl;
        cout << "Model: " << a[i].model << endl;
        cout << "X: " << a[i].r.x << " cm." << endl;
        cout << "Y:" << a[i].r.y << " cm." << endl;
        cout << "Z:" << a[i].r.z << " cm." << endl;
        cout << "Ves: " << a[i].w << " g." << endl;
        cout << "Price: " << a[i].price << " rub." << endl;
        cout << "Price: " << a[i].chastota << " MGs." << endl;
    }
}

void Vuvod(NOTEBOOK a[100], int n) { // записывает в конец бинарного файла структуру количество которого n?
    int i;
    ofstream out("bynarny.txt", ios::out | ios::binary);
        out.seekp(0, ios::end);
        if (!out) {
            cout << "can not open the file!\n";
        }
        
        out << n << endl;

        for (i = 1; i < n+1; i++) {
            out << a[i].model << endl;
            out << a[i].r.x << endl;
            out << a[i].r.y << endl;
            out << a[i].r.z << endl;
            out << a[i].w << endl;
            out << a[i].price << endl;
            out << a[i].chastota << endl << endl;
        }
        out.close();
}