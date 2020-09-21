#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
  tree t = createNullTree();
  t = readData(t,"address.txt");
  return 0;
}
