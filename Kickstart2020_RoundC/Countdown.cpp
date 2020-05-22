
/*
Author: Harshit Singh
Passed: AC (5pts,7pts)
*/

#include<bits/stdc++.h>

using namespace std;

#define MAX_N 200000
int arr[MAX_N + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    int t = 1;
    while (t <= T) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; i++) cin >> arr[i];
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] - K) continue;
            int cnt = 1, j = i;
            while (j + 1 <= N && cnt < K && (arr[j + 1] == arr[j] - 1)) {
                j++;
                cnt++;
            }
            if (cnt == K) {
                ans++;
            }
            i = j;
        }
        printf("Case #%d: %d\n", t, ans);
        t++;
    }

    return 0;
}
