#include <iostream>
#include <fstream>
#include <vector>
#include <list>

class Node
{
public:
    int frequency;
    int id;
    Node* left;
    Node* right;

    Node(int id, int frequency, Node* left, Node* right)
    {
        this->id = id;
        this->frequency = frequency;
        this->left = left;
        this->right = right;
    }
};

class Huffman
{
private:
    std::vector<Node*> nodes;
    std::vector<std::string> codes;
    int id = 0;

private:
    static int search(const std::vector<Node*>& arr, int value)
    {
        int i = 0;
        while (i < arr.size() && arr[i]->frequency >= value)
            ++i;
        return i;
    }

    void readTree(Node* root, const std::string& code)
    {
        if (root->id >= 0)
            codes[root->id] = code;
        else
        {
            readTree(root->left, code + '1');
            readTree(root->right, code + '0');
        }
        delete root;
    }

public:
    void build()
    {
        while (nodes.size() != 1)
        {
            Node* r = nodes[nodes.size() - 1];
            nodes.erase(--nodes.end());
            Node* l = nodes[nodes.size() - 1];
            nodes.erase(--nodes.end());
            int sum = l->frequency + r->frequency;
            int index = search(nodes, sum);
            nodes.insert(nodes.begin() + index, new Node(-1, sum, l, r));
        }
        readTree(nodes[0], "");
    }

    void addChance(int chance)
    {
        nodes.push_back(new Node(id++, chance, nullptr, nullptr));
        codes.emplace_back();
    }

    std::string get(int i)
    {
        return codes[i];
    }

    ~Huffman() = default;
};


int main()
{

    int n;
    Huffman* huff = new Huffman();
    std::fstream fin;
    fin.open("input.txt", std::ios::in);
    if (fin.is_open())
    {
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            fin >> x;
            huff->addChance(x);
        }

        fin.close();

        huff->build();
        std::fstream fout;
        fout.open("output.txt", std::ios::out);
        for (int i = 0; i < n; i++)
        {
            fout << huff->get(i) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        delete huff;

    }

    return 0;

}

