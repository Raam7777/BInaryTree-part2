namespace ariel {
  class Tree {

  private:
    struct node {
      int data;
      struct node *left, *right;
    };

    node *T_root;
    void insertNode(int i, node* ptr);
    void printInOrder(const struct node *root);
    void removeNode(int i, node *ptr);
    void removeRootMatch();
    void removeMatch(node* parent, node* match, bool left);
    int findSmallestNode(node* ptr);
    int T_size(node* n);
    node *contains_node(int i, node* n);
    int find_parent(int i, node* n);
    //void remove_Tree(node* n);


  public:

    Tree();
  //  ~Tree();
    node *createLeaf(int i);
    void insert(int i);
    int findSmallest();
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();

  };
}
