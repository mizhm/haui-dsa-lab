#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Product
{
  char id[6];
  char name[20];
  char unit[20];
  float price;
  int quantity;
};

struct Node
{
  Product product;
  Node *next;
};

typedef Node *List;

Product createProduct(char *id, char *name, char *unit, float price, int quantity)
{
  Product p;
  strcpy(p.id, id);
  strcpy(p.name, name);
  strcpy(p.unit, unit);
  p.price = price;
  p.quantity = quantity;
  return p;
}

void append(List &L, Product p)
{
  List N = new Node;
  N->product = p;
  N->next = NULL;
  if (L == NULL)
    L = N;
  else
  {
    List Q = L;
    while (Q->next != NULL)
      Q = Q->next;
    Q->next = N;
  }
}

void del(List &L, int index)
{
  if (L == NULL)
  {
    return;
  }
  List M, Q = L;

  while (Q != NULL && index > 1)
  {
    index--;
    M = Q;
    Q = Q->next;
  }

  if (Q == NULL)
  {
    return;
  }

  M->next = Q->next;
  delete Q;
}

void unshift(List &L, Product p)
{
  if (L == NULL)
  {
    return;
  }

  List P = new Node;
  P->product = p;
  P->next = L;
  L = P;
}

void bubbleSort(List &L)
{
  if (!L || !L->next)
  {
    return;
  }

  bool swapped = true;
  while (swapped)
  {
    swapped = false;
    List M = L;
    while (M->next)
    {
      List Q = M->next;
      float leftTotal = M->product.price * M->product.quantity;
      float rightTotal = Q->product.price * Q->product.quantity;
      if (leftTotal < rightTotal)
      {
        swap(M->product, Q->product);
        swapped = true;
      }
      M = M->next;
    }
  }
}

void insertionSort(List &L)
{
  if (!L || !L->next)
  {
    return;
  }

  List sorted = nullptr;
  while (L)
  {
    List current = L;
    L = L->next;

    if (!sorted || sorted->product.quantity * sorted->product.price < current->product.quantity * current->product.price)
    {
      current->next = sorted;
      sorted = current;
    }
    else
    {
      List tmp = sorted;
      while (tmp->next && tmp->next->product.quantity * tmp->next->product.price > current->product.quantity * current->product.price)
      {
        tmp = tmp->next;
      }
      current->next = tmp->next;
      tmp->next = current;
    }
  }
  L = sorted;
}

void showList(List L)
{
  cout << setw(6) << "STT" << setw(10) << "Ma hang" << setw(20) << "Ten hang" << setw(20) << "Don vi tinh" << setw(10) << "Don gia" << setw(10) << "So luong" << setw(15) << "Thanh tien" << endl;
  int i = 0;
  while (L != NULL)
  {
    i++;
    cout << setw(6) << i << setw(10) << L->product.id << setw(20) << L->product.name << setw(20) << L->product.unit << setw(10) << L->product.price << setw(10) << L->product.quantity << setw(15) << L->product.price * L->product.quantity << endl;
    L = L->next;
  }
}

int main()
{
  List L = NULL;
  Product p1 = createProduct("H2001", "Vo", "Quyen", 6500, 20);
  Product p2 = createProduct("H2002", "But chi", "Cai", 12000, 50);
  Product p3 = createProduct("H2003", "Hop but", "Chiec", 35000, 15);
  Product p4 = createProduct("H2004", "Tay", "Cai", 10000, 50);
  Product p5 = createProduct("H2005", "Thuoc ke", "Cai", 7000, 55);
  Product p6 = createProduct("H2006", "Muc", "Lo", 15000, 28);
  append(L, p1);
  append(L, p2);
  append(L, p3);
  append(L, p4);
  append(L, p5);
  append(L, p6);
  showList(L);
  // bubbleSort(L);
  insertionSort(L);
  showList(L);
  return 0;
}