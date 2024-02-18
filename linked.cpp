#include "linked.hpp"

Node *head = nullptr;
Node *tail = nullptr;

int printMenu(int &option)
{
    int data;
    bool success;
    int position;

    cout << "You have the following options: " << endl
         << endl;
    cout << "1. Add a node to front" << endl;
    cout << "2. Add a node to back" << endl;
    cout << "3. Remove a node from the list" << endl;
    cout << "4. Insert node into to the list" << endl;
    cout << "5. Print the list" << endl;
    cout << "6. Quit" << endl
         << endl;

    cin >> option;
    switch (option)
    {
    case 1:
        // add to front
        cout << "What data do you want to insert to the front?: " << endl;
        cin >> data;
        frontNode(data);
        break;

    case 2:
        // add to back
        cout << "What data do you want to insert to the back?: " << endl;
        cin >> data;
        backNode(data);
        break;

    case 3:
        // remove
        cout << "What data do you want to remove?: " << endl;
        cin >> data;
        success = removeNode(data);

        if (!success)
            cout << "Data not found" << endl;
        else
            cout << "Data removed" << endl;

        break;

    case 4:
        // add in middle
        cout << "What index do you want to insert data? (1+)?: " << endl;
        cin >> position;
        cout << "What data do you want to insert?" << endl;
        cin >> data;
        success = insertNode(position, data);

        if (!success)
            cout << "Your position is outside of the index range!" << endl;
        else
            cout << "Data added in your position!" << endl;

        break;

    case 5:
        // print
        printList();
        break;

    case 6:
        // quit
        return 0;
        break;
    }

    if (!cin)
    {
        cin.clear();  // Restore input stream to working state
        cin.ignore(); // Get rid of any garbage that user might have entered

        cout << endl
             << "Invalid option: use a number between 1 and 6" << endl
             << endl;
    }
    return 1;
}

Node *createNode(int data)
{
    Node *n = new Node;
    n->data = data;
    n->next = nullptr;

    return n;
}

void printList()
{
    cout << "---------------------------------" << endl;
    cout << "Linked List:";
    cout << "\n{ ";

    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << ", ";
        current = current->next;
    }
    cout << "}\n";
    cout << "---------------------------------" << endl;
}

void frontNode(int data)
{
    Node *n = createNode(data);
    n->next = head;
    head = n;

    if (tail == nullptr)
        tail = n;
}

void backNode(int data)
{

    Node *n = createNode(data);

    if (head == nullptr)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = tail->next;
        tail->next = nullptr;
    }
}

int insertNode(int position, int data)
{

    Node *index = head;
    Node *prev = head;
    int nPosition = 1;

    while (index != nullptr)
    {
        if (nPosition == position)
        {
            if (index == head)
            {
                frontNode(data);
            }
            else
            {
                Node *n = createNode(data);
                prev->next = n;
                n->next = index;
            }

            return 1; // found and removed data;
        }
        nPosition++;
        prev = index;
        index = index->next;
    }

    return 0; // node not found
}

int removeNode(int data)
{

    Node *n = head;
    Node *prev = head;

    while (n != nullptr)
    {
        if (n->data == data)
        {
            if (n == head)
            {
                head = head->next;
                n->next = nullptr;
                delete n;
            }
            else if (n == tail)
            {
                tail = prev;
                tail->next = nullptr;
                n->next = nullptr;
                delete n;
            }
            else
            {
                prev->next = n->next;
            }

            return 1; // found and removed data;
        }
        prev = n;
        n = n->next;
    }

    return 0;
}
