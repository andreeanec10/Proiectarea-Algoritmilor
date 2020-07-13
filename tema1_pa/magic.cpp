#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#define inf 1 << 20

using namespace std;

int dist2(int a, int b) {
    return (a-b) * (a-b);
}
int main() {
    int nr;
    vector<int> numere;
    ifstream in;
    in.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        /*citire date cu verificare erori*/
        in.open("magic.in");
        in >> nr;
        numere.push_back(0);
        for (int i = 1; i <= nr; i++) {
            int a;
            in >> a;
            numere.push_back(a);
        }
        in.close();
    }
    catch(ifstream::failure e) {
        cerr << "Exception opening/closing \n";
    }
    vector<int> lista_nr(nr+1);
    int suma_elem = 0;
    int dist = inf;
    int prim, secund;
    for (int i = 1; i <= nr; i++) {
        lista_nr[i] = suma_elem;
        suma_elem += numere[i];
    }
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j + i <= nr; j++) {
            if ((i * i + dist2(lista_nr[i+j], lista_nr[j])) < dist) {
                prim = j;
                secund = i + j;
                dist = dist2(lista_nr[i+j], lista_nr[j]) + i * i;
            }
        }
    }
    ofstream out;
    out.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        /*scriere date cu verificare erori*/
        out.open("magic.out");
        out << dist << "\n" << prim << " " << secund;
        out.close();
    }
    catch(ifstream::failure e) {
        cerr << "Exception writing/closing \n";
    }
    return 0;
}
