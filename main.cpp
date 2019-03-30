#include <iostream>
#include <cstdlib>

#include "Tree.cpp"

using namespace std;

int main(){

  int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
  ariel::Tree myTree;
  int input = 0;

  cout << "print the tree\nBefore adding numbers\n";
  myTree.print();

  for(int i=0; i<16; i++){
    myTree.insert(TreeKeys[i]);
  }

  cout << "print the tree\nAfter adding numbers\n";
  myTree.print();

  cout << endl;

  cout << "The smallest value in the tree is " << myTree.findSmallest() << endl;

  cout << "Enter a key value to delete. enter -1 to stop the process\n";
  while(input != -1){
    cout << "Delete node: ";
    cin >> input;
    {
      if(input != -1){
        cout << endl;
        myTree.removeData(input);
        myTree.print();
        cout << endl;
      }
    }
  }




  return 0;
}
