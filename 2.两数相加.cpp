#include <iostream>
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//算法
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode;
    ListNode *p = head;
    //先检测是否有一条链表是空的
    if(l1->val == 0 && l1->next == nullptr)     return l2;
    if(l2->val == 0 && l2->next == nullptr)     return l1;

    //开始相加
    bool Jin_Wei = false;
    while(true)
    {

        char temp = l1->val + l2->val;
        if (Jin_Wei)
        {
            ++temp;
            Jin_Wei = false;
        }

        if (temp >= 10)
        {
            Jin_Wei = true;
            temp %= 10;
        }
        p->val = temp;
        p->next = new ListNode;


        if(l2->next != nullptr && l1->next != nullptr)
        {
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1->next == nullptr && l2->next != nullptr)
        {
            p = p->next;
            l1->val = 0;
            l2 = l2->next;
        }
        else if(l2->next == nullptr && l1->next != nullptr)
        {
            p = p->next;
            l2->val = 0;
            l1 = l1->next;
        }
        else if(l1->next == nullptr && l2->next == nullptr)
        {
            if (Jin_Wei)
            {
                p->next->val = 1;
                Jin_Wei = false;
            }
            else
            {
                delete p->next;
                p->next = nullptr;
            }
            break;
        }
    }
    return head;
}

int main()
{
    //List创建
    ListNode *t;
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(9);

    t = l1;
    for (int i = 0 ; i < 6 ; ++i)
    {
        t->next = new ListNode(9);
        t = t->next;
    }
    t = l2;
    for (int i = 0 ; i < 3 ; ++i)
    {
        t->next = new ListNode(9);
        t = t->next;
    }

    //List输出


    ListNode *ans = addTwoNumbers(l1, l2);



    //删除工作
    ListNode *temp = nullptr;
    cout << "l1\t";
    while (l1->next != nullptr)
    {
        temp = l1;
        cout << l1->val << "\t";
        l1 = l1->next;
    }
    temp = l1;
    cout << l1->val << "\t";
    l1 = l1->next;

    cout << endl << "l2\t";
    while (l2->next != nullptr)
    {
        temp = l2;
        cout << l2->val << "\t";
        l2 = l2->next;
    }
    temp = l2;
    cout << l2->val << "\t";
    l2 = l2->next;

    //ans输出与删除
    cout << endl <<  "ans\t";
    do
    {
        temp = ans;
        cout << ans->val << "\t";
        ans = ans->next;
        delete temp;
    }while (ans->next != nullptr);
    temp = ans;
    cout << ans->val << "\t";
    ans = ans->next;
    delete temp;
}
