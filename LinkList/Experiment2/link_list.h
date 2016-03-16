//
//  link_list.h
//  Experiment2
//
//  Created by JacobLan on 16/3/15.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef link_list_h
#define link_list_h

const int ERROR = -1;
const int SUCCESS = 0;

#include "node.h"				// 结点类模板
using namespace std;
// 简单线性链表类模板
template <class MyType>
class LinkList
{
private:
    Node<MyType> *pHead;		// 头结点指针
    Node<MyType> *pTail;      //尾节点
    Node<MyType> *CurPoint;     //当前指针
    int CurPosition;
    int length;     //当前链表中的元素个数
    
public:
    //线性链表方法声明:
    void Init();	// 初始化线性表
    void CreateList( MyType num);
    void Clear();	// 将线性表清空
    void DestoryList();   // 销毁线性表
    int Length();		// 求线性表长度
    bool Empty();	// 判断线性表是否为空
    int SetElem(int position, MyType e);
    int GetElem(int position, MyType &e);
    int  Locate(MyType  e);
    int Insert(int position, MyType e);// 插入元素
    int Delete (int position, MyType &e);
    void Traverse();
    int  GetPrior(MyType e, MyType &x);
    int GetNext(MyType e, MyType &x);
    Node<MyType> *GetElemPtr(int position) ;
};
// 单链表类模板的实现部分

template <class MyType>
int LinkList<MyType>::Delete(int position, MyType &e) {
    if (position < 1) {
        cout << "---Get Position Error---";
        return ERROR;
    }
    Node<MyType> *temPoint = new Node<MyType>;
    temPoint = temPoint->pNext;
    
    if (position > CurPosition){
        temPoint = CurPoint;
        for (int i = CurPosition; i != position; i++) {
            temPoint = temPoint->pNext;
        }
    }
    else
    {
        for (int i = 1; i != position; i++) {
            temPoint = temPoint->pNext;
        }
    }
    
    //此时curpoint指向待删除节点的前一节点
    Node<MyType> *p = CurPosition;      //p指向待删除的变量
    CurPoint = CurPoint->pNext->pNext;
    CurPosition++;
    e = p->data;
    delete p;

}



template <class Mytype>
int LinkList<Mytype>::Insert(int position, Mytype e) {
    if (position < 1) {
        cout << "---Get Position Error---";
        return ERROR;
    }
    Node<Mytype> *temPoint = new Node<Mytype>;
    
    if (position > CurPosition)
    {
        temPoint = CurPoint;
        for (int i = CurPosition; i != position ; i++) {
            temPoint = temPoint->pNext;
        }
        
        CurPosition = position-1;
        CurPoint = temPoint;
        temPoint->data = e;
        temPoint->pNext = nullptr;
        temPoint->pNext = CurPoint->pNext;
        CurPoint->pNext = temPoint;
        return SUCCESS;
    }
    else
    {
        
        temPoint = pHead->pNext;
        for (int i = 1; i != position; i++) {
            temPoint = temPoint->pNext;
        }
        
        CurPoint = temPoint;
        temPoint = new Node<Mytype>;
        temPoint->data = e;
        temPoint->pNext = CurPoint->pNext;
        CurPoint->pNext = temPoint;
        CurPosition = position-1;
        return SUCCESS;
        
    }

}


template <class MyType>
int LinkList<MyType>::Locate(MyType  e) {
    Node<MyType> *temPoint = nullptr;
    temPoint = pHead->pNext;
    int count = 1;
    while (temPoint != nullptr && temPoint->data != e ) {
        temPoint = temPoint->pNext;
        count++;
    }
    if (temPoint == nullptr)
    {
        cout << "---Can't Find This Item---" << endl;
        return -1;
    }
    CurPoint = temPoint;
    CurPosition = count++;
    return count;
}




template <class MyType>
void LinkList<MyType>::Traverse() {
    Node<MyType> *temPoint = nullptr;
    temPoint = pHead->pNext;

    while (temPoint->pNext != nullptr) {
        MyType saveData = temPoint->data;
        cout <<  saveData << " ";
        temPoint = temPoint->pNext;
    }
    
    if (temPoint == pHead->pNext) {
        cout << "---None Nodes---" << endl;
    }
}


template <class MyType>
int LinkList<MyType>::GetElem(int position, MyType &e) {
    if (position < 1) {
        cout << "---Get Position Error---";
        return ERROR;
    }

    Node<MyType> *temPoint = nullptr;
    temPoint = pHead->pNext;

    if (position > CurPosition)     //position在curposition之后
    {
        temPoint = CurPosition;
        for (int i = CurPosition; i != position + 1; i++) {
            temPoint = temPoint->pNext;
        }
    }
    else        //position在curposition之前
    {
        for (int i = 1; i != position+1; i++) {
            temPoint = temPoint->pNext;
        }
    }
    
    CurPosition = temPoint;
    CurPosition = position;
    e = temPoint->pNext;
    return SUCCESS;
}



template <class MyType>
int LinkList<MyType>::SetElem(int position, MyType e) {
    if (position < 1) {
        cout << "---Get Position Error---";
        return ERROR;
    }
    
    Node<MyType> *temPoint = nullptr;
    temPoint = pHead->pNext;
    
    if (position > CurPosition)     //position在curposition之后
    {
        temPoint = CurPosition;
        for (int i = CurPosition; i != position + 1; i++) {
            temPoint = temPoint->pNext;
        }
    }
    else        //position在curposition之前
    {
        for (int i = 1; i != position+1; i++) {
            temPoint = temPoint->pNext;
        }
    }

    temPoint->data = e;
    CurPoint = temPoint;
    CurPosition = position;
    return SUCCESS;
}

template <class MyType>
bool LinkList<MyType>::Empty() {
    return length == 0 ? 0 : 1;
}


template <class MyType>
int LinkList<MyType>::Length() {
    return length;
}



template <class MyType>
void LinkList<MyType>::DestoryList() {
    while (nullptr != pHead->pNext) {
        Node<MyType> *temPoint = nullptr;
        temPoint = pHead->pNext;
        pHead->pNext = pHead->pNext->pNext;
        delete[] temPoint;
    }
    delete [] pHead;
    length = 0;
    CurPosition = 0;
    CurPoint = nullptr;
}


template <class MyType>
void LinkList<MyType>::Clear() {
    length = 0;
    CurPoint = pHead;
    CurPosition = 0;
    pTail = pHead;
}



template <class MyType>
void  LinkList<MyType>::Init() {
    pHead = new Node<MyType>;
    pTail = pHead;
    CurPosition = 0;
    CurPoint = pHead;
    length = 0;
    
}

template <class MyType>
void LinkList<MyType>::CreateList(MyType num) {
    Node<MyType> *temPoint = new Node<MyType>;
    if (nullptr == temPoint) {
        cout << "---Allocate Space Error---" << endl;       //分配空间错误
        exit(-1);
    }
    temPoint->data = num;
    temPoint->pNext = nullptr;
    length++;
    pTail->pNext = temPoint;
    pTail = temPoint;
    temPoint = nullptr;
    delete [] temPoint;
}



#endif /* link_list_h */
