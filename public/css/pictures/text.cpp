#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
class Huffman_Codes{
  struct Node{
    char dt;
    size_t fq;
    Node* left;
    Node* right;
    Node(char dt, size_t fq) : dt(dt),
    fq(fq),
    left(NULL),
    right(NULL)
    {}
    ~Node(){
      delete left;
      delete right;
    }
  };
struct compare{
  bool operator()(Node* l, Node* r){
    return (l->fq > r->fq);
  }
};
Node* top;
void print_Code(Node* root, string str){
  if(root == NULL)
    return;
  if(root->dt == '$'){
    print_Code(root->left, str + "0");
    print_Code(root->right, str + "1");
  }
  if(root->dt != '$'){
    cout << root->dt <<" : " << str << "\n";
    print_Code(root->left, str + "0");
    print_Code(root->right, str + "1");
  }
}
public:
  Huffman_Codes() {};
    ~Huffman_Codes(){
      delete top;
    }
    void Generate_tree(vector<char>& dt, vector<size_t>& fq, size_t size){
      Node* right;
      Node* left;
      priority_queue<Node*, vector<Node*>, compare > minHeap;
      for(size_t i = 0; i < size; ++i){
      minHeap.push(new Node(dt[i], fq[i]));
    }
    while(minHeap.size() != 1){
      left = minHeap.top();
      minHeap.pop();
      right = minHeap.top();
      minHeap.pop();
      top = new Node('$', left->fq + right->fq);
      top->left = left;
      top->right = right;
      minHeap.push(top);
    }
    print_Code(minHeap.top(), "");
  }
};
int main(){
  int n, f;
  char ch;
  Huffman_Codes set1;
  vector<char> dt;
  vector<size_t> fq;
  cout<<"Enter the number of elements \n";
  cin>>n;
  cout<<"Enter the characters \n";
  for (int i=0;i<n;i++){
    cin>>ch;
    dt.insert(dt.end(), ch);
  }
  cout<<"Enter the fquencies \n";
  for (int i=0;i<n;i++){
    cin>>f;
    fq.insert(fq.end(), f);
  }
  size_t size = dt.size();
  set1.Generate_tree(dt, fq, size);
  return 0;
}
