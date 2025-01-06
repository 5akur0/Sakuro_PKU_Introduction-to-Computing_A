#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

int main() {
    int n;
    cin >> n;
    int cur;
    cin >> cur;
    ListNode *head = new ListNode(0);
    ListNode *p = new ListNode(cur);
    head->next = p;
    int nowKill = cur;
    for (int i = 0 + 1; i < n; ++i) {
        cin >> cur;
        if (cur == nowKill) {
            if (p->val == nowKill) {
                p = head;
                if (p->next == nullptr) {
                    head->next = nullptr;
                    p = head;
                }
                while (p->next->next != nullptr) {
                    p = p->next;
                }
                p->next = nullptr;
            }
            continue;
        }
        ListNode *q = new ListNode(cur);
        nowKill = cur;
        p->next = q;
        p = p->next;
    }
    stringstream oss;
    ListNode *c = head;
    while (c -> next!= nullptr) {
        c = c->next;
        oss << c->val << " ";
    }
    string output = oss.str();
    output.pop_back();
    cout << output << endl;
    return 0;
}

