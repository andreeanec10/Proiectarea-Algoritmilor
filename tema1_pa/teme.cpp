#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#define inf 1 << 20

using namespace std;

bool comparator(vector<int> v1, vector<int> v2) {
    /*verifica in functie de termen de predare*/
    if (v1[3] < v2[3]) {
            return true;
    }
    return false;
}
bool comp(int x, int y) {
    return x < y;
}
int main() {
    int nr_teme;
    vector<vector<int> > teme;
    ifstream in;
    in.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        /*citire date cu verificare erori*/
        in.open("teme.in");
        in >> nr_teme;
        for (int i = 0; i < nr_teme; i++) {
            vector<int> aux(4);
            /*pozitia temei in lista*/
            aux[0] = i+1;
            /*nr_saptamani, punctaj, deadline*/
            in >> aux[1] >> aux[2] >> aux[3];
            teme.emplace_back(aux);
        }
        in.close();
    }
    catch(ifstream::failure e) {
        cerr << "Exception opening/closing \n";
    }
     sort(teme.begin(), teme.end(), comparator);
    int punctaj = 0;
    queue<int> ordine_teme;
    int saptamani_trecute = 0;
    for (int i = 0; i < nr_teme; i++) {
        if (saptamani_trecute <= teme[i][3]-teme[i][1]) {
            saptamani_trecute += teme[i][1];
            punctaj += teme[i][2];
            ordine_teme.push(teme[i][0]);
        }
    }
    ofstream out;
    out.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        /*scriere date cu verificare erori*/
        out.open("teme.out");
        out << punctaj << " " << ordine_teme.size() << "\n";
        while (!ordine_teme.empty()) {
            out << ordine_teme.front() << " ";
            ordine_teme.pop();
        }
        out.close();
    }
    
    return 0;
}
