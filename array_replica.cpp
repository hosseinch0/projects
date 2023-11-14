#include <iostream>
using namespace std;

class ArrayReplica
{
    // faraz added this method
private:
    int array[100];
    int cruiser = 0;

public:
    void append(int value)
    {
        this->array[this->cruiser] = value;
        cruiser++;
    }

    void insert(int value, int index)
    {
        for (int i = cruiser; i >= index; i--)
        {
            this->array[i + 1] = array[i];
        }
        this->array[index] = value;
        this->cruiser++;
    }

    void display()
    {
        sort(this->array);
        for (int i = 0; i < cruiser; i++)
        {
            cout << array[i] << endl;
        }
    }

    int del(int index)
    {
        for (int i = index; i < cruiser; i++)
        {
            this->array[i] = array[i + 1];
        }
        cruiser--;
        return array[index];
    }

    int find(int value)
    {
        for (int i = 0; i < cruiser - 1; i++)
        {
            if (value == array[i])
            {
                return i;
            }
        }
        return 0;
    }

    int sort(int array[])
    {
        for (int i = 0; i < cruiser - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < cruiser - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j];
                    this->array[j] = array[j + 1];
                    this->array[j + 1] = temp;
                    swapped = true;
                }
            }
            if (swapped == false)
            {
                break;
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}
