int longestConsecutiveSequenceOptimal(vector<int> &arr){
    int longest = 1;
    unordered_set<int> st;

    if(arr.size() == 0) return 0;

    for(int i = 0; i < arr.size(); i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}