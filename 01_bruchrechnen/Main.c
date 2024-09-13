#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

struct bruch {
  int zaehler;
  int nenner;
};

void input(struct bruch* eingabe, int i) {
  printf("\n%d).Bruch:\n", i + 1);
  printf("Zähler:");
  scanf_s("%d", &eingabe->zaehler);
  printf("\nNenner:");
  scanf_s("%d", &eingabe->nenner);
  printf("");
  printf("(%d/%d)\n\n", eingabe->zaehler, eingabe->nenner);
}

void berechnung(struct bruch* bruch1, struct bruch* bruch2, int op) {
  struct bruch ergebnis;
  switch (op) {
  case '+':
    ergebnis.zaehler = bruch1->zaehler * bruch2->nenner + bruch2->zaehler * bruch1->nenner;
    ergebnis.nenner = bruch1->nenner * bruch2->nenner;
    printf("(%d/%d)+(%d/%d)=(%d/%d)", bruch1->zaehler, bruch1->nenner, bruch2->zaehler, bruch2->nenner, ergebnis.zaehler, ergebnis.nenner);
    break;

  case '-':
    ergebnis.zaehler = bruch1->zaehler * bruch2->nenner - bruch2->zaehler * bruch1->nenner;
    ergebnis.nenner = bruch1->nenner * bruch2->nenner;
    printf("(%d/%d)-(%d/%d)=(%d/%d)", bruch1->zaehler, bruch1->nenner, bruch2->zaehler, bruch2->nenner, ergebnis.zaehler, ergebnis.nenner);
    break;

  case '*':
    ergebnis.zaehler = bruch1->zaehler * bruch2->zaehler;
    ergebnis.nenner = bruch1->nenner * bruch2->nenner;
    printf("(%d/%d)*(%d/%d)=(%d/%d)", bruch1->zaehler, bruch1->nenner, bruch2->zaehler, bruch2->nenner, ergebnis.zaehler, ergebnis.nenner);
    break;

  case ':':
    ergebnis.zaehler = bruch1->zaehler * bruch2->nenner;
    ergebnis.nenner = bruch1->nenner * bruch2->zaehler;
    printf("(%d/%d):(%d/%d)=(%d/%d)", bruch1->zaehler, bruch1->nenner, bruch2->zaehler, bruch2->nenner, ergebnis.zaehler, ergebnis.nenner);
    break;

  }
}

int main() {
  SetConsoleOutputCP(1252);
  SetConsoleCP(1252);
  struct bruch brueche[2];
  char c;

  do {

    printf("Brüche eingeben:\n");
    for (int i = 0; i < 2; i++) {
      input(&brueche[i], i);
    }

    char op;
    printf("Möchtest du (+, -, *, :)?\n");
    op = _getch();
    printf("");
    berechnung(&brueche[0], &brueche[1], op);

    printf("\nnoch einmal?(j/n)\n");
    c = _getch();
    system("cls");
  } while (c == 'j');
  return 0;
};