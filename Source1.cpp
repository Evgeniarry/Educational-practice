#include <iostream>
#include <cstring>

int main()
{
    char str[] = "����������� ������������ ������� - ��������������, ���������� �����.";

    std::cout << "���������� ������ "" << str << "" �� �������:n";
    char* pch = strtok(str, " ,.-"); // �� ������ ��������� ������� ����������� (������, �������, �����, ����)

    while (pch != NULL)                         // ���� ���� �������
    {
        std::cout << pch << "n";
        pch = strtok(NULL, " ,.-");
    }
    return 0;
}