class Solution {
public:

    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }


    ListNode* sortList(ListNode* head) {

        if (head == nullptr) return head;

        vector<int> arr;

        ListNode* curr = head;

        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        mergeSort(arr, 0, arr.size() - 1);

        curr = head;
        int i = 0;

        while (curr != nullptr) {
            curr->val = arr[i];
            i++;
            curr = curr->next;
        }

        return head;
    }
};