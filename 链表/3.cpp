#include <bits/stdc++.h>
using namespace std;

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 插入一个新节点到链表
void insert(ListNode *&head, int value) {
    ListNode *newNode = new ListNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        ListNode *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 打印链表
void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) {
            cout << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// 合并两个已经排好序的链表
ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

// 将链表转换为排序后的数组
vector<int> listToArray(ListNode *head) {
    vector<int> result;
    while (head != NULL) {
        result.push_back(head->val);
        head = head->next;
    }
    sort(result.begin(), result.end());
    return result;
}

// 将数组转换为链表
ListNode *arrayToList(const vector<int> &arr) {
    ListNode *head = NULL;
    for (int val : arr) {
        insert(head, val);
    }
    return head;
}

int main() {
    int N, M;
    cin >> N;

    ListNode *list1 = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insert(list1, x);
    }

    cin >> M;
    ListNode *list2 = NULL;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        insert(list2, x);
    }

    // 将两个链表转换为数组并合并
    vector<int> arr1 = listToArray(list1);
    vector<int> arr2 = listToArray(list2);
    vector<int> mergedArr(arr1.begin(), arr1.end());
    mergedArr.insert(mergedArr.end(), arr2.begin(), arr2.end());

    // 对合并后的数组进行排序
    sort(mergedArr.begin(), mergedArr.end());

    // 将排序后的数组转换为链表
    ListNode *mergedList = arrayToList(mergedArr);

    // 打印合并后的链表
    printList(mergedList);

    return 0;
}