#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insertAtHead(int val, ListNode* &head){
    ListNode* temp=new ListNode(val);
    temp->next=head;
    head=temp;
    return;
}

void printLinkedList(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    return;
}

int size(ListNode* head){
    int ans=0;
    while(head){
        ans++;
        head = head->next;
    }
    return ans;
}

ListNode* midpoint(ListNode* head){
    if(!head or !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* head1, ListNode* head2){
    ListNode* temp1=new ListNode(0);
    ListNode* temp=temp1;
    while(head1 and head2){
        if(head1->val < head2->val){
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }
    while(head1){
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
    }
    while(head2){
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }
    return temp1->next;
}

// ListNode* merge(ListNode* head1, ListNode* head2) {

// 	// base case

// 	if(head1 == NULL) {
// 		// first LL is empty
// 		return head2;
// 	}

// 	if(head2 == NULL) {
// 		// second LL is empty
// 		return head1;
// 	}


// 	// recursive case

// 	ListNode* head;
		
// 	if(head1->val < head2->val) {
// 		head = head1;
// 		head->next = merge(head1->next, head2);
// 	} else {
// 		head = head2;
// 		head->next = merge(head1, head2->next);
// 	}

// 	return head;

// } 

// ListNode* merge_sort(ListNode* head){
//     // base case
//     if(!head or !head->next) return head;

//     // recursive case
//     ListNode* getmid = midpoint(head);
//     ListNode* head2 = getmid->next;
//     getmid->next = NULL;

//     head = merge_sort(head);
//     head2 = merge_sort(head2);
//     // if(n%2==0){
//     //     head2 = merge_sort(head2, n/2);
//     // }
//     // else head2 = merge_sort(head2, n/2+1);
//     return merge(head, head2);
// }

ListNode* merge_sort(ListNode* head, int n){
    // base case
    if(!head or !head->next) return head;

    // recursive case
    ListNode* temp = head;
    int t = n/2-1;
    while(t--){
        temp = temp->next;
    }
    ListNode* head2 = temp->next;
    temp->next = NULL;

    head = merge_sort(head, n/2);
    if(n%2==0){
        head2 = merge_sort(head2, n/2);
    }
    else head2 = merge_sort(head2, n/2+1);
    return merge(head, head2);
}

int main(){
    ListNode* head = NULL;
    insertAtHead(10, head);
    insertAtHead(20, head);
    insertAtHead(30, head);
    insertAtHead(40, head);
    insertAtHead(50, head);

    printLinkedList(head);
    cout<<endl;
    int n = size(head);
    cout<<n<<endl;
    head = merge_sort(head, n);
    printLinkedList(head);
    cout<<endl;
    return 0;
}

// #include<iostream>

// using namespace std;

// class ListNode {
// public:

// 	int val;
// 	ListNode* next;

// 	ListNode(int val) {
// 		this->val = val;
// 		this->next = NULL;
// 	}

// };

// void insertAtHead(ListNode*& head, int val) {

// 	ListNode* n = new ListNode(val);
// 	n->next = head; 
// 	head = n;

// }


// void printLinkedList(ListNode* head) {
	
// 	while(head) { // head != NULL
// 		cout << head->val << " ";
// 		head = head->next;
// 	}

// 	cout << endl;
// }

// ListNode* getMidPoint(ListNode* head) {
// 	if(!head) { // head == NULL
// 		return head;
// 	}

// 	ListNode* slow = head;
// 	ListNode* fast = head->next;

// 	while(fast != NULL && fast->next != NULL) {
// 		slow = slow->next;
// 		fast = fast->next->next;
// 	}

// 	return slow;
// }

// ListNode* merge(ListNode* head1, ListNode* head2) {

// 	// base case

// 	if(head1 == NULL) {
// 		// first LL is empty
// 		return head2;
// 	}

// 	if(head2 == NULL) {
// 		// second LL is empty
// 		return head1;
// 	}


// 	// recursive case

// 	ListNode* head;
		
// 	if(head1->val < head2->val) {
// 		head = head1;
// 		head->next = merge(head1->next, head2);
// 	} else {
// 		head = head2;
// 		head->next = merge(head1, head2->next);
// 	}

// 	return head;

// } 

// ListNode* mergeSort(ListNode* head) {

// 	// base case

// 	if(head == NULL || head->next == NULL) {
// 		// LL is either empty or it has a single then it is already sorted
// 		return head;
// 	}

// 	// 1. divide the LL around the midPoint
// 	ListNode* midPoint = getMidPoint(head);
// 	ListNode* head2 = midPoint->next;
// 	midPoint->next = NULL;

// 	// 2. recursively sort the left and right subLists
// 	head  = mergeSort(head);
// 	head2 = mergeSort(head2);

// 	// 3. merge the two sorted subLists such that the merged list is sorted
// 	return merge(head, head2);

// }


// int main() {

// 	ListNode* head = NULL;

// 	insertAtHead(head, 10);
// 	insertAtHead(head, 20);
// 	insertAtHead(head, 30);
// 	insertAtHead(head, 40);
// 	insertAtHead(head, 50);

// 	printLinkedList(head);

// 	head = mergeSort(head);

// 	printLinkedList(head);

// 	return 0;
// }