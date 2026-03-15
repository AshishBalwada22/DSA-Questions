// 4 things
/*
1) Divide and conquer
2) Backtracking / brute force
3) generating fractal pattern
4) Kth generation(hard)

*/

// check pallinedrome using recursion
bool checkPallinedrome(string str, int i, int j){
    if(i>=j) return true;
    if(str[i]!=str[j]) return false;
    return checkPallinedrome(str,i+1,j-1);
}


// calculate ncr using recursion
int ncr(int n, int r){
    // nCr = (n-1)C(r-1) + (n-1)C(r)  , take + not take
    if(r<0 || r>n) return 0;
    if(r==0 || r == n) return 1;
    if(r==1) return n;
    return ncr(n-1,r-1) + ncr(n-1,r);
}

// tower of Hanoi
void towerOfHanoi(int disk, int cur, int target, int via){
    if(disk==0) return;
    towerOfHanoi(disk-1, cur, via, target);
    cout<<"move 1 disk from "<< cur<<" to "<<target<<endl;
    towerOfHanoi(disk-1, via, target, cur);
}
// number of moves = 2^(disk) -1

/*
LCCMD
L(level) -> row/index, at which row am i currently deciding
C(choice) -> at current level, what choices we have
C(check) -> is this choice valid / can i place
M(move) -> place recurse revert
D(decide) -> accept/reject/print
*/

// N queens
vector<int>queens; // store column value where i place the queen in each row
int n;
int ans=0;

int check(int row,int col){
    for(int i=0;i<row;i++){
        int pc = queens[i];
        if(pc == col) return 0; 
        if(abs(pc-col)==abs(i-row)) return 0; // slope would be same on diagonal
    }
    return 1;
}
void rec(int row){ // level 
    // base case -> Decide
    if(row==n){
        for(auto v:queens){
            cout<<v<<" ";
        }
        cout<<endl;
        ans++;
        return;
    }
    // Move
    for(int col=0;col<n;col++){ // iterate on choice
        if(check(row,col)){ // check - is choice valid
            queens.push_back(col);
            rec(row+1);
            queens.pop_back();
        }
    }
}
// time complexity -> (choices)^(levels) * (check) -> (m^n)*n
// time complexity -> n*(n-1)*(n-2).... => o(n!) , first row has n choices then second row left with n-1 choices and so on ..


// Find the number of ways such that i can place k queens in n*m board
vector<int>queens;
int n,m,k,ans,queenPlaced=0;

int check(int row, int col){
    if(col==-1) return 1; // i am not placing any queen at current row
    for(int i=0;i<row;i++){
        int pc = queens[i];
        if(pc==-1) continue; // if no queen is place on particular column in previous row
        if(pc==col) return 0;
        if(abs(pc-col)==abs(i-row)) return 0; 
    }
    return 1;
}
void rec(int row){
    // base case
    if(row==n){
        if(queenPlaced == k){
            for(auto v:queens) cout<<v<<" ";
            cout<<endl;
            ans++;
        }
        return;
    }
    // explore
    for(int ch=-1;ch<m;ch++){// we have -1(don't place any queen on that row), [0..m] choices
        if(check(row,ch)){
            queens.push_back(ch);
            if(ch!=-1) queenPlaced++;
            rec(row+1);
            if(ch!=-1) queenPlaced--;
            queens.pop_back();
        }
    }
}
// time complexity -> ((m+1)^n)) * (n)


//Find permutation of distinct element
void permutation(int ind, int n, vector<int>&v){
    if(ind==n-1){ // base case
        for(auto val:v) cout<<val<<" ";
        cout<<endl;
        return;
    }
    // explore
    for(int i=ind;i<n;i++){ // iterate on choices 
        swap(v[i],v[ind]);
        permutation(ind+1,n,v);
        swap(v[i],v[ind]);
    }
}


// Find distinct permutation of non-distinct element without calculating all permutation
vector<int>v,perm;
int n;
map<int,int> m;//choices we left with
void permutation(int level){
    if(level==n){ // filling n size permutation
       for(auto val:perm){
        cout<<val<<" ";
       }
       cout<<endl;
       return;
    }
    //explore all choices
    for(auto it:m){
        int val=it.first;
        int count=it.second;
        if(count>0){
            perm.push_back(val);
            m[val]--;
            permutation(level+1);
            m[val]++;
            perm.pop_back();
        }
    }
}


// Kth generation

// Find the kth move in tower of Hanoi
void kthMove(int disk, int cur, int target, int via, int k){
    // number of moves = 2^disk - 1
    // moves(2^(disk-1)-1) + 1 + moves(2^(disk-1)-1)
    if(disk==0){
        return;
    }
    // move disk-1 from cur to via using target
    if(k<=pow(2,disk-1)-1){
    kthMove(disk-1,cur,via,target,k);
    }
    // move 1 disk from cur to target
    else if(k<=pow(2,disk-1)){
    cout<<cur<<" "<<target<<endl;
    }
    // move disk-1 from via to target using cur
    else{
    kthMove(disk-1,via,target,cur,k-pow(2,disk-1)); // if we go in third half, then 2^(disk-1) moves already passed, then we are looking for k-pow(2,disk-1) move
    }
}



// https://atcoder.jp/contests/abc115/tasks/abc115_d

vector<int>p(51);// patty
vector<int>l(51);// layer
void pre(){
  p[0]=1;
  l[0]=1;
  for(int i=1;i<=50;i++){
    p[i]=0+p[i-1]+1+p[i-1]+0;
    l[i]=1+l[i-1]+1+l[i-1]+1;
  }
}
int countpatty(int n, int x){ // n = layer
  if(x==0) return 0;// no more to eat
  if(n==0) return 1;// 1 patty to eat
  if(x<=1){ // first one is BUN  , bun + layer-1 + patty + layer-1 + bun
    return 0;
  }else if(x<=1+l[n-1]){
    return countpatty(n-1,x-1);
  }else if(x<=1+l[n-1]+1){
    return p[n-1]+1;
  }else if(x<=1+l[n-1]+1+l[n-1]){
    return p[n-1]+1+countpatty(n-1,x-(1+l[n-1]+1));
  }else if(x<=1+l[n-1]+1+l[n-1]+1){
    return p[n-1]+1+p[n-1];
  }
  return 0;
}
void solve(){
    int n,x;
    cin>>n>>x;
    pre();
    cout<<countpatty(n,x);
}

/* practice problem for kth generation
https://codeforces.com/problemset/problem/896/A
https://codeforces.com/problemset/problem/768/B
https://codeforces.com/problemset/problem/36/B
*/