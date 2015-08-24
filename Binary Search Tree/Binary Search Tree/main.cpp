#include "bst.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    BST<int> bst;
    ofstream file("output.txt");
    
    cout << "is the bst empty? :   ";
    bst.isEmpty() ? cout << "Empty" : cout << "Not Empty";
    cout << endl;
    cout << endl;
    
    cout << "inserting data........." << endl;
    int items[10] = {4,9,2,7,3,11,17,0,5,1};
    
    for(int i = 0; i < 10; i++) bst.insert(items[i]);
    cout << endl;
    
    
    cout << "is the bst empty now? :   ";
    bst.isEmpty() ? cout << "Empty" : cout << "Not Empty";
    cout << endl;
    cout << endl;
    
    cout << "Tree in order :  ";
    bst.printInorder(file);
    file << "\n\n";
    cout << endl;
    cout << "Data has been printed to file\n" << endl;
    
    bst.postOrder(file);
    file << "\n\n";
    
    cout << "Finding 9 ......   ";
    bst.find(9) ? cout << "Element is found" : cout << "Element is not found";
    cout << endl;
    cout << endl;
    
    
    cout << "Finding 13 ......   ";
    bst.find(13) ? cout << "Element is found" : cout << "Element is not found";
    cout << endl;
    cout << endl;
    
    
    
    cout << "\t\t============= task # 1.1 =============\n" << endl;
    BST<int> t2;
    
    int data[9] = {8,3,1,6,4,7,13,14,10};
    for(int i = 0; i < 9; i++) t2.insert(data[i]);
    
    cout << "Number of leaves in t2 is : " << t2.numLeaves() << endl;
    cout << endl;
    
    
    cout << "\t\t============= task # 1.2 =============\n" << endl;
    
    cout << "Minimum element in t2 is : " << t2.findMin() << endl;
    cout << endl;
    
    
    cout << "\t\t============= task # 2 =============\n" << endl;
    BST<int> t3;
    
    int data2[9] = {5,2,-4,3,12,9,21,19,25};
    for(int i = 0; i < 9; i++) t3.insert(data2[i]);
    
    t3.printInorder(file);
    cout << "Data has been printed to file" << endl;
    file << "\n\n";
    
    t3.remove(-4);
    t3.printInorder(file);
    file << "\n\n";
    
    t3.remove(12);
    t3.printInorder(file);
    file << "\n\n";
    
    file.close();
    
    
    cout << "\t\t============= task # 2.1 =============\n" << endl;
    
    cout << "Max Depth of t3 : " << t3.maxDepth() << endl;
    
    
    cout << "\t\t============= task # 2.1 =============\n" << endl;
    
    cout << "Printpath : " << endl;
    
    t3.printPaths();
    
    cout << endl;
    cout << endl;
    
    
    cout << "Lenghth of the tree is : " << t3.lengthIs() << endl;
    
    
    return 0;
}
