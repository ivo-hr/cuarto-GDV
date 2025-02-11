
//Enrique Juan Gamboa
//51547377F


/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Esta implementación utiliza smart pointers para prevenir
 * fugas de memoria y problemas con la destrucción.
 */

#ifndef __BINTREE_H
#define __BINTREE_H

#include <cassert>
#include <iostream>
#include <memory>
using namespace std;

template <class T> class BinTree {
public:
  BinTree() : root_node(nullptr) {}

  BinTree(const T &elem)
      : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

  BinTree(const BinTree &left, const T &elem, const BinTree &right)
      : root_node(std::make_shared<TreeNode>(left.root_node, elem,
                                             right.root_node)) {}

  bool empty() const { return root_node == nullptr; }

  const T &root() const {
    assert(root_node != nullptr);
    return root_node->elem;
  }

  BinTree left() const {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->left;
    return result;
  }

  BinTree right() const {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->right;
    return result;
  }

  void display(std::ostream &out) const { display_node(root_node, out); }

private:
  // Las definiciones de TreeNode y NodePointer dependen recursivamente
  // la una de la otra. Por eso declaro 'struct TreeNode;' antes de NodePointer
  // para que el compilador sepa, cuando analice la definición de NodePointer,
  // que TreeNode va a ser definida más adelante.

  struct TreeNode;
  using NodePointer = std::shared_ptr<TreeNode>;

  struct TreeNode {
    TreeNode(const NodePointer &left, const T &elem, const NodePointer &right)
        : elem(elem), left(left), right(right) {}

    T elem;
    NodePointer left, right;
  };

  NodePointer root_node;

  static void display_node(const NodePointer &root, std::ostream &out) {
    if (root == nullptr) {
      out << ".";
    } else {
      out << "(";
      display_node(root->left, out);
      out << " " << root->elem << " ";
      display_node(root->right, out);
      out << ")";
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const BinTree<T> &tree) {
  tree.display(out);
  return out;
}

BinTree<int> read_tree(std::istream &in) {
  int c;
  in >> c;
  if (c == -1) {
    return BinTree<int>();
  } else {
    BinTree<int> left = read_tree(in);
    BinTree<int> right = read_tree(in);
    BinTree<int> result(left, c, right);
    return result;
  }
}

#endif


//Coste lineal O(n), ya que se exploran todos los nodos del árbol
int aguas(BinTree<int> const& arbol, int& naveg) {

    if (arbol.empty()) {
        return 0;
    }
    if (arbol.left().empty() && arbol.right().empty())
        return 1 - arbol.root();

    int tramoIzq = aguas(arbol.left(), naveg);
    int tramoDer = aguas(arbol.right(), naveg);
    
    if (tramoIzq > 2) naveg++;
    if (tramoDer > 2) naveg++;

    int caudalAct = tramoIzq + tramoDer - arbol.root();

    if (caudalAct < 0)
        caudalAct = 0;

    return caudalAct;
}

void resuelveCaso() {
    auto arbol = read_tree(cin);


    int navegables = 0;
    aguas(arbol, navegables);


    std::cout << navegables << '\n';
}

int main() {
  int casos;
  cin >> casos;
  while (casos--) {
    resuelveCaso();
  }
  return 0;
}



//Enrique Juan Gamboa
//51547377F