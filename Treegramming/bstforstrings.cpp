#include "bstforstrings.h"
#include "ui_bstforstrings.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QDebug>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>
#include <QInputDialog>
#include <QLabel>
#include <string>

/*
 * this is the node used in BST
 * all drawing is done in this Node class
*/
class Node{
    public:
        // key is the element in the node which is a string
        std::string key;
        // left and right child
        Node *left;
        Node *right;
        // coordinates where we have to draw the node in the scene
        int x, y;
        // vnode is the text to be displayed in the scene
        QGraphicsTextItem* vnode;
        QGraphicsLineItem* pline;
        // we hold the reference of the scene where we will draw the lines and texts
        QGraphicsScene* scene;

        Node(std::string e, int xcoord, int ycoord, QGraphicsScene* scn) {
            key = e;
            left = nullptr;
            right = nullptr;
            x = xcoord;
            y = ycoord;
            scene = scn;
            pline = nullptr;
        }

        ~Node() {
            removeLine();
            removeText();
        }

        // set text color to red
        void highlightNode() {
            vnode->setDefaultTextColor(Qt::red);
        }

        // set text color to black
        void unhighlightNode() {
            vnode->setDefaultTextColor(Qt::black);
        }

        void addTextToScene(std::string e) {
            vnode = new QGraphicsTextItem(QString::fromStdString(e));
            vnode->setPos(x, y);
            scene->addItem(vnode); // adding text to scene
        }

        void removeText() {
            if (vnode != nullptr){
                delete vnode; // removing text from scene
                vnode = nullptr;
            }
        }

        void connectLineToParent(Node* p) // parent coords
        {
            pline = scene->addLine(QLineF(p->x+20, p->y+20, x, y)); // drawing line from child to parent.
        }

        void removeLine() {
            if (pline != nullptr) {
                delete pline;
                pline = nullptr;
            }
        }

        // once a node is moved, we need to displace its childs too
        void adjustNodesToNewLocation(Node* p) {
            if(p->left != nullptr) {
                p->left->removeLine();
                p->left->removeText();
                p->left->x = p->x-40;
                p->left->y = p->y+80;
                p->left->connectLineToParent(p);
                p->left->addTextToScene(p->left->key);
                adjustNodesToNewLocation(p->left);
            }
            if(p->right != nullptr) {
                p->right->removeLine();
                p->right->removeText();
                p->right->x = p->x+80;
                p->right->y = p->y+80;
                p->right->connectLineToParent(p);
                p->right->addTextToScene(p->right->key);
                adjustNodesToNewLocation(p->right);
            }
        }

        // for moving nodes so that they don't intersect each other
        void displaceVisualNodeByFactor(Node* p, double fact) {
            removeLine();
            removeText();
            x *= fact;
            addTextToScene(key);
            connectLineToParent(p);
            adjustNodesToNewLocation(this);
        }
};

class BST {
    Node* head;
    QGraphicsScene* scene;
    Node* lastSearchedNode;
    public:
    BST(QGraphicsScene* scn) {
        head = nullptr;
        lastSearchedNode = nullptr;
        scene = scn;
    }

    // simple BST insertion routine
    void insert(std::string e, Node* p = nullptr) {
        if(head == nullptr) {
            head = new Node(e, 0, 0, scene);
            head->addTextToScene(e);
        } else {
            if (p == nullptr) // if p is null, we pick head and start from there.
                p = head;
            if (e >= p->key) {
                if (p->right == nullptr) {
                    // we insert new child below current node, thats why we add +ve value to y axis
                    // we insert new child right to current node, thats why we add +ve value to x axis
                    p->right =  new Node(e, p->x+100, p->y+80, scene);
                    p->right->connectLineToParent(p); // joining parent and child with line
                    p->right->addTextToScene(e); // add text to scene
                }
                else {
                    p->right->displaceVisualNodeByFactor(p, 1.5);
                    insert(e, p->right);
                }
            }
            else if(e < p->key) {
                if (p->left == nullptr) {
                    // we insert new child below current node, thats why we add +ve value to y axis
                    // we insert new child left to the current node, thats why we add -ve value to x axis
                    p->left = new Node(e, p->x-60, p->y+80, scene);
                    p->left->connectLineToParent(p);
                    p->left->addTextToScene(e);
                }
                else {
                    p->left->displaceVisualNodeByFactor(p, 1.5);
                    insert(e, p->left);
                }
            }
        }
    }

