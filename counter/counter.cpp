// counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>

//���������� ������
class NumberCounter {
private:
    int sum;
    int count;

public:
    //������������� ��������� ��������
    //� ������� std::for_each, ��������� �������� ����� � ���������� ����� ��������, � ��� �������� ����� ����������� � �������� ������ � ��������� �����
    NumberCounter() : sum(0), count(0) {}

    //operator() ��������� ������������ ��������� ������ NumberCounter ��� �������������� ������, �� ���� �������� ��� ��� �������
    //� ������, ����� number ������� �� 3, ���������� ���������� �������� sum �� number, 
    //��� ��������� ������������ ����� ���� �����, ������� ������� �� 3. �����, ������������� �������� count, ������� �������� �� ������� ���������� �����, ��������� �� 3
    void operator()(int number) {
        if (number % 3 == 0) {
            sum += number;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {
  
    std::vector<int> numbers{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";

    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    NumberCounter counter = std::for_each(numbers.begin(), numbers.end(), NumberCounter());

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
