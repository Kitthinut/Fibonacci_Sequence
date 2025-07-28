#include <iostream>
#include <vector>

std::vector<long long> fibonacci(unsigned int n) {
    std::vector<long long> seq;

    if (n >= 1) seq.push_back(0);
    if (n >= 2) seq.push_back(1);

    for (std::size_t i = 2; i < n; ++i) {
        seq.push_back(seq[i - 1] + seq[i - 2]);
    }

    return seq;
}

int main() {
    unsigned int n = 100;
    std::vector<long long> fibs = fibonacci(n);

    for (std::size_t i = 0; i < fibs.size(); ++i) {
        std::cout << fibs[i];
        if (i != fibs.size() - 1) std::cout << ", ";
    }

    std::cout << std::endl;
    return 0;
}
