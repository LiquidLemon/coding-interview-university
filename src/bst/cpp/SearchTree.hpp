#include <ostream>
#include <exception>

#ifndef _SEARCH_TREE_HPP
#define _SEARCH_TREE_HPP

// it's not balanced
template <typename T>
class SearchTree {
  public:
    class ValueNotFound : public std::exception {
      virtual const char* what() const throw() {
        return "ValueNotFound";
      }
    };

    SearchTree() : root(nullptr) {}

    virtual ~SearchTree() {
      delete_tree();
    }

    void insert(T value) {
      if (root) {
        root->insert(value);
      } else {
        root = new Node(value);
      }
    }

    // should this rather be unsigned or size_t?
    int get_node_count() {
      return root ? 1 + root->countChildren() : 0;
    }

    // tempting to create BFS and DFS iterators
    void print_values(std::ostream *stream) {
      if (root) {
        root->print(stream);
      }
    }

    // should this just empty the tree?
    void delete_tree() {
      if (root) {
        delete root;
        root = nullptr;
      }
    }

    bool is_in_tree(T value) {
      if (root) {
        return root->contains(value);
      }
      return false;
    }

    // TODO: implement
    int get_height();

    struct search_result {
      bool success;
      T value;
    };

    // should assert that T can be ordered
    search_result get_min() {
      search_result result;
      if (root) {
        result.success = true;
        result.value = root->getMin();
      } else {
        result.success = false;
      }
      return result;
    }

    search_result get_max() {
      search_result result;
      if (root) {
        result.success = true;
        result.value = root->getMax();
      } else {
        result.success = false;
      }
      return result;
    }

    void delete_value(T value) {
      if (root) {
        root->deleteValue(value, &root);
      } else {
        throw ValueNotFound();
      }
    }

    search_result get_successor(T value);

  private:
    struct Node {
      Node(T value) : value(value), lesser(nullptr), greater(nullptr) {}
      ~Node() {
        if (lesser) {
          delete lesser;
        }

        if (greater) {
          delete greater;
        }
      }

      T value;
      Node *lesser;
      Node *greater;

      void insert(T value) {
        if (value == this->value) {
          return;
        }

        if (value < this->value) {
          if (lesser) {
            lesser->insert(value);
          } else {
            lesser = new Node(value);
          }
        } else {
          if (greater) {
            greater->insert(value);
          } else {
            greater = new Node(value);
          }
        }
      }

      void deleteValue(T value, Node **rootPointer) {
        Node **edge = nullptr;
        Node *current = this;

        while (current->value != value) {
          if (value > current->value) {
            if (!current->greater) {
              throw ValueNotFound();
            }
            edge = &current->greater;
          } else {
            if (!current->lesser) {
              throw ValueNotFound();
            }
            edge = &current->lesser;
          }
          current = *edge;
        }

        if (edge == nullptr) {
          edge = rootPointer;
        }
        // leaf node
        if (current->lesser && !current->greater) {
          *edge = current->lesser;
          current->lesser = nullptr;
          delete current;
        } else if (current->greater && !current->lesser) { // single branch
          *edge = current->greater;
          current->greater = nullptr;
          delete current;
        } else if (!(current->lesser && current->greater)) {
          *edge = nullptr;
          delete current;
        } else { // both branches
          T minGreater = current->greater->getMin();
          current->value = minGreater;
          current->greater->deleteValue(minGreater, &current->greater);
        }
      }

      int countChildren() {
        int count = 0;
        if (lesser) {
          count++;
          count += lesser->countChildren();
        }

        if (greater) {
          count++;
          count += greater->countChildren();
        }
        return count;
      }

      void print(std::ostream *stream) {
        if (lesser) {
          lesser->print(stream);
        }

        *stream << value << " ";

        if (greater) {
          greater->print(stream);
        }
      }

      bool contains(T value) {
        if (this->value == value) {
          return true;
        }

        return (lesser && lesser->contains(value))
            || (greater && greater->contains(value));
      }

      T getMin() {
        return lesser ? lesser->getMin() : value;
      }

      T getMax() {
        return greater ? greater->getMax() : value;
      }
    };

    Node *root;
};

#endif
