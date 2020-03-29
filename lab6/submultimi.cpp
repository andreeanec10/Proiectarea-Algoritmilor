#include <iostream>
#include <vector>

bool check(std::vector<int> solution) {
    return true;
}
 
void printSolution(std::vector<int> solution) {
    for (int s : solution) {
        std::cout << s << " ";
    }
    std::cout << "\n";
}
 
void back(std::vector<int> domain, std::vector<int> solution, int index) {

    printSolution(solution);
    if (domain.size() == 0) {
        return;
    }
 
    for (unsigned int i = index; i < domain.size(); ++i) {

        std::vector<int> newSolution(solution), newDomain(domain);

        newSolution.push_back(domain[i]);

        back(newDomain, newSolution, i+1);
        
        newDomain.pop_back();

    }
}
 
int main() {
    int n; 
    std::cin >> n;
    std::vector<int> domain(n), solution;
    for (int i = 0; i < n; ++i) {
        domain[i] = i + 1;
    }
 
    back(domain, solution, 0);
}
