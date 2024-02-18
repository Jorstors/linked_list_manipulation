#ifndef LINKED_LIST_MANIP
#define LINKED_LIST_MANIP

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};


// Menu
int printMenu(int &option);
// create node
Node *createNode(int data);
// add to front
void frontNode(int data);
// add to back
void backNode(int data);
// remove
int removeNode(int data);
// insert
int insertNode(int position, int data);
// print
void printList();

#endif