    // simple BST search routine
    bool searchNode(std::string e) {
        // unhighlight previously highlighted node
        if (lastSearchedNode != nullptr) {
            lastSearchedNode->unhighlightNode();
        }
        Node* p = head;

        while(p != nullptr) {
            if(e > p->key)
                p = p->right;
            else if (e < p->key)
                p = p->left;
            else {
                lastSearchedNode = p;
                p->highlightNode();
                return true;
            }
        }
        return false;
    }

    // simple clear tree contents routine
    void clearTree() {
        clearTreeHelper(head);
        head = nullptr;
        lastSearchedNode = nullptr;
    }

    void clearTreeHelper(Node* p) {
        if(p == nullptr)
            return;
        clearTreeHelper(p->left);
        clearTreeHelper(p->right);
        delete p;
    }
};

BST* myTree;
QLabel* totalNodes;
int totalNodesCounter;

void addNodeAction() {
    bool ok;
    QString text = QInputDialog::getText(0, "Add Node Dialog",
                                         "String:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()) {
        totalNodesCounter++;
        totalNodes->setText(QString::fromStdString("Total Nodes: "+std::to_string(totalNodesCounter)));
        myTree->insert(text.toStdString());
    }
}

void searchNodeAction() {
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Search Node Dialog",
                                         "String:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()) {
        myTree->searchNode(text.toStdString());
    }
}

void clearTreeAction() {
    totalNodesCounter = 0;
    totalNodes->setText(QString::fromStdString("Total Nodes: "+std::to_string(totalNodesCounter)));
    myTree->clearTree();
}

BSTforStrings::BSTforStrings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BSTforStrings)
{
    ui->setupUi(this);
        QMainWindow* window = new QMainWindow();
        QWidget* windowWidget = new QWidget();
        QVBoxLayout* windowLayout = new QVBoxLayout();
        QWidget* buttonsWidget = new QWidget();
        QHBoxLayout* buttonsLayout = new QHBoxLayout();
        totalNodes = new QLabel();
        totalNodesCounter = 0;
        totalNodes->setText(QString::fromStdString("Total Nodes: "+std::to_string(0)));

        QGraphicsScene* scene = new QGraphicsScene();

        QGraphicsView* view = new QGraphicsView(scene);

        myTree = new BST(scene);


        QPushButton* addButton = new QPushButton("Add Node");
        QPushButton* searchButton = new QPushButton("Search Node");
        QPushButton* clearButton = new QPushButton("Clear Tree");

        QObject::connect(addButton, &QPushButton::released, addNodeAction);
        QObject::connect(searchButton, &QPushButton::released, searchNodeAction);
        QObject::connect(clearButton, &QPushButton::released, clearTreeAction);

        buttonsWidget->setLayout(buttonsLayout);
        buttonsLayout->addWidget(addButton);
        buttonsLayout->addWidget(searchButton);
        buttonsLayout->addWidget(clearButton);

        windowLayout->addWidget(totalNodes);
        windowLayout->addWidget(view);
        windowLayout->addWidget(buttonsWidget);
        windowWidget->setLayout(windowLayout);

        windowWidget->setMinimumSize(800, 400);
        window->setCentralWidget(windowWidget);
        char styleSheet[] = "background-color: rgb(255, 255, 255);"
                "color: rgb(0, 0, 0);"
                "font: 14pt \"Gill Sans Ultra Bold\"";
        window->setStyleSheet(styleSheet);
        window->show();
}

BSTforStrings::~BSTforStrings()
{
    delete ui;
}
