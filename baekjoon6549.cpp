#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX_N = 100000;
int arr[MAX_N];
int seg_tree[MAX_N * 4];
int n;

void init(int node, int start, int end) {
	if (start == end)
		seg_tree[node] = start;
	else {
		int mid = (start + end) / 2;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		if (arr[seg_tree[node * 2]] <= arr[seg_tree[node * 2 + 1]])
			seg_tree[node] = seg_tree[node * 2];
		else
			seg_tree[node] = seg_tree[node * 2+1];
	}
}

int query(int node, int start, int end, int i, int j) {
	if (i > end || j < start)
		return -1;
	if (i <= start && end <= j)
		return seg_tree[node];

	int mid = (start + end) / 2;
	int q1 = query(node * 2, start, mid, i, j);
	int q2 = query(node * 2 + 1, mid + 1, end, i, j);
	if (q1 == -1)
		return q2;
	if (q2 == -1)
		return q1;
	return arr[q1] <= arr[q2] ? q1 : q2;
}

ll largest(int start, int end) {
	int m = query(1, 0, n - 1, start, end);
	ll area = (ll)(end - start + 1) * (ll)arr[m];
	if (start <= m - 1) {
		ll temp = largest(start, m - 1);
		if (area < temp) {
			area = temp;
		}
	}
	if (m + 1 <= end) {
		ll temp = largest(m + 1, end);
		if (area < temp) {
			area = temp;
		}
	}
	return area;
}


void solve() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(arr, 0, sizeof(arr));
		memset(seg_tree, 0, sizeof(seg_tree));
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		init(1, 0, n - 1);
		printf("%lld\n", largest(0, n - 1));
	}
}


// By divide and conquer

ll divide_conquer(int start, int end) {
	if (start == end) return arr[start];
	int mid = (start + end) / 2;
	// ¿ÞÂÊ ¿À¸¥ÂÊÀÇ ÃÖ´ñ°ª
	ll ret = max(divide_conquer(start, mid), divide_conquer(mid + 1, end));
	// Áß¾ÓÀÇ ÃÖ´ñ°ª
	int left = mid, right = mid + 1;
	int height = min(arr[left], arr[right]);
	ret = max(ret, (ll)height * 2);
	while (left > start || right < end) {
		if (right < end && (left == start || arr[left - 1] <= arr[right + 1])) {
			right++;
			height = min(height, arr[right]);
			ret = max(ret, (ll)height * (ll)(right - left + 1));
		}
		else {
			left--;
			height = min(height, arr[left]);
			ret = max(ret, (ll)height * (ll)(right - left + 1));
		}
	}

	return ret;
}

void solve_by_divide_conquer() {
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		printf("%lld\n", divide_conquer(0, n - 1));
	}

}


int main() {
	solve_by_divide_conquer();
}


