#include "mlist.h"
#include <stack>
#include <cstdio>
cfListNode* reverse_list_v0(cfListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    cfListNode* prev = nullptr;
    cfListNode* cur = head;
    while(cur->next != nullptr) {
        cfListNode*next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    return cur;
}
cfListNode* reverse_list(cfListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    cfListNode* prev = head;
    cfListNode* cur = head->next;
    cfListNode* next;
    prev->next = nullptr;

    while(cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void print_list(cfListNode *phead)
{
    fprintf(stderr, "List: ");
    while (phead != NULL)
    {
        fprintf(stderr, "%d->", phead->value);
        phead = phead->next;
    }
    fprintf(stderr, "null\n");
}
void free_list(cfListNode *phead)
{
    cfListNode *pN;
    while (phead != NULL)
    {
        pN = phead;
        phead = phead->next;
        delete pN;
        pN = NULL;
    }
}

void printReversedList_Iterative(cfListNode* phead)
{
    std::stack<cfListNode*> plist;
    while (phead != nullptr) {
        plist.push(phead);
        phead = phead->next;
    }
    while(!plist.empty()) {
        phead = plist.top();
        fprintf(stderr, "%d<-", phead->value);
        plist.pop();
    }
}

void printReversedList_Recursive(cfListNode* phead){
    if(phead != nullptr) {
        if(phead->next != nullptr) {
            printReversedList_Recursive(phead->next);
        }
        fprintf(stderr, "%d<-", phead->value);
    }
}
