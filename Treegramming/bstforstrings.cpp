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

class Node{
    public:
        std::string key;
        Node *left;
        Node *right;
        int x, y;
        QGraphicsTextItem* vnode;
        QGraphicsLineItem* pline;
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

        void highlightNode() {
            vnode->setDefaultTextColor(Qt::red);
        }

        void unhighlightNode() {
            vnode->setDefaultTextColor(Qt::black);
        }

        void addTextToScene(std::string e) {
            vnode = new QGraphicsTextItem(QString::fromStdString(e));
            vnode->setPos(x, y);
            scene->addItem(vnode);
        }

        void removeText() {
            if (vnode != nullptr){
                delete vnode;
                vnode = nullptr;
            }
        }

        void connectLineToParent(Node* p)
        {
            pline = scene->addLine(QLineF(p->x+20, p->y+20, x, y));
        }

        void removeLine() {
            if (pline != nullptr) {
                delete pline;
                pline = nullptr;
            }
        }

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

    void insert(std::string e, Node* p = nullptr) {
        if(head == nullptr) {
            head = new Node(e, 0, 0, scene);
            head->addTextToScene(e);
        } else {
            if (p == nullptr)
                p = head;
            if (e >= p->key) {
                if (p->right == nullptr) {
                    p->right =  new Node(e, p->x+100, p->y+80, scene);
                    p->right->connectLineToParent(p);
                    p->right->addTextToScene(e);
                }
                else {
                    p->right->displaceVisualNodeByFactor(p, 1.5);
                    insert(e, p->right);
                }
            }
            else if(e < p->key) {
                if (p->left == nullptr) {
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

    bool searchNode(std::string e) {
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
        addButton->setStyleSheet("background-color: rgb(255, 35, 6); color: rgb(255, 255, 255);");
        searchButton->setStyleSheet("background-color: rgb(255, 35, 6); color: rgb(255, 255, 255);");
        clearButton->setStyleSheet("background-color: rgb(255, 35, 6); color: rgb(255, 255, 255);");

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
