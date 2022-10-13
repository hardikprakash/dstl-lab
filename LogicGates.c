#include <stdio.h>

int input[4][4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int OR(int A, int B)
{
  if (A || B)
  {
    return 1;
  }
  return 0;
}

int AND(int A, int B)
{
  if (A && B)
  {
    return 1;
  }
  return 0;
}

int XOR(int A, int B)
{
  if (A != B)
  {
    return 1;
  }
  return 0;
}

int XNOR(int A, int B)
{
  if (A == B)
  {
    return 1;
  }
  return 0;
}

int NOR(int A, int B)
{
  if (!A || !B)
  {
    return 1;
  }
  return 0;
}

void main()
{
  int A = 0, B = 0;
  int choice = 0;
  printf("1.OR\n2.AND\n3.XOR\n4.XNOR\n5.NOR\nChoose a Logic Gate: ");
  scanf("%d", &choice);

  // printf("Enter input A: ");
  // scanf("%d", &A);
  // printf("Enter input B: ");
  // scanf("%d", &B);


  printf("A\tB\tO/P\n");
  switch (choice)
  {
  case 1:
    for (int i = 0; i < 4; i++)
    {
      printf("%d\t%d\t%d\n", input[i][0], input[i][1], OR(input[i][0], input[i][1]));
    }
    break;
  case 2:
    for (int i = 0; i < 4; i++)
    {
      printf("%d\t%d\t%d\n", input[i][0], input[i][1], AND(input[i][0], input[i][1]));
    }
    break;
  case 3:
    for (int i = 0; i < 4; i++)
    {
      printf("%d\t%d\t%d\n", input[i][0], input[i][1], XOR(input[i][0], input[i][1]));
    }
    break;
  case 4:
    for (int i = 0; i < 4; i++)
    {
      printf("%d\t%d\t%d\n", input[i][0], input[i][1], XNOR(input[i][0], input[i][1]));
    }
    break;
  case 5:
    for (int i = 0; i < 4; i++)
    {
      printf("%d\t%d\t%d\n", input[i][0], input[i][1], NOR(input[i][0], input[i][1]));
    }
    break;
  default:
    break;
  }
}