#include <bits/stdc++.h>
using namespace std;
void build(vector<int> &arr, vector<int> &seg, int i, int low, int high) {
    if (low == high) {
        seg[i] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(arr, seg, 2 * i + 1, low, mid);
    build(arr, seg, 2 * i + 2, mid + 1, high);
    seg[i] = min(seg[2 * i + 1], seg[2 * i + 2]);
}
int query(vector<int> &seg, int i, int low, int high, int l, int r) {
    if (high < l || r < low) {
        return INT_MAX;
    }
    else if (low >= l && high <= r) {
        return seg[i];
    }
    else {
        int mid = (low + high) / 2;
        int left = query(seg, 2 * i + 1, low, mid, l, r);
        int right = query(seg, 2 * i + 2, mid + 1, high, l, r);
        return min(left, right);
    }
}
int main() {
    cout << "Segment trees:\n";
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter array elements: ";
    vector<int> arr(n), seg(4 * n, INT_MAX);
    for (int i = 0; i < n; i += 1)
    {
        cin >> arr[i];
    }
    build(arr, seg, 0, 0, n - 1);
    int q;
    cout << "Enter number of min queries: ";
    cin >> q;
    for (int i = 0; i < q; i += 1)
    {
        int l, r;
        cout << "Enter range for query: ";
        cin >> l >> r;
        cout << "Min in range " << l << " " << r << ": " << query(seg, 0, 0, n-1, l-1, r-1) << "\n";
    }
    return 0;
}