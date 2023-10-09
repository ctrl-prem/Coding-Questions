#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ListNode{
	public:
		int val;
		ListNode* next;
	
	ListNode(int val){
		this->val = val;
		this->next = NULL;
	}
};

void insertAthead(ListNode* &head, int val){
	ListNode* temp = new ListNode(val);
	temp->next = head;
	head = temp;
}

void printAllnodes(ListNode* head){
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
}

ListNode* nodeToSwap(ListNode* head){
    ListNode* prev = NULL;
    ListNode* temp = head;
    while(head->next){
        if(head->next->val<temp->val){
            prev = head;
            temp = head->next;
        }
        head = head->next;
    }
    return prev;
}

ListNode* swaping(ListNode* prev, ListNode* prev1, ListNode* head, ListNode* curr){
    ListNode* temp = head->next;
    if(!prev){
        head->next = curr->next;
        prev1->next = head;
        curr->next = temp;
        return curr;
    }

    prev->next = curr;
    prev1->next = head;
    head->next = curr->next;
    curr->next = temp;
    return curr;
}

ListNode* selectionSort(ListNode* prev, ListNode* head){
    if(!head or !head->next){
        return head;
    }

    ListNode* curr = nodeToSwap(head);
    
    if(curr and curr->next){
        ListNode* prev1 = curr;
        curr = curr->next;
        head = swaping(prev, prev1, head, curr);
        ListNode* nodeReturned = selectionSort(head, head->next);
        head->next = nodeReturned;
    }
    return head;
}

int main() {
	int n;
	cin>>n;
	// vector<int> vect(n);
	// for(int i=0; i<n; i++){
	// 	cin>>vect[i];
	// }

	// ListNode* head = NULL;
	// for(int i=n-1; i>=0; i--){
	// 	insertAthead(head, vect[i]);
	// }
	
	// ListNode* prev = NULL;
	// head = selectionSort(prev, head);

	// printAllnodes(head);
	// cout<<endl;
    bool arr[n];
    memset(arr, 1, n);
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    string str = "{0-0}K{2-1}R";
    str.pop_back();
    cout<<str<<endl;
    cout<<endl;

	return 0;
}

// this is for testing only.