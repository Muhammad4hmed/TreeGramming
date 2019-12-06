#include "decisiontree.h"
#include <string.h>
#include <QQueue>
#include <string>
#include "ui_decisiontree.h"
#include <QInputDialog>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

QGraphicsScene *scene;

class Node {
public:
    QGraphicsTextItem *name;
    int age ;
    QGraphicsTextItem *gender;
    Node *leftChild , *rightChild , *next = NULL , *prev;
    Node( std::string n , std::string gender, int a , Node *leftChild , Node *rightChild , Node *p) {
        name = new QGraphicsTextItem (QString::fromStdString( n ) ) ;
        next = NULL;
        prev = p ;
        age = a;
        this->gender = new QGraphicsTextItem( QString::fromStdString( gender ) ) ;
        this->leftChild = leftChild ;
        this->rightChild = rightChild ;
    }
};

class Tree {
public :
    int x = 0 , y = 0;
    int x1,y1;
    int M_Y_x , M_Y_y , M_O_x , M_O_y , F_Y_x , F_Y_y , F_O_x , F_O_y  ;
    Node *root = NULL ;
    Node *male , *female , *femaleYoung , * femaleOldage , *maleYoung , *maleOldage;
    void generateHeadTree( ){
        root = new Node("Person","-",-1,NULL,NULL,NULL);
        male = new Node( "Male", "-",-1,NULL,NULL,root);
        female = new Node( "Female", "-",-1,NULL,NULL,root);
        maleYoung = new Node( "Young", "-",-1,NULL,NULL,male);
        maleOldage = new Node( "Oldage", "-",-1,NULL,NULL,male);
        femaleYoung = new Node( "Young", "-",-1,NULL,NULL,female);
        femaleOldage = new Node( "Oldage", "-",-1,NULL,NULL,female);
        root->leftChild = male ;
        root->rightChild = female;
        male->leftChild = maleYoung;
        male->rightChild = maleOldage;
        female->leftChild = femaleYoung;
        female->rightChild = femaleOldage;
        scene->addItem(root->name );
        x = 0 , x1 = 0 , y1 = 0 , y = 0;
        M_Y_x = 0, M_Y_y = 0, M_O_x = 0, M_O_y = 0, F_Y_x = 0 , F_Y_y = 0, F_O_x = 0, F_O_y = 0 ;
         root->name->setPos( x - 20, y-100);
         y += 20;
        scene->addLine( x , y-100 , x - 180 , y  );
        scene->addLine( x , y-100 , x + 180 , y  );
        y += 50;
        scene->addItem(male->name);
        male->name->setPos( x - 195, y-50);
        x1=x;
        x1 += 300;
        y1=y;
        y+=20;
        y1 += 10;
        x-=80;
        scene->addItem(maleYoung->name);
        maleYoung->name->setPos( x -230, y);
        scene->addLine(x - 230 + 20 , y + 20 , x - 230 + 20, y + 80 );
        M_Y_x = x - 230 ;
        M_Y_y = y + 100 ;
        // scene->addLine(x + 20 , y + 20 , x + 20, y + 80 );
        scene->addLine(x - 100,y - 50 ,x-200 ,y);
        scene->addItem(maleOldage->name);
        maleOldage->name->setPos( x+25, y);
        scene->addLine(x-100,y - 50 ,x+25,y);
        scene->addLine(x + 25+20 , y + 20 , x + 25+20, y + 80 );
        M_O_x = x + 25 ;
        M_O_y = y + 100 ;
        scene->addItem(female->name);
        female->name->setPos( x1 + 170 - 300 , y1-60);
        scene->addItem(femaleYoung->name);
        femaleYoung->name->setPos( x1 -230, y1+10);
        scene->addLine(x1 - 110,y1 - 40 ,x1-200 ,y1+10);
        scene->addLine(x1 - 230+20 , y1 + 30 , x1 - 230+20, y1 + 90);
        F_Y_x = x1 - 230 ;
        F_Y_y = y1 + 110 ;
        scene->addItem(femaleOldage->name);
        femaleOldage->name->setPos( x1+10, y1+10);
        scene->addLine(x1-110,y1-40 ,x1+15,y1+10);
        scene->addLine(x1+10+20,y1 + 30,x1+10+20,y1 + 90);
        F_O_x = x1 + 10 ;
        F_O_y = y1 + 110 ;
     }
    std::string decodeString( std::string gender ) {
        if( gender.size() == 1 ) {
            std::transform(gender.begin(), gender.end(), gender.begin(),
                [](unsigned char c){ return std::tolower(c); });
            return gender ;
        }
        std::string s = "";
        for( int i = 0 ; i < gender.size() ; i ++ ) {
            if( gender[ i ] == 32 ) continue ;
            else {
                if( gender[ i ] >= 'a' ) s += gender[ i ];
                else s += gender[ i ] + 'A' ;
            }
        }
        return s ;
    }
    void addNode( std::string s , std::string gender , int age ) {
        gender = decodeString( gender );
        Node *n = root , *p = root;
        if( gender == "male" || gender == "m" ) n = n->leftChild ;
        else n = n->rightChild ;
        if( age <= 30 ) n = n->leftChild ;
        else n = n->rightChild ;
        p = n ;
        bool flag = 0 ;
        if( p->next ) flag = 1;
        while( n != NULL && n->age < age ) p = n , n = n->next;
        Node *newNode = new Node( s , gender , age , NULL , NULL , p);
        newNode->next = n;
        p->next = newNode ;
        if( n ) n->prev = newNode ;
        scene->addItem( newNode->name );
        if( gender == "m" || gender == "male") {
            if( age <= 30 ) {
                newNode->name->setPos(M_Y_x,M_Y_y);
                M_Y_y += 20;
            } else {
                newNode->name->setPos(M_O_x,M_O_y);
                M_O_y += 20;
            }
        } else {
            if( age <= 30 ) {
                newNode->name->setPos(F_Y_x,F_Y_y);
                F_Y_y += 20;
            } else {
                newNode->name->setPos(F_O_x,F_O_y);
                F_O_y += 20;
            }
        }
    }
};

