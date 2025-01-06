#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int _ = 0; _ < n; ++_) {
        string line;
        getline(cin, line);
        stringstream iss(line);
        int cur;
        iss >> cur;
        ListNode* head = new ListNode(cur);
        ListNode* p = head;
        while (iss >> cur) {
            if (cur < head->val) {
                ListNode* c = new ListNode(cur);
                c->next = head;
                head = c;
                continue;
            }
            ListNode* f = head;
            while (!(f->val < cur && (f->next == nullptr || f->next->val >= cur))) {
                if (f->next == nullptr) {
                    break;
                }
                f = f->next;
            }
            ListNode* q = f->next;
            ListNode* c = new ListNode(cur);
            f->next = c;
            c->next = q;
        }
        stringstream oss;
        ListNode*m = head;
        while (m != nullptr) {
            oss << m->val << " ";
            m = m->next;
        }
        string output = oss.str();
        output.pop_back();
        cout << output << endl;
    }
    return 0;
}