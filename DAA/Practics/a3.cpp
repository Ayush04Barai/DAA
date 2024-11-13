#include<bits/stdc++.h>
using namespace std ;
class Node {
    public :
    int freq ;
    char ch = '$';
    Node * left , * right;
    Node (int f ){
        freq = f;
        left = right = NULL;
    }
    Node (char c, int f ){
        ch = c ;
        freq = f;
        left = right = NULL;
    }
};
class cmp {
    public :
    bool operator ()(Node * a , Node * b){
        return a->freq > b->freq;
    }
};
void traverse(Node * root , string s)
{
    if (!root->left && !root->right){
        cout << root->ch << "->" << s << endl ;
        return ;
    }
    traverse(root->left,s+'0');
    traverse(root->right,s+'1');
}
void HuffMancode(vector<Node*> arr , int n){
    priority_queue <Node* , vector <Node *> , cmp> pq;
    for (int i = 0 ; i < n ; i++){
        pq.push(arr[i]);
    }

    while (pq.size() > 1){
        Node * l = pq.top();
        pq.pop();
        Node * r = pq.top();
        pq.pop();

        Node * newNode = new Node(l->freq + r->freq);
        newNode->left = l;
        newNode->right = r;
        pq.push(newNode);
    }
    Node * root = pq.top();
    pq.pop();
    string s = "";
    cout << "HUFFMUN ENCODING " << endl ;
    traverse(root , s);
}
int main (){
    int n ;
    cout << "Enter No of charecter : ";
    cin >> n;
    vector<Node *> arr(n);
    cout << "Enter character,frequency ( char , freq ) : ";
    for (int i = 0 ; i < n ; i++){
        int freq ;
        char ch;
        cin >> ch >> freq;
        Node * node = new Node(ch,freq);
        arr[i]=node;
    }

    HuffMancode (arr , n);

}


/*
OUTPUT ::

Enter No of charecter : 8
Enter character,frequency ( char , freq ) : z 2
k 7
m 24
c 32
u 37
d 42
l 42
e 120
HUFFMUN ENCODING
e->0
u->100
l->101
d->110
c->1110
z->111100
k->111101
m->11111

*/