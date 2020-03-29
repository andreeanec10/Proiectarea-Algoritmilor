#include <fstream>
#include <vector>

using namespace std;

int get_nr_of_sums(int n, vector<int> v) {
    int D[n+1][3];
    
    D[0][0] = D[0][1] = D[0][2] = 0;
    
    for(int i = 1; i <= n; i++) {
        if (v[i] % 3 == 0) {
			D[i][0] = 1 + 2*D[i-1][0];
			D[i][1] = 2 * D[i-1][1];
			D[i][2] = 2 * D[i-1][2];
		}
		if (v[i] % 3 == 1) {
			D[i][0] = D[i-1][0] + D[i-1][2];
			D[i][1] = 1 + D[i-1][0] + D[i-1][1];
			D[i][2] = D[i-1][2] + D[i-1][1];
		}
		if (v[i] % 3 == 2) {
			D[i][0] = D[i-1][0] + D[i-1][1];
			D[i][1] = D[i-1][2] + D[i-1][1];
			D[i][2] = 1 + D[i-1][2] + D[i-1][0];
		}
    }        
    
    return D[n][0];
}

int main() {
    //citire date de intrare
    ifstream in;
    in.open("input");
    
    int n;
    in >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) {
        in >> v[i];
    }
    in.close();
    
    //afisare in fisier
    ofstream out;
    out.open("output");
    out << get_nr_of_sums(n, v);
    out.close();
    
    return 0;
}
