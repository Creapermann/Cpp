#include <iostream>
#include <memory>
#include <queue>


class Node
{
public:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    int data;

    Node(int d)
        : data{d}
    {
    }
};


void createBinaryTree(std::shared_ptr<Node>& root)
{
    std::queue<std::shared_ptr<Node>> queue;
    queue.push(root);


    while (!queue.empty())
    {
        std::cout << "Data for left-child of: " << queue.front()->data << ", -1 for none: ";
        int input;
        std::cin >> input;

        if (input != -1)
        {
            std::shared_ptr<Node> temp_node(std::make_shared<Node>(input));
            queue.front()->left = temp_node;
            queue.push(temp_node);
        }

        std::cout << "Data for right-child of: " << queue.front()->data << ", -1 for none: ";
        std::cin >> input;

        if (input != -1)
        {
            std::shared_ptr<Node> temp_node(std::make_shared<Node>(input));
            queue.front()->right = temp_node;
            queue.push(temp_node);

        }

        system("CLS");

        queue.pop();
    }
}




int main()
{
    std::shared_ptr<Node> root(std::make_shared<Node>(5));
    createBinaryTree(root);


    std::cin.get();
}

