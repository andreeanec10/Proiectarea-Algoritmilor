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
 
void back(std::vector<int> domain, std::vector<int> solution) {

    if (domain.size() == 0) {
        printSolution(solution);
        return;
    }
 
    for (unsigned int i = 0; i < domain.size(); ++i) {

        std::vector<int> newSolution(solution), newDomain(domain);

        newSolution.push_back(domain[i]);

        newDomain.erase(newDomain.begin() + i);

        back(newDomain, newSolution);
    }
}
 
int main() {
    int n; 
    std::cin >> n;
    std::vector<int> domain(n), solution;
    for (int i = 0; i < n; ++i) {
        domain[i] = i + 1;
    }
 
    back(domain, solution);
}
