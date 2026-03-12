#include <iostream>
#include <unordered_map>
using std::unordered_map;
using std::cout;
using std::endl;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


bool hasCycle(ListNode *head) {
    unordered_map<ListNode *, int> hashmap;
    while (head != nullptr)
    {
        if (hashmap.find(head) != hashmap.end()) return true;
        hashmap[head] = head->val;
        head = head->next;
    }
    return false;
}

int main()
{
//    输入：head = [3,2,0,-4], pos = 1
//    输出：true
//    解释：链表中有一个环，其尾部连接到第二个节点。

    ListNode *L1 = new ListNode(3);
    L1->next = new ListNode(2);
    L1->next->next = new ListNode(0);
    L1->next->next->next = new ListNode(-4);
    L1->next->next->next->next = L1->next;

    cout << hasCycle(L1) << endl;

    delete L1->next->next->next;
    delete L1->next->next;
    delete L1->next;
    delete L1;
}