Tree t;

void AddNode( ) {
    std::string name , gender;
    int age ;
    bool ok , goodToGo;
    QString text = QInputDialog::getText(0 , "Enter Name ", "Name: ",QLineEdit::Normal, "", &ok );
    if( ok && !text.isEmpty() ) {
        name = text.toStdString() ;
    }
    text = QInputDialog::getText(0 , "Enter Age ", "Age: ",QLineEdit::Normal, "", &ok );
    if( ok && !text.isEmpty() ) {
        age = text.toInt();
        ok = true;;
    }
    text = QInputDialog::getText(0 , "Enter Gender ", "Gender: ",QLineEdit::Normal, "", &ok );
    if( ok && !text.isEmpty() ) {
        gender = text.toStdString();
        goodToGo = true ;
    }

    if( goodToGo ) t.addNode( name , gender , age );
}
void blackAll( Node *root ) {
    if( root != NULL ) {
        blackAll( root->leftChild );
        blackAll( root->rightChild );
        blackAll( root->next );
        root->name->setDefaultTextColor( Qt::black );
    }
}
void SearchNode() {
    blackAll( t.root );
    bool ok = 0 ;
    std::string name1;
    QGraphicsTextItem *name;
    QString text = QInputDialog::getText(0 , "Enter name to search " ,"Name: " ,QLineEdit::Normal , "" , &ok);
    if( ok && !text.isEmpty() ) {
        Node *n = t.root ;
        name1 = text.toStdString();
        // using bfs to search
        name = new QGraphicsTextItem( QString::fromStdString( name1 ) )  ;
        QQueue<Node*> q;
        q.enqueue( n );
        while( !q.isEmpty() ) {
            Node *tt = q.front();
            tt->name->setDefaultTextColor( Qt::black );
            q.dequeue();
            if( tt->leftChild ) q.enqueue( tt->leftChild );
            if( tt->rightChild ) q.enqueue( tt->rightChild );
            if( tt->next ) q.enqueue( tt->next );
            if( tt->name->toPlainText() == name->toPlainText() ) {
                Node *temp = tt;
                temp->name->setDefaultTextColor( Qt::red );
                while( temp != t.maleOldage && temp != t.maleYoung && temp != t.femaleYoung && temp != t.femaleOldage ) temp = temp->prev;
                while( temp != NULL ) {
                    temp->name->setDefaultTextColor( Qt::red );
                    temp = temp->prev ;
                }
            }
        }
    }
}
void ClearTree() {
    scene->clear();
    t.generateHeadTree();
}
DecisionTree::DecisionTree(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DecisionTree)
{
    ui->setupUi(this);
    setFixedSize( width() , height() );
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    t.generateHeadTree();
}
DecisionTree::~DecisionTree()
{
    delete ui;
}

void DecisionTree::on_pushButton_3_clicked()
{
    AddNode();
}

void DecisionTree::on_pushButton_2_clicked()
{
    SearchNode();
}

void DecisionTree::on_pushButton_clicked()
{
    ClearTree();
}
