#include <vector>
template <typename T>

class treenode{
    public:
    T data;
    vector<treenode*> children;

    treenode(int data){
        this->data = data;
    }
};