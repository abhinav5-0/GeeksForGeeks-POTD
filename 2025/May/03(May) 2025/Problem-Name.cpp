//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    // Function to check and return the nearest prime number
    int getNearestPrime(int val, const vector<int> &primes) {
        // Binary search to find the closest prime
        auto it = lower_bound(primes.begin(), primes.end(), val);
        
        if (it == primes.begin()) return *it;
        if (it == primes.end()) return primes.back();
        
        int upper = *it;
        int lower = *(it - 1);
        
        if (abs(val - lower) <= abs(upper - val))
            return lower;
        return upper;
    }

    Node *primeList(Node *head) {
        // Step 1: Generate primes up to 2*10^4 using Sieve of Eratosthenes
        int MAX = 20000;
        vector<bool> isPrime(MAX + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i)
                    isPrime[j] = false;
            }
        }

        // Store primes in a list for binary search
        vector<int> primes;
        for (int i = 2; i <= MAX; ++i) {
            if (isPrime[i])
                primes.push_back(i);
        }

        // Step 2: Traverse linked list and replace each value
        Node* curr = head;
        while (curr != NULL) {
            curr->val = getNearestPrime(curr->val, primes);
            curr = curr->next;
        }

        return head;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
