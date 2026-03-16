/*
Stack

 Feel the friction in the process and learn it.
 1) General Stack
 2) Maintaining version(undo/redo)
 3) parsing/parenthesis
 4) monotonic Stack
 */


 // Monotonic stack
 void ngeHelper(int n,vector<int>&v){
    stack<int>st;
    vector<int>nge(n); // storing index of next greater element bigger than v[i]
    for(int i=n-1;i>=0;i--){ // nge of current element depends upon further element
        while(!st.empty()&&v[st.top()]<=v[i]) st.pop(); // stack ke top pe minimum hai toh pop kardo, jo bigger hoga top pe vo hi nge hoga
        if(!st.empty()) nge[i]=st.top();
        else nge[i]=n;
        st.push(i);
    }
    for(int i=0;i<n;i++){
        if(nge[i]==n) cout<<-1<<" ";
        else cout<<v[nge[i]]<<" ";
    }
}

// for pge -> previous greater element -> starts from 0 to n-1


// Binary lifting -> without using stack, o(n)
void ngeHelper(int n, vector<int>&arr){
    vector<int>nge(n);
    for(int i=n-1;i>=0;i--){
        nge[i]=i+1; // let assume next element is nge
        while(nge[i]!=n&&arr[nge[i]]<=arr[i]){
            nge[i]=nge[nge[i]]; // if next element is not nge, then go to nge of next element.. so on..
        }
    }
    for(int i=0;i<n;i++){
        if(nge[i]==n) cout<<-1<<" ";
        else cout<<arr[nge[i]]<<" ";
    }
}


// Find maximum area and maximum perimeter of largest rectangle under histogram
vector<int> calculate_nse(int n, vector<int>&arr){
    vector<int>nse(n);
    for(int i=n-1;i>=0;i--){
        nse[i]=i+1;// let assume next element is nse
        while(nse[i]!=n&&arr[nse[i]]>=arr[i]){
            nse[i]=nse[nse[i]];
        }
    }
    return nse;
}
vector<int> calculate_pse(int n, vector<int>&arr){
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        pse[i]=i-1;// let assume next element is nse
        while(pse[i]!=-1&&arr[pse[i]]>=arr[i]){
            pse[i]=pse[pse[i]];
        }
    }
    return pse;
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>nse=calculate_nse(n,arr);// next smaller element
    vector<int>pse=calculate_pse(n,arr);// previous smaller element
    int max_area = INT_MIN, max_perimeter = INT_MIN;
    for(int i=0;i<n;i++){ // at each index i, just trying to acheive max height of rectangle
        max_area = max(max_area, (nse[i]-pse[i]-1)*arr[i]);
        max_perimeter = max(max_perimeter, 2*(nse[i]-pse[i]-1 + arr[i]));
    }
    cout<<"max_area = "<<max_area<<endl;
    cout<<"max_perimeter = "<<max_perimeter<<endl;
}


// Find the sum of minimum of all possible subarray of arr - o(n)
/*
[1 3 2]
 1      - 1
   3    - 3
     2  - 2
 1 3    - 1
   3 2  - 2
 1 3 2  - 1
   sum  = 10

Solution - each element contribute as minimum in how many subarray , if arr[i] is a minimum element, then we can't take element less than arr[i]
(i-pse[i])*(nse[i]-i)*arr[i]
*/

vector<int> calculate_nse(int n,vector<int>&arr){
    vector<int>nse(n);
    for(int i=n-1;i>=0;i--){
        nse[i]=i+1;
        while(nse[i]!=n&&arr[nse[i]]>=arr[i]){
            nse[i]=nse[nse[i]];
        }
    }
    return nse;
}
vector<int> calculate_pse(int n,vector<int>&arr){
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        pse[i]=i-1;
        while(pse[i]!=-1&&arr[pse[i]]>=arr[i]){
            pse[i]=pse[pse[i]];
        }
    }
    return pse;
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>nse=calculate_nse(n,arr);
    vector<int>pse=calculate_pse(n,arr);
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum + (i-pse[i])*(nse[i]-i)*arr[i];
    }
    cout<<sum<<endl;
}

// Follow up question - if we have non-distinct element, then calculate sum of minimum of all subarray
// [3 3 3] -> all 3's are minimum of subarray
// answer for above is 3 + 2 + 1 = 6
// then i will change arr[pse[i]]>=arr[i] -> arr[pse[i]]>arr[i], so that when we calculate for second index 3, it won't consider first index 3
// you can change sign for either pse or nse, not both.


