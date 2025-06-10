// ДЗ 7. Створити власний клас для однонаправленного зв'язаного списку

#include <iostream>

class SimpleList
{
private:
    struct Hillel
    {
        int value;
        Hillel* next;
        Hillel(int v) : value(v), next(nullptr) {}
    };

    Hillel* head = nullptr;
    Hillel* tail = nullptr;
    unsigned int size = 0;

public:
    SimpleList() = default;
    ~SimpleList()
    {
        Hillel* current = head;
        while (current != nullptr)
        {
            Hillel* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void Add(int isValue)
    {
        Hillel* newHillel = new Hillel(isValue);

        if (head == nullptr)
            head = tail = newHillel;
        else
        {
            tail->next = newHillel;
            tail = newHillel;
        }
        ++size;
    }

    void Insert(int isValue, unsigned int uiIndex)
    {
        Hillel* newHillel = new Hillel(isValue);

        if (uiIndex == 0 || head == nullptr)
        {
            newHillel->next = head;
            head = newHillel;
            if (tail == nullptr)
                tail = newHillel;
        }
        else
        {
            Hillel* current = head;
            unsigned int index = 0;

            while (current->next != nullptr && index < uiIndex - 1)
            {
                current = current->next;
                ++index;
            }

            newHillel->next = current->next;
            current->next = newHillel;

            if (newHillel->next == nullptr)
                tail = newHillel;
        }

        ++size;
    }

    unsigned int Size() const
    {
        return size;
    }

    int GetValue(unsigned int uiIndex) const
    {
        Hillel* current = head;
        for (unsigned int i = 0; i < uiIndex; ++i)
        {
            current = current->next;
        }
        return current->value;
    }
};

void FinalList(const SimpleList& list)
{
    for (unsigned int i = 0; i < list.Size(); ++i)
    {
        std::cout << "# " << i << ": " << list.GetValue(i) << "\n";
    }
}

int main()
{
    SimpleList list;

    list.Add(10);
    list.Add(20);
    list.Add(30);
    FinalList(list);

    list.Insert(5, 0);
    list.Insert(15, 2);
    list.Insert(40, 100);
    FinalList(list);

    std::cout << "Size of the List: " << list.Size() << "\n";

    return 0;
}