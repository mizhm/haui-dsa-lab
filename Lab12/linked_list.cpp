#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Student
{
  char id[7];
  char firstName[20];
  char lastName[10];
  bool gender;
  int year;
  float score;
};

struct Node
{
  Student info;
  Node *next;
};

typedef Node *Tro;

Student createStudent(char *id, char *firstName, char *lastName, bool gender, int year, float score)
{
  Student s;
  strcpy(s.id, id);
  strcpy(s.firstName, firstName);
  strcpy(s.lastName, lastName);
  fflush(stdin);
  s.gender = gender;
  s.year = year;
  s.score = score;
  return s;
}

void append(Tro &L, Student s)
{
  Tro P = new Node;
  P->info = s;
  P->next = NULL;
  if (L == NULL)
  {
    L = P;
  }
  else
  {
    Tro Q = L;
    while (Q->next != NULL)
      Q = Q->next;
    Q->next = P;
  }
}

void showList(Tro L)
{
  cout << setw(6) << "STT" << setw(10) << "Ma SV" << setw(20) << "Ho dem" << setw(15) << "Ten" << setw(10) << "Gioi tinh" << setw(10) << "Nam sinh" << setw(10) << "Diem TK" << endl;
  int i = 1;
  while (L != NULL)
  {
    cout << setw(6) << i << setw(10) << L->info.id << setw(20) << L->info.firstName << setw(15) << L->info.lastName << setw(10) << (L->info.gender ? "Nam" : "Nu") << setw(10) << L->info.year << setw(10) << L->info.score << endl;
    i++;
    L = L->next;
  }
}

void shift(Tro &L)
{
  if (L == NULL)
    return;
  Tro Q = L;
  L = L->next;
  delete Q;
}

void insert(Tro &L, int index, Student s)
{
  if (L == NULL)
    return;
  Tro M, Q = L;
  while (index > 1 && Q != NULL)
  {
    index--;
    M = Q;
    Q = Q->next;
  }
  Tro P = new Node;
  P->info = s;
  P->next = M->next;
  M->next = P;
}

void selectionSort(Tro &L)
{
  Tro M, Q, R = L;
  while (R->next != NULL)
  {
    Q = R->next;
    M = R;
    while (Q != NULL)
    {
      if (strcmp(M->info.lastName, Q->info.lastName) > 0)
        M = Q;
      Q = Q->next;
    }
    Student tmp = R->info;
    R->info = M->info;
    M->info = tmp;
    R = R->next;
  }
}

int main()
{
  Tro L = NULL;
  Student s1 = createStudent("SV1001", "Tran Van", "Thanh", true, 1999, 7.5);
  Student s2 = createStudent("SV1002", "Nguyen Thi", "Huong", false, 2000, 7.3);
  Student s3 = createStudent("SV1003", "Nguyen Van", "Binh", true, 1998, 6.4);
  Student s4 = createStudent("SV1004", "Bui Thi", "Hong", false, 2000, 5.8);
  Student s5 = createStudent("SV1005", "Duong Van", "Giang", true, 2998, 8.3);
  append(L, s1);
  append(L, s2);
  append(L, s3);
  append(L, s4);
  append(L, s5);
  showList(L);
  shift(L);
  showList(L);
  Student s6 = createStudent("SV1006", "Le Thi", "Doan", 0, 1998, 7.6);
  insert(L, 3, s6);
  showList(L);
  selectionSort(L);
  showList(L);
  return 0;
}