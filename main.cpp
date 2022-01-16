#include <iostream>
#include <vector>
#include <algorithm>

class Random_numbers
{
private:
    std::vector<int> _random_numbers;

public:
    Random_numbers();
    Random_numbers(int m1, int m2, int count);
    ~Random_numbers();

    void set_random_values(int m1, int m2, int count);
    int get_value(int index);
    std::vector<int> get_vector();
    int find_count_number(int number);
    void display_info();
    void shift_elements();
    void OnTen();
    int SqrCount();
};

Random_numbers::Random_numbers()
{

}

Random_numbers::Random_numbers(int m1, int m2, int vec_size)
{
    _random_numbers.resize(vec_size);
    int i;
    for (i = 0; i < vec_size; i++)
    {
        _random_numbers[i] = ((m1) + rand() % (m2 - m1));
    }
}

Random_numbers::~Random_numbers()
{

}

void Random_numbers::set_random_values(int m1, int m2, int vec_size)
{
    _random_numbers.resize(vec_size);
    int i;
    for (i = 0; i < vec_size; i++)
    {
        _random_numbers[i] =((m1) + rand() % (m2 - m1));
    }
}

int Random_numbers::get_value(int index)
{
    int value = _random_numbers[index];
    return value;
}

std::vector<int> Random_numbers::get_vector()
{
    return _random_numbers;
}

int Random_numbers::find_count_number(int numb)
{
    std::vector<int>::iterator number;		//объявляем итератор
    int count = 0;
    for (number = _random_numbers.begin(); number != _random_numbers.end(); ++number)
    {
        if (abs(*number) == numb)		//проверяем, равен ли элемент абсолютному значению
        {
            count++;
        }
    }
    return count;
}

void Random_numbers::display_info()
{
    std::vector<int>::iterator number;		//объявляем итератор
    int count = 1;
    for (number = _random_numbers.begin(); number != _random_numbers.end(); ++number)
    {
        std::cout << *number << " ";
        if (count % 10 == 0)		//раз в 10 значений переводим строку для удобства чтения
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void Random_numbers::shift_elements(){
    std::rotate(_random_numbers.rbegin(), _random_numbers.rbegin() + 2, _random_numbers.rend());
    // Rand генерирует следующее случайное число для последовательности
    // std::rotate меняет местами элементы в диапазоне [first, last) так ,
    // что элемент n_first становится первым элементом нового диапазона, а n_first - 1 становится последним элементом
}
void Random_numbers::OnTen() {
    std::transform(_random_numbers.begin(), _random_numbers.end(), _random_numbers.begin(), [](int e) {return e * 10; });
    // std::transform - на вход получает начало и конец списка. Далее нужно ввести то, куда нужно передать результат
    // а последним параметром принимается функция которую нужно применить ко всем элементам диапазона.
}
int Random_numbers::SqrCount() {
    return std::count_if(_random_numbers.begin(), _random_numbers.end(), [](int e) {return e * e > 10; });
    // std::count_if() ищет все вхождения элемента или элемент, соответствующий заданным критериям.
}

int main()
{
    std::vector<Random_numbers> numbers_entry;		//вводим массив элементов класса
    std::vector<int> massiv_1;
    std::vector<int> massiv_2;
    int m1, m2, vec_size, i, numb, vec_index;
    char command;
    bool exit = false;
    while (!exit)
    {
        std::cout << "\nЧто вы хотите сделать? \n";
        std::cout << "\t1. Создать массив с рандомными символами.\n";
        std::cout << "\t2. Сдвинуть все элемены массива вправо на 2(циклический сдвиг).\n";
        std::cout << "\t3. Умножить все элементы массива на 10.\n";
        std::cout << "\t4. Подсчитать количество элементов, квадрат которых больше p (p=10).\n";
        std::cout << "\t5. Отобразить все массивы.\n";
        std::cout << "\t6. Выход из программы.\n";
        std::cout << "Команда: ";
        std::cin >> command;
        std::cin.ignore();
        switch (command)
        {
            case '1':
                std::cout << "Введите число m1 начала диапазона: ";
                std::cin >> m1;
                std::cout << "Введите число m2 конца диапазона: ";
                std::cin >> m2;
                std::cout << "Введите размер вектора: ";
                std::cin >> vec_size;
                numbers_entry.push_back(Random_numbers(m1, m2, vec_size));
                std::cout << "Массив создан." << std::endl;
                numbers_entry[numbers_entry.size() - 1].display_info();
                break;
            case '2':
                std::cout << "Все имеющиеся массивы: " << std::endl;
                for (i = 0; i < size(numbers_entry); i++)
                {
                    std::cout << "Массив №" << i << " ";
                    numbers_entry[i].display_info();
                }
                std::cout << "В котором массиве вы хотите сдвинуть значения? Введите номер: ";
                std::cin >> vec_index;
                if (vec_index < 0 || vec_index >= numbers_entry.size())
                {
                    std::cout << "Введен неверный номер массива!" << std::endl;
                    break;
                }
                numbers_entry[vec_index].shift_elements();
                std::cout << "Элементы сдвинуты : " << std::endl;
                numbers_entry[vec_index].display_info();
                std::cout << std::endl;
                break;
            case '3':
                int mass_1;
                std::cout << "Все имеющиеся массивы: " << std::endl;
                for (i = 0; i < size(numbers_entry); i++)
                {
                    std::cout << "Массив №" << i << " ";
                    numbers_entry[i].display_info();
                }
                std::cout << "Выберите массив для умножения: ";
                std::cin >> mass_1;
                if (mass_1 < 0 || mass_1 >= numbers_entry.size())
                {
                    std::cout << "Введен неверный номер массива!" << std::endl;
                    break;
                }
                numbers_entry[mass_1].OnTen();
                std::cout << "Умноженный массив :" << std::endl;
                numbers_entry[mass_1].display_info();
                break;
            case '4':
                std::cout << "Все имеющиеся массивы: " << std::endl;
                for (i = 0; i < size(numbers_entry); i++)
                {
                    std::cout << "Массив №" << i << " ";
                    numbers_entry[i].display_info();
                }
                std::cout << "В котором массиве вы хотите проверить элементы? Введите номер: ";
                std::cin >> vec_index;
                if (vec_index < 0 || vec_index >= numbers_entry.size())
                {
                    std::cout << "Введен неверный номер массива!" << std::endl;
                    break;
                }
                std::cout << "Колличество элементов квадрат которых больще p(p=10) = " << numbers_entry[vec_index].SqrCount() << " раз(а)." << std::endl;
                break;
            case '5':
                for (i = 0; i < size(numbers_entry); i++)
                {
                    std::cout << "Массив №" << i << " ";
                    numbers_entry[i].display_info();
                }
                break;
            case '6':
                exit = true;
                break;
            default:
                std::cout << "Вы ввели некорректную команду. Введите от 1 до 6." << std::endl;
                break;
        }
    }
    return 0;
}