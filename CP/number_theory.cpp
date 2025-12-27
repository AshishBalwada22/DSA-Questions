1) GCD (greatest common divisor)

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

//maths behind it

x|a (x divide a) -> a%x=0
x|b (x divide b) -> b%x=0
then x|(a-b) -> (a-b)%x=0

gcd(a,b) -> gcd(a-b,b) -> gcd(a-xb,b) -> gcd(a%b,b) (I'm left with reminder) -> gcd(b,a%b)

gcd(a,b) , a<b  => gcd(b, a%b) => gcd(b,a) , here b>a

// time complexity

in one step -> swapped if a<b
in second step -> reduced to x/2 , gcd(x,y) where x>y

gcd(x%y,y) -> < x/2   , where x>y

how?

case1 - if y<=x/2 then result gcd(x%y,y) will be surely <= x/2    (a%b result lies in [0..b-1])
case2 - if y>x/2, then x%y < x/2, visualize on number line

time complexity -> o(log(min(a,b)))

2) LCM (least common multiple)

gcd(a,b) x lcm(a,b) = a x b

3) Prime factorization | divisor

int divisor(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      cout<<i<<endl;
      if(n/i!=i)// factor lies in second half
      cout<<n/i<<endl;
    }
  }
}

4) Prime factorization

void primeFactorization(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int expo=0;
            while(n%i==0){
                n=n/i;
                expo++;
            }
            cout<<i<<"^"<<expo<<" ";
        }
    }
    if(n!=1) cout<<n; // this is for prime number lies in second half
}

5) sieve of eratothenesis

void sieve_of_eratothenesis(int n){
    vector<int> isprime(n+1,1);
    isprime[0]=isprime[1]=0;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j=j+i){
                isprime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            cout<<i<<" ";
        }
    }
}

// time complexity

// N/i -> how many multiple of i we go through till we reach N
summation(N/i) where i = 0,1,...n  => o(nlogn)
summation(N/i) where i = 2,3,5..primetoN => o(nloglogn)

6) SPF array (smallest prime factor)

void smallest_prime_factor(int n){
    vector<int> spf(n+1);
    for(int i=0;i<=n;i++) spf[i]=i;

    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j=j+i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

    // prime factor of any number from 1 to n
    int x=24;
    while(x!=1){
      cout<<spf[x]<<" ";
      x=x/spf[x];
    }
}