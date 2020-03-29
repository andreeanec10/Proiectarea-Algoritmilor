#include <fstream>
#include <vector>

using namespace std;

int garduri(int k, int nr) {
    if (nr <= k) return 1;
    if (nr == k) return 2;
 
    vector<int> D(nr + 1); 
    
    for(int i = 1; i < k; i++) {
        D[i] = 1;
    }
    D[k] = 2;
 
    for (int i = k+1; i <= nr; ++i) {
        D[i] = (D[i - 1] + D[i - k]);
    }
 
    return D[nr];
}

int main() {
    //citire date de intrare
    ifstream in;
    in.open("input");
    
    int size, nr;
    in >> size >> nr;
    in.close();
    
    //afisare in fisier
    ofstream out;
    out.open("output");
    out << garduri(size, nr);
    out.close();
    
    return 0;
}
